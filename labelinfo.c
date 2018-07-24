#include "labelinfo.h"

int is_unique(Label_info_table *table, char *label) {
	return !get_label_address(table, label);
}

void insert_new_map(Label_info_table *table, char *label, Dword addr) {
	assert(strlen(label) < MAX_LABEL_LENGTH);
	assert(table->size < MAX_MAP_SIZE);
	assert(is_unique(table, label));

	strcpy(table->map[table->size].label, label);
	table->map[table->size].addr = addr;
	table->size += 1;
}

Dword get_label_address(Label_info_table *table, char *label) {
	size_t i;
	for (i = 0; i < table->size; i++) {
		if (strcmp(table->map[i].label, label) == 0) {
			return table->map[i].addr;
		}
	}
	return -1;
}

