#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef CATASM_COMDEF_H
#define CATASM_COMDEF_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>

#define VERSION "0.6.2"

#define MAX_STRING_LENGTH 512
#define MAX_MAP_SIZE 10000
#define MAX_SOURCE_SIZE 100000000

#define IS_TERMINATOR(ch) (ch == '\0' || ch == '\n')
#define IS_NUM(ch) (ch >= '0' && ch <= '9')
#define IS_PLUS(ch) (ch == '+')
#define IS_MINUS(ch) (ch == '-')
#define IS_ALPHA(ch) ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
#define IS_POUND(ch) (ch == '#')
#define IS_DOT(ch) (ch == '.')
#define IS_SPACE(ch) (ch == ' ' || ch == '\t')
#define IS_COMMA(ch) (ch == ',')
#define IS_SQ(ch) (ch == '\'') // single quotation
#define IS_DQ(ch) (ch == '\"') // double quotation
#define IS_BS(ch) (ch == '\\') // back-slash
#define IS_COLON(ch) (ch == ':')
#define IS_UNDERLINE(ch) (ch == '_')
#define IS_REG_PREFIX(ch) (ch == 'R' || ch == 'r')
#define IS_B_SUFFIX(ch) (ch == 'B' || ch == 'b')
#define IS_O_SUFFIX(ch) (ch == 'O' || ch == 'o')
#define IS_D_SUFFIX(ch) (ch == 'D' || ch == 'd')
#define IS_H_SUFFIX(ch) (ch == 'H' || ch == 'h')

#define DIFF(a, b) (a > b ? a - b : b - a)

#define PRINT_ERROR(str) fprintf(stderr, "[file: %s, line: %d], Error: %s\n", input_path, current_line, str)
#define PRINT_WARNING(str) fprintf(stderr, "[file: %s, line: %d], Warning: %s\n", input_path, current_line, str)

typedef unsigned int Dword;
typedef unsigned short Word;
typedef unsigned char Byte;

extern char *input_path, *output_path;
extern int current_line;
extern char current_error[500];
extern char current_warning[500];

#endif // CATASM_COMDEF_H
