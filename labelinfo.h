#pragma once
#ifndef CATASM_LABELINFO_H
#define CATASM_LABELINFO_H

#include "comdef.h"

typedef struct {
	char label[MAX_STRING_LENGTH];
	Dword addr;
}Label_info;

typedef struct {
	size_t size;
	Label_info map[MAX_MAP_SIZE];
}Label_info_table;

int is_unique(Label_info_table *, char *);
void insert_new_map(Label_info_table *, char *, Dword);
Dword get_label_address(Label_info_table *, char *);

#endif // CATASM_LABELINFO_H
