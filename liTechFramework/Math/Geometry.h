#ifndef LITECHFRAMEWORK_GEOMETRY_H
#define LITECHFRAMEWORK_GEOMETRY_H
#include "Utility/Resource.h"

struct liVertex3D {
    liVector3f position;
    liVector2f texCoord;
    liVector3f normal;
};

template <class VertexType = liVertex3D>
class liGeometry : public liResource {
public:
    using VertexList = std::vector<VertexType>;

    liGeometry() {
    }

    liGeometry(VertexList vertices, liUIntBuffer indices) {
        this->vertices = vertices;
        this->indices = indices;
    }

    ~liGeometry() {
    }

    void AddVertex(VertexType vertex) {
        vertices.push_back(vertex);
    }

    void AddIndex(uint_t index) {
        indices.push_back(index);
    }

    void Clear() {
        vertices.clear();
        indices.clear();
    }

    void CalculateHash() {
        this->hash = 0;
    }

    LITECH_INLINE ulong_t Hash() const { return hash; }
private:
    std::vector<VertexType> vertices;
    liUIntBuffer indices;
    ulong_t hash;
};

#endif