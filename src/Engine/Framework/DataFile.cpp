#include "DataFile.h"
#include "pch.h"

liDataFile::liDataFile() {
}

liDataFile::~liDataFile() {
}

liCharBuffer liDataFile::ToBuffer() const {
    std::stringstream ss;
    ss.write((const char*)&header, sizeof(dataFileHeader_t));

    liCharBuffer buffer;
    ulong_t size = ss.tellg();
    buffer.resize(size);
    std::memcpy(buffer.data(), ss.str().data(), size);
    return buffer;
}

void liDataFile::_CreateHeader() {
    std::memset((void*)&header, 0, sizeof(dataFileHeader_t));
    std::strcpy(header.signature, LI_DATA_FILE_SIGNATURE);
}