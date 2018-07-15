#ifndef CATASM_LABELMAP_H
#define CATASM_LABELMAP_H

#include "comdef.h"

typedef struct tagLabelMap {
    char label[MAX_LABEL_LENGTH];
    DWORD addr;
}LabelMap;

typedef struct tagLabelMapTable {
    size_t size;
    LabelMap map[MAX_MAP_SIZE];
}LabelMapTable;

int IsUnique(LabelMapTable *, char *);
void InsertNew(LabelMapTable *, char *, DWORD);
DWORD GetLabelAddr(LabelMapTable *, char *);

#endif //CATASM_LABELMAP_H
