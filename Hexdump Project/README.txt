##################################################
# Megan Chua & Ko Takahashi
# cssc0453 & cssc0452
# CS 530, Spring 2019
# Assignment #1, Hexadecimal File Dump Program
# README
##################################################

Partner work:
    Ko and Megan worked on this program together. We both worked on each
    file equally.
    
File Manifest:
    hexdump.c
    hexdump.h
    Makefile
    README.md
    xbd

Compile Instructions:
    To perform a basic hexdump, input "xbd <filename>" into the command line argument. To print the results of the hexdump in binary, input "xbd -b <filename>"
    We will need to compile the hexdump.c file while creating an operator file named "xbd":
        gcc hexdump.c -o xbd
    Once we have created the xbd operator file we can run the whole program:
        ./xbd <filename>
        ./xbd -b <filename>

Operating Instructions:
    Command line arguments: "./xbd <filename>" or "./xbd -b <filename>"
    Required inputs: N/A
    All the information that will be needed to run our program will be in the command line arguments.

Novel/Significant Design Decisions:
    The program is programmed in C.
    For each of our hexdump and binary hexdump, we separated each process into 2 different methods. The main
    method calls on each of these functions.

Extra features/algortihms/functionality included but not required:
    There is a global constant SIZE throughout the code to help denote the size of our buffer.
    Bitwise operation was used during the binary version of the hexdump.

Known deficiencies/bugs: 
    In the output of our binary hexdump, the spacing is off.
    The human readable character section of the output prints random garbage values.
    The make file does not compile. We are still learning how to create a make
    file, but the actual code compiles without the makefile. 

Lessons Learned:
    We learned how to work with command line arguments and executables in C.
    We learned how to use both pointers and bitwise operands to convert to hex and binary.
    We leaerned the purpose of a make file.
    We learned how to deal with input text files in C.
