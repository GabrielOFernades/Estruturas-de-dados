#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int valor;
	struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num)
{
	No *placeholder, *novo = malloc(sizeof(No));
	
	if(novo)
	{
		novo->valor = num;
		novo->proximo = NULL;
		
		if(*fila == NULL) //Para quando a fila for inicializada
		{
			*fila = novo;
		}
		else //para os demais casos
		{
			placeholder = *fila; //placeholder recebe o conteúdo da fila
			while(placeholder->proximo) //enquanto o próximo nó não for NULL
			{
				placeholder = placeholder->proximo; //placeholder irá receber o conteúdo do próximo nó
			}
			placeholder->proximo = novo; //próximo nó recebe o novo nó
		}
	}
	else
	{
		printf("Erro ao alocar memoria");
	}
}

No* remover_da_fila(No **fila)
{
	No *remover = NULL;
	
	if(fila)
	{
		remover = *fila; // atribuimos o conteúdo de fila para o No remover
		*fila = remover->proximo; //fila recebe o próximo nó (ou próxima posição na fila)
	}
	else
	{
		printf("Fila vazia");
	}
	return remover;
}

void imprimir(No *fila)
{
	printf("------FILA------\n");
	while(fila)
	{
		printf("%d ", fila->valor);
		fila = fila->proximo;
	}
	printf("\n------FIM------\n");
}

int main(void)
{
	No *r, *fila = NULL;
	int opcao, valor;
	
	do
	{
		system("cls");
		printf("[0] - Sair\t[1] - Inserir\t[2] - Remover\n[3] - Imprimir\n");
		printf("\nDigite o valor desejado: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 0:
				return 0;
			break;
			
			case 1:
				printf("Digite um valor: ");
				scanf("%d", &valor);
				inserir_na_fila(&fila, valor);
			break;
			
			case 2:
				if(fila)
				{
					r = remover_da_fila(&fila);
					if(r)
					{
						printf("Removido: %d\n", r->valor);
						free(r);
					}
				}
				else
				{
					printf("Fila vazia, nao se pode tem o que se remover");
				}
				printf("\n\n");
				system("Pause");

			break;
			
			case 3:
				if(fila)
				{
					imprimir(fila);
				}
				else
				{
					printf("Fila vazia");
				}
				printf("\n\n\n");
				system("pause");
			break;
		}
	}
	while(opcao != 0);
}
