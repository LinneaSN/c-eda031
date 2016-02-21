#include <unordered_map>
#include <string>
#include "nameserverinterface.h"

class UMNS : public NameServerInterface {
public:
    virtual void insert(const HostName& h, const IPAddress& ip) override;
    virtual bool remove(const HostName& h) override;
    virtual IPAddress lookup(const HostName& h) const override;
private: 
    std::unordered_map<HostName,IPAddress> UMNSmap;
};
