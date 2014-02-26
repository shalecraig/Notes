/*
 * MVC example of GTKmm program
 *
 * Model class.  Is responsible keeping track of the deck of cards.  
 * It knows nothing about views or controllers.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#include "model.h"


Model::Model() : topCard_(-1) {}

Suits Model::suit() {
  if (topCard_ == -1) return NOSUIT;
  
  return (Suits) (topCard_ % numSuits);
}

Faces Model::face() {
  if (topCard_ == -1) return NOFACE;

  return (Faces) (topCard_ / numSuits);
}

void Model::nextCard() {
  if (topCard_ == numCards-1) return;

  topCard_ += 1;
  notify();

}


void Model::resetCards() {
  topCard_ = -1;
  notify();
}
