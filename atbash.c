#include <ctype.h>

#include "atbash.h"

char a_encipher(char text)
{
    if (isupper(text))
    {
	text += 'Z' - text;
    }
    else if (islower(text))
    {
	text += 'z' - text;	
    }
	    
    return text;
}
char a_decipher(char text)
{
    if (isupper(text))
    {
	
    }
    else if (islower(text))
    {
	
    }
    
    return text;
}
