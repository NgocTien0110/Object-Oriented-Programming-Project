#pragma once
#include"PublicLibrary.h"

class House
{
private:	
	float length, width;
	string walls, windows;
	string door, roof, garage;
public:
	House();
	void setLength(float length);		
	void setWidth(float width);
	void setWalls(string walls);
	void setWindows(string Windows);
	void setDoor(string door);
	void setRoof(string roof);
	void setGarage(string garage);
	friend ostream& operator<<(ostream& os,const House& hs);
};


