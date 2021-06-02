\#include <iostream>
#include <fstream>

using namespace std;

namespace worker
{
  class worker 
  {
    protected:
        char w_name[100];
        char w_address[100];
        char w_id[100];
        char w_cnic[100];
        char w_phone[100];

    public:
        void worker_input()
    {
        cout << endl;
		cout << "Enter your name : ";
        cin >> w_name;
		cout << endl;
        cout << "Enter your id : ";
        cin >> w_id;
		cout << endl;
        cout << "Enter your cnic: ";
        cin >> w_cnic;
		cout << endl;
        cout << "Enter your address : ";
        cin >> w_address;
        cout << endl;
        cout << "Enter your PHONE : ";
        cin >> w_phone;

    }
    void workers_output()
    {
        system ("cls");
        cout << endl;
		cout << endl;
		cout <<"*************< YOUR DATA >*************"<<endl;
        cout << endl;
		cout << " your name : " << w_name << endl;
        cout << endl;
		cout << "your id : " << w_id << endl;
        cout << endl;
		cout << "your cnic: " << w_cnic << endl;
        cout << endl;
		cout << "Enter your address : " << w_address << endl;
		cout << endl;
                cout << endl;
		cout << "your phone: " << w_phone << endl;
        cout << endl;

	}
    class milkman : public worker
    {
        void workers_input();
        void workers_output();

    }

  }; 
};

using namespace worker;

int main ()
{
    worker w1;
    w1.worker_input();
    w1.worker_output();
}