
/* HILL CIPHER ENCRYPTION */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string p;
	cout<<"enter the plain text"<<endl;
	cin>>p;
	int n = p.length();
	if(n%2 == 1)
	{
		p[n] = 'X';
	}
	p[n+1] = '\0';
	if(n%2)
	++n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i] = (int)p[i] - 65;
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	string k;
	cout<<"enter the key without spaces in single line"<<endl;
	cin>>k;
	int c[n];
	for(int i=0;i<n-1;i++)
	{
		c[i] = ((int)k[0] - 48) * a[i] + ((int)k[1] - 48) * a[i+1];
		c[i+1] = ((int)k[2] - 48) * a[i] + ((int)k[3] - 48) * a[i+1];
	}
	cout<<"THE CIPHER TEXT IS "<<endl;
	for(int i = 0;i<n;i++)
	{
		c[i] = c[i] % 26;
		cout<<(char)(c[i]+65)<<" ";
	}
	cout<<endl;
		
}
