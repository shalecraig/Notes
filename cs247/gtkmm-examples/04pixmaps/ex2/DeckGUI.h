/*
 *  Deck.h
 *  
 * Loads a series of pixmaps used for displaying the cards, as well as a card back used as a place marker in the
 * display when we don't have a card yet to display. Use pixel buffers to share images since widgets cannot be
 * shared.
 *
 *  Created by Caroline Kierstead on 25/05/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */
#ifndef __DECK_GUI_H
#define __DECK_GUI_H
#include <gdkmm/pixbuf.h>
#include <vector>
using std::vector;

// Enumerated types to define the face and suit values.
enum Faces { NINE, TEN, JACK, QUEEN, KING, ACE };
enum Suits { DIAMOND, CLUB, HEART, SPADE };

class DeckGUI {
public:
	DeckGUI();
	virtual ~DeckGUI();
	Glib::RefPtr<Gdk::Pixbuf> getCardImage( Faces f, Suits s );   // Returns the image for the specified card.
	Glib::RefPtr<Gdk::Pixbuf> getNullCardImage();                 // Returns the image to use for the placeholder.

private:
	vector< Glib::RefPtr< Gdk::Pixbuf > > deck;                   // Contains the pixel buffer images.
}; // DeckGUI
#endif
