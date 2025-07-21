#include "pch.h"
#include "DataFileExplorer.h"
#include "imgui/imgui.h"
#include "imgui/imfilebrowser.h"
#include <Engine/Input/Keyboard.h>

liDataFileExplorer::liDataFileExplorer(gameContext_t context)
    : liGame(context) {
    Setup();

    this->dataFile = nullptr;
    this->browser = new ImGui::FileBrowser();
    browser->SetTitle("Data File Browser");
    browser->SetTypeFilters({ ".dat" });
}

liDataFileExplorer::~liDataFileExplorer() {
    delete browser;
    if(dataFile != nullptr) {
        delete dataFile;
    }
}

void liDataFileExplorer::Setup() {
    liGame::Setup();
}

void liDataFileExplorer::Render() {
}

void liDataFileExplorer::Update(float deltaTime) {
}

void liDataFileExplorer::ImGui() {
    liKeyboard* keyboard = Keyboard();
    browser->Display();

    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("New")) {
                if(dataFile != nullptr) {
                    delete dataFile;
                }
                this->dataFile = new liDataFile();
            }
            if (ImGui::MenuItem("Open", "Ctrl+O")) {
                browser->Open();
            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) {
            }
            if (ImGui::MenuItem("Save as..")) {
                browser->Open();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    if(ImGui::Begin("Data File Explorer")) {
        ImGui::End();
    }
}