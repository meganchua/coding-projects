#include <iostream>
#include <vector>
#include "prog2_1.hpp" 
#include <sstream>
#include <string> 
#include <cstddef>


//CONSTRUCTOR:
Tokenizer::Tokenizer()
{
    this->token = new vector<string>();
}

//DESTRUCTOR:
Tokenizer::~Tokenizer()
{
    delete this->token;
}

//TOKENIZER FUNCTION:
void Tokenizer::Tokenize(string str)
{
    stringstream ss(str);
    string input; //buffer input
    bool validtok = false; //to determine whether the token is valid or not
    
    while (getline(ss,input,' '))
    {
        //findfirstnotof used to search if token equals anything but digits
        //string::npos used to search until the end of the size of string
        try
        {
            if (input.find_first_not_of("0123456789")==string::npos)
            {
                validtok = true;
            }
            else if (input=="push"||input=="pop"||input=="add"||
                input=="sub"||input=="mul"||input=="div"||input=="mod"||
                input=="skip"||input=="save"||input=="get")  
            {
             validtok = true;
            }
            else
            {
                validtok = false;
                throw ("Unexpected token: " + input);
            }
          }catch(const char *e)
             {
                cout << "Exception Occurred" << endl << e;
             }
    }
    if (validtok) //saves valid input and pushes it onto the vector
    {
        token->push_back(str);
    }
}

vector<string> Tokenizer::GetTokens()
{
    if(this->token->empty())
    {
        throw ("No tokens");
    }
    else
    {
        return *token;
    }//retrieves string input from the vector, first input in is the first out
}    


    




