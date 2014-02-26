/*
 * Displays a text entry field in a dialog box when the button in the window is clicked. 
 */

#include "helloworld.h"
#include <gtkmm/dialog.h>
#include <gtkmm/stock.h>
#include <gtkmm/entry.h>
#include <iostream>
#include <string>

// Creates a new button with the label "Hello World".
HelloWorld::HelloWorld() : button("Bring up dialog box") {
	// Sets the border width of the window.
	set_border_width( 10 );
    
       
	// When the button receives the "clicked" signal, it will call the onButtonClicked() method defined below.
	button.signal_clicked().connect( sigc::mem_fun( *this, &HelloWorld::onButtonClicked ) );
	
	// This packs the button into the Window (a container).
	add( button );
	
	// The final step is to display this newly created widget.
	button.show();
} // HelloWorld::HelloWorld

HelloWorld::~HelloWorld() {}

void HelloWorld::onButtonClicked() {
    // Create the message dialog box with stock "Ok" and "Cancel" buttons.
    Gtk::Dialog dialog( "Text Entry Dialog Box", *this );
    
    Gtk::Entry   nameField;                  // Text entry for the user's name
    Gtk::Label   nameLabel( "Please enter your name:" );
    
    // Add the text entry widget to the dialog box.
    // Add the text entry widget to the vertical box section of the dialog box.
    Gtk::VBox* contentArea = dialog.get_vbox();
    contentArea->pack_start( nameLabel, true, false );
    contentArea->pack_start( nameField, true, false );
    
    nameField.set_text( "" );
    nameLabel.show();
    nameField.show();
    
    // Add two standard buttons, "Ok" and "Cancel" with the appropriate responses when clicked.
    Gtk::Button * okButton = dialog.add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);
    Gtk::Button * cancelButton = dialog.add_button( Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    
    // Wait for a response from the dialog box.
	int result = dialog.run();
    std::string name;
    switch (result) {
        case Gtk::RESPONSE_OK:
        case Gtk::RESPONSE_ACCEPT:
            name = nameField.get_text();
            std::cout << "Entered '" << name << "'" << std::endl;
            break;
        case Gtk::RESPONSE_CANCEL:
            std::cout << "dialog cancelled" << std::endl;
            break;
        default:
            std::cout << "unexpected button clicked" << std::endl;
            break;
    } // switch
} // HelloWorld::onButtonClicked
