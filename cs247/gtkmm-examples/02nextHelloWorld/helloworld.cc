/*
 * Ch. 3 of "Programming with gtkmm", pp. 11-14
 *
 * Displays a labelled button in a window. When the button is clicked, the text "Hello World" is printed
 * to standard output.
 */

#include "helloworld.h"
#include <iostream>

// Creates a new button with the label "Hello World".
HelloWorld::HelloWorld() : m_button( "Hello World" ) {
	// Sets the border width of the window.
	set_border_width( 10 );
	
	// When the button receives the "clicked" signal, it will call the onButtonClicked() method defined below.
	m_button.signal_clicked().connect( sigc::mem_fun( *this, &HelloWorld::onButtonClicked ) );
	
	// This packs the button into the Window (a container).
	add( m_button );
	
	// The final step is to display this newly created widget.
	m_button.show();
} // HelloWorld::HelloWorld

HelloWorld::~HelloWorld() {}

void HelloWorld::onButtonClicked() {
	std::cout << "Hello World" << std::endl;
} // HelloWorld::onButtonClicked
