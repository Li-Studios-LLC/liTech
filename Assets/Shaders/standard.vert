#version 320 es
precision mediump float;

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

out VS_OUT {
    vec2 texCoords;
    vec3 normals;
    vec3 pixelPos;
} vsOut;

layout (std140, binding = 0) uniform VertexUniform {
    mat4 projection;
    mat4 view;
    mat4 model;
};

void main() {
    vec4 pos = model * vec4(position, 1);
    gl_Position = projection * view * pos;
    vsOut.texCoords = texCoord;
    vsOut.normals = normal;
    vsOut.pixelPos = pos.xyz;
}