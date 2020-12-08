#include "pilha.h"


/**************************************
* DADOS
**************************************/

typedef struct {
	Pilha* p1;
    Pilha* p2;
	int qtdeElementos;
}Fila;

/**************************************
* PROTÓTIPOS
**************************************/
Fila* fila_criar();
void fila_destruir(Fila* f);
Boolean fila_inserir(Fila* f, TipoElemento elemento);
Boolean fila_remover(Fila* f, TipoElemento* saida); // estratégia do scanf
Boolean fila_primeiro(Fila* f, TipoElemento* saida); // estratégia do scanf
Boolean fila_vazia(Fila* f);


/**************************************
* EXERCICIO 02
**************************************/

Fila* fila_criar(){
   Fila* nova = (Fila*)malloc(sizeof(Fila));
   nova->p1 = pilha_criar();
   nova->p2 = pilha_criar();
   nova->qtdeElementos = 0;

   return nova;

}

void fila_destruir(Fila* f){
   pilha_destruir(f->p1);
   pilha_destruir(f->p2);
   free(f);

}

Boolean fila_inserir(Fila* f, TipoElemento elemento){
    if(f == NULL) return false;
	while (!pilha_vazia(f->p2)){
		TipoElemento item;
		pilha_desempilhar(f->p2,&item);
		pilha_empilhar(f->p1,item);
	}
	
	 pilha_empilhar(f->p1, elemento);
	 f->qtdeElementos++;

	return true;
	
}

Boolean fila_remover(Fila* f, TipoElemento* saida){ // estratégia do scanf
   if(f == NULL || pilha_vazia(f->p2) && pilha_vazia(f->p1)) return false;
	
	while (!pilha_vazia(f->p1)){
		 TipoElemento item;
		 pilha_desempilhar(f->p1,&item);
		 pilha_empilhar(f->p2,item);
	 }
	 pilha_desempilhar(f->p2,saida);
	 f->qtdeElementos--;
	 return true;
}

Boolean fila_primeiro(Fila* f, TipoElemento* saida){// estratégia do scanf
    if(f == NULL || pilha_vazia(f->p2) && pilha_vazia(f->p1)) return false;

	while (!pilha_vazia(f->p1)){
		TipoElemento item;
		pilha_desempilhar(f->p1,&item);
		pilha_empilhar(f->p2,item);
	}
	
	*saida = f->p2->topo->dado;
	return true;
	
}

Boolean fila_vazia(Fila* f){
	if(!f) return false;
	return(f->qtdeElementos == 0 ? true:false);
}



