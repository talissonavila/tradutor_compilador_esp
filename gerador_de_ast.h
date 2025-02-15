#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct Node {
    char *label;
    struct Node **children;
    int numChildren;
} Node;

Node *newNode(char *label, int numChildren, ...);
void printTree(Node *node, int depth);
void freeTree(Node *node);
void addChild(Node *parent, Node *child);
void generateCppCode(Node *node, FILE *file, int indentLevel);
void generateFinalCppCode(Node *node, FILE *file);
void printIndent(FILE *file, int indentLevel);

#endif
