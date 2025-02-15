#ifndef TABELA_DE_SIMBOLOS_H
#define TABELA_DE_SIMBOLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Symbol {
    char *name;
    char *type;
    struct Symbol *next;
} Symbol;

void insertSymbol(char *name, char *type);
Symbol *lookupSymbol(char *name);
void checkVariablesDeclared(int count, ...);
void checkVariableType(char *name, const char *expectedType);
void printSymbolTable();

#endif
