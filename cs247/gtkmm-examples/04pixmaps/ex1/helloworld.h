/*
 * Displays an image in a window. 
 */

#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm/image.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window {
public:
	HelloWorld();
	virtual ~HelloWorld();
	
protected:
	// Member widgets:
	Gtk::Image image;
}; // HelloWorld

#endif
