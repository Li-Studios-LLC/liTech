#ifndef LITECHFRAMEWORK_MESH_H
#define LITECHFRAMEWORK_MESH_H
#include "GraphicsObject.h"
#include "Math/Geometry.h"

struct drawRange_t {
    uint_t start;
    long_t count;
};

#define DEFAULT_DRAW_RANGE { 0, -1 }

enum class meshTopology_t {
    POINTS,
    LINES,
    TRIANGLES
};

class liMesh : public liGraphicsObject {
public:
    liMesh();
    liMesh(liGeometry<>* geometry);
    ~liMesh();

    virtual void Initialize() override;
    virtual void Delete() override;
    virtual void CalculateHash() override;

    void Draw(drawRange_t range = DEFAULT_DRAW_RANGE, meshTopology_t topology = meshTopology_t::TRIANGLES);
private:
    liGeometry<>* geometry;
};

#endif