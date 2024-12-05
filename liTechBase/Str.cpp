#include "Str.h"
#include "Mem.h"

#define SPRINTF_LENGTH 0x10

liStr::liStr() {
    this->buffer = nullptr;
    this->length = 0;
    this->capacity = 0;
}

liStr::liStr(const char* str) {
    ulong_t len = strlen(str);
    this->length = len;
    this->capacity = len;
    this->buffer = liNewArray<char>(len + 1);
    strcpy(buffer, str);
}

liStr::liStr(const liStr& str, ulong_t start) {
    ulong_t len = str.length - start;
    this->length = len;
    this->capacity = len;
    this->buffer = liNewArray<char>(len + 1);
    strcpy(buffer, str.buffer + start);
}

liStr::liStr(int i) {
    char str[SPRINTF_LENGTH];
    sprintf(str, "%d", i);
    ulong_t len = strlen(str);
    this->length = len;
    this->capacity = len;
    this->buffer = liNewArray<char>(len + 1);
    strcpy(buffer, str);
}

liStr::liStr(long long ll) {
    char str[SPRINTF_LENGTH];
    sprintf(str, "%lld", ll);
    ulong_t len = strlen(str);
    this->length = len;
    this->capacity = len;
    this->buffer = liNewArray<char>(len + 1);
    strcpy(buffer, str);
}

liStr::liStr(unsigned u) {
    char str[SPRINTF_LENGTH];
    sprintf(str, "%u", u);
    ulong_t len = strlen(str);
    this->length = len;
    this->capacity = len;
    this->buffer = liNewArray<char>(len + 1);
    strcpy(buffer, str);
}

liStr::liStr(float f) {
    char str[SPRINTF_LENGTH];
    sprintf(str, "%f", f);
    ulong_t len = strlen(str);
    this->length = len;
    this->capacity = len;
    this->buffer = liNewArray<char>(len + 1);
    strcpy(buffer, str);
}

liStr::liStr(bool b) {
    const char* str;
    ulong_t len;
    if(b) {
        str = "true";
    } else {
        str = "false";
    }
    len = strlen(str);
    this->length = len;
    this->capacity = len;
    this->buffer = liNewArray<char>(len + 1);
    strcpy(buffer, str);
}

liStr::liStr(char c) {
    this->length = 2;
    this->capacity = 2;
    this->buffer = liNewArray<char>(2);
    buffer[0] = c;
    buffer[1] = '\0';
}

liStr::liStr(const liStr& right) {
    this->buffer = nullptr;
    *this = right;
}

liStr::~liStr() {
    Clear();
}

void liStr::Clear() {
    if(buffer) {
        liDeleteArray(buffer);
    }

    this->buffer = nullptr;
    this->length = 0;
    this->capacity = 0;
}
 
void liStr::Append(char c) {
    if(length == capacity) {
        Reserve(capacity == 0 ? 2 : capacity * 2);
    }

    buffer[length] = c;
    buffer[++length] = '\0';
}

void liStr::Append(const liStr& str) {
    for(ulong_t i = 0; i < str.length; i++) {
        Append(str.buffer[i]);
    }
}

void liStr::Resize(ulong_t newSize) {
    char* newBuffer = liNewArray<char>(newSize + 1);
    if(buffer) {
        strcpy(newBuffer, buffer);
        liDeleteArray(buffer);
    }
    this->capacity = newSize;
    this->length = newSize;
    this->buffer = newBuffer;
}

void liStr::Reserve(ulong_t newCapacity) {
    char* newBuffer = liNewArray<char>(newCapacity + 1);
    if(buffer) {
        strcpy(newBuffer, buffer);
        liDeleteArray(buffer);
    }
    this->capacity = newCapacity;
    this->buffer = newBuffer;
}

bool liStr::Contains(const liStr& str) const {
    return strstr(buffer, str.buffer);
}

int liStr::Find(const liStr& str) const {
    const char* pos = strstr(buffer, str.buffer);
    if(!pos) { 
        return -1;
    } else {
        return pos - buffer;
    }
}

void liStr::ReplaceFirst(const liStr& oldStr, const liStr& newStr) {
    int pos = Find(oldStr);
    if(pos == -1) {
        return;
    }
    liStr result;
    result.Resize(length - oldStr.length + newStr.length + 1);
    strncpy(result.buffer, buffer, pos);
    result[pos] = '\0';
    strcat(result.buffer, newStr.buffer);
    strcat(result.buffer, buffer + pos + oldStr.length);
    *this = result;
}

void liStr::ReplaceAll(const liStr& oldStr, const liStr& newStr) {
    int pos;
    while((pos = Find(oldStr)) != -1) {
        ReplaceFirst(oldStr, newStr);
    }
}

liStr& liStr::operator+=(char c) {
    Append(c);
    return *this;
}

liStr& liStr::operator+=(const liStr& str) {
    Append(str);
    return *this;
}

liStr liStr::operator+(const liStr& str) {
    liStr copy = *this;
    copy.Append(str);
    return copy;
}

bool liStr::operator==(const liStr& str) {
    return !strcmp(buffer, str.buffer);
}

bool liStr::operator!=(const liStr& str) {
    return !(*this == str);
}

liStr& liStr::operator=(const liStr& right) {
    Clear();
    Resize(right.length + 1);
    if(right.length > 0) {
        strcpy(buffer, right.buffer);
        this->length = right.length;
    }
    return *this;
}