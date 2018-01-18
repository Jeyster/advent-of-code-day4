#include <iostream>
#include "tool.h"

using namespace std;

int main()
{
    /* Import et affichage input sous forme d'un vector de string (1 string par ligne) */
    vector<string> input = importInput("input.txt");
    //displayInput(input);
    //cout << endl << "Input size = " << input.size() << endl << endl;

    /* Modification de l'input en vector (input) de vector (ligne) de string (mot) */
    vector<vector<string> > input2;
    vector<string>::iterator itInput;
    for(itInput = input.begin(); itInput != input.end(); ++itInput)
    {
        vector<string> line = stringLineIntoVector(*itInput);
        input2.push_back(line);
    }

    /* Calcul solution partie 1 */
    int resultPart1(calculResultPart1(input2));
    cout << "Resultat partie 1 : " << resultPart1 << endl;

    /* Calcul solution partie 2 */
    sortEachWord(input2);

    int resultPart2(calculResultPart1(input2));
    cout << "Resultat partie 2 : " << resultPart2 << endl;

}
