/////////////////////////////////////////////////////////////////////////////
// Name:        wx/msw/scrolwin.h
// Purpose:     wxScrolledWindow class
// Author:      Torsten Landschoff
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_MSW_SCROLLWIN_H_
#define _WX_MSW_SCROLLWIN_H_

// ----------------------------------------------------------------------------
// wxScrolledWindow
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxScrollHelperNative : public wxScrollHelper
{
public:
    // default ctor doesn't do anything
    wxScrollHelperNative(wxWindow *win) : wxScrollHelper(win) { }

    void ShowScrollbars(wxScrollbarVisibility horz,
                        wxScrollbarVisibility vert);

private:
    DECLARE_NO_COPY_CLASS(wxScrollHelperNative)
};

#endif // _WX_MSW_SCROLLWIN_H_
