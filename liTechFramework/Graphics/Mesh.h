#ifndef LITECHFRAMEWORK_MESH_H
#define LITECHFRAMEWORK_MESH_H
#include "GraphicsObject.h"
#include "Math/Lib.h"

class liMesh : public liGraphicsObject<3> {
public:
    liMesh();
    liMesh(liGeometry<>* geometry);
    ~liMesh();

    void Initialize() override;
    void Delete() override;
    void CalculateHash() override;

    void Draw();
private:
    liGeometry<>* geometry;
};

#endif