#include<stdio.h>
#include<windows.h>
int cstar=0;
int makepos(int,int,int);
int harekat(int,int,char[100][100],int);
int check(char[100][100],int,int,int,int);
int main()
{
	printf("adress ra vared kon please\n");
	char fs[100]={'\0'};
	scanf("%s", fs);
	FILE*ptf;
	char A[100][100]={'\0'}, tmp[100]={'\0'};
	int blank=0, m=0, n=0, pacman, count=0, so;
	ptf=fopen(fs,"r");

	while(feof(ptf)==0)
	{
		blank=0;
		fgets(tmp,100,ptf);
		count=0;
		m=0;
		for(int i=0; tmp[i]!='\n'&&tmp[i]!='\0';i++)
		{
			if(tmp[i]=='0'||tmp[i]=='#'||tmp[i]=='*'||tmp[i]=='1')
			{
				count++;
			}
		}
		
		for(int i=0; tmp[i]!='\n'&&tmp[i]!='\0';i++)
		{
			if(tmp[i]=='0'||tmp[i]=='#'||tmp[i]=='*'||tmp[i]=='1')
			{
				blank++;
				A[n][m]=tmp[i];
				m++;	
				
				if(tmp[i]=='0')
				{
					pacman=makepos(n,m,count);
				
				}	
				if(tmp[i]=='*')
				{
					cstar++;
				}
			}
		}
		
		if(blank>0)
		{
			n++;	
		}
		
	}
	fclose(ptf);
	while(1)
	{
		//printf("%d\n", pacman);
		for(int i=0 ; i<n ; i++)
		{
			printf("%s\n", A[i]);
		}
		printf("number of stars are %d\n", cstar);
		so=getch();
		if (so==0xE0)
		{ 
     		so = getch();
     		if(check(A,count,so,pacman,n)==1)
     		{
     			pacman=harekat(pacman,so,A,count);
			 }
			if(cstar==0)
			{
				system("cls");
				for(int i=0 ; i<n ; i++)
				{
					printf("%s\n", A[i]);
				}
				printf("number of stars are %d\n", cstar);	
				return 0;
			}
		}
		else if(so-'0'==0)
		{
			return 0;
		}
	
		system("cls");
		
	}
	
	
}
	int makepos(int i,int j,int x)
{
	
	return (i*x)+(j);
}

int harekat(int pacman,int so,char G[100][100], int y)
{
	int i=0, j=0;
	if(pacman%y==0)
	{
		i=(pacman/y)-1;
		j=y-1;
	}
	else
	{
		i=pacman/y;
		j=(pacman%y)-1;
	}
	
	if(so==72)
	{
		if(G[i-1][j]=='*')
		{
			cstar--;
		}
		G[i][j]='1';
		G[i-1][j]='0';
		pacman=makepos(i-1,j+1,y);
	}
	if(so==80)
	{
			if(G[i+1][j]=='*')
		{
			cstar--;
		}
		G[i][j]='1';
		G[i+1][j]='0';
		pacman=makepos(i+1,j+1,y);
	}if(so==75)
	{
		if(G[i][j-1]=='*')
		{
			cstar--;
		}
		G[i][j]='1';
		G[i][j-1]='0';
		pacman=makepos(i,j,y);
	}if(so==77)
	{
		if(G[i][j+1]=='*')
		{
			cstar--;
		}
		G[i][j]='1';
		G[i][j+1]='0';
		pacman=makepos(i,j+2,y);
	}
	
	return pacman;
		
}
int check(char S[100][100],int y, int so, int pacman, int n)
{
	int i=0, j=0;
	if(pacman%y==0)
	{
		i=(pacman/y)-1;
		j=y-1;
	}
	else
	{
		i=pacman/y;
		j=(pacman%y)-1;
	}
	if((so==72&&i==0)||(so==72&&S[i-1][j]=='#'))
	{
		return 0;
	}
	if((so==80&&i==n-1)||(so==80&&S[i+1][j]=='#'))
	{
		return 0;
	}if((so==75&&j==0)||(so==75&&S[i][j-1]=='#'))
	{
		return 0;
	}if((so==77&&j==y-1)||(so==77&&S[i][j+1]=='#'))
	{
		return 0;
	}
	
	return 1;
	
}

