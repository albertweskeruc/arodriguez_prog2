#ifndef _ARGTOK_
#define _ARGTOK_

// uses all the functions 
char** argtok(char* str);

//Frees all tokens and the array containing the tokens
void free_tokens(char** tokens);

#endif
