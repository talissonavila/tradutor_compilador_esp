/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 19 "parser.y"

    #include "node.h"

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEIRO = 258,                 /* INTEIRO  */
    TEXTO = 259,                   /* TEXTO  */
    IDENTIFICADOR = 260,           /* IDENTIFICADOR  */
    STRING = 261,                  /* STRING  */
    SAIDA = 262,                   /* SAIDA  */
    ENTRADA = 263,                 /* ENTRADA  */
    NUMERO = 264,                  /* NUMERO  */
    FREQUENCIA = 265,              /* FREQUENCIA  */
    RESOLUCAO = 266,               /* RESOLUCAO  */
    COM = 267,                     /* COM  */
    VAR = 268,                     /* VAR  */
    BOOLEANO = 269,                /* BOOLEANO  */
    CONFIG = 270,                  /* CONFIG  */
    REPITA = 271,                  /* REPITA  */
    FIM = 272,                     /* FIM  */
    LIGAR = 273,                   /* LIGAR  */
    DESLIGAR = 274,                /* DESLIGAR  */
    ESPERAR = 275,                 /* ESPERAR  */
    CONFIGURAR = 276,              /* CONFIGURAR  */
    COMO = 277,                    /* COMO  */
    CONFIGURARPWM = 278,           /* CONFIGURARPWM  */
    CONECTARWIFI = 279,            /* CONECTARWIFI  */
    ENVIARHTTP = 280,              /* ENVIARHTTP  */
    VALOR = 281,                   /* VALOR  */
    AJUSTARPWM = 282,              /* AJUSTARPWM  */
    CONFIGURARSERIAL = 283,        /* CONFIGURARSERIAL  */
    ESCREVERSERIAL = 284,          /* ESCREVERSERIAL  */
    LERSERIAL = 285,               /* LERSERIAL  */
    SE = 286,                      /* SE  */
    ENTAO = 287,                   /* ENTAO  */
    SENAO = 288,                   /* SENAO  */
    ENQUANTO = 289,                /* ENQUANTO  */
    VERDADEIRO = 290,              /* VERDADEIRO  */
    FALSO = 291,                   /* FALSO  */
    IGUAL = 292,                   /* IGUAL  */
    DIFERENTE = 293,               /* DIFERENTE  */
    MENOR_QUE = 294,               /* MENOR_QUE  */
    MAIOR_QUE = 295,               /* MAIOR_QUE  */
    MAIOR_IGUAL = 296,             /* MAIOR_IGUAL  */
    MENOR_IGUAL = 297,             /* MENOR_IGUAL  */
    SOMA = 298,                    /* SOMA  */
    SUBTRACAO = 299,               /* SUBTRACAO  */
    MULTIPLICACAO = 300,           /* MULTIPLICACAO  */
    DIVISAO = 301                  /* DIVISAO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

    int intval;     // Para números inteiros
    char *strval;
    Node *node;

#line 122 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
