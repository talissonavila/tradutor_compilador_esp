# Tradutor Compilador ESP

Este projeto implementa um compilador para converter código-fonte no formato `.txt` para `.cpp`, facilitando a compilação de programas para o ESP32. O processo de tradução segue regras específicas que devem ser respeitadas.

## Índice

1. [Clonando o Repositório](#clonando-o-repositório)
2. [Gerando o Tradutor](#gerando-o-tradutor)
   1. [Modo Simplificado](#modo-simplificado)
   2. [Modo Passo a Passo](#modo-passo-a-passo)
        1. [Etapa da análise léxica](#etapa-da-análise-léxica)
        2. [Etapa da análise sintática](#etapa-da-análise-sintática)
        3. [Etapa da geração do tradutor](#etapa-da-geração-do-tradutor)
3. [Executando o Tradutor: `.txt` para `.cpp`](#executando-o-tradutor-txt-para-cpp)
4. [Compilando o Código para ESP32](#compilando-o-código-para-esp32)
5. [Créditos](#créditos)

---
Executando o tradutor txt para cpp

## Passo a Passo para Executar o Projeto

### Clonando o Repositório

Abra o terminal e execute o seguinte comando para clonar o repositório:

```bash
git clone https://github.com/talissonavila/tradutor_compilador_esp.git
```

Isso criará uma pasta chamadat radutor_compilador_esp no seu diretório atual.

## Gerando o Tradutor

Navegue até o diretório do projeto:

```bash
cd tradutor_compilador_esp
```

### Modo simplificado

Execute o script shell script ```gera_tradutor.sh```, da seguinte forma:

```bash
./gera_tradutor.sh
```

##### Observação: Pode ser necessário, tornar o script executável, caso não funcione. Para isso, execute o seguinte comando:

```bash
chmod +x gera_tradutor.sh
```

##### Este script gera o tradutor que será utilizado para converter o código-fonte.

### Modo Passo a Passo

Você precisará exectuar os seguintes passos:

<ol>
  <li>Etapa da análise léxica</li>
  <li>Etapa da análise sintática</li>
  <li>Geração do código tradutor</li>
</ol>

#### Etapa da análise léxica

Executa o ```flex``` no arquivo de entrada ```analisador_lexico.l```. O ```flex``` é uma ferramenta que gera um analisador léxico a partir de um arquivo de especificação.

Para isso, execute o seguinte comando:

```bash
flex analisador_lexico.l
```

#### Etapa da análise sintática

Executa o ```bison``` no arquivo ```analisador_sintatico.y```. O ```bison``` é uma ferramenta que gera um analisador sintático a partir de um arquivo de especificação.

Para isso, execute o seguinte comando:

```bash
bison -d analisador_sintatico.y
```

**O parâmetro ```-d``` gera um arquivo de cabeçalho (```arquivo.h```) para uso posterior.**


#### Etapa da geração do tradutor

Utiliza o gcc (GNU Compiler Collection) para compilar o código C que será o tradutor gerado. 

Para isso, execute o seguinte comando:

```bash
gcc -I. analisador_sintatico.tab.c lex.yy.c gerador_de_ast.c tabela_de_simbolos.c -o tradutor -lfl -g
```

Detalhando esse comando:
    
* ```gcc```: Inicia o compilador C.

* ```-I.```:  Indica que o diretório atual deve ser procurado por arquivos de cabeçalho.

* ```analisador_sintatico.tab.c```:  Arquivo gerado pelo ```bison```, que implementa o analisador sintático.

* ```lex.yy.c```: Arquivo gerado pelo ```flex```, que implementa o analisador léxico.

* ```gerador_de_ast.c ```:  Arquivo gerado para o gerador de AST.

* ```tabela_de_simbolos.c```: Arquivo gerado para a tabela de símbolos.

* ```-o tradutor```: Especifica que o arquivo de saída será chamado ```tradutor```.

* ```-lfl```: Vincula a biblioteca do ```flex``` (libfl).

* ```-g```: Ativa a informação de depuração para o compilador.

### Executando o tradutor txt para cpp

Após realizado o passo 2, execute o script que traduz o código para cpp, com o seguinte comando:

```bash
./script_esp.sh
```

##### Observação: Pode ser necessário, tornar o script executável, caso não funcione. Para isso, execute o seguinte comando:

```bash
chmod +x script_esp.sh
```

Durante a execução do ```script_esp.sh```, você será solicitado a fornecer as seguintes informações:

<ol>
  <li><strong>Caminho do arquivo de entrada:</strong> <br> Informe o caminho relativo do <code>arquivo.txt</code> que contém o código-fonte a ser traduzido.<br>Dentro da pasta <code>input</code>existem exemplos que você pode utilizar. Para usá-los, escreva <code>input/nome_do_arquivo.txt</code>trocando <code>nome_do_arquivo</code> pelo arquivo desejado</li>
  <li><strong>Caminho do arquivo de saída:</strong><br>Informe o nome onde o arquivo da árvore sintática será salvo.<br>O arquivo será salvo dentro da pasta <code>output</code><br>Será criado um arquivo <code>codigo_esp32.cpp</code> com o código traduzido.<br><strong>Obs: Cuidado para não sobrescrever o arquivo cpp.</strong></li>
</ol>

### Compilando o código para ESP32

Você pode usar o site do [Wokwi](https://wokwi.com/)
, um simulador que tem o ESP32 como opção.


##### Avalie nosso repositório positivamente :star:

##### Créditos
<strong>Por: [Hellyson Herik](https://github.com/hellyson-herik) e [Talisson Avila](https://github.com/talissonavila) 
</strong>
