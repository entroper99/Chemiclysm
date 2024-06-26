﻿export module Coord;

import std;
import util;

export class Coord
{
private:
	float x = 0;
	float y = 0;
	int gridX = 0;
	int gridY = 0;
	int gridZ = 0;
	float dstX = 0;
	float dstY = 0;
	int dstGridX = 0;
	int dstGridY = 0;
	float fakeX = 0;
	float fakeY = 0;

	int delX = 0;
	int delY = 0;
	int delGridX = 0;
	int delGridY = 0;
public:
	int getX() { return x; }
	int getY() { return y; }
	int getGridX() { return gridX; }
	int getGridY() { return gridY; }
	int getGridZ() { return gridZ; }
	int getDstX() { return dstX; }
	int getDstY() { return dstY; }
	int getDstGridX() { return dstGridX; }
	int getDstGridY() { return dstGridY; }
	int getFakeX() { return fakeX; }
	int getFakeY() { return fakeY; }
	void addFakeX(int val) { fakeX += val; }
	void addFakeY(int val) { fakeY += val; }

	void setGridZ(int val) { gridZ = val; }
	void setFakeX(int val) { fakeX = val; }
	void setFakeY(int val) { fakeY = val; }
	void setXY(int inputX, int inputY)
	{
		x = inputX;
		y = inputY;
		gridX = (x - 8) / 16;
		gridY = (y - 8) / 16;
	}
	virtual void setGrid(int inputX, int inputY, int inputZ)
	{
		gridX = inputX;
		gridY = inputY;
		gridZ = inputZ;
		x = 16 * gridX + 8;
		y = 16 * gridY + 8;
	}

	void addGridX(int input)
	{
		setGrid(getGridX() + input, getGridY(), getGridZ());
	}
	void addGridY(int input)
	{
		setGrid(getGridX(), getGridY() + input, getGridZ());
	}
	void addGridZ(int input)
	{
		setGrid(getGridX(), getGridY(), getGridZ() + input);
	}

	float getFloatFakeX() { return fakeX; }
	float getFloatFakeY() { return fakeY; }
	void setFloatFakeX(float inputVal) { fakeX = inputVal; }
	void setFloatFakeY(float inputVal) { fakeY = inputVal; }

	void setDstGrid(int inputGridX, int inputGridY)
	{
		dstGridX = inputGridX;
		dstGridY = inputGridY;
		dstX = 16 * dstGridX + 8;
		dstY = 16 * dstGridY + 8;
	}

	void setDelGrid(int inputGridX, int inputGridY)
	{
		delGridX = inputGridX;
		delGridY = inputGridY;
		delX = 16 * delGridX;
		delY = 16 * delGridY;
		//prt(L"del값이 (%d,%d)로 설정되었다.\n", delGridX, delGridY);
	}
	int getDelGridX() { return delGridX; }
	int getDelGridY() { return delGridY; }
	int getDelX() { return delX; }
	int getDelY() { return delY; }
};