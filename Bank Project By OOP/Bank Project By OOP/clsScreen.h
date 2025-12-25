#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"


using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t________________________________________";
        cout << "\n\n\t\t\t\t\t" << Title;
       
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t________________________________________\n\n";

        cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << "\t\tDate: " << clsDate::DateToString(clsDate()) << "\n";

    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t__________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact Your Admin"; 
            cout << "\n\t\t\t\t\t__________________________________";
            return false;
        }
        else
            return true;
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t__________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact Your Admin"; 
            cout << "\n\t\t\t\t\t__________________________________";
            return false;
        }
        else
            return true;
    }
};

