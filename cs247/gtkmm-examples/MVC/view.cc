/*
 * MVC example of GTKmm program
 *
 * View class.  Is responsible for buttons (that user clicks) and for displaying
 * the top card of the deck.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "DeckGUI.h"
#include <iostream>

// Creates buttons with labels. Sets butBox elements to have the same size, 
// with 10 pixels between widgets
View::View(Controller *c, Model *m) : model_(m), controller_(c), panels(true,10), butBox(true, 10), next_button( "next" ), reset_button( "reset" ), card(deck.null()) {

	// Sets some properties of the window.
        set_title( "CS246 MVC example" );
	set_border_width( 10 );
	
	// Add panels to the window
	add(panels);

	// Add button box and card image to the panels
	panels.add( butBox );
	panels.add( card );
	card.set( deck.null() );

	// Add buttons to the box (a container). Buttons initially invisible
	butBox.add( next_button );
	butBox.add( reset_button );


	// Associate button "clicked" events with local onButtonClicked() method defined below.
	next_button.signal_clicked().connect( sigc::mem_fun( *this, &View::nextButtonClicked ) );
	reset_button.signal_clicked().connect( sigc::mem_fun( *this, &View::resetButtonClicked ) );
	
	
	// The final step is to display the buttons (they display themselves)
	show_all();

	// Register view as observer of model
	model_->subscribe(this);

} // View::View

View::~View() {}


void View::update() {
  Suits suit = model_->suit();
  Faces face = model_->face();
  if ( suit == NOSUIT ) 
    card.set( deck.null() );
  else
    card.set( deck.image(face, suit) );

}

void View::nextButtonClicked() {
  controller_->nextButtonClicked();
} // View::nextButtonClicked

void View::resetButtonClicked() {
  controller_->resetButtonClicked();
} // View::resetButtonClicked
