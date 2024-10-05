#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "player.hpp"
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

void calculateEnding(int affection, int snmValue) {
    SCENE scene;
    if (affection > 5) {
        if(snmValue > (10/3) * 2){
            scene.loadDescription("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\HaS.txt");}
        else if (snmValue > 10/3){
            scene.loadDescription("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\HaN.txt");}
        else{
            scene.loadDescription("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\HaM.txt");}}
    else{   
        if(snmValue > (10/3) * 2){
            scene.loadDescription("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\LaS.txt");}
        else if (snmValue > 10/3){
            scene.loadDescription("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\LaN.txt");}
        else{
            scene.loadDescription("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\LaM.txt");}
            }    
}


vector<string> setUpDescriptorA()
{
    vector<string> descriptorsA = {"C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 1-1.txt", 
    "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 2-1.txt",
    "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 3-1.txt",
    "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 4-1.txt",
    "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 5-1.txt"};
    return descriptorsA;
}

vector<string> setUpDescriptorB()
{
    vector<string> descriptorsB = {"C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 1-2.txt",
    "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 2-2.txt",
    "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 3-2.txt",
    "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 4-2.txt",
    "C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\Scene 5-2.txt"};
    return descriptorsB;
}

vector<bool> setUpChoiceOrder()
{
    vector<bool> choiceOrder = {false, true, true, true, false};
    return choiceOrder;
}

vector<vector<int>> setUpChoiceValues(){
    vector<vector<int>> choiceValues = {{1, 0, -1, 1, -1}, {0, -1, 1, 1,-1}, {-1, 1, 0, 1, -1}, {1, 0, -1, -1, 1}, {1, -1, 0, -1, 0}};
    return choiceValues;
}

void run(vector<string> descriptorsA, vector<string> descriptorsB, vector<bool> choiceOrders, vector<vector<int>> choiceValues){
    PLAYER player;
    vector<int> points = {0,0};
    for ( int i = 0; i < descriptorsA.size(); i++){
        SCENE scene = setUpScene(descriptorsA[i], descriptorsB[i], choiceOrders[i], choiceValues[i]);
        points = scene.run();
        player.alterValues(points);
    }
    calculateEnding(player.affectionValue, player.snmValue);
}


int main() {
    vector<string> descriptorsA = setUpDescriptorA();
    vector<string> descriptorsB = setUpDescriptorB();
    vector<bool> choiceOrders = setUpChoiceOrder();
    vector<vector<int>> choiceValues = setUpChoiceValues();
    run(descriptorsA, descriptorsB, choiceOrders, choiceValues);
    return 0;
}