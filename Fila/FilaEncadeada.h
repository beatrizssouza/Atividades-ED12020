#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{True = 1 , False =0}Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

typedef struct {
	No *topo;
    No *final;
	int qtdeElementos;
}Fila;

/**************************************
* PROTÓTIPOS
**************************************/
Fila* fila_criar();
No* criar_no(TipoElemento elemento);
void desalocar_no(No* no);
void fila_destruir(Fila* f);
Boolean fila_vazia(Fila* f);
Boolean fila_inserir(Fila* f, TipoElemento elemento);
Boolean fila_remover(Fila* f, TipoElemento* saida); // estratégia do scanf
Boolean fila_primeiro(Fila* f, TipoElemento* saida); // estratégia do scanf
int fila_tamanho(Fila* f);
void fila_imprimir(Fila* f);
Fila* fila_clone(Fila* f);
Fila* fila_inverter(Fila* f);
Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor);

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções
Fila* fila_criar(){
    Fila* nova = (Fila*) malloc(sizeof(Fila));
    nova->qtdeElementos = 0;
    nova->topo = NULL;
    nova->final = NULL;
    return nova;
  
}
No* criar_no(TipoElemento elemento){
    No* nova  = (No*)malloc(sizeof(No));
    nova->dado = elemento;
    nova->prox = NULL;
    return nova;
}
void desalocar_no(No* no){
    if(no == NULL) return;
    desalocar_no(no->prox);
    free(no);
}
void fila_desalocar(Fila* f){
    fila_vazia(f);
    desalocar_no(f->topo);
    free(f);
}

Boolean fila_vazia(Fila* f){
    
    if(f == NULL || f->topo == NULL) {
        printf("Fila esta vazia \n");
        return False;
    }
}
Boolean fila_inserir(Fila* f, TipoElemento elemento){
    fila_vazia(f);

    No* salva = criar_no(elemento);
    if(f->topo == NULL){
        f->topo = salva;
    }else{
        f->final->prox = salva;
    }

    f->final = salva;
    f->qtdeElementos++;
    return True;
}
Boolean fila_remover(Fila* f, TipoElemento* saida){
 fila_vazia(f);

 TipoElemento removido = f->topo->dado;
 No* aux = f->topo->prox;
 free(f->topo);
 f->topo = aux;
 f->qtdeElementos--;
 *saida = removido;

 return True;
}
Boolean fila_primeiro(Fila* f, TipoElemento* saida){
    fila_vazia(f);

    *saida = f->topo->dado;
    return True;
}
int fila_tamanho(Fila* f){
    fila_vazia(f);
     
    return  f->qtdeElementos;

}
void fila_imprimir(Fila* f){

    fila_vazia(f);

    printf("Elementos: [");
    No* aux = f->topo;
    while (aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}
//Adiciona de maneira recursiva
void push_recursivo(Fila*f, No* no){
    push_recursivo(f,no->prox);
    fila_inserir(f,no->dado);
}
Fila* fila_clone(Fila* f){
    
    Fila* clone = fila_criar();
    push_recursivo(clone,f->topo);
    return clone;
}

Fila* fila_inverter(Fila* f){

    Fila* invertida = fila_criar();
    No* aux =  f->topo;
    while (aux != NULL){
        fila_inserir(invertida,aux->dado);
        aux = aux->prox;      
    }
    return invertida;

}
Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor){
    fila_vazia(f);

    for(int i=0; i < tamVetor;i++){
        fila_inserir(f,vetor[i]);
    }
    return True;
}
