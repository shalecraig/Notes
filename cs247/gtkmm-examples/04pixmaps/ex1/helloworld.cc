/*
 * Displays an image in a window. 
 */

#include "helloworld.h"
#include <iostream>

// Creates a new button with the label "Hello World".
HelloWorld::HelloWorld() : image( "card_0_0.png" ) {
	// Sets the border width of the window.
	set_border_width( 10 );
	
	// This packs the image into the Window (a container).
	add( image );
	
	// The final step is to display this newly created widget.
	show_all();
} // HelloWorld::HelloWorld

HelloWorld::~HelloWorld() {}
