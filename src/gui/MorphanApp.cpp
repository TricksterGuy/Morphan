/******************************************************************************************************
 * Morphan
 * Copyright (C) 2014 Brandon Whitehead (tricksterguy87[AT]gmail[DOT]com)
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * excluding commercial applications, and to alter it and redistribute it freely,
 * subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 *    you must not claim that you wrote the original software.
 *    An acknowledgement in your documentation and link to the original version is required.
 *
 * 2. Altered source versions must be plainly marked as such,
 *    and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 ******************************************************************************************************/

#include "MorphanApp.hpp"
#include "MorphanFrame.hpp"
#include <wx/config.h>
#include <wx/dialog.h>

IMPLEMENT_APP(MorphanApp);

bool MorphanApp::OnInit()
{
    wxInitAllImageHandlers();
    wxDialog::EnableLayoutAdaptation(true);

    // Fill in the application information fields before creating wxConfig.
    SetVendorName("wxWidgets");
    SetAppName("wx_docview_sample");
    SetAppDisplayName("wxWidgets DocView Sample");

    manager = new wxDocManager();
    frame = new MorphanFrame(manager, NULL);
    manager->CreateNewDocument();
    SetTopWindow(frame);
    frame->Centre();
    frame->Show();

    frame->UpdateStatusBar();

    return true;
}

int MorphanApp::OnExit()
{
    manager->FileHistorySave(*wxConfig::Get());
    delete manager;
    return wxApp::OnExit();
}
