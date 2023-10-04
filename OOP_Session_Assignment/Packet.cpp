#include "Packet.h"

// Packet constructor
Packet::Packet(std::string line) :packetLine(line) { // this->PacketLine = line;

}

 std::string Packet::getType(std::string line)
{
	std::string type;
	for (int i = 40; i < 44; i++) {
		type += line[i];
	}
	return type;
}

 void Packet::setCRC()
 {
	 for (int i = packetLine.size() - 9; i < packetLine.size(); i++) {
		 crc += packetLine[i];
	 }
	 
 }

 void Packet::setDestinationAddress()
 {
	 for (int i = 16; i < 28; i++) {
		 destinationAddress += packetLine[i];
	 }
 }

 void Packet::setSourceAddress()
 {
	 for (int i = 28; i < 40; i++) {
		 sourceAddress += packetLine[i];
	 }
 }

 void Packet::setFrameParameters()
 {
	 setCRC();
	 setSourceAddress();
	 setDestinationAddress();
 }

 Packet Packet::DefinePacketType(std:: string line)
{
	std::string type = getType(line);
	if (type == "AEFE")
		return  EcpriFrame(line,type);
	else
		return  RawFrame(line,type);
}
