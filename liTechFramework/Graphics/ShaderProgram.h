#ifndef LITECHFRAMEWORK_SHADER_PROGRAM_H
#define LITECHFRAMEWORK_SHADER_PROGRAM_H
#include "Shader.h"

class liShaderProgram : public liGraphicsObject<1> {
public:
    liShaderProgram();
    ~liShaderProgram();

    virtual void Initialize() override;
    virtual void Delete() override;
    virtual void CalculateHash() override;

    int Link(shaderType_t type);
    void SetVertex(liShader* vertex);
    void SetPixel(liShader* pixel);
    void SetCompute(liShader* compute);
    void Bind() const;
    static void Unbind();
private:
    void _Attach(liShader* shader);

    liShader* vertex, *pixel, *compute;
};

#endif