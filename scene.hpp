#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class SCENE
{
    public:
    SCENE();
    vector<int> run();
    void loadDescription(string filePath);
    int makeChoiceSnM();
    int makeChoiceA();
    int decideChoiceValue(int decision);
    string sceneDescriptionA;
    string sceneDescriptionB;
    vector<int> choiceValues;
    bool choiceTypeOrder; //If true makeChoiceA will go first.

    SCENE(string A, string B, vector<int> C, bool D)
{
    sceneDescriptionA = A;
    sceneDescriptionB = B;
    choiceValues = C;
    choiceTypeOrder = D;
}
};

vector<int> SCENE::run()
{
    vector<int> points = {0,0};
    loadDescription(sceneDescriptionA);
    int choice;
    if (choiceTypeOrder)
    {
        choice = makeChoiceA();
        points[0] = decideChoiceValue(choice);
    }
    else
    {
        choice = makeChoiceSnM();
        points[1] = decideChoiceValue(choice);

    }

    loadDescription(sceneDescriptionB);
    if (choiceTypeOrder)
    {
        makeChoiceSnM();
        points[1] = decideChoiceValue(choice);
    }
    else
    {
        makeChoiceA();
        points[0] = decideChoiceValue(choice);
    }
    return points;
}

void SCENE::loadDescription(string filePath)
{
    fstream myFile;
    myFile.open(filePath, ios::in); //read File
    if(myFile.is_open()) {
        string line;
        while(getline(myFile, line)) {
            cout << line << endl;
        }
        myFile.close();
    }
    else {
        cout << "Error opening file";
    }
}

int SCENE::makeChoiceSnM()
{
    int decision;
    cin >> decision;
    if (decision > 3 || decision < 1) {
        cout << "Select a valid option";
        makeChoiceSnM();
    }
    return (decision - 1);
}

int SCENE::makeChoiceA()
{
    int decision;
    cin >> decision;
    if (decision > 2 || decision < 1) {
        cout << "Select a valid option";
        makeChoiceA();
    }
    return (decision + 2);
}

int SCENE::decideChoiceValue(int decision)
{
    return choiceValues[decision];
}


#endif