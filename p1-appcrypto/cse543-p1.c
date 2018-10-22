
/**********************************************************************

   File          : cse543-p2.c

   Description   : This is the Diffie-Hellman (Hughes) 
                   and RSA code for the homework #2.
                   (see .h for applications)

   Last Modified : Sun Feb  4 08:42:48 EST 2007
   By            : Trent Jaeger

***********************************************************************/

/* Include Files */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* Project Include Files */
#include <cse543-util.h>
#include <cse543-appcrypto.h>

/* Definitions */
#define ARGUEMENTS "dr"
#define USEAGE "USEAGE: -d -- Diffie-Hellman (Hughes) test\n" \
               "        -r -- RSA test\n\n"

/**********************************************************************

    Function    : doHughesTest
    Description : Run the Hughes variation of the DH protocol
    Inputs      : none
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int doHughesTest( void )
{
     /* Create and initialize all the integers */
     mpz_t p, g, x, X, y, Y, kl, kr;
     mpz_init( p );
     mpz_init( g );
     mpz_init( x );
     mpz_init( X );
     mpz_init( y );
     mpz_init( Y );
     mpz_init( kl );
     mpz_init( kr );

     /* Now do the setup */
     if ( makePrime(p,DH_KEYLENGTH) || makeDHGenerator(p, g) )
     {
        /* Error out */
        errorMessage( "Error: failure making DH prime/generator\n" );
        return( -1 );
     }

     /* Make the seeds, challenges */
     if ( makeDHSeed( p, x ) || makeDHValue( kl, g, x, p ) || 
          makeHughesSeed( p, y ) || makeDHValue( Y, g, y, p ) ||
	  makeDHValue( X, Y, x, p ) )
     {
        /* Error out */
        errorMessage( "Error: failure making DH seeds/challenges\n" );
        return( -1 );
     }

     /* Extract secrets */
     if ( makeHughesSecret( kr, X, y, p ) )
     {
        /* Error out */
        errorMessage( "Error: failure exrtacting DH secrets\n" );
        return( -1 );
     }

     /* Print base data */
     char *tstr = NULL;
     printf( "Diffie-Hellman Exchange\n" );
     printf( "  Prime      : %s\n", mpzToString( &tstr, p ) );
     printf( "  Generator  : %s\n", mpzToString( &tstr, g ) );
     printf( "\n" );

     /* Left side data */
     printf( "Left player ..\n" );
     printf( "  x (Alice's secret)      : %s\n", mpzToString( &tstr, x ) );
     printf( "  X (Alice's public)      : %s\n", mpzToString( &tstr, X ) );
     printf( "  kl (Alice's key)        : %s\n", mpzToString( &tstr, kl ) );
     printf( "\n" );

     /* right side data */
     printf( "Right player ..\n" );
     printf( "  y (Bob's secret)        : %s\n", mpzToString( &tstr, y ) );
     printf( "  Y (Bob's public)        : %s\n", mpzToString( &tstr, Y ) );
     printf( "  kr (Bob's key)          : %s\n", mpzToString( &tstr, kr ) );
     printf( "\n" );

     /* Check if things worked out */
     if ( mpz_cmp (kr, kl) == 0 )
        printf( "*** SUCCESS, key negotiated ***\n" );
     else
        printf( "*** FAILURE, key not negotiated ***\n" );

     /* Return successfully */
     return( 0 );
}

/**********************************************************************

    Function    : doRSATest
    Description : do the RSA test
    Inputs      : none
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int doRSATest( void )
{
     /* Create and initialize all the integers */
     mpz_t n, e, d, val, rctext, rptext, pctext, pptext;
     mpz_init( n );
     mpz_init( e );
     mpz_init( d );
     mpz_init( val );
     mpz_init( rctext );
     mpz_init( rptext );
     mpz_init( pctext );
     mpz_init( pptext );
     getRandomBits( val, 128 );

     /* Now do the setup */
     if ( makeRSAkey(n,e,d) )
     {
        /* Error out */
        errorMessage( "Error: failure making RSA key\n" );
        return( -1 );
     }

     /* Encrypt with the private key/descrypt with public key */
     if ( rsaCrypt( val, rctext, n, d ) || 
          rsaCrypt( rctext, rptext, n, e ) )
     {
        /* Error out */
        errorMessage( "Error: RSA encrypt failure\n" );
        return( -1 );
     }

     /* Encrypt with the public key/descrypt with private key */
     if ( rsaCrypt( val, pctext, n, e ) || 
          rsaCrypt( pctext, pptext, n, d ) )
     {
        /* Error out */
        errorMessage( "Error: RSA encrypt failure\n" );
        return( -1 );
     }

     /* Print base data */
     char *tstr = NULL;
     printf( "RSA Key\n" );
     printf( "  Modulus           : %s\n", mpzToString( &tstr, n ) );
     printf( "  Public expoonent  : %s\n", mpzToString( &tstr, e ) );
     printf( "  Private expoonent : %s\n", mpzToString( &tstr, d ) );
     printf( "\n" );

     /* private->public */
     printf( "Private key encryption/public key decryption ..\n" );
     printf( "  plaintext         : %s\n", mpzToString( &tstr, val ) );
     printf( "  ciphertext        : %s\n", mpzToString( &tstr, rctext ) );
     printf( "  plaintext         : %s\n", mpzToString( &tstr, rptext ) );
     printf( "\n" );

     /* public->private */
     printf( "Public key encryption/private key decryption ..\n" );
     printf( "  plaintext         : %s\n", mpzToString( &tstr, val ) );
     printf( "  ciphertext        : %s\n", mpzToString( &tstr, pctext ) );
     printf( "  plaintext         : %s\n", mpzToString( &tstr, pptext ) );
     printf( "\n" );

     /* Check if things worked out */
     if ( (mpz_cmp(val, rptext) == 0) && (mpz_cmp(val, pptext) == 0) )
        printf( "*** SUCCESS, data encrypted/decrypted ***\n" );
     else
        printf( "*** FAILURE, data not encrypted/decrypted ***\n" );

     /* Return successfully */
     return( 0 );
}

/**********************************************************************q

    Function    : main
    Description : this is the main function for homework #1
    Inputs      : argc - number of command line parameters
                  argv - the text of the arguements
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

/* Functions */
int main( int argc, char **argv ) 
{
    /* Local Variables */
    int testComplete = 0;
    char ch;

    /* initialize everything */
    initAppCryptoLibarary();

    /* Check for arguments */
    if ( argc < 2 ) 
    {
        /* Complain, explain, and exit */
        errorMessage( "Error: missing or bad command line arguments\n" );
        printf( USEAGE );
        exit( -1 );
    }

    /* Keep getting arguments */
    while ( (ch = getopt(argc, argv, ARGUEMENTS)) != -1 ) 
    {
        /* Which test are we running? */
        switch (ch) 
        {
            /* Diffie-Hellman */
            case 'd' : printf( "Running DH (Hughes) Algorithm\n" );
                 testComplete = !doHughesTest();
                       break;

            /* RSA */
            case 'r' : printf( "Running RSA Algorithm\n" );
                 testComplete = !doRSATest();
                       break;

            /* Unknown Test, bail out */
            default: errorMessage( "Error: bad or test specification\n" );
                     break;
        }
    }

    /* Return test result state */
    return( (testComplete == 0) ? -1 : 0 );
}
