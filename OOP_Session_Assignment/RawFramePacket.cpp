#include "RawFramePacket.h"

RawFramePacket::RawFramePacket(string packet):Packet(packet){
	parse();
}

void RawFramePacket::parse(){
	parseCommon();
}

void RawFramePacket::print(){
	cout << "Packet: " << packet << endl;
	cout << "Preambles: " << preambles.value << endl;
	cout << "CRC: " << crc.value << endl;
	cout << "Destination Address: " << destinationAddress.value << endl;
	cout << "Source Address: " << sourceAddress.value << endl;
	cout << "Type: " << type.value << endl;
	cout << "Data: " << data.value << endl;
}