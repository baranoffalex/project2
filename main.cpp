#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "functions.h"

using namespace std;

/*NAME: Alex Baranoff
 * CLASS: CSI 1410
 * DESCRIPTION:
 * STATUS:
*/
//global deceleration of variables and function types.


//const int MAXSIZE = 9;

//string magicResponse[MAXSIZE];


int main() {
    cout << "ALEX BARANOFF PROJECT 2" << endl << endl;
    //do-while loop to get input from the user. If user input is not one of the available options (upper case, and lower case) it will loop.
    char fromUser;
    char playAgain = 'y';
    do {
        do {
            cout << "Please enter one of the available options!" << endl << endl;
            cout << "a. Read responses from a file" << endl;
            cout << "b. Play Magic Eight Ball" << endl;
            cout << "c. Print out responses and categories alphabetical" << endl;
            cout << "d. Write response to a file" << endl;
            cout << "e. Add a response to the list of possible responses" << endl;
            cout << "f. Delete a specific response" << endl;
            cout << "g. Exit" << endl;
            cin >> fromUser;
        } while ((fromUser != 'a') && (fromUser != 'A') && (fromUser != 'b') && (fromUser != 'B') &&
                 (fromUser != 'c') && (fromUser != 'C') && (fromUser != 'd') && (fromUser != 'D') &&
                 (fromUser != 'e') && (fromUser != 'E') && (fromUser != 'f') && (fromUser != 'F') &&
                 (fromUser != 'g') && (fromUser != 'G'));

        //if the user selects a or A; Read responses from a file.
        if ((fromUser == 'a') || (fromUser == 'A')) {
            char innn = 'y';
            do {
                ifstream infile;
                infile.open("magicIn.txt");
                const int MAXSIZE = 40;
                string magicResponse[MAXSIZE];
                readMagicResponses(infile, &magicResponse[MAXSIZE], MAXSIZE);
                cout << endl << "If you want to see the responses in a different way, or see them again type 'y'" << endl;
                cout << "Or press any key to exit" << endl;
                cin >> innn;
            }while(innn == 'y');
            cout << endl << "-------------------------------------------------------"<< endl;
            cout << "If you want to try another part of the game type 'y'." << endl;
            cout << "Press any key to quit." << endl;
            cout << "-------------------------------------------------------" << endl;
            cin >> playAgain;
        }
        //if the user selects b or B; Play Magic Eight Ball.
        if (fromUser == 'b' || fromUser == 'B') {
            const int MAXSIZE = 40;
            string magicResponse[MAXSIZE];
            int currentSize = 2 + (2 * rand()) % 40;
            playMagic(magicResponse, currentSize);
            cout << endl << "-------------------------------------------------------"<< endl;
            cout << "If you want to try another part of the game type 'y'." << endl;
            cout << "Press any key to quit." << endl;
            cout << "-------------------------------------------------------" << endl;
            cin >> playAgain;
        }
        //if the user selects c or C; Print out responses and categories alphabetically.
        if (fromUser == 'c' || fromUser == 'C') {
            cout << "Print out responses and categories alphabetically" << endl;
            const int MAXSIZE = 40;
            string magicResponse[MAXSIZE];
            int currentSize = 0;
            printSorted(magicResponse, currentSize);
            cout << endl << "-------------------------------------------------------"<< endl;
            cout << "If you want to try another part of the game type 'y'." << endl;
            cout << "Press any key to quit." << endl;
            cout << "-------------------------------------------------------" << endl;
            cin >> playAgain;
        }
        //if the user selects d or D; Write response to a file.
        if (fromUser == 'd' || fromUser == 'D') {
            ofstream outfile;
            outfile.open("alexOut.txt");
            int currentSize = 40;
            string magicResponse[currentSize];
            writeMagicResponses(outfile, &magicResponse[currentSize], currentSize);
            cout << endl << "-------------------------------------------------------"<< endl;
            cout << "If you want to try another part of the game type 'y'." << endl;
            cout << "Press any key to quit." << endl;
            cout << "-------------------------------------------------------" << endl;
            cin >> playAgain;
        }

        //if the user selects e or E;
        if (fromUser == 'e' || fromUser == 'E') {
            char options = 'y';
            while(options == 'y') {
                const int MAXSIZE = 40;
                int userIn;
                cout << "How many responses do you want to add?" << endl;
                cin >> userIn;
                int currentSize = MAXSIZE + (userIn * 2);
                string magicResponse[currentSize];
                addMagicResponse(magicResponse, currentSize, MAXSIZE);
                cout << endl << "If you want to create a new list type 'y'" << endl;
                cout << "Press any key to exit" << endl;
                cin >> options;
            }
            cout << endl << "-------------------------------------------------------"<< endl;
            cout << "If you want to try another part of the game type 'y'." << endl;
            cout << "Press any key to quit." << endl;
            cout << "-------------------------------------------------------" << endl;
            cin >> playAgain;
        }

        //if the user selects f or F;
        if (fromUser == 'f' || fromUser == 'F') {
            char yesss = 'y';
            do {
                int currentSize = 40;
                string magicResponse[currentSize];
                deleteMagicResponse(magicResponse, currentSize);
                cout << "If you want to delete a different response instead, type 'y'" << endl;
                cout << "Otherwise press any key to exit" << endl;
                cin >> yesss;
            }while(yesss == 'y');
            cout << endl << "-------------------------------------------------------"<< endl;
            cout << "If you want to try another part of the game type 'y'." << endl;
            cout << "Press any key to quit." << endl;
            cout << "-------------------------------------------------------" << endl;
            cin >> playAgain;
        }

        //if the user selects g or G; Exit
        if (fromUser == 'g' || fromUser == 'G') {
            cout << "Are you sure you want to exit?" << endl;
            cout << "Type 'y' to see the menue." << endl;
            cout << "Type any key to quit" << endl;
            cin >> playAgain;
        }
    }while (playAgain == 'y');


    cout << "Thank you for playing the magic eight ball game" << endl;
    cout << "Created by Alex Baranoff" << endl;
    return 0;
}