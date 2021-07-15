// TAMANHO MÁXIMO DA LISTA
#define MAX 3

// ESTRUTURA PARA DEFINIÇÃO DO TAMANHO E LIGAÇÃO COM A ESTRUTURA ALUNO
typedef struct {

    int tamanho_lista;
    ALUNO_LISTA aluno_l[MAX];

}LISTA;

typedef LISTA lista;

// PROTÓTIPO DAS FUNÇÕES UTILIZADAS
void Inicializar_Lista(lista *l);
int Lista_Cheia(lista *l);
int Inserir_Lista(lista *l, aluno_lista e);
int Remover_Lista(lista *l, int i, aluno_lista *e);
int Imprimir_Lista(lista *l, int i, aluno_lista *e);
int Pesquisar_Lista(lista *l, int i, aluno_lista *e);
int Ordenar_Lista(lista *l, aluno_lista *e);
int Tamanho_Lista(lista *l);
int Gravar_Arquivo(lista *l, int i, aluno_lista *e);
void Excluir_Todos(lista *l);


// IMPLEMETAÇÃO DAS FUNÇÕES
void Inicializar_Lista(lista *l) {

    l->tamanho_lista = 0;

}

int Lista_Cheia(lista *l) {

    return (l->tamanho_lista == MAX);

}

int Inserir_Lista(lista *l, aluno_lista e) {

    l->aluno_l[l->tamanho_lista] = e;
    l->tamanho_lista++;

}

int Remover_Lista(lista *l, int i, aluno_lista *e) {

    if(l->tamanho_lista == 0) {

        return 0;

    }

    else {

        if(i >= 0 && i <= l->tamanho_lista) {

            for(i = i - 1; i < l->tamanho_lista; i++) {

                l->aluno_l[i] = l->aluno_l[i+1];

            }

            l->tamanho_lista--;

        }

        else {

            return 0;

        }

    }

}

int Imprimir_Lista(lista *l, int i, aluno_lista *e) {

    if(i < l->tamanho_lista && l->tamanho_lista != 0) {

        *e = l->aluno_l[i];

    }

}

int Pesquisar_Lista(lista *l, int i, aluno_lista *e) {

    if(l->tamanho_lista == 0) {

        return 0;

    }

    else {

        if(i) {

            *e = l->aluno_l[i-1];

        }

    }

}

int Ordenar_Lista(lista *l, aluno_lista *e) {

    int i, j;

    if(l->tamanho_lista != 0) {

        for(i = 1; i < l->tamanho_lista; i++) {

            *e = l->aluno_l[i];

            for(j = i; j > 0 && (e->matricula < l->aluno_l[j - 1].matricula); j--) {

                l->aluno_l[j] = l->aluno_l[j - 1];

            }

            l->aluno_l[j] = *e;

        }

    }

    else {

        return 0;

    }

}

int Gravar_Arquivo(lista *l, int i, aluno_lista *e) {

    if(l->tamanho_lista != 0) {

        *e = l->aluno_l[i];

    }

    else {

        return 0;

    }

}

int Tamanho_Lista(lista *l) {

    return l->tamanho_lista;

}

void Excluir_Todos(lista *l) {

    l->tamanho_lista = 0;

}
