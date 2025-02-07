#include "Texture2D.h"
#include "Utility/Hash.h"

void liTexture2D::Load(void* data, uint_t width, uint_t height, uint_t bpp, textureFormat_t format, textureWrap_t wrap, textureFilter_t filter, bool mipmaps) {
    this->width = width;
    this->height = height;
    this->bpp = bpp;
    this->format = format;
    this->wrap = wrap;
    this->filter = filter;
    this->mipmaps = mipmaps;
    ulong_t bufferSize = 0;
    switch(format) {
    case textureFormat_t::BYTE:
        bufferSize = width * height * bpp;
        break;
    }

    int glFormat;
    switch(bpp) {
    case 1:
        glFormat = GL_RED;
        break;
    case 2:
        glFormat = GL_RG;
        break;
    case 3:
        glFormat = GL_RGB;
        break;
    case 4:
        glFormat = GL_RGBA;
        break;
    }

    int glMinFilter, glMagFilter;
    switch(filter) {
    case textureFilter_t::LINEAR:
        glMinFilter = mipmaps ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR;
        glMagFilter = GL_LINEAR;
        break;
    case textureFilter_t::NEAREST:
        glMinFilter = mipmaps ? GL_NEAREST_MIPMAP_LINEAR : GL_NEAREST;
        glMagFilter = GL_NEAREST;    
        break;
    }

    this->hash = liTechHashBuffer(data, bufferSize);

    glBindTexture(GL_TEXTURE_2D, handles[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, glFormat, width, height, 0, glFormat, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, glMinFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, glMagFilter);
    if(mipmaps) {
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
}

void liTexture2D::Bind(uint_t unit) {
    this->unit = unit;
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, handles[0]);
}

void liTexture2D::Unbind() {
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void liTexture2D::GenerateMipmaps() {
    this->mipmaps = true;
    glBindTexture(GL_TEXTURE_2D, handles[0]);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}