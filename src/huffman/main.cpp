#include <iostream>
#include <iomanip>
#include "huffman.h"
using namespace std;

void print_string(vector<uint8_t> data) {
    for (uint8_t sym : data) {
        cout << "0x" << hex << setw(2) << setfill('0') << +sym << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    Huffman huffman;
    vector<uint8_t> original = { 'a', 'b', 'r', 'a', 'c', 'a', 'd', 'a', 'b', 'r', 'a' }; 
    cout << "Original = ";
    print_string(original);

    vector<uint8_t> encode = huffman.encode(original);
    cout << "Encode = ";
    print_string(encode);

    vector<uint8_t> decode = huffman.decode(encode);
    cout << "Decode = ";
    print_string(decode);
    return 0;
}