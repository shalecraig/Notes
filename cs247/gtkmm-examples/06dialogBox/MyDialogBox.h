/*
 *  MyDialogBox.h
 *  
 * Creates a dialog box that holds a radio button group with each radio button associated with a colour.
 * Outputs the colour chosen by the user.
 *
 *  Created by Caroline Kierstead on 28/05/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */
#ifndef __MY_DIALOG_BOX_H
#define __MY_DIALOG_BOX_H
#include <gtkmm/dialog.h>
#include <gtkmm/box.h>
#include <gtkmm/radiobuttongroup.h>
#include <gtkmm/radiobutton.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

class MyDialogBox : Gtk::Dialog {
public:
	// Specifies the parent window of the dialog box and the title of the dialog box.
	MyDialogBox( Gtk::Window & parentWindow, string title);
	virtual ~MyDialogBox();
	
private:
	Gtk::RadioButton::Group      group;          // Used to group the radio buttons so only one can be active at a time.
	vector<Gtk::RadioButton *>   buttons;        // Buttons for the messages.
}; // MyDialogBox
#endif
