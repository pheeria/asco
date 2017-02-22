#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char* vigenere = argv[1];
    char* cipher = argv[2];

    int vlen = strlen(vigenere);
    int clen = strlen(cipher);

    printf("vigenere: %s\n", vigenere);
    printf("cipher: %s\n", cipher);

    for (int i = 0, j = 0; i < vlen; i++, j++)
    {
	if (j == clen)
	{
	    j = 0;
	}

	int to_add = 0;
	if (isupper(cipher[j]))
	{
	    to_add = (cipher[j] - 'A');
	}
	else if (islower(cipher[j]))
	{
	    to_add = (cipher[j] - 'a');
	}
	
	if (isupper(vigenere[i]))
	{
	    vigenere[i] += to_add;
	    if (!isupper(vigenere[i]))
	    {
		vigenere[i] -= 26;
	    }
	}
	else if (islower(vigenere[i]))
	{
	    vigenere[i] += to_add;
	    if (!islower(vigenere[i]))
	    {
		vigenere[i] -= 26;
	    }
	}
    }

    printf("ciphered: %s\n", vigenere);

}
