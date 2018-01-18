#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "tool.h"

using namespace std;

vector<string> importInput(string fileName)
{
    ifstream myStream(fileName);
    if(!myStream)
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        exit(0);
    }

    string line;
    vector<string> wordsList;
    while(getline(myStream, line))
    {
        wordsList.push_back(line);
    }

    return wordsList;
}


void displayInput(vector<string> input)
{
    vector<string>::iterator itInput;
    for(itInput = input.begin(); itInput != input.end(); ++itInput)
    {
        cout << *itInput << endl << endl ;
    }
}

void displayInput2(vector<vector<string> > input)
{
    vector<vector<string> >::iterator itInput;
    vector<string>::iterator itLine;
    for(itInput = input.begin(); itInput != input.end(); ++itInput)
    {
        for(itLine = itInput->begin(); itLine != itInput->end(); ++itLine)
        {
            cout << *itLine << " ";
        }
        cout << endl;
    }
}


vector<string> stringLineIntoVector(string line)
{
    istringstream stream(line);
    vector<string> wordVector;
    string word;
    while(stream >> word)
    {
        wordVector.push_back(word);
    }

    return wordVector;
}

int calculResultPart1(vector<vector<string> > input)
{
    int notValidPhrases(0);
    bool isValid(true);

    vector<vector<string> >::iterator itInput;
    vector<string>::iterator itLine;
    vector<string>::iterator itLine2;
    for(itInput = input.begin(); itInput != input.end(); ++itInput)
    {
        isValid = true;
        for(itLine = itInput->begin(); itLine != itInput->end(); ++itLine)
        {
            if(!isValid) break;
            for(itLine2 = itInput->begin(); itLine2 != itInput->end(); ++itLine2)
            {
                if((*itLine == *itLine2) && (itLine != itLine2))
                {
                    ++notValidPhrases;
                    isValid = false;
                    break;
                }
            }
        }
    }
    return input.size() - notValidPhrases;
}


void sortEachWord(vector<vector<string> > &input)
{
    vector<vector<string> >::iterator itInput;
    vector<string>::iterator itLine;
    vector<string>::iterator itLine2;

    for(itInput = input.begin(); itInput != input.end(); ++itInput)
    {
        for(itLine = itInput->begin(); itLine != itInput->end(); ++itLine)
        {
            sort(itLine->begin(), itLine->end());
        }
    }
}

