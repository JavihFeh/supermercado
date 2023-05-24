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
        printf ("Tentativas esgotadas! Encerrando sistema...");
        exit(0);
    }
    
    return 0;
}

void pagar(float compra, float *notas, int *notas_recebidas)
{
    float total = 0;
    int i, aux;
    for(i = 0; i < 7; i++)
    {
        if(compra >= notas[i])
        {
            printf("Quantas notas de %.2f? ",notas[i]);
            scanf("%d",&aux);
            
            total += aux * notas[i];
            notas_recebidas[i] = aux;
        }
        if(total >= compra)
        {
            break;
        }
        if(i == 6 && total < compra)
        {
            system("cls");
            printf("Pagamento insuficiente! Tente novamente...\n\n");
            i = 0;
        }
    }

}

void troco(float troco, int *qtd,float *notas){
    int i;
    int n_usadas[7] = {0,0,0,0,0,0,0};
    for (i = 0; i < 7; i++)
    {
        while (troco >= notas[i] && qtd[i] > 0)
        {
            qtd[i]--;
            n_usadas[i]++;
            troco -= notas[i];
        }
    }
    if(troco != 0)
    {
        printf("%f Troco insuficiente! \n",troco);
        for (i = 0; i < 7; i++)
        {
            qtd[i] += n_usadas[i];
        }
    }
    else
    {
        printf("O troco e: \n\n");
        for(i=0; i < 7; i++)
        {
        if(n_usadas[i] != 0)
            {
                printf("%d nota(s)/moeda(s) de %.2f\n",n_usadas[i],notas[i]);
            }
        }
        printf("\n\n");
    }
}

float caixa()
{
    float total = 0,produto,anterior;
    int i = 1;
    printf("Registrando nova compra... \n\nPara terminar a compra digite 0\nPara alterar o ultimo valor digite -1\nPara cancelar o pedido digite -2\n\n");
    do
    {
        
        printf("Qual valor do produto %d? ",i);
        scanf("%f",&produto);
        if(i > 0 && produto == -1)
        {
            i--;
            total -= anterior;
            printf("\nAlterando o valor do produto %d. Qual o novo valor?  ",i);
            scanf("%f",&produto);
        }
        anterior = produto;
        total += produto;
        i++;

        system("cls");
        printf("Total da compra: %.2f \n",total);
    }while(produto == -1 || produto > 0);

    if(produto == -2)
    {
        system("cls");
        printf("Compra cancelada! \n \n");
        total -= total;
    }
    return total;
    
}


int main()
{

    float total = 0, compra;
    int c_vendas = 0, c_cancel = 0, aux,i;
    float notas[7] = {200,100,50,10,5,1,0.5};
    int qtd_notas[7] = {2,4,6,10,10,20,20};
    
    login();
    
    do{
        float estorno = 0;
        int notas_recebidas[7] = {0,0,0,0,0,0,0};
        printf("1 - Registrar nova venda \n2 - Resumo do caixa\n3 - Fechar o caixa \n \n");
        scanf("%d",&aux);
        system("cls");
        if(aux == 1)
        {
            compra = caixa();
            if(compra != 0)
            {
                pagar(compra, notas, notas_recebidas);
                for(i = 0; i < 7; i++)
                {
                    qtd_notas[i] += notas_recebidas[i];
                    estorno += notas_recebidas[i] * notas[i];
                }
                estorno = estorno - compra;

                system("cls");

                troco(estorno, qtd_notas, notas);
                c_vendas += 1;
                total += compra;
            }
            else
            {
                c_cancel += 1;
            }
        }
        if(aux == 2)
        {
            system("cls");
            printf("Valor total em vendas: %.2f \nNumero de vendas: %d \nCompras canceladas: %d\nValor no caixa:\n",total,c_vendas,c_cancel);
            for(i=0; i < 7; i++)
                {
                    if(qtd_notas[i] != 0)
                    {
                        printf(".....%d nota(s)/moeda(s) de %.2f\n",qtd_notas[i],notas[i]);
                 }
                }
        }

    }while(aux != 3);
    system("cls");
    printf("Fechando o caixa...\n\nValor total em vendas: %.2f \nNumero de vendas: %d \nCompras canceladas: %d\nValor no caixa:\n",total,c_vendas,c_cancel);
    for(i=0; i < 7; i++)
        {
            if(qtd_notas[i] != 0)
            {
                printf(".....%d nota(s)/moeda(s) de %.2f\n",qtd_notas[i],notas[i]);
            }
        }
        printf("\n\nAte breve.............");
    
    return 0;
}

