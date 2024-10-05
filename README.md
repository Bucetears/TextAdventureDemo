# Overview

This is the base for a text adventure game. Currently there is no text to adventure with, but it has the framework set up to accomplish the goals of this text adventure. The goal of the finished product would be for the text to take the player through five different scenarios, and during each one of those scenarios the player is presented with two choices. For now the program is currently just designed to test the algorithm for scoring points, and file loading.

One choice will have two options, while the other choice will have three options. There will be two different variables it will base the file opening on. These variables will be alter based off of the choices made during the adventure game. Both of these variables will be integers with the starting value of 5. By the end of the scenario both stats can reach a maximum of 10 and a minimum of 0. At the end of the five scenarios The choices made will either increase, decrease, or do nothing to the integer value. The choice with two options is called the affection stat. It will have one option that increases the value, while the other decreases the value. At the end of the five scenarios it will be evaluated if the integer is above 5 or the halfway point of possibly earned points to see if the player will get a high affection of low affection ending. The second stat is the SNM meter which has three parts to it. If the player's final score is in the top third of all possible points, they will receive the S ending. If the player's final score is in the lower third of all possible points they will receive the M ending. Finally if the player's score is in the middle third of all possible points they will receive the N or neutral ending. With the combination of affection and SNM there is a total of six possible endings. 

Currently the program loads text files which provide the choices, the player has the ability to make choices and change their stats on Affection and SNM, and finally the player will receive an ending according to their stats that is loaded from another file.


# Demo Video Below
Software Demo Video Link (https://youtu.be/8RkR2LHFG7o)

# Development Environment
I coded this project in VSCode with using Mingw-64 for the complier. I also used Github to save and upload the repository.

I used C++ to write this code!
I also used the libraries below for this program:
- iostream
- fstream
- string
- vector
- namespace std;

# Useful Websites

- W3Schools (https://www.w3schools.com/cpp/default.asp)
- GeeksforGeeks (https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/)

# Future Work

- The first thing I would like to do is add actually text to this game so there is an actual story the player will make choices to be a part of. This current version only has text that will help test the program.
- I would also like to add the function that after you select a choice another text file will be loaded that has the result of the choice the player made.
- The final thing I would like to improve about this code is to find a way to make everything less hardcoded into it. I had to manually put the values of a lot of the variables into the code, and it would be better if those variables were able to be loaded from a different source.
