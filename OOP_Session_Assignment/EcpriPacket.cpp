#include "EcpriPacket.h"

EcpriPacket::EcpriPacket(string packet):Packet(packet){
	parse();
}

void EcpriPacket::parse(){
	parseCommon();
	Parameter* parameters_pointers[]={&protocolVersion,&reserved,&concatenationIndicator,&messageType,&payloadSize,&rtcID,&seqID};
	for(auto* parameter: parameters_pointers){
		int start = parameter->startByte * 2;
		parameter->value = data.value.substr(start,parameter->sizeInBytes * 2);
	}
	data.value = data.value.substr(8 * 2);
}

void EcpriPacket::print(){
	cout << "Packet: " << packet << endl;
	cout << "Preambles: " << preambles.value << endl;
	cout << "CRC: " << crc.value << endl;
	cout << "Destination Address: " << destinationAddress.value << endl;
	cout << "Source Address: " << sourceAddress.value << endl;
	cout << "Type: " << type.value << endl;
	cout << "Protocol Version: " << protocolVersion.value << endl;
	//cout << "Reserved: " << reserved.value << endl;
	cout << "Concatenation Indicator: " << concatenationIndicator.value << endl;
	cout << "Message Type: " << messageType.value << endl;
	cout << "Payload Size: " << payloadSize.value << endl;
	cout << "RTC ID: " << rtcID.value << endl;
	cout << "Seq ID: " << seqID.value << endl;
	cout << "Data: " << data.value << endl;
}