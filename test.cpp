#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

/* g++ -o test test.cpp */
int main(){

    fstream inFile;
    string fileName = "datafileTest.csv";
    inFile.open(fileName);

    string str;
    
    // getline(inFile, str);
    // cout << "first line :" << str << endl;

    // getline(inFile, str, ',');
    // cout << "second line's first word :" << str << endl;

    // getline(inFile, str);   //  remained strings
    // // cout << str << endl;

    // string _inputStringLine = str;
    // string input = _inputStringLine;
    // string parsed;
    // stringstream input_stringstream(input);

    while (!inFile.eof()){
        getline(inFile, str, ',');
        cout << str << endl;
    }
    // try{

    //     if (getline(input_stringstream, parsed, ','))
    //     {
    //         cout << "second line's second word :" << parsed << endl;
    //     }
    //     else
    //         throw "password parsing error!";

    //     if (getline(input_stringstream, parsed, ','))
    //     {
    //         cout << parsed << endl;
    //     }
    //     else
    //         throw "parsing error?";
        
    // }
    // catch (char const *msg)
    // {
    //     cerr << msg << endl;
    //     // exit(0);
    // }
}