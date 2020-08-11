#ifndef __prog2_H__
#define __prog2_H__
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Tokenizer
{
    private:
        vector<string> *token;
    public:
        Tokenizer(); //constructor
        ~Tokenizer(); //deconstructor
        void Tokenize(string str); //tokenizer
        vector<string> GetTokens(); //retrieves tokens from vector
};

#endif
