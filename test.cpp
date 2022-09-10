//
//  test.cpp
//  Project-3
//
//  Created by Allison Lee on 2/12/22.

//Allison Lee
//leealli

// EECS 183: Project 3
//Winter 2022

// Testing functions in utility.h, caesar.h, vigenere.h, and polybius.h

#include <iostream>
#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
using namespace std;

//declare test functions
void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testShiftAlphaCharacter();
void testCaesarCipher();
void testVigenereCipher();
void testFillGrid();
void testMixKey();
void testFindInGrid();
void testPolybiusSquare();



//call test functions
void startTests() {
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testCaesarCipher();
    testVigenereCipher();
    testFillGrid();
    testMixKey();
    testFindInGrid();
    testPolybiusSquare();
    
    return;
}

//make test functions below

void testToUpperCase() {
    cout << "Now testing toUpperCase()" << endl;
    cout << endl;
    cout << "Expected : I LOVE YOU Actual : " << toUpperCase("I love you");
    cout << endl;
    
    cout << "Expected : HELLO*&@@ Actual : " << toUpperCase("hello*&@@");
    cout << endl;
    
    cout << "Expected :  NO. Actual : " << toUpperCase(" no.");
    cout << endl;
    cout << endl;
    return;
}

void testRemoveNonAlphas() {
    cout << "Now testing removeNonAlphas()" << endl;
    cout << endl;
    
    cout << "Expected : Hiwhatsup Actual : " << removeNonAlphas("Hi what's up");
    cout << endl;
    
    cout << "Expected : ihey Actual : " << removeNonAlphas("i ^^3hey *)");
    cout << endl;
    cout << endl;
    return;
}

void testRemoveDuplicate() {
    cout << "Now testing removeDuplicate()" << endl;
    cout << endl;
    
    cout << "Expected: ABC Actual : " << removeDuplicate("AABBCC");
    cout << endl;
    cout << "Expected: A1B Actual : " << removeDuplicate("A11BB");
    cout << endl;
    cout << "Expected: NWHYSI Actual : " << removeDuplicate("NNWHYSIS");
    cout << endl;
    
    return;
}

void testCharToInt() {
    cout << "Now testing charToInt()" << endl;
    cout << endl;
    
    cout << "Expected: 3 Actual: " << charToInt('3');
    cout << endl;
    
    cout << "Expected: 0 Actual: " << charToInt('0');
    cout << endl;
    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing shiftAlphaCharacter()" << endl;
    cout << endl;
    
    cout << "Expected : z Actual : " << shiftAlphaCharacter('u', 5);
    cout << endl;
    
    cout << "Expected : u Actual : " << shiftAlphaCharacter('z', -5);
    cout << endl;
    
    cout << "Expected : b Actual : " << shiftAlphaCharacter('y', 3);
    cout << endl;
    
    cout << "Expected : y Actual : " << shiftAlphaCharacter('b', -3);
    cout << endl;
    
    cout << "Expected : Y Actual : " << shiftAlphaCharacter('B', -3);
    cout << endl;
    
    cout << "Expected : B Actual : " << shiftAlphaCharacter('Y', 3);
    cout << endl;
    
    cout << "Expected : U Actual : " << shiftAlphaCharacter('Z', -5);
    cout << endl;
    
    cout << "Expected : Z Actual : " << shiftAlphaCharacter('U', 5);
    cout << endl;
    
    cout << endl;
    return;
}

void testCaesarCipher() {
    cout << "Now testing caesarCipher()" << endl;
    cout << endl;
    
    cout << "Expected : Cuuj cu qj jxu Tyqw qj 11 f.c. Actual : " <<
        caesarCipher("Meet me at the Diag at 11 p.m.", 42, true);
    cout << endl;
    
    cout << "Expected : Meet me at the Diag at 11 p.m. Actual : " <<
        caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false);
    cout << endl;

    
    return;
}

void testVigenereCipher() {
    cout << "Now testing vigenereCipher()" << endl;
    cout << endl;
    
    cout << "Expected : Euyb dv ee lxy Lzrk ll 11 f.g. Actual : " <<
        vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true);
    cout << endl;
    
    cout << "Expected : Meet me at the Diag at 11 p.m. Actual : " <<
        vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false);
    cout << endl;
    return;
}

void testFillGrid() {
    cout << "Now testing fillGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
    return;
}

void testMixKey() {
    cout << "Now testing mixKey()" << endl;
    cout << endl;
    
    cout << "Expected : POLYBIUSACDEFGHJKMNQRTVWXZ0123456789 Actual : ";
    cout << mixKey("POLYBIUS");
    cout << endl;
    
    return;
}

void testFindInGrid() {
    cout << "Now testing findInGrid()" << endl;
    cout << endl;
    
    cout << "Expected : 00 Actual : ";
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << findInGrid('A', grid) << endl;
    cout << endl;
    
    cout << "Expected : 23 Actual : ";
    cout << findInGrid('P', grid) << endl;
    cout << endl;
    return;
}

void testPolybiusSquare() {
    cout << "Now testing polybiusSquare()" << endl;
    
    cout << "Expected : 11110533 000102 1533 341411 04113334 Actual : ";
    char grid[SIZE][SIZE];
    cout << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << endl;
    cout << endl;
    
    cout << "Expected : EECS 183 IS THE BEST Actual : ";
    cout << polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334",
                false) << endl;

    
    cout << endl;
    
    return;
}


