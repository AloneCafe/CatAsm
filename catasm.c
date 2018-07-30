#include "asminfo.h"
#include "labelinfo.h"
#include "parse.h"

char *input_path, *output_path;
int current_line;
char current_error[500];
char current_warning[500];

int main(int argc, char **argv) {
	int i;

	if (argc == 1) {
		fprintf(stdout, "Cat Microcomputer Assembler " "(Built at " __DATE__ " " __TIME__ ")\n" "Use \"-h\" option to print help information.\n");
		return 1;
	}

	for (i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][2] == 0) {
				switch (argv[i][1]) {
				case 'o':
					if ((output_path = argv[i + 1]) == NULL) {
						fprintf(stderr, "Error: \"-o\" must follow with binary file output path!\n");
						return 1;
					}
					i++;
					break;

				case 'h':
					fprintf(stdout, "Cat Microcomputer Assembler " "(Built at " __DATE__ " " __TIME__ ")\n" "USAGE: catasm [option] <inputs>\n" "OPTIONS:\n" "-o\tSet output binary file path\n" "-h\tPrint this help information\n");
					return 0;

				case 'v':
					fprintf(stdout, "Cat Microcomputer Assembler " "(Built at " __DATE__ " " __TIME__ ")\n" "version: %s\n", VERSION);
					return 0;

				default:
					fprintf(stderr, "Error: unrecognized option \"%s\" !\n", argv[i]);
					return 1;
				}
			}
			else {
				fprintf(stderr, "Error: option \"%s\" is too long!\n", argv[i]);
				return 1;
			}
		}
		else {
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
	if ((fp = fopen(input_path, "r")) == NULL) {
		fprintf(stderr, "Error: can not open input source file \"%s\"\n", input_path);
		return 1;
	}

	char buffer[1000], *p;
	Row_info row = { 0 };
	long n;
	fseek(fp, SEEK_SET, 0);
	fseek(fp, SEEK_SET, SEEK_END);
	n = ftell(fp);
	fseek(fp, SEEK_SET, 0);

	current_line = 1;
	while (!feof(fp)) {
		p = fgets(buffer, sizeof(buffer) / sizeof(char), fp);
		if (p == NULL) continue;
		// TODO FSM logic
		if (parse_line(buffer, &row) == 0) {
			fprintf(stderr, "assembly terminated!\n");
			return -1;
		}

		print_row_info(&row);
		current_line += 1;
	}

	fclose(fp);
	//free(buffer);

	return 0;
}
