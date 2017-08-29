
// by @ alibi mourad et ben amor amani 

#include <stdio.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include <windows.h>
#include<wincon.h>
#include <unistd.h>
#include <math.h>
void color_console(WORD text_color, WORD bg_color){
    HANDLE console_h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_h, text_color|bg_color*16);
}

char* choix_mot(){
FILE *in;
int nb_lignes=0,i=0,j;
char c,*mot;

mot=(char*)malloc(7*sizeof(char));
srand(time(NULL)*100);
in = fopen ("5.txt","rt");
while ( c = fgetc(in),! feof (in) )
      {
	  if(c == '\n')
		  nb_lignes++;
      }
fclose(in);

in = fopen("5.txt", "rt");

j=rand()%nb_lignes;
j++;
do

  {
  fscanf(in,"%s",mot);    
  i++;
  }
  while(i!=j);
fclose(in);
return(mot);
}

char *allouer_chaine (int taille){
char *tab;
tab = (char *) malloc (taille * sizeof (char));
if (tab == NULL) { printf ("Erreur lors de l'allocation\n");exit(1);}
return tab ;
}

int essay( char *tab2 , int cmt ){
	int test ;
	if (cmt>= 7) {printf("Game Over!!!\n   SOLUTION : \t"); test = 0 ;}
	else  {
		printf("Essay n    %d  :",cmt+1);
		
		test=1;}
		return test ;
}

void analyse (char *tab1 , char *tab2 , char *tab3){
int i,j;
for(i=0;i<7;i++){
	if(tab3[i]=='!') tab3[i]='-' ;
	}
for ( i=0;i<7;i++){
	if((tab3[i]=='-')||(tab3[i]=='!')){
	if(tab1[i]==tab2[i]) tab3[i]=tab1[i];
	else{for ( j=1;j<7;j++) if((tab1[i]==tab2[j])&&(i!=j))
				if((tab3[i]=='-')||(tab3[i]=='!')){tab3[j]='!';}
				}
}
}
}

int vrf(char *tab1,char *tab3){
	int i;
	for ( i=0;i<7;i++) if(tab1[i]!=tab3[i])  return 1;
	printf("BRAVO!!");
	return 0;
}

void jouer() {
		srand(getpid());

char ch ;
do{
	printf("________________________________\n");    
printf("|                              |\n");
printf("|        Jeu de motus          |\n");
printf("| By@ ALIBI-MOURAD             |\n");
printf("|          & BEN AMOR AMANI    |\n");
printf("|     PROJET DE PROGRAMATION   |\n");
printf("|    GI 1 - S4 2015-2016       |\n");
printf("________________________________\n"); 
printf("\n vous avez 7 essay ! le mot se commance par : \n");
char *tab1,*tab2,*tab3;
int i,test1=1,test2=1;
tab1=allouer_chaine (7);tab2=allouer_chaine (7);tab3=allouer_chaine (7);
tab1=choix_mot();
tab3[0]=tab1[0];
for (i =1 ;i<7 ; i++) { tab3[i]='-';}
int cmt=0;
while(test1 && test2){
	printf("\t       ");
	puts(tab3);
	test1=essay(tab2,cmt);
	
	if(cmt>=7) goto out ;
	gets(tab2);
	cmt++;
	
	if( strlen(tab2)==7){
	analyse(tab1,tab2,tab3);
	test2=vrf(tab1,tab3);}
	else printf("longeur faux\n");
	out: i=0;
}

puts(tab1);
printf ("\n");
free (tab1);free (tab2);free (tab3);
do{
		color_console(4, 3);
printf("Repeter une auter fois ? [o/n] ou [O/N] :  \n");
ch=getch();}while(ch!='o'&&ch!='O'&&ch!='n'&&ch!='N');
system("cls");system("color 3f");
} while( (ch=='o') || (ch== 'O' ));
}

void open_titre(int temp, char *nom ){
	char c;
	 FILE *fich;
	 fich = fopen(nom,"r"); 
    c = fgetc(fich); 
    while (!feof(fich))  {
      putchar(c); 
	 Sleep(temp);
     c = fgetc(fich);
      }
      fclose(fich); 
  } 

void signaler_rubrique_choisie(){
	int i;
    for( i=1000; i<10001; i+=1000)
    Beep(i, 70);

}

void signaler_rubrique_selection(){
	int i;
    for( i=0;i<10;i++){
    
    Beep(1365-i*200 +5*i, 50);}

}

void animer_titre(int temp , char *nom){
    FILE *fichier=NULL;
    char ch_lu[26]="";
    int i;
    
    for(i=1;i<16;i++)
    {
		system("cls"); 
		system("color 0f"); 
      color_console(i, 0);
    fichier=fopen(nom, "r");
    if(fichier)
    {
        while(fgets(ch_lu, 26,fichier))
        {
            printf("%s", ch_lu);
        }
        fclose(fichier);
        color_console(7,0);
    }
    Sleep(temp); 
    }
    
}

void affichage(){	
	SetConsoleTitle("                                                                                                                 M . O . T . U . S ");
	system("color 3f");
	printf ("\t\t __________________________________\n");
	printf ("\t\t%c%c%c%c  Bienvenu au jeu Motus  %c%c%c%c\n",3,4,5,6,3,4,5,6);
	printf ("\t\t __________________________________\n\n");
	printf ("\t\tRealiser par :\n");
	printf ("\t\t              %c Alibi Mourad \n",16);
	printf ("\t\t              %c Ben Amor Amani\n",16);
	printf ("\t\t\t\t\t\t%c  GI1 - S4  %c \n",14,14);
	printf ("\n\t\t\t\t%c  E.N.I.S %c  2015-2016  %c \n",1,29,2);
	Sleep(800);
	open_titre(3,"zz"); system("cls");system("color 3f");
	animer_titre(190,"zz");system("color 3f");
	do {
	system("cls");
	system("color 6a"); 
	printf(" \n\n\n\n\t\tTaper [ENTRE] pour passer au menu\n");
	
	}while(getch()!=13);system("cls");signaler_rubrique_selection();
	system("color 3f");
	
	
}

int menu (){
	char tap=0;
	int point[3]={1,0,0},i=0;
	do {
		
		open_titre(0,"zz");
		printf("\n\n\n\t\t%c Jouer",point[i%3]*16);
		printf("\n\t\t%c Les regles ",point[(i+2)%3]*16);
		printf("\n\t\t%c Quiter",point[(i+1)%3]*16);
		tap=getch();if(tap==13) {signaler_rubrique_selection();break ;}
			else {tap=getch();
		 
		 signaler_rubrique_choisie();
			 if(tap==80) i++;
			 if(tap==72) i--;
		 }
			 
		 	
		system("cls");
	}while(tap!=13);
	system("cls");
	i=fabs(i);
	 return (i%3);
 }

int main (){
	char tap;
	int i;
	affichage();
	last_menu:
	switch (menu()){
		case 0: {printf("\n\n\n\n\n\n\n\n\t\t\t\t BON CHANCE  :) \t");
			for(i=1;i<6;i++){
				sleep(1);
				printf("*");
				}
		system("cls");system("color 3f");jouer();goto verif_quiter;break;}
		case 1 : {
			open_titre(1,"regles.txt");
			goto verif_quiter;
			break;}
		case 2 : {
			verif_quiter:
			printf("\n\n\t\t Vous avez quiter ??? [ENRTRER]\n");
			printf("\n\n\t\t Si non , retournez menu principal [ECHAP]\n");
			do{tap=getch();
			if(tap==13) goto fin_quit ;}
			while (tap!=27);
			system ("cls");
			goto last_menu ;
			break;
	}
	}
	fin_quit:
	system("cls");
	printf("\n\n\t\t\t%c GOOD BEY %c",1,2);
	sleep(1);
	color_console(3, 3);
	exit(0);
}

