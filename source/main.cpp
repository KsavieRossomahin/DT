#include "s3e.h"
#include "IwGx.h"
#include "s3eKeyboard.h"

#include "ECS/Entities/CEntity.h"
#include "ECS/Systems/CSystemRender.h"
#include "ECS/Systems/CSystemPhysics.h"
#include "ECS/Systems/CSystemLua.h"

CSystemRender* render = NULL;
CSystemPhysics* physics = NULL;
CSystemLua* lua = NULL;
vector <CEntity*>* entities = NULL;

s3eCallback keyEventHandler(s3eKeyboardEvent* event)
{
	if(event->m_Pressed)
	{
		//physics->input(event->m_Key);

		if(event->m_Key == s3eKeyR)
		{
			delete lua;
			lua = new CSystemLua;
		}
		else if (event->m_Key == s3eKeyQ)
		{
			lua->call("testFunc");
		}
	}

    return 0;
}

CEntity* createEntity()
{
	CEntity* entity = new CEntity;
	entity->collection()->addComponent <CComponentPosition> ();
	entity->collection()->addComponent <CComponentVelocity> ();
	entity->collection()->addComponent <CComponentSprite> ();
	entities->push_back(entity);

	return entity;
}

int main()
{	
	s3eKeyboardRegister(S3E_KEYBOARD_KEY_EVENT, (s3eCallback) keyEventHandler, NULL);

	IwGxInit();
	IwGxSetColClear(41, 41, 41, 255);

	render = new CSystemRender;
	physics = new CSystemPhysics;
	lua = new CSystemLua;

	entities = new vector <CEntity*>;
	//createEntity();
	lua->init(*entities);
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
		lua->process();

		s3eDeviceYield(0);
	};

	delete render;
	delete physics;
	delete lua;

	for(size_t idx = 0; idx < entities->size(); idx++)
		delete (*entities)[idx];
	delete entities;

	IwGxTerminate();

	s3eKeyboardUnRegister(S3E_KEYBOARD_KEY_EVENT, (s3eCallback) keyEventHandler);

	return 0;
}