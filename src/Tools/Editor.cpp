#include "pch.h"
#include "Editor.h"
#include "imgui/imgui.h"
#include "imgui/imfilebrowser.h"
#include <Engine/Input/Keyboard.h>

liEditor::liEditor(gameContext_t context)
    : liGame(context) {
    Setup();
}

liEditor::~liEditor() {
}

void liEditor::Setup() {
    liGame::Setup();

    this->dataEditor = new liDataFileEditor();
}

void liEditor::Render() {
}

void liEditor::Update(float deltaTime) {
}

void liEditor::ImGui() {
    liKeyboard* keyboard = Keyboard();

    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("New")) {
            }
            if (ImGui::MenuItem("Open", "Ctrl+O")) {
            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) {
            }
            if (ImGui::MenuItem("Save as..")) {
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit")) {
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Help")) {
            if (ImGui::MenuItem("About")) {
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    dataEditor->Draw();
}