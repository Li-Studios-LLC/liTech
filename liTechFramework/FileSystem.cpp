#include "FileSystem.h"

liFileSystem::liFileSystem() {
	this->local = liNew<liLocalFileSystem>();
}

liFileSystem::~liFileSystem() {
	liDelete(local);
	for (ulong_t i = 0; i < paks.Size(); i++) {
		liDelete(paks[i]);
	}
}

liPakFile* liFileSystem::CreatePak(liStr path) {
	liPakFile* pak = liNew<liPakFile>(path);
	paks.Push(pak);
	return pak;
}

liPakFile* liFileSystem::GetPak(liStr path) {
	return nullptr;
}

bool liFileSystem::FileExists(liStr path) {
	return _DetermineSystem(path)->FileExists(path);;
}

bool liFileSystem::ReadFile(liStr path, liCharBuffer& buffer) {
	return _DetermineSystem(path)->ReadFile(path, buffer);
}

void liFileSystem::WriteFile(liStr path, liCharBuffer buffer) {
	_DetermineSystem(path)->WriteFile(path, buffer);
}

void liFileSystem::CreateDirectory(liStr path) {
	_DetermineSystem(path)->CreateDirectory(path);
}

void liFileSystem::DeleteFile(liStr path) {
	_DetermineSystem(path)->DeleteFile(path);
}

IFileSystem* liFileSystem::_DetermineSystem(const liStr& path) {
	if (path.Contains("local://")) {
		return local;
	}
	return nullptr;
}