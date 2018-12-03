#include <fstream>
#include <iostream>

using namespace std;

/* g++ -o test test.cpp */
int main(){

    fstream inFile;
    string fileName = "datafile.csv";
    inFile.open(fileName);

    string str;
    
    getline(inFile, str);
    cout << str << endl;

    getline(inFile, str, ',');
    cout << str << endl;

    getline(inFile, str);
    cout << str << endl;

}