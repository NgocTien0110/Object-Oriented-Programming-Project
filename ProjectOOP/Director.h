#pragma once
#include"PublicLibrary.h"
#include"Builder.h"

struct HouseUser
{
	Builder* housebuilder;
	Builder* houseblueprint;
};

struct NodeUser
{
	string username;
	vector<HouseUser> houseuser;
	NodeUser* pNext;
	
};

class Director //Control Builder to build House and draw house blueprint
{
private:
	NodeUser* pHead;
	NodeUser* pTail;
	int curN;
public:
	Director();
	void printHouseBuilderOrHouseBluePrint(NodeUser* Cur);
	void clientRequest(NodeUser*& Builder);  //Client will request to Director to build House.
	NodeUser*& operator[](const int& i);
	void MenuUpdateYourHouse(NodeUser*& Builder,int indexofhouse);
	static NodeUser* CreateNode(string username);
	void addTail(string username);
	static void MenuBuildHouseOfUser(string username, Director& dr);
	NodeUser* FindNodeUser(string username);
	Director& updateInfUserFileToDirector();
	void updateDirectortoInfUserFile();
	void removeAccountUser(string username);
	void MenuAdmin();
	~Director();
};

