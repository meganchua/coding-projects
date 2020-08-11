#include <iostream>
#include <vector>
#include <sstream>
#include <string> 
#include <cstddef>
#include <fstream>
#include "prog2_1.hpp"

int main (int argc, char** argv)
{
    cout << "Assignment #2-2, Megan Chua, meganchua@yahoo.com" << endl;
    if (argc!=2) //checks if user inputs into command line arguments
    {
        exit(EXIT_FAILURE); //if not, then exit code
    }
    else
    {
        int count = 0; //keeps track of the line the vector is on if error occurs
        try
        {
            string input = argv[1], line; //the file that the user inputs
            Tokenizer t; //declares tokenizer class
            ifstream ifs(input.c_str()); //ifstream = stream class that works with files    
            while(getline(ifs,line)) //goes through the file stream and puts into line
            {
                count++;
                t.Tokenize(line);
            }
            
            vector<string> token = t.GetTokens();

            for(int i=0; i<token.size(); i++) //tokenizes the vector
            {
                stringstream ss(token[i]);
                int num = 0;
                string tok;
                while (getline(ss, tok, ' ')) //space delimiter
                {
                    num++; //number of tokens
                    if(num > 1)
                    {
                        cout << "," << tok; //separates the tokens if more than one token
                    }
                
                    else if (tok.find_first_not_of("0123456789")== string::npos) 
                    {
                        stringstream ss2(tok);
                        int number;
                        ss2 >> number; //extraction on integers
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
        catch (string error)
        {
            cout << "Error on line " << count << ": " << error << endl;
            return 1;
        }

    }
    return 0;
}  
