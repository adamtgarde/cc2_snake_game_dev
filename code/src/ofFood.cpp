#include "ofFood.h"

ofFood::ofFood() {
    foodImage.load("food.png"); 
    pickLocation();
}

void ofFood::pickLocation() {
    int cols = floor(ofGetWidth() / scl);
    int rows = floor(ofGetHeight() / scl);
    myPos.x = floor(ofRandom(cols)) * scl;
    myPos.y = floor(ofRandom(rows)) * scl;
}

void ofFood::drawFood() {
    //ofSetColor(color);
    foodImage.draw(myPos.x, myPos.y, scl, scl);
}

ofVec2f ofFood::getPos() const { // Implementation of getter for myPos
    return myPos;
}

void ofFood::relocate() { // Implementation of public method to change location
    pickLocation();
}

void ofFood::setImage(const std::string& filename) {
    foodImage.load(filename);
}

ofImage ofFood::getImage() const {
    return foodImage;
}

ofFood::~ofFood() {
    // Destructor doesn't need to do anything
}
