#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "listaEncadeada.h" 

struct node {
    int data;
    struct node *next;
}*p,*tmp,*tmp1;

void inserir_fim(int elemento) {
    tmp = p;
    tmp1 = (struct node*) malloc (sizeof(struct node));
    tmp1->data=elemento;
    tmp1->next=NULL;
    if (p == NULL) {
        p = tmp1;
    } else {
        while (tmp->next!=NULL) {
            tmp = tmp->next;
        }
        tmp->next = tmp1;
    }
 }

void inserir_inicio(int elemento) {
	 tmp = p;
	 tmp1 = (struct node*) malloc (sizeof(struct node));
	 tmp1->data=elemento;
	 tmp1->next = p;
	 p=tmp1;
}

// Função para inserir em uma determinada posição
void inserir_posicao(int elemento, int pos) {
    tmp = p;
    tmp1 = (struct node*) malloc (sizeof(struct node));
    tmp1->data=elemento;
    
    // Caso for inserir na primeira posição
    if (pos == 1){
        tmp1->next = p;
        p = tmp1;
        return;
    }
    
    for (int i = 1; i < pos - 1 && tmp != NULL; i++){
        tmp = tmp->next;
    }
    // Caso não tiver uma posição, liberar a memória
    if (tmp == NULL){
        printf("\nErro: posicao invalida!");
        free(tmp1);
        return;
    }
    // Inserir na lista encadeada
    tmp1->next = tmp->next;
    tmp->next = tmp1;
}

void apagar(int ele) {
    tmp = p;
	struct node *pre=tmp;
	while (tmp != NULL) {
		if (tmp->data==ele) {
            if (tmp == p) {
                p = tmp->next;
			    free(tmp);
			    return;
			} else {
                pre->next=tmp->next;
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
 
void apagar_inicio() {	
	tmp = p;
	if (p == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else {
		printf("\nElemento deletado - %d", p->data);
		p = p->next;
	}
 }
 
void apagar_fim() {	
	tmp=p;
	struct node* pre;
	if(p == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else if (p->next == NULL) {
		printf("\nElemento deletado - %d", p->data);
		p = NULL;
	} else {
		while (tmp->next != NULL) {
			pre=tmp;
			tmp=tmp->next;
		}
		pre->next=NULL;
		printf("\nElemento deletado - %d", tmp->data);
	}
}

// Função para apagar em uma determinada posição
void apagar_posicao(int pos) {
	tmp = p;
	int i;

	// Remover na primeira posição 
	if (pos == 1){
		if (p == NULL) {
			printf("\nErro: lista vazia!");
			return;
		}
		p = tmp->next;
		free(tmp);
		return;
	}

	for (i = 1; i < pos - 1 && tmp != NULL; i++){
		tmp = tmp->next;
	}
	// Se tmp for NULL ou tmp->next for NULL, posição é inválida
	if (tmp == NULL || tmp->next == NULL){
		printf("\nErro: nao possui no nesta posicao!");
		return;
	}
	tmp1 = tmp->next;
	tmp->next = tmp1->next;
	free(tmp1);
}	


bool ehVazia() {
    if (p == NULL) {
        return (1);
    } else {
        return (0);
    }
}

void imprimir() {
	tmp = p;
 	while (tmp != NULL) {
        printf("\n %d",tmp->data);
	 	tmp = tmp->next;
	}
}

int obter_primeiro(void) {
    tmp = p;
	if (p == NULL) {
		printf("\n Nenhum elemento encontrado ");
    } else {
		return (p->data);
	}
}

int obter_ultimo(void) {
    tmp = p;
	struct node* pre;
	if (p == NULL) {
		printf("\n Nenhum elemento encontrado ");
        return (0);
    } else if (p->next==NULL) {
		return(p->data);
	} else {
		while (tmp->next!=NULL) {
			pre=tmp;
			tmp=tmp->next;
		}
		pre->next=NULL;
		return(tmp->data);
	}
}

int obter_posicao () {
	if (p == NULL){
		return 0;
	}
}

void main() { 
  int pos, val, n;
  p = NULL;
  do {
    printf("\n\n************************* MENU ************************");
	printf("\n1.Inserir no fim");
	printf("\n2.Inserir no inicio");
    printf("\n3.Inserir no em determinada posicao");
	printf("\n4.Apagar um elemento em particular");
	printf("\n5.Apagar do inicio");
	printf("\n6.Apagar do fim");
	printf("\n7.Imprimir lista");
	printf("\n8.E vazia?");
    printf("\n9.Obter primeiro");
    printf("\n10.Obter ultimo");
	printf("\n11.Apagar no em uma determinada posicao");
    printf("\n12.Obter o valor em uma posicao");
    printf("\n0.Sair");
	printf("\nEntre sua opcao : ");
	scanf("%d",&n);
	switch(n) {
        case 1: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_fim(val);
			    break;
		case 2: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_inicio(val);
			    break;
        case 3:
                printf("\nDigite a posicao ");
                scanf("%d", &pos);
                printf("\nDigite o valor ");
			    scanf("%d",&val);
                inserir_posicao(val, pos);
                break;
		case 4: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    apagar(val);
			    break;
		case 5: 
			    apagar_inicio();
			    break;
		case 6: 
			    apagar_fim();
			    break;
		case 7: imprimir();
		 	    break;
		case 8: if (ehVazia() == 1) {
                    printf("\nLista vazia");
                } else {
                    printf("\nLista não vazia");
                }
                break;
        case 9: val = obter_primeiro();
                if (val != 0) {
                    printf("%d", val);
                }
		 	    break;
        case 10: val = obter_ultimo();
                if (val != 0) {
                    printf("%d", val);
                }
		 	    break;
		case 11:
				printf("\nDigite a posicao que deseja remover ");
                scanf("%d", &pos);
				apagar_posicao(pos);
				break;
		case 12:
				printf("\nDigite a posicao que deseja obter");
				scanf("%d", &pos);
        case 0: exit(0);
		 	    break;
		default: printf("\n Opção errada!");
		 	    break;
		}
	} while(1);

}