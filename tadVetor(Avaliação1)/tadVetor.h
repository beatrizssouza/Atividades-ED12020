#include<stdio.h>
#include<stdlib.h> // neccessaria para rand - sorteio
#include <string.h>
#include <time.h> // necessaria para srand(sorteio), nao gerar mesmo valor

typedef int TipoElemento;


typedef struct {

    TipoElemento* array;
    int tamVetor;
    int qntdeElemento;

}Vetor;

typedef enum boolean { false = 0, true = 1} Boolean;



Vetor* vet_criar();
Boolean vet_inserirFim(Vetor * v, TipoElemento elemento);
Boolean vet_inserir(Vetor * v, TipoElemento elemento,int posicao);
Boolean vet_substituir(Vetor* v, int posicao, TipoElemento novoElemento);
Boolean vet_removerPosicao(Vetor* v, int posicao, TipoElemento* endereco);
int vet_removerElemento(Vetor* v, TipoElemento elemento);
Boolean vet_elemento(Vetor* v, int posicao, TipoElemento* saida);
int vet_tamanho(Vetor* v);
int vet_posicao(Vetor* v, TipoElemento elemento);
void vet_imprimir(Vetor* v);
void vet_destruir(Vetor* v);
Boolean vet_toString(Vetor* v, char* enderecoString);
void verifica_aumenta(Vetor* v);
void verifica_diminui(Vetor* v);
Vetor* vet_clone(Vetor* v);
void troca(int*a , int* b);
void vet_ordenarBuble(Vetor* v);
void vet_ordenarSelection(Vetor* v);
void vet_ordenarInsertion(Vetor* v);
Vetor* vet_importar(char* nomeArquivo);
Boolean vet_exportar(Vetor* v, char* nomeArquivo);
Vetor* vet_criarAleatorio(int tam);
int vet_tamanho(Vetor* v);


Vetor* vet_criar(){
    Vetor* new;
    new = (Vetor*) malloc (sizeof(Vetor));

    new -> array = (TipoElemento*)calloc(4,sizeof(TipoElemento));
    new -> tamVetor = 4;
    new -> qntdeElemento = 0;
    return new;
}

Boolean vet_inserirFim(Vetor * v, TipoElemento elemento){


    v->array[v->qntdeElemento++] = elemento;
    if (v->qntdeElemento > v->tamVetor)verifica_aumenta(v);
    
    return true;

    
}

Boolean vet_inserir(Vetor * v, TipoElemento elemento,int posicao){
    int aux,aux1;
    aux= v->array[posicao];
    aux1=v->array[posicao+1];
    
    for(int i = posicao+1 ; i <= v->qntdeElemento +1;i++){

        v->array[i] = aux;
        aux = aux1;
        aux1 = v->array[i+1];
        
    }
    v->array[posicao] = elemento;
    v->qntdeElemento++;
    if(v->qntdeElemento == v->tamVetor) verifica_aumenta(v);

    return true;

}

Boolean vet_substituir(Vetor* v, int posicao, TipoElemento novoElemento){

    if(posicao < v->qntdeElemento)
    v->array[posicao] = novoElemento;
    return true;
    

}

 Boolean vet_removerPosicao(Vetor* v, int posicao, TipoElemento* endereco){

    *endereco = v->array[posicao];
    v->array[posicao] = 0;
    v->qntdeElemento -= 1;
    verifica_diminui(v);
    
    return true;

}

int vet_removerElemento(Vetor* v, TipoElemento elemento){
    int aux;
    for(int i=0;i < v->qntdeElemento; i++){
        if(v->array[i] == elemento){
            v->array[i] =0;
            v->qntdeElemento -= 1;
            aux = i;

        }
        verifica_diminui(v);
        return aux;
    }

}
int vet_tamanho(Vetor* v){
    int aux;
    aux = v->qntdeElemento;
    return  aux;
}
Boolean vet_elemento(Vetor* v, int posicao, TipoElemento* saida){
    
    if(posicao <  v->qntdeElemento ){

        *saida = v->array[posicao];
        return saida;
    }
    return false;
}

int vet_posicao(Vetor* v, TipoElemento elemento){

    for(int i=0;i <=  v->qntdeElemento;i++){
        if(elemento == v->array[i]){
            return i;
        }

    }
    return -1;
}

void vet_imprimir(Vetor* v){

    if (v == NULL) return;

    int i;
    printf ("[");
    for(i=0; i < v->qntdeElemento; i++){
        printf("%d", v-> array[i]);
        if(i < v->qntdeElemento-1) printf (",");
    } 
    printf("]");
    printf("\n");
}



void vet_destruir(Vetor* v){
    free(v->array);
    free(v);

}

/* Boolean vet_toString(Vetor* v, char* enderecoString){

} */

void verifica_aumenta(Vetor* v){
    v->tamVetor *=2;

    int* aux = (int *) calloc(v->tamVetor,sizeof(int));
    for(int i=0;i< v->qntdeElemento;i++){
        aux[i] = v->array[i];
    }

    free(v->array);
    v->array = aux;

}

void verifica_diminui(Vetor* v){
    
    if(v->qntdeElemento < v->tamVetor * 0.25){

        int* vetor = (int*) calloc(v->tamVetor/2,sizeof(int));

        for (int i = 0; i < v->qntdeElemento; i++){
            
            vetor[i] =  v->array[i];
        }

        free(v->array);
        v->array = vetor;
        
    }
   
}

Vetor* vet_clone(Vetor* v){

   Vetor* clone = (Vetor*) malloc (sizeof(v->tamVetor));
   clone->array = (TipoElemento*) calloc(v->qntdeElemento,sizeof(TipoElemento));
   
    for(int i = 0; i < v->tamVetor;i++){
        clone->array= v->array[i];
        clone->qntdeElemento++;
    }
  
    return clone;
}


void troca(int* a, int* b){

    int aux = *a;
    *a = *b;
    *b= aux;
}


void vet_ordenarBuble(Vetor* v){

    for(int fim =0; fim < v->qntdeElemento-1; fim++){

        int trocou = 0;

        for(int i = 0; i <  v->qntdeElemento-fim-1; i++){

            if(v->array[i] > v->array[i+1]){
                troca(&v->array[i],&v->array[i+1]);
                trocou = 1;

            }

            if(trocou == 0){
                return;
            }
        }
    }
}
void vet_ordenarSelection(Vetor* v){
    int min_idx;
    
    for(int i=0; i < v->qntdeElemento -1;i++){
        
        min_idx = i;
        for(int j= i+1; j < v->qntdeElemento;j++){
            if(v->array[j] < v->array[min_idx])
            min_idx=j;
        }

        troca(&v->array[min_idx], &v->array[i]);
    }
}
void vet_ordenarInsertion(Vetor* v){

    int key,j;
    for(int i = 1; i < v->qntdeElemento; i++){
        key = v->array[i];
        j = i -1 ;

        while (j >= 0 && v->array[j] > key){
            v->array[j+1] = v->array[j];
            j = j -1;
        }
        v->array[j+1] = key;
        
    }
}


/*  Vetor* vet_importar(char* nomeArquivo){

    Vetor* v;
    FILE *arq = fopen(nomeArquivo,"r");
    char valorStr[11];
    char elemento;
    int numero;
    int qtdNumeros =0;

    if(arq == NULL){
        return;
    }
    else{

        while((elemento = fgetc(arq))  != EOF){

            if(trcmps (&elemento,",")){

                numero = atoi(valorStr);
                vet_inserirFim(v, numero);
                qtdNumeros++;
                

            }else{
                
                strcat(valorStr, &elemento);
            }
            
        }
    }


}  */

Boolean vet_exportar(Vetor* v, char* nomeArquivo){

}

Vetor* vet_criarAleatorio(int tam){

    int* vetor = (int*) calloc (tam,sizeof(int));

    srand(time(NULL));//tempo pra gerar os valores
    for(int i=0;i<tam;i++){
        vetor[i] = rand()%2000;
    }
    return vetor;

    
}


