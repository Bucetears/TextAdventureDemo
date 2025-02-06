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
    vector<string> sceneDescription = {"","",""};
    vector<int> choiceValues = {1};
    bool choiceTypeOrder = true; //If true makeChoiceA will go first.
    vector<string> choiceScenes = {""};
};


vector<int> SCENE::run()
{
    vector<int> points = {0,0};
    loadDescription(sceneDescription[0]); //This plays the first part of the scene
    int choice;
    if (choiceTypeOrder)
    {
        choice = makeChoiceA(); //Choice with two options
        points[0] = decideChoiceValue(choice);
        loadDescription(choiceScenes[choice]); //Plays the choice 
        loadDescription(sceneDescription[1]); //This plays the second part of the scene
        choice = makeChoiceSnM();
        points[1] = decideChoiceValue(choice);

    }
    else
    {
        choice = makeChoiceSnM(); //Choice with three options
        points[1] = decideChoiceValue(choice);
        loadDescription(choiceScenes[choice]); //Plays the choice 
        loadDescription(sceneDescription[1]); //This plays the second part of the scene
        choice = makeChoiceA();
        points[0] = decideChoiceValue(choice);

    }
    loadDescription(choiceScenes[choice]); //Plays the choice 
    loadDescription(sceneDescription[2]);
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
        cout << "Select a valid option" << endl;
        makeChoiceSnM();
    }
    if (choiceTypeOrder)
    {
        return (decision + 1);
    }
    else
    {
        return (decision - 1);
    }
    
}

int SCENE::makeChoiceA()
{
    int decision;
    cin >> decision;
    cout << endl;
    if (decision > 2 || decision < 1) {
        cout << "Select a valid option" << endl;
        makeChoiceA();
    }
    if (choiceTypeOrder)
    {
        return (decision - 1);
    }
    else
    {
        return (decision + 2);
    }
}

int SCENE::decideChoiceValue(int decision)
{
    return choiceValues[decision];
    
}

//---------------------------------------------------------------------------------------------------------------

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

SCENE setUpScene(string sceneA, string sceneB, string sceneC, bool choiceOrder, vector<int> choiceValue, vector<string> choiceScenes)
{
    SCENE scene;
    scene.sceneDescription[0] = sceneA;
    scene.sceneDescription[1] = sceneB;
    scene.sceneDescription[2] = sceneC;
    scene.choiceTypeOrder = choiceOrder;
    
    scene.choiceValues = choiceValue;
    scene.choiceScenes = choiceScenes;
    return scene;
}

//Calculates ending based on SNM points and Affection points. 
void calculateEnding(int affection, int snmValue, vector<string> endings) {
    SCENE scene;
    if (affection > 5) {
        if(snmValue > (10/3) * 2){
            scene.loadDescription(endings[2]);}
        else if (snmValue > 10/3){
            scene.loadDescription(endings[1]);}
        else{
            scene.loadDescription(endings[0]);}}
    else{   
        if(snmValue > (10/3) * 2){
            scene.loadDescription(endings[5]);}
        else if (snmValue > 10/3){
            scene.loadDescription(endings[4]);}
        else{
            scene.loadDescription(endings[3]);}
            }    
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------//
vector<string> setUpDescriptor(string filePath) //This saves the file locations listed in a file into a vector.
{
    vector<string> descriptors;
    fstream myFile;
    myFile.open(filePath, ios::in); //read File
    if(myFile.is_open()) {
        string line;
        while(getline(myFile, line)) {
            descriptors.push_back(line);
        }
        myFile.close();
    }
    else {
        cout << "Error opening file";
    }
    return descriptors;
}

//This sets up order the two choices (the 2 option choice and the 3 option choice) appear in.
vector<bool> setUpChoiceOrder()
{
    vector<bool> choiceOrder = {false, true, true, true, false};
    return choiceOrder;
}

//These vectors determine the point value of each of the choices.
vector<vector<int>> setUpChoiceValues(){
    vector<vector<int>> choiceValues = {{-1, 0, 1, -1, 1}, {1, -1, 0, -1,1}, {1, -1, -1, 1, 0}, {-1, 1, 1, 0, -1}, {1, -1, 0, -1, 1}};
    return choiceValues;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------//

//This function runs each of the scenes for the game.
void run(vector<string> descriptorsA, vector<string> descriptorsB, vector<string> descriptorsC, vector<bool> choiceOrders, vector<vector<int>> choiceValues, vector<string> endings, vector<string> decisions){
    PLAYER player;
    vector<int> points = {0,0}; //This is have the score tallied up in the end.
    vector<string> choiceScenes; //This will hold the scene collections needed for the choices made in each section of the game. 
    for ( int i = 0; i < descriptorsA.size(); i++){
        choiceScenes = setUpDescriptor(decisions[i]); //This will get the list of file locations for the scenes that come after the choices in this section of the game.
        SCENE scene = setUpScene(descriptorsA[i], descriptorsB[i], descriptorsC[i], choiceOrders[i], choiceValues[i], choiceScenes);
        points = scene.run();
        player.alterValues(points);
    }
    calculateEnding(player.affectionValue, player.snmValue, endings);
}


int main() {
    vector<string> descriptorsA = setUpDescriptor("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\SceneCollectionA.txt"); //This file holds the file locations for all of the A Scenes.
    vector<string> descriptorsB = setUpDescriptor("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\SceneCollectionB.txt"); //This holds all the file locations for the B Scenes.
    vector<string> descriptorsC = setUpDescriptor("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\SceneCollectionC.txt");
    vector<string> endings = setUpDescriptor("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\LoadEnding.txt"); //This holds all the scenes for the endings.
    vector<string> decisions = setUpDescriptor("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\TextAdventure\\DecisonScenes.txt"); //This holds all the file locations for the decision scenes.
    vector<bool> choiceOrders = setUpChoiceOrder();
    vector<vector<int>> choiceValues = setUpChoiceValues();
    run(descriptorsA, descriptorsB, descriptorsC, choiceOrders, choiceValues, endings, decisions);
    return 0;
}