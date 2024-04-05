//Includes
#include <stdio.h>
#include <stdlib.h>

//Constants
#define NO_ERROR 0
#define ERROR_INVALID_ARGUMENTS -1
#define ERROR_FILE_NOT_FOUND -2
#define ERROR_FILE_READ_FAILED -3
#define ERROR_FILE_CLOSE_FAILED -4
#define MAX_FILE_LEN 4096

//Functions Prototypes
int iTreatFileError( int iError );

//-----------------------------------------------------------------------------
// Procedure vTreatFileError
//-----------------------------------------------------------------------------
int iTreatFileError( int iError ) {
  switch (iError)
  {
    case ERROR_INVALID_ARGUMENTS:
      printf( "Error invalidad arguments" );
      iError = -1;
    break;

    case ERROR_FILE_READ_FAILED:
      printf( "Error reading file" );
    break;

    case ERROR_FILE_CLOSE_FAILED:
      printf( "Error closing file" );
    break;

    case ERROR_FILE_NOT_FOUND:
      printf( "Error opening file" );
      iError = -1;
break;

    default:
      printf( "Error: Unknown error code %d\n", iError );
    break;
  } //endswitch
  
  return (iError);
  
} //end vTreatFileError()
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function Comments
// name: main
// Arguments: int argc, char *argv[]
// que es lo que hace?....
//-----------------------------------------------------------------------------
int main( int argc, char *argv[] ) {
  int iFD, i;
  char cBuffer[MAX_FILE_LEN]; // Buffer to store read data
  int siBytesRead;
  int iCharCount = 0;

    if (argc != 2) {
        return (iTreatFileError( ERROR_INVALID_ARGUMENTS ));
    } //endif
  
    //Open the file using open() system call
    iFD = open( argv[1], 0 );
    if (iFD == -1) {
        return (iTreatFileError( ERROR_FILE_NOT_FOUND ));
    } //endif

    //Read from the file using read() system call
    //revisar, porque se debe LEER Y PROCESAR BYTE A BYTE...
    while ((siBytesRead = read( iFD, cBuffer, sizeof( cBuffer ) )) > 0) {
        //Count characters in the buffer
        for (i = 0; i < siBytesRead; i++) {
            if (cBuffer[i] != '\0') {
                iCharCount++;
            } //endif
        } //endfor
    } //endwhile 
  
    if (siBytesRead == -1) {
      close( iFD );
      return (iTreatFileError( ERROR_FILE_READ_FAILED ));
    } //endif 

    //Close the file using close() system call
    if (close( iFD ) == -1) {
      return (iTreatFileError( ERROR_FILE_CLOSE_FAILED ));
    } //endif

    printf( "Total characters in the file: %d\n", iCharCount );

    return (NO_ERROR);
} //endmain
