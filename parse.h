#pragma once
#ifndef CATASM_PARSE_H
#define CATASM_PARSE_H
#include "comdef.h"
#include "asminfo.h"

int bin_str_to_num(char *ch, int *num);
int oct_str_to_num(char *ch, int *num);
int dec_str_to_num(char *ch, int *num);
int hex_str_to_num(char *ch, int *num);
int str_to_reg(char *ch, Byte *reg);
int escape_str_to_num(char *ch, int *res);
int parse_arg(char *ch, Arg_info *arginfo);
int parse_line(char *ch, Row_info *row);
void print_row_info(Row_info *row);
void print_arg_info(Arg_info *arg);

#endif // CATASM_PARSE_H
