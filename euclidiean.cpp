/* euclidiean Algorithm */


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cout<<"enter the two numbers"<<endl;
	cin>>a>>b;
	int r;
	cout<<'q'<<" "<<'a'<<" "<<'b'<<" "<<'r'<<endl;
	while(a%b!=0)
	{
		cout<<a/b<<" ";
		r = a%b;
		cout<<a<<" ";
		cout<<b<<" ";
		cout<<r;
		a = b;
		b = r;	
		cout<<endl;
	}
	cout<<a/b<<" "<<a<<" "<<b<<" "<<a%b<<" "<<endl;
	cout<<"the gcd of the two numbers is "<<b<<endl;
}
