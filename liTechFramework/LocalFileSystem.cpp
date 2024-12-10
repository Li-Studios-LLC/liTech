#include "LocalFileSystem.h"

liLocalFileSystem::liLocalFileSystem() {
	this->base = SDL_GetCurrentDirectory();
	base.Append('/');
	this->localLength = strlen(LITECH_LOCALFS_PREFIX);
}

liLocalFileSystem::~liLocalFileSystem() {
}

bool liLocalFileSystem::FileExists(liStr path) {
	FILE* file = fopen(_ConvertPath(path).CStr(), "r");
	bool exists = file != nullptr;
	if(exists) {
		fclose(file);
		return true;
	} else {
		return false;
	}
}

bool liLocalFileSystem::ReadFile(liStr path, liCharBuffer& buffer) {
	FILE* file = fopen(_ConvertPath(path).CStr(), "rb");
	if(!file) {
		return false;
	}
	fseek(file, 0, SEEK_END);
	ulong_t len = ftell(file);
	rewind(file);
	buffer.Resize(len);
	fread(&buffer[0], len, 1, file);
	fclose(file);
	return true;
}

void liLocalFileSystem::WriteFile(liStr path, liCharBuffer buffer) {
	FILE* file = fopen(_ConvertPath(path).CStr(), "wb");
	fwrite(&buffer[0], buffer.Size(), 1, file);
	fclose(file);
}

void liLocalFileSystem::CreateDirectory(liStr path) {
	SDL_CreateDirectory(_ConvertPath(path).CStr());
}

void liLocalFileSystem::DeleteFile(liStr path) {
	SDL_RemovePath(_ConvertPath(path).CStr());
}

liStr liLocalFileSystem::_ConvertPath(liStr relativePath) {
	LITECH_ASSERT(relativePath.Contains(LITECH_LOCALFS_PREFIX), "Path requires prefix!");
	liStr result = base;
	result.Append(liStr(relativePath.CStr(), localLength));
	return result;
}