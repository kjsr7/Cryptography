#ifndef CSE543_APPCRYPTO_INCLUDED

/**********************************************************************

   File          : cse543-appcrypto.h
  Description    : This is the applied crytography include for the
                   project #2. It contains the functional prototypes
                   for the needed applications.

   Last Modified : Tue Feb  6 06:03:43 EST 2007
   By            : Trent Jaeger

***********************************************************************/

/* Includes */
#include <gmp.h>

/* Defines */
#define DH_KEYLENGTH (unsigned long)512
#define RSA_KEYLENGTH (unsigned long)1024

/* Functional Prototypes */

/**********************************************************************

    Function    : initAppCryptoLibarary
    Description : initializes applied cryptography library 
    Inputs      : none
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
extern int initAppCryptoLibarary( void );

/**********************************************************************

    Function    : makePrime
    Description : make a "big" prime number 
    Inputs      : prime - object to place the prime number
                  length - length, in bits
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
extern int makePrime( mpz_t prime, unsigned long length );

/**********************************************************************

    Function    : getRandomBits
    Description : get some random bits
    Inputs      : val - value to fill
                  bits - number of bits to fill
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
extern int getRandomBits( mpz_t val, unsigned long bits );

/*---------------------------------------------------------------------

      Diffie-Hellman Functions

*/

/**********************************************************************

    Function    : makeDHGenerator
    Description : make a "big" generator from a prime
    Inputs      : prime - prime to make generator for (i.e., <g)
                  gen - the object to place in generator value into
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
extern int makeDHGenerator( mpz_t prime, mpz_t gen );

/**********************************************************************

    Function    : makeDHSeed
    Description : make a "big" challenge for diffie hellman
    Inputs      : prime - the prime generator
                  seed - the seed to create
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
extern int makeDHSeed( mpz_t prime, mpz_t seed );

/**********************************************************************

    Function    : makeHughesSeed
    Description : make a "big" generator from a prime, 
                  must be relative prime to prime-1 
    Inputs      : prime - prime to make generator for (i.e., <g)
                  seed - challenge for computing the DH Hughes key
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

extern int makeHughesSeed(mpz_t prime, mpz_t gen );

/**********************************************************************

    Function    : makeDHValue
    Description : Run a DH challenge computation: g^x mod p
    Inputs      : y - output value
                  g - generator
                  x - challenge
                  p - prime
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
extern int makeDHValue( mpz_t y, mpz_t g, mpz_t x, mpz_t p );

/**********************************************************************

    Function    : makeHughesSecret
    Description : Compute the final Hughes value
    Inputs      : k - output value (key)
                  x - opposite challenge (from alice: X)
                  y - local challenge (Bob selects y)
                  p - prime
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
extern int makeHughesSecret( mpz_t k, mpz_t x, mpz_t y, mpz_t p );

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
extern int makeRSAkey( mpz_t n, mpz_t e, mpz_t d );

/**********************************************************************

    Function    : rsaCrypt
cout<<"ka is "<<endl;
mpz_out_str(stdout, 10, ka);
cout<<endl;
    Description : encrypt/decrypt a value with public/private key
    Inputs      : ptext - input plaintext 
                  ctext - output ciphertext 
                  mod - the modulus (key)
                  key - the public/private exponent (key)
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
extern int rsaCrypt( mpz_t itext, mpz_t otext, mpz_t mod, mpz_t key );

#define CSE543_APPCRYPTO_INCLUDED
#endif
