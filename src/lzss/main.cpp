#include <iostream>
#include <iomanip>
#include "lzss.h"
using namespace std;

void print_string(vector<uint8_t> data) {
    for (auto sym : data) {
        cout << "0x" << hex << setw(2) << setfill('0') << +sym << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    LZSS lzss;
    vector<uint8_t> original = { 'b', 'a', 'r', 'a', 'b', 'a', 'n', 'b', 'a', 'r', 'a', 'b', 'a', 'n', 'a', 'b', 'r', 'a', 'c', 'a', 'd', 'a', 'b', 'r', 'a'};
    cout << "Original = ";
    print_string(original);
    vector<uint8_t> encode = lzss.encode(original, 20);
    cout << "Encode = ";
    print_string(encode);
    vector<uint8_t> decode = lzss.decode(encode);
    cout << "Decode = ";
    print_string(decode);
    return 0;
}