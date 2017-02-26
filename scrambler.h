#ifndef SCRAMBLER_H
#define SCRAMBLER_H

enum ciphers
{
    atbash = 1 << 0,
    vigenere = 1 << 1
};
void scramble(char *src, char *dst, enum ciphers codes, char *keys[]);
void unscramble(char *src, char *dst, enum ciphers codes, char *keys[]);

#endif
