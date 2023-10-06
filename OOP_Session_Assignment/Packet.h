#pragma once

#include <iostream>
#include <string>

#include "Parameter.h"

using namespace std;

class Packet {
	protected:
		string packet;
		Parameter preambles = {.startByte = 0, .sizeInBytes = 8};
		Parameter crc = {.sizeInBytes = 4};
		Parameter destinationAddress = {.startByte = 8, .sizeInBytes = 6};
		Parameter sourceAddress = {.startByte = 14, .sizeInBytes = 6};
		Parameter type = {.startByte = 20, .sizeInBytes = 2};
		Parameter data = {.startByte = 22};
		void parseCommon();
		virtual void parse() = 0;
		virtual void print() = 0;
	public:
		Packet(string packet){
			this->packet = packet;
			crc.startByte = (packet.length() - crc.sizeInBytes *2) / 2;
			data.sizeInBytes = crc.startByte - data.startByte;
		}
};