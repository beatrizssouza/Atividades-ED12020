#include <stdio.h>
#include <stdlib.h>
#define TAM  10
typedef enum boolean {False = 0 , True = 1 }Boolean;
typedef int TipoElemento;

typedef struct{
    TipoElemento* vetor;
    int tam;
    int qntde;
}FilaPrioridade;

FilaPrioridade* filaP_criar();
void filaP_destruir(FilaPrioridade* f);
Boolean filaP_inserir(FilaPrioridade* f, TipoElemento elemento);
Boolean filaP_remover(FilaPrioridade* f, TipoElemento* saida);
Boolean filaP_vazia(FilaPrioridade* f);
int filaP_tamanho(FilaPrioridade* f);
void fila_imprimir(FilaPrioridade* f);
FilaPrioridade* filaP_clone(FilaPrioridade* f);
Boolean filaP_inserirTodos(FilaPrioridade* f, TipoElemento* vetor, int tamVetor);

FilaPrioridade* filaP_criar(){
    
    FilaPrioridade* f = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    f->vetor = (TipoElemento*) calloc(TAM,sizeof(TipoElemento));
    f->qntde = 0;
    f->tam = TAM ;
    return f;
}
void filaP_destruir(FilaPrioridade* f){
    free (f->vetor);
    free(f);
}
void troca(TipoElemento* a, TipoElemento* b){
    TipoElemento aux = *a;
    *a = *b;
    *b = aux;
}
void sobeHeap(FilaPrioridade* f, int filho){
    
    int pai = (filho - 1) / 2;
    while((filho > 0 ) && (f->vetor[pai] <= f->vetor[filho])){
        troca(&f->vetor[filho], &f->vetor[pai]);
        filho = pai(filho);
        
    }

}
Boolean filaP_inserir(FilaPrioridade* f, TipoElemento elemento){
    
    if(filaP_vazia(f)) return False;
    if(f->qntde == f->tam) return False;

    f->vetor[f->qntde] = elemento;
    sobeHeap(f,f->qntde);
    f->qntde++;
    return True;
}
void desceHeap(FilaPrioridade* f, int pos){
    
    int aux;
    int filho = 2 * pos + 1;

    while (filho < f->qntde){
        if(filho < f->qntde-1)
            if(f->vetor[filho] < f->vetor[filho+1])
                filho++;
            
            if(f->vetor[pos] >= f->vetor[filho])
                break;
    

        troca(&f->vetor[pos],&f->vetor[filho]);
        pos = filho;
        filho = 2 * pos + 1;
    }
    
}
Boolean filaP_remover(FilaPrioridade* f, TipoElemento* saida){
    if(filaP_vazia(f)) return False;

    f->qntde--;
    *saida = f->vetor[0];
    f->vetor[0] = f->vetor[f->qntde];
    desceHeap(f,0);
    return True;
    
}
Boolean filaP_vazia(FilaPrioridade* f){
    if(filaP_vazia(f)) return True;
    return(f->qntde == 0);
}
int filaP_tamanho(FilaPrioridade* f){
    return(f->qntde);
}

void fila_imprimir(FilaPrioridade* f){
    if(filaP_vazia(f)) return;

    printf("[%d",f->vetor[0]);
    for(int i=1; i < f->qntde;i++){
        printf(",%d,",f->vetor[i]);
    }
    printf("]\n");
}
FilaPrioridade* filaP_clone(FilaPrioridade* f){
    
    FilaPrioridade* clone = filaP_criar();
    for(int i=0; i < f->qntde; i++){
        clone->vetor[i] = f->vetor[i];
    }

    clone->qntde = f->qntde;
    clone->tam = f->tam;
    return clone;

}
Boolean filaP_inserirTodos(FilaPrioridade* f, TipoElemento* vetor, int tamVetor){
    if(filaP_vazia(f)) return False;

    for(int i=0; i< tamVetor; i++){
        int aux= vetor[i];
        filaP_inserir(f,aux);
    }
    return True;
}
