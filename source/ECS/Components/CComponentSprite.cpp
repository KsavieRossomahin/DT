#include "CComponentSprite.h"

CComponentSprite::CComponentSprite()
{
	SVertex2D* data = new SVertex2D[4];

	data[0]._xy.x = 10;
	data[0]._xy.y = 10;
	data[1]._xy.x = 10;
	data[1]._xy.y = 100;
	data[2]._xy.x = 100;
	data[2]._xy.y = 100;
	data[3]._xy.x = 100;
	data[3]._xy.y = 10;

	int col = rand() % 255;

	for(auto i = 0; i < 4; i++)
	{
		data[i]._col.r = 255;
		data[i]._col.g = col;
		data[i]._col.b = col;
		data[i]._col.a = 0;
	}

	_shared_stream = new CIwGxStream(CIwGxStream::INTERLEAVED_STORAGE, data, sizeof(SVertex2D) * 4, sizeof(SVertex2D));
	_shared_stream->Upload(true, true);
	_xy_stream = new CIwGxStream(*_shared_stream, CIwGxStream::VEC2, 0);
	_col_stream = new CIwGxStream(*_shared_stream, CIwGxStream::COLOUR, 8);
}

CComponentSprite::~CComponentSprite()
{
	_shared_stream->Free();

	delete _shared_stream;
	delete _xy_stream;
	delete _col_stream;
}

CIwGxStream* CComponentSprite::xyStream()
{
	return _xy_stream;
}

CIwGxStream* CComponentSprite::colStream()
{
	return _col_stream;
}