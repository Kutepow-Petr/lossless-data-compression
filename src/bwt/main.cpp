#include <iostream>
#include <iomanip>
#include "bwt.h"
using namespace std;

void print_string(vector<uint8_t> string) {
    for (auto s : string) {
        cout << "0x" << hex << setw(2) << setfill('0') << +s << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    BWT bwt;
    vector<uint8_t> original = { 227, 228, 224, 32, 237, 229 };
    cout << "Original = ";
    print_string(original);

    vector<uint8_t> encode = bwt.write_blocks_display(original, 3);
    cout << "Encode = ";
    print_string(encode);

    //vector<uint8_t> decode = bwt.read_blocks_matrix(encode);
    //cout << "Decode = ";
    //print_string(decode);
    vector<uint8_t> decode = bwt.read_blocks_display(encode);
    cout << "Decode = ";
    print_string(decode);
    return 0;
}