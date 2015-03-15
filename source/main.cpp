#include "s3e.h"
#include "IwGx.h"

#include "ECS/Entities/CEntity.h"
#include "ECS/Systems/CSystemRender.h"
#include "ECS/Systems/CSystemPhysics.h"

extern "C"
{
#include "LuaLib/Include/lua.h"
#include "LuaLib/Include/lauxlib.h"
#include "LuaLib/Include/lualib.h"
}

#include "LuaBridge/LuaBridge.h"

CSystemRender* render;
CSystemPhysics* physics;
vector <CEntity*>* entities;
lua_State* L;

s3eCallback keyEventHandler(s3eKeyboardEvent* event)
{
	if(event->m_Pressed)
	{
		//physics->input(event->m_Key);

		lua_getglobal(L, "testFunc");
		lua_pcall(L, 0, 0, 0);
	
	}

    return 0;
}

void printMessage(const string& message)
{
	printf("%s\n", message.c_str());
}

CEntity* createEntity()
{
	CEntity* entity = new CEntity;
	entity->collection()->addComponent(EComponentType::ECT_POSITION);
	entity->collection()->addComponent(EComponentType::ECT_VELOCITY);
	entity->collection()->addComponent(EComponentType::ECT_SPRITE);
	entities->push_back(entity);

	return entity;
}

using namespace luabridge;

int main()
{	
	L = luaL_newstate();
	luaL_openlibs(L);
	
	getGlobalNamespace(L)
		.beginNamespace("Engine")
		.addFunction("printMessage", &printMessage)
		.addFunction("createEntity", &createEntity)
		.beginClass <CEntity> ("CEntity")
			.addFunction("collection", &CEntity::collection)
		.endClass()
		.beginClass <CComponentsCollection> ("CComponentsCollection")
			.addFunction("getComponent", &CComponentsCollection::getComponent)
		.endClass()
		.beginClass <IComponent> ("IComponent")
		.endClass()
		.deriveClass <CComponentPosition, IComponent> ("CComponentPosition")
			.addFunction("posX", &CComponentPosition::posX)
		.endClass()
		.endNamespace();
	
	luaL_dofile(L, "script.lua");


	s3eKeyboardRegister(S3E_KEYBOARD_KEY_EVENT, (s3eCallback) keyEventHandler, NULL);

	IwGxInit();
	IwGxSetColClear(41, 41, 41, 255);

	render = new CSystemRender;
	physics = new CSystemPhysics;

	entities = new vector <CEntity*>;
	render->init(*entities);
	physics->init(*entities);

	uint64 time = s3eTimerGetUTC();
	while(!s3eDeviceCheckQuitRequest())
	{
		uint64 cur_time = s3eTimerGetUTC();
		uint64 dt = cur_time - time;
		if(dt < 0)
			dt = 0;
		time = s3eTimerGetUTC();

		physics->process();
		render->process();

		s3eDeviceYield(0);
	};

	delete render;
	delete physics;
	for(size_t idx = 0; idx < entities->size(); idx++)
		delete (*entities)[idx];
	delete entities;

	IwGxTerminate();

	s3eKeyboardUnRegister(S3E_KEYBOARD_KEY_EVENT, (s3eCallback) keyEventHandler);

	return 0;
}