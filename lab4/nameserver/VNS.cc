#include "vns.h"
#include "nameserverinterface.h"
#include <vector>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;
void VNS::insert(const HostName& h, const IPAddress& ip){
    VNSvector.push_back(make_pair(h , ip ));
}



bool VNS::remove(const HostName& h){
    vector<pair<HostName,IPAddress > >::iterator it=find_if(VNSvector.begin(),VNSvector.end(),[h](const pair<HostName,IPAddress>& element){return element.first==h; } );
    if(it!=VNSvector.end()){
        VNSvector.erase(it);
        return true;
    }
    return false;
}

IPAddress VNS::lookup(const HostName& h) const {
    const vector<pair <HostName,IPAddress > >::const_iterator it=find_if(VNSvector.begin(),VNSvector.end(),[h](const pair<HostName,IPAddress>& element){return element.first==h; });
    if(it!=VNSvector.end()){
        return (*it).second;
    }
    return NON_EXISTING_ADDRESS;
}

