#include "asminfo.h"

Inst_map_info instinfo[] = {
{ "nop", 0 },
{ "copy", 2, AT_REGISTER, AT_REGISTER },
{ "copy", 2, AT_REGISTER, AT_EXTEND_NUM },
{ "read", 2, AT_REGISTER, AT_REGISTER },
{ "read", 2, AT_REGISTER, AT_ADDRESS },
{ "write", 2, AT_REGISTER, AT_REGISTER },
{ "write", 2, AT_ADDRESS, AT_REGISTER },
{ "push", 1, AT_EXTEND_NUM },
{ "push", 1, AT_REGISTER },
{ "pop", 1, AT_REGISTER },
{ "add", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "add", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "add", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "add", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "sub", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "sub", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "sub", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "sub", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "mul", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "mul", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "mul", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "mul", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "div", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "div", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "div", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "div", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "mod", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "mod", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "mod", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "mod", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "jump", 1, AT_REGISTER },
{ "jump", 1, AT_ADDRESS },
{ "jpz", 2, AT_REGISTER, AT_REGISTER },
{ "jpz", 2, AT_ADDRESS, AT_REGISTER },
{ "jpnz", 2, AT_REGISTER, AT_REGISTER },
{ "jpnz", 2, AT_ADDRESS, AT_REGISTER },
{ "jpe", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "jpe", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "jpe", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "jpe", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "jpe", 3, AT_ADDRESS, AT_REGISTER, AT_REGISTER },
{ "jpe", 3, AT_ADDRESS, AT_REGISTER, AT_EXTEND_NUM },
{ "jpe", 3, AT_ADDRESS, AT_EXTEND_NUM, AT_REGISTER },
{ "jpe", 3, AT_ADDRESS, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "jpne", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "jpne", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "jpne", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "jpne", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "jpne", 3, AT_ADDRESS, AT_REGISTER, AT_REGISTER },
{ "jpne", 3, AT_ADDRESS, AT_REGISTER, AT_EXTEND_NUM },
{ "jpne", 3, AT_ADDRESS, AT_EXTEND_NUM, AT_REGISTER },
{ "jpne", 3, AT_ADDRESS, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "call", 1, AT_ADDRESS },
{ "ret", 0 },
{ "not", 2, AT_REGISTER, AT_REGISTER },
{ "not", 2, AT_REGISTER, AT_EXTEND_NUM },
{ "and", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "and", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "and", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "and", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "or", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "or", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "or", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "or", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "xor", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "xor", 3, AT_REGISTER, AT_REGISTER, AT_EXTEND_NUM },
{ "xor", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "xor", 3, AT_REGISTER, AT_EXTEND_NUM, AT_EXTEND_NUM },
{ "shl", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "shl", 3, AT_REGISTER, AT_REGISTER, AT_INLINE_NUM },
{ "shl", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "shl", 3, AT_REGISTER, AT_EXTEND_NUM, AT_INLINE_NUM },
{ "shr", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "shr", 3, AT_REGISTER, AT_REGISTER, AT_INLINE_NUM },
{ "shr", 3, AT_REGISTER, AT_EXTEND_NUM, AT_REGISTER },
{ "shr", 3, AT_REGISTER, AT_EXTEND_NUM, AT_INLINE_NUM },
{ "inc", 1, AT_REGISTER },
{ "dec", 1, AT_REGISTER }
};

// strcmp function (case-insensitive).
int strcmpci(char *s1, char *s2) {
	int i;
	for (i = 0; s1[i] != 0 && s2[i] != 0; i++) {
		if (s1[i] == s2[i] || (IS_ALPHA(s1[1]) && IS_ALPHA(s2[i]) && DIFF(s1[i], s2[i]) == 32)) {
			continue;
		}
		break;
	}
	return s1[i] - s2[i];
}

// return the number of argument, if inst is not exist, return -1.
int get_inst_arg_num(char *inst) {
	int i;
	for (i = 0; i < sizeof(instinfo) / sizeof(Inst_map_info); i++) {
		if (strcmpci(inst, instinfo[i].inst) == 0) {
			return instinfo[i].argnum;
		}
	}
	return -1;
}

// match the instruction information, if not then return 0, otherwise return non-zero.
int match_inst_info(char *inst, int argnum, ...) {
	va_list val;
	int i, j;

	va_start(val, argnum);

	for (i = 0; i < sizeof(instinfo) / sizeof(Inst_map_info); i++) {
		if (strcmpci(inst, instinfo[i].inst) != 0) {
			goto next;
		}

		va_start(val, argnum);
		for (j = 0; j < argnum; j++) {
			if (instinfo[i].argtype[j] != va_arg(val, int)) {
				goto next;
			}
		}
		return 1;
	next:
		continue;
	}

	va_end(val);
	return 0;
}
