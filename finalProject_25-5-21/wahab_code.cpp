#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
//#include<vector>

using namespace std;
//string username, password;
//int choice;

void login();
void registr();
void forget();

class customer
{
protected:
    string name, address;
    int cnic, id;
public:
    void customer_input()
    {
        cout << endl;
		cout << "Enter your name : ";
        cin >> name;
		cout << endl;
        cout << "Enter your id : ";
        cin >> id;
		cout << endl;
        cout << "Enter your cnic: ";
        cin >> cnic;
		cout << endl;
        cout << "Enter your address : ";
        cin >> address;
    }
    void customer_output()
    {
        system ("cls");
        cout << endl;
		cout << endl;
		cout <<"*************< YOUR DATA >*************"<<endl;
        cout << endl;
		cout << " your name : " << name << endl;
        cout << endl;
		cout << "your id : " << id << endl;
        cout << endl;
		cout << "your cnic: " << cnic << endl;
        cout << endl;
		cout << "Enter your address : " << address << endl;
		cout << endl;
	}
};
class daily_customer : public customer
{
protected:
    int qty;
    int price = 112;
public:
    static int count_daily_cust;
    void bill_calculation()
    {
		cout << endl;
        cout << "Enter quantity of milk : ";
        cin >> qty;
        cout <<endl;

        //cout <<"your total price is : " << price*qty<<endl;
    }
    void diplay_bill()
    {
        cout <<"*************< YOUR BILL IS >*************"<<endl;
        cout << endl;
		cout << "the price of 1 kg milk is equle to 112 PKR";
		cout << endl; 
	    cout << "your quantity of milk : " << qty <<" kg"<<endl;
        cout << endl;
		cout << "your total price is : " << price * qty<<" PKR"<< endl;
    }
};
class mountly_customer : public customer
{
protected:
    int qty, mounth_days = 0;
    int price = 112;
public:
    static int count_monthly_cust;
    void montly_bill_calculation()
    {
		cout << endl;
        cout << "Enter your day for buying milk : ";
        cin >> mounth_days;
		cout << endl;
        cout << "Enter quantity of milk : ";
        cin >> qty;
        //cout <<"your total price is : " << price*qty<<endl;
    }
    void monthly_diplay_bill()
    {	
		cout << endl;
        cout <<"*************< YOUR BILL IS >*************"<<endl;
        cout << endl;
		cout << "The price of 1 kg milk is equle to 112 PKR";
		cout << endl;
		cout << "your quantity of milk : " << qty <<" kg" <<endl;
        cout << endl;
		cout << "Enter your day for buying milk : " << mounth_days << endl;
        cout << endl;
		cout << "your total price is : " << price * qty <<" PKR" << endl;
		cout << endl;
	}
};

int main() 
{
	system ("cls");
	int choice = 0;
	cout << endl;
	cout << "**************** LOGIN ****************\n";
	cout << endl;
	cout << "select 1 for Login\n";
	cout << endl;
	cout << "select 2 for Register(if your are not Registered press this)\n";
	cout << endl;
	cout << "select 3 for forget password\n";
	//cout << "select 4 for Exit\n";
	cout << endl;
	cout << "Enetr your choice :";
	cin >> choice;
	switch (choice)
	{
	case 1:
		login();
		break;
	case 2:
		registr();
		break;
	case 3:
		forget();
		break;
	case 4:
		
		cout << "**************** Thank you for your time ****************\n";
		cout << endl;
		break;
	default:
		
		cout << "**************** wrrog selected choice ****************\n";
		cout << endl;
		main();
	}

	return 0;
}
void login()
{
	int exist = 0;
	string log_user, log_pass, u, p;
	system("cls");
	cout << endl;
	cout << "Enter a username : ";
	cin >> log_user;
	cout << endl;
	cout << "Enter your password : ";
	cin >> log_pass;

	ifstream input("User_data.txt");

	while (input >> u >> p)
	{
		if (u == log_user && p == log_pass)
		{
			exist = 1;
		}
	}

	input.close();
	if (exist == 1)
	{
		system ("cls");
		cout << endl;
		cout << " ****************** welcome ******************* \n";
		int cho{};
		cout << endl;
    	cout << "press 1 if you are daily customer\npress 2 if you are mountly customer" << endl;
    	cin >> cho;
		cout << endl;
		cout << " * * * * * * * * * * * * * * * * * * * * * * * * * < log_user > * * * * * * * * * * * * * * * * * * * * * * * * * * \n ";
		if (cho == 1)
    {
        daily_customer c1;
        c1.customer_input();
        c1.bill_calculation();
        c1.customer_output();

        c1.diplay_bill();
    }
    else {
        mountly_customer c2;
        c2.customer_input();
        c2.montly_bill_calculation();
        c2.customer_output();

        c2.monthly_diplay_bill();
        
    }

        //main();


        int a;
        cout << endl;
        cout << "press 1 if you are next customer ";
        cin >> a;
        if (a == 1)
        {
            system ("cls");
            main ();
        }
        else 
        {
            system ("cls");
        	cout <<endl;
            cout <<endl;
            cout <<endl;
            cout <<endl;
            cout <<endl;
            cout << "\t\t\t***   THANK YOU   **";
            cout <<endl;
            cout <<endl;
            cout <<endl;
            cout <<endl;
            cout <<endl;
            cout <<"."<<endl;
        }

		/*for (int a = 1; a <= 30; a++)
		{ 
			cout <<"  *                                                                                                                  *\n";
			
		}*/	
		cout << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * Thank you for joining us * * * * * * * * * * * * * * * * * * * * * * * * *\n";
		cin.get();
		cin.get();
		main();
	}
	else
	{
		cout << " ** Login ERROR **\n";
		cin.get();
		cin.get();
		main();
	}


}
void registr()
{
	string reg_user, reg_pass;
	system("cls");
	cout << endl;
	cout << "Eneter username : ";
	cin >> reg_user;
	cout << endl;
	cout << "Enet the pasword : ";
	cin >> reg_pass;
	ofstream reg("user_data.txt", ios::app);
	reg << reg_user << ' ' << reg_pass << endl;
	system("cls");
	cout << endl;
	cout << "congratulations your registration was successfull\n";
	main();
}
void forget()
{
	int ch = 0;
	int ex = 0;
	string serch_nam, sn, sp;
	ifstream search_us("user_data.txt");
	system("cls");
	cout << endl;
	cout << "select 1 to search your account by username \n";
	cout << endl;
	cout << "select 2 for mainmenu\n";
	cout << endl;
	cout << "Enetr your choice : ";
	cin >> ch;

	switch (ch)
	{
	case 1:
		cout << endl;
		cout << " Enter your username that u remember : ";
		cin >> serch_nam;

		while (search_us >> sn >> sp)
		{
			if (sn == serch_nam)
			{
				ex = 1;
				break;
			}
		}
		search_us.close();
		if (ex == 1)
		{
			cout << endl;
			cout << "congratulation accout found \n";
			cout << endl;
			cout << "so your password is : " << sp;
			cin.get();
			cin.get();
			main();
		}
		else
		{
			cout << endl;
			cout << " sorry account not found :-( \n";
			cin.get();
			cin.get();
			main();
		}
		break;
	case 2:
		system("cls");
		main();
		break;
	default:
		cout << endl;
		cout << "**************** wrrog selected choice ****************\n";
		main();
	}
}
/*int menu() 
{
	cout << "Press 1 to Register\nPress 2 to Sign In";
	cin >> choice;
	return choice;
}*/