global exception
exception = False
		
def isNumber(n): 
	try:
		int(n)
		return True
	except ValueError:
		return False
		
def Tokenize(str):
	validTokens = ['push','pop','add','sub','mul','div','mod','skip','save','get']
	tokens = []
	#checks if the x token is invalid
	invalidTokens = [x for x in str.split() if not (x in validTokens or isNumber(x))]
	if len(invalidTokens) != 0:
		raise ValueError("Unexpected token: " + invalidTokens[0])
	tokens = str.split() #space delimiter
	return tokens
	
def Parse(tokens):
	 singletok = ['pop','add','sub','mul','div','mod','skip']
	 doubletok = ['push','save','get']
	 
	 if tokens[0] in singletok and len(tokens) != 1:
	 	exception = True
	 	raise ValueError("Parse error: " + ' '.join(str(x) for x in tokens))
	 elif tokens[0] in doubletok:
	 	if len(tokens) != 2 or not isNumber(tokens[1]):
	 		raise ValueError("Parse error: " + ' '.join(str(x) for x in tokens))
	 return (True)
        
