#include <ctime>  // time and localtime
#include <iostream>
#include <iomanip>
#include "date.h"

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d){
    if(!(y=static_cast<int>(y))){
	return;
    }
    if(m>12) {
        month=12;
    } else if(m<1) {
        month=1;
    }
    if(d<1){
        day=1;
    } else if(d>daysPerMonth[month-1]) {
        day=daysPerMonth[month-1];
    }    
}

bool Date::init(int y, int m, int d){
    if(!(y=static_cast<int>(y))){
	    return false;
    }

    if(m>12 or m<1) {
        return false;
    }    
    if(d<1 or d>daysPerMonth[month-1]){
        day=1;
    }
    return true;
}
int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
  if(daysPerMonth[month-1]>=day+1){
    ++day;
  } else if(month+1<=12){
    ++month;
    day=1;
  } else {
    ++year;
    month=1;
    day=1;
  }
}

istream& operator>>(std::istream& in,Date& date){
    string temp;
    int y,m,d;
    char c;
    
    if(in.eof()){
        return in;
    }
    in>>y>>c>>m>>c>>d;

    if(!(date.year=y) or !(date.month=m) or !(date.day=d) or !date.init(y,m,d) or c!='-'){
        in.setstate(ios_base::failbit);
    }   
    return in;
}

ostream& operator<<(std::ostream& out,const Date& date){
    return out<<setw(4)<<setfill('0')<<date.getYear()<<'-'<<setw(2)<<setfill('0')<<date.getMonth()<<'-'<<setw(2)<<setfill('0')<<date.getDay()<<endl;
}
