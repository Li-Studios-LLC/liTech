#include "pch.h"
#include "Vertex.h"

liVertex::liVertex(liVec3 position, liVec2 texCoord, liVec3 normal) {
    this->position = position;
    this->texCoord = texCoord;
    this->normal = normal;
}

liVertex::liVertex() { }

void liVertex::SetPosition(liVec3 position) {
    this->position = position;
}

void liVertex::SetTexCoord(liVec2 texCoord) {
    this->texCoord = texCoord;
}

void liVertex::SetNormal(liVec3 normal) {
    this->normal = normal;
}