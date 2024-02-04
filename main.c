#include<stdio.h>
#include<stdlib.h>
//EStruutura chamada 
//Lista Encadeada

struct st_no { //criei uma struct chmada st_no
    int valor; // Declarei uma variável

    // Temos um ponteiro indicando qual que é o próximo 
    // elemento.
    struct st_no *prox; // Declarei um atributo que é do próprio tipo dele.
                       // Um ponteiro apontando para o próximo elemento.

};
/*Vou usar recurso aqui typedef vou criar uma varável struct st_no no tipo de chamada.
Esse vai ser a nosso tipo de dado.*/
typedef struct st_no no;

/*Vamos criar uma função aqui para verificar se essa nossa linha de lixo está vázio ou não*/
int vazia(no* le) { // le -> lista encadeada
    
    if(le->prox == NULL) { //Verificação
        return 1;

    } else {
        return 0;
    }// Estamos usando o verdadeiro e falso.
}
// Uma função agora chamada inicia que ela vai inicializar a nossa lista.
void inicia(no *le) {
    le->prox = NULL; // A gente simplesmente vai colocar o ponteiro apontando pra nu.

}
//Uma função chamada libera do tipo nota também vai receber a nossa lista.
void libera(no *le) {
    if(!vazia(le)) {
        no *proxNo, *atual;
/*Temos duas variáveis desse tipo proxNo é o atual.*/
// Vamos fazer o seguinte o atual vai receber
        atual = le->prox;
        while(atual != NULL) {
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;

        }
    }
}
// Uma função para exibir a lista.
void exibe(no *le){
    if(vazia(le)) {
        printf("Lista esta vazia!\n");
        return;
    }
    no *tmp;
    tmp = le->prox;
/*Vamos fazer um while porque enquanto o tempo que for diferente de 'nu' porque lá só a gente 
espera no NULL.*/
    while(tmp != NULL) {
        printf("%d ", tmp->valor);
        tmp = tmp->prox; // Se ele é NULL ou não.
    }
    printf("\n\n");
}
//Uma função inserir o  inicio.
void insereInicio(no *le) {
// Criamos uma nova variável -> no *novo
/*Ele vai retornar um ponteiro para o nó e vamos utilizar o malloc para fazer essa alocação 
dinâmica.*/
    no *novo = (no*)malloc(sizeof(no));
    if(!novo) {
        printf("Sem memoria desponivel!\n");
        exit(1); //Sair do programa.
    }
    printf("Informe o valor: ");
    scanf("%d", &novo->valor);
// head anterior
    no *oldHead = le->prox;

    le->prox = novo;
    novo->prox = oldHead;

}
// Uma função inserir no final.
void insereFinal(no *le) {
    no *novo = (no*) malloc(sizeof(no));
    if(!novo) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    printf("Informe o valor: ");
    scanf("%d", &novo->valor);
    novo->prox = NULL;
    if(vazia(le)) {
        le->prox = novo;
    } else {
        no *tmp = le->prox;
        while(tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}
// Uma função inserir opção.
// Só para a gente montar executar aquilo que ele deve fazer.
void opcao(no *le, int op) {
    switch(op) {
        case 0:
            libera(le); // A nossa função libera que no caso ele vai esvaziar ela.
            break;
        case 1:
            exibe(le); //Exibe então vai vim lá na função vai exiber todos os valores.
            break;
        case 2:
            insereInicio(le);
            break;
        case 3: 
            insereFinal(le);
            break;
        case 4:
            inicia(le);
            break;
        default:
            printf("Comando invalido\n\n");
    }
}
// Uma função inserir o menu.
int menu() {
    int opt;
    printf("Escolha a opcao: \n");
    printf("[0] - Sair: \n");
    printf("[1] - Exibir: \n");
    printf("[2] - Adicionar no no inicio:\n");
    printf("[3] - Adicionar no no fim: \n");
    printf("[4] - zerar lista: \n");
    printf("Opcao: ");
    scanf("%d", &opt);
    
    return opt;
}
int main() {
    no *le = (no*)malloc(sizeof(no));
    if(!le) {
        printf("Sem memoria disponivel: ");
        exit(1);
    }
    inicia(le);
    int opt;
    do {
        opt = menu();
        opcao(le, opt);
    }while(opt);
    free(le);
    return 0;
}
