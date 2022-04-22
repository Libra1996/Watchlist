#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class App : public wxApp
{
public:
  virtual bool OnInit() override;
};


