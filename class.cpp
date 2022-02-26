#include <iostream>
using namespace std;

class Person{
private:
        int salary;
public:
        string fullName;

        void set(int income){
            cout << "enter full name : ";
            fflush(stdin);
            getline(cin,this->fullName);

            salary = income;
        }

        void show(){
            cout << "fullname : " << fullName << endl;
            cout << "salary : " << salary << endl;
        }
};

class Student : public Person{
};

int main(){
    Student newstd;
    newstd.set(2000);
    newstd.show();
    return 0;
}
