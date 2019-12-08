/***************************************************************
 * Name:      GUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Samuel Javal ()
 * Created:   2019-07-16
 * Copyright: Samuel Javal ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "GUIMain.h"

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
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
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


GUIMain::GUIMain(wxFrame *frame)
    : MyFrame(frame)
{

}

GUIMain::~GUIMain()
{
}

void GUIMain::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void GUIMain::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void GUIMain::OnAbout(wxCommandEvent &event)
{
    /*
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
    */
}
