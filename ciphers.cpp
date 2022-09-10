/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Allison Lee
 * leealli
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * Main function to get user input and encrypt/decrypt user input based on
 which cipher they want
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

//declare functions
string getMessage();
bool checkMessageValidity(string message);
string getKey();
bool checkKey(string key);

/*
 Requires : nothing
 Modifies : cin, cout
 Effects : Get user message input and return the message
 */
string getMessage() {
    string message;
    cout << "Enter a message: ";
    getline(cin, message);
    cout << endl;
    
    return message;
}

/*
 Requires : nothing
 Modifies : nothing
 Effects : Checks if the message inputed by user is valid, return true if
 it is valid, false if it is not. 
 */
bool checkMessageValidity(string message) {
    //only use for polybius
    
    for (int x = 0; x < message.size(); x++) {
        if (!((message.at(x) >= 65 && message.at(x) <= 90) ||
                (message.at(x) >= 97 && message.at(x) <= 122) ||
                    message.at(x) == 32 || (message.at(x) >= 48 &&
                        message.at(x) <= 57))) {
            cout << "Invalid message!" << endl;
            return false;
        }
    }
    return true;
}

/*
 Requires : nothing
 Modifies : cin, cout
 Effects : Gets user string input for key, only use for polybius and vigenere.
 Returns the user inputted string.
*/
string getKey() {
    //use for all but caesar
    string keyword;
    cout << "What is your key: ";
    getline(cin, keyword);
    cout << endl;
    
    return keyword;
    
}

/*
 Requires : nothing
 Modifies : nothing
 Effects : checking if key is valid. Returns true if it is valid, false if it
 is not.
*/
bool checkKey(string key) {
    //use only for vigenere
    int charCounter = 0;
    for (int num = 0; num < key.size(); num++) {
        if ((key.at(num) >= 65 && key.at(num) <= 90) ||
                (key.at(num) >= 97 && key.at(num) <= 122)) {
            charCounter++;
        }
    }
    if (charCounter == 0) {
        cout << "Invalid key!" << endl;
        return false;
    } else {
        return true;
    }
}

void ciphers() {
    string cipherChoice;
    
    // ask user for cipher (Caesar, Vigenere, or Polybius)
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    getline(cin, cipherChoice);
    cout << endl;
    
    //make cipher uppercase to make it easier to check
    cipherChoice = toUpperCase(cipherChoice);
    
    //check if cipher input is valid
    if (!(cipherChoice == "CAESAR" || cipherChoice == "C" ||
            cipherChoice == "VIGENERE" || cipherChoice == "V" ||
                cipherChoice == "POLYBIUS" || cipherChoice == "P")) {
        cout << "Invalid cipher!" << endl;
        return;
    }
    
    //ask if encrypt or decrypt
    string encryptChoice;
    cout << "Encrypt or decrypt: ";
    getline(cin, encryptChoice);
    cout << endl;
    
    //check if encryptChoice is valid & store encryption choice
    encryptChoice = toUpperCase(encryptChoice);
    bool encryptOrNo;
    if (!(encryptChoice == "ENCRYPT" || encryptChoice == "DECRYPT" ||
            encryptChoice == "E" || encryptChoice == "D")) {
        cout << "Invalid mode!" << endl;
        return;
    } else if (encryptChoice == "ENCRYPT" || encryptChoice == "E") {
        encryptOrNo = true;
    } else {
        encryptOrNo = false;
    }
    
    //get message
    string original = getMessage();
    
    //run if choice is caesar
    if (cipherChoice == "CAESAR" || cipherChoice == "C") {
        
        //get key
        int keyNum;
        cout << "What is your key: ";
        cin >> keyNum;
        cout << endl;
        
        //run caesar
        string result = "";
        result = caesarCipher(original, keyNum, encryptOrNo);
        
        //return result
        if (encryptOrNo == true) {
            cout << "The encrypted message is: " << result << endl;
            cout << endl;
        } else {
            cout << "The decrypted message is: " << result << endl;
            cout << endl;
        }
        return;
    }
    else if (cipherChoice == "VIGENERE" || cipherChoice == "V"){
        //implement vigenere
        
        //get key
        string keyword = getKey();
        
        //check key
        bool keyOrNo = checkKey(keyword);
        
        //run program if key is okay
        if (keyOrNo == false) {
            return;
        } else {
            string result = vigenereCipher(original, keyword, encryptOrNo);
            
             //output message
            if (encryptOrNo == true) {
                cout << "The encrypted message is: " << result << endl;
                cout << endl;
            } else {
                cout << "The decrypted message is: " << result << endl;
                cout << endl;
            }
        }
        
    }
    else {
        //implement polybius
        
        //check message validity
        bool messageOrNo = checkMessageValidity(original);
        if (messageOrNo == false) {
            return;
        } else {
            
            //get key
            string keyword = getKey();
            
            //change keyword to valid keyword
            keyword = removeDuplicate(toUpperCase(removeNonAlphas(keyword)));
            
            //run polybius
            char grid[SIZE][SIZE];
            string result = polybiusSquare(grid, keyword, toUpperCase(original), encryptOrNo);
            
            if (encryptOrNo == true) {
                cout << "The encrypted message is: " << result << endl;
            } else {
                cout << "The decrypted message is: " << result << endl;
            }
        }
    }
    return;
   

}
