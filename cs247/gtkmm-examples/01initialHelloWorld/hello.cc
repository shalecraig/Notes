// Includes the entire gtkmm kit. Should normally be more specific.
#include <gtkmm.h>           

int main( int argc, char * argv[] ) {
	// Creates a Gtk::Main object initialized from argument list. Necessary in all gtkmm applications.
	Gtk::Main   kit( argc, argv );          
	
	// Creates a window, which is displayed in the next command.
	Gtk::Window window;
	
	// Shows the window and enters the main gtkmm processing loop, which will finish when the window is closed.
	Gtk::Main::run( window );
	
	return 0;
} // main
