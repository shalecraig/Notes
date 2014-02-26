/*
 *  Deck.cc
 *  
 *
 *  Created by Caroline Kierstead on 25/05/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */
#include "DeckGUI.h"
#include <algorithm>
#include <iterator>
#include <string>
using std::string;
using std::transform;

// Sets up an array of the Portable Network Graphics (PNG) file names that contain the necessary card images.
// The deck will load the contents into pixel buffers for later use.
const char * image_names[] = {   
	// Set up NINE of {DIAMOND,CLUB,HEART,SPADE}
	"cards_png/0_0.png", "cards_png/0_1.png", "cards_png/0_2.png", "cards_png/0_3.png",
	// Set up TEN of {DIAMOND,CLUB,HEART,SPADE}
	"cards_png/1_0.png", "cards_png/1_1.png", "cards_png/1_2.png", "cards_png/1_3.png",
	// Set up JACK of {DIAMOND,CLUB,HEART,SPADE}
	"cards_png/2_0.png", "cards_png/2_1.png", "cards_png/2_2.png", "cards_png/2_3.png",
	// Set up QUEEN of {DIAMOND,CLUB,HEART,SPADE}
	"cards_png/3_0.png", "cards_png/3_1.png", "cards_png/3_2.png", "cards_png/3_3.png",
	// Set up KING of {DIAMOND,CLUB,HEART,SPADE}
	"cards_png/4_0.png", "cards_png/4_1.png", "cards_png/4_2.png", "cards_png/4_3.png",
	// Set up ACE of {DIAMOND,CLUB,HEART,SPADE}
	"cards_png/5_0.png", "cards_png/5_1.png", "cards_png/5_2.png", "cards_png/5_3.png",
	// Set up the back of a card for a place holder/null card
	"cards_png/back_1.png"
}; 

// Loads the image from the specified file name into a pixel buffer.
Glib::RefPtr<Gdk::Pixbuf> createPixbuf(const string & name) {
	return Gdk::Pixbuf::create_from_file( name );
} // createPixbuf

DeckGUI::DeckGUI()  {
	// Images can only be loaded once the main window has been initialized, so cannot be done as a static
	// constant array. Instead, use the STL transform algorithm to apply the method createPixbuf to every
	// element in the array of image names, starting with first and ending with the last. New elements are
	// added to the back of deck.
	transform( &image_names[0], &image_names[G_N_ELEMENTS(image_names)], 
			   std::back_inserter(deck), &createPixbuf );
} // DeckGUI::DeckGUI

DeckGUI::~DeckGUI() {
} // DeckGUI::~DeckGUI

// Returns the image for the specified card.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::image( Faces f, Suits s ) {
	int index = ((int) f)*4 + ((int) s );
	return deck[ index ];
} // DeckGUI::getCardImage 

// Returns the image to use for the placeholder.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::null() {
	int size = deck.size();
	return deck[ size-1 ];
} // DeckGUI::getNullCardImage
