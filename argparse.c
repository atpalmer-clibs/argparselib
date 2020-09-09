#include <stdlib.h>
#include <string.h>
#include "argparse.h"

struct argparse *argparse_new(int argc, const char **argv) {
    struct argparse *new = malloc(sizeof *new);
    new->argc = argc;
    new->argv = argv;
    return new;
}

void argparse_free(struct argparse *this) {
    free(this);
}

const char *argparse_progname(struct argparse *this) {
    return argparse_string_at(this, 0);
}

const char *argparse_string_at(struct argparse *this, int pos) {
    if(pos < 0 || pos >= this->argc)
        return NULL;
    return this->argv[pos];
}

int argparse_hasopt(struct argparse *this, const char *opt) {
    for(int i = 1; i < this->argc; ++i) {
        if(strcmp(this->argv[i], opt) == 0)
            return 1;
    }
    return 0;
}

const char *argparse_getopt(struct argparse *this, const char *opt) {
    for(int i = 1; i < this->argc; ++i) {
        if(strcmp(this->argv[i], opt) == 0)
            return argparse_string_at(this, i + 1);
    }
    return NULL;
}
