#include "ofFood.h"

ofFood::ofFood() {
    color.set(0, 255, 0);
    pickLocation();
}

void ofFood::pickLocation() {
    int cols = floor(ofGetWidth() / scl);
    int rows = floor(ofGetHeight() / scl);
    myPos.x = floor(ofRandom(cols)) * scl;
    myPos.y = floor(ofRandom(rows)) * scl;
}

void ofFood::drawFood() {
    ofSetColor(color);
    ofDrawRectangle(myPos.x, myPos.y, scl, scl);
}

ofVec2f ofFood::getPos() const { // Implementation of getter for myPos
    return myPos;
}

void ofFood::relocate() { // Implementation of public method to change location
    pickLocation();
}

ofFood::~ofFood() {
    // Destructor doesn't need to do anything
}