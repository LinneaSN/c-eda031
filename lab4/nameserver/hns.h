#include <vector>
#include <string>
#include "nameserverinterface.h"

class HNS : public NameServerInterface {
public:
    HNS(unsigned int t);
    virtual void insert(const HostName& h, const IPAddress& ip) override;
    virtual bool remove(const HostName& h) override;
    virtual IPAddress lookup(const HostName& h) const override;
private: 
    std::vector< std::vector<std::pair<HostName,IPAddress > > > HNSvector;
    unsigned int vectorSize;
};
