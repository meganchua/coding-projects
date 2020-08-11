#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "prog2_3.hpp"

Parser::Parser() //constructor
{
    invalidLine = -1;
    this->tok = new vector<string>;
}

Parser::~Parser() //deconstructor
{
    delete this->tok;
}

bool Parser::Parse(vector<string> token) //checks if the rules are followed
{
    for (int i=0; i<token.size();i++)
    {
        if(token[i].substr(0,3)=="pop"||token[i].substr(0,3)=="add"||token[i].substr(0,3)=="sub"||token[i].substr(0,3)=="mul"||token[i].substr(0,3)=="div"||token[i].substr(0,3)=="mod")
        {
            if(token[i].length() > 3) //cannot have more than three characters
            {
                invalidLine = i; //puts incorrect line into i
                return false;
            }
        }

        else if(token[i].substr(0,4)=="skip")
        {
            if(token[i].length() > 4) //cannot have more than four characters
            {
                invalidLine = i; //puts incorrect line into i
                return false;
            }
        }

        else if(token[i].substr(0,4)=="push"||token[i].substr(0,4)=="save")
        {
            if(token[i].length() <= 5) //must have 5 characters including the argument
            { //must be 'push <int>' or 'save <int>'
                invalidLine = i; //puts incorrect line into i
                return false;
            }

            if(token[i].substr(5).find_first_not_of("0123456789")!=string::npos)
            {
                invalidLine = i; //puts incorrect line into i
                return false;
            }
        }

        else if(token[i].substr(0,3)=="get")
        {
            if(token[i].length() <= 4)
            {
                invalidLine = i;
                return false;
            }
            
             if(token[i].substr(4).find_first_not_of("0123456789")!=string::npos)
            {
                invalidLine = i; //puts incorrect line into i
                return false;
            }
        }
    }
    return true;
}

