
/*  des initial and final permuations for hexadecimal as input*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string p;
	cout<<"enter the plain text"<<endl;
	cin>>p;
	cout<<'A'<<endl;
	int b[64];
	int ind = -1;
	for(int i=0;i<p.length();i++)
	{
		switch(p[i])
		{
		
			
			case '0': b[++ind] = 0;b[++ind] = 0; b[++ind] = 0;b[++ind] = 0;break;
			case '1': b[++ind] = 0;b[++ind] = 0; b[++ind] = 0;b[++ind] = 1;break;
			case '2': b[++ind] = 0;b[++ind] = 0; b[++ind] = 1;b[++ind] = 0;break;
			case '3': b[++ind] = 0;b[++ind] = 0; b[++ind] = 1;b[++ind] = 1;break;
			case '4': b[++ind] = 0;b[++ind] = 1; b[++ind] = 0;b[++ind] = 0;break;
			case '5': b[++ind] = 0;b[++ind] = 1; b[++ind] = 0;b[++ind] = 1;break;
			case '6': b[++ind] = 0;b[++ind] = 1; b[++ind] = 1;b[++ind] = 0;break;
			case '7': b[++ind] = 0;b[++ind] = 1; b[++ind] = 1;b[++ind] = 1;break;
			case '8': b[++ind] = 1;b[++ind] = 0; b[++ind] = 0;b[++ind] = 0;break;
			case '9': b[++ind] = 1;b[++ind] = 0; b[++ind] = 0;b[++ind] = 1;break;
			case 'A': b[++ind] = 1;b[++ind] = 0; b[++ind] = 1;b[++ind] = 0;break;
			case 'B': b[++ind] = 1;b[++ind] = 0; b[++ind] = 1;b[++ind] = 1;break;
			case 'C': b[++ind] = 1;b[++ind] = 1; b[++ind] = 0;b[++ind] = 0;break;
			case 'D': b[++ind] = 1;b[++ind] = 1; b[++ind] = 0;b[++ind] = 1;break;
			case 'E': b[++ind] = 1;b[++ind] = 1; b[++ind] = 1;b[++ind] = 0;break;			
			case 'F': b[++ind] = 1;b[++ind] = 1; b[++ind] = 1;b[++ind] = 1;break;
			
			
		}
	}
//	b[++ind] = '\0';
//cout<<ind<<endl;
	cout<<"the plain text is "<<endl;
	for(int i=0;i<64;i++)
	cout<<b[i]<<" ";
	cout<<endl;
	//cout<<b[62]<<" "<<b[24]<<endl;
	cout<<endl;
	int ip[64] = {40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};
	
	cout<<endl;
	for(int i = 0;i<64;i++)
	cout<<ip[i]<<" ";
	cout<<endl;
	int c[64] = {0};
	ind = -1;
/*	cout<<"---"<<endl;
	cout<<ip[0]<<endl;
	cout<<ip[0] -1 <<endl;*/
//	cout<<"-------------["<<endl;
    //ind=0;
	for(int i = 0;i<64;i++)
	{
		//cout<<b[ip[++ind] - 1]<<" ";
		//c[i] = b[ip[i] - 1];	
		if(b[i] == 1)
		{
			ind  = ip[i];
			c[ind-1] = b[i];
		}
		//cout<<i<<" "<<ip[i]-1<<" "<<endl;	
	}
	
	cout<<endl;
	for(int i=0;i<64;i++)
	cout<<c[i]<<" ";
	cout<<endl;
	//	cout<<c[63]<<" "<<c[14]<<endl;

//	cout<<b[63]<<" "<<b[14]<<" "<<endl;
//	cout<<c[24]<<" "<<c[62]<<" "<<endl;
	ind = -1;
	char cip[100];
	for(int i=3;i<=63;i+=4)
	{
		int a = 1*c[i] + 2*c[i-1] + 4*c[i-2] + 8*c[i-3];
	//	cout<<a<<endl;
		switch(a)
		{
			case 0: cip[++ind] = '0';break;
			case 1 : cip[++ind]  = '1';break;
			case 2 : cip[++ind]  = '2';break;
			case 3 : cip[++ind]  = '3';break;
			case 4 : cip[++ind]  = '4';break;
			case 5 : cip[++ind]  = '5';break;
			case 6 : cip[++ind]  = '6';break;
			case 7 : cip[++ind]  = '7';break;
			case 8 : cip[++ind]  = '8';break;
			case 9 : cip[++ind]  = '9';break;
			case 10 : cip[++ind]  = 'A';break;
			case 11 : cip[++ind]  = 'B';break;
			case 12 : cip[++ind]  = 'C';break;
			case 13 : cip[++ind]  = 'D';break;
			case 14 : cip[++ind]  = 'E';break;
			case 15 : cip[++ind]  = 'F';break;	
			default: cout<<"*";
		}
	//	cout<<ind<<" "<<cip<<endl;
	}
	cip[++ind] = '\0';
	cout<<"---"<<cip<<endl;
	

	
	
	
}
