#include"GRAPHIC.h"

void DrawFrame(short x, short y) //This function is used to Draw a Rentangular Frame 
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 13);

	for (int i = 0; i <= x; i++)
	{
		gotoxy(i, 0);
		cout << char(196);
		gotoxy(i, y);
		cout << char(196);
	}

	for (int i = 0; i <= y; i++)
	{
		gotoxy(x, i);
		cout << char(179);
		gotoxy(0, i);
		cout << char(179);

	}

	gotoxy(0, 0);
	cout << char(218);

	gotoxy(x, 0);
	cout << char(191);

	gotoxy(0, y);
	cout << char(192);

	gotoxy(x, y);
	cout << char(217);
}

string inputPassWord() //Input password
{
	int ch;
	string password;

	while (ch = _getch())
	{
		if (ch == 13)
		{
			break;
		}
		else if (ch == 8)
		{
			if (password.length() > 0)
			{
				cout << "\b \b";
				password.erase(password.length() - 1);
			}
		}
		else
		{
			cout << "*";
			password += ch;
		}
	}

	return password;
}

bool Register(string username, string password) //This function is used to Register User
{
	bool checkregister = true;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (username == "admin" || username == "")
	{
		checkregister = false;
	}
	else
	{
		string temp, checkusername, checkpassword;
		ifstream fin;
		fin.open("AccountUser.txt"); //Open file

		while (!fin.eof())
		{
			getline(fin, temp);
			stringstream ss(temp);
			getline(ss, checkusername, ',');
			getline(ss, checkpassword);

			if (username == checkusername) //Chec Username was exist in system
			{
				checkregister = false;
			}
		}

		fin.close(); //Close File
	}

	if (checkregister == false) //If Username was exist in system
	{
		SetConsoleTextAttribute(h, 14);
		cout << "\n\t\t\t\tRegister is error\n";

		SetConsoleTextAttribute(h, 11);
	}
	else //checkregister == true
	{
		ofstream fout; 
		fout.open("AccountUser.txt", ios_base::app); //Open file
		fout << "\n" << username << "," << password;

		SetConsoleTextAttribute(h, 14);
		cout << "\n\t\t\t\tRegister is successful\n";

		SetConsoleTextAttribute(h,11);
		fout.close();
	}
	return checkregister;
}

void gotoxy(short x, short y) //go to a point coordinate
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void HouseIntro() //House Intro
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	int k = 0;

	while (1) {
		system("CLS");
		DrawFrame(117, 26);

		gotoxy(2, 2);
		SetConsoleTextAttribute(handle, 14);
		cout << "\t\t\t\t\t\t     GROUP 6 - OOP";
		SetConsoleTextAttribute(handle, 13);
		cout << "\n\n\n\n\n";
		cout << "\t||             ||           ==========        ||      ||        //OOOOOO\O         ________                 \n";
		cout << "\t||             ||          OO         OO      ||      ||        OO               ||_______|                 \n";
		cout << "\t||             ||          OO         OO      ||      ||        OO               ||                         \n";
		cout << "\t||_____________||          OO         OO      ||      ||          OO             ||_______                  \n";
		cout << "\t||_____________||          OO         OO      ||      ||            OO           ||_______|                 \n";
		cout << "\t||             ||          OO         OO      ||      ||               OO        ||                         \n";
		cout << "\t||             ||          OO         OO      ||      ||               OO        ||                         \n";
		cout << "\t||             ||          OO         OO      ||      ||               OO        ||                         \n";
		cout << "\t||             ||          OO         OO      |{      /|        OO     OO        ||_______                  \n";
		cout << "\t||             ||           ==========         ========           OOOOOOO        ||_______|                 \n";
		cout << "\n\n\t\t\t\t\t\tLoading ";

		SetConsoleTextAttribute(handle, 14);
		cout << k;
		cout << " %\n";

		k += 15;

		Sleep(300);

		if (k >= 100) break;
	}

}

void MenuHouse::FirstScreen() //This function is used to show first screen Menu House
{
	int choice; //Variable is used to select menu functions below.
	Director dr; //Director class

	dr.updateInfUserFileToDirector();

	do
	{
		system("CLS");
		DrawFrame(86, 22);

		gotoxy(2, 2);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 14);
		cout << "\t\t\t\t Menu House";

		SetConsoleTextAttribute(h,11);
		cout << "\n\t1.Sign in.";
		cout << "\n\t2.Register.";
		cout << "\n\t3.Exit.";
		cout << "\n\tInput your choice:";

		cin >> choice;

		switch (choice)
		{
		case 1:
			this->MenuSignin(dr);
			break;
		case 2:
			this->MenuRegister();
			break;
		}
	} while (choice != 3);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void MenuHouse::MenuSignin(Director& dr) //This function is used to help User Sign in to Menu Build House
{
	string username, password;
	bool checksignin = false; //Check Username was exist in system

	system("CLS");
	cin.ignore();
	DrawFrame(86, 22);

	gotoxy(2, 2);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\t\t\t\tSign In Screen";

	SetConsoleTextAttribute(h, 11);
	cout << "\n\tUsername:";
	getline(cin, username); //Input username

	cout << "\n\tPassword:";
	password = inputPassWord();

	if (username == "admin" && password == "admin") //Sign in as Admin
	{

		dr.MenuAdmin();
		checksignin = true;
	}
	else //Sign in as User
	{
		ifstream fin;
		fin.open("AccountUser.txt");
		string temp, checkusername, checkpassword;

		while (!fin.eof())
		{
			getline(fin, temp);
			stringstream ss(temp);
			getline(ss, checkusername, ',');
			getline(ss, checkpassword);

			if (username == checkusername && password == checkpassword && username != "") //Sign in is successful
			{
				Director::MenuBuildHouseOfUser(username, dr);
				checksignin = true;
			}
		}

		fin.close(); //Close file
	}

	if (checksignin == false) //Username is not exist in this system
	{
		SetConsoleTextAttribute(h, 14);
		cout << "\n\t\t\t\tSign in is error\n";

		SetConsoleTextAttribute(h, 11);
		cout << "\n\t";
		system("pause");
	}
}

void MenuHouse::MenuRegister() //This function is used to help User Register to Menu Build House
{
	string username, password;
	bool checkregister = true;

	system("CLS");
	DrawFrame(86, 22);

	gotoxy(2, 2);
	cin.ignore();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "\t\t\t\tRegister Screen";

	SetConsoleTextAttribute(h,11);
	cout << "\n\tUsername:";

	getline(cin, username); //Input username

	cout << "\n\tPassword:";
	password = inputPassWord();

	Register(username, password);

	cout << "\n\t";
	system("pause");
}
