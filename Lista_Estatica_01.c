#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ESTRUTURA ALUNO
typedef struct {

    char nome[10];
    int matricula;
    int idade;

}ALUNO_LISTA;

typedef ALUNO_LISTA aluno_lista;

// CHAMADA DA TAD ALUNO
#include "TAD_Lista_Estatica_01.h"

// VARIÁVEL DO TIPO LISTA PARA UTILIZAÇÃO DAS FUNÇÕES DEFINIDAS NA "TAD_Lista_Estatica_01.h"
LISTA lista_aluno;

void Menu() {

    printf("\t 1 - INSERIR NA LISTA \n");
    printf("\t 2 - IMPRIMIR LISTA \n");
    printf("\t 3 - TAMANHO DA LISTA \n");
    printf("\t 4 - PESQUISAR ALUNO \n");
    printf("\t 5 - ORDENAR LISTA \n");
    printf("\t 6 - EXCLUIR TODOS \n");
    printf("\t 7 - GRAVAR LISTA NO ARQUIVO \n");
    printf("\t 8 - REMOVER ALUNO \n");
    printf("\t 9 - SAIR \n");

}

// LIMPAR A TELA DEPOIS DE ESCOLHER UMA OPÇÃO
void Limpar_Tela() {

    system("cls");

}

void Inserir() {

    aluno_lista al[3];

    char nome[10];

    int tamanho = Tamanho_Lista(&lista_aluno);

    if(Lista_Cheia(&lista_aluno)) {

        printf("\t LISTA CHEIA \n");

    }

    else {

        do {

            printf("Informe o nome do aluno: \n");
            scanf("%s", nome);

            strcpy(al[tamanho].nome, nome);

            printf("Informe a matricula do aluno: \n");
            scanf("%d", &al[tamanho].matricula);

            printf("Informe a idade do aluno: \n");
            scanf("%d", &al[tamanho].idade);

            Inserir_Lista(&lista_aluno, al[tamanho]);

            tamanho++;

            printf("\t ALUNO INSERIDO COM SUCESSO \n");

        }while(!Lista_Cheia(&lista_aluno));

    }

}

void Listar() {

    aluno_lista al;

    int i;
    int tamanho = Tamanho_Lista(&lista_aluno);

    if(tamanho > 0) {

        for(i = 0; i < tamanho; i++) {

            if(Imprimir_Lista(&lista_aluno, i, &al)) {

                printf("\t ================================ \n");
                printf(" \t POSICAO: %d \n", i+1);
                printf(" \t NOME: %s \n", al.nome);
                printf(" \t MATRÍCULA: %d \n", al.matricula);
                printf(" \t IDADE: %d \n", al.idade);
                printf("\t ================================ \n");

            }

            printf("\n");

        }

    }

    else {

        printf("\t LISTA VAZIA \n");

    }

}

void Consultar() {

    aluno_lista al;

    int posicao = 0;

    int tamanho = Tamanho_Lista(&lista_aluno);

    if(tamanho > 0) {

        printf("\t INFORME A POSICAO DO ALUNO QUE DESEJA PESQUISAR: \n ");
        scanf("%d", &posicao);

        if(Pesquisar_Lista(&lista_aluno, posicao, &al)) {

            printf("\t ================================ \n");
            printf(" \t NOME: %s \n", al.nome);
            printf(" \t MATRÍCULA: %d \n", al.matricula);
            printf(" \t IDADE: %d \n", al.idade);
            printf("\t ================================ \n");

        }

        else {

            printf("\t O ALUNO NAO EXISTE \n");

        }

    }

    else {

        printf("\t LISTA VAZIA \n");

    }

}

void Ordenar() {

    aluno_lista al;

    int tamanho = Tamanho_Lista(&lista_aluno);

    if(tamanho > 0) {

        if(Ordenar_Lista(&lista_aluno, &al)) {

            printf("\t LISTA ORDENADA COM SUCESSO \n");

        }

    }

    else {

        printf("\t LISTA VAZIA \n");

    }

}

void Gravar() {

    aluno_lista al;

    int i;
    int tamanho = Tamanho_Lista(&lista_aluno);

    FILE *arquivo;

    arquivo = fopen("lista_estatica.txt", "w");

    if(arquivo == NULL) {

        printf("\t NÃO FOI POSSÍVEL ABRIR O ARQUIVO \n");
        exit(0);

    }

    else {

        if(tamanho > 0) {

            for(i = 0; i < tamanho; i++) {

                if(Gravar_Arquivo(&lista_aluno, i, &al)) {

                    fprintf(arquivo, "%s \n", al.nome);
                    fprintf(arquivo, "%d \n", al.matricula);
                    fprintf(arquivo, "%d \n", al.idade);

                }

            }

        }

    }

    fclose(arquivo);

}

void Remover() {

    aluno_lista al;

    int posicao = 0;

    int tamanho = Tamanho_Lista(&lista_aluno);

    if(tamanho > 0) {

        printf("\t INFORME A POSICAO DO ELEMENTO QUE DESEJA REMOVER: \n");
        scanf("%d", &posicao);

        if(Remover_Lista(&lista_aluno, posicao, &al)) {

            printf("\t ALUNO REMOVIDO COM SUCESSO \n");

        }

        else {

            printf("\t A POSICAO NAO EXISTE \n");

        }

    }

    else {

        printf("\t LISTA VAZIA \n");

    }

}

// CHAMADA DAS FUNÇÕES NO MÉTODO PRINCIPAL
int main(void) {

    int opcao = 0;

    Inicializar_Lista(&lista_aluno);

    do {

        Menu();

        printf("Informe uma opcao: \n");
        scanf("%d", &opcao);

        Limpar_Tela();

        switch(opcao) {

            case 1:

                Inserir();
                break;

            case 2:

                Listar();
                break;

            case 3:

                printf("\t TAMANHO DA LISTA: %d \n", Tamanho_Lista(&lista_aluno));
                break;

            case 4:

                Consultar();
                break;

            case 5:

                Ordenar();
                break;

            case 6:

                Excluir_Todos(&lista_aluno);
                break;

            case 7:

                Gravar();
                break;

            case 8:

                Remover();
                break;

            case 9:

                exit(0);
                break;

            default:

                printf("\t OPCAO INVALIDA \n");
                break;

        }

    }while(opcao != 0);

}

// CRIADO POR -> JORGE LUIS MOREIRA GOMES FILHO
// DATA -> 15/07/2021
