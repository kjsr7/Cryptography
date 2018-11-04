#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
int isgen(mpz_t r, mpz_t n)
{
mpz_t result,two,one;mpz_init(result);mpz_init(two);mpz_init(one);
mpz_set_ui(two,2);
mpz_set_ui(one,1);
mpz_set(result,n);
mpz_sub_ui(result,result,1);
mpz_t r2;
mpz_init(r2);
mpz_cdiv_q(r2,result,two);
mpz_t x2;
mpz_init(x2);
mpz_powm(x2,r,result,n);
if(mpz_cmp(x2,one) == 0)
{
return 0;
}
else
return 1;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
mpz_t n;
mpz_init(n);
	mpz_inp_str(n,stdin,10);
//	mpz_out_str(stdout, 10, n);
	if(mpz_probab_prime_p(n,10) != 2)
	{
	cout<<"not prime "<<endl;
	mpz_nextprime(n,n);
	}
mpz_out_str(stdout, 10, n);
cout<<endl;
mpz_t r,one;
mpz_init(r),mpz_init(one);
mpz_set_ui(r,1);mpz_set(one,n);
mpz_sub_ui(one,one,2);

//while(!(isgen(r,n)))

while(1)
{
if(isgen(r,n))
break;
if(mpz_cmp(r,one) == 0)
break;
mpz_add_ui(r,r,1);
}

if(isgen(r,n))
{
cout<<"the g is "<<endl;
mpz_out_str(stdout, 10, r);
 
}

cout<<"PRIMITIVE ROOT GENERATED "<<endl;
mpz_t a,b,x,y,ka,kb,g;
mpz_init(g); mpz_set(g,r);
mpz_init(x);
mpz_init(y);
mpz_init(a);
mpz_init(b);
mpz_init(ka);
mpz_init(kb);

cout<<"enter random number for alice "<<endl;
mpz_inp_str(a,stdin,10);
mpz_powm(x,g,a,n);
cout<<"the public for alice is "<<endl;
mpz_out_str(stdout, 10, x);cout<<endl;


cout<<"enter random number for  bob"<<endl;
mpz_inp_str(b,stdin,10);
mpz_powm(y,g,b,n);
cout<<"the public for alice is "<<endl;
mpz_out_str(stdout, 10, y);cout<<endl;

cout<<" the keys for alice and bob are "<<endl;
mpz_powm(ka,y,a,n);
mpz_powm(kb,x,b,n);
mpz_out_str(stdout, 10, ka); cout<<" "; mpz_out_str(stdout, 10, kb);


}
