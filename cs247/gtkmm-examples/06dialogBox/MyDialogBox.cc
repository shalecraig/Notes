/*
 *  MyDialogBox.cc
 *
 *  Created by Caroline Kierstead on 28/05/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */
#include "MyDialogBox.h"
#include <gtkmm/stock.h>
#include <iostream>

// Specifies the parent window of the dialog box and the title of the dialog box.
MyDialogBox::MyDialogBox( Gtk::Window & parentWindow, string title) : Dialog( title, parentWindow, true, true ) {
	vector<string> messages;
	messages.push_back( "Red" );
	messages.push_back( "Green" );
	messages.push_back( "Blue" );
	messages.push_back( "Cyan" );
	
	// Obtain the dialog box's vertical alignment box.
	Gtk::VBox* contentArea = this->get_vbox();
	
	// Set up a group of radio buttons, one per card in human player's hand plus the top card of the kitty.
	for ( int i = 0; i < messages.size(); i++ ) {
		buttons.push_back( Gtk::manage( new Gtk::RadioButton( group, messages[i] ) ) );
		contentArea->add( *buttons[i] );
	} // for
	
	// Make the first button the initial active choice.
	buttons[0]->set_active();
	
	// Add a standard "ok" buttons with the appropriate responses when clicked.
    Gtk::Button * okButton = add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);
	show_all_children();
	
    // Wait for a response from the dialog box.
	int result = run();
    switch (result) {
        case Gtk::RESPONSE_OK:
            for ( int i = 0; i < messages.size(); i++ ) {
				if ( buttons[i]->get_active() ) {
					std::cout << "chose '" << messages[i] << "'" << std::endl;
					break;
				} // if
			} // for
            break;
    } // switch    	
} // MyDialogBox::MyDialogBox

MyDialogBox::~MyDialogBox() {
	for ( int i = 0; i < buttons.size(); i++ ) delete buttons[i];
	buttons.clear();
} // MyDialogBox::~MyDialogBox
