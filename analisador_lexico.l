%{
#include "analisador_sintatico.tab.h"
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_POR_LINHA 2048
char linha_atual[MAX_CHAR_POR_LINHA];
int posicao_linha = 0;
%}

VAR              var
INTEIRO          inteiro
TEXTO            texto
BOOLEANO         booleano
CONFIG           config
REPITA           repita
FIM              fim
LIGAR            ligar
DESLIGAR         desligar
ESPERAR          esperar
CONFIGURAR       configurar
CONFIGURARPWM    configurarPWM
COMO             como
SAIDA            saida
ENTRADA          entrada
FREQUENCIA       frequencia
RESOLUCAO        resolucao
CONECTARWIFI     conectarWifi
ENVIARHTTP       enviarHttp
CONFIGURARSERIAL configurarSerial
ESCREVERSERIAL   escreverSerial
LERSERIAL        lerSerial
COM              com
VALOR            valor
AJUSTARPWM       ajustarPWM
SE               se
ENTAO            entao
SENAO            senao
ENQUANTO         enquanto
VERDADEIRO       verdadeiro
FALSO            falso

IDENTIFICADOR [a-zA-Z_][a-zA-Z0-9_]*
NUMERO        [0-9]+
STRING        \"(\\.|[^\\"])*\"
ESPACO        [ \t\r]+
NOVA_LINHA    \n
COMENTARIO    "//".*

%%

{ESPACO}        { /* ignora */ }
{COMENTARIO}    { /* ignora */ }
{NOVA_LINHA}    { yylineno++; }

{VAR}              return VAR;
{INTEIRO}          return INTEIRO;
{TEXTO}            return TEXTO;
{BOOLEANO}         return BOOLEANO;
{CONFIG}           return CONFIG;
{REPITA}           return REPITA;
{FIM}              return FIM;
{LIGAR}            return LIGAR;
{DESLIGAR}         return DESLIGAR;
{ESPERAR}          return ESPERAR;
{CONFIGURAR}       return CONFIGURAR;
{CONFIGURARPWM}    return CONFIGURARPWM;
{COMO}             return COMO;
{ENTRADA}          return ENTRADA;
{FREQUENCIA}       return FREQUENCIA;
{RESOLUCAO}        return RESOLUCAO;
{CONECTARWIFI}     return CONECTARWIFI;
{ENVIARHTTP}       return ENVIARHTTP;
{CONFIGURARSERIAL} return CONFIGURARSERIAL;
{ESCREVERSERIAL}   return ESCREVERSERIAL;
{LERSERIAL}        return LERSERIAL;
{COM}              return COM;
{VALOR}            return VALOR;
{AJUSTARPWM}       return AJUSTARPWM;
{SE}               return SE;
{ENTAO}            return ENTAO;
{SENAO}            return SENAO;
{ENQUANTO}         return ENQUANTO;

{NUMERO}        { yylval.intval = atoi(yytext); return NUMERO; }
{STRING}        { yylval.strval = strdup(yytext); return STRING; }
{VERDADEIRO}    { yylval.strval = strdup("verdadeiro"); return VERDADEIRO; }
{FALSO}         { yylval.strval = strdup("falso"); return FALSO; }
{SAIDA}         { return SAIDA; }
{IDENTIFICADOR} { yylval.strval = strdup(yytext); return IDENTIFICADOR; }

"="          return '=';
";"          return ';';
":"          return ':';
","          return ',';
"+"          return SOMA;
"-"          return SUBTRACAO;
"*"          return MULTIPLICACAO;
"/"          return DIVISAO;
"=="         return IGUAL;
"!="         return DIFERENTE;
"<"          return MENOR_QUE;
">"          return MAIOR_QUE;
">="         return MAIOR_IGUAL;
"<="         return MENOR_IGUAL;

. {
    if (yytext[0] == '\n') {
        linha_atual[posicao_linha] = '\0';
        posicao_linha = 0;
    } else {
        if (posicao_linha < MAX_CHAR_POR_LINHA - 1) {
            linha_atual[posicao_linha++] = yytext[0];
        }
    }
}

%%

int yywrap() { return 1; }