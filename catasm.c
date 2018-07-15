#include "comdef.h"
#include "labelmap.h"


int IsLabel(char *label, char *ch) {
    int state = 0, i;
    for(i = 0; ch[i] != '\n' && ch[i] != '\0'; i++) {

        if (state == 0) {
            if (IS_ALPHA(ch[i]) || IS_UNDERLINE(ch[i])) {
                *(label++) = ch[i];
                state = 1;
            } else if (IS_SPACE(ch[i])) {
                continue;
            } else {
                state = 5;
            }
        } else if (state == 1) {
            if (IS_ALPHA(ch[i]) || IS_UNDERLINE(ch[i]) || IS_NUM(ch[i])) {
                *(label++) = ch[i];
                state = 2;
            } else {
                state = 5;
            }
        } else if(state == 2) {
            if (IS_ALPHA(ch[i]) || IS_UNDERLINE(ch[i]) || IS_NUM(ch[i])) {
                *(label++) = ch[i];
                continue;
            } else if (IS_SPACE(ch[i])) {
                state = 4;
            } else if (IS_COLON(ch[i])) {
                state = 3;
            } else {
                state = 5;
            }
        } else if (state == 4) {
            if (IS_COLON(ch[i])) {
                state = 3;
            } else if (IS_SPACE(ch[i])) {
                continue;
            } else {
                state = 5;
            }
        } else if (state == 3) {
            if (IS_SPACE(ch[i])) {
                continue;
            } else {
                state = 5;
            }
        } else if (state == 5) {
            return 0;
        }
    }

    if(state == 3)
        return 1;
    else
        return 0;
}

int main(int argc, char **argv) {
    char *output_path = NULL, *input_path = NULL;
    int i;

    if (argc == 1) {
        fprintf(stdout, "Cat Microcomputer Assembler\n" "Use \"-h\" option to print help information.\n");
        return 1;
    }

    for(i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][2] == 0) {
                switch(argv[i][1]) {
                    case 'o':
                        if ((output_path = argv[i + 1]) == NULL) {
                            fprintf(stderr, "Error: \"-o\" must follow with binary file output path!\n");
                            return 1;
                        }
                        i++;
                        break;

                    case 'h':
                        fprintf(stdout, "Cat Microcomputer Assembler\n" "USAGE: catasm [option] <inputs>\n" "OPTIONS:\n" "-o\tSet output binary file path\n" "-h\tPrint this help information\n");
                        break;

                    case 'v':
                        fprintf(stdout, "Cat Microcomputer Assembler %s\n", VERSION);
                        break;

                    default:
                        fprintf(stderr, "Error: unrecognized option \"%s\" !\n", argv[i]);
                        return 1;
                }
            } else {
                fprintf(stderr, "Error: option \"%s\" is too long!\n", argv[i]);
                return 1;
            }
        } else {
            if (input_path) {
                fprintf(stderr, "Error: assembler can only accept one input source file!\n");
                return 1;
            }
            input_path = argv[i];
        }
    }

    if (!input_path) { fprintf(stderr, "Error: no input source file specified!\n"); return 1; }
    if (!output_path) { fprintf(stderr, "Error: no output binary file specified!\n"); return 1; }

    FILE *fp;
    if((fp = fopen(input_path, "r")) == NULL) {
        fprintf(stderr, "Error: can not open input source file \"%s\"\n", input_path);
        return 1;
    }

    //char *buffer = (char *)malloc(sizeof(char) * MAX_SOURCE_SIZE);
    char buffer[1000], *p;
    char label[1000];
    long n;
    int j;
    fseek(fp, SEEK_SET, 0);
    fseek(fp, SEEK_SET, SEEK_END);
    n = ftell(fp);
    fseek(fp, SEEK_SET, 0);

    while (!feof(fp)) {
        p = fgets(buffer, sizeof(buffer) / sizeof(char), fp);
        if (p == NULL) continue;
        // TODO FSM logic
        j = IsLabel(label, "abc123 4 : ");

    }

    fclose(fp);
    //free(buffer);

    return 0;
}
