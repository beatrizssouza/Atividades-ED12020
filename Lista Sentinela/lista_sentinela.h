#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef enum boolean{False=0, True=1} Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;
typedef struct {
	No *sentinela;
	int qtde;
}Lista;

/**************************************
* PROTÓTIPOS
**************************************/
Lista* lista_criar();
void lista_destruir(Lista* l);
Boolean lista_inserirFim(Lista* l, TipoElemento elemento);
Boolean lista_inserir(Lista* l, TipoElemento elemento, int posicao);
Boolean lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco);
int lista_removerElemento(Lista* l, TipoElemento elemento);
Boolean lista_substituir(Lista* l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista* l, TipoElemento elemento);
Boolean lista_buscar(Lista* l, int posicao, TipoElemento* endereco);
Boolean lista_contem(Lista* l, TipoElemento elemento);
int lista_tamanho(Lista* l);
Boolean lista_toString(Lista* l, char* enderecoString);
void lista_imprimir(Lista* l);

/* Funções auxiliares */

No* criarNo(TipoElemento elemento){
    No* n = (No*)malloc (sizeof(No));
    n->dado = elemento;

    return n;
}
No* criar_noSentinela(){
    No* no = (No*)malloc(sizeof(No));
    no->ant = no;
    no->prox = no;
    return no;
}
void destroi_no(No* no,No* aux,Lista* l){
    while(l->qtde != 0){
        free(no);
        no= aux;
        aux = aux->prox;
        l->qtde--;
    }
}
Boolean lista_valida(Lista* l){
    return(l != NULL? True: False);
}
int converte_posicao(Lista* l,int pos){
    return (pos < 0? l->qtde + pos : pos);
}
Boolean posicao_ehPreenchida(Lista* l,int pos){
    if(pos < 0) return False;
    if(pos >= l->qtde) return False;

    return True;
}
Boolean posicao_valida(Lista* l, int pos){
    if(pos < 0) return False;
    if(pos > l->qtde) return False;

    return True;
}
No* BuscaNo(Lista* l, int posicao){
   
    No* aux = l->sentinela;
    
        for(int i=0; i < posicao; i++){
            aux= aux-> prox;
        }
    
    return aux;
}
void insere_direita(No* referencia, No* novo){
    novo->ant = referencia;
    novo->prox = referencia->prox;

    referencia->prox->ant = novo;
    referencia->prox = novo;
}
/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções

Lista* lista_criar(){

    Lista* lista =(Lista*)malloc(sizeof(Lista));
    lista->sentinela = criar_noSentinela();
    lista->qtde = 0;

    return lista;
}

void lista_destruir(Lista* l){
    if(l->qtde !=0){
        destroi_no(l->sentinela,l->sentinela->prox,l);
    }
    free(l);
}
Boolean lista_inserirFim(Lista* l, TipoElemento elemento){

    if(!lista_valida(l)) return False;

    lista_inserir(l,elemento,l->qtde);
    return True;
    
}
Boolean lista_inserir(Lista* l, TipoElemento elemento, int posicao){
   
    if(!lista_valida(l)) return False;
   
    posicao = converte_posicao(l,posicao);
    if(!posicao_valida(l,posicao)) return False;
    
    No* novo = criarNo(elemento); 
    No* aux = BuscaNo(l, posicao-1);
        
    l->qtde++;
    return True;
    
}
Boolean lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){

    if(!lista_valida(l)) return False;
    posicao = converte_posicao(l,posicao);
    if(!posicao_ehPreenchida(l,posicao)) return False;

    No* aux = BuscaNo(l,posicao);
    *endereco = aux->dado;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    aux->ant = aux->prox = NULL;
    free(aux);
    l->qtde--;
    

    return True;
}
int lista_removerElemento(Lista* l, TipoElemento elemento){

    if(!lista_valida(l)) return False;

    No* aux;
    aux = l->sentinela;

    for(int i=0;i <= l->qtde; i++){
        if(elemento == aux->dado)
            break;
        aux = aux->prox;
    }

    if(aux != l->sentinela){
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        
        free(aux);
        l->qtde--;
        return True;
    }
    return False;
}


Boolean lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){

    if(posicao > l->qtde || l == NULL) return False;
    posicao = converte_posicao(l,posicao);
    if(!posicao_ehPreenchida(l,posicao)) return False;
    No* aux = BuscaNo(l,posicao);
    aux->dado = novoElemento;
    return True;
    
} 
int lista_posicao(Lista* l, TipoElemento elemento){

    No* aux = l->sentinela->prox;
    int pos = -1;
    for(int i=0; i < l->qtde;i++){
        if(aux->dado == elemento){
            pos = i;
            break;
        }
        aux = aux->prox;
    }

    return pos;
}
Boolean lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    
    if(l != NULL && posicao < l->qtde){
        No* aux = BuscaNo(l,posicao);
        *endereco = aux->dado;

        return True;
    }
    return False;

    
}
Boolean lista_contem(Lista* l, TipoElemento elemento){
    int a = lista_posicao(l,elemento);

    if(a == -1){
        return False;
    }else{
        return True;
    }
}
int lista_tamanho(Lista* l){
    return l->qtde;
}
 Boolean lista_toString(Lista* l, char* enderecoString){

    int qtde = 0;
    char str[10];

    enderecoString[qtde++]= '[';
    No* aux = l->sentinela->prox;
    while(aux != l->sentinela){
        sprintf(str,"%d",aux->dado);
        int numCaracteres = strlen(str);
        memcpy(enderecoString+qtde,str,numCaracteres*sizeof(char));
        qtde += numCaracteres;

        if(aux->prox != l->sentinela){
            enderecoString[qtde++] = ',';
        }

        aux= aux->prox;
    }

    enderecoString[qtde++] = ']';
    enderecoString[qtde] = '\0';
    return True;
} 
void lista_imprimir(Lista* l){

    if(l != NULL){
        No*  aux = l->sentinela->prox;
        printf("Lista: [ ");
        for(int i=0; i < l->qtde; i++){
            printf("%d",aux->dado);
            printf("%s",(aux->dado == l->sentinela->ant->dado ? "]\n" : ","));
            aux = aux->prox;
        }
    }else{
        
        printf("\n Lista Inexistente \n");
    }
    
}
