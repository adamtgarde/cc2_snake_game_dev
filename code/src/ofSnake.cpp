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

    // Only shift positions in the tail if it has more than one element
        if (tail.size() > 1) {
        for (int i = tail.size() - 1; i > 0; i--) {
            tail[i] = tail[i - 1];
        }
        // Add the current position to the start of the tail
        tail[0] = myPos;
    }

    // Only grow the tail if the grow delay is zero
    if (growDelay > 0) {
        grow();
        growDelay--;
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
        growDelay += 3; // Increase the grow delay when the snake eats food
        return true;
    }
    return false;

}


void ofSnake::grow() {
    // Add three tail pieces when the snake eats food
    for (int i = 0; i < 3; i++) {
        // Add the new tail piece at the end of the tail
        tail.push_back(myPos);
    }
}

bool ofSnake::checkCollision() {
    if (tail.empty()) { // If tail is empty, return false
        return false;
    }
    for (int i = 0; i < tail.size() - 4; i++) { // Ignore the last element of tail
        if (myPos.distance(tail[i]) < cellSize) {
            return true;
        }
    }
    return false;
}


void ofSnake::startMoving() {
    // Set xSpeed and ySpeed to values corresponding to up, down, left, or right
    int direction = floor(ofRandom(4));
    switch (direction) {
    case 0: // up
        xSpeed = 0;
        ySpeed = -0.5;
        break;
    case 1: // down
        xSpeed = 0;
        ySpeed = 0.5;
        break;
    case 2: // left
        xSpeed = -0.5;
        ySpeed = 0;
        break;
    case 3: // right
        xSpeed = 0.5;
        ySpeed = 0;
        break;
    }
}
