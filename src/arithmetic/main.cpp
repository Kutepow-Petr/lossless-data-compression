#include <iostream>
#include <iomanip>
#include "arithmetic.h"
using namespace std;

void print_string(vector<uint8_t> string) {
    for (auto s : string) {
        cout << "0x" << hex << setw(2) << setfill('0') << +s << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    Algorithmic_coding algorithmic;
    vector<uint8_t> original = { 'a', 'b', 'r', 'a', 'c', 'a', 'd', 'a', 'b', 'r', 'a' };
    cout << "Original = ";
    print_string(original);
    vector<uint8_t> encode = algorithmic.encode(original);
    cout << "Encode = ";
    algorithmic.print_encode_string(encode);
    vector<uint8_t> decode = algorithmic.decode(encode);
    cout << "Decode = ";
    print_string(decode);
    return 0;
}