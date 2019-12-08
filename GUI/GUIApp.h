/***************************************************************
 * Name:      GUIApp.h
 * Purpose:   Defines Application Class
 * Author:    Samuel Javal ()
 * Created:   2019-07-16
 * Copyright: Samuel Javal ()
 * License:
 **************************************************************/

#ifndef GUIAPP_H
#define GUIAPP_H

#include <wx/app.h>

class GUIApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // GUIAPP_H
