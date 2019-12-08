
///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FORMBUILDER_H__
#define __FORMBUILDER_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/choice.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <fstream>
#include <string>
#include <vector>
#include <wx/numdlg.h>  //for get user number

using namespace std;

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
	private:
        void ValorizeEnergyGrids(wxArrayString&);
        void ValorizeFlux2Dose(wxArrayString&);
        void ReadSpectrum(const wxString&);
        void ReadAndSpit(const wxString&, wxGrid*);
        void CreateInputFile();

	protected:
		wxStaticText* source_text;
		wxStaticText* from_file_text;
		wxButton* from_file_button;
		wxStaticText* nb_photons_text;
		wxTextCtrl* nb_photons_value;
		wxBoxSizer* modify_data_sizer;
		wxButton* add_row_button;
		wxButton* remove_row_button;
		wxButton* save_button;
		wxGrid* spectrum_list;
		/////////////////////////////////////////////////
		wxStaticText* medium_text;
		wxStaticText* medium_fromfile_text;
		wxButton* medium_fromfile_button;
		wxStaticText* thick_text;
		wxTextCtrl* thick_button;
		wxStaticText* dens_text;
		wxTextCtrl* dens_button;
		wxBoxSizer* modify_data_sizer_medium;
        wxButton* add_row_button_medium;
        wxButton* remove_row_button_medium;
        wxButton* save_button_medium;
		wxGrid* medium_list;
		/////////////////////////////////////////////////////
		wxStaticText* tally_text;
		wxStaticText* back_text;
		wxStaticText* transmit_text;
		wxStaticText* doserate_text;
		wxChoice* selection_up;
		wxChoice* selection_middle;
		wxChoice* selection_down;
		///////////////////////////////////////////////////////
		wxStaticText* results_text;
		wxStaticText* atten_text;
		wxStaticText* transmit_text_results;
		wxStaticText* reflect_text;
		wxTextCtrl* att_value;
		wxTextCtrl* att_uncer;
		wxButton* visu_transmit;
		wxButton* visu_reflect;
		//////////////////////////////////////////////////////
		wxMenuBar* MenuBar;
		wxMenu* m_fichier;
		wxMenu* m_calculate;
		wxMenu* m_apropos;
		wxStatusBar* m_statusBar;

		// Virtual event handlers, overide them in your derived class
		virtual void from_file_buttonOnButtonClick(wxCommandEvent&);
		virtual void remove_row_buttonOnButtonClick(wxCommandEvent&)
		{ long row = wxGetNumberFromUser("attention : you cannot delete row 0","enter row to remove","");spectrum_list->DeleteRows(row - 1 ,1,true);}
		virtual void remove_row_button_mediumOnButtonClick(wxCommandEvent&)
		{ long row = wxGetNumberFromUser("attention : you cannot delete row 0","enter row to remove","");medium_list->DeleteRows(row - 1 ,1,true);}
		virtual void save_buttonOnButtonClick(wxCommandEvent&);
		virtual void save_button_mediumOnButtonClick(wxCommandEvent&);
		virtual void add_row_buttonOnButtonClick(wxCommandEvent& event){spectrum_list->AppendRows(1, true);}
		virtual void add_row_button_mediumOnButtonClick(wxCommandEvent& event){medium_list->AppendRows(1, true);}
		virtual void medium_fromfile_buttonOnButtonClick( wxCommandEvent& );
		virtual void visu_transmitOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void visu_reflectOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_runOnMenuSelection( wxCommandEvent& );
		virtual void m_aboutOnMenuSelection( wxCommandEvent& );
		virtual void m_quitOnMenuSelection( wxCommandEvent& event) {this->Close(true);}
		virtual void m_printOnMenuSelection(wxCommandEvent&);


	public:

        wxString filename_spectrum;
        wxString filename_medium;

		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Photon Transport"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 901,574 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );


		~MyFrame();

};

#endif //__FORMBUILDER_H__
