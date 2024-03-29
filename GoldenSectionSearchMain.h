/***************************************************************
 * Name:      GoldenSectionSearchMain.h
 * Purpose:   Defines Application Frame
 * Author:    Daniil Pendikov (danilpendikov@gmail.com)
 * Created:   2014-05-02
 * Copyright: Daniil Pendikov (https://vk.com/id40362369)
 * License:
 **************************************************************/

#ifndef GOLDENSECTIONSEARCHMAIN_H
#define GOLDENSECTIONSEARCHMAIN_H

//(*Headers(GoldenSectionSearchFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class GoldenSectionSearchFrame: public wxFrame
{
    public:

        GoldenSectionSearchFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GoldenSectionSearchFrame();

    private:

        //(*Handlers(GoldenSectionSearchFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(GoldenSectionSearchFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GoldenSectionSearchFrame)
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GOLDENSECTIONSEARCHMAIN_H
