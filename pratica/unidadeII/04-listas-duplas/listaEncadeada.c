#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
//#include "listaEncadeada.h" 

struct node {
    int data;
    struct node *next, *prev;
}*tmp, *tmp1;

struct listaDupla {
	struct node *inicio, *fim;
};

bool ehVazia(struct listaDupla *lista) {
    if (lista->inicio == NULL) {
        return (1);
    } else {
        return (0);
    }
}

void inserir_inicio(struct listaDupla *lista, int elemento) {
	tmp = (struct node*) malloc (sizeof(struct node));
	tmp->data=elemento;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (ehVazia(lista)){
		lista->inicio = tmp;
		lista->fim = tmp;
	} else {
		tmp->next = lista->inicio;
		lista->inicio->prev = tmp;
		lista->inicio = tmp;
	}
}

void inserir_fim(struct listaDupla *lista, int elemento) {
    tmp = (struct node*) malloc (sizeof(struct node));
    tmp->data=elemento;
    tmp->next=NULL;
	tmp->prev = NULL;
    if (ehVazia(lista)) {
        inserir_inicio(lista, elemento);
    } else {
        lista->fim->next = tmp;
		tmp->prev = lista->fim;
		lista->fim = tmp;
    }
}

// Função para inserir em uma determinada posição
void inserir_posicao(struct listaDupla *lista, int elemento, int pos) {
    // Caso for inserir na primeira posição
    if (pos == 1){
        inserir_inicio(lista, elemento);
		return;
    }

    tmp = (struct node*) malloc (sizeof(struct node));
    tmp->data=elemento;
	tmp->next=NULL;
	tmp->prev = NULL;

	tmp1 = lista->inicio;
    
    for (int i = 1; i < pos && tmp1 != NULL; i++){
        tmp1 = tmp1->next;
    }
    // Caso não tiver uma posição, liberar a memória
    if (tmp1 == NULL){
        printf("\nErro: posicao inexistente, no inserido no final da lista!");
        inserir_fim(lista, elemento);
		return;
    }
    // Inserir na lista duplamente encadeada
	tmp->next = tmp1;
	tmp->prev = tmp1->prev;
	tmp1->prev->next = tmp;
	tmp1->prev = tmp;
}

void apagar(struct listaDupla *lista, int ele) {
	tmp = lista->inicio;
	struct node *pre = tmp;
	while (tmp != NULL) {
		if (tmp->data==ele) {
            if (tmp == lista->inicio) {
                lista->inicio = tmp->next;
			    free(tmp);
			    return;
			} else {
                pre->next=tmp->next;
				if (tmp->next != NULL){
					tmp->next->prev = pre;
				}
			    free(tmp);
			    return;
			}
		} else {
            pre = tmp;
		    tmp = tmp->next;
		}
	}
	printf("\n Valor não encontrado! ");
 }
 
void apagar_inicio(struct listaDupla *lista) {	
	tmp = lista->inicio;
	if (tmp == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else {
		printf("\nElemento deletado - %d", lista->inicio->data);
		lista->inicio = lista->inicio->next;
		if (lista->inicio != NULL){
			lista->inicio->prev = NULL;
		}
		free(tmp);
	}
 }
 
void apagar_fim(struct listaDupla *lista) {	
	tmp= lista->fim;
	struct node* pre;
	if(lista->inicio == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else {
		if (lista->inicio->next == NULL){
			lista->inicio = NULL;
			lista->fim = NULL;
			printf("\nElemento deletado - %d", tmp->data);
			free(tmp);
			return;
		}
		pre = lista->fim->prev;
		pre->next= NULL;
		lista->fim = pre;
		
		printf("\nElemento deletado - %d", tmp->data);
		free(tmp);
	}
}

// Função para apagar em uma determinada posição
void apagar_posicao(struct listaDupla *lista,int pos) {
	tmp = lista->inicio;
	int i;

	// Remover na primeira posição 
	if (pos == 1){
		if (lista->inicio == NULL) {
			printf("\nErro: lista vazia!");
			return;
		}
		apagar_inicio(lista);
		return;
	}

	for (i = 1; i < pos && tmp != NULL; i++){
		tmp = tmp->next;
	}
	// Se tmp for NULL ou tmp->next for NULL, posição é inválida
	if (tmp == NULL || tmp->next == NULL){
		printf("\nErro: nao possui no nesta posicao!");
		return;
	}
	tmp1 = tmp->next;
	tmp->next = tmp1->next;
	tmp1->next->prev = tmp;
	free(tmp1);
}	

void imprimir(struct listaDupla *lista) {
	tmp = lista->inicio;
 	while (tmp != NULL) {
        printf("\n %d",tmp->data);
	 	tmp = tmp->next;
	}
}

int obter_primeiro(struct listaDupla *lista) {
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento encontrado ");
    } else {
		return (lista->inicio->data);
	}
}

int obter_ultimo(struct listaDupla *lista) {
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento encontrado ");
        return (0);
    } else {
		return(lista->fim->data);
	}
}

// Função para obter o valor em uma determinada posição
int obter_posicao (struct listaDupla *lista, int pos) {
	tmp = lista->inicio;

	if (lista->inicio == NULL){
		// Retornar 0 caso de lista vazia
		return 0;
	}

	for (int i = 1; i < pos; i++){
		tmp = tmp->next;
	}
	if (tmp == NULL || pos <= 0){
		// Posição é inválida
		return -1;
	}
	return tmp->data;
}

void main() { 
  int pos, val, n;

  struct listaDupla *lista = malloc(sizeof(struct listaDupla));
  lista->inicio = NULL;
  lista->fim = NULL;


  do {
    printf("\n\n************************* MENU ************************");
	printf("\n1.Inserir no inicio");
	printf("\n2.Inserir no fim");
    printf("\n3.Inserir no em determinada posicao");
	printf("\n4.Apagar um elemento em particular");
	printf("\n5.Apagar do inicio");
	printf("\n6.Apagar do fim");
	printf("\n7.Apagar no em uma determinada posicao");
	printf("\n8.Imprimir lista");
	printf("\n9.E vazia?");
    printf("\n10.Obter primeiro");
    printf("\n11.Obter ultimo");
    printf("\n12.Obter o valor em uma posicao");
    printf("\n0.Sair");
	printf("\nEntre sua opcao : ");
	scanf("%d",&n);
	switch(n) {
		case 1: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_inicio(lista, val);
			    break;		
        case 2: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_fim(lista, val);
			    break;
        case 3:
                printf("\nDigite a posicao ");
                scanf("%d", &pos);
                printf("\nDigite o valor ");
			    scanf("%d",&val);
                inserir_posicao(lista, val, pos);
                break;
		case 4: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    apagar(lista, val);
			    break;
		case 5: 
			    apagar_inicio(lista);
			    break;
		case 6: 
			    apagar_fim(lista);
			    break;
		case 7:
				printf("\nDigite a posicao que deseja remover ");
                scanf("%d", &pos);
				apagar_posicao(lista, pos);
				break;
		case 8: imprimir(lista);
		 	    break;
		case 9: if (ehVazia(lista) == 1) {
                    printf("\nLista vazia");
                } else {
                    printf("\nLista não vazia");
                }
                break;
        case 10: val = obter_primeiro(lista);
                if (val != 0) {
                    printf("%d", val);
                }
		 	    break;
        case 11: val = obter_ultimo(lista);
                if (val != 0) {
                    printf("%d", val);
                }
		 	    break;
		case 12:
				printf("\nDigite a posicao que deseja obter ");
				scanf("%d", &pos);
				int posicao = obter_posicao(lista, pos);
				if (posicao == 0){
					printf("\nErro: lista vazia");
				} else if (posicao == -1){
					printf("\nErro: posicao invalida");
				} else {
					printf("\n%d", posicao);
				}
				break;
        case 0: exit(0);
		 	    break;
		default: printf("\n Opção errada!");
		 	    break;
		}
	} while(1);

}