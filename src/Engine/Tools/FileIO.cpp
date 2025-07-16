#include "pch.h"
#include "FileIO.h"

bool liFileIO::Read(std::string path, std::string& output) {
    std::ifstream stream;
    stream.open(path, std::ios::in | std::ios::binary);
    if(!stream.is_open()) {
        return false;
    }
    stream.seekg(0, std::ios::end);
    ulong_t size = stream.tellg();
    output.resize(size);
    stream.seekg(0);
    stream.read(&output[0], size);
    stream.close();
    return true;
}

bool liFileIO::Write(std::string path, const std::string& input) {
    std::ofstream stream;
    stream.open(path, std::ios::out | std::ios::binary);
    if(!stream.is_open()) {
        return false;
    }
    stream.write(input.c_str(), input.length());
    stream.close();
    return true;
}