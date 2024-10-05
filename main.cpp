#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "scene.hpp"
using namespace std;


SCENE setUpScene(string sceneA, string sceneB, bool choiceOrder, vector<int> choiceValue)
{
    SCENE scene;
    scene.sceneDescriptionA = sceneA;
    scene.sceneDescriptionB = sceneB;
    scene.choiceTypeOrder = choiceOrder;
    scene.choiceValues = choiceValue;
    return scene;
}

void calculateEnding(int affection, int snmValue, SCENE scene) {
    if (affection > 5) {
        if(snmValue > (10/3) * 2){
            scene.loadDescription("HaS.txt");}
        else if (snmValue > 10/3){
            scene.loadDescription("HaN.txt");}
        else{
            scene.loadDescription("HaM.txt");}}
    else{   
        if(snmValue > (10/3) * 2){
            scene.loadDescription("LaS.txt");}
        else if (snmValue > 10/3){
            scene.loadDescription("LaN.txt");}
        else{
            scene.loadDescription("LaM.txt");}
            }    
}


vector<string> setUpDescriptorA()
{
    vector<string> descriptorsA = {"C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 1-1.txt"};
    return descriptorsA;
}

vector<string> setUpDescriptorB()
{
    vector<string> descriptorsB = {"C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 1-2.txt"};
    return descriptorsB;
}

vector<bool> setUpChoiceOrder()
{
    vector<bool> choiceOrder = {false};
    return choiceOrder;
}

vector<vector<int>> setUpChoiceValues(){
    vector<vector<int>> choiceValues = {{1, 0, -1, 1, -1}, {}};
    return choiceValues;
}


int main() {
    cout << "START";
    SCENE scene = setUpScene("", "", true, {1});
    cout << "SCENE IS SET UP!!";
    //PLAYER player;
    vector<int> points = {0,0};
    points = scene.run();
    cout << "SCENE IS RUN!";
    //player.alterValues(points);
    cout << "Affection Points: " << points[0] << endl;
    cout << "SnM Points: " << points[1] << endl;
    return 0;
}