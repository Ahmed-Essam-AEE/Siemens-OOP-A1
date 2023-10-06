#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>


#include "EcpriPacket.h"
#include "RawFramePacket.h"

using namespace std;

int main() {    
    ifstream file("input_packets"); //taking file as inputstream
    string str;
    vector<string> packets;
    if(file.is_open()) {
        stringstream ss;
        string line;
        ss << file.rdbuf(); // reading data
        while(getline(ss, line)) {
            packets.push_back(line);
        }
    }
    file.close();

    ofstream output_file("output_packets_generated");

    if(!output_file.is_open()) {
        cout << "Error opening output file" << endl;
        return 1;
    }

    streambuf* coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(output_file.rdbuf()); //redirect std::cout to output file

    int counter = 0;
    for(auto packet : packets) {
        cout << "Packet # " << counter++ << ":" << endl;
        string packet_type = packet.substr(20 * 2, 2 * 2);
        if(packet_type == "AEFE") {
            EcpriPacket ecpriPacket(packet);
            ecpriPacket.print();
        } else if(packet_type == "88F7") {
            RawFramePacket rawFramePacket(packet);
            rawFramePacket.print();
        }
        cout << endl;
        cout << setw(230) << setfill('*') << "" << endl << endl;
    }

    cout.rdbuf(coutbuf); //reset to standard output again
    
    output_file.close();


    return 0;
}
