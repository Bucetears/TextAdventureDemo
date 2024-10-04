#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openFile(string filePath) {
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

int main() {
    openFile("C:\\Users\\Cecel\\OneDrive\\Documents\\school\\Fall 2024\\CSE 310\\Module 1\\LaN.txt");
    return 0;
}