#include<bits/stdc++.h> 
#include<gmp.h>
using namespace std;
long long int power(long long int a, long long int b, 
                                     long long int P) 
{  
    if (b == 1) 
        return a;   
    else
        return (((long long int)pow(a, b)) % P); 
} 
  
int main() 
{ 
    mpz_t p,g,a,b,x,ka,kb,x,y;
  gmp_scanf("%Zd", &p);  // 23
    gmp_printf("The value of P : %Zd\n", p);   
    gmp_scanf("%Zd", &g);//9 
    printf("The value of G : %Zd\n\n", g);  
  gmp_scanf("%Zd",&a);//4
    printf("The private key a for Alice : %Zd\n", a); 
   mpz_pow_ui(x,g,a,p); 
  gmp_scanf("%Zd",&b);  //3
    printf("The private key b for Bob : %Zd\n\n", b); 

   mpz_pow_ui(y,g,b,p); 
  

   mpz_pow_ui(ka,y,a,p); 

   mpz_pow_ui(kb,x,b,p); 
      
    printf("Secret key for the Alice is : %Zd\n", ka); 
    printf("Secret Key for the Bob is : %Zd\n", kb); 
      
    return 0; 
} 
