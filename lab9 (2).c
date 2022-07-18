#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void fifo(char[],char[],int,int);
void lru(char[],char[],int,int);
int main() {
	int f,l,choice,yn,i;
	char s[10],F[10];
	printf("Enter no of frames\n");
	scanf("%d",&f);
	printf("Enter length of string\n");
	scanf("%d",&l);
	printf("Enter the string\n");
	for( i=0;i<l;i++)
	scanf("%s",&s[i]);
	for( i=0;i<f;i++)
	F[i]=-1;
	do{
		
		printf("1.FIFO\n2.LRU\n3.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				for( i=0;i<f;i++)
	F[i]=-1;
				fifo(s,F,l,f);
				break;
			case 2:
				for( i=0;i<f;i++)
	F[i]=-1;
				lru(s,F,l,f);
				break;
			case 3:
				exit(0);
				
		}
		printf("Do you want to continue?\nTf yes press 1 or 0\n");
		scanf("%d",&yn);
		
	}while(yn==1);
	return 0;
}
void fifo(char s[],char F[],int l,int f)
{
	int flag=0,cnt=0,j=0,i,k;
	printf("Pages\t\tFrames\t\tAction\n");
	for( i=0;i<l;i++)
	{
		for( k=0;k<f;k++)
		{
			if(F[k]==s[i])
			flag=1;
		}
		if(flag==0)
		{
			printf("%c\t",s[i]);
			F[j]=s[i];
			j++;
			for( k=0;k<f;k++)
			{
				printf("%c\t",F[k]);
			}
			printf("Page Fault is %d\n",cnt);
			cnt++;
		}
		else
		{
			flag=0;
				printf("%c\t",s[i]);
		
			for(k=0;k<f;k++)
			{
				printf("%c\t",F[k]);
			}
			printf("No Page Fault\n ");
		
		}
		if(j==f)
		j=0;
	}
}
void lru(char s[],char F[],int l,int f)
{
	int j=0,top=0,flag=0,cnt=0,i,k,m;
		printf("Pages\t\tFrames\t\tAction\n");
		for( i=0;i<l;i++)
	{
		for( k=0;k<f;k++)
		{
			if(F[k]==s[i])
			{
			
			flag=1;
			break;
		}
		}
		printf("%c\t",s[i]);
		if(j!=f&&flag!=1)
		{
		
			F[top]=s[i];
			j++;
			if(j!=f)
			top++;
			
			
		
		}	
		else
		{
			if(flag==0)
			{
					
		
				for( k=0;k<top;k++)
				{
					F[k]=F[k+1];
				}
				F[top]=s[i];
			}
			if(flag==1)
			{
					printf("%c\t",s[i]);
		
				for( m=k;m<top;m++)
				{
					F[m]=F[m+1];
				}
				F[top]=s[i];
			}
			
		}
		
			for( k=0;k<f;k++)
			{
				printf("%c\t",F[k]);
			}
			if(flag==0)
			{
				printf("Page Fault is %d\n",cnt);
			cnt++;
			}
			else
			{
			
		
			printf("No Page Fault\n ");
			flag=0;
		}
		
		}
	}
