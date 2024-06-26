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

    // Shift positions in the tail to make room for the new position
    for (int i = tail.size() - 1; i > 0; i--) {
        tail[i] = tail[i - 1];
    }
    // Add the current position to the start of the tail
    if (!tail.empty()) {
        tail[0] = myPos;
    }

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

    // Draw the tail
    for (const auto& pos : tail) {
        ofSetColor(colorIO);
        ofDrawRectangle(pos.x, pos.y, cellSize, cellSize);
    }

    // Draw the head
    ofSetColor(colorIO);
    ofDrawRectangle(myPos.x, myPos.y, cellSize, cellSize);
}


void ofSnake::setDir(int x, int y) {
    
    float speedFactor = 0.5;

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
        grow(); // Add a tail piece when the snake eats food
        return true;
    }
    return false;

}


void ofSnake::grow() { // Implementation of grow
    // Add three tail pieces when the snake eats food
    for (int i = 0; i < 4; i++) {
        tail.push_back(myPos);
    }
}

