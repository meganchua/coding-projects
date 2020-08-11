#include <iostream>
#include <vector>
#include <sstream>
#include <string> 
#include <cstddef>
#include <fstream>
#include "prog2_1.hpp"
#include "prog2_3.hpp"

int main (int argc, char** argv)
{
    cout << "Assignment #2-4, Megan Chua, meganchua@yahoo.com" << endl;
    if (argc!=2) //checks if user inputs into command line arguments
    {
        exit(EXIT_FAILURE); //if not, then exit code
    }

    else
    {
        int count = 0; //keeps track of the line the vector is on if error occurs
        vector<string> token;
        Tokenizer t; //calls tokenizer function
        Parser p; //calls parser function
        bool validp = false; //checks whether we can move on to parsing
        string input = argv[1], line; //the file that the user inputs

        //Checking for valid tokenization:

        try
        {
            ifstream ifs(input.c_str()); //ifstream = stream class that works with files    
            while(getline(ifs,line)) //goes through the file stream and puts into line
            {
                count++; //move through each line
                t.Tokenize(line); //tokenize each line
            }
            token = t.GetTokens(); 
            validp = true; //move onto parsing if there are no tokenization errors

        }
        catch (string error)
        {
            cout << "Error on line " << count << ": " << error << endl;
            validp = false;
        }
        
        //Checking for valid Parsing:
        
        if(validp)
        {
            if(p.Parse(token)) //if there are no parsing errors
            {
                for(int i=0; i<token.size(); i++) //tokenizes the vector
                {
                    stringstream ss(token[i]);
                    int num = 0;
                    string tok;
                    while (getline(ss, tok, ' ')) //tokenizes on spaces
                    {
                        num++; //number of tokens
                        if(num > 1)
                        {
                            cout << "," << tok; //separates the tokens if more than one
                        }
                
                        else if (tok.find_first_not_of("0123456789")== string::npos) 
                        {
                            stringstream ss2(tok);
                            int number;
                            ss2 >> number;
                            cout << "," << number;
                        }

                        else
                        {
                            cout << tok;
                        }
                    }
                    cout << endl;
                }
                
            }
            
            else
            {
                cout << "Parse error on line " << p.invalidLine+1 << ":" << token[p.invalidLine] << endl;
            }
        }

    }
    return 0;
}

