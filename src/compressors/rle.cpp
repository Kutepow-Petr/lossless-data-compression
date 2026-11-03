#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdint>
#include "../file-reader.h"
#include "../rle/rle-group.h"
using namespace std;

int main(int argc, char* argv[]) {
    RLE_group rle;
    cout << "Enter file path: ";
    string file_path;
    cin >> file_path;
    file_path.erase(remove(file_path.begin(), file_path.end(), '\"'), file_path.end());
    int dot_pos = file_path.find_last_of('.');
    int slash_pos = file_path.find_last_of('\\') + 1;
    string file_name = file_path.substr(slash_pos, dot_pos - slash_pos);
    string extension = file_path.substr(dot_pos);
    vector<uint8_t> original = read_file(file_path);

    vector<uint8_t> encode = rle.encode(original, 1, 1);
    vector_to_file(encode, "./" + file_name + "_encode.bin");

    vector<uint8_t> decode = rle.decode(encode, 1, 1);
    vector_to_file(decode, "./" + file_name + "_decode" + extension);
    return 0;
}