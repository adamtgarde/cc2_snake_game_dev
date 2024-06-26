#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Yet, think about this approach? What are the pros and cons
    // of using the frame rate and what other approach could be
    // used instead?
	ofSetFrameRate(15);
    
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update() {

	if (gameStarted && !gameOver) {
		mySnake.updateSnake();
		if (mySnake.eat(myFood.getPos())) {
			myFood.relocate();
		}
		// Check for collision after eating
		if (mySnake.checkCollision()) {
			gameOver = true;
			gameOverTime = ofGetElapsedTimef();
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



