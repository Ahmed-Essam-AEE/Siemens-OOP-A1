#include <iostream>
#include <fstream>
#include <string>
#include "Packet.h"
using namespace std;

int main()
{
    // Reading the input file
    ifstream inputFile("input_packets");

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            Packet frame = Packet::DefinePacketType(line); // Inherting the suitable class according to data type
        }
        inputFile.close();
    }
    else {
        cout << "Failed to open the file." << endl;
    }
    return 0;

}

