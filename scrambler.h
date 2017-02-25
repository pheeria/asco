#ifndef SCRAMBLER_H
#define SCRAMBLER_H

enum ciphers
{
    atbash = 1 << 0,
    vigenere = 1 << 1
};
char scramble(char character, char vigenere);

#endif
