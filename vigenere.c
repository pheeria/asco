#include <stdio.h>
#include <string.h>
#include <ctype.h>

void key_overflow(int *key_counter, int key_length);
int changer(int character);

int main(int argc, char *argv[])
{
    char* vigenere = argv[1];
    char* cipher = argv[2];

    int vlen = strlen(vigenere);
    int clen = strlen(cipher);

    printf("vigenere: %s\n", vigenere);
    printf("cipher: %s\n", cipher);

    for (int i = 0, j = 0, to_add = 0; i < vlen; i++, j++)
    {
	key_overflow(&j, clen);
        to_add = changer(cipher[j]);

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

void key_overflow(int *key_counter, int key_length)
{
    if (*key_counter == key_length)
    {
	*key_counter = 0;
    }
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
