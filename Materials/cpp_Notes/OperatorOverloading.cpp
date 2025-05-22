/*
Demo on Operator overloading

- operator keyword
operator symbol_name()

some operators which can't be overloaded are,
1) :: 
2) .
3) .*
4) ?:
5) sizeof()


using friend function we can't overload operators like
1) ()
2) []
3) =
4) ->

*/
#include <iostream>
using namespace std;

class Test
{
	public:
		int value;
		Test(){}
		Test(int i) { value = i; }
		void display() { cout<<"Value : "<<value<<endl; }
		Test operator +(Test &obj)
		{
			value = value + obj.value;
			return value;
		}

		Test operator +=(Test &obj)
		{
			this->value = this->value + obj.value;
			return *this;
		}

		friend void operator ++(Test &obj1)
		{
			obj1.value++;
		}

		friend ostream &operator << (ostream &output, Test &obj1)
		{
					output << " Value : " << obj1.value;
					return output;
		}
};





int main(int argc, char const *argv[])
{
	/* code */
	Test T1(10), T2(20);

	cout<<"\nT1= ";
	T1.display();
	cout<<"\nT2= ";
	T2.display();
	

	T1 += T2;

	cout<<"\nT1= ";
	T1.display();
	cout<<"\nT2= ";
	T2.display();

	cout<<T1;
	++T1;
	cout<<T1;

	cout<<endl;

	return 0;
}
