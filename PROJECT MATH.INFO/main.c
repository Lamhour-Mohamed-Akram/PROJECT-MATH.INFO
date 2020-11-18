#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>
#include <time.h>
/*variables globales*/
char choix;
int i,j,choix1,nombre_elements=0,nb_ch=0,num_reservation=0;

/*structure gestion client*/
typedef struct {
          int id;
          char nom[15];
          char prenom[15];
          char CIN[15];
          char tele[10];
              }client;

 client c1[200];

/*structure gestion chambre*/

typedef struct {
          int id;
          char type[15];
          int prix;
                }chambre;
chambre c2[200];
/*structure gestion des reservations*/
typedef struct{
     int Numero_De_Reservation;
     char jour1[20];
     char mois1[20];
     char ann1[20];
     char jour2[20];
     char mois2[29];
     char ann2[20];
     char jour3[20];
     char mois3[20];
     char ann3[20];
     int Nuit;
     int Montons_avance;
     int Numero_De_Client;
     char Type_De_Chambre[20];
 }reservation;
 reservation rev[100];


/*prototypes des fonctions */

void menu_principale(void);
 void gestion_client(void);
 void Nouveau(void);
void consulter(void);
int chercher_client(int x);
void cadre_gestion_client(void);
void modifier_client(void);
 void supprimer(void);

void gestion_chambre(void);
 void Nouveau_chambre(void);
void consulter_chambre(void);
int chercher_chambre(int x);
void cadre_gestion_chambre(void);
void modifier_chambre(void);
void supprimer_chambre(void);

void cadre_gestion_reservation(void);
 int chercher_reservation(int x);
 void gestion_reservation(void);
 void Nouveau_reservations(void);
 void consulter_Reservation(void);
 void modifier_reservation(void);
 void supprimer_reservation(void);
 void menu_temp(void);

void menu_etat(void);
void gestion_etat(void);
void reservations_encours(void);

void table_consuler_facture_reservation(void);
void facture(void);


/*fonction principale main*/
void main(void)
{
         do
            {
              system("cls");
              menu_principale();
             gotoxy(40,25);printf("Donner votre choix (1-5) :   ");
             choix=getch();
         }while(choix!='1' && choix!='2' && choix!='3' &&choix!='4' &&choix!='5'  );

         switch(choix)
           {
            case '1':gestion_client();
                    break;
            case '2':gestion_chambre();
                    break;
            case '3': gestion_reservation();
                    break;
            case '4':gestion_etat();
                   break;
            case '5':exit(0);
                break;
            default:break;


           }
return ;
}

/* fonction principale  gestion de client*/

void gestion_client(void)
      {       system("cls");
              system("color f0");
              menu_temp();

            textcolor(YELLOW);textbackground(LIGHTCYAN);
            gotoxy(23,6);cprintf("                                  GESTION DES CLIENTS                                     ");
            gotoxy(23,7);cprintf("                                                                                          ");
            textcolor(BLUE);textbackground(LIGHTGRAY);
            gotoxy(45,11);cprintf("   F1:          NOUVEAU CLIENT                  ");
            gotoxy(45,12);cprintf("                                                ");
            gotoxy(45,13);cprintf("   F2:          CONSULTER CLIENT                ");
            gotoxy(45,14);cprintf("                                                ");
            gotoxy(45,15);cprintf("   F3:          MODIFIER CLIENT                 ");
            gotoxy(45,16);cprintf("                                                ");
            gotoxy(45,17);cprintf("   F4:          SUPRESSION CLIENT               ");
            gotoxy(45,18);cprintf("                                                ");
            gotoxy(45,19);cprintf("   ESC:                 MENU                    ");
            gotoxy(45,20);cprintf("                                                ");
            textbackground(LIGHTCYAN);textcolor(YELLOW);
            gotoxy(23,26);cprintf("       F1:Nouveau    F2:Consulter      F3:Modifier     F4:Supprimer    ESC:MENU           ");
            gotoxy(23,27);cprintf("                                                                                          ");
do{
                 gotoxy(23,30);
                 choix1=getch();
                if(choix1==59)
                  {
                 system("cls");
                 }
               switch(choix1)
                   {

                       case 59:  Nouveau();
                              break;
                       case 60:consulter();
                               break;
                       case 61:modifier_client();
                               break;
                       case 62:  supprimer();
                               break;
                       case 27: main();
                               break;
                      default:gotoxy(23,29);textcolor(RED);textbackground(LIGHTGRAY);cprintf("VOTRE CHOIX EST INCORRECT ") ;

                               break;
                   }

}while(5);
return;
}

/*fonction Nouveau pour ajouter un client*/
  void Nouveau(void)
  {               system("cls");
                 cadre_gestion_client();

                 textbackground(GREEN);textcolor(WHITE);gotoxy(53,23);cprintf(" Enregistrer ");
                 textbackground(GREEN);textcolor(WHITE);gotoxy(78,23);cprintf("  Annuler ")  ;

                 if(nombre_elements<200)
                        {
                            textcolor(BLUE);textbackground(LIGHTGRAY);
                            gotoxy(33,9);cprintf("Nouveau client :");
                             gotoxy(70,11);scanf("%d",&c1[nombre_elements].id);
                            gotoxy(70,13);scanf("%s",c1[nombre_elements].nom);
                            gotoxy(70,15);scanf("%s",c1[nombre_elements].prenom);
                            gotoxy(70,17);scanf("%s",c1[nombre_elements].CIN);
                            gotoxy(70,19);scanf("%s",c1[nombre_elements].tele);
                            gotoxy(56,21);textcolor(1);textbackground(LIGHTGRAY);cprintf("le nouveau client est ajouter");
                            nombre_elements++;
                        }
                    else{
                            gotoxy(56,21);textcolor(1);textbackground(LIGHTGRAY);cprintf("la table est pleine!!!");
                            Sleep(1000);
                        }
    return;
    }

/*fonction consulter pour consulter les clients*/

void consulter(void)
  { int idc;

                             if(nombre_elements==0)
                                {
                                  textcolor(RED);textbackground(LIGHTGRAY);
                                  gotoxy(60,9);cprintf("Table est vide!!!");
                                  Sleep(1000);
                                  gestion_client();
                                }
                           system("cls");
                           textcolor(BLUE);textbackground(LIGHTGRAY);
                           gotoxy(30,9);cprintf("Consulter Client :");
                           cadre_gestion_client();
                            textcolor(WHITE);
                             textbackground(GREEN);
                             gotoxy(33,23);
                             cprintf("    >>     ");
                             gotoxy(54,23);
                             cprintf("     >     ");
                             gotoxy(76,23);
                             cprintf("     <     ");
                             gotoxy(96,23);
                             cprintf("    <<    ");
                             gotoxy(70,11);scanf("%d",&idc);
                             chercher_client(idc);
                            if(nombre_elements>0&&chercher_client(idc)==idc)
                                   {
                                        gotoxy(70,13);printf("%s",c1[i].nom);
                                        gotoxy(70,15);printf("%s",c1[i].prenom);
                                        gotoxy(70,17);printf("%s",c1[i].CIN);
                                        gotoxy(70,19);printf("%s",c1[i].tele);
                                        gotoxy(64,21);textcolor(1);textbackground(LIGHTGRAY);cprintf("voila le client");
                                        Sleep(1000);
                                   }

                             else
                                {

                                    textcolor(RED);textbackground(LIGHTGRAY);
                                    gotoxy(55,8);cprintf("Le numero de reservation n'existe pas !!!");
                                    Sleep(1000);
                                    system("cls");
                                    gestion_client();
                                }
return;
  }

/*fonction aide chercher*/
  int chercher_client(int x)
     {int temp1,temp2;

                          for(i=0;i<nombre_elements;i++)
                             {
                                   if(x==c1[i].id)
                                       {
                                           temp1=x;temp2=i;i=nombre_elements+1;
                                       }else
                                       {
                                          temp1=-1;
                                        }
                            }
                            i=temp2;
    return temp1;
     }

/*fonction cadre de gestion client*/
 void cadre_gestion_client(void)
    {
                       for(j=0;j<=89;j++)
                            {
                                gotoxy(23+j,5);printf("\304");
                            }
                       gotoxy(22,5);
                       printf("\332");
                       for(j=0;j<=21;j++)
                            {
                              gotoxy(22,6+j);printf("\263");
                            }
                       gotoxy(22,28);
                       printf("\300");
                       for(j=0;j<=89;j++)
                            {
                                gotoxy(23+j,28);printf("\304");
                            }
                       printf("\331");
                       for(j=0;j<=21;j++)
                            {
                              gotoxy(113,27-j);printf("\263");
                            }
                       gotoxy(113,5);printf("\277");

                    textcolor(BLACK);textbackground(LIGHTGRAY);
                    gotoxy(23,6);cprintf("                                   GESTION DES CLIENTS                                    ");
                    gotoxy(23,7);cprintf("                                                                                          ");
                    gotoxy(33,11);printf("Numero De Client    :..........................................");
                    gotoxy(33,13);printf("Nom                 :..........................................");
                    gotoxy(33,15);printf("Prenom              :..........................................");
                    gotoxy(33,17);printf("CIN                 :..........................................");
                    gotoxy(33,19);printf("Tel                 :..........................................");
                    textbackground(LIGHTGRAY);textcolor(BLACK);gotoxy(23,26);
                    cprintf("       F1:Nouveau    F2:Consulter      F3:Modifier     F4:Supprimer    ESC:MENU           ");
                    gotoxy(23,27);cprintf("                                                                                          ");
   return;
    }

/*fonction qui modifie les informations des clients*/

 void modifier_client()
  {int idm;
             if(nombre_elements==0)
                {
                 textcolor(RED);textbackground(LIGHTGRAY);
                 gotoxy(60,9);cprintf("la table est vide!!!");
                 Sleep(800);
                 gestion_client();
                }
                system("cls");
              cadre_gestion_client();
             gotoxy(30,9);cprintf("Modifier Client :");
             textcolor(WHITE);textbackground(GREEN);
            gotoxy(33,23);cprintf("    >>     ");
            gotoxy(54,23);cprintf("     >     ");
            gotoxy(76,23);cprintf("     <     ");
            gotoxy(96,23);cprintf("    <<    ");

                gotoxy(70,11);scanf("%d",&idm);
                chercher_client(idm);
            if(nombre_elements>0&&chercher_client(idm)==idm)
               {
                     gotoxy(70,13);
                     scanf("%s",c1[i].nom);
                     gotoxy(70,15);
                     scanf("%s",c1[i].prenom);
                     gotoxy(70,17);
                     scanf("%s",c1[i].CIN);
                     gotoxy(70,19);
                     scanf("%s",c1[i].tele);
                     textcolor(1);textbackground(LIGHTGRAY);
                    gotoxy(60,21);cprintf(" le client est modifier");



              }
        else {
                 textcolor(RED);textbackground(LIGHTGRAY);
                 gotoxy(54,8);cprintf("ce numero de client n'existe pas!");
                 Sleep(800);
                 system("cls");
                 gestion_client();
            }
return;
  }


/*fonction supprimer pour supprimer un client*/
    void supprimer(void)
    {int ids,temp1;
     char temp2[20];
                             if(nombre_elements==0)
                                {
                                  textcolor(RED);textbackground(LIGHTGRAY);
                                  gotoxy(60,9);cprintf("la table est vide!!!");
                                  Sleep(900);
                                  gestion_client();
                                }
                                 system("cls");
                               cadre_gestion_client();
                               gotoxy(30,9);cprintf("Supprimer Client :");
                              textcolor(WHITE);textbackground(GREEN);
                              gotoxy(33,23);cprintf("    >>     ");
                              gotoxy(54,23);cprintf("     >     ");
                             gotoxy(76,23);cprintf("     <     ");
                             gotoxy(96,23);cprintf("    <<    ");

                            gotoxy(70,11);
                            scanf("%d",&ids);
                            chercher_client(ids);

                        if(nombre_elements>0&&chercher_client(ids)==ids)
                                   {
                                         gotoxy(67,13);printf("%s",c1[i].nom);
                                         gotoxy(67,15);printf("%s",c1[i].prenom);
                                         gotoxy(67,17);printf("%s",c1[i].CIN);
                                         gotoxy(67,19);printf("%s",c1[i].tele);



                                         for(j=i;j<nombre_elements;j++)
                                            {
                                                  temp1=c1[j].id;
                                                  c1[j].id=c1[j+1].id;
                                                  c1[j+1].id=temp1;

                                                  strcpy(temp2,c1[j].nom);
                                                  strcpy(c1[j].nom,c1[j+1].nom);
                                                  strcpy(c1[j+1].nom,temp2);

                                                  strcpy(temp2,c1[j].prenom);
                                                  strcpy(c1[j].prenom,c1[j+1].prenom);
                                                  strcpy(c1[j+1].prenom,temp2);

                                                  strcpy(temp2,c1[j].CIN);
                                                  strcpy(c1[j].CIN,c1[j+1].CIN);
                                                  strcpy(c1[j+1].CIN,temp2);

                                                  strcpy(temp2,c1[j].tele);
                                                 strcpy(c1[j].tele,c1[j+1].tele);
                                                 strcpy(c1[j+1].tele,temp2);

                                          }
                                                  nombre_elements--;


                                                 gotoxy(61,21);textcolor(1);textbackground(LIGHTGRAY);
                                                 cprintf(" le client est supprime");

                            }



                 else        {
                                         gotoxy(56,20);textcolor(1);textbackground(LIGHTGRAY);
                                         cprintf("ce numero de client n'existe pas !!!");
                                         Sleep(800);
                                         gestion_client();
                             }
  return;

}

/*menu_principale fonction qui affiche menu principale*/

void menu_principale(void)
    {
             system("color f0");
             textbackground(BLUE);
             textcolor(YELLOW);
             gotoxy(40,7);cprintf("                                                ");
             gotoxy(40,8);cprintf("       GESTION DEE RESERVATION HOTELIERE        ");
             gotoxy(40,9);cprintf("                                                ");

            textbackground(GREEN);
            gotoxy(40,12);cprintf("                                                ");
            gotoxy(40,13);cprintf("       GESTION DES CLIENTS                      ");
            gotoxy(40,14);cprintf("                                                ");

            textbackground(BLUE);
            gotoxy(40,15);cprintf("                                                ");
            gotoxy(40,16);cprintf("       GESTION DES CHAMBRES                     ");
            gotoxy(40,17);cprintf("                                                ");
            gotoxy(40,18);cprintf("       GESTION DES RESERVATIONS                 ");
            gotoxy(40,19);cprintf("                                                ");
            gotoxy(40,20);cprintf("       GESTION D'ETATS                          ");
            gotoxy(40,21);cprintf("                                                ");
            gotoxy(40,22);cprintf("       QUITTER                                  ");
            gotoxy(40,23);cprintf("                                                ");
return;
    }
/*fonction principale de partie gestion des chambres*/

void gestion_chambre(void)
      {
            system("color f0");
            menu_temp();
            textcolor(YELLOW);textbackground(LIGHTCYAN);
            gotoxy(23,6);cprintf("                                  GESTION DES CHAMBRES                                    ");
            gotoxy(23,7);cprintf("                                                                                          ");
            textcolor(BLUE);textbackground(LIGHTGRAY);
            gotoxy(45,11);cprintf("   F1:          NOUVEAU CHAMBRE                  ");
            gotoxy(45,12);cprintf("                                                 ");
            gotoxy(45,13);cprintf("   F2:          CONSULTER CHAMBRE                ");
            gotoxy(45,14);cprintf("                                                 ");
            gotoxy(45,15);cprintf("   F3:          MODIFIER CHAMBRE                 ");
            gotoxy(45,16);cprintf("                                                 ");
            gotoxy(45,17);cprintf("   F4:          SUPRESSION CHAMBRE               ");
            gotoxy(45,18);cprintf("                                                 ");
            gotoxy(45,19);cprintf("   ESC:                 MENU                     ");
            gotoxy(45,20);cprintf("                                                 ");
            textbackground(LIGHTCYAN);textcolor(YELLOW);
            gotoxy(23,26);cprintf("       F1:Nouveau    F2:Consulter      F3:Modifier     F4:Supprimer    ESC:MENU           ");
            gotoxy(23,27);cprintf("                                                                                          ");


do{
        gotoxy(23,30);
        choix1=getch();
        if(choix1==59)
         {
            system("cls");
         }
          system("cls");
     switch(choix1)
        {

           case 59:  Nouveau_chambre();
                  break;
           case 60:consulter_chambre();
                  break;
           case 61:modifier_chambre();
                   break;
           case 62:supprimer_chambre();
                  break;
           case 27: main();
                  break;
           default:gotoxy(23,29);printf(" votre choix est incorect ") ;
                  break;
         }

}while(5);
return;
}

/*fonction Nouveau_chambre pour ajouter une chambre*/
void Nouveau_chambre(void)
     {




                    system("cls");
                    cadre_gestion_chambre();
                    textcolor(BLUE);textbackground(LIGHTGRAY);
                    gotoxy(33,10);cprintf("Nouveau chambre :");
                   textbackground(GREEN);textcolor(WHITE);
                    gotoxy(53,22);cprintf(" Enregistrer ");
                    gotoxy(78,22);cprintf("  Annuler ")  ;

                    if(nb_ch<200 &&nb_ch>=0)
                            {
                                gotoxy(70,14);scanf("%d",&c2[nb_ch].id);
                                gotoxy(70,16);scanf("%s",c2[nb_ch].type);
                                gotoxy(70,18);scanf("%d",&c2[nb_ch].prix);
                                textcolor(1);textbackground(LIGHTGRAY);
                                gotoxy(60,20);cprintf("la chambre est ajoutee");
                                nb_ch++;
                              }


                      else{
                                textcolor(1);textbackground(LIGHTGRAY);
                                gotoxy(62,19);printf("table est pleine!!!");
                          }
return;
   }
/*fonction consulter_chambre pour afficher les chambre*/
void consulter_chambre(void)
  { int idc;

                     if(nb_ch ==0)
                         {
                    textcolor(RED);textbackground(LIGHTGRAY);
                    gotoxy(60,9);cprintf("Table est vide!!!");
                    Sleep(800);
                    gestion_chambre();
                      }
                    system("cls");
                    cadre_gestion_chambre();
                    textcolor(1);textbackground(LIGHTGRAY);
                    gotoxy(30,12);cprintf("Consulter Chambre :");
                   textcolor(WHITE);textbackground(GREEN);
                    gotoxy(33,22);cprintf("    >>     ");
                   gotoxy(54,22);cprintf("     >     ");
                   gotoxy(76,22);cprintf("     <     ");
                  gotoxy(96,22);cprintf("    <<    ");
                  gotoxy(70,14);scanf("%d",&idc);
                  chercher_chambre(idc);
              if(nb_ch>0&&chercher_chambre(idc)==idc)
                    {

                                             gotoxy(70,16);printf("%s",c2[i].type);
                                              gotoxy(70,18);printf("%d",c2[i].prix);
                                              gotoxy(60,20);textcolor(1);textbackground(LIGHTGRAY);
                                              cprintf("voila la chambre  !!!");

                       }
                 else
                       {
                            textcolor(RED);textbackground(LIGHTGRAY);
                            gotoxy(55,8);cprintf("Le numero de chambre n'existe pas !!!");
                            Sleep(800);
                            system("cls");
                            gestion_chambre();
                        }
return;
  }
/*fonction rechercher_chambre sa role est aider les fonction consulter  modifier et supprimer*/

int chercher_chambre(int x)
     {int temp1,temp2;

                    for(i=0;i<nb_ch;i++)
                          {
                               if(x==c2[i].id)
                                   {
                                     temp1=x;
                                     temp2=i;
                                     i=nb_ch+1;
                                   }

                               else {temp1=-1;}
                           }
                           i=temp2;
     return temp1;
     }


/*fonction cadre de gestion de chambres*/

 void cadre_gestion_chambre(void)
    {
                      for(j=0;j<=89;j++)
                            {
                                gotoxy(23+j,5);printf("\304");
                            }
                      gotoxy(22,5);printf("\332");

                      for(j=0;j<=21;j++)
                            {
                              gotoxy(22,6+j);printf("\263");
                            }
                      gotoxy(22,28);printf("\300");

                      for(j=0;j<=89;j++)
                            {
                              gotoxy(23+j,28);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=21;j++)
                            {
                              gotoxy(113,27-j);printf("\263");
                            }
                     gotoxy(113,5);printf("\277");

                    textcolor(BLACK);textbackground(LIGHTGRAY);
                    gotoxy(23,6);cprintf("                                   GESTION DES CHAMBRES                                   ");
                    gotoxy(23,7);printf("                                                                                          ");
                    gotoxy(33,14);printf("Numero De Chambre    :..........................................");
                    gotoxy(33,16);printf("Type De Chambre      :..........................................");
                    gotoxy(33,18);printf("Prix                 :..........................................");
                    textbackground(LIGHTGRAY);textcolor(BLACK);
                    gotoxy(23,26);cprintf("       F1:Nouveau    F2:Consulter      F3:Modifier     F4:Supprimer    ESC:MENU           ");
                    gotoxy(23,27);cprintf("                                                                                          ");
   return;
    }


void modifier_chambre(void)
    { int idm;
                            if(nb_ch==0)
                                 {
                                   textcolor(RED);textbackground(LIGHTGRAY);
                                   gotoxy(60,9);cprintf("La table est vide!!!");
                                    Sleep(800);
                                    gestion_chambre();
                                  }

                            system("cls");
                             cadre_gestion_chambre();
                             gotoxy(30,10);cprintf("Modifier chambre:");
                             textcolor(WHITE);textbackground(GREEN);
                             gotoxy(33,23);cprintf("    >>     ");
                             gotoxy(54,23);cprintf("     >     ");
                             gotoxy(76,23);cprintf("     <     ");
                             gotoxy(96,23);cprintf("    <<    ");
                             gotoxy(70,14);scanf("%d",&idm);
                             chercher_chambre(idm);
                              if(nb_ch>0&&chercher_chambre(idm)==idm)
                                {
                                              gotoxy(70,16);scanf("%s",c2[i].type);
                                              gotoxy(70,18);scanf("%d",&c2[i].prix);
                                              textcolor(1);textbackground(LIGHTGRAY);
                                              gotoxy(57,20);cprintf("la chambre est modifier");
                                }
                            else
                               {
                                               textcolor(RED);textbackground(LIGHTGRAY);
                                               gotoxy(54,8);cprintf("ce numero de client n'existe pas!");
                                               Sleep(800);
                                               system("cls");
                                               gestion_chambre();

                                }

return;
    }

/*fonction supprimer_chambre pour supprimer les chambres*/

void supprimer_chambre(void)
    {int temp1,ids;
     char temp2[15];
                       if(nb_ch==0)
                                 {
                                   textcolor(RED);textbackground(LIGHTGRAY);
                                   gotoxy(60,9);cprintf("La table est vide!!!");
                                    Sleep(800);
                                    gestion_chambre();
                                  }


                       system("cls");
                       cadre_gestion_chambre();
                       textcolor(WHITE);textbackground(GREEN);
                       gotoxy(33,23);cprintf("    >>     ");
                       gotoxy(54,23);cprintf("     >     ");
                       gotoxy(76,23);cprintf("     <     ");
                       gotoxy(96,23);cprintf("    <<     ");
                       gotoxy(70,14);scanf("%d",&ids);
                       chercher_chambre(ids);
                    if(nb_ch>0&&chercher_chambre(ids)==ids)

                    {

                         gotoxy(70,16);printf("%s",c2[i].type);
                         gotoxy(70,18);printf("%d",c2[i].prix);
                        for(j=i;j<=nb_ch;j++)
                         {    temp1=c2[j].id;
                              c2[j].id=c2[j+1].id;
                              c2[j+1].id=temp1;

                              strcpy(temp2,c2[j].type);
                             strcpy(c2[j].type,c2[j+1].type);
                             strcpy(c2[j+1].type,temp2);


                             temp1=c2[j].prix;
                              c2[j].prix=c2[j+1].prix;
                              c2[j+1].prix=temp1;
                          }
                          nb_ch--;
                        textcolor(1);textbackground(LIGHTGRAY);
                        gotoxy(60,20);cprintf(" la chambre est supprime");
                    }
                else
                    {
                                              textcolor(1);textbackground(LIGHTGRAY);
                                               gotoxy(54,8);cprintf("ce numero de client n'existe pas!");
                                               Sleep(800);
                                               system("cls");
                                               gestion_chambre();
                    }

return;
    }



/*fonction principale de gestion des reservation*/

void gestion_reservation( void)
      {
              system("color f0");
              menu_temp();

            textcolor(YELLOW);textbackground(LIGHTCYAN);
            gotoxy(23,6);cprintf("                                  GESTION DES RESERVATION                                 ");
            gotoxy(23,7);cprintf("                                                                                          ");
            textcolor(BLUE);textbackground(LIGHTGRAY);
            gotoxy(45,11);cprintf("   F1:          NOUVELLE RESERVATION            ");
            gotoxy(45,12);cprintf("                                                ");
            gotoxy(45,13);cprintf("   F2:          CONSULTER RESERVATION           ");
            gotoxy(45,14);cprintf("                                                ");
            gotoxy(45,15);cprintf("   F3:          MODIFIER RESERVATION            ");
            gotoxy(45,16);cprintf("                                                ");
            gotoxy(45,17);cprintf("   F4:          SUPRESSION RESERVATION          ");
            gotoxy(45,18);cprintf("                                                ");
            gotoxy(45,19);cprintf("   ESC:                 MENU                    ");
            gotoxy(45,20);cprintf("                                                ");
            textbackground(LIGHTCYAN);textcolor(YELLOW);
            gotoxy(23,26);cprintf("       F1:Nouveau    F2:Consulter      F3:Modifier     F4:Supprimer    ESC:MENU           ");
            gotoxy(23,27);cprintf("                                                                                          ");
do{
            gotoxy(23,30);
            choix1=getch();
            if(choix1==59)
               {
                 system("cls");
               }
           switch (choix1)
               {
                  case 59: Nouveau_reservations();
                         break;
                  case 60:  consulter_Reservation();
                         break;
                  case 61: modifier_reservation();
                         break;
                  case 62:supprimer_reservation();
                           break;
                  case 27: main();
                         break;
                  default:gotoxy(23,29);textcolor(RED);textbackground(LIGHTGRAY);cprintf("VOTRE CHOIX EST INCORRECT ") ;
                         break;
                }
}while(3);
return;
}

/*fonction ajouter nouvelle reservation*/

void Nouveau_reservations( void)
{
               if(num_reservation<100)
                   {
                     textcolor(BLUE);textbackground(LIGHTGRAY);
                      gotoxy(30,8);cprintf("Nouvelle Reservation :");
                      cadre_gestion_reservation();

                      gotoxy(76,10);scanf("%d",&rev[num_reservation].Numero_De_Reservation);
                     gotoxy(63,12);scanf("%s",rev[num_reservation].jour1);
                     gotoxy(75,12);scanf("%s",rev[num_reservation].mois1);
                     gotoxy(88,12);scanf("%s",rev[num_reservation].ann1);
                     gotoxy(63,14);scanf("%s",rev[num_reservation].jour2);
                     gotoxy(75,14);scanf("%s",rev[num_reservation].mois2);
                     gotoxy(88,14);scanf("%s",rev[num_reservation].ann2);
                     gotoxy(63,16);scanf("%s",rev[num_reservation].jour3);
                     gotoxy(75,16);scanf("%s",rev[num_reservation].mois3);
                     gotoxy(88,16);scanf("%s",rev[num_reservation].ann3);
                     gotoxy(75,18);scanf("%d",&rev[num_reservation].Nuit);
                     gotoxy(75,20);scanf("%d",&rev[num_reservation].Montons_avance);
                     gotoxy(75,22);scanf("%d",&rev[i].Numero_De_Client);
                     gotoxy(75,24);scanf("%s",rev[num_reservation].Type_De_Chambre);
                     num_reservation++;
        }else{
                    textcolor(RED);textbackground(LIGHTGRAY);
                    gotoxy(65,8);cprintf("Table est pleine");
             }
return;
}

/*fonction  pour consulter les reservations*/

void consulter_Reservation( void)
   {int idr;
                 if(num_reservation==0)
                   {
                    textcolor(RED);textbackground(LIGHTGRAY);
                    gotoxy(60,9);cprintf("Table est vide!!!");
                    Sleep(800);
                    gestion_reservation();
                    }
                    system("cls");
                    textcolor(BLUE);textbackground(LIGHTGRAY);
                    gotoxy(30,8);cprintf("Consulter Reservation :");
                    cadre_gestion_reservation();
                    gotoxy(75,10);scanf("%d",&idr);
                    chercher_reservation(idr);
                    if(num_reservation>0&&chercher_reservation(idr)==idr)
                    {
                     gotoxy(63,12);printf("%s",rev[i].jour1);
                     gotoxy(75,12);printf("%s",rev[i].mois1);
                     gotoxy(88,12);printf("%s",rev[i].ann1);
                     gotoxy(63,14);printf("%s",rev[i].jour2);
                     gotoxy(75,14);printf("%s",rev[i].mois2);
                     gotoxy(88,14);printf("%s",rev[i].ann2);
                     gotoxy(63,16);printf("%s",rev[i].jour3);
                     gotoxy(75,16);printf("%s",rev[i].mois3);
                     gotoxy(88,16);printf("%s",rev[i].ann3);
                     gotoxy(75,18);printf("%d",rev[i].Nuit);
                     gotoxy(75,20);printf("%d",rev[i].Montons_avance);
                     gotoxy(75,22);printf("%d",rev[i].Numero_De_Client);
                     gotoxy(75,24);printf("%s",rev[i].Type_De_Chambre);
             }
         else{
                     textcolor(RED);textbackground(LIGHTGRAY);
                     gotoxy(55,8);cprintf("Le numero de reservation n'existe pas !!!");
                     Sleep(800);
                     system("cls");
                     gestion_reservation();
              }
return;
  }


/*foction pour modifier les reservations*/

 void modifier_reservation( void)
  {int idm;
             if(num_reservation==0)
                {
                 textcolor(RED);textbackground(LIGHTGRAY);
                 gotoxy(60,9);cprintf("La table est vide!!!");
                 Sleep(800);
                 gestion_reservation();
                }
                system("cls");
                textcolor(BLUE);textbackground(LIGHTGRAY);
                gotoxy(30,8);cprintf("Modifier Reservation :");
                cadre_gestion_reservation();
                gotoxy(75,10);scanf("%d",&idm);
                chercher_reservation(idm);
            if(num_reservation>0&&chercher_reservation(idm)==idm)
               {
                 gotoxy(63,12);scanf("%s",rev[i].jour1);
                 gotoxy(75,12);scanf("%s",rev[i].mois1);
                 gotoxy(88,12);scanf("%s",rev[i].ann1);
                 gotoxy(63,14);scanf("%s",rev[i].jour2);
                 gotoxy(75,14);scanf("%s",rev[i].mois2);
                 gotoxy(88,14);scanf("%s",rev[i].ann2);
                 gotoxy(63,16);scanf("%s",rev[i].jour3);
                 gotoxy(75,16);scanf("%s",rev[i].mois3);
                 gotoxy(88,16);scanf("%s",rev[i].ann3);
                 gotoxy(75,18);scanf("%d",&rev[i].Nuit);
                 gotoxy(75,20);scanf("%d",&rev[i].Montons_avance);
                 gotoxy(75,22);scanf("%d",&rev[i].Numero_De_Client);
                 gotoxy(75,24);scanf("%s",rev[i].Type_De_Chambre);
              }
        else {
                 textcolor(RED);textbackground(LIGHTGRAY);
                 gotoxy(54,8);cprintf("Vouz pouvez pas modifier une reservation qui n'existe pas!");
                 Sleep(1000);
                 system("cls");
                 gestion_reservation();
            }
return;
  }


/*cette fonction pour supprimer les reservations*/

 void supprimer_reservation( void)
  {int k,A,ids;
   char B[15];
                 if(num_reservation==0)
                  {
                    textcolor(RED);textbackground(LIGHTGRAY);
                    gotoxy(60,9);cprintf("La table est vide!!!");
                    Sleep(800);
                    gestion_reservation();
                  }
                 system("cls");
                 textcolor(BLUE);textbackground(LIGHTGRAY);
                 gotoxy(30,8);cprintf("Supprimer Reservation :");
                 cadre_gestion_reservation();
                 gotoxy(75,10);scanf("%d",&ids);
                 chercher_reservation(ids);

              if(num_reservation>0&&chercher_reservation(ids)==ids)
               {
                gotoxy(63,12);printf("%s",rev[i].jour1);
                gotoxy(75,12);printf("%s",rev[i].mois1);
                gotoxy(88,12);printf("%s",rev[i].ann1);
                gotoxy(63,14);printf("%s",rev[i].jour2);
                gotoxy(75,14);printf("%s",rev[i].mois2);
                gotoxy(88,14);printf("%s",rev[i].ann2);
                gotoxy(63,16);printf("%s",rev[i].jour3);
                gotoxy(75,16);printf("%s",rev[i].mois3);
                gotoxy(88,16);printf("%s",rev[i].ann3);
                gotoxy(75,18);printf("%d",rev[i].Nuit);
                gotoxy(75,20);printf("%d",rev[i].Montons_avance);
                gotoxy(75,22);printf("%d",rev[i].Numero_De_Client);
                gotoxy(75,24);printf("%s",rev[i].Type_De_Chambre);
                for(k=i;k<num_reservation;k++)
                 {
                   A=rev[k].Numero_De_Reservation;
                   rev[k].Numero_De_Reservation=rev[k+1].Numero_De_Reservation;
                   rev[k+1].Numero_De_Reservation=A;

                   strcpy(B,rev[k].jour1);
                   strcpy(rev[k].jour1,rev[k+1].jour1);
                   strcpy(rev[k+1].jour1,B);

                   strcpy(B,rev[k].mois1);
                   strcpy(rev[k].mois1,rev[k+1].mois1);
                   strcpy(rev[k+1].mois1,B);

                   strcpy(B,rev[k].ann1);
                   strcpy(rev[k].ann1,rev[k+1].ann1);
                   strcpy(rev[k+1].ann1,B);

                   strcpy(B,rev[k].jour2);
                   strcpy(rev[k].jour2,rev[k+1].jour2);
                   strcpy(rev[k+1].jour2,B);

                   strcpy(B,rev[k].mois2);
                   strcpy(rev[k].mois2,rev[k+1].mois2);
                   strcpy(rev[k+1].mois2,B);

                   strcpy(B,rev[k].ann2);
                   strcpy(rev[k].ann2,rev[k+1].ann2);
                   strcpy(rev[k+1].ann2,B);

                   strcpy(B,rev[k].jour3);
                   strcpy(rev[k].jour3,rev[k+1].jour3);
                   strcpy(rev[k+1].jour3,B);

                   strcpy(B,rev[k].mois3);
                   strcpy(rev[k].mois3,rev[k+1].mois3);
                   strcpy(rev[k+1].mois3,B);

                   strcpy(B,rev[k].ann3);
                   strcpy(rev[k].ann3,rev[k+1].ann3);
                   strcpy(rev[k+1].ann3,B);



                    A=rev[k].Nuit;
                   rev[k].Nuit=rev[k+1].Nuit;
                  rev[k+1].Nuit=A;



                     A=rev[k].Montons_avance;
                   rev[k].Montons_avance=rev[k+1].Montons_avance;
                  rev[k+1].Montons_avance=A;

                   A=rev[k].Numero_De_Client;
                   rev[k].Numero_De_Client=rev[k+1].Numero_De_Client;
                   rev[k+1].Numero_De_Client=A;

                   strcpy(B,rev[k].Type_De_Chambre);
                   strcpy(rev[k].Type_De_Chambre,rev[k+1].Type_De_Chambre);
                   strcpy(rev[k+1].Type_De_Chambre,B);
                 }
                num_reservation--;
                textcolor(RED);
                gotoxy(60,8);cprintf("La reservastion est supprimer");

        }
    else{

                 textcolor(RED);
                 gotoxy(54,8);cprintf("Vouz pouvez pas supprimer une reservation qui n'existe pas!");
                 Sleep(1000);
                 system("cls");
                 gestion_reservation();
                 }
return;
}


/*cadre de gestion des reservations*/

  void cadre_gestion_reservation( void)
    {
                      for(j=0;j<=89;j++)
                            {
                                gotoxy(23+j,5);printf("\304");
                            }
                      gotoxy(22,5);printf("\332");
                      for(j=0;j<=21;j++)
                            {
                              gotoxy(22,6+j);printf("\263");
                            }
                      gotoxy(22,28);printf("\300");
                      for(j=0;j<=89;j++)
                            {
                              gotoxy(23+j,28);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=21;j++)
                            {
                              gotoxy(113,27-j);printf("\263");
                            }
                      gotoxy(113,5);printf("\277");

                      textcolor(BLACK);textbackground(LIGHTGRAY);
                      gotoxy(23,6);cprintf("                                  GESTION DE RESERVATION                                  ");
                      gotoxy(23,7);cprintf("                                                                                          ");
                      gotoxy(33,10);
                      printf("Numero De reservation    :..........................................");
                      gotoxy(33,12);printf("Date de Reservation      :........../............../................");
                      gotoxy(33,14);printf("Debut de sejour          :........../............../................");
                      gotoxy(33,16);printf("Fin de sejour            :........../............../................");
                      gotoxy(33,18);printf("Nombre de nuit           :..........................................");
                      gotoxy(33,20);printf("Montant avance           :..........................................");
                      gotoxy(33,22);printf("Numero de Client         :..........................................");
                      gotoxy(33,24);printf("Type de Chambre          :..........................................");
                      textbackground(LIGHTGRAY);textcolor(BLACK);
                      gotoxy(23,26);cprintf("       F1:Nouveau    F2:Consulter      F3:Modifier     F4:Supprimer    ESC:MENU           ");
                      gotoxy(23,27);cprintf("                                                                                          ");
   return;
    }

/*cette fonction pour chercher dans les reservations*/

 int chercher_reservation(int x)
     {int a,b;
                     for(i=0;i<num_reservation;i++)
                      {
                         if(x==rev[i].Numero_De_Reservation)
                          {
                             a=x;
                             b=i;
                             i=num_reservation+1;
                         }else{
                                 a=-1;
                              }
                      }
                         i=b;
return a;
     }


void menu_temp(void)
     {
          system("cls");
              for(j=0;j<=89;j++)
                    {
                      gotoxy(23+j,5);printf("\304");
                    }
             gotoxy(22,5);printf("\332");
              for(j=0;j<=21;j++)
                    {
                      gotoxy(22,6+j);printf("\263");
                    }
             gotoxy(22,28);printf("\300");
             for(j=0;j<=89;j++)
                    {
                      gotoxy(23+j,28);printf("\304");
                    }
             printf("\331");
             for(j=0;j<=21;j++)
                    {
                       gotoxy(113,27-j);printf("\263");
                    }
                       gotoxy(113,5);printf("\277");
    return;
     }

/*menu de gestion d'etats*/
     void menu_etat(void)
    {        system("cls");
             system("color f0");
             textbackground(BLUE);
             textcolor(YELLOW);
             gotoxy(40,7);cprintf("                                         ");
             gotoxy(40,8);cprintf("          GENERATION D'ETATS             ");
             gotoxy(40,9);cprintf("                                         ");

            textbackground(GREEN);
            gotoxy(40,12);cprintf("                                         ");
            gotoxy(40,13);cprintf("          RESERVATION EN COURS           ");
            gotoxy(40,14);cprintf("                                         ");

            textbackground(BLUE);
            gotoxy(40,15);cprintf("                                         ");
            gotoxy(40,16);cprintf("           FACTURE                       ");

            gotoxy(40,17);cprintf("                                         ");
            gotoxy(40,18);cprintf("           QUITTER                       ");
            gotoxy(40,19);cprintf("                                         ");
return;
    }


/*fonction principale gestion d'etats*/

void gestion_etat(void)
    {

do{

do{
              system("cls");
              menu_etat();
             gotoxy(40,21);printf("Donner votre choix (1-3):   ");
             choix=getch();
         }while(choix!='1' && choix!='2' && choix!='3');

         switch(choix)
            {
            case '1': reservations_encours();
                     break;
            case '2':facture() ;
                     break;
            case '3':main();
                     break;
            }

    }while(7);

return;
    }

/*fonction qui affiche le tableau les reservations en cours*/

void reservations_encours(void)
        {int k;
            system("cls");

             for(j=0;j<=117;j++)
                            {
                                gotoxy(2+j,4);printf("\304");
                            }
                             for(j=0;j<=118;j++)
                               {
                                gotoxy(1+j,6);printf("\304");
                              }
                       gotoxy(1,4);
                       printf("\332");
                           for(j=0;j<=5+num_reservation;j++)
                            {
                              gotoxy(1,5+j);printf("\263");
                            }
                         gotoxy(1,5+j);
                       printf("\300");
                       k=j;
                     for(j=0;j<=117;j++)
                            {
                                gotoxy(2+j,5+k);printf("\304");
                            }

                        printf("\331");
                        for(j=0;j<=5+num_reservation;j++)
                            {
                              gotoxy(120,10+num_reservation-j);printf("\263");
                            }
                       gotoxy(120,10+num_reservation-j);printf("\277");
              textcolor(0);textbackground(LIGHTGRAY);
            gotoxy(7,5);cprintf("Res numero");
            gotoxy(27,5);cprintf("NOM");
            gotoxy(47,5);cprintf("Arrivee");
            gotoxy(67,5);cprintf("Depat");
           gotoxy(87,5);cprintf("Chambre");
            gotoxy(107,5);cprintf("Type");


          for(i=0;i<num_reservation;i++)
              {
                gotoxy(7,8+i);
                printf("%d",rev[i].Numero_De_Reservation);
                gotoxy(26,8+i);
                printf("%s",c1[i].nom);
                gotoxy(47,8+i);
                printf("%s/%s/%s",rev[i].jour2,rev[i].mois2,rev[i].ann2);
                gotoxy(67,8+i);
                printf("%s/%s/%s",rev[i].jour3,rev[i].mois3,rev[i].ann3);
                gotoxy(90,8+i);printf("%d",&c2[nb_ch].id);
                gotoxy(107,8+i);printf("%s",rev[i].Type_De_Chambre);
                }
                gotoxy(2,12+i);
                system("pause");


return;
        }





void table_consuler_facture_reservation(void)
      {int k;

        system("cls");
                         for(j=0;j<=70;j++)
                            {
                                gotoxy(25+j,4);printf("\304");
                            }
                             for(j=0;j<=70;j++)
                               {
                                gotoxy(25+j,6);printf("\304");
                              }
                       gotoxy(24,4);
                       printf("\332");
                           for(j=0;j<=5+num_reservation;j++)
                            {
                              gotoxy(24,5+j);printf("\263");
                            }
                         gotoxy(24,4+j);printf("\300");
                       k=j;
                     for(j=0;j<=70;j++)
                            {
                                gotoxy(25+j,4+k);printf("\304");
                            }

                        printf("\331");
                        for(j=0;j<=4+num_reservation;j++)
                            {
                              gotoxy(96,9+num_reservation-j);printf("\263");
                            }
                       gotoxy(96,9+num_reservation-j);printf("\277");
            textcolor(0);textbackground(LIGHTGRAY);
           gotoxy(27,5);cprintf("NOM");
           gotoxy(55,5);cprintf("CIN");
           gotoxy(78,5);cprintf("Res numero");



          for(i=0;i<num_reservation;i++)
              {
                 gotoxy(27,8+i);printf("%s %s" ,c1[i].nom,c1[i].prenom);
                 gotoxy(55,8+i);printf("%s",c1[i].CIN);
                 gotoxy(78,8+i);printf("%d",rev[i].Numero_De_Reservation);
              }


    return 0;
}

/*fonctuin qui cherche le numero de reservation pour afficher la facture*/
int chercher_numero_reservation(int x )
     {int temp1,temp2;

                          for(i=0;i<num_reservation;i++)
                             {
                                   if(x==rev[i].Numero_De_Reservation)
                                       {
                                           temp1=x;temp2=i;i=nombre_elements+1;
                                       }else
                                       {
                                          temp1=-1;
                                        }
                            }
                            i=temp2;
    return temp1;
     }
/*fonction qui affiche en tete de la facture*/
     void cadre_facture(void)
    {
                      for(j=0;j<=89;j++)
                            {
                                gotoxy(23+j,5);printf("\304");
                            }
                      gotoxy(22,5);printf("\332");
                      for(j=0;j<=21;j++)
                            {
                              gotoxy(22,6+j);printf("\263");
                            }
                      gotoxy(22,28);printf("\300");
                      for(j=0;j<=89;j++)
                            {
                              gotoxy(23+j,28);printf("\304");
                            }
                      printf("\331");
                       for(j=0;j<=21;j++)
                            {
                              gotoxy(113,27-j);printf("\263");
                            }
                      gotoxy(113,5);printf("\277");

                      textcolor(BLACK);textbackground(LIGHTGRAY);
                      gotoxy(23,6);cprintf("                                       FACTURE                                            ");
                      gotoxy(23,7);cprintf("                                                                                          ");
                      gotoxy(33,10);printf("Facture n      :....................");
                      gotoxy(33,12);printf("Date d'edition :........................");
                      gotoxy(33,14);printf("Nom du client  :...........................");
                      gotoxy(33,16);printf("Periode    Du  :....../....../......  Au  :....../....../.......");
                      gotoxy(33,18);printf("Duree          : ............ jour(s)");
                      gotoxy(33,20);printf("Montant avance : ............ DH TTC");
                      gotoxy(33,22);printf("Montant a payer: ............ DH TTC");

   return;
    }



/*facture fonction qui affiche la facture*/
    void facture(void)
    {
        int temp;
        float a;
        time_t t=time(NULL);


                 table_consuler_facture_reservation();
                gotoxy(25,11+i);
                printf("donner le numero de reservation :");
                scanf("%d",&temp);
                 system("cls");


                cadre_facture();
                chercher_numero_reservation(temp);
                if(chercher_numero_reservation(temp)==temp)
                {
                     gotoxy(55,10);printf("%d",num_reservation);
                     gotoxy(49,12);printf("%s",asctime(localtime(&t)));
                     gotoxy(55,14);printf("%s",c1[i].nom);
                     gotoxy(50,16);printf("%s",rev[i].jour2);
                     gotoxy(56,16);printf("%s",rev[i].mois2);
                     gotoxy(65,16);printf("%s",rev[i].ann2);
                     gotoxy(77,16);printf("%s",rev[i].jour3);
                     gotoxy(85,16);printf("%s",rev[i].mois3);
                     gotoxy(93,16);printf("%s",rev[i].ann3);
                     gotoxy(56,18);printf("%d",rev[i].Nuit);
                     gotoxy(56,20);printf("%d",rev[i].Montons_avance);
                     a=(float)c2[i].prix*rev[i].Nuit*1.2-rev[i].Montons_avance;

                     gotoxy(56,22);printf("%.2f",a);
                }
                else
                 {
                    gotoxy(48,9);
                     textcolor(YELLOW);textbackground(LIGHTCYAN);
                    cprintf("ce numero de reservation n'existe pas");
                 }

                     gotoxy(48,25);system("pause");

     return;
    }

