# Sistemas-Operacionais
Repositório da faculdade - 04N11
---
## Grupo

|Participante                              |     TIA    |
|------------------------------------------|------------|
|Gabriel Augusto Ribeiro Gomes             | 32134762   |
|Paulo Henrique Braga Cechinel             | 32151128   |
|Ricardo Gabriel Marques dos Santos Ruiz   | 31234908   |
---

## Lab01a - Hello World
Contém código que printa "Hello, World"

## Lab01b - Introdução ao Linux

```
1) O comando cat é usado no sistema operacional Linux para exibir o conteúdo de um arquivo na tela do
computador. Escreva um programa (na linguagem C) faça exatamente o que o cat faz, o programa
deverá ler um arquivo texto (entrada) informado por linha de comando no interpretador de comando
(Como se faz isso ?) e depois imprimir o conteúdo do arquivo na tela. Faça todos os testes necessários
para abertura, leitura e ao final não se esqueça de fechar o arquivo.
Identifique no seu programa as linhas de comando onde ocorrem chamadas de sistemas ao SO.
Quantas chamadas de sistemas foram realizadas?
Dica de arquivos em C: https://www.ime.usp.br/~pf/algoritmos/aulas/io.html
```
1-) Código se encontra em: 

**Lab01b-IntroducaoLinux/HandmadeCat/HandmadeCat.c**, junto com o seu MakeFile e seu arquivo de exemplo

Para compilar/rodar o programa:
No diretório do programa:

```
make
./HandmadeCat text.txt
```



```
2) Escreva um programa (na linguagem C) que leia um arquivo texto (entrada) e copie para um outro
arquivo (saída), ou seja, faz o que o comando cp faz no Linux. O seu programa deve solicitar o nome do
arquivo de entrada e de saída (por linha de comando), uma vez obtido os dois nomes, o programa
deve abrir o arquivo de entrada e criar o arquivo de saída. Caso por alguma razão não possa abrir o
arquivo de entrada seu programa deve imprimir uma mensagem de aviso e finalizar, caso aconteça um
erro de criação do arquivo saída o programa imprime uma mensagem e finaliza. Caso o programa tenha
sucesso na abertura e criação, o programa lê a partir do arquivo de entrada e grava no arquivo de saída.
Finalmente, depois que o arquivo de entrada for inteiramente copiado o programa pode fechar os dois
arquivos.
Identifique no seu programa as linhas de comando onde ocorrem chamadas de sistemas ao SO.
Quantas chamadas de sistemas foram realizadas?
```
