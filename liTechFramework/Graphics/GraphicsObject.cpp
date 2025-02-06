#include "GraphicsObject.h"
#include "Utility/Hash.h"

liGraphicsObject::liGraphicsObject() {
    this->hash = 0;
    memset(handles, 0, sizeof(ghandle_t[0x10]));
}

void liGraphicsObject::CalculateHash() {
    this->hash += liTechHash(handles);
}