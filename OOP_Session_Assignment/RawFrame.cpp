#include "RawFrame.h"

RawFrame::RawFrame(std::string line, std::string type):Packet(line)
{
	this->type = type;
	setFrameParameters();
}
