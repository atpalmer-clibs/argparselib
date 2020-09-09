#include <stdio.h>
#include "argparse.h"


int main(int argc, const char **argv) {
    struct argparse *parser = argparse_new(argc, argv);
    printf("Arg count: %d\n", ARGPARSE_COUNT(parser));
    printf("Program name: %s\n", argparse_progname(parser));
    for(int i = 0; i < ARGPARSE_COUNT(parser); ++i) {
        printf("Arg %d: %s\n", i, argparse_string_at(parser, i));
    }
    printf("--value: %s\n", argparse_getopt(parser, "--value"));
    printf("--flag: %s\n", argparse_hasopt(parser, "--flag") ? "True" : "False");
    argparse_free(parser);
}
