#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "vigenere.h"
#include "atbash.h"

int main(int argc, char *argv[])
{
    FILE *src_file = fopen(argv[1], "r");
    FILE *dst_file = fopen("output.txt", "w");

    if (src_file == NULL)
    {
	fclose(dst_file);
    }
    else
    {
	int c = 0, i = 0;
	char *cipher = argv[2];
	int clen = strlen(cipher);
	
	while ((c = getc(src_file)) != EOF)
	{
	    if (isalpha(c))
	    {
		c = v_encipher(c, cipher[i++]);
		c = a_encipher(c);
	    }
	    putc(c, dst_file);

	    i %= clen;
	}
	fclose(src_file);
	fclose(dst_file);
    }
}
