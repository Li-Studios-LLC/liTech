#ifndef LITECHFRAMEWORK_FILESYSTEM_H
#define LITECHFRAMEWORK_FILESYSTEM_H
#include "Typedefs.h"
#include "IFileSystem.h"
#include "LocalFileSystem.h"
#include "PakFile.h"

class liFileSystem : public IFileSystem {
public:
	static liFileSystem* Instance() {
		static liFileSystem* instance = nullptr;
		if (!instance) {
			instance = liNew<liFileSystem>();
		}
		return instance;
	}

	liFileSystem();
	liFileSystem(const liFileSystem&) = delete;
	~liFileSystem();

	liPakFile* CreatePak(liStr path);
	liPakFile* GetPak(liStr path);

	bool FileExists(liStr path) override;
	bool ReadFile(liStr path, liCharBuffer& buffer) override;
	void WriteFile(liStr path, liCharBuffer buffer) override;
	void CreateDirectory(liStr path) override;
	void DeleteFile(liStr path) override;
private:
	IFileSystem* _DetermineSystem(const liStr& path);

	liLocalFileSystem* local;
	liList<liPakFile*> paks;
};

#endif