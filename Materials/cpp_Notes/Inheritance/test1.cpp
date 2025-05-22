//Demo of multipath/hybrid inheritance

#include <iostream>
#include <cstring>
using namespace std;

//Base Class
class Employee
{
	private:
		int empID;
		char name[20];
	public:
		void getEmp()
		{
			cout<<"\nEnter the Details of the Employee";
			cout<<"\nEnter EMP ID : ";
			cin>>empID;
			cout<<"\nEnter EMP Name : ";
			cin>>name;
		}

		void printEmp()
		{
			cout<<"\n=============Employee Info==============";
			cout<<"\nEMP ID : "<<empID;
			cout<<"\nEMP Name : "<<name;
		}

		char *getName()
		{
			return name;
		}
};


class EmpTeach : public Employee
{
	private:
		char sub_name[20];
		char t_name[20];
	public:
		void getTeach()
		{
			getEmp();
			cout<<"\nEnter Sub Name : ";
			cin>>sub_name;
			strcpy(t_name,getName());
		}

		void dispEmpTeach()
		{
			printEmp();
			cout<<"\nSub : "<<sub_name;
			cout<<"\n Teacher Name : "<<t_name;

		}
};

class NonEmpTeach: public Employee
{
	char dept_name[20];

	public:
		void getNonEmp()
		{
			cout<<"\nEnter Dept Name : ";
			cin>>dept_name;
		}

		void dispNonETeach()
		{
			cout<<"\nDept Name : "<<dept_name;
		}
};


class Instructor: public NonEmpTeach, public EmpTeach
{
	public:
		void getInstDetails()
		{
			getTeach();
			getNonEmp();
		}

		void dispInstDetails()
		{
			dispEmpTeach();
			dispNonETeach();
		}
};


int main()
{
	Instructor *inst;

	int count,i;
	cout<<"\nEnter the number of Instructor";
	cin>>count;

	inst = new Instructor[count];

	for(i=0;i<count;i++)
	{
		inst[i].getInstDetails();
	}
	
	for(i=0;i<count;i++)
	{
		inst[i].dispInstDetails();
		cout<<endl;
	}

	return 0;
}
