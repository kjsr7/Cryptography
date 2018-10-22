/**********************************************************************

   File          : cse543-util.c

   Description   : This is a set of utility functions for the CSE543
                   projects. (see .h for applications)

   Last Modified : Sun Feb  4 08:42:48 EST 2007
   By            : Trent Jaeger

***********************************************************************/

/* Include Files */
#include <stdio.h>
#include <strings.h>
#include <cse543-util.h>

/* Functions */

/**********************************************************************

    Function    : errorMessage
    Description : prints an error mesage to stderr
    Inputs      : msg - pointer to string message
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int errorMessage( char *msg ) 
{
     /* Print message and return */
     fprintf( stderr, "CSE497 Error: %s\n", msg );
     return( 0 );
}

/**********************************************************************

    Function    : warningMessage
    Description : prints an warning mesage to stderr
    Inputs      : msg - pointer to string message
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/

int warningMessage( char *msg ) 
{
     /* Print message and return */
     fprintf( stderr, "CSE497 Warning: %s\n", msg );
     return( 0 );
}

/**********************************************************************

    Function    : mpzToString
    Description : convert a mpz to a hexidecimal numbes
    Inputs      : str - a double pointer to the string 
                        note: function will allocate buffer
                  no - the number
    Outputs     : the character string

***********************************************************************/

char * mpzToString( char **str, mpz_t no )
{
     /* Check for possible memory leak */
     if ( *str != NULL ) 
     {
          /* Send warning */
          warningMessage( "possible memory leak in mpzToString: input"
                           " string should be null." );
     }

     /* clear out string, then print to string */
     *str = NULL;
     return( mpz_get_str (*str, 16, no) );
}
