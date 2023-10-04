#pragma once
#include <iostream>
#include <string>
#include "EcpriFrame.h"
#include "RawFrame.h"
class Packet
{
protected:
	std::string packetLine;
	std::string crc;
	std::string destinationAddress;
	std::string sourceAddress;
	std::string type;

private:
	void setCRC();
	void setDestinationAddress();
	void setSourceAddress();

public:
	Packet(std::string line); // Main Constructor

	static std::string getType(std::string line);
	static Packet DefinePacketType(std::string line);
	void setFrameParameters();

	// TODO override method to display the information of different packets
	virtual void displayInformation();

};

