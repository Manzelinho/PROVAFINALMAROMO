#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Cliente
{
    char nome[256];
    int cpf;
} Clientes;

typedef struct Conta
{
    int numero_da_conta;
    struct Cliente cliente;
    float saldo;
} Contas;

void Sacar(Contas *conta)
{
    float valorDoSaque;
    printf("Digite o Valor do saque:\n");
    scanf("%f", &valorDoSaque);

    if (valorDoSaque < 0)
    {
        printf("Digite um valor válido\n");
    }
    else
    {
        if ((conta->saldo - valorDoSaque) < 0)
        {
            printf("Saque invalido devido a falta de dinheiro\n");
        }
        else if (valorDoSaque == 0)
        {
            printf("Transação nao realizada\n");
        }

        else
        {
            conta->saldo = conta->saldo - valorDoSaque;
            printf("Transação efetuada com sucesso\n");
        }
    }
};

void Depositar(Contas *conta)
{
    float valorDoDeposito;
    printf("Digite o Valor do Deposito:\n");
    scanf("%f", &valorDoDeposito);

    if (valorDoDeposito < 0)
    {
        printf("Digite um valor válido\n");
    }
    else if (valorDoDeposito == 0)
    {
        printf("Transação nao realizada\n");
    }
    else
    {
        conta->saldo = conta->saldo + valorDoDeposito;
        printf("Transação efetuada com sucesso\n");
    }
};

void ExibirSaldo(Contas *conta)
{
    printf("Saldo Atual: %.2f $\n", conta->saldo);
};

void inicializarconta(Contas *conta)
{
    printf("Digite a seguir os dados para criar sua conta:\n");

    printf("Numero da Conta: ");
    scanf("%d", &conta->numero_da_conta);

    printf("\n");

    printf("Nome Cliente: ");
    scanf("%s", &conta->cliente.nome);

    printf("\n");

    printf("CPF: ");
    scanf("%d", &conta->cliente.cpf);

    printf("\n");

    printf("Saldo Inicial: ");
    scanf("%f", &conta->saldo);
}

int main(int argc, char const *argv[])
{
    // inicializar conta
    Contas *ptr, contaInicial;
    ptr = &contaInicial;

    // funcçãoi para definir a conta
    inicializarconta(ptr);
    // funcionalidades;

    printf("%f", contaInicial.saldo);
    bool continueloop = true;

    while (continueloop)
    {
        int escolha;

        printf("Opcoes:\n\n");

        printf("1.Sacar\n");
        printf("2.Depositar\n");
        printf("3.Exibir Saldo\n");
        printf("4.Sair\n");

        printf("\nDigite o numero desejado conforme o caso:\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            Sacar(ptr);
            break;

        case 2:
            Depositar(ptr);
            break;

        case 3:
            ExibirSaldo(ptr);
            break;

        case 4:
            continueloop = false;
            break;

        default:
            break;
        }
    }

    printf("Obrigado por os contratrar\n");

    return 0;
}
