#version 320 es
precision mediump float;

out vec4 outColor;

in VS_OUT {
    vec2 texCoords;
} vsIn;

layout (std140, binding = 1) uniform PixelUniform {
    int padding[4];
};

uniform sampler2D fbo;

void main() {
    outColor = texture(fbo, vsIn.texCoords);
}