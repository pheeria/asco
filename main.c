#include <stdio.h>
#include <getopt.h>

#include "scrambler.h"

static int decipher_flag;
void parse(int argc, char *argv[]);

int main(int argc, char *argv[])
{
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

    char *filename = argv[1];
    char *output = "q.asco";

    enum ciphers codes = 0;
    char *keywords[1];
    int option, option_index;
    while ((option = getopt_long(argc, argv, "ao:v:", long_options, &option_index)) != -1)
    {
	switch(option)
	{
	    case 'a':
		codes |= atbash;
		break;
	    case 'v':
		codes |= vigenere;
		keywords[0] = optarg;
		break;
	    case 'o':
		output = optarg;
		break;
	}
    }
    printf("b: %d\n", codes);

    if (codes & vigenere)
	printf("vigenere!! Key: %s\n", keywords[0]);
    if (codes & atbash)
	printf("atbash!!\n");
    
    printf("output: %s\n", output);
    
    if (decipher_flag)
    {
	printf("Deciphering!\n");
	unscramble(filename, output, codes, keywords);
    }
    else
    {
	printf("Enciphering!\n");
	scramble(filename, output, codes, keywords);
    }
}
