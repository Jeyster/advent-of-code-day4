#ifndef TOOL_H_INCLUDED
#define TOOL_H_INCLUDED

#include <string>
#include <vector>

std::vector<std::string> importInput(std::string fileName);
void displayInput(std::vector<std::string> input);
void displayInput2(std::vector<std::vector<std::string> > input);
std::vector<std::string> stringLineIntoVector(std::string line);
int calculResultPart1(std::vector<std::vector<std::string> > input);
void sortEachWord(std::vector<std::vector<std::string> > &input);

#endif // TOOL_H_INCLUDED
