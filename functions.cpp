#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//for a
//file is opened in main then passed into readMagicResponses
//reads in up to MAXSIZE number of records
//returns number of records read actually read in

int readMagicResponses(ifstream &infile, string magicResponse[], const int MAXSIZE) {
    magicResponse = new string[MAXSIZE];
    if (!infile.fail()) {
        cout << "Enter 'a' or 'A' too see just the responses" << endl;
        cout
                << "Enter 'b' or 'B' too see the responses and the category they belong too (positive, negative, or vague)"
                << endl;
        char input;
        cin >> input;
        while ((input != 'a') && (input != 'A') && (input != 'b') && (input != 'B')) {
            cout << "Please enter one of the available options ('a','A' or 'b','B')" << endl << endl;
            cout << "Enter 'a' or 'A' too see just the responses." << endl;
            cout
                    << "Enter 'b' or 'B' too see the responses and the category they belong too (positive, negative, or vague)."
                    << endl;
            cin >> input;
        }
        for (int i = 0; i < MAXSIZE; i++) {
            getline(infile, magicResponse[i]);
            if ((input == 'a') || (input == 'A')) {
                if (i % 2 != 1) {
                    cout << magicResponse[i] << endl;
                }
            }
            if ((input == 'b') || (input == 'B')) {
                if (i % 2 != 0) {
                    cout << magicResponse[i] << ": " << magicResponse[i - 1] << endl;
                }
            }
        }
    }
}

//for b
//While the user doesn't type the word quit
//Asks a user for a question
//Choose a random size between zero and count of number of records
//Provides the response from that position in the array
void playMagic(string magicResponse[], int currentSize){
    cout << "Please type in your question" << endl;
    cout << "Ask as many questions as you want" << endl;
    cout << "Type 'quit' at anytime to exit" << endl;
    string question;
    cin.ignore();
    getline(cin, question, '\n');
    while (question != "quit") {
        const int MAXSIZE = 40;
        ifstream infile;
        infile.open("magicIn.txt");
        for (int i = 0; i < MAXSIZE; i++) {
            getline(infile, magicResponse[i]);
        }
        currentSize = 2 + (2 * rand()) % 40;
        cout << "You asked: " << question << endl;
        cout << "Magic Eight Ball says: " << magicResponse[currentSize] << endl;
        getline(cin, question, '\n');
    }
}

//for c
//Asks the user to whether to sort on responses or categories
//After sorting, print the response and category to the screen.
void printSorted(string magicResponse[], int currentSize) {
    cout << "This is the Sorting of the responses program" << endl;
    char again = 'y';
    do{
        const int MAXSIZE = 40;
        ifstream infile;
        infile.open("magicIn.txt");
        for (currentSize = 0; currentSize < MAXSIZE; currentSize++) {
            getline(infile, magicResponse[currentSize]);
        }
        cout << "Menu of choices:  " << endl << endl;
        cout << "a. specific category in alphabetical order" << endl;
        cout << "b. all responses in alphabetical order" << endl;
        char in;
        cin >> in;
        while ((in != 'a') && (in != 'A') && (in != 'b') && (in != 'B')) {
            cout << "Please enter one of the available options (a or b)" << endl;
            cout << "a. specific category in alphabetical order" << endl;
            cout << "b. all responses in alphabetical order" << endl;
            cin >> in;
        }
        if ((in == 'a') || (in == 'A')) {
            cout << "What category of responses do you want to see alphabetical?" << endl;
            cout << "a. positive" << endl << "b. vague" << endl << "c. negative" << endl;
            char in2;
            cin >> in2;
            while ((in2 != 'a') && (in2 != 'A') && (in2 != 'b') && (in2 != 'B') && (in2 != 'c') && (in2 != 'C')) {
                cout << "Please enter one of the available options (a or b or c)" << endl;
                cout << "a. positive" << endl << "b. vague" << endl << "c. negative" << endl;
                cin >> in2;
            }
            if ((in2 == 'a') || (in2 == 'A')) {
                int sizePositive = 20;
                int j = 0;
                bool swap = true;
                string temp;
                while (swap) {
                    swap = false;
                    j++;
                    for (int l = 0; l < sizePositive - j; l++) {
                        if (magicResponse[l] > magicResponse[l + 1]) {
                            temp = magicResponse[l];
                            magicResponse[l] = magicResponse[l + 1];
                            magicResponse[l + 1] = temp;
                            swap = true;
                        }
                    }
                }
                for (int k = 0; k < sizePositive / 2; k++) {
                    cout << magicResponse[k] << endl;
                }
                cout << endl;
                cout << "Play again? Type 'y' to play again. Type any key to exit" << endl;
                cin >> again;
            }
            if ((in2 == 'b') || (in2 == 'B')) {
                int sizeVague = 30;
                int j = 0;
                bool swap = true;
                string temp;
                while (swap) {
                    swap = false;
                    j++;
                    for (int l = 20; l < sizeVague - j; l++) {
                        if (magicResponse[l] > magicResponse[l + 1]) {
                            temp = magicResponse[l];
                            magicResponse[l] = magicResponse[l + 1];
                            magicResponse[l + 1] = temp;
                            swap = true;
                        }
                    }
                }
                for (int k = 20; k < sizeVague - 5; k++) {
                    cout << magicResponse[k] << endl;
                }
                cout << endl;
                cout << "Play again? Type 'y' to play again. Type any key to exit" << endl;
                cin >> again;
            }
            if ((in2 == 'c') || (in2 == 'C')) {
                int sizeNegative = 40;
                int j = 0;
                bool swap = true;
                string temp;
                while (swap) {
                    swap = false;
                    j++;
                    for (int l = 30; l < sizeNegative - j; l++) {
                        if (magicResponse[l] > magicResponse[l + 1]) {
                            temp = magicResponse[l];
                            magicResponse[l] = magicResponse[l + 1];
                            magicResponse[l + 1] = temp;
                            swap = true;
                        }
                    }
                }
                for (int k = 30; k < sizeNegative - 5; k++) {
                    cout << magicResponse[k] << endl;
                }
                cout << endl;
                cout << "Play again? Type 'y' to play again. Type any key to exit" << endl;
                cin >> again;
            }
        }
        if ((in == 'b') || (in == 'B')) {
            int j = 0;
            bool swap = true;
            string temp;
            while (swap) {
                swap = false;
                j++;
                for (int l = 0; l < MAXSIZE - j; l++) {
                    if (magicResponse[l] > magicResponse[l + 1]) {
                        temp = magicResponse[l];
                        magicResponse[l] = magicResponse[l + 1];
                        magicResponse[l + 1] = temp;
                        swap = true;
                    }
                }
            }
            for (int k = 0; k < MAXSIZE / 2; k++) {
                cout << magicResponse[k] << endl;
            }
            cout << endl;
            cout << "Play again? Type 'y' to play again. Type any key to exit" << endl;
            cin >> again;
        }
    }while(again == 'y');
}


//for d
//Writes the array with responses and categories to a file
//in the same order that you passed into the function
void writeMagicResponses(ofstream &outfile, string magicResponse[], int currentSize){
    magicResponse = new string[currentSize];
    ifstream infile;
    infile.open("magicIn.txt");
    for(int i =0; i<currentSize; i++){
        getline(infile, magicResponse[i]);
    }
    for(int i =0; i<currentSize; i++) {
        outfile << magicResponse[i] << endl;
        cout << magicResponse[i] << endl;
    }
}

//for e
//Add a Response and associated Category to the back of the array if there is room
//Let the user know if it was too full to add. Don't forget to add one to your currentSize!
//currentSize is passed by reference since we will change it.
void addMagicResponse(string magicResponse[], int &currentSize, const int MAXSIZE){
    magicResponse = new string[currentSize];
    ifstream infile;
    infile.open("magicIn.txt");
    for(int i = 0; i < MAXSIZE-1; i++){
        getline(infile, magicResponse[i]);
    }
    for(int j = MAXSIZE-1; j < currentSize-1; j=j+2){
        cout << "Enter the response you want to add" << endl;
        cin >> magicResponse[j];
        cout << "Enter the category of your new response: positive, negative, vague" << endl;
        cout << "1. Positive" << endl;
        cout << "2. Negative" << endl;
        cout << "3. Vague" << endl;
        int catag;
        cin >> catag;
        while((catag != 1) && (catag != 2) && (catag !=3)){
            cout << "Please enter one of the available options!" << endl;
            cout << "1. Positive" << endl;
            cout << "2. Negative" << endl;
            cout << "3. Vague" << endl;
            cin >> catag;
        }
        if(catag == 1){
            magicResponse[j+1] = "positive";
        }
        if(catag == 2){
            magicResponse[j+1] = "negative";
        }
        if(catag == 3){
            magicResponse[j+1] = "vague";
        }
    }
    cout << "What do you want to do with your new personalized list?" << endl;
    cout << "a. Print out your new list to see for yourself" << endl;
    cout << "b. Send your new list to a new file to use later" << endl;
    char whatDo;
    cin >> whatDo;
    while((whatDo != 'a') && (whatDo != 'A') && (whatDo != 'b') && (whatDo != 'B')){
        cout << "Please enter one of the available options" << endl;
        cout << "a. Print out your new list to see for yourself" << endl;
        cout << "b. Send your new list to a txt file called 'alexOut.txt" << endl;
        cin >> whatDo;
    }
    if((whatDo == 'a') || (whatDo == 'A')){
        for(int k = 0; k < currentSize; k++){
            cout << magicResponse[k] << endl;
        }
    }
    if((whatDo == 'b') || (whatDo == 'B')){
        ofstream outfile;
        outfile.open("alexOut.txt");
        for(int k = 0; k < currentSize; k++){
            outfile << magicResponse[k] << endl;
        }
    }
}
//for f;
/*Ask the user for a specific index number to delete. Note that static arrays can not
actually delete, so we have to shift everything to the left by
overwriting the old value. Don't forget to decrease currentSize by one*/
void deleteMagicResponse(string magicResponse[], int &currentSize) {
    cout << "What response do you want to delete?" << endl;
    ifstream infile;
    infile.open("magicIn.txt");
    fstream outfile;
    outfile.open("alexOut.txt");
    for (int i = 0; i < currentSize; i++) {
        getline(infile, magicResponse[i]);
        if (i % 2 != 0) {
            cout << "#" << (i / 2) + 1 << ": " << magicResponse[i - 1] << endl;
            cout << "#" << (i / 2) + 1 << " category: " << magicResponse[i] << endl;
            cout << endl;
        }
    }
    infile.close();
    cout << "Please pick a specific number that correlates to the response you want to delete " << endl;
    int pickNum;
    cin >> pickNum;
    while (pickNum <= 0 || pickNum >= 21) {
        cout << "Please pick of the available responses to delete (1 threw 20)" << endl;
        cin >> pickNum;
    }
    if (pickNum >= 1 && pickNum <= 20) {
        infile.open("magicIn.txt");
        magicResponse = new string[(currentSize +1)];
        for (int i = 0; i < (pickNum * 2)-2; i++) {
            getline(infile, magicResponse[i]);
            outfile <<  magicResponse[i] << endl;
        }
        cout << endl << endl;
        for(int i = pickNum*2-1; i < (pickNum*2)+2; i++){
            infile.ignore(15, '\n');
        }
        for (int i = (pickNum*2)+2; i < currentSize+1; i++) {
            getline(infile, magicResponse[i]);
            outfile << magicResponse[i] << endl;
        }
        outfile.close();
    }
    outfile.open("alexOut.txt");
    string newest[40];
    for(int i = 0; i < 38; i++){
        getline(outfile, newest[i]);
        if (i % 2 != 1) {
            cout << "#" << (i / 2) + 1 << ": " << newest[i] << endl;
            cout << "#" << (i / 2) + 1 << " category: " << newest[i-1] << endl << endl;
        }
    }
    cout << "This is your list of responses after deleting response #" << pickNum << endl;
    cout << "You can access this in the standard list form on the text file 'alexOut.txt' " << endl;
}
