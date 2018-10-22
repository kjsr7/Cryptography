/**********************************************************************

   File          : cse543-appcrypto.c
   Description   : This is the applied cryptography code for the
                   project #2.  (see .h for functions)

   Last Modified : Sun Feb  4 08:42:48 EST 2007
   By            : Trent Jaeger

***********************************************************************/

/* Include Files */

/* Project Include Files */
#include <stdio.h>
#include <cse543-appcrypto.h>

/* Global Data */
gmp_randstate_t randState;

/**********************************************************************

    Function    : initAppCryptoLibarary
    Description : initializes applied cryptography library 
    Inputs      : none
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
int initAppCryptoLibarary( void )
{
     /* For now, just initialize the ramdomness */
     gmp_randinit_default( randState );
     return;
}

/**********************************************************************

    Function    : makePrime
    Description : make a "big" prime number 
    Inputs      : prime - object to place the prime number
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int makePrime( mpz_t prime, unsigned long length )
{ 
     /* Create a prime number */
     getRandomBits( prime, length );
     if ( mpz_probab_prime_p( prime, 10 ) == 2 )
          return( 0 );

     /* Get next prime and return it */
     mpz_t nprime;
     mpz_init( nprime );
     mpz_nextprime( nprime, prime );
     mpz_swap( prime, nprime );

     /* Return succesfully */
     return( 0 );
}

/**********************************************************************

    Function    : getRandomBits
    Description : get some random bits
    Inputs      : val - value to fill
                  bits - number of bits to fill
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int getRandomBits( mpz_t val, unsigned long bits )
{ 
     /* Create a random number */
     mpz_urandomb( val, randState, bits );
     return( 0 );
}

/*---------------------------------------------------------------------

      Diffe-Hellman Functions Code 

*/

/**********************************************************************

    Function    : makeDHGenerator
    Description : make a "big" generator from a prime
    Inputs      : prime - prime to make generator for (i.e., <g)
                  gen - the object to place in generator value into
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int makeDHGenerator( mpz_t prime, mpz_t gen )
{
    return( 0 );
}

/**********************************************************************

    Function    : makeHughesSeed
    Description : make y Hughes seed (will need to compute expontiative 
                  inverse of this, so it must be relatively-prime to prime-1)
    Inputs      : prime - prime to make generator for (i.e., <g)
                  seed - challenge for computing the DH Hughes key
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int makeHughesSeed( mpz_t prime, mpz_t seed )
{
    return( 0 );
}

/**********************************************************************

    Function    : makeDHSeed
    Description : make a "big" challenge for diffie hellman
    Inputs      : prime - the prime generator
                  seed - the challenge to create
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int makeDHSeed( mpz_t prime, mpz_t seed )
{
    return( 0 );
}

/**********************************************************************

    Function    : makeDHValue
    Description : compute the DH public values
    Inputs      : y - output value
                  g - generator
                  x - challenge
                  p - prime
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int makeDHValue( mpz_t y, mpz_t g, mpz_t x, mpz_t p )
{
    return( 0 );
}

/**********************************************************************

    Function    : makeHughesSecret
    Description : compute the Hughes value: k = X^y(-1) mod p
    Inputs      : k - output value
                  x - opposite challenge (Alice's value: X)
                  y - local challenge (Bob selects y)
                  p - prime
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int makeHughesSecret( mpz_t k, mpz_t x, mpz_t y, mpz_t p )
{
    return( 0 );
}

/*---------------------------------------------------------------------

      RSA Functions 

*/

/**********************************************************************

    Function    : makeRSAkey
    Description : create the initial RSA keys
    Inputs      : n - the modulus
                  e - the public exponent
                  d - the public exponent
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int makeRSAkey( mpz_t n, mpz_t e, mpz_t d )
{
    return( 0 );
}

/**********************************************************************

    Function    : rsaCrypt
    Description : encrypt/decrypt a value with public/private key
    Inputs      : itext - input {plain/cipher}text 
                  otext - output {plain/cipher}text 
                  mod - the modulus (key)
                  key - the public/private exponent (key)
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int rsaCrypt( mpz_t itext, mpz_t otext, mpz_t mod, mpz_t key )
{
    return( 0 );
}
