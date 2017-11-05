#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "StackStatic.h"
#define FLUSHIN(u) while((u = getchar()) != EOF && u != '\n')

#define S1X 40
#define S1Y 25
#define S2X 70
#define S2Y 25
#define S3X 100
#define S3Y 25


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fint_test(){/*numero inteiro positivo*/
	int t;
	char c;
	while(scanf("%d",&t) != 1)
	{
		while(getchar() != '\n');
	}
	return t;
}

void irparaxy(int x,int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y}); // x=j (sao colunas) e y=i (sao as linhas)
}

void cursor(int x,int y){
	/*cursor placemente*/
	irparaxy(x,y);
}

void FS_printStacktable(apStack *apS1,apStack *apS2,apStack *apS3,componente holder,int moves){
	
	int i;
	printf("moves-> %d\n",moves);
	printf("\nstack 1: ");
	if(FS_empty(apS1)==FALSO)
	{
		for(i=0;i<=(*apS1).topo;i++)
		{
			printf("%d",(*apS1).elementos[i]);
		}
	}
	printf("\nstack 2: ");
	if(FS_empty(apS2)==FALSO)
	{
		for(i=0;i<=(*apS2).topo;i++)
		{
			printf("%d",(*apS2).elementos[i]);
		}
	}
	printf("\nstack 3: ");
	if(FS_empty(apS3)==FALSO)
	{
		for(i=0;i<=(*apS3).topo;i++)
		{
			printf("%d",(*apS3).elementos[i]);
		}
	}
	if(holder!=-1)
	{
		printf("\n\n	holder( %d ) ->",holder);
	}
	else
	{
		printf("\n\n	holder( ? ) <-",holder);
	}
	
	
}


int main(int argc, char *argv[]) {
	int i,num_to_print,level,num,moves;
	componente holder;
	holder=-1;// -1 não tem block (tem que fazer pop) // 1~8 tem que fazer push (pois tem o bloco com o numero correspondente)
	apStack s1,s2,s3;/*stacks*/
	char u;
	char string[30],c;
	FS_new(&s1);
	FS_new(&s2);
	FS_new(&s3);
	moves=0;
	printf("set console to full screen\n");
	system("pause");
	
	printf("escolha o nivel:\n 3~8\n");
	do
	{
		level=fint_test();
	}
	while(level>8 || level<3);
	system("cls");
	i=level;
	printf("level:%d\n",level);
	while(i!=0)
	{
		FS_push(&s1,i);
		i--;	
	}
	FS_printStacktable(&s1,&s2,&s3,holder,moves);
	
	
	
	do
	{
		do
		{
			c=getche();
			if(c=='1')
			{
				num=1;
			}
			else
			{
				if(c=='2')
				{
					num=2;
				}
				else
				{
					if(c=='3')
					{
						num=3;
					}
					else
					{
						num=0;
					}
				}
			}
		}
		while(num<1||num>3);
		
		switch(num)
		{
			case(1):
			{
				if(holder==-1)
				{
					if(FS_empty(&s1)==FALSO)
					{
						holder=FS_pop(&s1);
						moves++;
					}
				}
				else
				{
					if(FS_top(&s1)>holder||FS_empty(&s1)==VERDADEIRO)
					{
						FS_push(&s1,holder);
						holder=-1;
						moves++;
					}	
				}
				break;
			}
			case(2):
			{
				if(holder==-1)
				{
					if(FS_empty(&s2)==FALSO)
					{
						holder=FS_pop(&s2);
						moves++;
					}					
				}
				else
				{
					if(FS_top(&s2)>holder||FS_empty(&s2)==VERDADEIRO)
					{
						FS_push(&s2,holder);
						holder=-1;
						moves++;
					}
				}
				break;
			}
			case(3):
			{
				if(holder==-1)
				{
					if(FS_empty(&s3)==FALSO)
					{
						holder=FS_pop(&s3);
						moves++;
					}
				}
				else
				{
					if(FS_top(&s3)>holder||FS_empty(&s3)==VERDADEIRO)
					{
						FS_push(&s3,holder);
						holder=-1;
						moves++;
					}
				}
				break;
			}
		}
		
		system("cls");
		printf("level:%d\n",level);
		FS_printStacktable(&s1,&s2,&s3,holder,moves);
	}
	while(FS_size(&s3)!=level);
	system("cls");
	printf("you won the game");
	
	return 0;
}
