#ifndef LITECHFRAMEWORK_FILESYSTEM_H
#define LITECHFRAMEWORK_FILESYSTEM_H
#include "Typedefs.h"
#include "IFileSystem.h"
#include "LocalFileSystem.h"

class LITECH_EXPORT liFileSystem : public IFileSystem {
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

	bool FileExists(liStr path) override;
	bool ReadFile(liStr path, liCharBuffer& buffer) override;
	void WriteFile(liStr path, liCharBuffer buffer) override;
	void CreateDirectory(liStr path) override;
	void DeleteFile(liStr path) override;
private:
	IFileSystem* _DetermineSystem(const liStr& path);

	liLocalFileSystem* local;
};

#endif