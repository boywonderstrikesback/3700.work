#include <iostream>
#include <fstream>
#include <queue>
#include "../include/word_ladder.h"


//calling all functions from main.
//uses auto to allow program to define variable as whatever it needs
//this allows file to run due to i may not know what is in file 
WordLadder::WordLadder() {
    read();
    Hamming();
    auto pair=checkInput();
    auto ladder=genLadder(pair.first, pair.second);
    print(ladder);
}


//reads the SGB file. if unable to open error message occurs
void WordLadder::read(){
    std::ifstream inFile;
    std::string fileName="sgb-words.txt";
    inFile.open(fileName);

    if (!inFile){
        std::cerr << "Error: Unable to Open File " << fileName << "!";
        exit(1);
    }
    std::string line;
    while (getline(inFile, line)){
        Word word = Word(line);
        words.emplace_back(word);
    }
    inFile.close();
}


//produces the actual word later by each spot into place by using QUe
//if empty 
/// copys word and modifies each step using pointers
std::list<std::string>WordLadder::genLadder(Word *first, Word *second){
    std::list<std::string>s;
    std::queue<Word *>q;
    q.push(second);
    Word *w;
    second->ptr = second;


//if empty q is moved to front then q pops which pushes wordinto place 
// for when I is equal to zero list size will be what ever it needs to be
//this happens because of the vector 
    while (!q.empty()){
        w = q.front();
        q.pop();
        for (auto i = 0; i < w->list.size(); i++){
            Word *v = w->list.at(i);
            if (v->ptr == nullptr) {
                v->ptr = w;
                q.push(v);
            }
        }
    }
    /// succeeds if pointer is null 
    second->ptr = nullptr;
    if (first->ptr != nullptr){
        s.push_back(first->val);
        w = first->ptr;

        while (w != nullptr){
            s.push_back(w->val);
            w = w->ptr;
        }
    }
    return s;
}

//calculates the distance and returns the distance 
int WordLadder::Distance(std::string x, std::string y){
    int dist = 0;
    for (auto i = 0; i < x.size(); i++){
        if (x[i] != y[i]) {
            dist++;
        }
    }
    return dist;
}
//uses two 4 loops to push the distance using hamming 
void WordLadder::Hamming(){
    for (auto i = 0; i < words.size(); i++){
        for (auto j = i + 1; j < words.size(); j++){
            auto *w1 = &words.at(i);
            auto *w2 = &words.at(j);

            if (Distance(w1->val, w2->val) == 1){
                w1->list.push_back(w2);
                w2->list.push_back(w1);
            }
        }
    }
}



//checks the input of of the word entired
//if a word on the list is entered word will enter vector (false)
// this is done with use of boolean
// if not error occurs that says word is not on list (true)
///if w1 and w2 exist they returned as pair 
std::pair<Word *, Word *> WordLadder::checkInput(){
    std::string w1,w2;
    bool w1Exist = false, w2Exist = false;
    std::cout<< "Input: ";
    std::cin>> w1 >> w2;
    std::pair<Word *,Word *> pair;
    for (Word &word : words){
        if (word.val == w1){
            pair.first= &word;
            w1Exist=true;
        }
        if (word.val == w2){
            pair.second = &word;
            w2Exist=true;
        }
    }
    if (!w1Exist){
        std::cerr << "Word not in list: Consult line 1";
        exit(1);
    } else if (!w2Exist){
        std::cerr << "Error: Word not on list. Consult line 2 ";
        exit(1);
    }
    return pair;
}




/// prints the word ladder if word exist
/// if word doesn't exist funtion prints word doesn't exist 
void WordLadder::print(std::list<std::string>ladder){
    if(ladder.empty()){
        std::cout<<"Does not Exist"<<std::endl;
    }else{
        std::cout<< "Ladder:" <<std::endl;
        for(auto &str:ladder){
            std::cout<<str<<std::endl;
        }
    }
}
