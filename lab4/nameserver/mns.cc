#include "mns.h"
#include "nameserverinterface.h"
#include <map>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;
void MNS::insert(const HostName& h, const IPAddress& ip){
    MNSmap.insert({h , ip});
}



bool MNS::remove(const HostName& h){
    return MNSmap.erase(h)==1;
}

IPAddress MNS::lookup(const HostName& h) const {
    const map<HostName,IPAddress >::const_iterator it=MNSmap.find(h);
    if(it!=MNSmap.end()){
        return (*it).second;
    }
    return NON_EXISTING_ADDRESS;
}

