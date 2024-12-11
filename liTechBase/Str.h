#ifndef LITECHBASE_STR_H
#define LITECHBASE_STR_H
#include "Typedefs.h"

class liStr {
public:
	liStr();
	liStr(const char* str);
	liStr(const liStr& str, ulong_t start);
	explicit liStr(int i);
	explicit liStr(long long ll);
	explicit liStr(unsigned u);
	explicit liStr(float f);
	explicit liStr(bool b);
	explicit liStr(char c);
	liStr(const liStr& right);
	~liStr();

	void Clear();
	void Append(char c);
	void Append(const liStr& str);
	void Resize(ulong_t newSize);
	void Reserve(ulong_t newCapacity);
	bool Contains(const liStr& str) const;
	int Find(const liStr& str) const;
	void ReplaceFirst(const liStr& oldStr, const liStr& newStr);
	void ReplaceAll(const liStr& oldStr, const liStr& newStr);

	ulong_t Length() const { return length; }
	ulong_t Capacity() const { return capacity; }
	const char* CStr() { return buffer; }
	const char* CStr() const { return buffer; }

	liStr& operator+=(char c);
	liStr& operator+=(const liStr& str);
	liStr operator+(const liStr& str);
	bool operator==(const liStr& str);
	bool operator!=(const liStr& str);
	char& operator[](int index) { return buffer[index]; }
	const char& operator[](int index) const { return buffer[index]; }
	liStr& operator=(const liStr& right);
private:
	char* buffer;
	ulong_t length, capacity;
};

#endif