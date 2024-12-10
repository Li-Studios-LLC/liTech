#ifndef MP_LOCALFILESYSTEM_H
#define MP_LOCALFILESYSTEM_H
#include "Typedefs.h"
#include "IFileSystem.h"

#define LITECH_LOCALFS_PREFIX "local://"

class liLocalFileSystem : public IFileSystem {
public:
	liLocalFileSystem();
	liLocalFileSystem(const liLocalFileSystem&) = delete;
	~liLocalFileSystem();

	bool FileExists(liStr path) override;
	bool ReadFile(liStr path, liCharBuffer& buffer) override;
	void WriteFile(liStr path, liCharBuffer buffer) override;
	void CreateDirectory(liStr path) override;
	void DeleteFile(liStr path) override;
private:
	liStr base;
	ulong_t localLength;
	liStr _ConvertPath(liStr relativePath) override;
};

#endif