#indef WORDLADDERS_WORD_LADDER_H
#define WORDLADDERS_WORD_LADDER_H


#include <string>
#include <list>
#include <vector> 

struct word{
std::vector<Word *> list;
Word *ptr;
std::string val;


Word()= default;

Word(std::string &val)