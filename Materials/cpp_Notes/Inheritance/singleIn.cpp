#include <iostream>
using namespace std;

//Base Class
class AddData 
{
	protected:
		int num1, num2;
	public:
		void ipValues(){
			cout<<"\nEnter the two values(num1,num2)"<<endl;
			cin>>num1>>num2;
		}
};

class MulValues : public AddData
{
	private:
		int mul;
	public:
		void multiply()
		{
			mul = num1*num2;
		}
		void result()
		{
			cout<<"Multiplication of two numbers = "<<mul<<endl;
		}
};


int main()
{
	MulValues M;
	M.ipValues();
	M.multiply();
	M.result();

	return 0;
}

