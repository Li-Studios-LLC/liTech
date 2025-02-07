#include "Texture.h"

liTexture::liTexture() {
    Initialize();
}

liTexture::~liTexture() {
    Delete();
}

void liTexture::Initialize() {
    glGenTextures(1, &handles[0]);
}

void liTexture::Delete() {
    glDeleteTextures(1, &handles[0]);
}