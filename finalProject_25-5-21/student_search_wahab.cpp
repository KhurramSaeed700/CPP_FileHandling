#include <iostream>

#include <fstream>

using namespace std;

class student
{
private:
	string name, address;
	int id;

public:
	void student_input()
	{
		//system ("cls");
		fstream student_data("student.txt", ios::app);
		cout << "Enter your name : ";
		cin >> name;
		cout << endl;
		cout << "Enter your id : ";
		cin >> id;
		cout << endl;
		cout << "Enter your address : ";
		cin >> address;
		cout << endl;

		student_data.open("student.txt");
		student_data << id << ' ' << name << ' ' << address << endl;
		student_data.close();
		cout << "file write operation performed successfully" << endl<< endl;
	}
	// void student_output()
	// {
	//     system ("cls");
	//     cout << endl;
	// 	cout << endl;
	// 	cout <<"*************< YOUR DATA >*************"<<endl;
	//     ofstream student_data("student.txt");
	//     while(student_data)
	//         {
	//             fstream student_data;
	//             student_data.seekg(ios::beg);
	//             student_data.std::cout<<;
	//             student_data.close();
	//         }
	// }
};


int main()
{
	student s1;
	int a;
	cout<<"Hello World\nWelcome\n\nhow many students you would like to add? : ";
	cin>>a;
	cout<<"\nAdd data for "<<a<<" students: ";
	while (a <= 5)
	{
		cout << "\n*************  student #" << a <<"  *************" << endl;
		s1.student_input();
		cout << endl;
		a++;
	}

	search();
}

void search()
{
	int ex = 0;
	string s_name, s_id, s_address;
	ifstream search_data;
	search_data.open("student.txt");

	cout<<"\ntype the students name you want to search: ";
	cin>>s_name;

	while (search_data.eof()){
		if (s_name == s_id && s_name == s_address)
		{
			ex = 1;
			break;
		}
	}
	search_data.close();
	if (ex == 1)
	{
		cout << endl;
		cout << "congratulation student found \n";
		cout << endl;
		cout << "so student name is : " << s_name;
		cout << endl;
		cout << "so student id is : " << s_id;
		cout << endl;
		cout << "so student addres is : " << s_address;
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
}