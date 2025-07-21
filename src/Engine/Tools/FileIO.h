#ifndef FILEIO_H
#define FILEIO_H
#pragma once

class liFileIO {
public:
    static bool Read(std::string path, liCharBuffer& output);
    static bool Write(std::string path, const liCharBuffer& input);
};

#endif