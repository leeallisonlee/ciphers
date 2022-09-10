/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Allison Lee
 * leealli
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * Writing function for polybius cipher and its helper functions
 */


#include "polybius.h"
#include <string>
using namespace std;

string mixKey(string key) {
    string newString = key + ALNUM;
    return removeDuplicate(newString);
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    int indexCounter = 0;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            grid[row][col] = content.at(indexCounter);
            indexCounter++;
        }
    }
    return;
}


string findInGrid(char c, char grid[SIZE][SIZE]) {
    string returnString = "";
    
    //run through grid, find c, and change row/col location to string
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == c) {
                returnString += to_string(row);
                returnString += to_string(col);
                return returnString;
            }
        }
    }
    return "";
}

string polybiusSquare(char grid[SIZE][SIZE], string key, string original,
                      bool encrypt) {
    string codeString = "";
    
    //change key
    string newKey = mixKey(key);
    //fill the grid with changed key
    fillGrid(grid, newKey);

    //encrypt/decrypt
    if (encrypt == true) {
        
        for (int i = 0; i < original.size(); i++) {
            if (original.at(i) != ' ') {
                codeString += findInGrid(original.at(i), grid);
                
            } else {
                codeString += " ";
            }
        }
        return codeString;
    } else {
        
        for (int i = 0; i < original.size() - 1; i = i + 2) {
            if (original.at(i) != ' ') {
                codeString += grid[static_cast<int>(original.at(i) - '0')][static_cast<int>(original.at(i + 1) - '0')];
            } else {
                codeString += " ";
                i--;
            }
        }
        return codeString;
    }
    
}
