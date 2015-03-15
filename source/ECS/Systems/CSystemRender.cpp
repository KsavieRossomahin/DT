#include "CSystemRender.h"

void CSystemRender::process()
{
	IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);

	for(size_t idx = 0; idx < _entities->size(); idx++)
	{
		CComponentsCollection* collection = (*_entities)[idx]->collection();
		CComponentSprite* render = static_cast <CComponentSprite*> (collection->getComponent <CComponentSprite> ());
		CComponentPosition* position = static_cast <CComponentPosition*> (collection->getComponent <CComponentPosition> ());
		
		if(!render)
			continue;

		if(position)
		{
			CIwSVec2 pos(static_cast <int16> (position->pos().x), static_cast <int16> (position->pos().y));
			IwGxSetScreenSpaceOrg(&pos);
		}

		CIwMaterial* material = IW_GX_ALLOC_MATERIAL();
		IwGxSetMaterial(material);

		IwGxSetVertStreamScreenSpace(*render->xyStream());
		IwGxSetColStream(*render->colStream());
		IwGxDrawPrims(IW_GX_QUAD_LIST, NULL, 4);
	}

	IwGxFlush();
	IwGxSwapBuffers();
}