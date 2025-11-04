#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;


class clsBankClient :public clsPerson
{

private:
	enum enMode { EmptyMode =0 , UpdateMode=1};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1],
			vClientData[2], vClientData[3], vClientData[4], vClientData[5],
			stod(vClientData[6]));
	}

	
public:

	clsBankClient(enMode Mode , string FirstName, string LastName, 
		string Email, string Phone ,string AccountNumber,
		string PinCode,float AccountBalance) :
		clsPerson(FirstName , LastName , Email , Phone)
	{
		_Mode = Mode;
		AccountNumber =  _AccountNumber;
		PinCode =  _PinCode;
		AccountBalance = _AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string Pincode)
	{
		_PinCode = Pincode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName     :" << FirstName;
		cout << "\nLastName      :" << LastName;
		cout << "\nFullName      :" << FullName();
		cout << "\nEmail         :" << Email;
		cout << "\nPhone         :" << Phone;
		cout << "\nAcc. Number   :" << _AccountNumber ;
		cout << "\nPassword      :" << _PinCode;
		cout << "\nBalance       :" << _AccountBalance;
		cout << "\n___________________";

	}

	static clsBankClient Find(string accountNumber)
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("clients.txt", ios::in); // read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();	
		}
		return _GetEmptyClientObject();
		
	}

	static clsBankClient Find(string AccountNumber, string Pincode)
	{

	}
};

