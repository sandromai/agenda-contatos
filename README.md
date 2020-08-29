<h1 align="center">Agenda</h1>

<br />

## Sumário

- [Bibliotecas Utilizadas](#bicliotecas-utilizadas)
- [Funcionalidades](#funcionalidades)
- [Estrutura dos Contatos](#estrutura-dos-contatos)
- [Descrição](#descrição)
- [Como Usar](#como-usar)
  - [Baixando o Código](#baixando-o-código)
  - [Baixando o Programa Executável](#baixando-o-programa-executável)
    - [Windows](#windows)
    - [Linux](#linux)

## Bibliotecas Utilizadas

- stdio.h;
- stdlib.h;
- locale.h;
- string.h;
- unistd.h.

## Funcionalidades

- Armazena contatos;
- Busca contatos;
- Deleta contatos;
- Armazena os contatos em disco;
- Login e senha;
- Compatibilidade com Windows e Linux.

## Estrutura dos Contatos

- Nome completo:
- Endereço (rua, número, bairro, cidade, estado):
- Telefone:
- Email:
- CPF:
- RG:
- Data nascimento:

## Descrição

Na primeira inicialização o programa pede para o usuário criar um login e uma senha, que serão necessários para os futuros acessos. O arquivo que contém os dados de login e senha é ocultado.
Este programa cria uma pasta chamada "contatos", onde são armazenados todos os contatos criados pelo usuário, cada contato adicionado gera um arquivo diferente para armazenar suas informações. Posteriormente o usuário pode buscar e deletar contatos.

## Como Usar

Para utilizar esse programa você pode baixar o código, fazendo as mudanças que quiser, ou apenas baixar o programa executável e já sair utilizando!

### Baixando o Código

**Você vai precisar de um compilador para realizar este processo!**

1. Faça o download do arquivo `agenda.c`;
2. Abra o arquivo e faça as mudanças que desejar;
3. Compile o código, gerando um arquivo executável;
4. Agora é só dar 2 cliques no arquivo executável ou rodar o comando `./nome_do_executavel`.

### Baixando o Programa Executável

#### Windows

1. Faça o download do arquivo `agenda.exe`;
2. Dê 2 cliques no arquivo ou abra o terminal e rode o comando `./nome_do_executavel`.

#### Linux

1. Faça o download do arquivo `agenda`;
2. Dê 2 cliques no arquivo ou abra o terminal e rode o comando `./nome_do_executavel`.