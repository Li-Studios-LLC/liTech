#ifndef LITECHFRAMEWORK_PAK_H
#define LITECHFRAMEWORK_PAK_H
#include "Typedefs.h"
#include "IFileSystem.h"

#define LIPAK_SIGNATURE "_PAK"

struct pakHeader_t {
	char signature[4];
	uint_t timestamp;
	uint_t fileCount;
	ulong_t blobSize;
	char padding[8];
};

struct pakEntry_t {
	char name[32];
	ulong_t size;
	ulong_t offset;
	ubyte_t flags;
	char padding[15];
};

class liPakFile : public IFileSystem {
public:
	liPakFile(liStr path);
	liPakFile(const liPakFile&) = delete;
	~liPakFile();

	void Save();
	static liPakFile* Read(liStr path);

	bool FileExists(liStr path) override;
	bool ReadFile(liStr path, liCharBuffer& buffer) override;
	void WriteFile(liStr path, liCharBuffer buffer) override;
	void CreateDirectory(liStr path) override;
	void DeleteFile(liStr path) override;
private:
	pakHeader_t _ConstructHeader();
	pakEntry_t* _GetEntry(liStr path, ulong_t* index = nullptr);

	liStr path;
	ulong_t offset;
	liList<pakEntry_t> entries;
	liList<void*> files;
};

#endif