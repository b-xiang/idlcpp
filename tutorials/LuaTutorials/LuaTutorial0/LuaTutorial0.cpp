#include <tchar.h>
#include <string>
#include <windows.h>

#include "lua.hpp"
#include "../../../paf/src/paflua/paflua.h"
#include "../../Common/Tutorial0.h"
#include "../../Common/Tutorial0.mh"
#include "../../Common/Tutorial0.ic"
#include "../../Common/Tutorial0.mc"

#if defined(_DEBUG)
#pragma comment(lib,"pafcore_d.lib")
#pragma comment(lib,"paflua_d.lib")
#pragma comment(lib,"lua53_d.lib")
#else
#pragma comment(lib,"pafcore.lib")
#pragma comment(lib,"paflua.lib")
#pragma comment(lib,"lua53.lib")
#endif


void GetExePath(std::string& path)
{
	char fileName[MAX_PATH];
	GetModuleFileName(0, fileName, sizeof(fileName));
	const char* end = _tcsrchr(fileName, '\\');
	path.assign(fileName, end + 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	tmpFlag |= _CRTDBG_LEAK_CHECK_DF;
	_CrtSetDbgFlag(tmpFlag);
	int error;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_paflua(L);
	std::string path;
	GetExePath(path);
	path += "tutorial0.lua";
	error = luaL_loadfile(L, path.c_str()) || lua_pcall(L, 0, 0, 0);
	if (error) 
	{
		fprintf(stderr, "%s\n", lua_tostring(L, -1));
		lua_pop(L, 1);
	}
	lua_close(L);
	return 0;
}

