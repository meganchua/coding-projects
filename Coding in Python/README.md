Megan Kaye Chua

meganchua@yahoo.com

Goal: To practice programming with Python and creating a Stack Machine

Prog4_1: Coded in Python and implement the Tokenize and Parse functions. The tokenize function takes in an input string and tokenizes it based on the rules given to us. We return the list of tokens once the function is over. The Parse function takes in the tokens that were previously tokenized by the Tokenize function. Any input errors will raise a ValueError.

Prog4_2: Coded in Python and implements the StackMachine class. The Execute(tokens) function takes in the input list that was tokenized and parsed, then executes the operation. The CurrentLine property increases by 1 every time the Execute function is executed. Any errors raises an IndexError: "Invalid Memory Access"

Prog4_3: Coded in Python and implements the driver program to run Prog4_1 and Prog4_2. It intakes the first command line argument as a file and then runs through the tokenizer and parsing functions. The lines get stored into an index so we can reach any token by looking for the line number. After tokenization and parsing, the file runs through the StackMachine. When the StackMachine stops running, the program prints "Program terminated correctly". 

