// Turma: 33C
// Nome: Gabriel Robert Wischer Guedes
// Matricula: 2211784

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define ALPHA 26
#define TRUE 1
#define FALSE 0

struct contato
{
	char nome[81];
	char telefone[21];
	struct contato* next;
};

struct agenda
{
	struct contato* letra[ALPHA];
};
typedef struct agenda Agenda;

Agenda* criaAgenda(void)
{
	Agenda* novo = (Agenda*)malloc(sizeof(Agenda));
	if (novo == NULL)
		return FALSE;
	for (int i = 0; i < ALPHA; i++)
		novo->letra[i] = NULL;
	return novo;
}

Agenda* insereOrd(struct contato Contato, Agenda* agenda)
{
	int i = Contato.nome[0] - 'A';
	struct contato* aux = (struct contato*)malloc(sizeof(struct contato));
	if (aux == NULL)
		return FALSE;
	
	strcpy(aux->nome, Contato.nome);
	strcpy(aux->telefone, Contato.telefone);
	aux->next = NULL;
	
	struct contato* p = agenda->letra[i];
	struct contato* ant = NULL;

	if (p == NULL)
		agenda->letra[i] = aux;
	else
	{
		while (p != NULL && strcmp(p->nome, Contato.nome) < 0)
		{
			ant = p;
			p = p->next;
		}
		if (ant == NULL)
		{
			aux->next = agenda->letra[i];
			agenda->letra[i] = aux;
		}
		else
		{
			aux->next = ant->next;
			ant->next = aux;
		}
	}
	return agenda;
}

void listaLetra(Agenda* agenda, char letra)
{
	int i =  letra - 'A';
	struct contato* aux = agenda->letra[i];
	printf("\nLetra %c\n", letra);
	while (aux != NULL)
	{
		printf("%s: %s\n", aux->nome, aux->telefone);
		aux = aux->next;
	}
	return;
}

Agenda* retiraAgenda(Agenda* agenda, char* nome)
{
	int i = nome[0] - 'A';
	
	struct contato* p = agenda->letra[i];
	struct contato* ant = NULL;

	
	while (p != NULL && strcmp(p->nome, nome) != 0)
	{
		ant = p;
		p = p->next;
	}
	if (p == NULL)
		return FALSE;
	else if (ant == NULL)
	{
		agenda->letra[i] = p->next;
		free(p);
	}
	else
	{
		ant->next = p->next;
		free(p);
	}
	return agenda;
}

void liberaCadastro(Agenda* agenda)
{
	for (int i = 0; i < ALPHA; i++)
	{
		struct contato* p = agenda->letra[i];
		struct contato* aux = NULL;
		while (p != NULL)
		{
			p = p->next;
			free(aux);
			aux = p;
		}
	}
	free(agenda);
	printf("\nAgenda liberada\n");
}

int main(void)
{
	Agenda* agenda = criaAgenda();
	if (agenda == FALSE)
	{
		printf("Erro ao alocar memoria da Agenda\n");
		exit(1);
	}

	struct contato contato1;
	strcpy(contato1.nome, "Gabriel");
	strcpy(contato1.telefone, "(21) 90000-0000");
	agenda = insereOrd(contato1, agenda);

	struct contato contato2;
	strcpy(contato2.nome, "Guilherme");
	strcpy(contato2.telefone, "(21) 91111-1111");
	agenda = insereOrd(contato2, agenda);

	struct contato contato3;
	strcpy(contato3.nome, "Ana");
	strcpy(contato3.telefone, "(21) 92222-2222");
	agenda = insereOrd(contato3, agenda);

	struct contato contato4;
	strcpy(contato4.nome, "Abraao");
	strcpy(contato4.telefone, "(21) 93333-3333");
	agenda = insereOrd(contato4, agenda);

	struct contato contato5;
	strcpy(contato5.nome, "Julio");
	strcpy(contato5.telefone, "(21) 94444-4444");
	agenda = insereOrd(contato5, agenda);

	struct contato contato6;
	strcpy(contato6.nome, "Joao");
	strcpy(contato6.telefone, "(21) 95555-5555");
	agenda = insereOrd(contato6, agenda);

	struct contato contato7;
	strcpy(contato7.nome, "Luis");
	strcpy(contato7.telefone, "(21) 99999-6666");
	agenda = insereOrd(contato7, agenda);

	struct contato contato8;
	strcpy(contato8.nome, "Marco");
	strcpy(contato8.telefone, "(21) 96666-9999");
	agenda = insereOrd(contato8, agenda);

	struct contato contato9;
	strcpy(contato9.nome, "Marcelo");
	strcpy(contato9.telefone, "(21) 97777-7777");
	agenda = insereOrd(contato9, agenda);

	struct contato contato10;
	strcpy(contato10.nome, "Muniz");
	strcpy(contato10.telefone, "(21) 98888-8888");
	agenda = insereOrd(contato10, agenda);

	struct contato contato11;
	strcpy(contato11.nome, "Zilberman");
	strcpy(contato11.telefone, "(21) 99999-9999");
	agenda = insereOrd(contato11, agenda);

	struct contato contato12;
	strcpy(contato12.nome, "Nando");
	strcpy(contato12.telefone, "(21) 90111-0111");
	agenda = insereOrd(contato12, agenda);

	if (agenda == FALSE)
	{
		printf("Erro ao alocar memoria da Agenda\n");
		exit(1);
	}

	listaLetra(agenda, 'A');
	listaLetra(agenda, 'B');
	listaLetra(agenda, 'G');
	listaLetra(agenda, 'J');
	listaLetra(agenda, 'L');
	listaLetra(agenda, 'M');
	listaLetra(agenda, 'N');
	listaLetra(agenda, 'Z');

	if (retiraAgenda(agenda, "Marcelo") == FALSE)
		printf("\nContato nao encontrado\n");
	else
		printf("\nContato %s removido\n", "Marcelo");
	if (retiraAgenda(agenda, "Lucio") == FALSE)
		printf("\nContato %s nao encontrado\n", "Lucio");
	else
		printf("\nContato %s removido\n", "Lucio");
	listaLetra(agenda, 'M');

	liberaCadastro(agenda);
	
	return 0;
}