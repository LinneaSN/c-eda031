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
    if(m>12) {
        month=12;
    } else if(m<1) {
        month=1;
    } else {
        month=m;
    }
    if(d<1){
        day=1;
    } else if(d>daysPerMonth[month-1]) {
        day=daysPerMonth[month-1];
    } else {
        day=d;
    }
    year=y;
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
    day++;
  } else if(month+1<=12){
    month++;
    day=1;
  } else {
    year++;
    month=1;
    day=1;
  }
}

istream& operator>>(std::istream& in,Date& date){
    string temp;
    in>>temp;
    int msep,dsep;
    msep = static_cast<int>(temp.find('-'));
    dsep = static_cast<int>(temp.rfind('-'));
    if(!date.init(stoi(temp.substr(0,msep),nullptr),stoi(temp.substr(msep+1,dsep-msep-1),nullptr),stoi(temp.substr(dsep+1),nullptr))){
        in.setstate(ios_base::failbit);
    }   
    return in;
}

ostream& operator<<(std::ostream& out,Date& date){
    return out<<setw(4)<<setfill('0')<<date.getYear()<<'-'<<setw(2)<<setfill('0')<<date.getMonth()<<'-'<<setw(2)<<setfill('0')<<date.getDay()<<endl;
}
