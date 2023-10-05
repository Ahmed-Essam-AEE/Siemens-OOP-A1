#include "Packet.h"
using namespace std;
class EcpriFrame :
    public Packet
{

private:
    // TODO: Implement setters.
    string ConcatinationIndicator;
    string MessageType;
    string PayloadSize;
    string ProtocolVersion;
    string RtcID;
    string SequenceID;
    //string FrameParameters;
    //string ECPRIParameters;

public:
    EcpriFrame(string line, string type);
    void setConcatinationIndicator(string );
    void setMessageType(string MessageType);
    void setPayloadSize(string PayloadSize);
    void setProtocolVersion(string ProtocolVersion);
    void setRtcID(string RtcID);
    void setSequenceID(string SequenceID);


    string getConcatinationIndicator();
    string getMessageType();
    string getPayloadSize();
    string getProtocolVersion();
    string getRtcID();
    string getSequenceID();
    //string getFrameParameters();
    //string getECPRIParameters();

    void setFrameParameters();
    void setECPRIParameters();

    // TODO: implement method to display the information of e-CPRI packets
    void displayInformation();

};

