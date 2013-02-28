/////////////////////////////////////////////////////////////////////////////
// Name:        msw/scrolwin.cpp
// Purpose:     wxScrolledWindow implementation
// Author:      Robert Roebling
// Modified by: Torsten Landschoff
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// ============================================================================
// declarations
// ============================================================================

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "wx/scrolwin.h"

// ============================================================================
// implementation
// ============================================================================

// ----------------------------------------------------------------------------
// wxScrollHelper implementation
// ----------------------------------------------------------------------------

void wxScrollHelperNative::ShowScrollbars(
        wxScrollbarVisibility horz, wxScrollbarVisibility vert)
{
    // Call base class first to save the new values, as hiding the scroll bars
    // caused a size event which caused an update of the scroll bars making
    // them visible again.

    wxScrollHelper::ShowScrollbars(horz, vert);

    HWND winhnd = GetHwndOf(m_win);
    bool show_horizontal = (horz != wxSHOW_SB_NEVER);
    bool show_vertical = (vert != wxSHOW_SB_NEVER);
    if (!::ShowScrollBar(winhnd, SB_HORZ, show_horizontal))
        wxLogLastError(wxT("ShowScrollBar"));
    if (!::ShowScrollBar(winhnd, SB_VERT, show_vertical))
        wxLogLastError(wxT("ShowScrollBar"));
}
