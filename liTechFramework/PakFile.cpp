#include "PakFile.h"

liPakFile::liPakFile(liStr path) {
	this->path = path;
	this->offset = 0;
}

liPakFile::~liPakFile() {
	for (ulong_t i = 0; i < files.Size(); i++) {
		liFree(files[i]);
	}
}

void liPakFile::Save() {
	pakHeader_t header = _ConstructHeader();

	FILE* file = fopen(path.CStr(), "wb");
	fwrite(&header, sizeof(pakHeader_t), 1, file);
	fwrite(&entries[0], sizeof(pakEntry_t) * header.fileCount, 1, file);
	for (ulong_t i = 0; i < files.Size(); i++) {
		fwrite(files[i], entries[i].size, 1, file);
	}

	fclose(file);
}

bool liPakFile::FileExists(liStr path) {
	for (ulong_t i = 0; i < entries.Size(); i++) {
		if (path == entries[i].name)
			return true;
	}
	return false;
}

bool liPakFile::ReadFile(liStr path, liCharBuffer& buffer) {
	return false;
}

void liPakFile::WriteFile(liStr path, liCharBuffer buffer) {
	void* memory = (void*)buffer.Data();
	pakEntry_t entry = { 0 };
	strcpy(entry.name, path.CStr());
	entry.size = buffer.Size();
	entry.offset = offset;
	entries.Push(entry);

	void* copy = liAlloc(buffer.Size());
	memcpy(copy, memory, buffer.Size());
	files.Push(copy);
	this->offset += entry.size;
}

void liPakFile::CreateDirectory(liStr path) {
	liAssert::Assert(false, "liPakFile doesn't use directories!");
}

void liPakFile::DeleteFile(liStr path) {
}

pakHeader_t liPakFile::_ConstructHeader() {
	pakHeader_t header = { 0 };
	memcpy(header.signature, LIPAK_SIGNATURE, 4);
	header.fileCount = entries.Size();
	header.timestamp = time(0);
	for (ulong_t i = 0; i < entries.Size(); i++) {
		header.fileSize += entries[i].size;
	} 
	return header;
}