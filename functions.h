//Alex Baranoff
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <fstream>
#include <string>
using namespace std;


int readMagicResponses(ifstream &infile, string magicResponse[], const int MAXSIZE);

void playMagic(string magicResponse[], int currentSize);

void printSorted(string magicResponse[], int currentSize);

void writeMagicResponses(ofstream &outfile, string magicResponse[], int currentSize);

void addMagicResponse(string magicResponse[], int &currentSize, const int MAXSIZE);

void deleteMagicResponse(string magicResponse[], int &currentSize);

#endif