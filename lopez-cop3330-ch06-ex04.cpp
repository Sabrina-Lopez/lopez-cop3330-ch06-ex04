/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Sabrina Lopez
 */

#include <iostream>
#include <vector>
using namespace std;

class Name_value { //create the Name_value class to hold pairs of names and scores inputted by the user
    public:
        string name; //declare a string to hold a name
        int value; //declare a string to hold a value or score
};

int main() {
    Name_value currentNameAndValue; //declare a variable of the Name_value class to hold the current name-value pair from the user
    vector<Name_value> namesAndValues; //declare a vector to hold the set of name-value pairs
    int index = 0; //declare an integer to keep track of the number of indexes in the vector, intializing the number of indexes as 0

    //tell the user to input a name-value pair or "NoName 0" if they want to stop the program right after launching it
    cout << "Input a name and a value (e.g., Sabrina 9). If you wish to not continue, type \"NoName 0\".\n";

    cin >> currentNameAndValue.name; //input the user's next name into the Name_value class
    cin >> currentNameAndValue.value; //input the user's next value or score into the Name_value class

    namesAndValues.resize(index + 1); //resize the vector by 1 to hold the new name-value pair
    namesAndValues[index] = currentNameAndValue; //input the current Name_value class into the current index of the vector
    index++; //increment the index count

    while(!((currentNameAndValue.name == "NoName") && (currentNameAndValue.value == 0))) { //while the user has not inputted "NoName 0"
        //tell the user to input another name-value pair or "NoName 0" if they want to stop inputting new name-value pairs
        cout << "\nInput a name and a value (e.g., Sabrina 9). If you wish to not continue, type \"NoName 0\".\n";

        cin >> currentNameAndValue.name; //input the user's next name into the Name_value class
        cin >> currentNameAndValue.value; //input the user's next value or score into the Name_value class

        int validNameFlag = 1; //declare an integer to act as a flag to ensure the current name inputted is not a duplicate
        //initializing the variable as 1 to represent that the current name is valid until found otherwise

        for(int i = 0; i < index; i++) { //loop until reached the max index of the vector

            //if the current name is a duplicate but the current overall input is not "NoName 0"
            if((currentNameAndValue.name == namesAndValues[i].name) && !((currentNameAndValue.name == "NoName") && (currentNameAndValue.value == 0))) {
                
                //tell the user that the name already exists and thus is a duplicate
                cout << "\nThe last name you entered already exists or, in other words, has been entered already.\n";
                validNameFlag = 0; //change the flag to false as the name is not valid
                return 0; //terminate the program
            }
        }

        if(validNameFlag == 1) { //if the name is still valid
            namesAndValues.resize(index + 1); //resize the vector by 1 to hold the new name-value pair
            namesAndValues[index] = currentNameAndValue; //input the current Name_value class into the current index of the vector
            index++; //increment the index count
        }
    }

    for(int i = 0; i < index - 1; i++) { //loop until reached the second-to-max index of the vector to skip the last index with the "NoName 0" input
        cout << "\n(" << namesAndValues[i].name << ", " << namesAndValues[i].value << ")"; //print the name-value pairs in coordinate form
    }

    cout << "\n";

    return 0;
}