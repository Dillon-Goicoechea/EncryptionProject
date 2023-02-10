
using namespace std;
class AES {
    //non XOR implementation (Vickers said not to use XOR)
    // Access specifier
public:
    // Data  Members
    string fileName="";
    // Member Functions()
    void Encrypt(){
        //needs to read non-encrpted file in file in segments of 16 charcters into a 4x4 array like [][] 
        //and call the shift rows and mix columns functions and rewrite file
    };
    void Decrypt(){
        //needs to encrypted file in segments of 16 charcters into a 4x4 array like [][] 
        //and call the inverse shift rows and inverse mix columns functions and rewrite file
    }; 

    void ShiftRows(&char section[][]) {
        //Dillon will implement
    };
    void MixColumns(&char section[][]) {

    };
    void InverseShiftRows(&char section[][]) {
        //Dillon will implement this
    };
    void InverseMixColumns(&char section[][]) {

    };

};
int main()
{
    //implement menu for user
    //Dillon Will implement
    AES userFile;
    
    
    return 0;
}