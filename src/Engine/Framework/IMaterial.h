#ifndef IMATERIAL_H
#define IMATERIAL_H

class liShaderProgram;
class liUniformBuffer;

class IMaterial {
public:
    virtual ~IMaterial() { }

    virtual void Bind() = 0;
    virtual void Update() = 0;

    inline void SetProgram(liShaderProgram* program) { this->program = program; }
protected:
    liShaderProgram* program;
    liUniformBuffer* vertexUniform, *pixelUniform;
};

#endif