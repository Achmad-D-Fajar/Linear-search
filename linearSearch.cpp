#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Step1, input data file
    ifstream file("DtaNama.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open the file!" << endl;
        return 1;
    }
    // Step2, declare
    int s;
    int n = 0;
    int i = 0;
    // Step3, input n
    string line;
    while (getline(file, line)) {
        n++;
    }
    // Reset file
    file.clear();
    file.seekg(0, ios::beg);
    // Data dynamic array
    string* data = new string[n];
    int index = 0;
    while (getline(file, data[index])) {
        index++;
    }
    file.close();
    // Step3, input s
    cout << "File loaded successfully." << endl;
    cout << "Enter a number to search: ";
    cin >> s;
    //Linear search
    // Step4, check i=n
    bool found = false;
    for (i; i < n; i++) { //Step5 no-> i++
        // Take number in line
        int space = data[i].find(' ');
        int number = stoi(data[i].substr(0, space));
        //Step4 yes-> Step5, check i=s
        if (number == s) {
            cout << "Result: " << data[i] << endl;
            found = true;
            break; // Step5 yes-> end
        }
    }
    // Step4 no-> end
    if (found==false) {
        cout << "Data not found" << endl;
    }
    //Delete data dynamic array
    delete[] data;

    return 0;
}