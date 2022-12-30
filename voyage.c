
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct date{
    int jour;
    int mois;
    int annee;
    }date;
typedef struct voyage{
    char destination[100];
    date d;
    float prix ;

    }voyage;

 void menu()
    {
        int choice ;
        main:

		printf("\n\n\t\t ****************************************************************");
		printf("\n\t\t                               Bienvenue                  ");
		printf("\n\t\t   ***************************************************************");
		printf("\n\n\n\t\t choisir un choix  (1-5):");

		printf("\n\n\t\t 1.Ajouter le voyage. ");
		printf("\n\n\t\t 2. Afficher la description du voyage.");
		printf("\n\n\t\t 3.Supprimer un voyage.");
		printf("\n\n\t\t 4.chercher un voyage entre deux dates donnees.");
		printf("\n\n\t\t 5.modifier un voyage.");
		printf("\n\n\t\t 6.chercher un voyage selon une date precise.");

		printf("\n\n\t\t Entrer votre choix :");



		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			ajouter();
			break;
		case 2:
			description();
			break;
		case 3:
			supprimer();
			break;
		case 4:

				  chercher_entre_deux_date();
				  break;
        case 5:
            modifier_voyage();
            break;
         case 6:
            cherche_date();
            break;


		default:
			printf("\n\n\t choix invalide!");
			printf("\n\n\t svp choisir entre(1-5)");
		}
		getch();
	}
int rechercher(struct voyage travel){
   struct voyage v;
   int nb;
    FILE * f ;
    f=fopen("voyage.txt","r+");
    if (f!=NULL)
    {
        fscanf(f,"%s %d %d %d %f",&v.destination,&v.d.jour ,&v.d.mois ,&v.d.annee,&v.prix);
        if (strcmp(v.destination,travel.destination) && v.d.jour==travel.d.jour && v.d.mois==travel.d.mois && v.d.annee==travel.d.annee && v.prix== travel.prix){
        nb=1;
        }
        else nb=-1;

    };

    fclose(f);
    return nb;

}
void ajouter () {
    int choice;
    voyage travel;
    FILE*f;
    int n;
    f=fopen("voyage.txt","w");
        printf("\n\n\t ///Saisir le nbre de voyages a ajouter:/// ");
        scanf("%d",&n);
        for (int i=0;i<n;i++) {
        printf("\n saisir votre destination:");
        scanf("%s",&travel.destination);
        printf("\n saisir le jour du voyage:");
        scanf("%d",&travel.d.jour);
        printf("\n saisir le mois du voyage:");
        scanf("%d",&travel.d.mois);
        printf("\n saisir l'ann�e du voyage:");
        scanf("%d",&travel.d.mois);
        printf("\n saisir votre prix:");
        scanf("%f",&travel.prix);
    fprintf(f,"%s %d %d %d %f \n",travel.destination,travel.d.jour ,travel.d.mois ,travel.d.annee,travel.prix);}
    fclose(f);
    printf("\n\n\t\t tapez 0 pour revenir au menu :");
		printf("\n\n\t\t tapez 1 pour quitter :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			menu();
			break;
        case 1:
            printf("\n\n\t MERCI pour choisir notre agence ");
            break;

		default:
			printf("\n\n\t Veuillez choisir 0 ou 1: ");
getch();}

 }


void description () {
    int choice ;
    char ch[100] ;
    FILE*f;
    voyage v;
    printf("\n saisir la destination : ");
    scanf("%s",&ch);
    f=fopen("voyage.txt","r");
    int s=0;
    if(f!=NULL){
        fscanf(f,"%s %d %d %d  %f",&v.destination,&v.d.jour ,&v.d.mois ,&v.d.annee,&v.prix);
        fflush(stdin);
        if (strcmp(ch,v.destination)==0){
        s=s+1;
        printf("%s %d %d %d %f",v.destination,v.d.jour ,v.d.mois ,v.d.annee,v.prix);
        }
        }
        fclose(f);

    if (s==0)
        printf("la destination saisie est introuvable");
    fclose(f);
    printf("\n\n\t\t tapez 0 pour revenir au menu :");
    printf("\n\n\t\t tapez 1 pour quitter :");
    scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			menu();
			break;
        case 1:
            printf("\n\n\t MERCI pour choisir notre agence ");
            break;

		default:
			printf("\n\n\t Veuillez choisir 0 ou 1: ");
getch();}

}


void supprimer(){
     int choice ;
    struct voyage  v ,travel ;
    FILE*f1,*f2;
    f1=fopen("voyage.txt","r");
    f2=fopen("voyagejdid.txt","w");

        printf("\n saisir votre destination:");
        scanf("%s",&travel.destination);
        printf("\n saisir la jour du voyage:");
        scanf("%d",&travel.d.jour);
        printf("\n saisir le mois du voyage:");
        scanf("%d",&travel.d.mois);
        printf("\n saisir l'ann�e du voyage:");
        scanf("%d",&travel.d.annee);
        printf("\n saisir votre prix:");
        scanf("%f",&travel.prix);

        {
   if(f1!=NULL)
    {
        fscanf(f1,"%s %d %d %d %f",&v.destination,&v.d.jour,&v.d.mois,&v.prix,&v.prix);
        if(strcmp(v.destination,travel.destination)!=0 && v.d.jour!=travel.d.jour && v.d.mois!=travel.d.mois && v.d.annee!=travel.d.annee && v.prix!= travel.prix)
        {fprintf(f2,"%s %d %d %d %f /n",v.destination,v.d.jour ,v.d.mois ,v.d.annee,v.prix);}
        }



    else {printf("ce voyage n'existe pas");}
    fclose(f1);
    fclose(f2);
    remove("voyage.txt");
    rename("voyagejdid.txt","voyage.txt") ;
    printf("\n*****la suppression est faite avec succ�s*****");
    printf("\n\n\t\t tapez 0 pour revenir au menu :");
		printf("\n\n\t\t tapez 1 pour quitter :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			menu();
			break;
        case 1:
            printf("\n\n\t MERCI pour choisir notre agence ");
            break;

		default:
			printf("\n\n\t Veuillez choisir 0 ou 1: ");
getch();}

}
 }
void modifier_voyage()
{
     int choice ;
FILE*f;
FILE*fich;
            f=fopen("voyage.txt","r");
            fich=fopen("voyagejdid.txt","w");
struct voyage v,travel;

    printf("\n entrer la destination du voyage a modifier :");
    scanf("%s",&travel.destination);
        if (f!=NULL){
            fscanf(f,"%s %d %d %d %f",&v.destination,&v.d.jour ,&v.d.mois ,&v.d.annee,&v.prix);
            if (strcmp(v.destination,travel.destination)==0){

                printf("\n sasisir le nouveau jour:");
                scanf("%d",&v.d.jour);
                printf("\n sasisir le nouveau mois :");
                scanf("%d",&v.d.mois);
                printf("\n sasisir la nouvelle annee :");
                scanf("%d",&v.d.annee);
                printf("\n saisir le nouveau prix du voyage :");
                scanf("%f",&v.prix);




            fprintf(fich,"%s, %d /%d/ %d ,%f ",v.destination,v.d.jour ,v.d.mois ,v.d.annee,v.prix);


        fclose(f);
        fclose(fich);
        remove("voyage.txt");
        rename("voyagejdid.txt","voyage.txt");
        printf("\n\n\t\t tapez 0 pour revenir au menu :");
		printf("\n\n\t\t tapez 1 pour quitter :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			menu();
			break;
        case 1:
            printf("\n\n\t MERCI pour choisir notre agence ");
            break;

		default:
			printf("\n\n\t Veuillez choisir 0 ou 1: ");
getch();}
}}}

void cherche_date(){
     int choice ;
int x1, x2 , x3, s=0;
    struct voyage v;
    FILE*f ;
    f=fopen("voyage.txt","r+");
    printf("saisir le jour de la date voulu :");
    scanf("%d",&x1);
   printf("\n saisir le mois de la date voulu:");
    scanf("%d",&x2);
    printf("\n saisir l'année de la date voulu:");
    scanf("%d",&x3);

    if (f!=NULL){
        fscanf(f,"%s %d %d %d %f",&v.destination,&v.d.jour,&v.d.mois,&v.d.annee,&v.prix);
        fflush(stdin);
        if(v.d.annee==x3 &&  v.d.mois==x2 && v.d.jour==x1){
            printf("%s, %d / %d / %d, %f",v.destination,v.d.jour,v.d.mois,v.d.annee,v.prix);
            s=s+1;
            return (s);

        }
        if (s==0){
            printf("ce voyage n'existe pas");
        }

    }
    printf("\n\n\t\t tapez 0 pour revenir au menu :");
    printf("\n\n\t\t tapez 1 pour quitter :");
    scanf("%d", &choice);
        switch (choice)
		{
		case 0:
			menu();
			break;
        case 1:
            printf("\n\n\t MERCI pour choisir notre agence ");
            break;

		default:
			printf("\n\n\t Veuillez choisir 0 ou 1: ");
getch();}

 }
 void chercher_entre_deux_date(){
     int choice ;
    int x1, x2, y1, y2, x3, y3, s=0;
    struct voyage v;
    FILE*f ;
    f=fopen("voyage.txt","r+");
    printf("saisir le jour de la 1ere date:");
    scanf("%d",&x1);
   printf("\n saisir le mois de la 1ere date:");
    scanf("%d",&x2);
  printf("\n saisir l'année de la 1ere date:");
    scanf("%d",&x3);
  printf("\n saisir le jour de la 2eme date:");
    scanf("%d",&y1);
  printf("\n saisir le mois de la 2eme date:");
    scanf("%d",&y2);
  printf("\n saisir l'année de la 2eme date:");
    scanf("%d",&y3);
 if (f!=NULL){
        fscanf(f,"%s %d %d %d %f",&v.destination,&v.d.jour,&v.d.mois,&v.d.annee,&v.prix);
        if(v.d.annee==x3 && v.d.annee==y3){
            if( v.d.mois==x2 && v.d.mois==y2){
                if( v.d.jour>x1 && v.d.jour<y1){
                    printf("%s, %d / %d / %d, %f",v.destination,v.d.jour,v.d.mois,v.d.annee,v.prix);
                    s=s+1;
                }
            }
            else if( v.d.mois>x2 && v.d.mois<y2){
                printf("%s, %d / %d / %d, %f",v.destination,v.d.jour,v.d.mois,v.d.annee,v.prix);
                s=s+1;

            }
        }
        else if(v.d.annee<x3 && v.d.annee>y3){
            printf("%s, %d / %d / %d, %f",v.destination,v.d.jour,v.d.mois,v.d.annee,v.prix);
            s=s+1;
        }
    }
    fclose(f);
     printf("\n\n\t\t tapez 0 pour revenir au menu :");
    printf("\n\n\t\t tapez 1 pour quitter :");
    scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			menu();
			break;
        case 1:
            printf("\n\n\t MERCI pour choisir notre agence ");
            break;

		default:
			printf("\n\n\t Veuillez choisir 0 ou 1: ");
getch();}
}








