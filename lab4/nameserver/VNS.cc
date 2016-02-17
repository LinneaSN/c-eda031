#include "VNS.h"
#include "nameserverinterface.h"
#include <vector>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>

/*VNS::VNS(){


}*/

/*~VNS::VNS(){


}*/
using namespace std;
void VNS::insert(const HostName& h, const IPAddress& ip){
    VNSvector.push_back(make_pair(h , ip ));
}

bool VNS::remove(const HostName& h){
    vector<pair<HostName,IPAddress> >::iterator it=find_if(VNSvector.begin(),VNSvector.end(),[h](const pair<pair<HostName,IPAddress>,HostName>& element){ return element.first.first==h; });
    if(it!=VNSvector.end()){
        VNSvector.erase(it);
        return true;
    }
    return false;
}

IPAddress VNS::lookup(const HostName& h) const{
    vector<pair<HostName,IPAddress> >::iterator it=find_if(VNSvector.begin(),VNSvector.end(),[h](const pair<pair<HostName,IPAddress>,HostName>& element){ return element.first.first==h; });
    return VNSvector[it].second;
}
