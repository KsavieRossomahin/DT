#include "CSystemLua.h"

bool CSystemLua::_is_registered = false;
lua_State* CSystemLua::L = NULL;

CSystemLua::CSystemLua()
{
	if (!_is_registered)
	{
		L = luaL_newstate();
		luaL_openlibs(L);

		luabridge::getGlobalNamespace(L)
			.beginNamespace("Engine")
			.addFunction("printMessage", &CSystemLua::printMessage)
			.addFunction("createEntity", &CSystemLua::createEntity)
			.addFunction("destroyEntity", &CSystemLua::destroyEntity)
			.endNamespace();

		luabridge::getGlobalNamespace(L)
			.beginNamespace("Engine")
			.beginClass <CEntity>("CEntity")
			.addFunction("collection", &CEntity::collection)
			.endClass()
			.endNamespace();

		luabridge::getGlobalNamespace(L)
			.beginNamespace("Engine")
			.beginClass <CComponentsCollection> ("CComponentsCollection")
			.addFunction("size", &CComponentsCollection::size)
			.endClass()
			.endNamespace();

		luaL_dofile(L, "script.lua");

		_is_registered = true;
	}
}

CSystemLua::~CSystemLua()
{
	lua_close(L);
	_is_registered = false;
}

void CSystemLua::process()
{
}

void CSystemLua::call(const string& func)
{
	lua_getglobal(L, func.c_str());
	lua_pcall(L, 0, 0, 0);
}

void CSystemLua::printMessage(const string& message)
{
	printf("%s\n", message.c_str());
}

void CSystemLua::createEntity()
{
	_entities->push_back(new CEntity);
}

void CSystemLua::destroyEntity(CEntity* entity)
{
	for(size_t idx = 0; idx < _entities->size(); idx++)
	{
		if(entity == _entities->at(idx))
		{
			delete entity;
			if(idx != _entities->size() - 1)
			{
				_entities->at(idx) = _entities->at(_entities->size());
				_entities->resize(_entities->size() - 1);
			}
		}
	}
}
