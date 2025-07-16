#ifndef FILEIO_H
#define FILEIO_H
#pragma once

class liFileIO {
public:
    static bool Read(std::string path, std::string& output);
    static bool Write(std::string path, const std::string& input);
};

#endif