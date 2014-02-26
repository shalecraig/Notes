#ifndef __OTHER_WORLD_H
#define __OTHER_WORLD_H
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>

#include "DeckGUI.h"

class OtherWorld : public Gtk::Window {
public:
	OtherWorld();
	virtual ~OtherWorld();
	
private:
	DeckGUI                         deck;             // Knows all of the card pixel buffers.
	
	// Member widgets:
	Gtk::Image                    * card[5];          // Images to display.
	Gtk::Button                     button;           // Button that will hold an image.
	Gtk::HBox                       hbox;             // Horizontal box for aligning widgets in the window.
	Gtk::Frame                      frame;            // Create a nice framed border for the box.
}; // OtherWorld

#endif
