#include <ctype.h>

#include "atbash.h"

char a_encipher(char text)
{
    if (isupper(text))
    {
	text = 'A' + 'Z' - text;
    }
    else if (islower(text))
    {
	text = 'a' + 'z' - text;	
    }
	    
    return text;
}
char a_decipher(char text)
{
    return a_encipher(text);
}
