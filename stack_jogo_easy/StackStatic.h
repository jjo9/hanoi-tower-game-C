/*assinatura*/

#define MAXSTACK 50 /*tamanho da stack*/

#define VERDADEIRO -3
#define FALSO -2
#define NULO -1

typedef int componente;

typedef struct Stack{
	
	int topo;
	componente elementos[MAXSTACK];

}apStack;

int FS_new(apStack *apS);

int FS_empty(apStack *apS);

int FS_full(apStack *apS);

int FS_push(apStack *apS, componente x);

componente FS_pop(apStack *apS);

void FS_clear(apStack *apS);

int FS_size(apStack *apS);

componente FS_top(apStack *apS);

void FS_printStack(apStack *apS);

