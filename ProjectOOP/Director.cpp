#include"Director.h"
#include"GRAPHIC.h"

void ShowInformation(Builder* Builder) //Application of polymorphism to output house information of House builder class or House Blueprint class
{
	cout << *Builder->getResult();
}

Director::Director()  //Constructor of Director
{
	this->pHead = nullptr;
	this->pTail = nullptr;
	this->curN = 0;
}

void Director::printHouseBuilderOrHouseBluePrint(NodeUser* Cur)  //This function is used to print house information of User
{
	int choice;		//Variable is used to select menu functions below.
	int indexofhouse; 
	do
	{
		system("CLS");
		DrawFrame(86, 22);
		gotoxy(2, 2);

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);
		cout << "\t\t\t\tMenu House Information";

		SetConsoleTextAttribute(h, 11);
		cout << "\n\t1. House Builder.";
		cout << "\n\t2. House Blue Print.";
		cout << "\n\t3. Back to menu";
		cout << "\n\tEnter your choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1: //Output House builder information
			cout << "\tYou have " << Cur->houseuser.size()	<< " houses";
			cout << "\n\tWhat is a house you want to see. Please input number:";

			cin >> indexofhouse;

			indexofhouse -= 1;

			cout << "\n\tThis is a house " << indexofhouse +1 <<" we have built: ";
			ShowInformation(Cur->houseuser[indexofhouse].housebuilder);
			cout << "\n\t";
			system("pause");
			break;
		case 2: //Output House Blue Print information
			cout << "\tYou have " << Cur->houseuser.size() << " house blueprints";
			cout << "\n\tWhat is a house you want to see. Please input number:";

			cin >> indexofhouse;

			indexofhouse -= 1;
				
			cout << "\n\tThis is a house blueprint of house " << indexofhouse + 1  << " :";
			ShowInformation(Cur->houseuser[indexofhouse].houseblueprint);
			cout << "\n\t";
			system("pause");
		}
	} while (choice != 3); //Exit loop

}

void Director::clientRequest(NodeUser*& Cur)  //Client will request to Director to build House.
{
	HouseBuilder* housebuilder = new HouseBuilder();
	HouseBluePrint* houseblueprint = new HouseBluePrint();

	int choice; //Variable is used to select menu functions below.
	float x; //x variable is used to input length or width of house
	string temp, input;  //temp variable is used to input elements like walls, windows.

	do
	{
		system("CLS");

		DrawFrame(86, 26);

		gotoxy(2, 2);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);
		cout << "\t\t\t\tMENU IDEA BUILD HOUSE";

		SetConsoleTextAttribute(h, 11);
		cout << "\n\t1. Enter Length of house.";
		cout << "\n\t2. Enter Width of house.";
		cout << "\n\t3. Enter Walls information of house.";
		cout << "\n\t4. Enter Windows information of house.";
		cout << "\n\t5. Enter Door information of house.";
		cout << "\n\t6. Enter Roof information of house.";
		cout << "\n\t7. Enter Garage information of house.";
		cout << "\n\t8. Check house building plan information";
		cout << "\n\t9. Back to menu";
		cout << "\n\tEnter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1: //Input Length of House
			do
			{
				cout << "\tEnter Length (Length > 0) of house:";
				cin >> x;
			} while (x < 0);

			housebuilder->setLengthToBuild(x);
			houseblueprint->setLengthToBuild(x);
			break;
		case 2: //Input Width of House
			do
			{
				cout << "\tEnter Width (Width >0) of house:";
				cin >> x;
			} while (x < 0);

			housebuilder->setWidthToBuild(x);
			houseblueprint->setWidthToBuild(x);
			break;
		case 3: //Input Walls of House
			cout << "\tEnter quantity of Walls:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Walls and Material is ";

			cout << "\tEnter material Walls of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildWalls(input);
			houseblueprint->buildWalls(input);
			break;
		case 4: //Input Windows of House
			cout << "\tEnter quantity of Windows:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Windows and Material is ";

			cout << "\tEnter material Windows of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildWindows(input);
			houseblueprint->buildWindows(input);
			break;
		case 5: //Input Door of House
			cout << "\tEnter quantity of Doors:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Doors and Material is ";

			cout << "\tEnter material Door of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildDoor(input);
			houseblueprint->buildDoor(input);
			break; 
		case 6: //Input Roof of House
			cout << "\tEnter quantity of Roofs:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Roofs and Material is ";

			cout << "\tEnter material Roofs of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildRoof(input);
			houseblueprint->buildRoof(input);
			break;
		case 7: //Input Garage of House
			cout << "\tEnter quantity of Garages:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Garages and Material is ";

			cout << "\tEnter material Garage of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildGarage(input);
			houseblueprint->buildGarage(input);
			break;
		case 8: //Check house building plan inf
			cout << "\n\tThis is a house building plan information: ";
			ShowInformation(houseblueprint);
			cout << endl;
			cout << "\n\t";
			system("pause");
			break;
		}
	} while (choice != 9);

	HouseUser TEMP;
	TEMP.housebuilder = (Builder*)housebuilder;
	TEMP.houseblueprint = (Builder*)houseblueprint;
	Cur->houseuser.push_back(TEMP);
}


NodeUser*& Director::operator[](const int& i) //This function is used to return NodeUser of position i
{
	int pos = i;

	if (pos < 0 || pos == 0)
		return pHead;
	else if (pos == curN - 1 || pos > curN - 1)
		return pTail;
	else
	{
		NodeUser* Cur = pHead;

		while (pos != 0)
		{
			Cur = Cur->pNext;
			pos--;
		}
		return Cur;
	}
}

void Director::MenuUpdateYourHouse(NodeUser*& Cur,int indexofhouse)
{
	HouseBuilder* housebuilder = new HouseBuilder();
	HouseBluePrint* houseblueprint = new HouseBluePrint();

	housebuilder = (HouseBuilder*)Cur->houseuser[indexofhouse].housebuilder; //Assign housebuilder
	houseblueprint = (HouseBluePrint*)Cur->houseuser[indexofhouse].houseblueprint; //Assign houseblueprint
	int choice;  //Variable is used to select menu functions below.
	float x; //x variable is used to input length or width of house
	string temp, input;  //temp variable is used to input elements like walls, windows.

	do
	{

		system("CLS");

		DrawFrame(86, 26);

		gotoxy(2, 2);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);

		cout << "\t\t\t\tMENU UPDATE YOUR HOUSE";

		SetConsoleTextAttribute(h, 11);
		cout << "\n\t1. Update Length of house.";
		cout << "\n\t2. Update Width of house.";
		cout << "\n\t3. Update Walls information of house.";
		cout << "\n\t4. Update Windows information of house.";
		cout << "\n\t5. Update Door information of house.";
		cout << "\n\t6. Update Roof information of house.";
		cout << "\n\t7. Update Garage information of house.";
		cout << "\n\t8. Check your house after update.";
		cout << "\n\t9. Back to menu";
		cout << "\n\tEnter your choice:";

		cin >> choice;

		switch (choice)
		{
		case 1: //Update Length of House
			do
			{
				cout << "\tEnter Length (Length > 0) of house:";
				cin >> x;
			} while (x < 0);

			housebuilder->setLengthToBuild(x);
			houseblueprint->setLengthToBuild(x);
			break;
		case 2: //Update Width of House
			do
			{
				cout << "\tEnter Width (Width >0) of house:";
				cin >> x;
			} while (x < 0);

			housebuilder->setWidthToBuild(x);
			houseblueprint->setWidthToBuild(x);
			break;
		case 3: //Update Walls of House
			cout << "\tEnter quantity of Walls:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Walls and Material is ";

			cout << "\tEnter material Walls of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildWalls(input);
			houseblueprint->buildWalls(input);
			break;
		case 4: //Update Windows of House
			cout << "\tEnter quantity of Windows:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Windows and Material is ";

			cout << "\tEnter material Windows of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildWindows(input);
			houseblueprint->buildWindows(input);
			break;
		case 5: //Update Door of House
			cout << "\tEnter quantity of Doors:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Doors and Material is ";

			cout << "\tEnter material Door of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildDoor(input);
			houseblueprint->buildDoor(input);
			break;
		case 6: //Update Roof of House
			cout << "\tEnter quantity of Roofs:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Roofs and Material is ";

			cout << "\tEnter material Roofs of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildRoof(input);
			houseblueprint->buildRoof(input);
			break;
		case 7: //Update Garage of House
			cout << "\tEnter quantity of Garages:";
			cin.ignore();
			getline(cin, temp);

			input = temp;
			input = input + " Garages and Material is ";

			cout << "\tEnter material Garage of house:";
			getline(cin, temp);

			input = input + temp;
			housebuilder->buildGarage(input);
			houseblueprint->buildGarage(input);
			break;
		case 8: //Check house building plan information
			cout << "\n\tThis is a house building plan information: ";
			ShowInformation(houseblueprint);
			cout << "\n\t";
			system("pause");
			break;
		}
	} while (choice != 9); //Exit loop

	Cur->houseuser[indexofhouse].housebuilder = (Builder*)housebuilder;   //Assign housebuilder
	Cur->houseuser[indexofhouse].houseblueprint = (Builder*)houseblueprint; //Assign houseblueprint
}

NodeUser* Director::CreateNode(string username) //This function is used to create NodeUser
{
	NodeUser* p = new NodeUser;
	p->username = username;
	p->pNext = nullptr;
	return p;
}

void Director::addTail(string username) //This function is used to add pTail
{
	if (pHead == nullptr)
	{
		NodeUser* p = CreateNode(username);
		pHead = pTail = p;
	}

	else
	{
		NodeUser* p = CreateNode(username);
		pTail->pNext = p;
		pTail = pTail->pNext;
	}

	this->curN++;
}

void OutputVipUser(NodeUser* Cur) //This function is used print VIP text
{
	if (Cur->houseuser.size() > 0 && Cur->houseuser.size() <= 1)
	{
		cout << "VIP 1";
	}
	else if (Cur->houseuser.size() > 1 && Cur->houseuser.size() <= 4)
	{
		cout << "VIP 2";
	}
	else
	{
		cout << "VIP 3";
	}
}

void Director::MenuBuildHouseOfUser(string username, Director& dr)
{
	int i = 0; //Variable will help func OutputVipUser
	int choice;  //Variable is used to select menu functions below.
	bool CheckUserExist = false; //Variable is used to check if User is Exist in system
	NodeUser* Cur = nullptr;
	int indexofhouse; //Index of House

	Cur = dr.FindNodeUser(username); //Find Node User
	
	if (Cur != nullptr) //If NodeUser was Exist
	{
		CheckUserExist = true;
	}

	if (CheckUserExist == false) //If NodeUser is not Exist
	{
		dr.addTail(username);
	}

	do
	{
		system("CLS");

		DrawFrame(86, 22);

		gotoxy(70, 20);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);

		if (CheckUserExist == true) //If User was Exist
		{
			OutputVipUser(Cur);
		}
		else //If User isnot Exist
		{
			if (i > 0 && i <= 1)
				cout << "VIP 1";
			else if (i > 1 && i <= 4)
				cout << "VIP 2";
			else if (i > 4)
				cout << "VIP 3";
		}

		gotoxy(2, 2);
		SetConsoleTextAttribute(h, 14);
		cout << "\t\t\t\tMenu Build House";

		SetConsoleTextAttribute(h,11);
		cout << "\n\t1. House building plan.";
		cout << "\n\t2. House information after build.";
		cout << "\n\t3. Update your house.";
		cout << "\n\t4. Exit.";
		cout << "\n\tEnter your choice:";
		cin >> choice;

		switch (choice)
		{
		case 1: //Client request to build house.

			if (CheckUserExist == false) //If User was Exist
			{
				dr.clientRequest(dr.pTail);
				dr.updateDirectortoInfUserFile();

				i++;
			}
			else  //If User is not Exist
			{
				dr.clientRequest(Cur);
				dr.updateDirectortoInfUserFile();
			}
			break;
		case 2: //Output house builder information or house blueprint information

			if (Cur != nullptr)  //If User was Exist 
			{
				dr.printHouseBuilderOrHouseBluePrint(Cur);
			}
			else if (dr.pTail != nullptr) //If User is not Exist
			{
				dr.printHouseBuilderOrHouseBluePrint(dr.pTail);
			}
			break;
		case 3: //Update attribute of House

			if (Cur != nullptr)  //If User was Exist 
			{
				cout << "\tYou have " << Cur->houseuser.size() << " houses";
				cout << "\n\tWhat is a house you want to update. Please input number:";

				cin >> indexofhouse;

				indexofhouse -= 1;

				dr.MenuUpdateYourHouse(Cur, indexofhouse);
			}
			else if (dr.pTail != nullptr)  //If User is not Exist
			{
				cout << "\tYou have " << dr.pTail->houseuser.size() << " houses";
				cout << "\n\tWhat is a house you want to update. Please input number:";

				cin >> indexofhouse;

				indexofhouse -= 1;

				dr.MenuUpdateYourHouse(dr.pTail, indexofhouse);
			}
			break;
		case 4: //Update House Information User File
			dr.updateDirectortoInfUserFile();
			break;
		}
	} while (choice != 4);

}

NodeUser* Director::FindNodeUser(string username) //This function is used to find Node User
{
	if (this->pHead == nullptr)
		return nullptr;
	else
	{
		NodeUser* Cur = this->pHead;

		while (Cur)
		{
			if (Cur->username == username)
				return Cur;
			Cur = Cur->pNext;
		}
		return nullptr;
	}
}

Director& Director::updateInfUserFileToDirector()  //This function is used to Update House Information User File To Director
{
	string line, temp;
	HouseUser TEMP;
	ifstream fin;
	fin.open("DataUser.txt"); //Open file

	while (true)
	{
		getline(fin, line);

		if (strcmp(line.c_str(), "\0") == 0) //Check if line string == "\0" then exit loop
		{
			break;
		}

		this->addTail(line); //add node pTail
		HouseBuilder* housebuilder = new HouseBuilder;
		HouseBluePrint* houseblueprint = new HouseBluePrint;
		getline(fin, line); //ignore line "/"
		getline(fin, line); //ignore line "The house includes:"

		while (true)
		{
			if (housebuilder == nullptr) //If House Builder is nullptr then allocate it
			{
				housebuilder = new HouseBuilder;
			}

			if (houseblueprint == nullptr) //If House Blueprint is nullptr then allocate it
			{
				houseblueprint = new HouseBluePrint;
			}

			getline(fin, line);

			if (strcmp(line.c_str(), "/") == 0) //Check if line string == "/" then exit loop and push HouseBuilder and HouseBluePrint to HouseUser
			{
				HouseUser TEMP;

				HouseBuilder* housebuildertemp = new HouseBuilder;
				HouseBluePrint* houseblueprinttemp = new HouseBluePrint;

				*housebuildertemp = *housebuilder;
				*houseblueprinttemp = *houseblueprint;

				TEMP.housebuilder = (Builder*)housebuildertemp;
				TEMP.houseblueprint = (Builder*)houseblueprinttemp;

				this->pTail->houseuser.push_back(TEMP);

				housebuilder = nullptr;
				houseblueprint = nullptr;
				break;
			}
			else
			{
				stringstream ss(line);
				getline(ss, temp, ':'); //Get temp string befor char ':' of line string
				if (strcmp(temp.c_str(), "\tLength of house") == 0)
				{
					getline(ss, temp);
					housebuilder->setLengthToBuild(stof(temp));
					houseblueprint->setLengthToBuild(stof(temp));
				}
				else if (strcmp(temp.c_str(), "\tWidth of house") == 0)
				{
					getline(ss, temp);
					housebuilder->setWidthToBuild(stof(temp));
					houseblueprint->setWidthToBuild(stof(temp));
				}
				else if (strcmp(temp.c_str(), "\tWalls of house") == 0)
				{
					getline(ss, temp);
					housebuilder->buildWalls(temp);
					houseblueprint->buildWalls(temp);
				}
				else if (strcmp(temp.c_str(), "\tWindows of house") == 0)
				{
					getline(ss, temp);
					housebuilder->buildWindows(temp);
					houseblueprint->buildWindows(temp);
				}
				else if (strcmp(temp.c_str(), "\tDoor of house") == 0)
				{
					getline(ss, temp);
					housebuilder->buildDoor(temp);
					houseblueprint->buildDoor(temp);
				}
				else if (strcmp(temp.c_str(), "\tRoof of house") == 0)
				{
					getline(ss, temp);
					housebuilder->buildRoof(temp);
					houseblueprint->buildRoof(temp);
				}
				else if (strcmp(temp.c_str(), "\tGarage of house") == 0)
				{
					getline(ss, temp);
					housebuilder->buildGarage(temp);
					houseblueprint->buildGarage(temp);
				}
				else if (strcmp(temp.c_str(), "\tThe house includes") == 0) //Check and push HouseBuilder and HouseBluePrint to HouseUser
				{
					HouseUser TEMP;

					HouseBuilder* housebuildertemp = new HouseBuilder;
					HouseBluePrint* houseblueprinttemp = new HouseBluePrint;

					*housebuildertemp = *housebuilder;
					*houseblueprinttemp = *houseblueprint;

					TEMP.housebuilder = (Builder*)housebuildertemp;
					TEMP.houseblueprint = (Builder*)houseblueprinttemp;

					this->pTail->houseuser.push_back(TEMP);

					housebuilder = nullptr;
					houseblueprint = nullptr;
				}
			}
		}
	}

	fin.close(); //Close file
	return *this;
}

void Director::updateDirectortoInfUserFile()  //This function is used to Update Director to House Information User File
{
	ofstream fout;
	fout.open("DataUser.txt");

	if (this->pHead == nullptr)
		return;
	else
	{
		NodeUser* Cur = pHead;

		while (Cur)
		{
			fout << Cur->username; //print username
			fout << "\n/";  //print "/"
			for (int i = 0; i < Cur->houseuser.size(); i++)
			{
				fout << *Cur->houseuser[i].housebuilder->getResult(); //Print the attribute of house class
			}
			fout << "\n/";  //print "/"
			fout << endl;
			Cur = Cur->pNext;
		}

		delete Cur;
	}

	fout.close(); //Close File
}

void removeLineInFileAccountUser(string username)	//This function is used to remove username and password in AccountUser File
{
	ifstream fin; 
	ofstream fout;  

	fin.open("AccountUser.txt");   //Open file
	fout.open("temp.txt");		   //Open file

	string line, temp;

	while (!fin.eof())
	{
		getline(fin, line);
		stringstream ss(line);
		getline(ss, temp, ',');

		if (temp != username)
		{
			fout << line << endl;
		}
	}

	fout.close(); //Close file
	fin.close(); //Close file

	remove("AccountUser.txt");
	rename("temp.txt", "AccountUser.txt");
}

void Director::removeAccountUser(string username) //This function is used to Remove AccountUser (NodeUser)
{
	NodeUser* Cur;
	if (this->pHead == nullptr)
		return;

	if (this->pHead->username == username) //If pHead is NodeUser which need to remove
	{
		Cur = this->pHead;
		this->pHead = this->pHead->pNext;

		for (int i = 0; i < Cur->houseuser.size(); i++)
		{
			if (Cur->houseuser[i].houseblueprint != nullptr)
				delete Cur->houseuser[i].houseblueprint;
			if (Cur->houseuser[i].housebuilder != nullptr)
				delete Cur->houseuser[i].housebuilder;
		}

		delete Cur;

		removeLineInFileAccountUser(username);

		this->updateDirectortoInfUserFile();
	}
	else if (this->pTail->username == username)  //If pTail is NodeUser which need to remove
	{
		Cur = this->pHead;

		while (Cur->pNext->pNext != nullptr)
		{
			Cur = Cur->pNext;
		}

		NodeUser* temp = this->pTail;
		this->pTail = Cur;
		this->pTail->pNext = nullptr;

		for (int i = 0; i < temp->houseuser.size(); i++)
		{
			if (temp->houseuser[i].houseblueprint != nullptr)
				delete temp->houseuser[i].houseblueprint;
			if (temp->houseuser[i].housebuilder != nullptr)
				delete temp->houseuser[i].housebuilder;
		}

		delete temp;

		removeLineInFileAccountUser(username);

		this->updateDirectortoInfUserFile();
	}
	else
	{
		Cur = this->pHead;

		while (Cur->pNext)
		{
			if (Cur->pNext->username == username)
			{
				NodeUser* temp = Cur->pNext;
				Cur->pNext = Cur->pNext->pNext;

				for (int i = 0; i < temp->houseuser.size(); i++)
				{
					if (temp->houseuser[i].houseblueprint != nullptr)
						delete temp->houseuser[i].houseblueprint;
					if (temp->houseuser[i].housebuilder != nullptr)
						delete temp->houseuser[i].housebuilder;
				}

				delete temp;

				removeLineInFileAccountUser(username);

				this->updateDirectortoInfUserFile();
			}
			else
			{
				Cur = Cur->pNext;
			}
		}
	}
}

void Director::MenuAdmin()
{
	int choice; //Variable is used to select menu functions below.
	int indexofuser,indexofhouse;
	string username, password;
	bool checkregister;
	ofstream fout;

	do
	{
		system("CLS");

		indexofuser = 1;
		NodeUser* Cur = this->pHead;

		DrawFrame(86, 22);

		gotoxy(2, 2);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);
		cout << "\t\t\t\tMenu Admin";

		SetConsoleTextAttribute(h, 11);
		cout << "\n\t1.Show all users";
		cout << "\n\t2.Search information users";
		cout << "\n\t3.Add new user";
		cout << "\n\t4.Remove user";
		cout << "\n\t5.Exit.";
		cout << "\n\tInput your choice:";

		cin >> choice;

		switch (choice)
		{
		case 1: //Show all usernames
			system("CLS");
			DrawFrame(86, 22);

			gotoxy(2, 2);
			SetConsoleTextAttribute(h, 14);
			cout << "\t\t\t\tAll User Name\n";

			SetConsoleTextAttribute(h, 11);

			while (Cur) //Loop to print all usernames
			{
				cout << "\tUsername " << indexofuser << ":" << Cur->username << " ";

				SetConsoleTextAttribute(h, 14);
				OutputVipUser(Cur);

				SetConsoleTextAttribute(h, 11);
				cout << endl;
				Cur = Cur->pNext;
				indexofuser++;
			}

			delete Cur;

			cout << "\n\t";
			system("pause");
			break;
		case 2: //Show attributes of house belong to username
			system("CLS");

			DrawFrame(86, 22);

			gotoxy(2, 2);
			SetConsoleTextAttribute(h, 14);
			cout << "\t\t\t\tSearch Information Users\n";

			SetConsoleTextAttribute(h, 11);
			cout << "\tEnter Username:";

			cin.ignore();
			getline(cin, username);

			Cur = this->FindNodeUser(username); //Find node User has same username

			if (Cur != nullptr) //If has User has same username
			{
				cout << "\tThe User have " << Cur->houseuser.size() << " houses";
				cout << "\n\tWhat is a house you want to see. Please input number:";

				cin >> indexofhouse;

				indexofhouse -= 1;

				cout << "\n\tThis is a house " << indexofhouse + 1 << " we have built: ";

				ShowInformation(Cur->houseuser[indexofhouse].housebuilder);
				cout << endl;
			}

			cout << "\n\t";
			system("pause");
			break;
		case 3: //Add new User
			system("CLS");

			DrawFrame(86, 22);

			gotoxy(2, 2);
			SetConsoleTextAttribute(h, 14);
			cout << "\t\t\t\tAdd New User\n";

			SetConsoleTextAttribute(h, 11);
			cout << "\tEnter Username:";
			cin.ignore();
			getline(cin, username);

			cout << "\tEnter Password:";
			password = inputPassWord();

			checkregister = Register(username, password); //Register new User

			if (checkregister == true) //Register successful
			{
				this->addTail(username);
				this->clientRequest(this->pTail);
				this->updateDirectortoInfUserFile();
			}
			else
			{
				cout << "\n\t";
				system("pause");
			}
			break;
		case 4: //Remove User
			system("CLS");

			DrawFrame(86, 22);

			gotoxy(2, 2);
			SetConsoleTextAttribute(h, 14);
			cout << "\t\t\t\tRemove User\n";

			SetConsoleTextAttribute(h, 11);
			cout << "\tEnter username:";
			cin.ignore();
			getline(cin, username);

			this->removeAccountUser(username); //Remove account User out system!
			break;
		}
	} while (choice != 5); //Exit loop
}

Director::~Director() //Destructor of Director class
{
	if (this->pHead != nullptr)
	{
		while (pHead) //Loop until pHead is nullptr
		{
			NodeUser* temp = pHead;
			pHead = pHead->pNext;

			for (int i = 0; i < temp->houseuser.size(); i++) //If size vector House User of Node User is better than 0 will delete Builder Pointer
			{
					if (temp->houseuser[i].houseblueprint != nullptr)
						delete temp->houseuser[i].houseblueprint;
					if (temp->houseuser[i].housebuilder != nullptr)
						delete temp->houseuser[i].housebuilder;
			}

			delete temp;
		}
	}
}