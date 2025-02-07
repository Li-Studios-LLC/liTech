#ifndef LITECHFRAMEWORK_TEXTURE2D_H
#define LITECHFRAMEWORK_TEXTURE2D_H
#include "Texture.h"

class liTexture2D : public liTexture {
public:
	void Load(void* data, uint_t width, uint_t height, uint_t bpp, textureFormat_t format = textureFormat_t::BYTE, textureWrap_t wrap = textureWrap_t::CLAMP, textureFilter_t filter = textureFilter_t::NEAREST, bool mipmaps = false) override;
	void Bind(uint_t unit = 0) override;
	void Unbind() override;
    void GenerateMipmaps() override;
private:
    uint_t unit;
};

#endif