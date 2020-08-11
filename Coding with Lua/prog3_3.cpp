#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstdlib>
#include "lua.hpp"

using namespace std;

extern "C" //since Lua is compiled as C code, we tell the compiler the variable is here
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

int main (int argc, char* argv[])
{
    printf("Assignment #3-3, Megan Chua, meganchua@yahoo.com\n");
    lua_State *state = luaL_newstate();
	luaL_openlibs(state);
	luaL_dofile(state,argv[1]);

    string buff = "return InfixToPostfix(\"";
    string stdIn;
    
    getline(cin,stdIn);
    buff+=stdIn;
	string end = "\")";
	buff+=end;

    char run[256];
	strcpy(run,buff.c_str());
	luaL_dostring(state,run); //runs the InfixToPostFix function
	cout << luaL_checkstring(state,1) << endl; //prints out the postfix string
	lua_close(state);
	return 0; //end
}
