#ifndef SERIALIZER_H
#define SERIALIZER_H
#pragma once

class liSerializer {
public:
    liSerializer();
    ~liSerializer();
private:
    nlohmann::json j;
};

#endif