#pragma once
#include"House.h"
#include"PublicLibrary.h"
class Builder //Abstract class
{
public:
	virtual void setLengthToBuild(float length) = 0;
	virtual void setWidthToBuild(float width) = 0;
	virtual void buildWalls(string walls) = 0;
	virtual void buildWindows(string windows) = 0;
	virtual void buildDoor(string door) = 0;
	virtual void buildRoof(string roof) = 0;
	virtual void buildGarage(string garage) = 0;
	virtual House* getResult() = 0;
};

class HouseBuilder : public Builder
{
private:
	House* result; //Composition relation
public:
	HouseBuilder();
	void setLengthToBuild(float length);
	void setWidthToBuild(float width);
	void buildWalls(string walls);
	void buildWindows(string windows);
	void buildDoor(string door);
	void buildRoof(string roof);
	void buildGarage(string garage);
	House* getResult();
	~HouseBuilder();
};

class HouseBluePrint : public Builder
{
private:
	House* result; //Composition relation
public:
	HouseBluePrint();
	void setLengthToBuild(float length);
	void setWidthToBuild(float width);
	void buildWalls(string walls);
	void buildWindows(string windows);
	void buildDoor(string door);
	void buildRoof(string roof);
	void buildGarage(string garage);
	House* getResult();
	~HouseBluePrint();
};