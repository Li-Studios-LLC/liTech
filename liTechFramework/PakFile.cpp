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

liPakFile* liPakFile::Read(liStr path) {
	liPakFile* pak = liNew<liPakFile>(path);
	FILE* file = fopen(path.CStr(), "rb");
	pakHeader_t header;
	fread(&header, sizeof(pakHeader_t), 1, file);
	pak->files.Reserve(header.fileCount);

	for (ulong_t i = 0; i < header.fileCount; i++) {
		pakEntry_t entry;
		fread(&entry, sizeof(pakEntry_t), 1, file);
		pak->entries.Push(entry);
	}

	for (ulong_t i = 0; i < header.fileCount; i++) {
		pakEntry_t entry = pak->entries[i];
		void* blob = liAlloc(entry.size);
		fread(blob, entry.size, 1, file);
		pak->files.Push(blob);
		pak->offset += entry.size;
	}

	fclose(file);
	return pak;
}

bool liPakFile::FileExists(liStr path) {
	return _GetEntry(path) != nullptr;
}

bool liPakFile::ReadFile(liStr path, liCharBuffer& buffer) {
	ulong_t index = 0;
	pakEntry_t* entry = _GetEntry(path, &index);
	if (entry == nullptr) {
		return false;
	}
	buffer = liCharBuffer((char*)files[index], entry->size);
	return true;
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
	ulong_t index = 0;
	pakEntry_t* entry = _GetEntry(path, &index);
}

pakHeader_t liPakFile::_ConstructHeader() {
	pakHeader_t header = { 0 };
	memcpy(header.signature, LIPAK_SIGNATURE, 4);
	header.fileCount = entries.Size();
	header.timestamp = time(0);
	for (ulong_t i = 0; i < entries.Size(); i++) {
		header.blobSize += entries[i].size;
	} 
	return header;
}

pakEntry_t* liPakFile::_GetEntry(liStr path, ulong_t* index) {
	for (ulong_t i = 0; i < entries.Size(); i++) {
		if (path == entries[i].name) {
			*index = i;
			return &entries[i];
		}
	}
	return nullptr;
}