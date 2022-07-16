//
// Created by 戴宇昂 on 2022/7/17.
//

#ifndef EDITOR_BUTTON_H

#include <wx/frame.h>

#define EDITOR_BUTTON_H


class Button : public wxFrame {
public:
    [[maybe_unused]] Button(const wxString &title);

    void OnQuit(wxCommandEvent &event);
};


#endif //EDITOR_BUTTON_H
