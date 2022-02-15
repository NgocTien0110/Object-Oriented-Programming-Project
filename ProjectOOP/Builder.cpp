#include"Builder.h"

HouseBuilder::HouseBuilder() //initialize variable House pointer
{
	result = new House;
}

//Application of Polymorphism 
void HouseBuilder::setLengthToBuild(float length) //This function is used to set Length of House Builder
{
	result->setLength(length);
}

void HouseBuilder::setWidthToBuild(float width) //This function is used to set Width of House Builder
{
	result->setWidth(width);
}

void HouseBuilder::buildWalls(string walls) //This function is used to build Walls of House Builder
{
	result->setWalls(walls);
}

void HouseBuilder::buildWindows(string windows) //This function is used to build Windows of House Builder
{
	result->setWindows(windows);
}

void HouseBuilder::buildDoor(string door)  //This function is used to build Door of House Builder
{
	result->setDoor(door);
}

void HouseBuilder::buildRoof(string roof)  //This function is used to build Roof of House Builder
{
	result->setRoof(roof);
}

void HouseBuilder::buildGarage(string garage)  //This function is used to build Garage of House Builder
{
	result->setGarage(garage);
}

House* HouseBuilder::getResult() //Return variable House pointer
{
	return result;
}

HouseBuilder::~HouseBuilder() //Destructor of HouseBuilder
{
	if (result != nullptr)
	{
		delete result;
	}
}


HouseBluePrint::HouseBluePrint() //initialize variable House pointer
{
	result = new House;
}


//Application of Polymorphism 
void HouseBluePrint::setLengthToBuild(float length)  //This function is used to set Length of House BluePrint
{
	result->setLength(length);
}

void HouseBluePrint::setWidthToBuild(float width) //This function is used to set Width of House BluePrint
{
	result->setWidth(width);
}

void HouseBluePrint::buildWalls(string walls) //This function is used to build Walls of House BluePrint
{
	result->setWalls(walls);
}

void HouseBluePrint::buildWindows(string windows) //This function is used to build Windows of House BluePrint
{
	result->setWindows(windows);
}

void HouseBluePrint::buildDoor(string door) //This function is used to build Door of House BluePrint
{
	result->setDoor(door);
}

void HouseBluePrint::buildRoof(string roof) //This function is used to build Roof of House BluePrint
{
	result->setRoof(roof);
}

void HouseBluePrint::buildGarage(string garage) //This function is used to build Garage of House BluePrint
{
	result->setGarage(garage);
}

House* HouseBluePrint::getResult() //Return variable House pointer
{
	return result;
}

HouseBluePrint::~HouseBluePrint() //Desturctor of HouseBluePrint class
{
	if (result != nullptr)
	{
		delete result;
	}
}
