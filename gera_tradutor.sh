#!/bin/bash

# Variáveis de arquivos e comandos
lexical_analyser="analisador_lexico.l"
lexical_filename="lex.yy.c"
sintatical_analyser="analisador_sintatico.y"
sintatical_filename="analisador_sintatico"
three_filename="gerador_de_ast"
symbol_table_filename="tabela_de_simbolos"

# Comando para gerar o tradutor com gcc
generate_translater="gcc -I. $sintatical_filename.tab.c $lexical_filename $three_filename.c $symbol_table_filename.c -o tradutor -lfl -g"

# Função para a análise léxica
analise_lexica() {
    echo "====================================="
    echo "Início etapa da analise lexica"
    echo "====================================="
    echo ""
    # Executa o comando flex com o analisador léxico
    flex $lexical_analyser
    echo "====================================="
    echo "Processando o comando..."
    echo "Arquivo gerado com sucesso!"
    echo "====================================="
}

# Função para a análise sintática
analise_sintatica() {
    echo "====================================="
    echo "Início etapa da analise sintatica"
    echo "====================================="
    echo ""
    # Executa o comando bison para gerar o analisador sintático
    bison -d $sintatical_analyser
    echo "====================================="
    echo "Processando o comando..."
    echo "Arquivo gerado com sucesso!"
    echo "====================================="
}

# Função para a geração do tradutor
gerar_tradutor() {
    echo "====================================="
    echo "Início etapa da geracao do tradutor"
    echo "====================================="
    echo ""
    # Executa o comando para gerar o tradutor com gcc
    #gcc -I. $sintatical_filename.tab.c $lexical_filename $three_filename.c $symbol_table_filename.c -o tradutor -lfl -g
    eval $generate_translater
    echo "====================================="
    echo "Processando o comando..."
    echo "Tradutor gerado com sucesso!"
    echo "====================================="
}

# Função principal que orquestra a execução das etapas
executar_etapas() {
    analise_lexica
    analise_sintatica
    gerar_tradutor
}

# Chama a função principal para rodar as etapas
executar_etapas
