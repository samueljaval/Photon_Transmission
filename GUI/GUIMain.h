/***************************************************************
 * Name:      GUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    Samuel Javal ()
 * Created:   2019-07-16
 * Copyright: Samuel Javal ()
 * License:
 **************************************************************/

#ifndef GUIMAIN_H
#define GUIMAIN_H



#include "GUIApp.h"


#include "GUIFrame.h"

class GUIMain: public MyFrame
{
    public:
        GUIMain(wxFrame *frame);
        ~GUIMain();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // GUIMAIN_H
