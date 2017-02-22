#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    FILE *fdp = fopen("output.txt", "w");

    int c;
    while ((c = getc(fp)) != EOF)
    {
	putc(c, fdp);
    }
    fclose(fp);
    fclose(fdp);    
}
