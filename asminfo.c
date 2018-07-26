#include "asminfo.h"

Fake_inst_map_info fake_inst_info[] = {
{ "byte", AT_BYTE_NUM },
{ "word", AT_WORD_NUM },
{ "dword", AT_DWORD_NUM },
{ "bytes", AT_NUM, AT_BYTE_NUM },
{ "words", AT_NUM, AT_WORD_NUM },
{ "dwords", AT_NUM, AT_DWORD_NUM },
{ "string", AT_STRING },
{ "strings", AT_NUM, AT_STRING}
};

Inst_map_info inst_info[] = {
{ "nop", 0 },
{ "copy", 2, AT_REGISTER, AT_REGISTER },
{ "copy", 2, AT_REGISTER, AT_DWORD_NUM },
{ "read", 2, AT_REGISTER, AT_REGISTER },
{ "read", 2, AT_REGISTER, AT_ADDRESS },
{ "write", 2, AT_REGISTER, AT_REGISTER },
{ "write", 2, AT_ADDRESS, AT_REGISTER },
{ "push", 1, AT_DWORD_NUM },
{ "push", 1, AT_REGISTER },
{ "pop", 1, AT_REGISTER },
{ "add", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "add", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "add", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "add", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "sub", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "sub", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "sub", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "sub", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "mul", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "mul", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "mul", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "mul", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "div", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "div", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "div", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "div", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "mod", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "mod", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "mod", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "mod", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "jump", 1, AT_REGISTER },
{ "jump", 1, AT_ADDRESS },
{ "jpz", 2, AT_REGISTER, AT_REGISTER },
{ "jpz", 2, AT_ADDRESS, AT_REGISTER },
{ "jpnz", 2, AT_REGISTER, AT_REGISTER },
{ "jpnz", 2, AT_ADDRESS, AT_REGISTER },
{ "jpe", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "jpe", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "jpe", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "jpe", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "jpe", 3, AT_ADDRESS, AT_REGISTER, AT_REGISTER },
{ "jpe", 3, AT_ADDRESS, AT_REGISTER, AT_DWORD_NUM },
{ "jpe", 3, AT_ADDRESS, AT_DWORD_NUM, AT_REGISTER },
{ "jpe", 3, AT_ADDRESS, AT_DWORD_NUM, AT_DWORD_NUM },
{ "jpne", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "jpne", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "jpne", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "jpne", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "jpne", 3, AT_ADDRESS, AT_REGISTER, AT_REGISTER },
{ "jpne", 3, AT_ADDRESS, AT_REGISTER, AT_DWORD_NUM },
{ "jpne", 3, AT_ADDRESS, AT_DWORD_NUM, AT_REGISTER },
{ "jpne", 3, AT_ADDRESS, AT_DWORD_NUM, AT_DWORD_NUM },
{ "call", 1, AT_ADDRESS },
{ "ret", 0 },
{ "not", 2, AT_REGISTER, AT_REGISTER },
{ "not", 2, AT_REGISTER, AT_DWORD_NUM },
{ "and", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "and", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "and", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "and", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "or", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "or", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "or", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "or", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "xor", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "xor", 3, AT_REGISTER, AT_REGISTER, AT_DWORD_NUM },
{ "xor", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "xor", 3, AT_REGISTER, AT_DWORD_NUM, AT_DWORD_NUM },
{ "shl", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "shl", 3, AT_REGISTER, AT_REGISTER, AT_BYTE_NUM },
{ "shl", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "shl", 3, AT_REGISTER, AT_DWORD_NUM, AT_BYTE_NUM },
{ "shr", 3, AT_REGISTER, AT_REGISTER, AT_REGISTER },
{ "shr", 3, AT_REGISTER, AT_REGISTER, AT_BYTE_NUM },
{ "shr", 3, AT_REGISTER, AT_DWORD_NUM, AT_REGISTER },
{ "shr", 3, AT_REGISTER, AT_DWORD_NUM, AT_BYTE_NUM },
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
	for (i = 0; i < sizeof(inst_info) / sizeof(Inst_map_info); i++) {
		if (strcmpci(inst, inst_info[i].inst) == 0) {
			return inst_info[i].argnum;
		}
	}
	return -1;
}

// match the instruction information, if not then return 0, otherwise return non-zero.
int match_inst_info(char *inst, int argnum, ...) {
	va_list val;
	int i, j;

	va_start(val, argnum);

	for (i = 0; i < sizeof(inst_info) / sizeof(Inst_map_info); i++) {
		if (strcmpci(inst, inst_info[i].inst) != 0) {
			goto next;
		}

		va_start(val, argnum);
		for (j = 0; j < argnum; j++) {
			if (inst_info[i].argtype[j] != va_arg(val, int)) {
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
