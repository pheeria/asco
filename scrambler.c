#include <ctype.h>

#include "vigenere.h"
#include "atbash.h"

char scramble(char character, char vigenere)
{
    if (isalpha(character))
    {
	character = v_encipher(character, vigenere);
	character = a_encipher(character);
    }
    return character;
}
