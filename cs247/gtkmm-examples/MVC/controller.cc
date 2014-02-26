/*
 * MVC example of GTKmm program
 *
 * Controller class.  Is responsible for translating UI events (from the View)
 * into method calls to the Model.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Copyright 2009 UW. All rights reserved.
 *
 */


#include "controller.h"
#include "model.h"


Controller::Controller(Model *m) : model_(m) {}


void Controller::nextButtonClicked() {
     model_->nextCard();
} 


void Controller::resetButtonClicked() {
     model_->resetCards();
} 
