//
// Created by 戴宇昂 on 2022/7/7.
//

#include "frame.h"

EditorFrame::EditorFrame()
        : wxFrame(nullptr, wxID_ANY, "Hello World") {
    auto *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    auto *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetSize(500, 500);
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &EditorFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &EditorFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &EditorFrame::OnExit, this, wxID_EXIT);
}

void EditorFrame::OnExit(wxCommandEvent &event) {
    std::cout << "123";
    Close(false);
}

void EditorFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void EditorFrame::OnHello(wxCommandEvent &event) {
    wxLogMessage("Hello world from wxWidgets!");
}
