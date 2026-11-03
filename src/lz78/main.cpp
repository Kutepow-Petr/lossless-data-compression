#include <iostream>
#include <fstream>
#include <iomanip>
#include "lz78.h"
using namespace std;

void print_string(vector<uint8_t> string) {
    for (auto s : string) {
        cout << "0x" << hex << setw(2) << setfill('0') << +s << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    LZ78 lz78;
    vector<uint8_t> original = { 'b', 'a', 'r', 'a', 'b', 'a', 'n' };
    cout << "Original = ";
    print_string(original);
    vector<uint8_t> encode = lz78.encode(original);
    cout << "Encode = ";
    print_string(encode);
    vector<uint8_t> decode = lz78.decode(encode);
    cout << "Decode = ";
    print_string(decode);
    return 0;
}