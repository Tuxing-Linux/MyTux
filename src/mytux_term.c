#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//funcao opcao
int opcao = 1;
int fome= 100;
int sono = 100;
int love = 0;

//funcao bolo

void cake(){

opcao = 0;
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










fome= 0;
printf("Tux is no more hungry\n");

getchar();
printf("Tux loved it\n");
love++;
getchar();


opcao = 1;
}   








//funcao hamburguer

void hamburguer()

{
	opcao = 0;
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
			

          
            fome= 0;
            printf("Tux is no more hungry\n");
            getchar();
            printf("Tux loved it\n");
			love++;
			getchar();
            
            opcao = 1; 
}













void menu()
{

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












	







printf("Tux is hungry, feed him\n");
printf("choose beetween hamburguer or cake\n");
printf("\n [1] Hamburguer");
printf("\n [2] Cake");
printf("\n [3] Exit the game");
printf("\n");
scanf(" %d", &comida);

switch(comida)
{
	case 1:
	hamburguer();
	menu();
	break;
	
	case 2:
	cake();
	menu();
	break;
	
	case 3:
	opcao = 0;
	break;
	
	default:
	menu();
	break;
}
}




int main()
{
	
	printf("welcome to MyTux!\n");
	printf("Press any key to continue\n");
	getchar();
	
	
	while(opcao == 1)
	{
		menu();
		
		}
	
		return 0;
	}



