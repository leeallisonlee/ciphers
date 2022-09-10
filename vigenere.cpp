/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Allison Lee
 * leealli
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * Writing function for vigenere cipher
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

string vigenereCipher(string original, string keyword, bool encrypt) {
    //remove non alphas and make keyword all caps to use later
    string nonAlphaString = removeNonAlphas(keyword);
    string allCapsString = toUpperCase(nonAlphaString);
    string finalKeyword = "";
    
    //fill new keyword in the same format as original(add spaces for nonalphas)
    int spaceCounter = 0;
    for (int i = 0; i < original.size(); i++) {
        if (!((original.at(i) >= 97 && original.at(i) <= 122) ||
                (original.at(i) >= 65 && original.at(i) <= 90))) {
            finalKeyword += ' ';
            spaceCounter++;
        } else {
            finalKeyword +=
            allCapsString.at((i - spaceCounter) % (allCapsString.size()));
        }
    }
    //if encrypt is true
    //shift characters in new keyword using shiftAlphaCharacter()
    //else
    //shift characters in new keyward backwards using shiftAlphaCharacter()
    if (encrypt == true) {
        
        string finalString = "";
        for (int i = 0; i < finalKeyword.size(); i++) {
            int indexFromA = finalKeyword.at(i) - 'A';
            if ((original.at(i) >= 97 && original.at(i) <= 122) ||
                    (original.at(i) >= 65 && original.at(i) <= 90)) {
                finalString += shiftAlphaCharacter(original.at(i), indexFromA);
            } else {
                finalString += original.at(i);
            }
            
        }
        return finalString;
    } else {
        string finalString2 = "";
        for (int i = 0; i < finalKeyword.size(); i++) {
            int indexFromA = finalKeyword.at(i) - 'A';
            if ((original.at(i) >= 97 && original.at(i) <= 122) ||
                    (original.at(i) >= 65 && original.at(i) <= 90)) {
                finalString2 +=
                shiftAlphaCharacter(original.at(i), -(indexFromA % 26));
            } else {
                finalString2 += original.at(i);
            }
            
        }
        return finalString2;
    }
    
    
}
