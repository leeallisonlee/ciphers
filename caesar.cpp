/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Allison Lee
 * leealli
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * Writing function for caesar cipher and its helper functions
 */

#include "caesar.h"
#include <iostream>


char shiftAlphaCharacter(char c, int n) {
    //shifting for lowercase char
    if (c >= 97 && c <= 122) {
        if ((c + n) < 97) {
            return ((((c - 'a') + n) % 26) + 'z' + 1);
        } else {
            return (((c - 'a') + n) % 26) + 'a';
        }
    } else if (c >= 65 && c <= 90) {
        if ((c + n) < 65) {
            return ((((c - 'A') + n) % 26) + 'Z' + 1);
        } else {
            return (((c - 'A') + n) % 26) + 'A';
        }
    }
    return ' ';
}

string caesarCipher(string original, int key, bool encrypt) {
    if (encrypt == true) {
        string newString = "";
        //run through original and add shifted characters to string (encrypt)
        for (int i = 0; i < original.size(); i++) {
            if ((original.at(i) >= 97 && original.at(i) <= 122) ||
                    (original.at(i) >= 65 && original.at(i) <= 90) ) {
                char addChar = shiftAlphaCharacter(original.at(i), key);
                newString += addChar;
            } else {
                newString += original.at(i);
            }
        }
        return newString;
    } else {
        string otherString = "";
        //run through original and add shifted characters to string (decrypt)
        for (int i = 0; i < original.size(); i++) {
            if ((original.at(i) >= 97 && original.at(i) <= 122) ||
                    (original.at(i) >= 65 && original.at(i) <= 90)) {
                char addNewChar =
                        shiftAlphaCharacter(original.at(i), (-(key % 26)));
                otherString += addNewChar;
            } else {
                otherString += original.at(i);
            }
        }
        return otherString;
    }
    
}
