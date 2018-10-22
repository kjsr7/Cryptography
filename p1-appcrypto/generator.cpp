#include<bits/stdc++.h>
using namespace std;
int main()
{
int n = 19;int f;
map<int,int> m;
int ans;
for(int r = n-1;r>0;r--)
{
f = 0;ans = r;
m.clear();
for(int x=0;x<=n-2;x++)
{
if(m[pow(r,x)] == 0)
	m[pow(r,x)]  = 1;
else
{
f = 1;break;
}

}
if(!f)
	break;

}
cout<<ans<<endl;

}
