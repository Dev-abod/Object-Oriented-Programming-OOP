#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h";
#include "clsUser.h";
#include "clsMainScreen.h";
#include "Global.h";

using namespace std;




class clsLoginScreen : protected clsScreen
{


private:

	static void _Login()
	{
		bool LoginFaild = false;
		string Username, Password;

		do
		{
			if (LoginFaild)
			{
				cout << "\nInvaild Username/Password :\n\n ";
			}

			cout << "Enter Username? ";
			cin >> Username ;
			cout << "Enter Password? :";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);


		clsMainScreen::ShowMainMenue();

	}



public:

	static void ShowLoginScreen()
	{
		system("cls");

		_DrawScreenHeader("\tLogin Screen");
		_Login();


	}




};

