function InfixToPostfix(str)
    str = string.gsub(str, "%s+", "") --string global substitution
    length = string.len(str) --string command to get the length
    str2 = "" --string with tokenization

    for i = 1, length do --tokenizes the string
        tok = string.sub(str,i,i) --takes a token from the string from i=1 to i character
        if(tok == "+" or tok == "-" or tok == "*" or tok == "/" or tok == "%") 
        then
        	str2 = str2.. " ".. tok.. " " 
	    else
    		str2 = str2.. tok
        end
    end

function opOrder(stack,char) --checks order of math operations
    s = 0 --initializes stack and char priority
    c = 0

    if(stack == "%" or stack == "/" or stack == "*") 
    then
        s = 2
    elseif(stack=="+" or stack=="-") 
    then
    	s = 1
    end
    if(char == "%" or char == "/" or char == "*") 
    then
    	c = 2
	elseif(char == "+" or char == "-") 
    then
    	c = 1
	end
    if (s==c and s~=0 and c~=0)
    then
        return 3
    elseif(s<c)
    then
        return 2
    elseif(s>c)
    then
        return 1
    else
        return 0
    end
end

    opStack = {}
    opCount = 0
    poststr = ""

    for n in (str2):gmatch(".") do --goes through string and checks the rules of operands
        if (n == "+" or n == "-" or n == "*" or n == "/" or n == "%") --priority check
        then
            while (opCount ~= 0 and opOrder(opStack[opCount],n)==1 and opStack[1]) do
                poststr = poststr.. table.remove(opStack,opCount).. " " 
        	    opCount = opCount - 1	
            end
            if (opCount ~= 0 and opOrder(opStack[opCount],n)==3) --same character check
            then
                poststr = poststr.. table.remove(opStack,opCount).. " "
                table.insert(opStack,opCount,n)
            elseif (opOrder(opStack[opCount],n)==0)
            then
                print("Error")
                return
            else
                opCount = opCount + 1
        	    table.insert(opStack,n)
            end
        elseif (n == " ")
        then
            poststr = poststr.. " "
        else
            poststr = poststr.. n
        end
    end
    while (opCount~=0) do --takes the rest of the stack characters and puts into output
        if(opStack[opCount] == "(") 
        then
        	print("Error: Missing ( or )" )
        	return
        end
        poststr = poststr .. " ".. table.remove(opStack,opCount)
        opCount = opCount - 1
    end
    print("Assignment #3-2, Megan Chua, meganchua@yahoo.com")
    poststr = string.gsub(poststr, "%s+%s+", " ")
    return(poststr)
end
            
            

            
    












