#include "pch.h"
#include "FileIO.h"

bool liFileIO::Read(std::string path, std::string& output) {
    std::string newPath = std::string(LI_ASSET_PATH + path);
    SDL_IOStream* stream = SDL_IOFromFile(newPath.c_str(), "rb");
    if(stream == nullptr) {
        return false;
    }
    SDL_SeekIO(stream, 0, SDL_IO_SEEK_END);
    ulong_t size = SDL_TellIO(stream);
    SDL_SeekIO(stream, 0, SDL_IO_SEEK_SET);
    output.resize(size);
    SDL_ReadIO(stream, output.data(), size);
    SDL_CloseIO(stream);
    return true;
}

bool liFileIO::Write(std::string path, const std::string& input) {
    return true;
}