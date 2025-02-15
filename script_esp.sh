#!/bin/bash

echo "====================================="
echo "Início do processo de tradução"
echo "====================================="

echo ""
echo "Escolha o caminho de entrada:"
read caminho_entrada

echo "====================================="
echo "Agora, escolha o nome do arquivo de saída"
echo "====================================="

echo ""
echo "Escolha o nome do arquivo de saída da arvore sintática:"
read nome_saida

echo "====================================="
echo "Processando o comando..."
echo "====================================="

./tradutor < "$caminho_entrada" > "output/$nome_saida.txt"

echo ""
echo "====================================="
echo "Arquivo '$nome_saida.txt' foi criado com sucesso!"
echo ""
echo "Caso não tenha nenhum erro, seu arquivo C++ será criado em:"
echo "output/codigo_esp32.cpp"
echo "====================================="

echo ""
echo "Pressione qualquer tecla para fechar..."
read -n 1 -s