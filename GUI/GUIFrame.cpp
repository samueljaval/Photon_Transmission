///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	this->SetBackgroundColour( wxColour( 199, 199, 199 ) );

	wxGridSizer* Biggest_sizer;
	Biggest_sizer = new wxGridSizer( 0, 2, 0, 0 );
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	wxBoxSizer* source_sizer;
	source_sizer = new wxBoxSizer( wxVERTICAL );

	source_text = new wxStaticText( this, wxID_ANY, wxT("SOURCE"), wxPoint( 325,-1 ), wxSize( 650,-1 ), 0 );
	source_text->Wrap( -1 );
	source_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	source_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	source_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	source_sizer->Add( source_text, 0, wxALL, 5 );

	wxBoxSizer* fromfile_source_sizer;
	fromfile_source_sizer = new wxBoxSizer( wxHORIZONTAL );

	fromfile_source_sizer->SetMinSize( wxSize( 650,0 ) );
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	from_file_text = new wxStaticText( this, wxID_ANY, wxT("From File : "), wxDefaultPosition, wxDefaultSize, 0 );
	from_file_text->Wrap( -1 );
	from_file_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	from_file_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	from_file_text->SetBackgroundColour( wxColour( 199, 199, 199 ) );

	bSizer28->Add( from_file_text, 0, wxALL, 5 );

	from_file_button = new wxButton( this, wxID_ANY, wxT("..."), wxDefaultPosition, wxSize(70,-1), 0 );
	bSizer28->Add( from_file_button, 0, wxALL, 5 );


	fromfile_source_sizer->Add( bSizer28, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	nb_photons_text = new wxStaticText( this, wxID_ANY, wxT("Number of Photons"), wxDefaultPosition, wxDefaultSize, 0 );
	nb_photons_text->Wrap( -1 );
	nb_photons_text->SetFont( wxFont( 12, 70, 90, 90, false, wxEmptyString ) );
	nb_photons_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	nb_photons_text->SetBackgroundColour( wxColour( 199, 199, 199 ) );

	bSizer30->Add( nb_photons_text, 0, wxALL, 5 );

	nb_photons_value = new wxTextCtrl( this, wxID_ANY, wxT("1000000"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( nb_photons_value, 0, wxALL, 5 );


	fromfile_source_sizer->Add( bSizer30, 1, wxEXPAND, 5 );


	source_sizer->Add( fromfile_source_sizer, 1, wxEXPAND, 5 );

    modify_data_sizer = new wxBoxSizer( wxHORIZONTAL );

    add_row_button = new wxButton( this, wxID_ANY, wxT("add row"), wxDefaultPosition, wxDefaultSize, 0 );
    remove_row_button = new wxButton( this, wxID_ANY, wxT("remove row"), wxDefaultPosition, wxDefaultSize, 0 );
    save_button = new wxButton( this, wxID_ANY, wxT("save data"), wxDefaultPosition, wxDefaultSize, 0 );

    modify_data_sizer->Add(add_row_button, 0, wxALL, 1);
    modify_data_sizer->Add(remove_row_button, 0, wxALL, 1);
    modify_data_sizer->Add(save_button, 0, wxALL, 1);
	source_sizer->Add(modify_data_sizer, 5, wxEXPAND, 5);


	wxBoxSizer* source_values_sizer;
	source_values_sizer = new wxBoxSizer( wxVERTICAL );

	spectrum_list = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( 640,170 ));
	spectrum_list->SetMinSize( wxSize( 1000000,100000 ) );
	spectrum_list->CreateGrid(1,2);
	spectrum_list->SetColLabelValue(0,wxT("Energy (MeV)"));
    spectrum_list->SetColLabelValue(1,wxT("Intensity (-)"));

	source_values_sizer->Add( spectrum_list, 0, wxALL, 5 );

	source_sizer->Add( source_values_sizer, 1, wxEXPAND, 5 );

	Biggest_sizer->Add( source_sizer, 1, wxEXPAND, 5 );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////:
	wxBoxSizer* medium_sizer;
	medium_sizer = new wxBoxSizer( wxVERTICAL );

	medium_text = new wxStaticText( this, wxID_ANY, wxT("MEDIUM"), wxDefaultPosition, wxSize( 650,-1 ), 0 );
	medium_text->Wrap( -1 );
	medium_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	medium_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	medium_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	medium_sizer->Add( medium_text, 0, wxALL, 5 );

	wxBoxSizer* fromfile_medium_sizer;
	fromfile_medium_sizer = new wxBoxSizer( wxHORIZONTAL );

	medium_fromfile_text = new wxStaticText( this, wxID_ANY, wxT("From File : "), wxDefaultPosition, wxDefaultSize, 0 );
	medium_fromfile_text->Wrap( -1 );
	medium_fromfile_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	medium_fromfile_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	medium_fromfile_text->SetBackgroundColour( wxColour( 199, 199, 199 ) );

	fromfile_medium_sizer->Add( medium_fromfile_text, 0, wxALL, 5 );

	medium_fromfile_button = new wxButton( this, wxID_ANY, wxT("..."), wxDefaultPosition, wxSize(70,-1) , 0 );
	fromfile_medium_sizer->Add( medium_fromfile_button, 0, wxALL, 5 );

	medium_sizer->Add( fromfile_medium_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* thickdens_sizer;
	thickdens_sizer = new wxBoxSizer( wxHORIZONTAL );

	thick_text = new wxStaticText( this, wxID_ANY, wxT("Thickness :  "), wxDefaultPosition, wxDefaultSize, 0 );
	thick_text->Wrap( -1 );
	thick_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	thick_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	thick_text->SetBackgroundColour( wxColour( 199, 199, 199 ) );

	thickdens_sizer->Add( thick_text, 0, wxALL, 5 );

	thick_button = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	thickdens_sizer->Add( thick_button, 0, wxALL, 5 );

	dens_text = new wxStaticText( this, wxID_ANY, wxT("Density :  "), wxDefaultPosition, wxDefaultSize, 0 );
	dens_text->Wrap( -1 );
	dens_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	dens_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	dens_text->SetBackgroundColour( wxColour( 199, 199, 199 ) );

	thickdens_sizer->Add( dens_text, 0, wxALL, 5 );

	dens_button = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	thickdens_sizer->Add( dens_button, 0, wxALL, 5 );


	medium_sizer->Add( thickdens_sizer, 1, wxEXPAND, 5 );

	modify_data_sizer_medium = new wxBoxSizer( wxHORIZONTAL );

	add_row_button_medium = new wxButton( this, wxID_ANY, wxT("add row"), wxDefaultPosition, wxDefaultSize, 0 );
    remove_row_button_medium = new wxButton( this, wxID_ANY, wxT("remove row"), wxDefaultPosition, wxDefaultSize, 0 );
    save_button_medium = new wxButton( this, wxID_ANY, wxT("save data"), wxDefaultPosition, wxDefaultSize, 0 );

    modify_data_sizer_medium->Add(add_row_button_medium, 0, wxALL, 1);
    modify_data_sizer_medium->Add(remove_row_button_medium, 0, wxALL, 1);
    modify_data_sizer_medium->Add(save_button_medium, 0, wxALL, 1);
	medium_sizer->Add(modify_data_sizer_medium, 5, wxEXPAND, 5);


	wxBoxSizer* medium_list_sizer;
	medium_list_sizer = new wxBoxSizer( wxVERTICAL );

	medium_list = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( 640,170 ));
	medium_list->SetMinSize( wxSize( 10000000,100000000 ) );
    medium_list->CreateGrid(1,2);
    medium_list->SetColLabelValue(0,wxT("Z"));
    medium_list->SetColLabelValue(1,wxT("Fraction"));



	medium_list_sizer->Add( medium_list, 0, wxALL, 5 );


	medium_sizer->Add( medium_list_sizer, 1, wxEXPAND, 5 );

	Biggest_sizer->Add( medium_sizer, 1, wxEXPAND, 5 );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	wxBoxSizer* tally_sizer;
	tally_sizer = new wxBoxSizer( wxVERTICAL );

	tally_text = new wxStaticText( this, wxID_ANY, wxT("TALLY"), wxDefaultPosition, wxSize( 650,-1 ), 0 );
	tally_text->Wrap( -1 );
	tally_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	tally_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	tally_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	tally_sizer->Add( tally_text, 0, wxALL, 5 );

	wxBoxSizer* tally_subsizer;
	tally_subsizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* tally_left_sizer;
	tally_left_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* backscattered_sizer;
	backscattered_sizer = new wxBoxSizer( wxVERTICAL );

	back_text = new wxStaticText( this, wxID_ANY, wxT("Backscatterred"), wxDefaultPosition, wxDefaultSize, 0 );
	back_text->Wrap( -1 );
	back_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	back_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	backscattered_sizer->Add( back_text, 0, wxALL, 5 );


	tally_left_sizer->Add( backscattered_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* transmitted_sizer;
	transmitted_sizer = new wxBoxSizer( wxVERTICAL );

	transmit_text = new wxStaticText( this, wxID_ANY, wxT("Transmitted"), wxDefaultPosition, wxDefaultSize, 0 );
	transmit_text->Wrap( -1 );
	transmit_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	transmit_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	transmitted_sizer->Add( transmit_text, 0, wxALL, 5 );


	tally_left_sizer->Add( transmitted_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* doserate_sizer;
	doserate_sizer = new wxBoxSizer( wxVERTICAL );

	doserate_text = new wxStaticText( this, wxID_ANY, wxT("Doserate Function"), wxDefaultPosition, wxDefaultSize, 0 );
	doserate_text->Wrap( -1 );
	doserate_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	doserate_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

	doserate_sizer->Add( doserate_text, 0, wxALL, 5 );


	tally_left_sizer->Add( doserate_sizer, 1, wxEXPAND, 5 );


	tally_subsizer->Add( tally_left_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* right_sizer;
	right_sizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* up;
	up = new wxBoxSizer( wxVERTICAL );

	wxArrayString selection_upChoices;
	ValorizeEnergyGrids(selection_upChoices);
	selection_up = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, selection_upChoices, 0 );
	selection_up->SetSelection( 0 );
	up->Add( selection_up, 0, wxALL, 5 );


	right_sizer->Add( up, 1, wxEXPAND, 5 );

	wxBoxSizer* middle;
	middle = new wxBoxSizer( wxVERTICAL );

	selection_middle = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, selection_upChoices, 0 );
	selection_middle->SetSelection( 0 );
	middle->Add( selection_middle, 0, wxALL, 5 );


	right_sizer->Add( middle, 1, wxEXPAND, 5 );

	wxBoxSizer* down;
	down = new wxBoxSizer( wxVERTICAL );

	wxArrayString selection_downChoices;
	ValorizeFlux2Dose(selection_downChoices);
	selection_down = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, selection_downChoices, 0 );
	selection_down->SetSelection( 0 );
	down->Add( selection_down, 0, wxALL, 5 );


	right_sizer->Add( down, 1, wxEXPAND, 5 );


	tally_subsizer->Add( right_sizer, 1, wxEXPAND, 5 );


	tally_sizer->Add( tally_subsizer, 1, wxEXPAND, 5 );


	Biggest_sizer->Add( tally_sizer, 1, wxEXPAND, 5 );


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	wxBoxSizer* results_sizer;
	results_sizer = new wxBoxSizer( wxVERTICAL );

	results_text = new wxStaticText( this, wxID_ANY, wxT("RESULTS"), wxDefaultPosition, wxSize( 650,-1 ), 0 );
	results_text->Wrap( -1 );
	results_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	results_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	results_text->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	results_sizer->Add( results_text, 0, wxALL, 5 );

	wxBoxSizer* results_subsizer;
	results_subsizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* left_sizer_results;
	left_sizer_results = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* atten_sizer;
	atten_sizer = new wxBoxSizer( wxVERTICAL );

	atten_text = new wxStaticText( this, wxID_ANY, wxT("Attenuation Factor : " ), wxDefaultPosition, wxDefaultSize, 0 );
	atten_text->Wrap( -1 );
	atten_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	atten_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );

	atten_sizer->Add( atten_text, 0, wxALL, 5 );


	left_sizer_results->Add( atten_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* transmit_sizer_results;
	transmit_sizer_results = new wxBoxSizer( wxVERTICAL );

	transmit_text_results = new wxStaticText( this, wxID_ANY, wxT("Transmitted Spectra : "), wxDefaultPosition, wxDefaultSize, 0 );
	transmit_text_results->Wrap( -1 );
	transmit_text_results->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	transmit_text_results->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );

	transmit_sizer_results->Add( transmit_text_results, 0, wxALL, 5 );


	left_sizer_results->Add( transmit_sizer_results, 1, wxEXPAND, 5 );

	wxBoxSizer* reflect_sizer;
	reflect_sizer = new wxBoxSizer( wxVERTICAL );

	reflect_text = new wxStaticText( this, wxID_ANY, wxT("Reflected Spectra  : "), wxDefaultPosition, wxDefaultSize, 0 );
	reflect_text->Wrap( -1 );
	reflect_text->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	reflect_text->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );

	reflect_sizer->Add( reflect_text, 0, wxALL, 5 );


	left_sizer_results->Add( reflect_sizer, 1, wxEXPAND, 5 );


	results_subsizer->Add( left_sizer_results, 1, wxEXPAND, 5 );

	wxBoxSizer* right_sizer_results;
	right_sizer_results = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* top_sizer;
	top_sizer = new wxBoxSizer( wxVERTICAL );

	att_value = new wxTextCtrl( this, wxID_ANY, wxT("TBD"), wxDefaultPosition, wxSize(200,-1) , 0 );
	att_value->Enable( false );
	att_uncer = new wxTextCtrl( this, wxID_ANY, wxT("TBD"), wxDefaultPosition, wxSize(200,-1) , 0 );
	att_uncer->Enable( false );

	top_sizer->Add( att_value, 0, wxALL, 5 );
	top_sizer->Add(att_uncer, 0, wxALL, 5);


	right_sizer_results->Add( top_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* visu1_sizer;
	visu1_sizer = new wxBoxSizer( wxVERTICAL );

	visu_transmit = new wxButton( this, wxID_ANY, wxT("visualize"), wxDefaultPosition, wxDefaultSize, 0 );
	visu1_sizer->Add( visu_transmit, 0, wxALL, 5 );


	right_sizer_results->Add( visu1_sizer, 1, wxEXPAND, 5 );

	wxBoxSizer* visu2_sizer;
	visu2_sizer = new wxBoxSizer( wxVERTICAL );

	visu_reflect = new wxButton( this, wxID_ANY, wxT("visualize"), wxDefaultPosition, wxDefaultSize, 0 );
	visu2_sizer->Add( visu_reflect, 0, wxALL, 5 );


	right_sizer_results->Add( visu2_sizer, 1, wxEXPAND, 5 );


	results_subsizer->Add( right_sizer_results, 1, wxEXPAND, 5 );


	results_sizer->Add( results_subsizer, 1, wxEXPAND, 5 );


	Biggest_sizer->Add( results_sizer, 1, wxEXPAND, 5 );


	this->SetSizer( Biggest_sizer );
	this->Layout();
	MenuBar = new wxMenuBar( 0 );
	m_fichier = new wxMenu();
	wxMenuItem* m_print;
	m_print = new wxMenuItem( m_fichier, wxID_ANY, wxString( wxT("Print") ) , wxEmptyString, wxITEM_NORMAL );
	m_fichier->Append( m_print );

	wxMenuItem* m_quit;
	m_quit = new wxMenuItem( m_fichier, wxID_ANY, wxString( wxT("Quit") ) , wxEmptyString, wxITEM_NORMAL );
	m_fichier->Append( m_quit );

	MenuBar->Append( m_fichier, wxT("File") );

	m_calculate = new wxMenu();
	wxMenuItem* m_run;
	m_run = new wxMenuItem( m_calculate, wxID_ANY, wxString( wxT("Run") ) , wxEmptyString, wxITEM_NORMAL );
	m_calculate->Append( m_run );

	MenuBar->Append( m_calculate, wxT("Calculate") );

	m_apropos = new wxMenu();
	wxMenuItem* m_about;
	m_about = new wxMenuItem( m_apropos, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_apropos->Append( m_about );

	MenuBar->Append( m_apropos, wxT("About") );

	this->SetMenuBar( MenuBar );

	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	Connect(m_run->GetId(), wxEVT_MENU, wxCommandEventHandler(MyFrame::m_runOnMenuSelection));
	Connect(m_print->GetId(), wxEVT_MENU, wxCommandEventHandler(MyFrame::m_printOnMenuSelection));
	Connect(m_about->GetId(), wxEVT_MENU, wxCommandEventHandler(MyFrame::m_aboutOnMenuSelection));
	Connect(m_quit->GetId(), wxEVT_MENU, wxCommandEventHandler(MyFrame::m_quitOnMenuSelection));
	from_file_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::from_file_buttonOnButtonClick ), NULL, this );
	remove_row_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::remove_row_buttonOnButtonClick ), NULL, this );
	remove_row_button_medium->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::remove_row_button_mediumOnButtonClick ), NULL, this );
	save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_buttonOnButtonClick ), NULL, this );
	save_button_medium->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_button_mediumOnButtonClick ), NULL, this );
	add_row_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::add_row_buttonOnButtonClick ), NULL, this );
	add_row_button_medium->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::add_row_button_mediumOnButtonClick ), NULL, this );
	medium_fromfile_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::medium_fromfile_buttonOnButtonClick ), NULL, this );
	visu_transmit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::visu_transmitOnButtonClick ), NULL, this );
	visu_reflect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::visu_reflectOnButtonClick ), NULL, this );
}

#include "wx/dir.h"
void MyFrame::ValorizeEnergyGrids(wxArrayString& as)
{
    wxString path = wxT(".\\Data\\EnergyGrids");
    wxDir dir(path);
    if ( !dir.IsOpened() ) return;
    wxString filename;
    wxString filespec = wxT("");
    bool cont = dir.GetFirst(&filename, filespec, wxDIR_FILES|wxDIR_DIRS);
    while ( cont )
    {
        as.Add(filename);
        cont = dir.GetNext(&filename);
    }
}
void MyFrame::ValorizeFlux2Dose(wxArrayString& as)
{
    wxString path = wxT(".\\Data\\Flux2DoseConversion");
    wxDir dir(path);
    if ( !dir.IsOpened() ) return;
    wxString filename;
    wxString filespec = wxT("");
    bool cont = dir.GetFirst(&filename, filespec, wxDIR_FILES|wxDIR_DIRS);
    while ( cont )
    {
        as.Add(filename);
        cont = dir.GetNext(&filename);
    }
}

#include "wx/filedlg.h"
void MyFrame::from_file_buttonOnButtonClick( wxCommandEvent& event )
{
    wxFileDialog dialog(this,_T("Choose a file"),_T("c:"),_T(""),_T(""),wxFD_OPEN);
    if (dialog.ShowModal() == wxID_OK)
    {
        wxString path = dialog.GetPath();

        filename_spectrum = path;

        m_statusBar->SetStatusText(wxT("The file " + filename_spectrum + " was chosen"));
        ReadAndSpit(path, spectrum_list);
    }
}


void MyFrame::medium_fromfile_buttonOnButtonClick( wxCommandEvent& event )
{
     wxFileDialog dialog(this,_T("Choose a file"),_T("c:"),_T(""),_T(""),wxFD_OPEN);
    if (dialog.ShowModal() == wxID_OK)
    {
        wxString path = dialog.GetPath();

        filename_medium = path;

        m_statusBar->SetStatusText(wxT("The file " + filename_medium + " was chosen"));
        ReadAndSpit(path, medium_list);
    }
}

#include "wx/wfstream.h"    /// for wxFileInputStream
#include "wx/txtstrm.h"     /// for wxTextInputStream

void MyFrame::ReadAndSpit(const wxString& file, wxGrid* grid)
{
    wxFileInputStream input(file);
    wxTextInputStream text(input);
    wxString f;
    vector<wxString> E;
    vector<wxString> I;
    while (input.Eof() == false)
    {
        grid->AppendRows(1,true);
        text >> f;
        E.push_back(f);
        text >> f;
        I.push_back(f);
    }
    for (int i = 0; i<E.size() ; i++)
    {
        grid->SetCellValue(i,0,E[i]);
        grid->SetCellValue(i,1,I[i]);
    }
    grid->DeleteRows(E.size(), E.size(),true);
}

#include <wx/textdlg.h>
#include <wx/textfile.h>
void MyFrame::save_buttonOnButtonClick(wxCommandEvent& event)
{
    wxTextEntryDialog dlg(this, wxT("SAVE AS :"), wxT("will go in ./Data/Spectra. You can only enter letters"));
    dlg.SetTextValidator(wxFILTER_ALPHA);
    wxString name;
    if ( dlg.ShowModal() == wxID_OK )
    {
        name = wxT(".\\Data\\Spectra\\") + dlg.GetValue();
    }
    wxFileOutputStream out(name);
    wxTextOutputStream text(out);
    for (int i = 0 ; i < spectrum_list->GetNumberRows() ; i++)
    {
         text << spectrum_list->GetCellValue(i,0) << wxT("    ") << spectrum_list->GetCellValue(i,1)  << wxT('\n');
    }
}

void MyFrame::save_button_mediumOnButtonClick(wxCommandEvent& event)
{
    wxTextEntryDialog dlg(this, wxT("SAVE AS :"), wxT("will go in ./Data/Materials. You can only enter letters"));
    dlg.SetTextValidator(wxFILTER_ALPHA);
    wxString name;
    if ( dlg.ShowModal() == wxID_OK )
    {
        name = wxT(".\\Data\\Materials\\") +dlg.GetValue();
    }
    wxFileOutputStream out(name);
    wxTextOutputStream text(out);
    for (int i = 0 ; i < spectrum_list->GetNumberRows() ; i++)
    {
         text << medium_list->GetCellValue(i,0) << wxT("    ") << medium_list->GetCellValue(i,1)  << wxT('\n');
    }
}

void MyFrame::CreateInputFile()
{
    wxFileOutputStream out(wxT("inputFile"));
    wxTextOutputStream text(out);
    text << wxT("###################") << wxT('\n')
         << wxT("PHOTON_NUMBER") << wxT("   ") << nb_photons_value->GetValue() << wxT('\n')
         << wxT("SOURCE") << wxT("   ") << spectrum_list->GetNumberRows() << wxT('\n');
    for (int i = 0; i < spectrum_list->GetNumberRows(); i++)
    {
        text << spectrum_list->GetCellValue(i,0) << wxT("  ") << spectrum_list->GetCellValue(i,1) << wxT('\n');
    }
    text << wxT("MEDIUM") << wxT("  ") << medium_list->GetNumberRows()
                          << wxT("  ") << thick_button->GetValue() << wxT("  ") << dens_button->GetValue() << wxT('\n');
    for (int i = 0; i < medium_list->GetNumberRows(); i++)
    {
        text << medium_list->GetCellValue(i,0) << wxT("  ") << medium_list->GetCellValue(i,1) << wxT('\n');
    }
    text << wxT("TALLY") << wxT("  ") << 3 << wxT("   ") << wxT("BACKSCATTERED") << wxT("  ") << wxT(".\\Data\\EnergyGrids\\") + selection_up->GetString(selection_up->GetSelection()) << wxT('\n');
    text << wxT("TRANSMITTED") << wxT("  ") << wxT(".\\Data\\EnergyGrids\\") + selection_middle->GetString(selection_middle->GetSelection()) << wxT('\n');
    text <<  wxT("DOSERATE") << wxT("  ") << wxT(".\\Data\\Flux2DoseConversion\\") + selection_down->GetString(selection_down->GetSelection()) << wxT('\n');
    text << wxT("###################") << wxT('\n');
}

void MyFrame::m_runOnMenuSelection(wxCommandEvent& event)
{
    CreateInputFile();
    m_statusBar->SetStatusText(wxT("CALCULATING... see console to track progress"));
    wxExecute(wxT("BigProjectFinal.exe inputFile"), wxEXEC_SHOW_CONSOLE | wxEXEC_SYNC);
    m_statusBar->SetStatusText(wxT("Calculations done, see folder containing GUI.exe for more details"));
    wxString atten;
    wxString uncer;
    wxFileInputStream input(wxT("doserate.log"));
    wxTextInputStream text(input);
    for (int i = 0; i < 7; i++) text >> atten;
    for (int i = 0; i < 7; i++) text >> uncer;
    att_value->Enable(true);
    att_value->SetValue(atten);
    att_value->Enable(false);
    att_uncer->Enable(true);
    att_uncer->SetValue(wxT("+- ") + uncer);
    att_uncer->Enable(false);
}

#include <wx/tipwin.h>
#include <wx/msgdlg.h>
void MyFrame::m_aboutOnMenuSelection(wxCommandEvent& event)
{
    wxString text = wxT("This program was written by Samuel Javal with the help of Laurent Bindel. It is the property of the Nuvia - Millennium company.");
    wxString text2 = wxT(" It was written during Samuel Javal's 2 month long internship at the company. There is no error handling in the program but it was designed to be relatively simple enough");
    wxString text3 = wxT( " for the user to notice their input errors. Created July 2019");
    wxString tot = text +text2 +text3;
    wxMessageDialog about(this,tot);
    about.ShowModal();
}

void MyFrame::m_printOnMenuSelection(wxCommandEvent& event)
{
    wxString text = wxT("Just take a screenshot. What did you expect? I can't do everything for you");
    wxMessageDialog print(this, text);
    print.ShowModal();
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	from_file_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::from_file_buttonOnButtonClick ), NULL, this );
	remove_row_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::remove_row_buttonOnButtonClick ), NULL, this );
	remove_row_button_medium->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::remove_row_button_mediumOnButtonClick ), NULL, this );
	save_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_buttonOnButtonClick ), NULL, this );
	save_button_medium->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_button_mediumOnButtonClick ), NULL, this );
	add_row_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::add_row_buttonOnButtonClick ), NULL, this );
	add_row_button_medium->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::add_row_button_mediumOnButtonClick ), NULL, this );
	medium_fromfile_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::medium_fromfile_buttonOnButtonClick ), NULL, this );
	visu_transmit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::visu_transmitOnButtonClick ), NULL, this );
	visu_reflect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::visu_reflectOnButtonClick ), NULL, this );
}
