#ifndef LITECHFRAMEWORK_SHADER_PROGRAM_H
#define LITECHFRAMEWORK_SHADER_PROGRAM_H
#include "Shader.h"

struct liVector2f;
struct liVector3f;
struct liVector4f;
struct liMatrix4f;

class liShaderProgram : public liGraphicsObject {
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

    void ClearUniforms();
    void Load(std::string name, int v);
    void Load(std::string name, float v);
    void Load(std::string name, liVector2f vec);
    void Load(std::string name, liVector3f vec);
    void Load(std::string name, liVector4f vec);
    void Load(std::string name, liMatrix4f mat);
private:
    void _Attach(liShader* shader);
    int _GetUniformLocation(std::string name);

    liShader* vertex, *pixel, *compute;
    std::unordered_map<std::string, int> uniforms;
};

#endif