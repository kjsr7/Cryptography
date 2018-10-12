/* VIGENER'S ENCRYPTION AND DECRYPTION */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[26][26];
	char sr = 'a';
	char isr;
	for(int i=0;i<26;i++)
	{
		isr = sr;
		for(int j=0;j<26;j++)
		{
		a[i][j] = isr;
		if(isr == 'z')
		isr = 'a';
		else
		++isr;
		}
		++sr;
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	string p,k;
	cout<<"enter the plain text"<<endl;
	cin>>p;
	cout<<"enter the key"<<endl;
	cin>>k;
	int ind = 0;
	char cipher[100];
	int index = -1;
	for(int i=0;i<p.length();i++)
	{
		//cout<<a[(int)k[ind] - 97][(int)p[i] - 97]<<" ";
		cipher[++index] = a[(int)k[ind] - 97][(int)p[i] - 97];
		if(ind == k.length()-1)
		ind = 0;
		else
		++ind; 
	}
	cipher[++index] = '\0';
	cout<<"the cipher text is "<<endl;
	cout<<cipher<<endl;
	char decipher[100];
	index = -1;
	ind = 0;
	int j;
	for(int i=0;i<strlen(cipher);i++)
	{
		//cout<<a[(int)k[ind] - 97][(int)p[i] - 97]<<" ";
		
//		['decipher[++index] = a[(int)k[ind] - 97][(int)cipher[i] - 97];
		int r,c;
		r = (int)k[ind] - 97;
		j = 0;
		for(j=0;j<26;j++)
		{
			if (a[r][j] == cipher[i])
			{
			break;	
			}
		}
		decipher[++index] = (char)(97+j);
		if(ind == k.length()-1)
		ind = 0;
		else
		++ind; 
	}
		
	decipher[++index] = '\0';
	cout<<"the plain text is "<<endl;
	cout<<decipher<<endl;

}
