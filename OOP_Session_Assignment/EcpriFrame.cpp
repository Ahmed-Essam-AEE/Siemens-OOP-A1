#include "EcpriFrame.h"
using namespace std;

EcpriFrame::EcpriFrame(string line, string type):Packet(line)
{
	this->type = type;
	setFrameParameters();
    setECPRIParameters();
}

void EcpriFrame::setConcatinationIndicator(string c){
    this->ConcatinationIndicator = c;
}
string EcpriFrame::getConcatinationIndicator(){
    return this->ConcatinationIndicator;
}

void EcpriFrame::setMessageType(string m){
    this->MessageType = m;
}
string EcpriFrame::getMessageType(){
    return this->MessageType;
}

void EcpriFrame::setPayloadSize(string p){
    this->PayloadSize = p;
}
string EcpriFrame::getPayloadSize(){
    return PayloadSize;
}

void EcpriFrame::setProtocolVersion(string p){
    this->ProtocolVersion = p;
}
string EcpriFrame::getProtocolVersion(){
    this->ProtocolVersion;
}

void EcpriFrame::setRtcID(string r){
    this->RtcID = r;
}
string EcpriFrame::getRtcID(){
    return this->RtcID;
}

void EcpriFrame::setSequenceID(string s){
    this->SequenceID = s;
}
string EcpriFrame::getSequenceID(){
    return this->SequenceID;
}

void EcpriFrame::setFrameParameters()
{
	Packet::setFrameParameters();
}

void EcpriFrame::setECPRIParameters()
{
    string c;
    c = this->packetLine[45];
    setConcatinationIndicator(c);
    c = this->packetLine[46] + this->packetLine[47];
    setMessageType(c);
    c = this->packetLine[48] + this->packetLine[49] + this->packetLine[50] + this->packetLine[51];
    setPayloadSize(c);
    c = this->packetLine[44];
    setProtocolVersion(c);
    c = this->packetLine[52] + this->packetLine[53] + this->packetLine[54] + this->packetLine[55];
    setRtcID(c);
    c = this->packetLine[56] + this->packetLine[57] + this->packetLine[58] + this->packetLine[59];
    setSequenceID(c);
}
