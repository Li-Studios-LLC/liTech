#ifndef DATAFILE_H
#define DATAFILE_H
#pragma once

#define LI_DATA_FILE_SIGNATURE "LIDF"

struct dataFileHeader_t {
    char signature[4];
    ulong_t timestamp;
    ulong_t nodes;
};

struct dataFileNode_t {
    char name[16];
};

class liDataFile {
public:
    liDataFile();
    ~liDataFile();

    liCharBuffer ToBuffer() const;
private:
    void _CreateHeader();

    dataFileHeader_t header;
};

#endif