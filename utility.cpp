/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Allison Lee
 * leealli
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * Creating helper functions to use in other functions
 */

#include "utility.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string toUpperCase(string original) {
    string upperString = "";
    
    //only change to uppercase if character in string original is lowercase
    for (int i = 0; i < original.size(); i++) {
        if ((original.at(i) >= 97) && (original.at(i) <= 122)) {
            char upper = toupper(original.at(i));
            upperString = upperString + upper;
            
        } else {
            char upperString2 = original.at(i);
            upperString = upperString + upperString2;
        }
    }
    
    return upperString;
}

string removeNonAlphas(string original) {
    string newString = "";
    for (int i = 0; i < original.size(); i++) {
        if (((original.at(i) >= 65) && (original.at(i) <= 90)) ||
            ((original.at(i) >= 97) && (original.at(i) <= 122))) {
            newString = newString + original.at(i);
        }
    }
    return newString;
}

string removeDuplicate(string original) {
    string newString = "";
    
    for (int i = original.size() - 1; i > 0; i--) {
        int addToString = 0;
        for (int j = 0; j < i; j++) {
            if ((original.at(i) == original.at(j)) && (i > j)) {
                addToString++;
            }
        }
        if (addToString == 0) {
            newString = original.at(i) + newString;
        }
    }
    newString = original.at(0) + newString;
    return newString;
}

int charToInt(char original) {
    
    if (original == 49) {
        return 1;
    } else if (original == 50) {
        return 2;
    } else if (original == 51) {
        return 3;
    } else if (original == 52) {
        return 4;
    } else if (original == 53) {
        return 5;
    } else if (original == 54) {
        return 6;
    } else if (original == 55) {
        return 7;
    } else if (original == 56) {
        return 8;
    } else if (original == 57){
        return 9;
    } else {
        return 0;
    }
    
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
