/***************************************************************
 * Name:      GUIApp.cpp
 * Purpose:   Code for Application Class
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

#include "GUIApp.h"
#include "GUIMain.h"

IMPLEMENT_APP(GUIApp);

bool GUIApp::OnInit()
{
    MyFrame* frame = new MyFrame(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();

    return true;
}
