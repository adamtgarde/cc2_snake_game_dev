#pragma once
#include "ofMain.h"
#include "ofImage.h" 

class ofFood {

private:
    int scl = 50;
    ofImage foodImage; //add ofImage for dealing with PNG
    ofColor color;
    ofVec2f myPos{};
    void pickLocation();

public:
    ofFood();
    ~ofFood();
    void drawFood();
    ofVec2f getPos() const; // Getter for myPos
    void relocate(); // Public method to change location
};
