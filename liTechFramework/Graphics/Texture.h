#ifndef LITECHFRAMEWORK_TEXTURE_H
#define LITECHFRAMEWORK_TEXTURE_H
#include "Typedefs.h"
#include "GraphicsObject.h"

enum class textureFormat_t {
    BYTE
};

enum class textureWrap_t {
    CLAMP,
    REPEAT
};

enum class textureFilter_t { 
    LINEAR,
    NEAREST
};

class liTexture : public liGraphicsObject {
public:
    liTexture();
    virtual ~liTexture();
    
    virtual void Initialize() override;
    virtual void Delete() override;
    // Does nothing, hash is calculated when texture is loaded.
    virtual void CalculateHash() override { }

    virtual void Load(void* data, uint_t width, uint_t height, uint_t bpp, textureFormat_t format, textureWrap_t wrap, textureFilter_t filter, bool mipmaps) = 0;
    virtual void Bind(uint_t unit) = 0;
    virtual void Unbind() = 0;
    virtual void GenerateMipmaps() = 0;
protected:
    uint_t width, height, bpp;
    textureFormat_t format;
    textureWrap_t wrap;
    textureFilter_t filter;
    bool mipmaps;
};

#endif