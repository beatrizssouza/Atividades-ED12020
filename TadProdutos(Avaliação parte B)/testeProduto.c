#include <stdio.h>
#include <stdlib.h>
#include "tadVetorProduto.h"

int main(){
    Vetor* v1 =vet_criar();
    Produto p1 = {20,"teclado",38.60};
    vet_inserirFim(v1, p1);

}