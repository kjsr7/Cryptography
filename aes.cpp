#include<bits/stdc++.h>
using namespace std;
int mc[4][4] = {{2,3,1,1}, {1,2,3,1} ,{ 1,1,2,3}, {3,1,1,2}};
int subt[16][16];
char str[2];
void add_round_key(int pa[][4],int  ka[][4])
{
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
pa[i][j] = pa[i][j] ^ ka[i][j];
}
}
}
char shex(int n)
{
switch(n)
{
	case 0 : return '0';break;
	case 1: return '1';break;
	case 2: return '2';break;
	case 3: return '3';break;

	case 4: return '4';break;
	case 5: return '5';break;
	case 6: return '6';break;
	case 7: return '7';break;
	case 8: return '8';break;
	case 9: return '9';break;
	case 10: return 'A';break;
	case 11: return 'B';break;
	case 12: return 'C';break;
	case 13: return 'D';break;
	case 14: return 'E';break;
	case 15: return 'F';break;
}
}
void int_to_hex(int n)
{
int ind = 0;
int pind = -1,ans=0;
while(ind<=3)
{
if(((1<<ind) & n) == 0)
{

}
else
{
ans += pow(2,ind);
}
++ind;
}
//cout<<ans<<endl;
str[2]  = '\0';
str[1] = shex(ans);

ind = 4;
int ans2 = 0;
while(ind<=7)
{

if(((1<<ind) & n) == 0)
{

}
else
{
ans2 += pow(2,ind-4);
}

++ind;
}

//cout<<ans2<<endl;
str[0] = shex(ans2);
str[2] = '\0';
}
int sint_to_hex(char c)
{
switch(c)
{
	case '0': return 0;break;
	case '1': return 1;break;

	case '2': return 2;break;
	case '3': return 3;break;
	case '4': return 4;break;
	case '5': return 5;break;
	case '6': return 6;break;
	case '7': return 7;break;
	case '8': return 8;break;
	case '9': return 9;break;
	case 'A': return 10;break;
	case 'B': return 11;break;
	case 'C': return 12;break;	  
	case 'D': return 13;break;
	case 'E': return 14;break;
	case 'F': return 15;break;
}

}
void sub(int pa[][4])
{
int r,c;
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
int_to_hex(pa[i][j]);
r = sint_to_hex(str[0]); c = sint_to_hex(str[1]);
pa[i][j] = subt[r][c];
}
}

}
void shift_rows(int pa[][4])
{

int cs = 1;
int temp[4];
for(int i=1;i<4;i++)
{int ind = -1;
for(int j = cs;j<4;j++)
{
temp[++ind] = pa[i][j];}
for(int j=0;j<cs;j++)
{
temp[++ind] = pa[i][j];
}
for(ind  = 0;ind<4;ind++)
{
pa[i][ind]  = temp[ind];
}

++cs;
}

}
int last8(int n)
{
int ind = 0;int ans = 0;
while(ind<=7)
{
if(((1<<ind) & n) == 0)
{

}
else
{
ans += pow(2,ind);
}
++ind;
}
return ans;
}
void mix_columns(int pa[][4])
{
int ans = 0;
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
ans = 0;	
for(int k=0;k<4;k++)
{
int t = mc[i][k] * pa[k][j];
t = last8(t);
ans ^= t;
}
pa[i][j]  = ans;
}
}
}
int main()
{

	int m[256],t;
	memset(m,-1,sizeof(m));
for(int i=0;i<16;i++)
{
	for(int j=0;j<16;j++)
	{
	t = rand()%256;
	while(m[t]==1)
	{
	t = rand()%255;
	}
	subt[i][j] = t; m[t] = 1; 

	}
}

for(int i=0;i<16;i++)
{
	for(int j=0;j<16;j++)
	{
	cout<<subt[i][j]<<" ";
	}
	cout<<endl;
}
int_to_hex(16);
cout<<str<<endl;
int_to_hex(255);
cout<<str<<endl;
string p,k;
cout<<"enter 16 character string"<<endl;
cin>>p;
cout<<"enter the 16 character key"<<endl;
cin>>k;
int pa[4][4];
int ind = 0;
for(int i=0;i<4;i++)
{

for(int j=0;j<4;j++)
{
pa[j][i] = (int)p[ind];++ind;
}
}
ind = 0;
int ka[4][4];
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
ka[j][i] = (int)k[ind];++ind;
}
}
cout<<"the p is "<<endl;
for(int i=0;i<4;i++)
{
	for(int j=0;j<4;j++)
	{
	cout<<pa[i][j]<<" ";
	}
	cout<<endl;
}
cout<<"the k is "<<endl;
for(int i=0;i<4;i++)
{
	for(int j=0;j<4;j++)
	{
	cout<<ka[i][j]<<" ";
	}
	cout<<endl;
}
add_round_key(pa,ka);
cout<<"after adding round key"<<endl;
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
	cout<<pa[i][j]<<" ";
}
cout<<endl;
}
sub(pa);
cout<<"after sub "<<endl;
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
cout<<pa[i][j]<<" ";
}
cout<<endl;
}
shift_rows(pa);
cout<<"after shift rows"<<endl;

for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
cout<<pa[i][j]<<" ";
}
cout<<endl;
}
cout<<"the mix_col is "<<endl;
for(int i=0;i<4;i++)
{
	for(int j=0;j<4;j++)
	{
	cout<<mc[i][j]<<" ";
	}
	cout<<endl;
}
mix_columns(pa);
cout<<"after mixing the columns "<<endl;
for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
cout<<pa[i][j]<<" ";
}
cout<<endl;
}

}
