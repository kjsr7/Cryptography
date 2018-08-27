
/* DES INITIAL AND FINAL PERMUTATIONS FOR ASCII CHARACTERS AS INPUT */

#include<bits/stdc++.h>
using namespace std;
void fun(string p)
{
	
	int b[64];
	int ind =-1;
	for(int i = 0;i<p.length();i++)
	{
		int t = (int)p[i];
		cout<<t<<endl;
		int bt[8];
	 	int ti = -1;
	 	int ct = t;
	 	while(ct!=0)
	 	{
	 		bt[++ti] = ct%2;
	 		ct= ct/2;
		 }
		 if(ti!=7)
		 {
		 	do
		 	{
		 		bt[++ti] = 0;
			 }while(ti!=7);
		 }
		 int  n = 8;
		 for(int i=0;i<n/2;i++)
		 {
		 	//bt[i] = bt[n-1-i];
		 	bt[i] = bt[i] ^ bt[n-1-i];
		 	bt[n-1-i] = bt[i] ^ bt[n-1-i];
		 	bt[i] = bt[i] ^ bt[n-1-i];
		 }
		
	for(int i=0;i<n;i++)
	{
	cout<<bt[i]<<" ";b[++ind] = bt[i];}
	cout<<endl;
	
	}
	cout<<"the plain text is"<<endl;
	if(ind!=63)
	{
		do
		{
			b[++ind] = 0;
		}while(ind!=64);
	}
	for(int i=0;i<64;i++)
	cout<<b[i]<<" ";
		int ip[64] = {58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
	
	cout<<endl;
	for(int i = 0;i<64;i++)
	cout<<ip[i]<<" ";
	cout<<endl;
	int c[64] = {0};
	ind = -1;
	for(int i = 0;i<64;i++)
	{
		if(b[i] == 1)
		{
			ind  = ip[i];
			c[ind-1] = b[i];
		}
	}
	
	cout<<endl;
	for(int i=0;i<64;i++)
	cout<<c[i]<<" ";
	cout<<endl;

	int iip[64] = {40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};
	int new1[64] = {0};
	for(int i = 0;i<64;i++)
	{
	
		if(c[i] == 1)
		{
			ind  = iip[i];
			new1[ind-1] = c[i];
		}
	}
	cout<<"AFTER FINAL PERMUTATION"<<endl;
	for(int i=7;i<=63;i+=8)
	{
		int a = 1*new1[i] + 2*new1[i-1] + 4*new1[i-2] + 8*new1[i-3] + 16*new1[i-4] + 32*new1[i-5]+64*new1[i-6] + 128*new1[i-7];
		cout<<(char)a<<" ";
	}
	
}
int main()
{
	string p;
	cout<<"enter the plain text"<<endl;
	cin>>p;
	
	//char t[100];
	int i =0;
	while(p[i])
	{
	
	char*t  = new char[100];
		t[0] = '\0';
		int j;
		for(j=i;p[j]!='\0' && j<=i+5;j++)
		{
			t[j-i] = p[j];
		}
		if(p[j] == '\0')
		{
			while(j!=i+6)
			{
				t[j-i] = 'X';
				++j;
			}
		}
		
		t[j] = '\0';
		string ct(t);
		//cout<<"the permuted blocks are"<<endl;
		fun(ct);
		i=j;
		
	}
	

	
}
