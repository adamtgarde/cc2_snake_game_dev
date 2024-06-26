#include "ofSnake.h"



ofSnake::ofSnake() {

    xSpeed = 0;
    ySpeed = 0;

    int stage = 0;

    colorIO.set(255);
}

ofSnake::~ofSnake() {

    int test = 4;
    std::cout << "help, I will die" << std::endl;

}

void ofSnake::updateSnake() {
    myPos.x = myPos.x + xSpeed * cellSize;
    myPos.y = myPos.y + ySpeed * cellSize;

    // Wrap the snake's position around to the opposite side of the window
    if (myPos.x < 0) {
        myPos.x = ofGetWidth() - cellSize;
    }
    else if (myPos.x >= ofGetWidth()) {
        myPos.x = 0;
    }
    if (myPos.y < 0) {
        myPos.y = ofGetHeight() - cellSize;
    }
    else if (myPos.y >= ofGetHeight()) {
        myPos.y = 0;
    }
}


void ofSnake::drawSnake() {

    ofSetColor(colorIO);
    ofDrawRectangle(myPos.x, myPos.y, cellSize, cellSize);
    
}


void ofSnake::setDir(int x, int y) {
    
    float speedFactor = 0.25;

    xSpeed = x * speedFactor;
    ySpeed = y * speedFactor;

    
}

void ofSnake::setSpeed(float xSpeed, float ySpeed) { // Implementation of setSpeed

    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;

}

void ofSnake::setCellSize(int cellSize) { // Implementation of setCellSize

    this->cellSize = cellSize;

}

bool ofSnake::eat(ofVec2f foodPos) {

    if (myPos.distance(foodPos) < cellSize) {
        
        std::cout << " eat !" << std::endl;

        return true;
    }

    return false;

}



