#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class DNR {
    //non XOR implementation (Vickers said not to use XOR)
    // Access specifier
public:
    fstream file;
    // Data  Members
    string fileName="";
    // Member Functions()
    void CaesarsCipher(string text){
        
        cout << text << endl;
    };

     string GenerateKey(string text, string keyword){
        int x = text.size();
        for(int i=0; ; i++){
            if (x == i)
            i = 0;
            if (keyword.size() == str.size())
            break;
            keyword.push_back(keyword[i]);
        }
        return keyword; 
    };
    string EncryptVigenereSquare(string text, string keyword){
        string encryptedtext;

        for(int i=0; i< text.size(); i++){
            if(text[i].isaplha()){
                char x = (text[i]+keyword[i])%26;
                x+='A';
                encryptedtext.push_back(x);
            }
            else{
                encryptedtext.push_back(text[i]);
            }
        }
        return encryptedtext;
        
    };
    string DecryptVingenereSquare(string text, string keyword){
        string decryptedtext;
        for(int i=0; i< text.size(); i++){
            if(text[i].isaplha()){
                char x = (text[i]+keyword[i]+26)%26;
                x+='A';
                decryptedtext.push_back(x);
            }
            else{
                decryptedtext.push_back(text[i]);
            }
        }
        return decryptedtext;
    };



};
int main()
{
    //Defined variable used to access AES Class
    DNR userFile;

    string textFromFile;

    bool menuExit = false;
    char optionSelection;


    while(menuExit != true){
        cout << "  !----- Welcome to our DNR encryptor/decryptor! -----! \n"
                "    !----- Please select encryption option! -----! \n \n"
            " a. -->  Encrypt and decrypt file using Casears Cipher.\n"
            " b. -->  Encrypt and decrypt file using Vigenere Square.\n"
            " c. -->  Exit the program! \n";

    cout << "Your option -->: ";
    cin >> optionSelection;

        switch (optionSelection) {

            case 'a':
                // Encrypt and Decrypt file using Caesars Cipher

                cout << "Please enter a file name: ";
                cin >> userFile.fileName;
                cout << endl;

                userFile.file.open(userFile.fileName);

                if(!userFile.file.is_open()){
                    cerr << "Error: Program could not read file \n" ;
                }
                else {
                    while(!userFile.file.eof()) {
                        userFile.file >> textFromFile ;
                        userFile.CaesarsCipher(textFromFile);
                    }
                }
                break;
            case 'b':
                //Encrypt and Decrypt file using Vigenere Square Cipher

                cout << "Please enter a file name: ";
                cin >> userFile.fileName;
                cout << endl;

                userFile.file.open(userFile.fileName);

                if(!userFile.file.is_open()){
                    cerr << "Error: Program could not read file \n" ;
                }
                else {
                    while(!userFile.file.eof()) {
                        userFile.file >> textFromFile ;
                        userFile.VigenereSquare(textFromFile);
                    }
                }
                break;
            case 'c':
                cout << "END of the program! Goodbye!" << endl;
                menuExit = true;
                break;
            default:
                cout << "Not an option! Try again \n \n \n";

        }

    }

    
    return 0;
}