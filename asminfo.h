#pragma once
#ifndef CATASM_ASMINFO_H
#define CATASM_ASMINFO_H
#include "comdef.h"

typedef enum {
	AT_NULL,
	AT_REGISTER,
	AT_INLINE_NUM,
	AT_EXTEND_NUM,
	AT_ADDRESS,
	AT_NUM,
	AT_LABEL_NAME
}Arg_type;

typedef struct {
	char inst[10];
	int argnum;
	Arg_type argtype[10];
}Inst_map_info;

typedef struct {
	Arg_type type;
	union {
		Byte reg;
		Byte inline_num;
		Dword extend_num;
		Dword address;
		Dword num;
		char label_name[MAX_LABEL_LENGTH];
	}u;
}Arg_info;

typedef struct {
	char name[10];
	int argnum;
	Arg_info arg[3];
}Instruction;

typedef struct {
	char name[MAX_LABEL_LENGTH];
}Label;

typedef struct {
	Label label;
	Instruction inst;
}Label_instruction;

typedef enum {
	RT_NULL,
	RT_LABEL,
	RT_INSTRUCTION,
	RT_PRECODE,
	RT_LABEL_AND_INSTRUCTION
}Row_type;

typedef struct {
	Row_type type;
	union {
		Instruction inst;
		Label label;
		Label_instruction label_inst;
		// TODO Precode
	}u;
}Row_info;

extern Inst_map_info instinfo[];

int strcmpci(char *s1, char *s2);
int get_inst_arg_num(char *inst);
int match_inst_info(char *inst, int argnum, ...);

#endif
