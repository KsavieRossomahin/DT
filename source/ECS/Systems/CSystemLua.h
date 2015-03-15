#pragma once

#include "ISystem.h"

extern "C"
{
#include "LuaLib/Include/lua.h"
#include "LuaLib/Include/lauxlib.h"
#include "LuaLib/Include/lualib.h"
}

#include "LuaBridge/LuaBridge.h"

class CSystemLua : public ISystem
{
public:
	CSystemLua();
	~CSystemLua();

	virtual void process();
	void call(const string& func);

private:
	static bool _is_registered;
	static lua_State* L;

	static void printMessage(const string& message);
	static void createEntity();
	static void destroyEntity(CEntity* entity);
};