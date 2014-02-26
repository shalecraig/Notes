/*
 * Displays a group of radio buttons in a dialog box when the button in the window is clicked. 
 */

#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window {
public:
	HelloWorld();
	virtual ~HelloWorld();
	
protected:
    // Signal handlers:
    virtual void onButtonClicked();
    
	// Member widgets:
    Gtk::Button          button;           // Button to trigger the dialog box
}; // HelloWorld

#endif
