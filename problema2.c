#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Produtos
{
    int codigo;
    char descricao[50];
    float precounit;
};

struct Carrinho
{
    int numitem;
    int codigoprod[100];
    int qtd[100];
    float preco[100];
    float precototal[100];
};

int main(int argc, char const *argv[])
{

    char ListaProdutos[10][3][50] = {
        {"12311", "COCA-COLA 2 LT", "5.98"},
        {"13111", "FANTA 2 LT", "5.23"},
        {"14422", "SKOL LATINHA", "2.98"},
        {"14221", "SKOL GARRAFA", "3.11"},
        {"12324", "PACOTE BISNAGUINHA 12U", "12.57"},
        {"14811", "CHEETOS SABOR REQUEIJÃO", "7.79"},
        {"19981", "BOLACHA MAIZENA", "6.50"},
        {"12311", "DORITOS PIMENTA", "3.39"},
        {"12701", "CAIXA DE MENTOS", "5.15"},
        {"15431", "FARINHA DE TRIGO 1KG", "8.25"},
    };

    //*Carregar Produtos;

    struct Produtos ProdutosDisponiveis[10];

    for (int i = 0; i < 10; i++)
    {
        ProdutosDisponiveis[i].precounit = atof(ListaProdutos[i][2]);
        strcpy(ProdutosDisponiveis[i].descricao, ListaProdutos[i][1]);
        ProdutosDisponiveis[i].codigo = (int)ListaProdutos[i][0];
    }

    bool continueloop = true;

    int count = 0;

    while (continueloop)
    {
        //*Mostrar Produtos;

        printf("PRODUTOS:\n\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d. %s - R$%.2f\n", i + 1, ProdutosDisponiveis[i].descricao, ProdutosDisponiveis[i].precounit);
        }

        printf("\n\nDigite os numeros dos prdutos desejados(digite 0 para sair e ver o carrinho):\n");

        //*Colocar no Carrinho

        struct Carrinho carrinho;
        carrinho.numitem = 0;

        int escolha;
        scanf("%d", &escolha);
        
        if (escolha == 0)
        {
            continueloop = false;
        }
        else
        {
            count++;
            carrinho.numitem +=1;
            carrinho.preco[count] = ProdutosDisponiveis[escolha-1].precounit;
            carrinho.codigoprod[count] = ProdutosDisponiveis[escolha-1].codigo;          

        }
        


        //*Exibir total;
    }

    return 0;
}
