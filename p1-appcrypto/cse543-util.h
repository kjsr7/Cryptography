#ifndef CSE543_UTIL_INCLUDED

/**********************************************************************

   File          : cse543_util.h

   Description   : This is the utilities include for the project
                   #2. It contains the functional prototypes for the 
                   needed applications.

   Last Modified : Sun Feb  4 08:42:48 EST 2007
   By            : Trent Jaeger

***********************************************************************/

/* Include Files */
#include <gmp.h>

/* Functional Prototypes */

/**********************************************************************

    Function    : errorMessage
    Description : prints an error mesage to stderr
    Inputs      : msg - pointer to string message
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
int errorMessage( char *msg );

/**********************************************************************

    Function    : warningMessage
    Description : prints an warning mesage to stderr
    Inputs      : msg - pointer to string message
    Outputs     : 0 if successful, -1 if failure

***********************************************************************/
int warningMessage( char *msg );

/**********************************************************************

    Function    : mpzToString
    Description : convert a mpz to a hexidecimal numbes
    Inputs      : str - a double pointer to the string 
                        note: function will allocate buffer
                  no - the number
    Outputs     : the character string

***********************************************************************/
char * mpzToString( char **str, mpz_t no );

#define CSE543_UTIL_INCLUDED
#endif
