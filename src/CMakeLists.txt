cmake_minimum_required(VERSION 3.15)
project(MultiProjectCollection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# algorithms
add_executable(arithmetic "arithmetic/main.cpp" "arithmetic/arithmetic.cpp")
add_executable(bwt "bwt/main.cpp" "bwt/bwt.cpp")
add_executable(huffman "huffman/main.cpp" "huffman/huffman.cpp")
add_executable(lz77 "lz77/main.cpp" "lz77/lz77.cpp")
add_executable(lz78 "lz78/main.cpp" "lz78/lz78.cpp")
add_executable(lzss "lzss/main.cpp" "lzss/lzss.cpp")
add_executable(lzw "lzw/main.cpp" "lzw/lzw.cpp")
add_executable(mtf "mtf/main.cpp" "mtf/mtf.cpp")
add_executable(rle "rle/main.cpp" "rle/rle.cpp" "rle/rle-flag.cpp" "rle/rle-group.cpp")

# compressors
add_executable(bwt+mtf+rle+huffman-compressor "compressors/bwt+mtf+rle+huffman.cpp" "bwt/bwt.cpp" "mtf/mtf.cpp" "rle/rle-group.cpp" "huffman/huffman.cpp" "file-reader.cpp")
add_executable(bwt+rle-compressor "compressors/bwt+rle.cpp" "bwt/bwt.cpp" "rle/rle-group.cpp" "file-reader.cpp")
add_executable(bwt+mtf+huffman-compressor "compressors/bwt+mtf+huffman.cpp" "bwt/bwt.cpp" "mtf/mtf.cpp" "huffman/huffman.cpp" "file-reader.cpp")
add_executable(huffman-compressor "compressors/huffman.cpp" "huffman/huffman.cpp" "file-reader.cpp")
add_executable(lzss-compressor "compressors/lzss.cpp" "lzss/lzss.cpp" "file-reader.cpp")
add_executable(lzss+huffman-compressor "compressors/lzss+huffman.cpp" "lzss/lzss.cpp" "huffman/huffman.cpp" "file-reader.cpp")
add_executable(lzw-compressor "compressors/lzw.cpp" "lzw/lzw.cpp" "file-reader.cpp")
add_executable(lzw+huffman-compressor "compressors/lzw+huffman.cpp" "lzw/lzw.cpp" "huffman/huffman.cpp" "file-reader.cpp")
add_executable(rle-compressor "compressors/rle.cpp" "rle/rle-group.cpp" "file-reader.cpp")