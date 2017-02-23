#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "vigenere.h"

int changer(int character);

int main(int argc, char *argv[])
{
    char* vigenere = argv[1];
    char* pcipher = argv[2];

    printf("vigenere: %s\n", vigenere);
    printf("cipher: %s\n", pcipher);

    v_encipher(vigenere, pcipher);
    printf("enciphered: %s\n", vigenere);

    v_decipher(vigenere, pcipher);
    printf("deciphered: %s\n", vigenere);
}

int changer(int character)
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
void v_encipher(char *text, char *key)
{
    int vlen = strlen(text);
    int clen = strlen(key);

    for (int i = 0, j = 0, to_add = 0; i < vlen; i++, j++)
    {
	j = j % clen;
        to_add = changer(key[j]);

	if (isupper(text[i]))
	{
	    text[i] += to_add;
	    if (!isupper(text[i]))
	    {
		text[i] -= 26;
	    }
	}
	else if (islower(text[i]))
	{
	    text[i] += to_add;
	    if (!islower(text[i]))
	    {
		text[i] -= 26;
	    }
	}
    }
}
void v_decipher(char *text, char *key)
{
    int vlen = strlen(text);
    int clen = strlen(key);

    for (int i = 0, j = 0, to_add = 0; i < vlen; i++, j++)
    {
	j = j % clen;
        to_add = changer(key[j]);

	if (isupper(text[i]))
	{
	    text[i] -= to_add;
	    if (!isupper(text[i]))
	    {
		text[i] += 26;
	    }
	}
	else if (islower(text[i]))
	{
	    text[i] -= to_add;
	    if (!islower(text[i]))
	    {
		text[i] += 26;
	    }
	}
    }
}
