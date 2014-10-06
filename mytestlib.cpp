
/**
 * @author libearxiong@tencent.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <signal.h>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int add(lua_State* L) 
{
    double op1 = luaL_checknumber(L, 1);
    double op2 = luaL_checknumber(L, 2);
    lua_pushnumber(L, op1 + op2);
    return 1;
}

int sub(lua_State* L)
{
    double op1 = luaL_checknumber(L, 1);
    double op2 = luaL_checknumber(L, 2);
    lua_pushnumber(L, op1 - op2);
    return 1;
}

static const luaL_Reg mylibs[] = { 
    {"add", add},
    {"sub", sub},
    {NULL, NULL} 
};

extern "C" int luaopen_mytestlib(lua_State* L) 
{
    luaL_newlib(L, mylibs);  // lua 5.2 local
    //luaL_register(L, "hello_lib",hello_lib); // lua 5.1 global
    //lua_register(L, "add", add);
    lua_register(L, "add", add);
    return 1;
}
