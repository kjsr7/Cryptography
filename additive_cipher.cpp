/* ENCRYPTION AND DECRYPTION USING ADDITIVE CIPHER METHOD */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string p;
	cout<<"enter the plain text"<<endl;
	cin>>p;
	int k;
	cout<<"enter the key"<<endl;
	cin>>k;
	int i=0;
	char cipher[100];
	while(p[i])
	{
		int asc = (int)p[i];
		if(asc>=97 && asc<=122)
		{
		
	
		asc=asc+k;
		
		if(asc > 122)
		{
		//	cout<<asc<<" ";
			asc = 97 + asc - 122 -1;
			cout<<asc<<endl;
				}
			}
			else
			{
				asc = asc + k;
				if(asc > 90)
				{
					asc = 65 + asc - 90 -1;
				}
			}
		//cout<<asc<<endl;
		cipher[i] = (char)asc;
		++i;
	}
	cipher[i] = '\0';
	cout<<"the cipher text is "<<endl;
	cout<<cipher<<endl;
	i = 0;
	char plain[100];
	while(cipher[i])
	{
		int asc = (int)cipher[i];
		if(asc>=97 && asc <=122)
		{
		
		asc-=k;
		if(asc < 97)
		{
		//	cout<<asc<<" ";
			asc  = 122 - (97 - abs(asc) - 1);
			//cout<<asc<<endl;
		}
	}
	else
	{
		asc-=k;
		if(asc < 65)
		{
		//	cout<<asc<<" ";
			asc  = 90 - (65 - abs(asc) - 1);
			//cout<<asc<<endl;
		}
		
	}
	
		plain[i] = (char)asc;
		++i;
		
	}
	plain[i] = '\0';
	cout<<"the plain text is "<<endl;
	cout<<plain<<endl;
}
