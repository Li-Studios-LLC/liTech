#ifndef LITECHFRAMEWORK_PAK_H
#define LITECHFRAMEWORK_PAK_H
#include "Typedefs.h"
#include "IFileSystem.h"

#define LIPAK_SIGNATURE "_PAK"

struct pakHeader_t {
	char signature[4];
	uint_t timestamp;
	uint_t fileCount;
	ulong_t fileSize;
	char padding[8];
};

struct pakEntry_t {
	char name[32];
	ulong_t size;
	ulong_t offset;
	char padding[16];
};

class liPakFile : public IFileSystem {
public:
	liPakFile(liStr path);
	liPakFile(const liPakFile&) = delete;
	~liPakFile();

	void Save();

	bool FileExists(liStr path) override;
	bool ReadFile(liStr path, liCharBuffer& buffer) override;
	void WriteFile(liStr path, liCharBuffer buffer) override;
	void CreateDirectory(liStr path) override;
	void DeleteFile(liStr path) override;
private:
	pakHeader_t _ConstructHeader();

	liStr path;
	ulong_t offset;
	liList<pakEntry_t> entries;
	liList<void*> files;
};

#endif