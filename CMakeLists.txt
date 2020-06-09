cmake_minimum_required(VERSION 3.16)
project(harc C)

set(CMAKE_C_STANDARD 11)

add_executable(harc harc.c cli.c cli.h archiver.c archiver.h extractor.c extractor.h actions.c actions.h settings.h files.c files.h huffman.c huffman.h heap.c heap.h bitset.c bitset.h structures.h)