#include <vector>
#include <string>
#include "nameserverinterface.h"

class VNS : public NameServerInterface {
public:
    //virtual ~NameServerInterface() override;
    virtual void insert(const HostName& h, const IPAddress& ip) override;
    virtual bool remove(const HostName& h) override;
    virtual IPAddress lookup(const HostName& h) const override;
private: 
    std::vector<std::pair<HostName,IPAddress> > VNSvector;
};
