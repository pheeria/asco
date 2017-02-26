#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "scrambler.h"
#include "vigenere.h"
#include "atbash.h"

void scramble(char *src, char *dst, enum ciphers codes, char *keys[])
{
    printf("src: %s\n", src);
    printf("dst: %s\n", dst);
    FILE *src_file = fopen(src, "r");
    FILE *dst_file = fopen(dst, "w");

    if (src_file == NULL)
    {
    	fclose(dst_file);
    }
    else
    {
    	int character = 0, i = 0;
    	char *cipher = keys[0];
	printf("cipher: %s\n", cipher);
    	int clen = strlen(cipher);
	
    	while ((character = getc(src_file)) != EOF)
    	{
	    printf("char %c\n", character);
	    if (isalpha(character))
	    {
		if (codes & vigenere)
		{
		    character = v_encipher(character, cipher[i++]);
		}
		if (codes & atbash)
		{
		    character = a_encipher(character);
		}
	    }
    	    putc(character, dst_file);
    	    i %= clen;
    	}
    	fclose(src_file);
    	fclose(dst_file);
    }
}
