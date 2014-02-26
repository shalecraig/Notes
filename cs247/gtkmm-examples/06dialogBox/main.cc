/*
 * Displays an image in a window. 
 */

#include <gtkmm/main.h>
#include "helloworld.h"

int main( int argc, char * argv[] ) {
	Gtk::Main  kit( argc, argv );    // Initialize gtkmm with the command line arguments, as appropriate.
	HelloWorld hello;                // Create the window with the image.
	Gtk::Main::run( hello );         // Show the window and return when it is closed.
	
	return 0;
} // main
