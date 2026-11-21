#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

time_t ultimo_tempo; //cria uma varáivel do tipo time int, responsável por pegar o tempo a cada passada do ciclo


//funcao opcao
int opcao = 1;
int fome= 0;
int energia = 100;
int love = 0;

//funcao bolo


void atualizar_tempo()
{
	time_t tempo_agora = time(NULL); //guarda a data e hora atual
	double sec = difftime(tempo_agora, ultimo_tempo); //define que o double sec será a diferença de tempo entre essas duas
	
	if (sec >= 25.0 ){
		int ciclos = (int)(sec / 25.0);
		
		fome += (ciclos * 5);// a fome vai aumentando
		energia -= (ciclos * 3);
		
		
		//travas de sefurança
		if (fome > 100) fome = 100;
		if (energia < 0) energia = 0; 
	
		ultimo_tempo = tempo_agora; //necessário para evitar que cobre ciclos infinitos
	}
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);//definidas duas variáveis x e y, o 033 diz que é um comando interno nao para printar na tela, o %d é substituído pelo Y, e o segundo %d pelo X, e o H significa cursor position pela tabela ANSI. Nós digitamos x e y, mas pelas regras ANSI o terminal entende y e x, então o gotoxy cria essa abstração para que possamos usar nossa sequência e ser traduzida ao terminal
}





void cake(){


system("clear");



//desenho do bolinho
printf("                               #############                         \n");
printf("                             ################                        \n");
printf("                             ####--###+.#####                        \n");
printf("                             #######++#######                        \n");
printf("                             #####+....-#####      +-...+..--..-+    \n");
printf("                            #################      +-..........-+    \n");
printf("                            ##################     ++++++++++++++    \n");
printf("                         #########++++++#######    ++----------++    \n");
printf("                        ########-       .######    ++++++++++++++    \n");
printf("                        #######-.        .######                     \n");
printf("                        #######-          ######                     \n");
printf("                        ######+.          #######                    \n");
printf("                        ######.           #######                   \n");
printf("                         #####.        .-########                    \n");
printf("                        ###..##-.     -##-.#####                     \n");
printf("                       ##-....-########-....-###                     \n");
printf("                       ##++++++##    ##++++++##                      \n");












love++;
}   








//funcao hamburguer

void hamburguer()

{
	
system("clear");

//desenho do hamburguer

			printf("                              ##############                         \n");
			printf("                             ################                        \n");
			printf("                             ####--###+.#####                        \n");
			printf("                             ################                        \n");
			printf("                             #######++#######                        \n");
			printf("                             #####+....-#####                        \n");
			printf("                            #################         ##########     \n");
			printf("                            ##################     ##+.........-+#  \n");
			printf("                         #########++++++#######    ##-----------+#  \n");
			printf("                        ########-       .######    ##+++++++++++##   \n");
			printf("                        #######-.        .######   ##------------#   \n");
			printf("                        #######-          ######    #############    \n");
			printf("                        ######+.          #######                    \n");
			printf("                        ######.           #######                    \n");
			printf("                        ######.           #######                    \n");
			printf("                         #####.        .-########                    \n");
			printf("                        ###..##-.     -##-.#####                     \n");
			printf("                       ##-....-########-....-###                     \n");
			printf("                       ##++++++##    ##++++++##                      \n");
			

          
            

			love++;
            

}




void loving()
{
 system("clear");
    printf("               -++. -++                            .+##+++###-               \n");
    printf("              +##+###+##.                          -#+++++++#-               \n");
    printf("              +#-++++++#.                          .-+++++++-.               \n");
    printf("               -+++++++          .-#############-.    +++++.                 \n");
    printf("               .-##+.          -####-+####-+####-     .-.                   \n");
    printf("                                +####-+####-+####-                           \n");
    printf("                                +################-                           \n");
    printf("                                +################-                           \n");
    printf("                                +#####+-...-+####-                           \n");
    printf("                               .+######++++++####-                           \n");
    printf("                               +##################-                        \n");
    printf("                            .--###################+                         \n");
    printf("                            .########-......-######+                         \n");
    printf("                           -########.        -######                         \n");
    printf("                           -#######           .######.                       \n");
    printf("                           -#######           .######.                       \n");
    printf("                           -######+           .#######-                      \n");
    printf("                           -#####+            .#######-                     \n");
    printf("                           -#####+            .#######-                      \n");
    printf("                          .-####+           .+#######-                      \n");
    printf("                           .-####+.        .+#########.                      \n");
    printf("                          -##--.-+#+.     +##-..-####.                       \n");
    printf("                          +#......-########+......+#+.                       \n");
    printf("                          +#########.     ##########                         \n");

	
	printf("\n");
    love++;
    usleep(750000);
}




void eathamburguer()
{
   system("clear");
    hamburguer();
    gotoxy(1, 23);//vá para coluna 1, linha 23
    printf("Eating: [#  ]");
    fflush(stdout);//essa função serve para limpar o buffer de saída, tornando o printf imediato
    usleep(900000);//paraliza momentaneamente

    system("clear");
    hamburguer();
    gotoxy(1, 23); 
    printf("Eating: [## ]");
    fflush(stdout);
    usleep(900000);
	
    system("clear");
    hamburguer();
    gotoxy(1, 23);
    printf("Eating: [###]");
    fflush(stdout);
    usleep(900000);
    
    system("clear");
    fome = 0;
    gotoxy(1, 5); 
    printf("Done! Tux is no more hungry!\n"); 
    gotoxy(1, 7); 
    usleep(900000);
    system("clear");
    loving();
    usleep(900000);
    system("clear");
}


void eatcake()
{
    system("clear");
    cake();
    gotoxy(1, 23); //vá para coluna 1, linha 23
    printf("Eating: [#  ]");
    fflush(stdout); //essa função serve para limpar o buffer de saída, tornando o printf imediato
    usleep(900000); ///paraliza momentaneamente

    system("clear");
    cake();
    gotoxy(1, 23); 
    printf("Eating: [## ]");
    fflush(stdout);
    usleep(900000);
	
    system("clear");
    cake();
    gotoxy(1, 23); 
    printf("Eating: [###]");
    fflush(stdout);
    usleep(900000);
    
    system("clear");
    fome = 0;
    gotoxy(1, 5); 
    printf("Done! Tux is no more hungry!\n"); 
    gotoxy(1, 7); 
    usleep(900000);
    system("clear");
    loving();
    usleep(900000);
    system("clear");
}



void tuxsleep()
{
	system("clear");
    gotoxy(1, 23);//vá para coluna 1, linha 23
    printf("Sleeping: [#  ]");
    fflush(stdout);//essa função serve para limpar o buffer de saída, tornando o printf imediato
    usleep(900000);//paraliza momentaneamente

    system("clear");
  
    gotoxy(1, 23); 
    printf("Sleeping: [## ]");
    fflush(stdout);
    usleep(900000);
	
    system("clear");
    
    gotoxy(1, 23);
    printf("Sleeping: [###]");
    fflush(stdout);
    usleep(900000);
    
    system("clear");
    energia = 100;
    gotoxy(1, 5); 
    printf("Done! Tux is no more tired!\n"); 
    gotoxy(1, 7); 
    usleep(900000);
    system("clear");
    loving();
    usleep(900000);
    system("clear");
}

void menu()
{
atualizar_tempo();
system("clear");

int comida = 0;

  

  

    

  //first tux draw
	printf("                                   #################                             \n");
	printf("                                  #####-+####+-#####                             \n");
	printf("                                  #####-+####+-#####                             \n");
	printf("                                  ##################                             \n");
	printf("                                  ##################                             \n");
	printf("                                  #######-...-+#####                             \n");
	printf("                                  ######+.....-#####                             \n");
	printf("                                ######################                           \n");
	printf("                                ######################                           \n");
	printf("                              #########++++++++########                          \n");
	printf("                             #########-.      ..#######                          \n");
	printf("                             ########+.         +#######                         \n");
	printf("                            #######+            -######                         \n");
	printf("                             #######+            -#######                       \n");
	printf("                             ######+-            -########                      \n");
	printf("                             ######-             -########                       \n");
	printf("                              #####-            +#########                       \n");
	printf("                             ###++#+-        .-##+########                       \n");
	printf("                           ###+-..-+#+.     -##-..--####                         \n");
	printf("                           ##-......-########+.......###                         \n");
	printf("                           ############     ###########                         \n");












	







printf("Actions:\n");
printf("\n");
printf("\n [1] Hamburguer");
printf("\n [2] Cake");
printf("\n [3] Pet Tux");
printf("\n [4] Sleep");
printf("\n [5] Exit the game");
printf("\n Hungry: %d", fome);
printf("\n Energy: %d", energia);
printf("\n Love: %d", love);
printf("\n");
printf("\n");
printf("\n");
scanf(" %d", &comida);

switch(comida)
{
	case 1:
	eathamburguer();
	
	break;
	
	case 2:
	eatcake();
	
	break;

    case 3:
    loving();
    
    break;
	
	case 4:
	tuxsleep();
	break;
	
	case 5:
	opcao = 0;
	break;
	
	default:
	
	break;
}
}




int main()
{
	
	printf("welcome to MyTux!\n");
	printf("Press any key to continue\n");
	getchar();
	
	ultimo_tempo = time(NULL);
	
	while(opcao == 1)
	{
		menu();
		
		}
	
		return 0;
	}



