#include "EcpriFrame.h"


EcpriFrame::EcpriFrame(std::string line, std::string type):Packet(line)
{
	this->type = type;
	setFrameParameters();
    setECPRIParameters();
}

void EcpriFrame::setFrameParameters()
{
	Packet::setFrameParameters();
}

void EcpriFrame::setECPRIParameters()
{
    setConcatinationIndicator();
    setMessageType();
    setPayloadSize();
    setProtocolVersion();
    setRtcID();
    setSequenceID();
}
