Megan Kaye Chua
meganchua@yahoo.com

Purpose: This assignment focuses on the utilization of Tokenization and Parsing with C++. All of the following programs were written in C++.

Prog2_1: Consists of both a driver and header file (.cpp and .hpp). It holds a class called Tokenizer that has four public methods: the constructor, the deconstructor, a void function named Tokenize that takes a single string argument, and lastly a vector<string> function named GetTokens that retrieves a single set of input tokens in a queue fashion. The Tokenize function only recognizes push, pop, add, sub, mul, div, mod, skip, save, get, and any valid integer as valid inputs, anything else results in an "Unexpected token" message being thrown. 

Prog2_2: This is a driver program that takes in a single command line argument that has a file name. This program uses Prog2_1 to tokenize the contents of the file and throw an error message if there are any errors within the file. If there are no tokenization errors, the tokens are printed out to STDOUT each separated by a comma.

Prog2_3: Consists of both a driver and header file (.cpp and .hpp). It holds a class called Parser that has three public methods: the constructor, the deconstructor, and a boolean function named Parse that takes a single vector<string> argument. The strings pop,add,sub,mul,div,mod,skip were to be on their own on a single line. The strings push, save, get were to be on a single line of two tokens where the second token is an integer. Anything not adhering to these rules would result in the Parse function returning false because the input is invalid.

Prog2_4: This is a driver program that takes in a single command line argument that has a file name. This program uses both prog2_1 and prog2_3 in order to Tokenize and Parse the file. First, the file is tokenized and if there is any tokenization error, then an error message would be thrown. Then, if the tokenization was successful it would move onto the Parsing function. If there is a parsing error, then an error message with the line number where the error occured would also be thrown. Any errors will cause the program to stop execution. If there are no errors, the tokens are printed out to STDOUT each separated by a comma.

