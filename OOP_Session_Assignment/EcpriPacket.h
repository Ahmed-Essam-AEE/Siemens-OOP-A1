#pragma once

#include "Packet.h"

using namespace std;

class EcpriPacket : private Packet{
    private:
        Parameter protocolVersion = {.startByte = 0, .sizeInBytes = 0.5};
        Parameter reserved = {.startByte = 0.5, .sizeInBytes = 0.5};
        Parameter concatenationIndicator = {.startByte = 0.5, .sizeInBytes = 0.5};
        Parameter messageType = {.startByte = 1, .sizeInBytes = 1};
        Parameter payloadSize = {.startByte = 2, .sizeInBytes = 2};
        Parameter rtcID = {.startByte = 4, .sizeInBytes = 2};
        Parameter seqID = {.startByte = 6, .sizeInBytes = 2};
    	void parse() override;
    public:
        EcpriPacket(string packet);
        void print() override;
};