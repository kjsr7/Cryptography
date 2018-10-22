#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
int main()
{
mpz_t n,g,x,y,a,b,ka,kb;	//initialisation
//declaration
mpz_init(n);mpz_init(g); mpz_init(x);
mpz_init(y);
mpz_init(a);
mpz_init(b);
mpz_init(ka);
mpz_init(kb);

mpz_set_si(n,23);
mpz_set_ui(g,9);
mpz_set_ui(a,4);
mpz_set_ui(b,3);
// cout<<n<<endl; doesn't work
cout<<"n is "<<endl;
mpz_out_str(stdout, 10, n);
cout<<endl;
cout<<"g is "<<endl;
mpz_out_str(stdout, 10, g);
cout<<endl;

cout<<"a is "<<endl;
mpz_out_str(stdout, 10, a);
cout<<endl;

cout<<"b is "<<endl;
mpz_out_str(stdout, 10, b);
cout<<endl;

mpz_powm(x,g,a,n); 

cout<<"x is "<<endl;
mpz_out_str(stdout, 10, x);
cout<<endl;

mpz_powm(y,g,b,n);
mpz_powm(ka,y,a,n);

mpz_powm(kb,x,b,n);
printf("secret key for alice is %Zd\n", (signed size_t)ka);

printf("secret key for bob is %Zd\n", (signed size_t)kb);






}
