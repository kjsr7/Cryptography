
/* ENCYPTION AND DECRYPTION USING PLAYFAIR */

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string p;
	cout<<"enter the plain text"<<endl;
	cin>>p;
	cout<<"enter the key"<<endl;
	string k;
	cin>>k;
	//int m =5,n = 5;
	char key[5][5];
	int ind = 0;
	int indj = 0;
	int indi = 0;
	map <char,int> m;
	while(k[ind])
	{
		if(m[k[ind]] == 1)
		{
			
		}
		else
		{
			if(indj == 5)
			{
				++indi;indj = 0;
			}
			if(k[ind] == 'J' && m['I']!=1)
			{
				key[indi][indj]  = 'I';
				m['I'] = 1;
				++indj;
				m[k[ind]] = 1;
			}
			else if(k[ind] == 'J' && m['I'] == 1)
			{
				
			}
			else
			{
			key[indi][indj]  = k[ind];
			++indj;
			m[k[ind]] = 1;
		    }
			
		}
		
		++ind;
	}
	
	

int asc=65;
	for(int i=indj;i<5;i++)
	{
		while(m[(char)asc]==1)
		{
			++asc;
		}
		key[indi][i] = (char)asc;
		m[(char)asc] =1;	
	}
for(int i = indi+1;i<5;i++)
{
	for(int j=0;j<5;j++)
	{
		while(m[(char)asc] == 1)
		{
			++asc;
		}
		if((char)asc == 'J')
		{
			++asc;
			while(m[(char)asc] == 1)
			{
				++asc;
			}
		}
		key[i][j] = (char)asc;
		m[(char)asc] = 1;
		
	}
}
	
	cout<<endl;
for(int i=0;i<5;i++)
{
	for(int j=0;j<5;j++)
	{
		cout<<key[i][j]<<" ";
	}
	cout<<endl;
	}	
int n = p.length();
char a,b;
char cipher[100];
int index = -1;
int i=0;
int f = 0;
while(1)
{
if(i>n-1)
break;

	a = p[i];
	if(i+1 > n-1)
{
	b = 'X';f = 1;
}
else
	b = p[i+1];
	if(a == b)
	{
		b = 'X';
		--i;		
	}
		int ar,br,ac,bc;
	for(int i1=0;i1<5;i1++)
	{
		for(int j1= 0;j1<5;j1++)
		{
			if(key[i1][j1] == a)
			{
				ar = i1;ac=j1;break;
			}
		}
	}
	for(int i1=0;i1<5;i1++)
	{
		for(int j1= 0;j1<5;j1++)
		{
			if(key[i1][j1] == b)
			{
				br = i1;bc=j1;break;
			}
		}
	}
	if(ar == br)
	{
		if(ac == 4)
		ac = 0;
		else
		++ac;
		if(bc == 4)
		bc = 0;
		else
		++bc;	
		cipher[++index] = key[ar][ac];cipher[++index]  = key[br][bc];	
	}
	else if(ac == bc)
	{
		if(ac == 4)
		ar =0;
		else
		++ar;
		if(br == 4)
		br = 0;
		else
		
		++br;
		cipher[++index] = key[ar][ac]; cipher[++index] = key[br][bc];
	}
	else
	{
		ac = ac^bc;bc = ac^bc;ac = ac^bc;
		cipher[++index] = key[ar][ac]; cipher[++index] = key[br][bc];
	}
	
	i = i+2;
	if(f)
	break;
}
	cipher[++index] = '\0';
	cout<<cipher<<endl;
n =strlen(cipher);
index = -1;
char decipher[100];
for(int j = 0;j<n-1;j=j+2)
{
	char a,b;
	a = cipher[j];b = cipher[j+1];
	int ar,br;
	int ac,bc;
	for(int i1=0;i1<5;i1++)
	{
		for(int j1= 0;j1<5;j1++)
		{
			if(key[i1][j1] == a)
			{
				ar = i1;
				ac = j1;break;
			}
		}
	}
	for(int i1=0;i1<5;i1++)
	{
		for(int j1= 0;j1<5;j1++)
		{
			if(key[i1][j1] == b)
			{
				br = i1;
				bc = j1;break;
			}
		}
	}
	if(ar == br)
	{
		if(ac == 0)
		ac = 4;
		else
		--ac;
		if(bc == 0)
		bc = 4;
		else
		--bc;
		decipher[++index] = key[ar][ac]; decipher[++index]  = key[br][bc];
		
	}
	else if(bc == ac)
	{
		if(ar == 0)
		ar = 4;
		else
		--ar;
		if(br == 0)
		br = 4;
		else
		--br;
		decipher[++index] = key[ar][ac];
		decipher[++index] = key[br][bc];
	}
	else
	{
		ac = ac^bc;bc  = ac^bc;ac = ac^bc;
		decipher[++index] = key[ar][ac]; decipher[++index] = key[br][bc];
	}
	
	
	
	}
	decipher[++index] = '\0';
	//cout<<decipher<<endl;
for(int j = 0;j<strlen(decipher);j++)
	{
		if(decipher[j]!='X')
		{
			cout<<decipher[j];		}
	}
	
	
}
	

