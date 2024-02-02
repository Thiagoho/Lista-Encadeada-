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
        return 0;

    } else {
        return 1;
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
void exibir(no *le){
    if(vazia(le)) {
        printf("Lista esta vazia!\n");
        return;
    }
    no *tmp;
    tmp = le->prox;
/*Vamos fazer um while porque enquanto o tempo que for diferente de 'nu' porque lá só a gente 
espera no NULL.*/
    while(tmp != NULL) {
        printf("%d", tmp->valor);
        tmp = tmp->prox; // Se ele é NULL ou não.
    }
    printf("\n\n");
}
//Uma função inserir o  inicio.
void insereInicio(no *le) {
// Criamos uma nova variável *novo

}


