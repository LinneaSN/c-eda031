#include "umns.h"
#include "nameserverinterface.h"
#include <unordered_map>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;
void UMNS::insert(const HostName& h, const IPAddress& ip){
    UMNSmap.insert({h , ip});
}



bool UMNS::remove(const HostName& h){
    return UMNSmap.erase(h)==1;
}

IPAddress UMNS::lookup(const HostName& h) const {
    const unordered_map<HostName,IPAddress >::const_iterator it=UMNSmap.find(h);
    if(it!=UMNSmap.end()){
        return (*it).second;
    }
    return NON_EXISTING_ADDRESS;
}

