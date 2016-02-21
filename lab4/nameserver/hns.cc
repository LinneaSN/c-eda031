#include "hns.h"
#include "nameserverinterface.h"
#include <vector>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

HNS::HNS(unsigned int t) : vectorSize(t) {
   HNSvector = vector<vector<pair<HostName,IPAddress> > > (t);    
}

void HNS::insert(const HostName& h, const IPAddress& ip){
    string::size_type t=hash<string>{}(h);
    t=t%vectorSize;
    HNSvector[t].push_back(make_pair(h , ip ));
}

bool HNS::remove(const HostName& h){
    string::size_type t=hash<string>{}(h);
    t=t%vectorSize;
    vector<pair<HostName,IPAddress> >::iterator it=find_if(HNSvector[t].begin(),HNSvector[t].end(),[h](const pair<HostName,IPAddress>& element){return element.first==h; });
    if(it!=HNSvector[t].end()){
        HNSvector[t].erase(it);
        return true;
    }
    return false;
}

IPAddress HNS::lookup(const HostName& h) const {
    string::size_type t=hash<string>{}(h);
    t=t%vectorSize;
    vector<pair<HostName,IPAddress> >::const_iterator it=find_if(HNSvector[t].begin(),HNSvector[t].end(),[h](const pair<HostName,IPAddress>& element){return element.first==h; });
    if(it!=HNSvector[t].end()){
        return (*it).second;
    }
    return NON_EXISTING_ADDRESS;
}
