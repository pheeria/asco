#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include "scrambler.h"

static int decipher_flag;
void parse(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    /* FILE *src_file = fopen(argv[1], "r"); */
    /* FILE *dst_file = fopen("q.asco", "w"); */

    /* if (src_file == NULL) */
    /* { */
    /* 	fclose(dst_file); */
    /* } */
    /* else */
    /* { */
    /* 	int c = 0, i = 0; */
    /* 	char *cipher = argv[2]; */
    /* 	int clen = strlen(cipher); */
	
    /* 	while ((c = getc(src_file)) != EOF) */
    /* 	{ */
    /* 	    c = scramble(c, cipher[i++]); */
    /* 	    putc(c, dst_file); */
    /* 	    i %= clen; */
    /* 	} */
    /* 	fclose(src_file); */
    /* 	fclose(dst_file); */
    /* } */

    parse(argc, argv);
}

void parse(int argc, char *argv[])
{
    static struct option long_options[] =
    {
	{"encipher", no_argument, &decipher_flag, 0},
	{"decipher", no_argument, &decipher_flag, 1},
	{"output", required_argument, 0, 'o'},
	{"atbash", no_argument, 0, 'a'},
	{"vigenere", required_argument, 0, 'v'}
    };

    enum ciphers codes = 0;
    printf("filename: %s\n", argv[1]);
    int option, option_index;

    char *output = "q.asco", *vkey;
    while ((option = getopt_long(argc, argv, "ao:v:", long_options, &option_index)) != -1)
    {
	switch(option)
	{
	case 'a':
	    codes |= atbash;
	    break;
	case 'v':
	    codes |= vigenere;
	    vkey = optarg;
	    break;
	case 'o':
	    output = optarg;
	    break;
	}
    }
    printf("b: %d\n", codes);

    if (codes & vigenere)
	printf("vigenere!! Key: %s\n", vkey);
    if (codes & atbash)
	printf("atbash!!\n");
    
    if (decipher_flag)
	printf("Deciphering!\n");
    else
	printf("Enciphering!\n");

    printf("output: %s\n", output);
}
