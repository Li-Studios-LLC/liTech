#include "pch.h"
#include "Asset.h"

liAsset::liAsset() {
    GenerateGUID();
}

void liAsset::GenerateGUID() {
    std::memset((void*)&guid, 0, sizeof(guid_t));
    const char* letters = "1234567890abcdef";
    for(ulong_t i = 0; i < LI_GUID_LENGTH; i++) {
        char c = letters[SDL_rand(LI_GUID_LENGTH)];
        guid.id[i] = c;
    }
}

void liAsset::SetGUID(guid_t guid) {
    this->guid = guid;
}