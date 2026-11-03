#include <iostream>
#include <iomanip>
#include "mtf.h"
using namespace std;

void print_string(vector<uint8_t> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << "0x" << hex << setw(2) << setfill('0') << +data[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    MTF mtf;

     vector<uint8_t> in = {0xaa, 0xbb, 0xaa, 0xbb, 0xcc, 0xcc, 0xff, 0xff, 0xff, 0xff};

    vector<uint8_t> original = { 'a', 'b', 'r', 'a', 'c', 'a', 'd', 'a', 'b', 'r', 'a' };
    cout << "Original = ";
    print_string(original);
    vector<uint8_t> encode = mtf.encode(original, 1);
    cout << "Encode = ";
    print_string(encode);
    vector<uint8_t> decode = mtf.decode(encode, 1);
    cout << "Decode = ";
    print_string(decode);
    return 0;
}