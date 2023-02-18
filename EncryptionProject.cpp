#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;
class Caesar_Encryption {
    // Access specifier
public:
    // Constructors
    /**
     * Default Constructor with no inputs
     */
    Caesar_Encryption(): _key(0){
    }

    /**
     * Constructor with a string input and int key
     */
    Caesar_Encryption(int key): _key(key){
        InitializeDictionaries();
    }

    // Member Functions()
    /**
     * Encrypt
     * @param plainText
     * @return
     */
    string Encrypt(string plainText){
        // initialize variables
        string cipherText;
        char currentChar;
        int charIndex;
        int ptLength = plainText.length();

        // go through the entire plainText and encrypt it using the dictionaries
        for(int i = 0; i < ptLength; i++) {
            // get the currentChar and check it to see if it's not a white space
            currentChar = plainText[i];
            if(isalpha(currentChar)) {
                // make sure it's all uppercase
                currentChar = toupper(currentChar);

                // get the index of the currentChar from the dictionary
                charIndex = IndexOf(_dictionary, currentChar);

                charIndex += _key + 1;

                if(charIndex >= 25) {
                    // if the end of the list has been reached, set finalIndex to 0, else subtract 25
                    if(charIndex == 25) {
                        charIndex = 0;
                    }else{
                        charIndex -= 25;
                    }
                }

                // get the encrypted char from the encrypted dictionary
                currentChar = _encryptedDictionary.at(charIndex);

                // add the current char to the cipherText
                cipherText.push_back(currentChar);
            }else{ // if the currentChar is not a letter, just insert it straight into the cipher text
                cipherText.push_back(currentChar);
            }

        }

        return cipherText;
    }

    /**
     * Decrypt
     * @param cipherText
     * @return
     */
    string Decrypt(string cipherText){
        // initialize variables
        string plainText;
        char currentChar;
        int charIndex;
        int ctLength = cipherText.length();

        // go through the entire cipherText and decrypt it using the dictionaries
        for(int i = 0; i < ctLength; i++) {
            // get the currentChar and check it to see if it's not a white space
            currentChar = cipherText[i];
            if(isalpha(currentChar)) {
                // make sure it's all uppercase
                currentChar = toupper(currentChar);

                // get the index of the currentChar from the encrypted dictionary
                charIndex = IndexOf(_encryptedDictionary, currentChar);

                charIndex -= _key;
                charIndex -= 1;

                if(charIndex <= 0) {
                    // if the end of the list has been reached, set finalIndex to 0, else subtract 25
                    if(charIndex == 0) {
                        charIndex = 0;
                    }else{
                        charIndex += 25;
                    }
                }

                // get the decrypted char from the dictionary
                currentChar = _dictionary.at(charIndex);

                // add the current char to the cipherText
                plainText.push_back(currentChar);
            }else{ // if the currentChar is not a letter, just insert it straight into the cipher text
                plainText.push_back(currentChar);
            }

        }

        return plainText;
    }

private:
    int _key;
    vector<char> _dictionary;
    vector<char> _encryptedDictionary;

    /**
     * InitializeDictionaries \n
     * Creates a dictionary of every uppercase letter.
     */
    void InitializeDictionaries(){
        // initalize variables
        char c;
        //vector<char>::iterator itr;
        int finalIndex;

        // initialize the default dictionary
        for(char ltr = 'A'; ltr <= 'Z'; ltr++) {
            _dictionary.push_back(ltr);
        }

        // initialize the encrypted dictionary
        for(int i = 0; i <= 25; i++) {
            _encryptedDictionary.push_back('0');
        }

        // if the key isn't equal to zero, create the encrypted dictionary by shifting everything in the original by 1
        if(_key > 0) {
            for(int i = 0; i <= 25; i++) {
                // get the char at index i
                c = _dictionary.at(i);

                // if the finalIndex is over 25, subtract 25 from the total
                finalIndex = i + _key;
                if(finalIndex > 25) {
                    // if the end of the list has been reached, set finalIndex to 0, else subtract 25
                    if(i == 25) {
                        finalIndex = 0;
                    }else{
                        finalIndex -= 25;
                    }
                }

                // replace at the given index
                _encryptedDictionary.at(finalIndex) = c;
            }
        }
    }

    /**
     * Finds the Index of a given char in the vector 
     */
    int IndexOf(const vector<char>& v, char c) {
        // for loop that goes through v to find c
        int vLength = v.size();
        for(int i = 0; i < vLength; i++) {
            // if c is found, return the index
            if(v.at(i) == c) {
                return i;
            }
        }

        return 0;
    }
};


     string GenerateKey(string text, string keyword){
        int x = text.size();
        for(int i=0; ; i++){
            if (x == i)
                i = 0;
            if (keyword.size() == text.size())
                break;
            keyword.push_back(keyword[i]);
        }
        return keyword; 
    };
    string EncryptVingenereSquare(string text, string keyword){
        string encryptedtext;

        for(int i=0; i< text.size(); i++){
            
                char x = (text[i]+keyword[i])%26;
                x +='A';
                encryptedtext.push_back(x);
            
            
        }
        return encryptedtext;
        
    };
    string DecryptVingenereSquare(string text, string keyword){
        string orig_text;
 
    for (int i = 0 ; i < text.size(); i++)
    {
        // converting in range 0-25
        char x = (text[i] - keyword[i] + 26) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
    };




int main()
{
    //Defined variable used to access AES Class
    
    string fileName;
    string textFromFile;
    istringstream input;
    

    bool menuExit = false;
    char optionSelection;
    char optionSelection2;
    char optionSelection3;
    int caeserkey;
    string vingenerekey;


    while(menuExit==false){
        cout << "  !----- Welcome to our encryptor/decryptor! -----! \n"
                "    !----- Please select encryption option! -----! \n \n"
            " a. -->  Encrypt and decrypt file using Casears Cipher.\n"
            " b. -->  Encrypt and decrypt file using Vigenere Square.\n"
            " c. -->  Exit the program! \n";

    cout << "Your option -->: ";
    cin >> optionSelection;

        switch (optionSelection) {
            case 'a': 
            {
                cout << "Encrypt (E) or Decrypt (D)?"<<endl;
                cin >>optionSelection2;
                cout << "Enter number between 0-9 for key"<<endl;
                cin >>caeserkey;
                switch(optionSelection2){
                    case 'E':
                    {
                        // Encrypt using Caesars Cipher

                        cout << "Please enter a txt file name without extension: ";
                        cin >> fileName;
                        cout << endl;
                        ifstream file(fileName+".txt");
                        

                        if(!file.is_open()){
                            cerr << "Error: Program could not read file \n" ;
                        }
                        // else {
                        //     while(!file.eof()) {
                        //         getline(file,textFromFile);
                        //     }
                        // }
                        ostringstream str;
                        str << file.rdbuf();
                        textFromFile=str.str();
                        file.close();
                        ofstream fileRewrite(fileName+".txt",ios::trunc);
                        Caesar_Encryption x(caeserkey);
                        
                        fileRewrite << x.Encrypt(textFromFile);
                        fileRewrite.close();
                    }
                    break;
                    case 'D':
                    {
                        // Deceypt using Caesar's Cipher
                        cout << "Please enter a txt file name without extension: ";
                        cin >> fileName;
                        cout << endl;
                        ifstream file(fileName+".txt");
                        

                        if(!file.is_open()){
                            cerr << "Error: Program could not read file \n" ;
                        }
                        // else {
                        //     while(!file.eof()) {
                        //         getline(file,textFromFile);
                        //     }
                        // }
                        ostringstream str;
                        str << file.rdbuf();
                        textFromFile=str.str();
                        file.close();
                        ofstream fileRewrite(fileName+".txt",ios::trunc);
                        Caesar_Encryption y(caeserkey);
                        
                        fileRewrite << y.Decrypt(textFromFile);
                        fileRewrite.close();
                    }
                    break;
                }
                break;
            }
            case 'b':
            {
                cout << "Encrypt (E) or Decrypt (D)?"<<endl;
                cin >>optionSelection3;
                cout << "Enter keyword"<<endl;
                cin >>vingenerekey;
                for (auto & c: vingenerekey) c = toupper(c);
                switch(optionSelection3){
                    case 'E':
                    {
                        // Encrypt using Caesars Cipher

                        cout << "Please enter a txt file name without extension: ";
                        cin >> fileName;
                        cout << endl;
                        ifstream file(fileName+".txt");
                        

                        if(!file.is_open()){
                            cerr << "Error: Program could not read file \n" ;
                        }
                        // else {
                        //     while(!file.eof()) {
                        //         getline(file,textFromFile);
                        //     }
                        // }
                        ostringstream str;
                        str << file.rdbuf();
                        textFromFile=str.str();
                        file.close();
                        ofstream fileRewrite(fileName+".txt",ios::trunc);
                        textFromFile.erase(remove_if(textFromFile.begin(), textFromFile.end(), ::isspace),textFromFile.end());
                        for (auto & c: textFromFile) c = toupper(c);
                        cout << textFromFile;
                        fileRewrite << EncryptVingenereSquare(textFromFile, GenerateKey(textFromFile,vingenerekey));
                        fileRewrite.close();
                        break;
                    }
                    case 'D':
                    {
                        // Deceypt using Caesar's Cipher
                        cout << "Please enter a txt file name without extension: ";
                        cin >> fileName;
                        cout << endl;
                        ifstream file(fileName+".txt");
                        

                        if(!file.is_open()){
                            cerr << "Error: Program could not read file \n" ;
                        }
                        // else {
                        //     while(!file.eof()) {
                        //         getline(file,textFromFile);
                        //     }
                        // }
                        ostringstream str;
                        str << file.rdbuf();
                        textFromFile=str.str();
                        file.close();
                        ofstream fileRewrite(fileName+".txt",ios::trunc);
                        fileRewrite << DecryptVingenereSquare(textFromFile, GenerateKey(textFromFile,vingenerekey));
                        break;
                    }
                }
                break;
            }

            case 'c':
            { menuExit=true;}
         }
         

    }
        cout << "End of the program! Goodbye!" << endl;
    

    
    return 0;
}