#include "CSystemPhysics.h"

void CSystemPhysics::process()
{
	for(size_t idx = 0; idx < _entities->size(); idx++)
	{
		CComponentsCollection* collection = (*_entities)[idx]->collection();
		CComponentPosition* position = static_cast <CComponentPosition*> (collection->getComponent <CComponentPosition> ());
		CComponentVelocity* velocity = static_cast <CComponentVelocity*> (collection->getComponent <CComponentVelocity> ());

		if(!position)
			continue;

		if(velocity)
		{
			float val = velocity->speed();
			if(val > 0.0f)
			{
				val -= 0.01f;
				if(val < 0.0f)
					val = 0.0f;
				velocity->setSpeed(val);
			}

			if(val > 0)
			{
				CIwFVec2 dir = velocity->dir();
				CIwFVec2 dpos = dir * val;
				position->setPos(position->pos() + dpos);
			}
		}
	}
}

void CSystemPhysics::input(s3eKey key)
{
	CComponentVelocity* velocity = static_cast <CComponentVelocity*> ((*_entities)[0]->collection()->getComponent <CComponentVelocity> ());
	
	if(velocity)
	{
		CIwFVec2 dir = CIwFVec2::g_Zero;

		switch(key)
		{
		case s3eKeyW:
			dir.y -= 5.0f;
			break;
		case s3eKeyA:
			dir.x -= 5.0f;
			break;
		case s3eKeyS:
			dir.y += 5.0f;
			break;
		case s3eKeyD:
			dir.x += 5.0f;
			break;

		default:
			break;
		}

		velocity->setDir(dir);
		velocity->setSpeed(1.0f);
	}
}