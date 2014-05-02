/***************************************************************
 * Name:      GoldenSectionSearchMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Daniil Pendikov (danilpendikov@gmail.com)
 * Created:   2014-05-02
 * Copyright: Daniil Pendikov (https://vk.com/id40362369)
 * License:
 **************************************************************/

#include "GoldenSectionSearchMain.h"
#include <wx/msgdlg.h>
#include "expression_parser.h"

//(*InternalHeaders(GoldenSectionSearchFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GoldenSectionSearchFrame)
const long GoldenSectionSearchFrame::ID_TEXTCTRL1 = wxNewId();
const long GoldenSectionSearchFrame::ID_BUTTON1 = wxNewId();
const long GoldenSectionSearchFrame::ID_STATICTEXT1 = wxNewId();
const long GoldenSectionSearchFrame::idMenuQuit = wxNewId();
const long GoldenSectionSearchFrame::idMenuAbout = wxNewId();
const long GoldenSectionSearchFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GoldenSectionSearchFrame,wxFrame)
    //(*EventTable(GoldenSectionSearchFrame)
    //*)
END_EVENT_TABLE()

GoldenSectionSearchFrame::GoldenSectionSearchFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GoldenSectionSearchFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(56,176), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(224,176), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Enter a function and the program will try to find the extremum: "), wxPoint(48,24), wxSize(168,32), 0, _T("ID_STATICTEXT1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GoldenSectionSearchFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GoldenSectionSearchFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GoldenSectionSearchFrame::OnAbout);
    //*)
}

GoldenSectionSearchFrame::~GoldenSectionSearchFrame()
{
    //(*Destroy(GoldenSectionSearchFrame)
    //*)
}

void GoldenSectionSearchFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GoldenSectionSearchFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void GoldenSectionSearchFrame::OnButton1Click(wxCommandEvent& event)
{
    const char * test = "x + (x-453.45837 * 4)";
    parse_expression(test);
}
