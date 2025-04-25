#include <fstream>
#include <iostream>
using namespace std;

class File {
private:
    string filename;

public:
    File(string fname) : filename(fname) {}

    string encryptString(const string& input) {
        string encrypted = input;
        for (int i = 0; i < input.length(); i++) {
            encrypted[i] = input[i] + (i + 1);
        }
        return encrypted;
    }


    string decryptString(const string& input) {
        string decrypted = input;
        for (int i = 0; i < input.length(); ++i) {
            decrypted[i] = input[i] - (i + 1);
        }
        return decrypted;
    }

    void writedata(const string& data) {
        ofstream file(filename);
            file << data << endl;
            file.close();
       
    }

    string readdata() {
        ifstream file(filename);
        string data;
        getline(file, data);
        file.close();
        return data;
    }
};

int main() {
    string input;
    cout << "Enter String = ";
    getline(cin, input);

    cout << "\nNormal Text: " << input << endl;

    File F1("File1.txt");

    string encrypted = F1.encryptString(input);
    F1.writedata(encrypted);
    cout << "Encrypted text inserted in file\n";

    
    string readEncrypted = F1.readdata();
    string decrypted = F1.decryptString(readEncrypted);
    cout << "Decrypted text Read then decoded from file: ";
    cout << decrypted << endl;

    return 0;
}
