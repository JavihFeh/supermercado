int login()
{
    char senha[10];
    printf("Digite a senha: ");
    do
    {
        scanf("%s",senha);
        if(strcmp(senha,"senha") != 0)
        {
            printf("Senha incorreta! Digite novamente... \n \n");
        }
        else
        {
            printf("Iniciando sistema de vendas... \n \n");
        }
    }while(strcmp(senha,"senha") != 0);
    
    return(0);
}


float venda(float x)
{
    float produto,troco,total = 0;
    printf("Digite um numero negativo para finalizar a compra... \n");
    do
    {
        printf("Qual valor do produto? ");
        scanf("%f",&produto);
        if(produto >= 0)
        {
            x += produto;
            total += produto;
        }
    }while(produto >= 0);
    
    do
    {
        printf("Quanto foi pago? ");
        scanf("%f",&troco);
    }while(total > troco);
    printf("O troco é %.2f \n \n",troco - total);
    return x;
}

int main()
{
    float total;
    int c_vendas,aux;
    
    login();
    
    volta:
    printf("1 - Registrar nova venda \n2 - Encerrar programa \n \n");
    scanf("%d",&aux);
    if(aux == 1)
    {
        total = venda(total);
        c_vendas +=1;
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
    printf("Valor total em vendas: %.2f, numero de vendas: %d",total,c_vendas);
    return 0;
    
}

