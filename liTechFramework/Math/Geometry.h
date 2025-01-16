#ifndef LITECHFRAMEWORK_GEOMETRY_H
#define LITECHFRAMEWORK_GEOMETRY_H

struct liVertex3D {
    liVector3f position;
    liVector2f texCoord;
    liVector3f normal;
};

template <typename VertexType = liVertex3D>
class liGeometry {
public:
private:
    std::vector<VertexType> vertices;
    std::vector<uint_t> indices;
};

#endif