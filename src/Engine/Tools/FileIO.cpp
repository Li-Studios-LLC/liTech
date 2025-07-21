#include "pch.h"
#include "FileIO.h"

bool liFileIO::Read(std::string path, liCharBuffer& output) {
    SDL_IOStream* stream = SDL_IOFromFile(path.c_str(), "rb");
    if(stream == nullptr) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, path.c_str(), "Failed to find file!", nullptr);
        return false;
    }
    SDL_SeekIO(stream, 0, SDL_IO_SEEK_END);
    ulong_t size = SDL_TellIO(stream);
    SDL_SeekIO(stream, 0, SDL_IO_SEEK_SET);
    output.resize(size);
    output.push_back('\0');
    SDL_ReadIO(stream, output.data(), size);
    SDL_CloseIO(stream);
    return true;
}

bool liFileIO::Write(std::string path, const liCharBuffer& input) {
    SDL_IOStream* stream = SDL_IOFromFile(path.c_str(), "wb");
    if(stream == nullptr) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, path.c_str(), "Failed to open file!", nullptr);
        return false;
    }
    SDL_WriteIO(stream, input.data(), input.size());
    SDL_CloseIO(stream);
    return true;
}