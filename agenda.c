/*
Desenvolva uma agenda eletrônica na qual seja capaz de armazenar, buscar e deletar as seguintes
informações:

Nome completo:
Endereço: (rua, número, bairro, cidade, estado)
Telefone:
Email:
CPF:
RG:
Data nascimento:

Essas informações deverão se manter persistentes em sistema, ou seja, deverão ser armazenadas
não somente em memória, mas em um local que seja possível busca-las caso o programa encerre
ou o computador seja desligado.

A agenda deverá ter um sistema de login e senha, para prover a segurança do sistema. Caso o
login e senha seja digitado mais de 3 vezes de forma incorreta o sistema deverá bloquear o
sistema durante 30 segundos. Usar funções, ponteiros e escrita/leitura em arquivos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

void OS();
void display(int displayType);
void option();
void verify();
void login();
void createAccount(); 
void add();
void search();
void delete();
void clearTerminal();

int os;

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    display(1);

    OS();

    verify();

    system("mkdir contatos");

    if (os == 1)
    {
        system("cls");
    } else if (os == 2)
    {
        system("clear");
    }
    
    while (1)
    {
        option();
    }

    return 0;
}

void verify()
{
    FILE *loginFile;

    if (os == 1)
    {
        loginFile = fopen("login.txt", "r");

        if (loginFile == NULL)
        {
            createAccount();
            sleep(2);
            system("cls");

            login();
        } else
        {
            login();
        }
    } else if (os == 2)
    {
        loginFile = fopen(".login.txt", "r");
        
        if (loginFile == NULL)
        {
            createAccount();
            sleep(2);
            system("clear");

            login();
        } else
        {
            login();
        }
        
    }
}

void createAccount()
{
    FILE *loginFile;
    char user[100], password[100];

    if (os == 1)
    {
        loginFile = fopen("login.txt", "a");     
        system("attrib +h login.txt");
    } else if (os == 2)
    {
        loginFile = fopen(".login.txt", "a");
    }
    
    if (loginFile == NULL)
    {
        printf("\nERRO NO CADASTRO\n");
        sleep(2);
        exit(3);
    } else
    {
        display(8);

        printf("\nUsuário: ");
        fgets(user, 100, stdin);
        fprintf(loginFile, "%s", user);

        printf("\nSenha: ");
        fgets(password, 100, stdin);
        fprintf(loginFile, "%s", password);

        fclose(loginFile);

        printf("\n");

        display(9);
    }
}

void login()
{
    FILE *loginFile;
    char user[100], password[100], line[100];
    int i, error = 0, errorCount = 0;

    if (os == 1)
    {
        loginFile = fopen("login.txt", "r");
    } else if (os == 2)
    {
        loginFile = fopen(".login.txt", "r");
    }
    
    if (loginFile == NULL)
    {
        printf("\nERRO NO LOGIN\n");
        sleep(2);
        exit(2);
    } else
    {
        while (errorCount != 5)
        {
            display(4);

            printf("\nUsuário: ");
            fgets(user, 100, stdin);

            printf("\nSenha: ");
            fgets(password, 100, stdin);

            printf("\n");

            rewind(loginFile);

            fgets(line, 100, loginFile);

            if (strlen(user) != strlen(line))
            {
                error++;
            } else
            {
                for (i = 0; i < strlen(line); i++)
                {
                    if (user[i] != line[i])
                    {
                        error++;
                    }
                } 
            }

            fgets(line, 100, loginFile);

            if (strlen(password) != strlen(line))
            {
                error++;
            } else
            {
                for (i = 0; i < strlen(line); i++)
                {
                    if (password[i] != line[i])
                    {
                        error++;
                    }
                } 
            }

            if (error == 0)
            {
                display(5);
                errorCount = 5;
            } else
            {
                error = 0;
                errorCount++;
                display(6);
                sleep(2);

                if (os == 1)
                {
                    system("cls");
                } else if (os == 2)
                {
                    system("clear");
                }
            }

            if (errorCount == 3)
            {
                display(7);
                sleep(30);
                errorCount = 0;

                if (os == 1)
                {
                    system("cls");
                } else if (os == 2)
                {
                    system("clear");
                }
            }
        }

        fclose(loginFile);
        sleep(2);

        if (os == 1)
        {
            system("cls");
        } else if (os == 2)
        {
            system("clear");
        }
    }
}

void OS()
{
    display(3);

    printf("\nInsira o valor corespondente ao seu SO: ");
    scanf("%d", &os);

    getchar();

    if (os == 1)
    {
        system("cls");
    }
    else if (os == 2)
    {
        system("clear");
    } else
    {
        printf("\nERRO NO OS\n");
        sleep(2);
        exit(1);
    }
}

void display(int displayType)
{
    switch (displayType)
    {
    case 1:
        printf("************************************\n");
        printf("*  Bem-vindo à agenda eletrônica   *\n");
        printf("************************************\n");
        break;
    
    case 2:
        printf("************************************\n");
        printf("*        Menu de Utilização        *\n");
        printf("*                                  *\n");
        printf("*       1. Adicionar Contato       *\n");
        printf("*       2. Buscar Contato          *\n");
        printf("*       3. Remover Contato         *\n");
        printf("*       4. Sair                    *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 3:
        printf("************************************\n");
        printf("* Sistemas Operacionais Suportados *\n");
        printf("*                                  *\n");
        printf("*            1 - Windows           *\n");
        printf("*            2 - Linux             *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 4:
        printf("************************************\n");
        printf("*           Fazer Login            *\n");
        printf("************************************\n");
        break;

    case 5:
        printf("************************************\n");
        printf("*    Login Efetuado com Sucesso    *\n");
        printf("************************************\n");
        break;

    case 6:
        printf("************************************\n");
        printf("*   Usuário ou Senha Incorretos    *\n");
        printf("************************************\n");
        break;

    case 7:
        printf("************************************\n");
        printf("*     3 Tentativas Fracassadas     *\n");
        printf("*       Aguarde 30 Segundos        *\n");
        printf("************************************\n");
        break;

    case 8:
        printf("************************************\n");
        printf("*      Cadastrar novo Usuário      *\n");
        printf("************************************\n");
        break;

    case 9:
        printf("************************************\n");
        printf("*  Cadastro Realizado com Sucesso  *\n");
        printf("************************************\n");
        break;

    case 10:
        printf("************************************\n");
        printf("*     Adicionar novo Contato       *\n");
        printf("************************************\n");
        break;

    case 11:
        printf("************************************\n");
        printf("*       Contato Adicionado         *\n");
        printf("************************************\n");
        break;

    case 12:
        printf("************************************\n");
        printf("*          Buscar Contato          *\n");
        printf("************************************\n");
        break;

    case 13:
        printf("************************************\n");
        printf("*         Deletar Contato          *\n");
        printf("************************************\n");
        break;

    case 14:
        printf("************************************\n");
        printf("*         Contato Removido         *\n");
        printf("************************************\n");
        break;

    case 15:
        printf("************************************\n");
        printf("*      Encerrando o Programa       *\n");
        printf("************************************\n");
        break;

    default:
        printf("\nERRO NO DISPLAY\n");
        sleep(2);
        exit(5);
        break;
    }
}

void option()
{
    int option;

    display(2);

    printf("\nDigite a opção desejada: ");
    scanf("%d", &option);

    getchar();

    if (os == 1)
    {
        sleep(1);
        system("cls");
    } else if (os == 2)
    {
        sleep(1);
        system("clear");
    }

    switch (option)
    {
    case 1:
        printf("\n");
        add();
        break;

    case 2:
        printf("\n");
        search();
        break;

    case 3:
        printf("\n");
        delete();
        break;

    case 4:
        display(15);
        sleep(2);

        if (os == 1)
        {
            system("cls");
        } else if (os == 2)
        {
            system("clear");
        }

        exit(0);

        break;
    
    default:
        printf("\nOpção Inexistente!\n");

        if (os == 1)
        {
            sleep(1);
            system("cls");
        } else if (os == 2)
        {
            sleep(1);
            system("clear");
        }
        break;
    }
}

void add()
{
    FILE *document;
    char name[50], adress[80], phone[15], email[30], cpf[15], rg[15], birthday[11];
    char fileName[100], fileNameAux[100], fileExtension[100], moveFile[100], moveFileAux[100];

    display(10);

    printf("\nInsira um nome para o arquivo: ");
    fgets(fileName, 100, stdin);

    strtok(fileName, "\n");

    strcpy(fileExtension, ".txt");
    strcat(fileName, fileExtension);

    if (os == 1)
    {
        sleep(1);
        system("cls");
    } else if (os == 2)
    {
        sleep(1);
        system("clear");
    }

    document = fopen(fileName, "a");

    if (document == NULL)
    {
        printf("\nNão foi possível criar o arquivo!\n");
        sleep(2);
        exit(6);
    }
    else
    {
        display(10);

        printf("\nInsira as Informações\n");

        printf("\nNome Completo: ");
        fgets(name, 50, stdin);
        fprintf(document, "Nome Completo: %s", name);

        printf("\nEndereço (rua, número, bairro, cidade, estado): ");
        fgets(adress, 80, stdin);
        fprintf(document, "Endereço: %s", adress);

        printf("\nTelefone: ");
        fgets(phone, 20, stdin);
        fprintf(document, "Telefone: %s", phone);

        printf("\nE-mail: ");
        fgets(email, 30, stdin);
        fprintf(document, "E-mail: %s", email);
        
        printf("\nCPF: ");
        fgets(cpf, 15, stdin);
        fprintf(document, "CPF: %s", cpf);

        printf("\nRG: ");
        fgets(rg, 15, stdin);
        fprintf(document, "RG: %s", rg);

        printf("\nData de Nascimento: ");
        fgets(birthday, 11, stdin);
        fprintf(document, "Data de Nascimento: %s\n", birthday);

        printf("\n");

        display(11);

        fclose(document);

        sleep(2);
    }

    if (os == 1)
    {
        strcpy(fileNameAux, "\"");
        strcat(fileNameAux, fileName);
        strcat(fileNameAux, "\"");

        strcpy(moveFile, "move ");
        strcat(moveFile, fileNameAux);
        strcpy(moveFileAux, " contatos");
        strcat(moveFile, moveFileAux);

        system(moveFile);
        system("cls");
    } else if (os == 2)
    {
        strcpy(fileNameAux, "\'");
        strcat(fileNameAux, fileName);
        strcat(fileNameAux, "\'");

        strcpy(moveFile, "mv ");
        strcat(moveFile, fileNameAux);
        strcpy(moveFileAux, " contatos");
        strcat(moveFile, moveFileAux);

        system(moveFile);
        system("clear");
    }
}

void search()
{
    FILE *document;
    char fileName[100], fileExtension[100], filePath[100], c;
    int i=0;

    display(12);

    printf("\nDigite o nome do arquivo para a busca: ");
    fgets(fileName, 100, stdin);

    strtok(fileName, "\n");
    strcpy(fileExtension, ".txt");
    strcat(fileName, fileExtension);
    strcpy(filePath, "contatos/");
    strcat(filePath, fileName);

    document = fopen(filePath, "r");

    if (document == NULL)
    {
        printf("\nNão foi possível encontrar o arquivo!\n");

        if (os == 1)
        {
            sleep(1);
            system("cls");
        } else if (os == 2)
        {
            sleep(1);
            system("clear");
        }
    } else
    {
        if (os == 1)
        {
            sleep(1);
            system("cls");
        } else if (os == 2)
        {
            sleep(1);
            system("clear");
        }

        display(12);

        printf("\n------------------------------------\n\n\n");

        c = fgetc(document);

        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(document);
        }

        printf("\n------------------------------------\n\n");

        printf("Pressione \"enter\" para continuar\n");
        getchar();
        
        if (os == 1)
        {
            system("cls");
        } else if (os == 2)
        {
            system("clear");
        }

        fclose(document);
    }
}

void delete()
{
    FILE *document;
    char fileName[100], fileExtension[100], filePath[100];
    int i=0;

    display(13);

    printf("\nDigite o nome do arquivo que você deseja deletar:  ");
    fgets(fileName, 100, stdin);

    strtok(fileName, "\n");
    strcpy(fileExtension, ".txt");
    strcat(fileName, fileExtension);
    strcpy(filePath, "contatos/");
    strcat(filePath, fileName);

    document = fopen(filePath, "r");

    if (document == NULL)
    {
        printf("\nNão foi possível encontrar o arquivo\n");

        if (os == 1)
        {
            sleep(1);
            system("cls");
        } else if (os == 2)
        {
            sleep(1);
            system("clear");
        }
    } else
    {
        fclose(document);

        remove(filePath);

        printf("\n");
        
        display(14);
    }
    
    if (os == 1)
    {
        sleep(2);
        system("cls");
    } else if (os == 2)
    {
        sleep(2);
        system("clear");
    }
}

void clearTerminal()
{
    if (os == 1)
    {
        system("cls");
    } else if (os == 2)
    {
        system("clear");
    }
}