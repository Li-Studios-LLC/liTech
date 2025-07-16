#version 320 es
precision mediump float;

out vec4 outColor;

in VS_OUT {
    vec2 texCoords;
    vec3 normals;
    vec3 pixelPos;
} vsIn;

layout (std140, binding = 1) uniform PixelUniform {
    int type;
    vec4 color;
};

layout (std140, binding = 2) uniform Lighting {
    int padding;
};

void main() {
    outColor = color;
}