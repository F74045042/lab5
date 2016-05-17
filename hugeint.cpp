#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class HugeInt{
	public:
		static int num;
		static string str;
		static int intstr;
		friend istream & operator >> (istream & in, HugeInt & huge)
		{
			in>>huge.integer;

			return in;
		}
		friend ostream & operator << (ostream &out, HugeInt & huge)
		{
			//cout<<"nono";
			out<<huge.integer;
			//out<<huge.str1;
			
			return out;
		}
		friend int operator + (HugeInt & a, HugeInt & b)
		{
			return a.integer + b.integer;
		}

		friend string & operator - (HugeInt & a, HugeInt & b)
		{
			//Here
			while(1)
			{
				b.digit = (b.integer)/(pow(10,num));
				num++;
				if(b.digit>0 && b.digit<10)
				{
					break;
				}

			}
			num = (20)-num;
			a.str1 = str.substr(num,21);
			
			istringstream ss(a.str1);
			ss >> intstr;
			
			intstr = intstr - b.integer;
			stringstream ss1;
			ss1 << intstr;
			//cout<< ss1.str() << endl;
			
			str = str.substr(0,num);
			//cout<< str << endl;
			
			b.str1 = str+ss1.str();
			//cout<<b.str1<<endl;

			return b.str1;
		}

		string & operator = (string & right)
		{
			cout<<right<<endl;

			return right;
		}

		HugeInt(int num = 0):integer(num)
		{
			//cout<<integer<<endl;
		}
		HugeInt(string str2):str1(str2)
		{
			str = str1;
			//cout<<str1<<endl;
		}
	private:
		int integer;
		int ten;
		int tmp;
		int digit;
		string str1;
};

int HugeInt::num = 0;
string HugeInt::str;
int HugeInt::intstr;

int main()
{
	HugeInt x;
	HugeInt y(28825252);
	HugeInt z("314159265358979323846");
	HugeInt result;
	cin>>x;
	result = x + y;
	cout<< x << "+" << y << "=" << result <<endl;

	result = z-x;
}
