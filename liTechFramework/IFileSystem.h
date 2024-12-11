#ifndef LITECHFRAMEWORK_IFILESYSTEM_H
#define LITECHFRAMEWORK_IFILESYSTEM_H

struct IFileSystem {
	virtual ~IFileSystem() {}

	virtual bool FileExists(liStr path) = 0;
	virtual bool ReadFile(liStr path, liCharBuffer& buffer) = 0;
	virtual void WriteFile(liStr path, liCharBuffer buffer) = 0;
	virtual void CreateDirectory(liStr path) = 0;
	virtual void DeleteFile(liStr path) = 0;
protected:
	virtual liStr _ConvertPath(liStr relativePath) { return liStr(); };
};

#endif