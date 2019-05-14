#ifndef WORDLADDERS_WORD_LADDER_H
#define WORDLADDERS_WORD_LADDER_H

#include <string>
#include <list>
#include <vector>

struct Word{
    std::vector<Word *> list;
    Word *ptr;
    std::string val;

    Word() = default;

    Word(std::string &val) {
        this->ptr = nullptr;
        this->val = val;
    };

    Word(const Word &word){
        this->list = word.list;
        this->ptr = word.ptr;
        this->val = word.val;
    }
};

class WordLadder {
public:
    WordLadder();
    std::list<std::string>genLadder(Word *first, Word *second);

private:
    std::vector<Word> words;
    void read();
    int Distance(std::string x, std::string y);
    void Hamming();
    std::pair<Word *, Word *> checkInput();
    void print(std::list<std::string> ladder);
};
#endif //end line
