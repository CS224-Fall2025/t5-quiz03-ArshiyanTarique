#include <iostream>
#include <string>
using namespace std;

class Employee{
    protected:
        string name;
        double salary;
        static int employeeCount;
    public:
        Employee(string n, double s):name(n),salary(s){
            employeeCount+=1;
        }
        virtual void displayInfo(){
            cout<<"Name: "<<name<<", "<<"Salary: "<<salary<<endl;
        }
        static void showTotalEmployees(){
            cout<<"Total Number of Employees: "<<employeeCount<<endl;
        }
        virtual ~Employee(){}
};
int Employee::employeeCount=0;

class Staff:public Employee{
    private:
        string department;
    public:
        Staff(string n, string nameEmployee, double sal): Employee(nameEmployee,sal),department(n){}
        void displayInfo()override{
            cout<<"Name: "<<name<<" (Staff), "<<"Salary: "<<salary<<endl;
        }
};

class Faculty:public Employee{
    private:
        string department;
    public:
        Faculty(string n, string nameEmployee, double sal):Employee(nameEmployee,sal),department(n){}
        void displayInfo()override{
            cout<<"Name: "<<name<<" (Faculty), "<<"Salary: "<<salary<<endl;
        }
};



int main() {
    int n=0;
    string dep,nameEmployee;
    double sal;
    cin>>n;
    Employee* employeeArr[1];
    for (int i=0; i<n; i++){
        cin>>dep>>nameEmployee>>sal;
        if (dep=="Staff"){
            Staff* staff=new Staff(dep,nameEmployee,sal);
            employeeArr[i]=staff;
        }
        else if (dep=="Faculty"){
            Faculty* faculty=new Faculty(dep,nameEmployee,sal);
            employeeArr[i]=faculty;
        }
    }
    for (int i=0; i<n; i++){
        employeeArr[i]->displayInfo();
    }
    Employee::showTotalEmployees();
}