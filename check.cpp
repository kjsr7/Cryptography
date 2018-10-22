#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
int main()
{
mpz_t r,x,n,x2;
mpz_init(r);

mpz_init(x);

mpz_init(n);

mpz_init(x2);
mpz_set_ui(r,9);

mpz_set_ui(x,2);

mpz_set_ui(n,11);
mpz_powm(x2,r,x,n);
mpz_out_str(stdout, 10, x2);
map<mpz_t, int> m;
mpz_t a,b,q;
mpz_init(a);
mpz_init(b);
mpz_init(q);
mpz_set_ui(a,10);

mpz_set_ui(b,2);
mpz_cdiv_q(q,a,b);
mpz_out_str(stdout, 10, q);


}
