#include <iostream>
using namespace std;

class Student
{
	private:

		int rollno;
		char name[20];
	public:
		void getDetails()
		{
			cout<<"\nEnter RollNo: ";
			cin>>rollno;
			cout<<"\nEnter Name: ";
			cin>>name;
		}

		void dispDetails()
		{
			cout<<"\n==============================";
			cout<<"\n\tStudent Details";
			cout<<"\nRoll No: "<<rollno;
			cout<<"\nName: "<<name;
		}
};

class StdMarks : public Student
{
	public:
		int s1,s2,s3,s4,s5,s6;
		float per;
	public:
		void getMarks()
		{
			cout<<"\nEnter Marks for Subj 1 : ";
			cin>>s1;
			cout<<"\nEnter Marks for Subj 2 : ";
			cin>>s2;
			cout<<"\nEnter Marks for Subj 3 : ";
			cin>>s3;
			cout<<"\nEnter Marks for Subj 4 : ";
			cin>>s4;
			cout<<"\nEnter Marks for Subj 5 : ";
			cin>>s5;
			cout<<"\nEnter Marks for Subj 6 : ";
			cin>>s6;
		}

		void dispMarks()
		{
			dispDetails();
			cout<<"\nMarks of Subj 1 : "<<s1;
			cout<<"\nMarks of Subj 2 : "<<s2;
			cout<<"\nMarks of Subj 3 : "<<s3;
			cout<<"\nMarks of Subj 4 : "<<s4;
			cout<<"\nMarks of Subj 5 : "<<s5;
			cout<<"\nMarks of Subj 6 : "<<s6;
		}
};

class StdResult : public StdMarks 
{
	public:
		void calc()
		{
			per = (s1+s2+s3+s4+s5+s6)/6.0;
			cout<<"\n\n Total Percentage : "<<per;
		}

};


int main()
{
	StdResult *S;
	cout<<"\nEnter the no of Students : ";
	int count,i;
	cin>>count;
	S = new StdResult[count];

	for(i=0;i<count;i++)
	{
		S[i].getDetails();
		S[i].getMarks();
	}

	for(i=0;i<count;i++)
	{
		S[i].dispMarks();
		S[i].calc();
	}


	
	delete[] S;

	return 0;
}

