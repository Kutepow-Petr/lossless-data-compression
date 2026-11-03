#include <iostream>
#include <vector>
#include <cstdint>
#include <map>
#include <iomanip>
#include <algorithm>
#include "lzw.h"
using namespace std;

void print_string(vector<uint8_t> string) {
    for (auto s : string) {
        cout << "0x" << hex << setw(2) << setfill('0') << +s << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    LZW lzw;
    vector<uint8_t> original = { 'b', 'a', 'r', 'a', 'b', 'a', 'n' };
    cout << "Original = ";
    print_string(original);
    vector<uint8_t> encode = lzw.encode(original, 10);
    cout << "Encode = ";
    print_string(encode);
    vector<uint8_t> decode = lzw.decode(encode);
    cout << "Decode = ";
    print_string(decode);
    return 0;
}