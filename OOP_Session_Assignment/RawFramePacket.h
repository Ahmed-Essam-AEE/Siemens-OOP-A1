#pragma once

#include "Packet.h"

using namespace std;

class RawFramePacket : private Packet{
    private:
        void parse() override;

    public:
        RawFramePacket(string packet);
        void print() override;
};