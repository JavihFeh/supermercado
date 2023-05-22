#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int login()
{
    char senha[10];
    int tentativas = 3;
    do
    {
        printf("Digite a senha: ");
        scanf("%s",senha);
        if(strcmp(senha,"senha") != 0)
        {
            system("cls");
            tentativas -= 1;
            printf("Senha incorreta! Voce tem %d tentativas\n \n",tentativas);
        }
        else
        {
            system("cls");
            printf("Iniciando sistema de vendas... \n \n");
        }
    }while(strcmp(senha,"senha") != 0 && tentativas > 0);

    if (tentativas == 0)
    {
        printf ("Tentativas expiradas! Encerrando sistema...");
        exit(0);
    }
    
    return 0;
}


float venda(float x)
{
    float produto,troco,total = 0;
    printf("Para terminar a compra digite -1, para cancelar o pedido digite -2 ou menos... \n");
    do
    {
        
        printf("Qual valor do produto? ");
        scanf("%f",&produto);
        if(produto >= 0)
        {
            x += produto;
            total += produto;
        }
        system("cls");
        printf("Total da compra: %.2f \n",total);
    }while(produto >= 0);

    if(produto == -1)
    {
        do
        {
            printf("Quanto foi pago? ");
            scanf("%f",&troco);

            if(total > troco)
            {
                system("cls");
                printf("Total da compra: %.2f \n",total);
                printf("Valor insuficiente! \n \n");
            }
        }while(total > troco);
        system("cls");
        printf("O troco e %.2f \n \n",troco - total);
    }
    else
    {
        system("cls");
        printf("Compra cancelada! \n \n");
        x -= total;
    }

    return x;
    
}

int main()
{
    float total = 0, v_total;
    int c_vendas = 0, c_cancel = 0, aux;
    
    login();
    
    volta:
    printf("1 - Registrar nova venda \n2 - Fechar o caixa \n \n");
    scanf("%d",&aux);
    if(aux == 1)
    {
        v_total = total;
        total = venda(total);
        if(v_total < total)
        {
            c_vendas += 1;
        }
        else
        {
            c_cancel += 1;
        }
        goto volta;
    }
    else
        if(aux == 2)
        {
            goto fim;
        }
        else
        {
            printf("Operador invalido! \n \n");
            goto volta;
        }
    fim:
    printf("Valor total em vendas: %.2f \nNumero de vendas: %d \nCompras canceladas: %d",total,c_vendas,c_cancel);
    return 0;
    
}

