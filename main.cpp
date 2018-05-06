#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <cctype>
#include <windows.h>

static char vet[19][8] = {"JESUS", "PROGRAM", "ORANGE", "SERVICE", "BIKE", "HEALTH", "NOISE", "TABLE", "CHAIR", "ZEBRA", "ONION", "WATER", "HEART", "BOOK", "SCHOOL", "WALLET", "WORLD", "MOON", "BANANA"};
static const char teste[5] = "EXIT";
char escolhido[10][7];
char tabela [10][15];
char teste2[10][7];
char buscatabela[7];

bool VerifyConcatWords()
{
	for(int x = 0; x < 10; x++)
	{
		if(strlen(escolhido[x]) > 7)
		{
			return true;
		}
	}
	return false;
}

void ClearVariables()
{
	for(int x = 0; x < 10; x++)
	{	
		strcpy(teste2[x]," ");
		strcpy(escolhido[x], " ");	
		for(int y=0; y<15; y++)
		{
			tabela[x][y]=' ';
		}
	}
}

void ChooseRandomWords()
{
	int i,existe = 0;
	srand (time(NULL));
	for(int x=0; x<10; x++)
	{
		do
		{
			existe = 0;
			i = rand() % 19;
			for(int y = 0; y < 10; y++)
			{
				if(strcmp(escolhido[y], vet[i]) == 0)
				{
					existe = 1;
					break;
				}
			}
			
			if(existe == 0)
			{
				strcpy(escolhido[x], vet[i]);
			}	
											
		}while(existe == 1);				
	}
	
	if(VerifyConcatWords())
	{
		system("cls");
		printf("\n 			Generating table...");
		ChooseRandomWords();
	}			
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int menu=0,v;		
	do
	{
		system("cls");
		printf("		Word Game - Seek And Destroy 9000 Double Dissipator - \"The Lamentation\" Version 3.0");
		printf("\n");
		printf("\n");		
		printf("				 _______  _______  _                	\n");
		printf("				(       )(  ____ \\( (    /||\\     /|	\n");
		printf("				| () () || (    \\/|  \\  ( || )   ( |	\n");
		printf("				| || || || (__    |   \\ | || |   | |	\n");
		printf("				| |(_)| ||  __)   | (\\ \\) || |   | |	\n");
		printf("				| |   | || (      | | \\   || |   | |	\n");
		printf("				| )   ( || (____/\\| )  \\  || (___) |	\n");
		printf("				|/     \\|(_______/|/    )_)(_______)	\n");	
		printf("\n");
		printf("\n");
		printf("						1 - Play\n");
		printf("						2 - Credits\n");
		printf("						3 - Words\n");
		printf("						4 - Exit\n");
	do
	{
		fflush(stdin);
		scanf("%d",&menu);
		if(menu < 1 || menu > 4)
		{
			printf("Invalid option!\n");
		}
	}while(menu < 1 || menu > 4);
	
		system("cls");
		switch(menu)
		{
			case 1:
				
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1 );
				printf("1   Dark blue\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2 );
				printf("2   Dark green\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3 );
				printf("3   Dark Cyan\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4 );
				printf("4   Dark red\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5 );
				printf("5   Dark pink\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6 );
				printf("6   Dark yellow\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8 );
				printf("8   Dark grey\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 9 );
				printf("9   Light blue\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10 );
				printf("10  Light green\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11 );
				printf("11  Light Cyan\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12 );
				printf("12  Light red\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13 );
				printf("13  Light pink\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14 );
				printf("14  Light yellow\n");			
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );
				
				do
				{
					printf("Enter the color you want to mark the words in the table: ");
					fflush(stdin);
					scanf("%d",&v);
					if(v!=1 && v!=2 && v!=3 && v!=4 && v!=5 && v!=6 && v!=8 && v!=9 && v!=10 && v!=11 && v!=12 && v!=13 && v!=14)
					{
						printf("Invalid color!.\n");
					}
				}while(v!=1 && v!=2 && v!=3 && v!=4 && v!=5 && v!=6 && v!=8 && v!=9 && v!=10 && v!=11 && v!=12 && v!=13 && v!=14);
								
				{
				
				ClearVariables();
				ChooseRandomWords();							
				
				int i,j,existe,maisum=0;
				int z,falha;
				int colocado;
		
				for(int x=0; x<7; x++)
				{			
					do{
						existe=0;
						i=rand()%10;
						j=rand()%15;
						z=strlen(escolhido[x])-1;			
						for (int p=0; p<=z; p++)
						{
							if(tabela[i][j+p] !=' ' || j+p>14)
							{
								existe=1;
							}
						}
					}while(existe==1);
			
					for(int y=0; y<=z; y++)
					{				
						tabela[i][j+y]=escolhido[x][0+y];				
					}			
				}
				
		
				
				for(int x=7; x<10; x++)
				{
					
					colocado=0;		
					z=strlen(escolhido[x])-1;
					for(int t=0; t<=z; t++)
					{					
						for(int l=0; l<10; l++)
						{	
							for(int c=0; c<15; c++)
							{
								if(tabela[l][c]==escolhido[x][t])
								{
									falha=0;
															
									int z1=z-t;
									int z2=z-z+t;
									
									if(z1 != 0 && l+z1<=9)
									{							
										for(int p=1; p<=z1; p++)
										{							
											if(tabela[l+p][c] !=' ')
											{
												
												falha=1;
											}
										}
									}
									if(z2 != 0 && l-z2>=0)
									{							
										for(int p=1; p<=z2; p++)
										{
											if(tabela[l-p][c] !=' ')
											{
													
												falha=1;
											}
										}
									}
									if(falha==0)
									{
																		
										if(z1 != 0 && l+z1<=9 && l-z2>=0)
										{										
											for(int p=1; p<=z1; p++)
											{
												
												tabela[l+p][c]=escolhido[x][t+p];
											}
											colocado=1;
										}
										
										if(z2 != 0 && l+z1<=9 && l-z2>=0)
										{										
											for(int p=1; p<=z2; p++)
											{
												
												tabela[l-p][c]=escolhido[x][t-p];
											}
											colocado=1;
										}						
									}			
								}if(colocado ==1){
											break;
											}   
							}if(colocado ==1){
											break;
											} 
						}if(colocado ==1){
											break;
											} 						
					}
			
			
				}	
				
				
				srand (time(NULL));
				for(int x=0; x<10; x++)
				{
					for(int y=0; y<15; y++)
					{			
						do
						{
							i=rand() % 91;
						}while(i<65);
						if(tabela[x][y]==' ')
						{
							tabela[x][y]=i;
						}
					
					
					}		
					
				}
				
				int zerado=0,achou=0,jatem=0;
				
				do
				{
					system("cls");
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					printf("\n");
					for(int x=0; x<10; x++)
					{
						for(int y=0; y<15; y++)
						{			
							if(islower(tabela[x][y]))
							{
								SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), v );
	    						printf(" %c",toupper(tabela[x][y]));
							}else{
								SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );
								printf(" %c",tabela[x][y]);
							}
							
				
						}		
						printf("\n");
					}
					printf("\n");
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					printf("Words found: %d.\n",zerado);
					printf("Remaining words: %d.\n",10-zerado);
					printf("\n");
					printf("*The words found will be marked in the table according to the chosen color\n ");
					printf(" *Type \"HELP\" to see the words in the table\n ");
					printf("  *To return to the menu type \"EXIT\"\n ");
					
					printf("\n");
					do
					{	
						do{
					
						jatem=0;	
						printf("Enter the word found: ");
						fflush(stdin);
						gets(buscatabela);
						int z3=strlen(buscatabela);
						for(int d=0; d<=z3; d++)
						{
							buscatabela[d] = toupper(buscatabela[d]);
						}
						if((strcmp(buscatabela, teste)!=0) && (strcmp(buscatabela,"HELP")!=0) && (strcmp(buscatabela, escolhido[0])!=0 && strcmp(buscatabela, escolhido[1])!=0 && strcmp(buscatabela, escolhido[2])!=0 && strcmp(buscatabela, escolhido[3])!=0 && strcmp(buscatabela, escolhido[4])!=0 &&
						 strcmp(buscatabela, escolhido[5])!=0 && strcmp(buscatabela, escolhido[6])!=0 && strcmp(buscatabela, escolhido[7])!=0 && strcmp(buscatabela, escolhido[8])!=0 && strcmp(buscatabela, escolhido[9])!=0))
						 {
		 					printf("Word not found! \n");
						 }
						 for(int p=0; p<=9; p++)
						 {					 	
						 	if(strcmp(buscatabela, teste2[p])==0)
						 	{					 		
						 		jatem=1;
						 	}
						 }
						 if(jatem==1)
						 {
						 	printf("Oops! This word has already been found!\n");
						 }	 
						}while(jatem==1 && strcmp(buscatabela,"HELP")!=0);
						if(strcmp(buscatabela,"HELP")==0)
						{
							for(int d=0; d<=9; d++)
							{
								printf("%s.\n",escolhido[d]);
							}
						}
					}while((strcmp(buscatabela, teste)!=0) && (strcmp(buscatabela, escolhido[0])!=0 && strcmp(buscatabela, escolhido[1])!=0 && strcmp(buscatabela, escolhido[2])!=0 && strcmp(buscatabela, escolhido[3])!=0 && strcmp(buscatabela, escolhido[4])!=0 &&
		 			strcmp(buscatabela, escolhido[5])!=0 && strcmp(buscatabela, escolhido[6])!=0 && strcmp(buscatabela, escolhido[7])!=0 && strcmp(buscatabela, escolhido[8])!=0 && strcmp(buscatabela, escolhido[9])!=0)); 
					 for(int p=0; p<=9; p++)
						 {
						 	if(strcmp(teste2[p]," ")==0);
						 	{
						 		strcpy(teste2[p],buscatabela);
						 		break;
						 	}
						 }
					 
					  z=strlen(buscatabela)-1;
					  falha=0;
					  achou=0;
					  for(int l=0; l<10; l++)
					  {
					  	for(int c=0; c<15; c++)
					  	{
					  		if(tabela[l][c]==buscatabela[0] || tolower(buscatabela[0])==tabela[l][c])
					  		{
					  			
					  			falha=0;
							    achou=0;
					  			for(int t=1; t<=z; t++)
					  			{
								  	
					  				if(tabela[l][c+t] != buscatabela[0+t] && tolower(buscatabela[0+t])!=tabela[l][c+t])
					  				{
					  					
					  					falha=1;
					  				}
					  			}
					  				if(falha==0)
					  				{
					  					
					  					for(int h=0; h<=z; h++)
					  					{
					  						tabela[l][c+h]=tolower (tabela[l][c+h]);				
					  						
					  					}
					  					achou=1;
					  				}else{
					  					falha=0;
					  					for(int h=1; h<=z; h++)
					  					{
					  						if(tabela[l+h][c] != buscatabela[0+h] && tolower(buscatabela[0+h])!=tabela[l+h][c])
					  						{
					  							
					  							falha=1;
					  						}
					  					}
					  					if(falha ==0)
					  					{
					  						for(int h=0; h<=z; h++)
					  						{
					  							tabela[l+h][c]=tolower (tabela[l+h][c]);
					  							
					  							achou=1;
					  						}
					  					}
					  				}
					  		
					  		}if(achou ==1)
					  		{
					  			break;
					  		}
					  	}if(achou ==1)
					  	{
					  		zerado++;
					  		break;
					  	}
					  }
		
				}while((zerado <=9)&&(strcmp(buscatabela, teste)!=0));
				system("cls");
				if(strcmp(buscatabela, "EXIT")==0)
				{
					for(int x = 0; x < 10; x++)
					{
						strcpy(teste2[x], " ");
					}
					break;
				}
				int again=0;
				printf("\n");
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					for(int x=0; x<10; x++)
					{
						for(int y=0; y<15; y++)
						{			
							if(islower(tabela[x][y]))
							{
								SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), v );
	    						printf(" %c",toupper(tabela[x][y]));
							}else{
								SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );
								printf(" %c",tabela[x][y]);
							}
							
				
						}		
						printf("\n");
					}
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );
				printf("\n");
				printf("CONGRATULATIONS! You've found all the words!.\n");
				system("pause");
				break;
				}
				
			case 2:
			{
				system("cls");
			
				printf("                                     ¯__ ¯                                           \n");
				printf("                             ______¦¦ ¦¦¦_ ¦¦_ ¯_                                    \n");
				printf("                         ¦¦¦¦¦¦¦¦¦¦¯ _¦¦¦¦¦¦¦¦¦ ¦¦                                   \n");
				printf("               ______ _  ¦¯¦¦¦¦¦¦¦¦_¦¦¦¦¦¦_¦¦¦¦ ¦¦¦___ _ ______                      \n");
				printf("               ¦      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦   ¦¦      ¦                      \n");
				printf("               ¦       ¦  ¦¦¦¦¦¦¦¦_¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦   ¦       ¦                      \n");
				printf("               ¦   _  ¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦_¦¦¦   ¦¦  _   ¦                      \n");
				printf("               ¦   ¦¦¦¦     ¯¯¯¯¯¦¦¦¦¦¦¦¦¦¦¦¯¯¯  ¦¦¦   ¦¦¦¦   ¦                      \n");
				printf("               ¦   ¦¦¦¦  _¦_        ¦¦¦¦¦¦       ¦¦¦   ¦¦¦¦   ¦                      \n");
				printf("               ¦_ ¦¦ ¦¦   ¯   ¦¦____¦¦  ¦__¦¦¦¦¦¦¦ ¯   ¦¦ ¦¦ _¦                      \n");
				printf("               ¦¦  ¦_ ¯¦_     ¦¦¦¦¦¦¦    ¦¦¦¦¦¦¦¦¦   _¦¯ _¦  ¦¦                      \n");
				printf("               ¦¯_  ¯¯__¦¯_   ¯¯¦¦¦¦¦¦  ¦¦¦____ ¯¯ _¯¦__¯¯  _¯¦                      \n");
				printf("        _      ¦  ¯¯__  ¯¯_¯_    ¦¦¦¯¯¯¯¯¯ ¦¦¦¦¦ _¯_¯¯  __¯¯  ¦                      \n");
				printf("        ¦¦     ¦     ¯¦¦_ ¦¦¦¦   ___ ¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦ _¦¯      ¦  _      _            \n");
				printf("       _¯      ¦   _  ¦¦¦¦¦¦¦   ¦¦¦¦ ¦¦¦¦¦       ¦¦¦¦¦_       ¦  ¦¦     ¦¦           \n");
				printf("     _¯__¯     ¦   ¦¦ ¦¦¦¦_¯           __¯¯¯¦¦__  ¯_¦¦¦¦      ¯__¦¦    _¯            \n");
				printf("    ¦¦¦¦¦      ¯ __¦¦¦¦¦¯           _¦¦¦     ¦¦¦¦    ¦¯     _¦¦¦¯    _¯__¯           \n");
				printf("    ¦¦¦¦¦     _¦¦¦¯  ¦¦¦           ¦¦¦¦¦    ¦¦¦¦¦¦ _¯__¯   ¦¦¦¦¦    ¦¦¦¦¦            \n");
				printf("    ¦¦¦¦¦¦   ¦¦¦¦¦  ¦¦¦           ¦¦¦¦¦     ¦¦¦¦¦ ¦¦¦¦¦    ¦¦¦¦¦    ¦¦¦¦¦            \n");
				printf("     ¦¦¦¦¦   ¦¦¦¦¦ ¦¦¦¦    ____¦¦¦¦¦¦¦¦    ¦¦¦¦¦¦ ¦¦¦¦¦    __¦¦¦¦¦  ¦¦¦¦¦¦           \n");
				printf("     ¦¦¦¦¦¦  __¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¯   ¯¦¦¦¦¦   ¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¯ ¦¦¦¦¦¦¦¦¦           \n");
				printf(" ¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¯ ¦¦¦  ¦¦¦¦¦     _¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦          \n");
				printf(" ¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦ ¦¦¦¦¦¦    ¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦   ¦¦¦¦ ¦¦¦¦¦¦         \n");
				printf(" ¦¦¦¦  ¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦   ¦¦¦¦¦¦¦¦   ¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦        \n");
				printf(" ¦¦¦¦¦_¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦    ¦¦¦¦¦¦¦¦    ¯¯¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦__¦¦¦¦  ¦¦¦¦¦¦        \n");
				printf(" ¦¦¦¦¦¦¦¦¦¦¯¦¦¦¦¦_¦¦¦¦¦¦¦¦¦¦    ¦¦¦¦¦¦        ¦¦¦¦¦  ¦¦¦¦¦¦ ¯¯¯¦¦¦¦¦¦ _¦¦¦¦¦¦        \n");
				printf(" ¦¦¦¦¦¦¦¦¦___¦¦¯¯¯¦¦¦¦¦¦¦¦¦¦___¦¦¦¦¦¯         ¦¦¦¦¦ _¦¦¦¦¦¦   ¦ ¦¦¦¦¦¦¦¦¦¦¦¯         \n");
				printf("  ¦¦¦¦    ¯¯¯¦¦¦¦_____¦¦   ¯¯¯¯¯              ¦¦¦¦¦¦¦¦¦¦¦¯    ¦ ¦¦¦¦¦¦¦¯¯¯           \n");
				printf("  ¯¯¯¯         _¯¯¯¦¦¦¦¦¦                     ¦¦¦¦¦¦¦¯¯¯      ¦                      \n");
				printf("               ¦     ¦¦¦¦                                     ¦                      \n");
				printf("               ¦                                              ¦                      \n");
				printf("               ¦     _   ___   ___  _    ___ ___  _  ______   ¦                      \n");
				printf("               ¦    /_\\ |   \\ / _ \\| |  | __/ _ \\| |/ /__ /   ¦                  \n");        
				printf("               ¦   / _ \\| |) | (_) | |__| _| (_) | ' < |_ \\   ¦                    \n");              
				printf("               ¦  /_/ \\_\\___/ \\___/|____|_| \\___/|_|\\_\\___/   ¦				  \n");                                
				printf("               ¦___                                        ___¦                      \n");
				printf("        	       Luiz Adolfo - Software Engineering 2015\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				system("pause");
				break;
			}
							
			case 4: 
			{
				system("cls");
				printf("		 _______  _______  _______               _______          \n");
				printf("		(  ____ \\(  ____ \\(  ____ \\    |\\     /|(  ___  )|\\     /|\n");
				printf("		| (    \\/| (    \\/| (    \\/    ( \\   / )| (   ) || )   ( |\n");
				printf("		| (_____ | (__    | (__         \\ (_) / | |   | || |   | |\n");
				printf("		(_____  )|  __)   |  __)         \\   /  | |   | || |   | |\n");
				printf(" 	              ) || (      | (             ) (   | |   | || |   | |\n");
				printf("		/\\____) || (____/\\| (____/\\       | |   | (___) || (___) |\n");
				printf("		\\_______)(_______/(_______/       \\_/   (_______)(_______)\n");
				printf("                                                       Ride Like The Wind! \n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				break;			
			}
			
			case 3:
			{
				char wordToEdit[7];
				char newWord[7];
								
				do
				{				
					system("cls");
					printf("Default words: \n \n");
					
					for(int x = 0; x < 19; x++)
					{
						printf(" - ");
						printf(vet[x]);
						printf("\n");
					}
					printf("\n*Type only characters*");	
					printf("\n*Type \"BACK\" to return to menu*");			
					printf("\n Type the word to edit: ");
					fflush(stdin);
					gets(wordToEdit);
					for(int y = 0; y < 7; y++)
					{
						wordToEdit[y] = toupper(wordToEdit[y]);
					}
					
					if(strcmp(wordToEdit, "BACK") == 0)
					{
						break;						
					}
					
					for(int x = 0; x < 19; x++)
					{
						if(strcmp(wordToEdit, vet[x])==0)
						{
							printf("\n Type the new word (max 8 characters): ");
							fflush(stdin);
							gets(newWord);
							for(int y = 0; y < 7; y++)
							{
								newWord[y] = toupper(newWord[y]);
							}
							
							if(strcmp(newWord, "EXIT") == 0 || strcmp(newWord, "HELP") == 0)
							{
								printf("\n Invalid word!\n");
								system("pause");
								break;							
							}
							
							for(int z = 0; z < 19; z++)
							{
								if(strcmp(vet[z], newWord) == 0)
								{
									printf("\n Word already exists!\n");
									system("pause");
									break;									
								}
							}
							
							if(strlen(newWord) > 8)
							{
								printf("\n This word is too big!\n");
								system("pause");
								break;									
							}
							
							strcpy(vet[x], newWord);
							break;
						}
						
						if(x == 19)
						{
							printf("\n Word not found!\n");
							system("pause");
						}
					}
				}while(true);				
				break;		
			}
		}




	}while(menu != 4);
	
	system("pause");
	return 0;
}


