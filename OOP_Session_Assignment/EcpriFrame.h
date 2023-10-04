#include "Packet.h"
class EcpriFrame :
    public Packet
{

private:
    // TODO: Implement setters.
    void setConcatinationIndicator();
    void setMessageType();
    void setPayloadSize();
    void setProtocolVersion();
    void setRtcID();
    void setSequenceID();

public:
    EcpriFrame(std::string line, std::string type);

    void setFrameParameters();
    void setECPRIParameters();

    // TODO: implement method to display the information of e-CPRI packets
    void displayInformation();

};

