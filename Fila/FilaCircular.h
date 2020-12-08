#include <stdio.h>
#include <stdlib.h>
//FilaCircular.h

typedef enum boolean{false=0,true=1} Boolean;
typedef int TipoElemento;

/**************************************
* DADOS
**************************************/
typedef struct {
	TipoElemento* vetor;
	int tam;
	int inicio;
	int fim;
	int qtde;
}Fila;

/**************************************
* PROTÓTIPOS
**************************************/

Fila* fila_criar();
void fila_destruir(Fila* f);
void aumenta_fila(Fila* f);
Boolean fila_inserir(Fila* f, TipoElemento elemento);
Boolean fila_remover(Fila* f, TipoElemento* saida); // estratégia do scanf
Boolean fila_primeiro(Fila* f, TipoElemento* saida); // estratégia do scanf
Boolean fila_vazia(Fila* f);
int fila_tamanho(Fila* f);
void fila_imprimir(Fila* f);
Fila* fila_clone(Fila* f);
void fila_inverter(Fila* f);
Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor);

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Desenvolva as funções
Fila* fila_criar(){
	Fila* nova = (Fila*)malloc(sizeof(Fila));
	nova->vetor = (TipoElemento*)calloc(5,sizeof(TipoElemento));
	nova->tam = 5;
	nova->inicio = 0;
	nova->fim = 0;
	nova->qtde = 0;
	return nova;

}
void fila_destruir(Fila* f){
	fila_vazia(f);

	free(f->vetor);
	free(f);
}
void aumenta_fila(Fila* f){
	int i,j;
	TipoElemento* copia = (TipoElemento*)calloc(f->tam*2,sizeof(TipoElemento));
	
	for(i= f->inicio,j=0;i < f->fim;i++,j++){
		copia[j] = copia[i];
	}

	f->vetor =(TipoElemento*)calloc(f->tam+5,sizeof(TipoElemento));

	for(i=0;i < j;i++){
		f->vetor[i] = copia[i];
	}

	f->tam += 5;
	f->inicio = 0;
	f->fim = i;
	free(copia);

}
Boolean fila_inserir(Fila* f, TipoElemento elemento){
	fila_vazia(f);

	if(f->inicio == 0 || f->inicio > f->fim && f-> fim < (f->tam)){

		f->vetor[f->fim] = elemento;
		f->fim++;
	}
	if(f->inicio == 0 && f->fim == f->tam){
		aumenta_fila(f);
		return true;
	}
}
Boolean fila_remover(Fila* f, TipoElemento* saida){
	fila_vazia(f);

	if(f->inicio == f->fim){
		f->fim = 0;
		f->inicio = 0;
		return -1;

	}
	int i= f->inicio;
	*saida = f->vetor[i];
	f->inicio++;

	if(f->inicio >= f->tam){
		f->inicio = 0;
	}
}
Boolean fila_primeiro(Fila* f, TipoElemento* saida){
	fila_vazia(f);

	*saida = f->vetor[f->inicio];
	return true;
}
Boolean fila_vazia(Fila* f){
	if(f == NULL) return true;
}
int fila_tamanho(Fila* f){
	fila_vazia(f);

	return f->tam;
}
void fila_imprimir(Fila* f){
	fila_vazia(f);

	if(f->vetor == NULL || f->inicio == f->fim){
		printf("Fila Vazia \n");
	}
	else if(f-> fim < f->inicio){
		int j;
		printf("Elementos: [ ");
		for(int j = f->inicio; j < f->tam; j++){
			printf("%d",f->vetor[j]);
		}
		for(j=0;j < f-> fim ; j++){
			printf("%d",f->vetor[j]);
		}
		printf("]\n");
	}else {
		printf("Elementos: [");
		for(int i=f->inicio;i < f->fim; i++){
			printf("%d",f->vetor[i]);
		}
		printf("]\n");
	}
}
Fila* fila_clone(Fila* f){
	Fila* copia = (Fila*) malloc (sizeof(Fila));

	copia->tam = f->qtde;
	copia->qtde = f->qtde;
	copia->vetor = (TipoElemento*) calloc (f->qtde,sizeof(TipoElemento));
	for(int i=0;i < f->qtde;i++){
		copia->vetor[i] =  f->vetor[i];
	}
	return copia;
}
void fila_inverter(Fila* f){
	TipoElemento* aux = (TipoElemento*) calloc(f->qtde,sizeof(TipoElemento));

	for(int i =(f->qtde-1),j=0;i >= 0;i--){
		aux[j] = f->vetor[j];
		j++;
	}
	for(int i=0;i<f->qtde;i++){
		f->vetor[i] = aux[i];
	}

	free(aux);
}
Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor){
	while (f->qtde + tamVetor > f->tam){
		aumenta_fila(f);
	}
	for (int i = f->qtde,j=0; j < tamVetor; i++){
		f->vetor[i] = vetor[j];
		f->qtde++;
		j++;
	}
	
	
}

