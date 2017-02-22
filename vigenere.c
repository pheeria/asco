#include <stdio.h>
#include <string.h>
#include <ctype.h>

void key_overflow(int *key_counter, int key_length);
int changer(int character);
void cipher(char *text, char *key);
void decipher(char *text, char *key);

int main(int argc, char *argv[])
{
    char* vigenere = argv[1];
    char* pcipher = argv[2];

    printf("vigenere: %s\n", vigenere);
    printf("cipher: %s\n", pcipher);

    cipher(vigenere, pcipher);
    printf("ciphered: %s\n", vigenere);

    decipher(vigenere, pcipher);
    printf("deciphered: %s\n", vigenere);
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
void cipher(char *text, char *key)
{
    int vlen = strlen(text);
    int clen = strlen(key);

    for (int i = 0, j = 0, to_add = 0; i < vlen; i++, j++)
    {
	key_overflow(&j, clen);
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
void decipher(char *text, char *key)
{
    int vlen = strlen(text);
    int clen = strlen(key);

    for (int i = 0, j = 0, to_add = 0; i < vlen; i++, j++)
    {
	key_overflow(&j, clen);
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
