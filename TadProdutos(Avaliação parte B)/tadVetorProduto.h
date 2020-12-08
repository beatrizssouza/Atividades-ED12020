#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int codigo;
	char descricao[120];
	float preco;
}Produto;

typedef struct{
	Produto* array;
	int tamVetor;
	int qtdeElementos;
}Vetor;

typedef Produto TipoElemento;
typedef enum boolean { False = 0, True = 1} Boolean;

Vetor* vet_criar();
Boolean  vet_inserirFim(Vetor * v, TipoElemento elemento);
void verifica_aumenta(Vetor* v);

Vetor* vet_criar(){

    Vetor* nova;
    nova = (Vetor*) malloc (sizeof(Vetor));

    nova-> array = (Produto*)calloc(5,sizeof(Produto));
    nova -> tamVetor = 5;
    nova -> qtdeElementos = 0;
    return nova;
}
Produto* criar_produto(int codigo, char* descricao, float preco){
    Produto* novo = (Produto*) malloc(sizeof(Produto));
    novo->codigo = codigo;
    strcpy(novo->descricao, descricao);
    novo->preco = preco;
    return novo;
}
Boolean  vet_inserirFim(Vetor * v, TipoElemento elemento){
    vetor_add_verifica(v);

    if(v == NULL) return false;
    
    v->array[v->qtdeElementos++] = elemento;
    return True;
}
void vetor_add_verifica(Vetor* v){
    if(v->qtdeElementos == v->tamVetor) verifica_aumenta(v);
    else return;
}
void verifica_aumenta(Vetor* v){
    v->tamVetor *= 2;
    Produto* aux = (Produto *)calloc(v->tamVetor,sizeof(Produto));
    for(int i=0;i< v->qtdeElementos;i++){
        aux[i] = v->array[i];
    }
    free(v->array);
    v->array = aux;
} 



