#include "symbol_table.h"

Symbol *symbolTable = NULL;

void insertSymbol(char *name, char *type) {
    if (lookupSymbol(name) != NULL) {
        printf("Erro Semântico: Variável '%s' já declarada!\n", name);
        exit(1);
    }

    Symbol *newSymbol = (Symbol *)malloc(sizeof(Symbol));
    newSymbol->name = strdup(name);
    newSymbol->type = strdup(type);
    newSymbol->next = symbolTable;
    symbolTable = newSymbol;

    printf("[DEBUG] Variável '%s' do tipo '%s' adicionada à tabela de símbolos.\n", name, type);
}

Symbol *lookupSymbol(char *name) {
    Symbol *current = symbolTable;
    while (current) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void checkVariableType(char *name, const char *expectedType) {
    Symbol *symbol = lookupSymbol(name);
    if (symbol == NULL) {
        printf("Erro Semântico: Variável '%s' não foi declarada antes do uso.\n", name);
        exit(1);
    }

    if (strcmp(symbol->type, expectedType) != 0) {
        printf("Erro Semântico: Variável '%s' esperava tipo '%s', mas foi usada com tipo '%s'.\n",
               name, expectedType, symbol->type);
        exit(1);
    }
}

void printSymbolTable() {
    printf("\n[DEBUG] Tabela de Símbolos:\n");
    printf("----------------------------\n");
    Symbol *current = symbolTable;
    while (current) {
        printf("Nome: '%s', Tipo: %s\n", current->name, current->type);
        current = current->next;
    }
    printf("----------------------------\n");
}
