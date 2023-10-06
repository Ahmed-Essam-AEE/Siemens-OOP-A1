#include "Packet.h"

void Packet::parseCommon(){
	Parameter* parameters_pointers[]={&preambles,&crc,&destinationAddress,&sourceAddress,&type,&data};
	for(auto* parameter: parameters_pointers){
		int start = parameter->startByte * 2;
		parameter->value = packet.substr(start,parameter->sizeInBytes * 2);
	}
}