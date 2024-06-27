#pragma once
#include "ofMain.h"


class ofSnake {

private:
    float xSpeed;
    float ySpeed;
    int cellSize = 50;
    ofColor colorIO;
    ofVec2f myPos{ 0,0 };

public:
    ofSnake();
    ~ofSnake();
    void updateSnake();
    void drawSnake();
    void setDir(int x, int y);
    void setSpeed(float xSpeed, float ySpeed);
    void setCellSize(int cellSize);
    bool eat(ofVec2f foodPos);
    void startMoving(); // New method to start game

};
