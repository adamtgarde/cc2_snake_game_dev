#include "ofApp.h"
#include "ofFood.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(7);
    
	ofBackground(0);

  // Load 14 PNG files
   
	foodImages = {
        "food1.png", "food2.png", "food3.png", "food4.png", "food5.png", "food6.png", "food7.png", 
		"food8.png", "food9.png", "food10.png", "food11.png", "food12.png", "food13.png", "food14.png",
		"food15.png", "food16.png", "food17.png", "food18.png"
    };

    //Load a random food image
    int randomIndex = ofRandom(foodImages.size());
    myFood.foodImage.load(foodImages[randomIndex]);
}

//--------------------------------------------------------------
void ofApp::update() {

	if (mySnake.eat(myFood.myPos)) {
		int randomIndex = ofRandom(foodImages.size());
        myFood.foodImage.load(foodImages[randomIndex]);
		myFood.pickLocation();
        
	if (gameStarted && !gameOver) {
		mySnake.updateSnake();
		if (mySnake.eat(myFood.getPos())) {
			myFood.relocate();
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
	
	if (!gameStarted) {
		ofSetColor(255);
		ofDrawBitmapString("PRESS SPACE TO START", ofGetWidth() / 2 - 80, ofGetHeight() / 2);
	}
	else if (gameOver) {
	if (ofGetElapsedTimef() - gameOverTime < 2) {
		ofDrawBitmapString("GAME OVER!", ofGetWidth() / 2 - 80, ofGetHeight() / 2);
	}
	else {
		gameStarted = false;
		gameOver = false;
		mySnake = ofSnake();
		myFood = ofFood();
	}
}
else {
	mySnake.drawSnake();
	myFood.drawFood();
}
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == ' ' && !gameStarted) { // If space key is pressed and the game has not started
		gameStarted = true;
		mySnake.startMoving();
	}

	switch (key) {

	case OF_KEY_LEFT: // left
		mySnake.setDir(-1, 0);
		break;
	case OF_KEY_RIGHT: // right
		mySnake.setDir(1, 0);
		break;
	case OF_KEY_UP: // up
		mySnake.setDir(0, -1);
		break;
	case OF_KEY_DOWN: // down
		mySnake.setDir(0, 1);
		break;
	}
}



