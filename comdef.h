#ifndef CATASM_COMDEF_H
#define CATASM_COMDEF_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define VERSION "1.0.0"

#define MAX_LABEL_LENGTH 512
#define MAX_MAP_SIZE 10000
#define MAX_SOURCE_SIZE 100000000

#define IS_NUM(ch) (ch >= '0' && ch <= '9')
#define IS_ALPHA(ch) ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
#define IS_SPACE(ch) (ch == ' ')
#define IS_COMMA(ch) (ch == ',')
#define IS_COLON(ch) (ch == ':')
#define IS_UNDERLINE(ch) (ch == '_')

typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

#endif //CATASM_COMDEF_H
