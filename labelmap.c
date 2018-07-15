#include "labelmap.h"

int IsUnique(LabelMapTable *table, char *label) {
    return !GetLabelAddr(table, label);
}

void InsertNew(LabelMapTable *table, char *label, DWORD addr) {
    assert(strlen(label) < MAX_LABEL_LENGTH);
    assert(table->size < MAX_MAP_SIZE);
    assert(IsUnique(table, label));

    strcpy(table->map[table->size].label, label);
    table->map[table->size].addr = addr;
    table->size += 1;
}

DWORD GetLabelAddr(LabelMapTable *table, char *label) {
    int i;
    for(i = 0; i < table->size; i++) {
        if(strcmp(table->map[i].label, label) == 0) {
            return table->map[i].addr;
        }
    }
    return 0;
}
