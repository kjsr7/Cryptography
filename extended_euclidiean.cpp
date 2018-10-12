
/* Extended Euclidiean Algorithm */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cout<<"enter the two numbers"<<endl;
	cin>>a>>b;
	int r;
	int s1,s2,s,t1,t2,t;	
	cout<<'q'<<" "<<"a"<<" "<<"b"<<" "<<'r'<<" "<<""<<" "<<"s2"<<" "<<'s'<<" "<<"t1"<<" "<<"t2"<<" "<<"t"<<endl;
	s1 = 1;s2 = 0; t1 = 0;t2 = 1;
	while(a%b!=0)
	{
		cout<<a/b<<" ";
		r = a%b;
		
		cout<<a<<" ";
		cout<<b<<" ";
		cout<<r<<" ";
		cout<<s1<<" ";
		cout<<s2<<" ";
		s = s1 - s2*(a/b);
		cout<<s1 - s2*(a/b)<<" ";
		cout<<t1<<" "<<t2<<" ";
		t = t1 - t2*(a/b);
		cout<<t1 - t2*(a/b)<<" ";
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
		a = b;
		b = r;	
		cout<<endl;
	}
		cout<<a/b<<" "<<a<<" "<<b<<" "<<a%b<<" "<<s1<<" "<<s2<<" "<<s<<" "<<t1<<" "<<t2<<" "<<t<<endl;

	cout<<"the gcd of the two numbers is "<<b<<endl;
}
