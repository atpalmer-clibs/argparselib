#ifndef ARGPARSE_H
#define ARGPARSE_H

struct argparse {
    int argc;
    const char **argv;
};

#define ARGPARSE_COUNT(this) ((this)->argc)

struct argparse *argparse_new(int argc, const char **argv);
void argparse_free(struct argparse *this);

const char *argparse_progname(struct argparse *this);
const char *argparse_string_at(struct argparse *this, int pos);
int argparse_hasopt(struct argparse *this, const char *opt);
const char *argparse_getopt(struct argparse *this, const char *opt);

#endif
