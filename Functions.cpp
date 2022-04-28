#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h"

using namespace std;

//_________________________________________
void addText() {
    fstream file;
    char name[100];
    string Text;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file as in to check if it exist
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            file.close(); // close the file to open it to append
            file.open(name, ios::app); // open the file to append
            cout << "Please enter the Text to append: ";
            cin.ignore();
            getline(cin, Text);
            file << " " << Text;
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_________________________________________
void dispalyContent() {
    fstream file;
    char name[100];
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            cout << file.rdbuf(); // reading the buffer and print it
            break;
        }
    }
    file.close();
}
//_________________________________________
void emptyFile() {
    fstream file;
    char name[100];
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::out);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            file.clear(); // Clearing the file content
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_________________________________________
void encryptFile() {
    fstream file;
    char name[100];
    string buffer = "";

    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file to take the buffer
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                if (file.peek() == EOF) { // To avoid printing EOF char
                    break;
                }
                buffer += char(file.get()); // Add each char to the buffer
            }
            file.close(); // Close the file
            for (int i = 0; i < buffer.size(); i++) { // Encrypt the file content
                buffer[i]++;
            }
            file.open(name, ios::out); // Open the file for writing
            file << buffer; // Add the content encrypted to the file
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_________________________________________
void decryptFile() {
    fstream file;
    char name[100];
    string buffer = "";

    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                if (file.peek() == EOF) { // To avoid printing EOF char
                    break;
                }
                buffer += char(file.get()); // Add each char to the buffer
            }
            file.close();
            for (int i = 0; i < buffer.size(); i++) { // Decrypt the file content
                buffer[i]--;
            }
            file.open(name, ios::out); // Open the file for writing
            file << buffer; // Add the content decrypted to the file
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_________________________________________
void Merge() {
    fstream firstFile, secFile;
    char name1[100], name2[100];
    while (true)
    {
        cout << "Please enter the first file name to append to(e.g. file1.txt): ";
        cin >> name1;
        cout << "Please enter the second file name(e.g. file2.txt): ";
        cin >> name2;
        firstFile.open(name1, ios::in);
        secFile.open(name2, ios::in);
        if (firstFile.fail() || secFile.fail()) {
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            firstFile.close();
            firstFile.open(name1, ios::app);
            firstFile << "\n" << secFile.rdbuf();
            cout << "Please go check " << name1 << "\n";
            break;
        }
    }
    firstFile.close();
    secFile.close();

}
//_________________________________________
void countWords() {
    fstream file;
    char name[100];
    int count = 0;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                file >> name;
                if (name != NULL) { // Count words
                    count++;
                }
            }
            cout << "There is " << count << " words in this file.";
            break;
        }
    }
    file.close();
}
//_________________________________________
void countChars() {
    fstream file;
    char name[100];
    int count = 0;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                /*if (isalnum(file.get())) { // will count if alpha or digit not else
                    count++;
                }*/
                if (isascii(file.get())) { // If the char is in ascii will count even spaces
                    count++;
                }
            }
            cout << "There is " << count << " characters in this file.";
            break;
        }
    }
    file.close();
}
//_________________________________________
void countLines() {
    fstream file;
    char name[256];
    int count = 0;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                if (file.getline(name, 256, '\n')) { // Count lines
                    count++;
                }
            }
            cout << "There is " << count << " lines in this file.";
            break;
        }
    }
    file.close();
}
//_________________________________________
void searchWord() {
    fstream file;
    int check = 0;
    char fileName[100];
    string word, name;
    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> fileName;
        file.open(fileName, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            cout << "Please enter the word to search for: ";
            cin >> word;
            for (int i = 0; i < word.size(); i++) { // to ignore the case 
                word[i] = toupper(word[i]);
            }
            while (!file.eof()) {
                file >> name;
                for (int i = 0; i < name.size(); i++) {
                    name[i] = toupper(name[i]);
                }
                if (name == word) {
                    check = 1;
                    break;
                }
            }
            if (check == 1) {
                cout << "Word was found in the file.";
                break;
            }
            else {
                cout << "Word was not found in the file.";
            }
        }
    }
    file.close();
}
//_________________________________________
void countWordExists() {
    fstream file;
    char name[100];
    int count = 0;
    string buffer = "", word, temp;
    istringstream content("");

    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            cout << "Please enter the word to search for: ";
            cin >> word;
            for (int i = 0; i < word.size(); i++) { // To ignore the case 
                word[i] = toupper(word[i]);
            }
            while (!file.eof())
            {
                if (file.peek() == EOF) { // To avoid taking EOF char
                    break;
                }
                buffer += char(file.get()); // Add each char to the buffer
            }
            content.str(buffer); 
            content >> temp; // Put the first word to check it
            while (content)
            {
                for (int i = 0; i < temp.size(); i++) { // To ignore the case
                    temp[i] = toupper(temp[i]);
                }
                if (word == temp) {
                    count++;
                }
                content >> temp; // To put the next word to check it
            }
            cout << "The word \"" << word << "\" was found " << count << " times in the file.";
            break;
        }
    }
    file.close();
}
//_________________________________________
void upperCase() {
    fstream file;
    char name[100];
    string buffer = "";

    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                if (file.peek() == EOF) { // To avoid taking EOF char
                    break;
                }
                buffer += char(file.get()); // Add each char to the buffer
            }
            file.close();
            for (int i = 0; i < buffer.size(); i++) { // Content to upper case
                buffer[i] = toupper(buffer[i]);
            }
            file.open(name, ios::out); // Open the file for writing
            file << buffer; // Add the content to the file
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
 }
//_________________________________________
void lowerCase() {
    fstream file;
    char name[100];
    string buffer = "";

    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                if (file.peek() == EOF) { // To avoid taking EOF char
                    break;
                }
                buffer += char(file.get()); // Add each char to the buffer
            }
            file.close();
            for (int i = 0; i < buffer.size(); i++) { // Content to lower case
                buffer[i] = tolower(buffer[i]);
            }
            file.open(name, ios::out); // Open the file for writing
            file << buffer; // Add the content to the file
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_________________________________________
void contentCaps() {
    fstream file;
    char name[100];
    int count = 0;
    string buffer = "", word = "", temp;
    istringstream content("");

    while (true)
    {
        cout << "Please enter the file name (e.g. file1.txt): ";
        cin >> name;
        file.open(name, ios::in);// Opening file
        if (file.fail()) { // If the file is not exist ask the user again to enter the file name
            cout << "Please enter valid file name.\n";
            cin.ignore();
        }
        else {
            while (!file.eof())
            {
                if (file.peek() == EOF) { // To avoid taking EOF char
                    break;
                }
                buffer += char(file.get()); // Add each char to the buffer
            }
            file.close();
            content.str(buffer);
            buffer = "";
            content >> temp; // Put the first word to change it
            while (content)
            {
                temp[0] = toupper(temp[0]);
                buffer += temp + " ";
                content >> temp; // To put the next word to change it
            }
            file.open(name, ios::out);
            for (int i = 0; i < buffer.size() - 1; i++) {
                word += buffer[i];
            }
            file << word;
            cout << "Please go check " << name << "\n";
            break;
        }
    }
    file.close();
}
//_________________________________________