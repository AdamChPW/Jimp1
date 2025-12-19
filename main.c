#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    FILE *in = argc > 1 ? fopen(argv[1],"r") : stdin;
    return 0;
}