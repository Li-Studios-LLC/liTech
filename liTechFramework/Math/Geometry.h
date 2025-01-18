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
        this->hash = 0;
    }

    liGeometry(VertexList vertices, liUIntBuffer indices) {
        this->vertices = vertices;
        this->indices = indices;
        CalculateHash();
    }

    ~liGeometry() {
    }

    void AddVertex(VertexType vertex) {
        vertices.push_back(vertex);
        CalculateHash();
    }

    void AddIndex(uint_t index) {
        indices.push_back(index);
        CalculateHash();
    }

    void AddPoint(VertexType vertex) {
        vertices.push_back(vertex);
        CalculateHash();
    }

    void AddLine(VertexType point0, VertexType point1) {
        vertices.push_back(point0);
        vertices.push_back(point1);
        CalculateHash();
    }

    void AddTriangle(VertexType point0, VertexType point1, VertexType point2) {
        vertices.push_back(point0);
        vertices.push_back(point1);
        vertices.push_back(point2);
        CalculateHash();
    }

    void Clear() {
        vertices.clear();
        indices.clear();
        this->hash = 0;
    }

    void CalculateHash() {
        this->hash = 0;
    }
    
    LITECH_INLINE VertexType* Vertices() { return vertices.data(); }
    LITECH_INLINE uint_t* Indices() { return indices.data(); }

    LITECH_INLINE ulong_t VertexCount() const { return vertices.size(); }
    LITECH_INLINE ulong_t IndexCount() const { return indices.size(); }
    LITECH_INLINE ulong_t Hash() const { return hash; }
private:
    std::vector<VertexType> vertices;
    liUIntBuffer indices;
    ulong_t hash;
};

#endif