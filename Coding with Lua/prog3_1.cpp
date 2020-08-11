#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

extern "C" //since Lua is compiled as C code, we tell the compiler the variable is here
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

int main (int argc, char* argv[])
{
    printf("Assignment #3-1, Megan Chua, meganchua@yahoo.com\n");
    lua_State *state = luaL_newstate();
    luaL_openlibs(state);

    if (argc == 2) //checks if there is a single command line argument
    {
        string file = argv[1];
        size_t isLua = file.find(".lua"); //find lua file
        if (isLua != string::npos)  //if the file is found, open and run through contents
        {
            luaL_dofile(state,argv[1]);
        }
    } 

    lua_close(state); //close the lua environment
}
