#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define Matriz 3

void MostraValores(char v[Matriz][Matriz])
{
	printf("   1  2  3\n");
	for (int i = 0; i < Matriz; i++)
	{
		int aux = i + 1;
		printf("%d ", aux);
		
		for (int j = 0; j < Matriz; j++)
		{		
			printf(" %c ",v[i][j]);
		}		
		putchar('\n');
	}
}

void DefineValores(char v[][Matriz])
{
	for(int i = 0; i < Matriz; i++)
	{
		for(int j = 0; j < Matriz; j++)
		{
			v[i][j]= '#' ;
		}
	}
	MostraValores(v);
}

void MudaValor(char v[Matriz][Matriz], int escolhaL, int escolhaC, char jogador)
{
	for(int i = 0; i < Matriz; i++)
	{
		for(int j = 0; j < Matriz; j++)
		{
			if (escolhaL == i && escolhaC == j)
			{	
				if (jogador == 'X')
				{
					v[i][j] = 'X'; 	
				}		
				else {
					if (jogador == 'O')
					{
						v[i][j] = 'O'; 
					}
				}		
			}
		}
	}
	MostraValores(v);
}

int VColuna(char v[Matriz][Matriz], char c)
{
	for (int i = 0; i < Matriz; i++)
	{
		if (v[0][i] == v[1][i] && v[0][i] == v[2][i])
		{
			if (v[0][i] == c)
			{
				return 1;
			}
		}
	}
}

int VLinha(char v[Matriz][Matriz], char c)
{
	for (int i = 0; i < Matriz; i++)
	{
		if (v[i][0] == v[i][1] && v[i][0] == v[i][2])
		{
			if (v[i][0] == c)
			{
				return 1;
			}
		}
	}
}

int VDiagonal(char v[Matriz][Matriz], char c)
{
	if (v[0][0] == v[1][1] && v[0][0] == v[2][2])
	{
		if (v[0][0] == c)
		{
			return 1;
		}
	}
	
	if (v[2][0] == v[1][1] && v[2][0] == v[0][2])
	{
		if (v[2][0] == c)
		{
			return 1;
		}
	}
} 

int Ganhou(char v[Matriz][Matriz], char c)
{
	if (VColuna(v,c) == 1)
	{
		return 1;
	}
	
	if (VLinha(v,c) == 1)
	{
		return 1;
	}
	
	if (VDiagonal(v,c) == 1)
	{
		return 1;
	}

	return 0;
}

int Empate(int rodada)
{
	if (rodada == Matriz*Matriz)
	{
		return 1;
	}
	
	return 0;
}

main()
{
	setlocale(LC_ALL,"");
	
	char tabuleiro[Matriz][Matriz];
	int escolhaL, escolhaC;
	char vitoria = 0;
	char jogador = ' '; 
	char empate = 0;
	int rodada;
	
	putchar('\n');
	DefineValores(tabuleiro);
	
	do 
	{
		printf("\nLINHA: ");		
		scanf("%d", &escolhaL);
		
		printf("COLUNA: ");
		scanf("%d", &escolhaC);

		system("cls");	
		
		if (escolhaL > Matriz || escolhaC > Matriz)
		{
			escolhaL = Matriz;
			escolhaC = Matriz;
		}
		
		if (escolhaL < 0 || escolhaC < 0)
		{
			escolhaL = 0;
			escolhaC = 0;
		}

		escolhaL--;
		escolhaC--;
	
		putchar('\n');
		
		if (jogador == 'X')
		{
			jogador = 'O';
		}
		else
		{
			jogador = 'X';
		}
		
		if (tabuleiro[escolhaL][escolhaC] == '#')
		{
			MudaValor(tabuleiro, escolhaL, escolhaC, jogador);	
		}
		else
		{
			MostraValores(tabuleiro);
			printf("\nPosição Invalida\n");
			
			if (jogador == 'O')
			{
				jogador = 'X';
			}
			else
			{
				jogador = 'O';
			}
			
			rodada--;
		}
		
		if (Empate(rodada) == 1)
		{
			empate = 1;
		}
		rodada++;

		if (Ganhou(tabuleiro, jogador) == 1)
		{
			vitoria = 1;
		}
		
	} while (vitoria == 0 && empate == 0);
	
		system("cls");
		if (vitoria == 1)
		{
			printf("\n\n\tVITORIA\n\n");
			printf("   Parabéns Jogador %c", jogador);
		}	
		if (empate == 1)
		{
			printf("\n\n\tEMPATE\n\n");
		}	
}
