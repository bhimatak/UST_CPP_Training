// demo of multiple inheritance

#include <iostream>
#include <cstring>
using namespace std;

//Base class 1
class employee
{	
	protected:
		int empCode;
		char name[200];
		float salary;

	public:
		employee(){}
		employee(int id, char *n, float s)
		{ 
			empCode = id; 
			strcpy(name,n);
			salary = s;
		}

		void printEmp()
		{	
			cout<<"\nEmpID = "<<empCode;
			cout<<"\nEmpName = "<<name;
			cout<<"\nEmpSalary = "<<salary;
		}
};

//Base class 2
class officer
{
	protected:
		float DA,HRA;

	public:
		officer(){}
		officer(float d, float h){ DA = d; HRA = h; }

		void printOff()
		{
			cout<<"\nDA = "<<DA;
			cout<<"\nHRA = "<<HRA;
		}

};

//Derivered Class from B1 and B2
class manager : public employee, public officer
{
	private:
		float TA, gsal;
	
	public:
		manager(){}
		manager(int c, char *n, float s, float d, float h):employee(c,n,s), officer(d,h){}
		void printMang()
		{
			printEmp();
			printOff();
			TA = 0.10 * salary;
			cout<<"\nTA = "<<TA;
			gsal = DA+HRA+TA+salary;
			cout<<"\nGross Salary = "<<gsal<<endl;
		}

};

int main()
{
	int count, i;
	manager *m;

	cout<<"\nEnter the number of Managers : ";
	cin>>count;

	m = new manager[count];

	for(i=0;i<count;i++)
	{
		cout<<"\nEnter the information of Employee "<<(i+1)<<endl;
		cout<<"\nEnter the empID : ";
		int id;	
		cin>>id;
		cout<<"\nEnter the EmpName : ";
		char n[20];
		cin>>n;
		cout<<"\nEnter Salary : ";
		float s;
		cin>>s;
		cout<<"\nEnter DA : ";
		float d;
		cin>>d;
		cout<<"\nEnter HRA : ";
		float h;
		cin>>h;
		m[i] = manager(id,n,s,d,h);
	}

	for(i=0;i<count;i++)
	{
		cout<<"\n================================";
		cout<<"\n\tManager's Information";
		cout<<"\n================================";
		m[i].printMang();
	}

	return 0;
}
