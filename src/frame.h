//
// Created by 戴宇昂 on 2022/7/7.
//

#ifndef EDITOR_FRAME_H
#define EDITOR_FRAME_H
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class EditorFrame : public wxFrame {
public:
    EditorFrame();

private:
    void OnHello(wxCommandEvent &event);

    void OnExit(wxCommandEvent &event);

    void OnAbout(wxCommandEvent &event);
};

enum {
    ID_Hello = 1
};


#endif //EDITOR_FRAME_H
