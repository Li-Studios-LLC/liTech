#ifndef COMPONENTS_H
#define COMPONENTS_H
#pragma once

class liDataFile;

namespace ImGui {
    class FileBrowser;
}

template<typename T>
struct IEditorComponent {
    IEditorComponent() {
        this->output = nullptr;
    }
    
    virtual ~IEditorComponent() {
        if(output != nullptr) {
            delete output;
        }
    }

    virtual void Draw() = 0;

    T* Output() { return output; }
protected:
    T* output;
};

struct liDataFileEditor : public IEditorComponent<liDataFile> {
public:
    virtual void Draw() override;
private:
};

#endif