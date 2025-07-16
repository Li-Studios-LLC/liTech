#version 320 es
precision mediump float;

layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoord;

out VS_OUT {
    vec2 texCoords;
} vsOut;

void main() {
    gl_Position = vec4(position, 0, 1);
    vsOut.texCoords = texCoord;
}