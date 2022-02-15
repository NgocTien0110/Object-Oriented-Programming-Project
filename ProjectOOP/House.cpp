#include"House.h"
House::House() //Construct of House Class
{
	length = width = 0;
}

//Setter 
void House::setLength(float length) //This Function is used to set Length of House
{
	this->length = length;
}

void House::setWidth(float width) //This Function is used to set Width of House
{
	this->width = width;
}

void House::setWalls(string walls) //This Function is used to set Walls of House
{
	this->walls = walls;
}

void House::setWindows(string windows) //This Function is used to set Windows of House
{
	this->windows = windows;
}

void House::setDoor(string door) //This Function is used to set Door of House
{
	this->door = door;
}

void House::setRoof(string roof) //This Function is used to set Roof of House
{
	this->roof = roof;
}

void House::setGarage(string garage) //This Function is used to set Garage of House
{
	this->garage = garage;
}

ostream& operator<<(ostream& os,const House& hs)	//This Function is used to print house information 
{
	os << "\n\tThe house includes:";
	os << "\n\tLength of house:" << hs.length;
	os << "\n\tWidth of house:" << hs.width;

	if (hs.walls != "")
	{
		os << "\n\tWalls of house:" << hs.walls;
	}

	if (hs.windows != "")
	{
		os << "\n\tWindows of house:" << hs.windows;
	}

	if (hs.door != "")
	{
		os << "\n\tDoor of house:" << hs.door;
	}

	if (hs.roof != "")
	{
		os << "\n\tRoof of house:" << hs.roof;
	}

	if (hs.garage != "")
	{
		os << "\n\tGarage of house:" << hs.garage;
}
	return os;
}

