#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class SCENE
{
    public:
    vector<int> run();
    void loadDescription(string filePath);
    int makeChoiceSnM();
    int makeChoiceA();
    int decideChoiceValue(int decision);
    string sceneDescriptionA = " ";
    string sceneDescriptionB = " ";
    vector<int> choiceValues = {1};
    bool choiceTypeOrder = true; //If true makeChoiceA will go first.


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
    cout << endl;
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
    cout << endl;
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


class PLAYER
{
    public:
    int affectionValue = 5;
    int snmValue = 5;
    void alterValues(vector<int> values)
    {
        affectionValue += values[0];
        snmValue += values[1];
    }

};

//-----------------------------------------------------------------------------------------//

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