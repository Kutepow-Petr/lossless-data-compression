#include <iostream>
#include <iomanip>
#include "rle.h"
#include "rle-flag.h"
#include "rle-group.h"
using namespace std;

void print_string(vector<uint8_t> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << "0x" << hex << setw(2) << setfill('0') << +data[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    vector<uint8_t> original = {0xAA, 0xAA, 0xAA, 0xBB, 0xAA, 0xBB, 0xAA, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xAA, 0xBB};
    cout << "Original: ";
    print_string(original);

    RLE rle_classic;
    RLE_flag rle_flag;
    RLE_group rle_group;
    vector<uint8_t> encode = rle_classic.encode(original);
    //vector<uint8_t> encode = rle_flag.encode(original);
    //vector<uint8_t> encode = rle_group.encode(original, 2, 1);
     cout << "Encode: ";
     print_string(encode);

    vector<uint8_t> decode = rle_classic.decode(encode);
    //vector<uint8_t> decode = rle_flag.encode(encode);
    //vector<uint8_t> decode = rle_group.decode(encode, 2, 1);
    cout << "Decode: ";
    print_string(decode);
    return 0;
}