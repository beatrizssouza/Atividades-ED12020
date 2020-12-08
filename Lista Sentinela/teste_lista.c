#include<string.h>
#include "lista_sentinela.h"
#include "tad_teste.h"


/**
 * INSERIR
 * Teste das funções inserirFim e inserir
*/
void teste_inserir(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE INSERIR \n");
    printf("------------------------------------------------\n");
    char str[500];
    
    Lista* l = lista_criar();
    lista_inserirFim(l, 10);
    lista_inserirFim(l, 20);
    lista_inserirFim(l, 30);
    lista_toString(l,str);
    test(strcmp(str, "[10,20,30]")==0, "A saída deve ser [10,20,30]");

    // inicio
    lista_inserir(l, 5, 0);
    lista_inserir(l, 3, 0);
    lista_toString(l,str);
    test(strcmp(str, "[3,5,10,20,30]")==0, "A saída deve ser [3,5,10,20,30]");

    // fim
    lista_inserir(l, 40, 5);
    lista_inserir(l, 50, 6);
    
    // meio
    lista_inserir(l, 15, 3);
    lista_inserir(l, 45, 7);
    lista_toString(l,str);
    test(strcmp(str, "[3,5,10,15,20,30,40,45,50]")==0, "A saída deve ser [3,5,10,15,20,30,40,45,50]");
    
}

/**
 * REMOVER
 * Teste da função remover por posição
*/
void teste_removerPosicao(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE REMOVER POR POSICAO\n");
    printf("------------------------------------------------\n");
    char str[500];
    TipoElemento item;

    Lista* l = lista_criar();
    lista_inserirFim(l, 10);
    lista_inserirFim(l, 20);
    lista_inserirFim(l, 30);
    lista_inserirFim(l, 40);
    lista_inserirFim(l, 50);



    lista_removerPosicao(l, 0, &item);
    lista_toString(l,str);
    test(item == 10, "Item removido deve ser o 10");
    test(strcmp(str, "[20,30,40,50]")==0, "A saída depois da remoção [20,30,40,50]");

    lista_removerPosicao(l, 3, &item);
    lista_toString(l,str);
    test(item == 50, "Item removido deve ser o 50");
    test(strcmp(str, "[20,30,40]")==0, "A saída depois da remoção [20,30,40]");
    
    lista_removerPosicao(l, 1, &item);
    lista_toString(l,str);
    test(item == 30, "Item removido deve ser o 30");
    test(strcmp(str, "[20,40]")==0, "A saída depois da remoção [20,40]");
    
    lista_removerPosicao(l, -1, &item);
    lista_toString(l,str);
    test(item == 40, "Item removido deve ser o 40");
    test(strcmp(str, "[20]")==0, "A saída depois da remoção [20]");

    lista_removerPosicao(l, -1, &item);
    lista_toString(l,str);
    test(item == 20, "Item removido deve ser o 20");
    test(strcmp(str, "[]")==0, "A saída depois da remoção []");

    item = -1;
    lista_removerPosicao(l, -1, &item);
    lista_toString(l,str);
    test(item == -1, "Nenhum elemento deve ser removido");
    test(strcmp(str, "[]")==0, "A saída depois da remoção []");
}

/**
 * REMOVER POR ELEMENTO
 * Teste da função remover por elemento
*/
void teste_removerElemento(){
    printf("\n------------------------------------------------\n");
    printf(">>> TESTE REMOVER POR ELEMENTO\n");
    printf("------------------------------------------------\n");
    
    Lista* l = lista_criar();
    lista_inserirFim(l, 10);
    lista_inserirFim(l, 20);
    lista_inserirFim(l, 30);
    lista_inserirFim(l, 40);
    lista_inserirFim(l, 50);

    int posicao;
    char str[500];


    
    posicao = lista_removerElemento(l, 100);
    test(posicao == -1, "Elemento nao encontrado");
    lista_toString(l,str);
    test(strcmp(str, "[10,20,30,40,50]")==0, "A saída depois da remoção [10,20,30,40,50]");

    

    
    posicao = lista_removerElemento(l, 10);
    test(posicao == 0, "Posicao do elemento removido: 0");
    lista_toString(l,str);
    test(strcmp(str, "[20,30,40,50]")==0, "A saída depois da remoção [20,30,40,50]");


    posicao = lista_removerElemento(l, 50);
    test(posicao == 3, "Posicao do elemento removido: 3");
    lista_toString(l,str);
    test(strcmp(str, "[20,30,40]")==0, "A saída depois da remoção [20,30,40]");

    posicao = lista_removerElemento(l, 30);
    test(posicao == 1, "Posicao do elemento removido: 1");
    lista_toString(l,str);
    test(strcmp(str, "[20,40]")==0, "A saída depois da remoção [20,40]");

    
    
    posicao = lista_removerElemento(l, 40);
    test(posicao == 1, "Posicao do elemento removido: 1");
    lista_toString(l,str);
    test(strcmp(str, "[20]")==0, "A saída depois da remoção [20]");

    posicao = lista_removerElemento(l, 20);
    test(posicao == 0, "Remocao do ultimo elemento posicao 0");
    lista_toString(l,str);
    test(strcmp(str, "[]")==0, "A saída depois da remoção []");
    
    posicao = lista_removerElemento(l, 40);
    test(posicao == -1, "Elemento nao encontrado");
    lista_toString(l,str);
    test(strcmp(str, "[]")==0, "A saída depois da remoção []");
    
}



int main(){

    printf("TESTES\n");

    teste_inserir();
    //teste_removerPosicao();
    teste_removerElemento();

    report();
 

}