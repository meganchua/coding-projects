import prog4_1
import prog4_2
import sys 

readFile = sys.argv[1] 
readString = [] 
tokLine = []
parseLine = [] 

print('Assignment #4-3, Megan Chua, meganchua@yahoo.com')

readString = [line.rstrip('\n') for line in open(readFile)] 

for x in readString: 
	tokLine.append(prog4_1.Tokenize(x))
	
for x in tokLine:
	parseLine.append(prog4_1.Parse(x))
	
while prog4_2.CurrentLine <= len(tokLine):
	prog4_2.StackMachine.Execute(tokLine[prog4_2.CurrentLine-1])

print("Program terminated correctly")

