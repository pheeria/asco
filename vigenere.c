#include <ctype.h>

#include "vigenere.h"

int shifter(int character)
{
    int result;
    if (isupper(character))
    {
	result = character - 'A';
    }
    else if (islower(character))
    {
	result = character - 'a';
    }
    else
    {
	result = 0;
    }
    return result;
}
char v_encipher(char text, char key)
{
    if (isupper(text))
    {
	text += shifter(key);
	if (!isupper(text))
	{
	    text -= 26;
	}
    }
    else if (islower(text))
    {
	text += shifter(key);
	if (!islower(text))
	{
	    text -= 26;
	}
    }
    return text;
}
char v_decipher(char text, char key)
{
    if (isupper(text))
    {
	text -= shifter(key);
	if (!isupper(text))
	{
	    text += 26;
	}
    }
    else if (islower(text))
    {
	text -= shifter(key);
	if (!islower(text))
	{
	    text += 26;
	}
    }
    return text;
}
