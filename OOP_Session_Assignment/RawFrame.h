#include "Packet.h"
class RawFrame :
    public Packet
{
public:
    RawFrame(std::string line, std::string type);

    // TODO implement method to display the information of raw packets
    void displayInformation();
};

