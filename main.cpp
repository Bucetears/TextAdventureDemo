#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "scene.hpp"
using namespace std;

SCENE setUpScene()
{
    SCENE scene;
    scene.sceneDescriptionA = "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 1-1.txt";
    scene.sceneDescriptionB = "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 1-2.txt";
    scene.choiceTypeOrder = false;
    scene.choiceValues = {1, 0, -1, 1, -1};
    return scene;
}





int main() {
    SCENE scene = setUpScene();
    PLAYER player;
    vector<int> points = {0,0};
    points = scene.run();
    player.alterValues(points);
    cout << "Affection Points: " << player.affectionValue << endl;
    cout << "SnM Points: " << player.snmValue << endl;
    return 0;
}