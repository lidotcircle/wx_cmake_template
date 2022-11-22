// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/gdicmn.h"
#include "wx/sizer.h"
#include <wx/wx.h>
#include <wx/splitter.h>
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
// wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
}
void MyFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent &event)
{
    wxLogMessage("Hello world from wxWidgets!");
}


class App2: public wxApp {
public:
    virtual bool OnInit();
};

class Frame2: public wxFrame {
public:
    Frame2(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};

bool App2::OnInit() {
    wxFrame *frame = new Frame2("I'm a demo", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}

wxBEGIN_EVENT_TABLE(Frame2, wxFrame)
EVT_MENU(ID_Hello, Frame2::OnHello)
EVT_MENU(wxID_EXIT, Frame2::OnExit)
EVT_MENU(wxID_ABOUT, Frame2::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(App2);

Frame2::Frame2(const wxString &title, const wxPoint &pos, const wxSize &size):
    wxFrame(NULL, wxID_ANY, title, pos, size)
{
    const auto addText = [](wxPanel* panel, const wxString& str) {
        auto text = new wxStaticText(panel, wxID_ANY, str);
        auto sizer = new wxBoxSizer(wxHORIZONTAL);
        sizer->Add(text, 1, wxALIGN_CENTER);
        panel->SetSizerAndFit(sizer);
    };

    auto toolbar = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 30));
    toolbar->SetBackgroundColour(wxColor(100,200,100));
    addText(toolbar, "toolbar");

    auto main_area = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 500));
    main_area->SetBackgroundColour(wxColor(200,100,100));

    auto main_sizer = new wxBoxSizer(wxVERTICAL);
    main_sizer->Add(toolbar, 0, wxEXPAND, 5);
    main_sizer->Add(main_area, 1, wxEXPAND, 10);
    this->SetSizerAndFit(main_sizer);

    auto splitter = new wxSplitterWindow(main_area, wxID_ANY, wxDefaultPosition, wxSize(800, 500), wxSP_LIVE_UPDATE | wxSP_BORDER);
    auto canavas = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxSize(700, 100));
    canavas->SetBackgroundColour(wxColor(100,100,200));
    auto navigator = new wxPanel(splitter, wxID_ANY, wxDefaultPosition, wxSize(100, 100));
    navigator->SetBackgroundColour(wxColor(200,200,100));
    addText(navigator, "navigator");
    splitter->SetMinimumPaneSize(150);
    splitter->SetSashGravity(0.5);
    splitter->SplitVertically(canavas, navigator);

    auto pn_top = new wxPanel(canavas);
    auto pn_bottom = new wxPanel(canavas);
    pn_top->SetBackgroundColour(wxColor(150, 150, 200));
    pn_bottom->SetBackgroundColour(wxColor(150, 250, 200));
    auto secondary_sizer = new wxBoxSizer(wxVERTICAL);
    secondary_sizer->Add(pn_top, 4, wxEXPAND);
    secondary_sizer->Add(pn_bottom, 1, wxEXPAND);
    canavas->SetSizerAndFit(secondary_sizer);

    auto pn_top_left = new wxPanel(pn_top);
    pn_top_left->SetBackgroundColour(wxColor(50, 80, 120));
    addText(pn_top_left, "explorer");
    auto pn_top_right = new wxPanel(pn_top);
    pn_top_right->SetBackgroundColour(wxColor(150, 180, 120));
    addText(pn_top_right, "canavas");
    auto pn_top_sizer = new wxBoxSizer(wxHORIZONTAL);
    pn_top_sizer->Add(pn_top_left, 1, 0, 10);
    pn_top_sizer->Add(pn_top_right, 4, wxEXPAND);
    pn_top->SetSizerAndFit(pn_top_sizer);

    auto pn_bottom_left = new wxPanel(pn_bottom);
    pn_bottom_left->SetBackgroundColour(wxColor(150, 80, 120));
    // addText(pn_bottom_left, "terminal");
    auto pn_bottom_right = new wxPanel(pn_bottom);
    pn_bottom_right->SetBackgroundColour(wxColor(150, 80, 120));
    addText(pn_bottom_right, "preview");
    auto pn_bottom_sizer = new wxBoxSizer(wxHORIZONTAL);
    pn_bottom_sizer->Add(pn_bottom_left, 2, 0, 10);
    pn_bottom_sizer->Add(pn_bottom_right, 3, wxEXPAND);
    pn_bottom->SetSizerAndFit(pn_bottom_sizer);
}

void Frame2::OnHello(wxCommandEvent& event) {
}

void Frame2::OnExit(wxCommandEvent& event) {
}

void Frame2::OnAbout(wxCommandEvent& event) {
}