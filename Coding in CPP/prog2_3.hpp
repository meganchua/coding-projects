#ifndef __prog2_3H__
#define __prog2_3H__

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Parser
{
    private:
        vector<string> *tok;
    public:
        Parser();
        ~Parser();
        bool Parse(vector<string> token);
        int invalidLine;
};

#endif
        
