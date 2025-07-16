#ifndef UNIFORMBUFFER_H
#define UNIFORMBUFFER_H
#pragma once

class liUniformBuffer {
public:
    liUniformBuffer(ulong_t size);
    liUniformBuffer(const liUniformBuffer&) = delete;
    ~liUniformBuffer();

    void Upload(void* data);
    void Bind(ghandle_t program, std::string name, int binding = 0);
    
    inline ghandle_t Handle() const { return handle; }
private:
    ghandle_t handle;
    ulong_t size;
};

#endif