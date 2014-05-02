/***************************************************************
 * Name:      GoldenSectionSearchApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Daniil Pendikov (danilpendikov@gmail.com)
 * Created:   2014-05-02
 * Copyright: Daniil Pendikov (https://vk.com/id40362369)
 * License:
 **************************************************************/

#include "GoldenSectionSearchApp.h"

//(*AppHeaders
#include "GoldenSectionSearchMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GoldenSectionSearchApp);

bool GoldenSectionSearchApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GoldenSectionSearchFrame* Frame = new GoldenSectionSearchFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
