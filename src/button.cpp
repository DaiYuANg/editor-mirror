//
// Created by 戴宇昂 on 2022/7/17.
//

#include "button.h"
#include <stdio.h>
#include <wx/panel.h>
#include <wx/button.h>

[[maybe_unused]] Button::Button(const wxString &title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 150)) {
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit"),
                                    wxPoint(20, 20));
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(Button::OnQuit));
    button->SetFocus();
    Centre();
}

void Button::OnQuit(wxCommandEvent & WXUNUSED(event)) {
    printf("123");
}
