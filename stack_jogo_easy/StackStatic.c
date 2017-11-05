#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackStatic.h"
/*codigo*/

int FS_new(apStack *apS){
	
	(*apS).topo=-1;
	return VERDADEIRO;
}

int FS_empty(apStack *apS){
	
	if((*apS).topo==-1)
	{
		return VERDADEIRO;
	}
	else
	{
		return FALSO;
	}
}

int FS_full(apStack (*apS)){
	
	if((*apS).topo==MAXSTACK-1)
	{
		return VERDADEIRO;
	}
	else
	{
		return FALSO;
	}
}

int FS_push(apStack *apS, componente x){
	
	if((*apS).topo==MAXSTACK-1)
	{
		return FALSO;
	}
	else
	{
		
		(*apS).topo++;
		(*apS).elementos[(*apS).topo]=x;
		return VERDADEIRO;
	}
}

componente FS_pop(apStack *apS){
	
	if((*apS).topo==-1)
	{
		return NULO;
	}
	else
	{
		(*apS).topo--;
		return (*apS).elementos[(*apS).topo+1];
	}
}

void FS_clear(apStack *apS){
	
	(*apS).topo=-1;
}

int FS_size(apStack *apS){
	
	return (*apS).topo+1;
}

componente FS_top(apStack *apS){
	
	if(FS_empty(apS)==FALSO)
	{
		return (*apS).elementos[(*apS).topo];
	}
	else
	{
		return NULO;
	}
}

void FS_printStack(apStack *apS){
	
	int i;
	
	if(FS_empty(apS)==FALSO)
	{
		for(i=0;i<=(*apS).topo;i++)
		{
			printf("%d",(*apS).elementos[i]);
		}
	}
	else
	{
		printf("esta vazio\n");
	}
}

