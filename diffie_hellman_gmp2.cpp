#include<bits/stdc++.h>
#include<gmp.h>
using namespace std;
mpz_t 
int isgen(mpz_t r, mpz_t n)
{
mpz_t x;
mpz_init(x);
mpz_set_ui(0);


}
int main()
{
mpz_t n;
mpz_init(n);
	mpz_inp_str(n,stdin,10);
	mpz_out_str(stdout, 10, n);
	if(mpz_probab_prime_p(n,10) != 2)
	{
	mpz_nextprime(n,n);
	}
mpz_t r;
mpz_init(r);
mpz_set(r,n);
    
mpz_sub_ui(r,r,1);
while(!(isgen(r,n)))
{

}

	
	

}
