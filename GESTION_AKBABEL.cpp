#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<graphics.h>

#include<windows.h>

#include <time.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

//========================Structures principales ========================
typedef struct medcin {
  char cnem[9];
  char nom[10];
  char prenom[10];
  char sex[2];
  char specialisation[15];
  long int numtele;
  struct medcin * suivant;
}
medcin;

typedef struct consultation {
  int numconsult;
  char cnep[9];
  char cnem[9];
  int jour;
  int mois;
  int annee;
  int heur;
  int min;
  struct consultation * suivant;
}
consultation;

typedef struct patient {
  char cnep[9];
  char nom[10];
  char prenom[10];
  char sex[2];
  long int tele;
  int jour;
  int mois;
  int annee;
  struct patient * suivant;
}
patient;

//=============structure pour le fonctionement de gotoxy==============
COORD coord = {
  0,
  0
};
void gotoxy(int x, int y) {
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//====LES PROTOTYPE DES FONCTIONs GERER=====//

patient * initialiserp(patient * listp);
patient * ajouter_entetep(patient * listp);
patient * ajoutEnfinp(patient * listp);
void affichagep(patient * listp);
void recherchercnep(patient * listp);
void recherchernomp(patient * listp);
int rechercherAjoup(patient * listp, char n[]);
patient * suppRp(patient * listp, char cnep[9]);
patient * modifierp(patient * listp);
void enregistrerp(patient * print);
patient * chargerp(patient * p);
patient * chargehelpp(patient * list, char cne[], char nom[], char prenom[], int tele, char sex[], int jour, int mois, int annee);
void initialiserfichierp();
consultation * initialiserc(consultation * c);
int rechercherAjouc(consultation * c, int n);
consultation * ajouter_entetec(consultation * listc);
consultation * ajouter_enfinc(consultation * listc);
void affichagec(consultation * c);
consultation * suppRc(consultation * listc);
void rechercher_consultation(consultation * listc);
consultation * modifierc(consultation * listc, patient * p, medcin * m);
void enregistrerc(consultation * print);
consultation * chargerhelpc(consultation * c, int num, char cnep[], char cnem[], int annee, int mois, int jour, int heur, int min);
consultation * chargerc(consultation * c);
void initialiserfichierc();
medcin * initialiserm(medcin * l);
int rechercherAjoum(medcin * list, char n[]);
medcin * ajouter_entetem(medcin * list);
medcin * ajoutEnfinm(medcin * list);
void affichagem(medcin * list);
medcin * modifierm(medcin * list);
void recherchercnem(medcin * list);
void recherchernomm(medcin * list);
medcin * suppRm(medcin * list);
void enregistrerm(medcin * print);
medcin * chargerm(medcin * m);
medcin * chargehelpm(medcin * list, char cne[], char nom[], char prenom[], int tele, char sex[], char spec[]);
void initialiserfichierm();
//====LE PROTOTYPE LOGIN=====//
void login(char user[], int theme);
void changepass(char user[], int theme);
//====LES PROTOTYPE MENU=====//

//=============================================
//==================prototypes de fonctions d'affichage====================
//============================================
void drawRectangle();
void Chargement();
void printMsg();
void nothing();
void clearS();
void display();
void ClearConsoleToColors(int ForgC, int BackC);
void SetColorAndBackground(int ForgC, int BackC);
void drawRectanglelogin();
void print(const char st[]);
int mode_switch();
//=========================================
void MENUPRI(char user[], int theme);
//=========================================

//===================================================fonctions patient==================///

patient * initialiserp(patient * l) {
  l = NULL;
  return l;
}
// ==============================================  //

patient * ajouter_entetep(patient * list) {
  patient * nv = (patient * ) malloc(sizeof(patient));
  patient * tst = list;
  int j, ms, an;

  gotoxy(38, 10);
  printf("Entrez le CNE de ce patient :\t ");
  scanf("%s", & nv -> cnep);
  while (tst != NULL) {
    if ((strcmp(tst -> cnep, nv -> cnep)) == 0) {
      gotoxy(38, 12);
      printf("Ce patient existe d%cja dans la liste", 130);
      return list;
    } else
      tst = tst -> suivant;
  }
  gotoxy(38, 11);
  printf("Nom                      :    ");
  gotoxy(38, 12);
  printf("Pr%cnom                   :    ", 130);
  gotoxy(38, 13);
  printf("t%cl%c                     :    ", 130, 130);
  gotoxy(38, 14);
  printf("sex                      :    ");
  gotoxy(38, 15);
  printf("entrez la date naissance :    ");

  gotoxy(65, 11);
  scanf("%s", nv -> nom);
  gotoxy(65, 12);
  scanf("%s", nv -> prenom);
  gotoxy(65, 13);
  scanf("%d", & nv -> tele);
  gotoxy(65, 14);
  scanf("%s", nv -> sex);

  jr: gotoxy(42, 16);
  printf("jour:");
  scanf("%d", & j);
  if (j > 31) {
    gotoxy(54, 16);
    printf("incorrect!!!");
    gotoxy(47, 16);
    printf("      ");
    Sleep(333);
    gotoxy(54, 16);
    printf("              ");
    goto jr;
  }
  nv -> jour = j;

  ms: gotoxy(42, 17);
  printf("mois:");
  scanf("%d", & ms);
  if (ms > 12) {
    gotoxy(54, 17);
    printf("incorrect!!!");
    gotoxy(47, 17);
    printf("      ");
    Sleep(333);
    gotoxy(54, 17);
    printf("              ");
    goto ms;
  }
  nv -> mois = ms;

  ane: gotoxy(42, 18);
  printf("ann%ce:", 130);
  scanf("%d", & an); //code ascii ÃƒÆ’Ã‚Â©
  if (an > 9999 && an < 1000) {
    gotoxy(54, 18);
    printf("incorrect!!!");
    gotoxy(47, 18);
    printf("      ");
    Sleep(333);
    gotoxy(54, 18);
    printf("              ");
    goto ane;
  }
  nv -> annee = an;
  nv -> suivant = list;
  return nv;
}

// ==============================================  //
patient * ajoutEnfinp(patient * list) {
  patient * nv = (patient * ) malloc(sizeof(patient));
  patient * tst = list;
  int j, ms, an;

  gotoxy(38, 10);
  printf("Entrer le CNE de ce patient\t ");
  scanf("%s", & nv -> cnep);
  while (tst != NULL) {
    if ((strcmp(tst -> cnep, nv -> cnep)) == 0) {
      gotoxy(38, 12);
      printf("Ce patient existe d%cja dans la liste", 130);
      return list;
    } else
      tst = tst -> suivant;
  }
  gotoxy(38, 11);
  printf("Nom                      :    ");
  gotoxy(38, 12);
  printf("Pr%cnom                   :    ", 130);
  gotoxy(38, 13);
  printf("t%cl%c                     :    ", 130, 130);
  gotoxy(38, 14);
  printf("sex                      :    ");
  gotoxy(38, 15);
  printf("entrez la date naissance :    ");

  gotoxy(65, 11);
  scanf("%s", nv -> nom);
  gotoxy(65, 12);
  scanf("%s", nv -> prenom);
  gotoxy(65, 13);
  scanf("%d", & nv -> tele);
  gotoxy(65, 14);
  scanf("%s", nv -> sex);

  jr1: gotoxy(42, 16);
  printf("jour:\t");
  scanf("%d", & j);
  if (j > 31) {
    gotoxy(54, 16);
    printf("incorrect!!!");
    gotoxy(47, 16);
    printf("    ");
    Sleep(333);
    gotoxy(54, 16);
    printf("              ");
    goto jr1;
  }
  nv -> jour = j;
  ms1: gotoxy(42, 17);
  printf("mois:\t");
  scanf("%d", & ms);
  if (ms > 12) {
    gotoxy(54, 17);
    printf("incorrect!!!");
    gotoxy(47, 17);
    printf("    ");
    Sleep(333);
    gotoxy(54, 17);
    printf("              ");
    goto ms1;
  }
  nv -> mois = ms;
  ane1: gotoxy(42, 18);
  printf("ann%ce:", 130);
  scanf("%d", & an); //code ascii ÃƒÆ’Ã‚Â©
  if (an > 9999 && an < 1000) {
    gotoxy(54, 18);
    printf("incorrect!!!");
    gotoxy(47, 18);
    printf("    ");
    Sleep(333);
    gotoxy(54, 18);
    printf("              ");
    goto ane1;
  }
  nv -> annee = an;

  nv -> suivant = NULL;
  if (list == NULL) return nv;
  else
    tst = list;
  while (tst -> suivant != NULL) tst = tst -> suivant;
  tst -> suivant = nv;

  return tst;
}

// ==============================================  //
void affichagep(patient * list) {
  patient * tmp = list;
  int c = 1, i = 1;
  int x = 38;
  int y = 15;
  int choix;

  if (list == NULL) {
    gotoxy(38, 14);
    printf("la liste est vide!!");
    return;
  }
  gotoxy(38, 12);
  printf("affichage de liste ");
  ri: while (tmp != NULL) {
    gotoxy(x, 15);
    printf(" PATIENT %d ", i);
    gotoxy(x, 16);
    printf("CNE    :%5s     ", tmp -> cnep);
    gotoxy(x, 17);
    printf("Nom    :%5s     ", tmp -> nom);
    gotoxy(x, 18);
    printf("Pr%cnom :%5s     ", 130, tmp -> prenom);
    gotoxy(x, 19);
    printf("Sex    :%5s     ", tmp -> sex);
    gotoxy(x, 20);
    printf("T%cl%C   :%5d     ", 130, 130, tmp -> tele);
    gotoxy(x, 21);
    printf("DateNaiss : %d/%d/%d    ", tmp -> jour, tmp -> mois, tmp -> annee);

    ask: gotoxy(38, 23);
    printf("Voulez vous afficher le patient suivant (Y/N):  ");
    choix = _getch();
    if (choix == 'Y' || choix == 'y') {
      tmp = tmp -> suivant;
      i++;
      clearS();
      goto ri;
    }
    if (choix == 'N' || choix == 'n') {
      return;
    } else {
      gotoxy(38, 24);
      printf("Choix invalide !!");
      Sleep(666);
      clearS();
      goto ask;
    }
  }
}
// ==============================================  //
void recherchercnep(patient * list) {
  char cne[9];
  patient * tmp = list;
  int i = 1;
  int x = 38;
  int y = 15;

  gotoxy(38, 10);
  printf("Entrez le CNE du patient");
  scanf("%s", cne);
  while (tmp != NULL) {
    if (strcmp(tmp -> cnep, cne) == 0) {
      gotoxy(46, 12);
      printf("La valeur existe");
      gotoxy(x, y);
      printf(" PATIENT %d ", i);
      y++;
      gotoxy(x, y);
      printf("CNE    :%5s     ", tmp -> cnep);
      y++;
      gotoxy(x, y);
      printf("Nom    :%5s     ", tmp -> nom);
      y++;
      gotoxy(x, y);
      printf("Pr%cnom :%5s     ", 130, tmp -> prenom);
      y++;
      gotoxy(x, y);
      printf("Sex    :%5s     ", tmp -> sex);
      y++;
      gotoxy(x, y);
      printf("T%cl%c   :%5d     ", 130, 130, tmp -> tele);
      y++;
      gotoxy(x, y);
      printf("DateNaiss : %3d/%3d/%4d    ", tmp -> jour, tmp -> mois, tmp -> annee);
      y = y + 2;
      gotoxy(x, 24);
      return;
    }
    tmp = tmp -> suivant;
  }
  gotoxy(46, 12);
  printf("Le patient n'existe pas ");
}

// ==============================================  //
void recherchernomp(patient * list) {
  char nom[15];
  patient * tmp = list;
  int x = 38;
  int y = 15;
  int i = 1;
  int k = 0;
  gotoxy(38, 10);
  printf(" entrez le nom a recherch%c\t", 130);
  scanf("%s", nom);
  while (tmp != NULL) {
    if (strcmp(tmp -> nom, nom) == 0) {
      gotoxy(x, y);
      printf(" PATIENT  ");
      y++;
      gotoxy(x, y);
      printf("CNE    :%5s     ", tmp -> cnep);
      y++;
      gotoxy(x, y);
      printf("Nom    :%5s     ", tmp -> nom);
      y++;
      gotoxy(x, y);
      printf("Pr%cnom :%5s     ", 130, tmp -> prenom);
      y++;
      gotoxy(x, y);
      printf("Sex    :%5s     ", tmp -> sex);
      y++;
      gotoxy(x, y);
      printf("T%cl%c   :%5d     ", 130, 130, tmp -> tele);
      y++;
      gotoxy(x, y);
      printf("DateNaiss : %3d/%3d/%4d    ", tmp -> jour, tmp -> mois, tmp -> annee);
      y = y + 2;
      gotoxy(36, y);
      printf("cliquez n'importe o%c pour afficher le patient suivant", 151);
      _getch();
      clearS();
      y = y - 8;
      tmp = tmp -> suivant;
    } else
      tmp = tmp -> suivant;
  }
  gotoxy(46, 12);
  printf("aucun autre patient n'existe avec ce nom ");
}

// ==============================================  //
int rechercherAjoup(patient * list, char n[]) {
  patient * tmp = list;
  while (tmp != NULL) {
    if (strcmp(tmp -> cnep, n) == 0) {
      return 1;
    }
    tmp = tmp -> suivant;
  }
  return -1;
}

// ==============================================  //
patient * suppRp(patient * list, char cnep[9]) {
  patient * n, * prec;
  if (list == NULL) {
    gotoxy(38, 13);
    printf("la liste est vide!");
    return NULL;
  }
  if (list -> suivant == NULL && strcmp(list -> cnep, cnep) == 0) {
    gotoxy(38, 15);
    printf("la liste ne contient que ce patient ");
    gotoxy(38, 17);
    printf("le patient est supprim%c", 130);
    return NULL;
  } else {
    if (strcmp(list -> cnep, cnep) == 0) {
      n = list;
      list = list -> suivant;
      free(n);
      gotoxy(38, 17);
      printf("le patient est supprim%c", 130);
      return list;
    }

    prec = list;
    n = list -> suivant;
    while (n != NULL) {
      if (strcmp(n -> cnep, cnep) == 0) {
        prec -> suivant = n -> suivant;
        free(n);
        gotoxy(38, 17);
        printf("le patient est supprim%c", 130);
        return prec;
      }
      prec = n;
      n = n -> suivant;
    }
  }
  gotoxy(38, 18);
  printf("le patient n'est pas trouv%c", 130);
  return list;
}

// ==============================================  //

patient * modifierp(patient * p) {
  int num, num2;
  patient * tmp1, * tmp2, * print = p;
  char cnep[9], n[9];
  int rp, rm, j, ms, an, k = 0, d;
  patient * nv = (patient * ) malloc(sizeof(patient));
  gotoxy(38, 11);
  printf("entrez le CNE de la patient a modifi%c  ", 130);
  scanf("%s", cnep);

  if (p == NULL) {
    gotoxy(38, 12);
    printf("la liste est vide");
    return NULL;
  }
  d = rechercherAjoup(p, cnep);
  if (d == 1) {

    if (strcmp(print -> cnep, cnep) == 0) {
      tmp2 = print -> suivant;
      free(print);
      k++;
      goto red;
    }

    while (print != NULL) {
      if (strcmp(print -> suivant -> cnep, cnep) == 0) {
        tmp1 = print;
        tmp2 = print -> suivant -> suivant;
        free(print -> suivant);
        red: Sleep(100);
        clearS();
        gotoxy(38, 11);
        printf("entrez le nouveau cne ");
        scanf("%s", n);
        num = rechercherAjoup(p, n);
        if (num == 1) {
          gotoxy(38, 12);
          printf("le CNE d%cja existe !!!", 130);
          Sleep(200);
          goto red;
        }
        strcpy(nv -> cnep, n);
        gotoxy(38, 12);
        printf("Nom :    ");
        scanf("%s", nv -> nom);
        gotoxy(38, 13);
        printf("Pr%cnom :    ", 130);
        scanf("%s", nv -> prenom);
        gotoxy(38, 14);
        printf("t%cl%c  :    ", 130, 130);
        scanf("%d", & nv -> tele);
        gotoxy(38, 15);
        printf("sex :    ");
        scanf("%s", nv -> sex);
        gotoxy(38, 16);
        printf("  entrez la date naissance :    ");
        jr: gotoxy(38, 17);
        printf("jour:");
        scanf("%d", & j);
        if (j > 31) {
          gotoxy(38, 18);
          printf("incorrect!!!");
          Sleep(200);
          clearS();
          goto jr;
        }
        nv -> jour = j;
        ms: gotoxy(38, 18);
        printf("mois:");
        scanf("%d", & ms);
        if (ms > 12) {
          gotoxy(38, 19);
          printf("incorrect!!!");
          Sleep(200);
          clearS();
          goto ms;
        }
        nv -> mois = ms;
        ane: gotoxy(38, 19);
        printf("ann%ce:\t", 130);
        scanf("%d", & an);
        if (j > 9999) {
          gotoxy(38, 20);
          printf("incorrect!!!");
          Sleep(200);
          clearS();
          goto ane;
        }
        nv -> annee = an;
        nv -> suivant = tmp2;
        if (k == 1) {
          return nv;
        }

        tmp1 = nv;
        return tmp1;
      }
      print = print -> suivant;
    }
  }
  if (d != 1) {
    gotoxy(38, 13);
    printf("ce CNE n'est pas trouv%c", 130);
    return p;
  }

}
// ==============================================  //

void enregistrerp(patient * print) {
  char en[] = "fpatient.txt";
  FILE * fichier = fopen(en, "a");
  while (print != NULL) {
    fprintf(fichier, "%s\n", print -> cnep);
    fprintf(fichier, "%s\n", print -> nom);
    fprintf(fichier, "%s\n", print -> prenom);
    fprintf(fichier, "%d\n", print -> tele);
    fprintf(fichier, "%s\n", print -> sex);
    fprintf(fichier, "%d\n%d\n%d\n", print -> jour, print -> mois, print -> annee);
    print = print -> suivant;
  }
  fclose(fichier);
}
// ==============================================  //
patient * chargerp(patient * p) {
  patient * list = p;
  //  patient *tst=list;

  char en[] = "fpatient.txt";
  FILE * fichier = fopen(en, "r+");
  if ((fopen(en, "r")) == NULL) {
    gotoxy(52, 15);
    printf("Fichier ne pas trouv%c !!", 130);
    return list;
  }

  while (!feof(fichier)) {
    patient * nw = (patient * ) malloc(sizeof(patient));

    fscanf(fichier, "%s\n%s\n%s\n%d\n%s\n%d\n%d\n%d\n", nw -> cnep, nw -> nom, nw -> prenom, & nw -> tele, nw -> sex, & nw -> jour, & nw -> mois, & nw -> annee);
    // while(list->suivant!=NULL)	list=list->suivant;
    list = chargehelpp(list, nw -> cnep, nw -> nom, nw -> prenom, nw -> tele, nw -> sex, nw -> jour, nw -> mois, nw -> annee);
  }
  fclose(fichier);
  gotoxy(52, 15);
  printf("liste charg%ce (^-^)", 130);
  return list;
}
//=====================================================//
patient * chargehelpp(patient * list, char cne[], char nom[], char prenom[], int tele, char sex[], int jour, int mois, int annee) {
  patient * nv = (patient * ) malloc(sizeof(patient));
  patient * tst = list;
  while (tst != NULL) {
    if ((strcmp(tst -> cnep, cne)) == 0) {
      return list;
    } else
      tst = tst -> suivant;
  }
  strcpy(nv -> cnep, cne);
  strcpy(nv -> nom, nom);
  strcpy(nv -> prenom, prenom);
  nv -> tele = tele;
  strcpy(nv -> sex, sex);
  nv -> jour = jour;
  nv -> mois = mois;
  nv -> annee = annee;

  if (list == NULL) {
    nv -> suivant = NULL;
    return nv;
  } else {
    nv -> suivant = list;
    return nv;
  }
}
//=====================================================//

void initialiserfichierp() {
  char en[] = "fpatient.txt";
  int d = remove(en);
  if (d == 0) {
    gotoxy(52, 15);
    printf("liste initialis%ce(^-^)", 130);
  } else {

    gotoxy(49, 16);
    printf("Echec lors initialisation !");
    gotoxy(49, 17);
  }
}

// ==============================================  //
///fonction consultation///
// ==============================================  // 
// ==============================================  //
consultation * initialiserc(consultation * c) {
  c = NULL;
  return c;
}

// ==============================================  //
int rechercherAjouc(consultation * c, int n) {
  consultation * tmp = c;
  while (tmp != NULL) {
    if (tmp -> numconsult == n) {
      return 1;
    }
    tmp = tmp -> suivant;
  }
  return -1;
}
//============================================================
int rechercherAjoum(medcin * list, char n[]) {
  medcin * tmp = list;
  while (tmp != NULL) {
    if (strcmp(tmp -> cnem, n) == 0) {
      return 1;
    }
    tmp = tmp -> suivant;
  }
  return -1;
}
// ==============================================  //
consultation * ajouter_entetec(consultation * listc, patient * listp, medcin * listm) {
  char cnep[9], cnem[9];
  int rp, rm, j, ms, an, h, min, num, numt;
  consultation * nv = (consultation * ) malloc(sizeof(consultation));
  consultation * tst = listc;
  red: gotoxy(38, 10);
  printf("entrez le num du consultation  :  ");
  scanf("%d", & num);
  numt = rechercherAjouc(listc, num);
  if (numt == 1) {
    gotoxy(38, 12);
    printf("le num existe d%cja !!!", 130);
    Sleep(333);
    gotoxy(38, 12);
    printf("                           ");
    goto red;
  }
  nv -> numconsult = num;
  red1: gotoxy(38, 11);
  printf("entrez le cne du patient  :  ");
  scanf("%s", cnep);
  rp = rechercherAjoup(listp, cnep);
  if (rp != 1) {
    gotoxy(38, 13);
    printf("le cne n'existe pas dans la liste");
    Sleep(333);
    gotoxy(38, 13);
    printf("                                           ");
    goto red1;
  }
  strcpy(nv -> cnep, cnep);
  red2: gotoxy(38, 12);
  printf("entrez le cne du medcin  :  ");
  scanf("%s", cnem);
  rm = rechercherAjoum(listm, cnem);
  if (rm != 1) {
    gotoxy(38, 14);
    printf("le cne n'existe pas dans la liste");
    Sleep(333);
    gotoxy(38, 14);
    printf("                                           ");
    goto red2;
  }
  strcpy(nv -> cnem, cnem);
  gotoxy(38, 13);
  printf("la date du consultation : ");
  jr: gotoxy(38, 14);
  printf("jour:\t");
  scanf("%d", & j);
  if (j > 31) {
    gotoxy(38, 15);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 15);
    printf("               ");
    gotoxy(38, 14);
    printf("     		");
    goto jr;
  }
  nv -> jour = j;
  ms: gotoxy(38, 15);
  printf("mois:\t");
  scanf("%d", & ms);
  if (ms > 12) {
    gotoxy(38, 16);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 16);
    printf("               ");
    gotoxy(38, 15);
    printf("     		");
    goto ms;
  }
  nv -> mois = ms;
  ane: gotoxy(38, 16);
  printf("ann%ce:\t", 130);
  scanf("%d", & an);
  if (j > 9999) {
    gotoxy(38, 17);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 17);
    printf("               ");
    gotoxy(38, 16);
    printf("  		   		");
    goto ane;
  }
  nv -> annee = an;
  he: gotoxy(38, 17);
  printf("heure:\t");
  scanf("%d", & h);
  if (h > 23) {
    gotoxy(38, 18);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 18);
    printf("               ");
    gotoxy(38, 17);
    printf("   		  		");
    goto he;
  }
  nv -> heur = h;
  mi: gotoxy(38, 18);
  printf("minutes:\t");
  scanf("%d", & min);
  if (min > 59) {
    gotoxy(38, 19);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 19);
    printf("               ");
    gotoxy(38, 18);
    printf("   		  		");
    goto mi;
  }
  nv -> min = min;
  nv -> suivant = listc;
  return nv;

}

// ==============================================  //
consultation * ajouter_enfinc(consultation * listc, patient * listp, medcin * listm) {
  char cnep[9], cnem[9];
  int rp, rm, j, ms, an, h, min, num, num1, num2;
  consultation * nv = (consultation * ) malloc(sizeof(consultation));
  consultation * tst = listc;
  red: gotoxy(38, 10);
  printf("entrez le num du consultation :  ");
  scanf("%d", & num);
  num1 = rechercherAjouc(listc, num);
  if (num1 == 1) {
    gotoxy(38, 12);
    printf("le num existe d%cja !!!", 130);
    Sleep(333);
    gotoxy(38, 12);
    printf("                                           ");
    goto red;
  }
  nv -> numconsult = num;
  red1: gotoxy(38, 11);
  printf("entrez le cne de patient :\t");
  scanf("%s", cnep);
  rp = rechercherAjoup(listp, cnep);
  if (rp != 1) {
    gotoxy(38, 13);
    printf("le cne n'existe pas dans la liste");
    Sleep(333);
    gotoxy(38, 13);
    printf("                                           ");
    goto red1;
  }
  strcpy(nv -> cnep, cnep);
  red2: gotoxy(38, 12);
  printf("entrez le cne de medcin :\t ");
  scanf("%s", cnem);
  rm = rechercherAjoum(listm, cnem);
  if (rm != 1) {
    gotoxy(38, 14);
    printf("le cne n'existe pas dans la liste");
    Sleep(333);
    gotoxy(38, 14);
    printf("                                           ");
    goto red2;
  }
  strcpy(nv -> cnem, cnem);
  gotoxy(38, 13);
  printf("la date du consultation :");
  jr: gotoxy(38, 14);
  printf("jour:\t");
  scanf("%d", & j);
  if (j > 31) {
    gotoxy(38, 15);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 15);
    printf("               ");
    gotoxy(38, 14);
    printf("     		");
    goto jr;
  }
  nv -> jour = j;
  ms: gotoxy(38, 15);
  printf("mois:\t");
  scanf("%d", & ms);
  if (ms > 12) {
    gotoxy(38, 16);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 16);
    printf("               ");
    gotoxy(38, 15);
    printf("     		");
    goto ms;
  }
  nv -> mois = ms;
  ane: gotoxy(38, 16);
  printf("ann%ce:\t", 130);
  scanf("%d", & an);
  if (j > 9999) {
    gotoxy(38, 17);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 17);
    printf("               ");
    gotoxy(38, 16);
    printf("     		");
    goto ane;
  }
  nv -> annee = an;
  he: gotoxy(38, 17);
  printf("heure:\t");
  scanf("%d", & h);
  if (h > 23) {
    gotoxy(38, 18);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 18);
    printf("               ");
    gotoxy(38, 17);
    printf("     		");
    goto he;
  }
  nv -> heur = h;
  mi: gotoxy(38, 18);
  printf("minutes:\t");
  scanf("%d", & min);
  if (min > 59) {
    gotoxy(38, 19);
    printf("incorrect!!!");
    Sleep(333);
    gotoxy(38, 19);
    printf("               ");
    gotoxy(38, 18);
    printf("     		");
    goto mi;
  }
  nv -> min = min;
  nv -> suivant = NULL;
  if (listc == NULL) return nv;
  else
    tst = listc;
  while (tst -> suivant != NULL) tst = tst -> suivant;
  tst -> suivant = nv;
  return tst;
}

// ==============================================  //
void affichagec(consultation * list) {
  consultation * tmp = list;
  int c = 1, i = 1;
  int x = 38;
  int y = 15;
  int choix;
  if (list == NULL) {
    gotoxy(38, 12);
    printf("la liste est vide!!");
    return;
  }
  gotoxy(38, 12);
  printf("affichage de liste ");
  ri: while (tmp != NULL) {
    gotoxy(x, 15);
    printf(" CONSULTATION %d ", i);
    gotoxy(x, 16);
    printf("CNE de patient:%s", tmp -> cnep);
    gotoxy(x, 17);
    printf("CNE de medcin:%s", tmp -> cnem);
    gotoxy(x, 18);
    printf("date de consultation:%d/%d/%d %d:%d", tmp -> annee, tmp -> mois, tmp -> jour, tmp -> heur, tmp -> min);
    gotoxy(x, 19);

    ask: gotoxy(38, 23);
    printf("Voulez vous afficher le patient suivant (Y/N):  ");
    choix = _getch();
    if (choix == 'Y' || choix == 'y') {
      tmp = tmp -> suivant;
      i++;
      clearS();
      goto ri;
    }
    if (choix == 'N' || choix == 'n') {
      return;
    } else {
      gotoxy(38, 24);
      printf("invalide choix !!");
      Sleep(666);
      clearS();
      goto ask;
    }
  }
}
// ==============================================  //
consultation * suppRc(consultation * listc) {
  int val;
  consultation * n, * prec;
  if (listc == NULL) {
    gotoxy(38, 13);
    printf("la liste est vide!");
    return NULL;
  }
  gotoxy(38, 13);
  printf("entrez la numero du consultation a supprim%c:   ", 130);
  scanf("%d", & val);
  if (listc -> numconsult == val) {
    if (listc -> suivant == NULL) {
      gotoxy(38, 15);
      printf("la liste ne contient que cette consultation ");
      gotoxy(38, 17);
      printf("la consultation est supprim%ce", 130);
      return NULL;
    } else {
      n = listc;
      listc = listc -> suivant;
      free(n);
      gotoxy(38, 17);
      printf("la consultation est supprim%ce", 130);
      return listc;
    }
  } else
    prec = listc;
  n = listc -> suivant;
  while (n != NULL) {
    if (n -> numconsult == val) {
      prec -> suivant = n -> suivant;
      free(n);
      gotoxy(38, 17);
      printf("la consultation est supprim%ce", 130);
      return prec;
    } else
      prec = n;
    n = n -> suivant;
  }
  gotoxy(38, 18);
  printf("le consultation n'est pas trouv%ce", 130);
  return listc;
}

// ==============================================  //
consultation * modifierc(consultation * listc, patient * p, medcin * m) {
  int num, num1, num2;
  consultation * tmp1, * tmp2;
  char cnep[9], cnem[9];
  int rp, rm, j, ms, an, h, min, d, k = 0;
  consultation * nv = (consultation * ) malloc(sizeof(consultation));
  consultation * print = listc;
  gotoxy(38, 11);
  printf("entrez le numero du consultation  :  ");
  scanf("%d", & num);
  if (listc == NULL) {
    gotoxy(38, 12);
    printf("la liste est vide");
    return NULL;
  }
  d = rechercherAjouc(listc, num);
  if (d == 1) {

    if (print -> numconsult == num) {
      tmp2 = print -> suivant;
      free(print);
      k++;
      goto red;
    }
    while (print != NULL) {
      if (print -> suivant -> numconsult == num) {
        tmp1 = print;
        tmp2 = print -> suivant -> suivant;
        free(print -> suivant);
        red: clearS();
        gotoxy(38, 11);
        printf("entrez le nouveau num du consultation");
        scanf("%d", & num2);
        num1 = rechercherAjouc(listc, num2);
        if (num1 == 1) {
          gotoxy(38, 12);
          printf("le num existe d%cja !!!", 130);
          Sleep(500);
          clearS();
          goto red;
        }
        nv -> numconsult = num2;
        red1: gotoxy(38, 12);
        printf("entrez le cne de patient ");
        scanf("%s", cnep);
        rp = rechercherAjoup(p, cnep);
        if (rp != 1) {
          gotoxy(38, 13);
          printf("le cne n'est pas trouv%c'\n", 130);
          Sleep(500);
          clearS();
          goto red1;
        }
        strcpy(nv -> cnep, cnep);
        red2: gotoxy(38, 13);
        printf("entrez le cne de medcin\t ");
        scanf("%s", cnem);
        rm = rechercherAjoum(m, cnem);
        if (rm != 1) {
          gotoxy(38, 14);
          printf("le cne n'est pas trouv%c\n", 130);
          Sleep(500);
          clearS();
          goto red2;
        }
        strcpy(nv -> cnem, cnem);
        gotoxy(38, 14);
        printf("la date de consultation \n");
        jr: gotoxy(38, 15);
        printf("jour:\t");
        scanf("%d", & j);
        if (j > 31) {
          gotoxy(38, 16);
          printf("incorrect!!!");
          Sleep(200);
          clearS();
          goto jr;
        }
        nv -> jour = j;
        ms: gotoxy(38, 16);
        printf("mois:\t");
        scanf("%d", & ms);
        if (ms > 12) {
          gotoxy(38, 17);
          printf("incorrect!!!");
          Sleep(200);
          clearS();
          goto ms;
        }
        nv -> mois = ms;
        ane: gotoxy(38, 17);
        printf("ann%ce:\t", 130);
        scanf("%d", & an);
        if (j > 9999) {
          gotoxy(38, 18);
          printf("incorrect!!!");
          Sleep(200);
          clearS();
          goto ane;
        }
        nv -> annee = an;
        he: gotoxy(38, 18);
        printf("heure:\t");
        scanf("%d", & h);
        if (h > 23) {
          gotoxy(38, 19);
          printf("incorrect!!!");
          Sleep(200);
          clearS();
          goto he;
        }
        nv -> heur = h;
        mi: gotoxy(38, 19);
        printf("minutes:\t");
        scanf("%d", & min);
        if (min > 59) {
          gotoxy(38, 20);
          printf("incorrect!!!");
          Sleep(200);
          clearS();
          goto mi;
        }
        nv -> min = min;
        nv -> suivant = tmp2;
        if (k == 1) {
          return nv;
        }
        tmp1 -> suivant = nv;

        return tmp1;

      }
      print = print -> suivant;
    }

  }
  if (d != 1) {
    gotoxy(38, 13);
    printf("ce CNE n'est pas trouv%c", 130);
    return listc;
  }
}
// ==============================================  //
void rechercher_consultation(consultation * listc) {
  int num;
  consultation * print = listc;
  gotoxy(38, 11);
  printf("entrez le numero du consultation  :  ");
  scanf("%d", & num);
  while (print != NULL) {
    if (num == print -> numconsult) {
      gotoxy(38, 13);
      printf("--------------consultation  %d--------------------", print -> numconsult);
      gotoxy(38, 14);
      printf(">>CNE de patient:%s", print -> cnep);
      gotoxy(38, 15);
      printf(">>CNE de medcin:%s", print -> cnem);
      gotoxy(38, 16);
      printf(">>date du consultation:%d/%d/%d %d:%d", print -> annee, print -> mois, print -> jour, print -> heur, print -> min);
      return;
    }
    print = print -> suivant;
  }
}

// ==============================================  //
void enregistrerc(consultation * print) {
  char en[] = "fconsultation.txt";
  FILE * fichier = fopen(en, "a");
  while (print != NULL) {
    fprintf(fichier, "%d\n", print -> numconsult);
    fprintf(fichier, "%s\n", print -> cnep);
    fprintf(fichier, "%s\n", print -> cnem);
    fprintf(fichier, "%d\n%d\n%d\n%d\n%d\n", print -> annee, print -> mois, print -> jour, print -> heur, print -> min);
    print = print -> suivant;
  }
  fclose(fichier);
}
// ==============================================  //
consultation * chargerc(consultation * c) {
  consultation * list = c;
  char en[] = "fconsultation.txt";
  FILE * fichier = fopen(en, "r+");
  if ((fopen(en, "r+")) == NULL) {
    gotoxy(52, 15);
    printf("Fichier ne pas trouv%c !!", 130);
    return list;
  }
  while (feof(fichier) == 0) {
    consultation * nw = (consultation * ) malloc(sizeof(consultation));
    fscanf(fichier, "%d\n", & nw -> numconsult);
    fscanf(fichier, "%s\n", nw -> cnep);
    fscanf(fichier, "%s\n", nw -> cnem);
    fscanf(fichier, "%d\n%d\n%d\n%d\n%d\n", & nw -> annee, & nw -> mois, & nw -> jour, & nw -> heur, & nw -> min);
    list = chargerhelpc(list, nw -> numconsult, nw -> cnep, nw -> cnem, nw -> annee, nw -> mois, nw -> jour, nw -> heur, nw -> min);
  }
  fclose(fichier);
  gotoxy(52, 15);
  printf("liste charg%ce (^-^)", 130);
  return list;

}
// ==============================================  //
consultation * chargerhelpc(consultation * list, int num, char cnep[], char cnem[], int annee, int mois, int jour, int heur, int min) {
  consultation * nv = (consultation * ) malloc(sizeof(consultation));
  consultation * tst = list;
  while (tst != NULL) {
    if (tst -> numconsult == num) {
      return list;
    } else
      tst = tst -> suivant;
  }
  nv -> numconsult = num;
  strcpy(nv -> cnep, cnep);
  strcpy(nv -> cnem, cnem);
  nv -> annee = annee;
  nv -> mois = mois;
  nv -> jour = jour;
  nv -> heur = heur;
  nv -> min = min;

  if (list == NULL) {
    nv -> suivant = NULL;
    return nv;
  } else {
    nv -> suivant = list;
    return nv;
  }
}
//================================================//
void initialiserfichierc() {

  char en[] = "fconsultation.txt";
  FILE * fichier = fopen(en, "r+");
  if (fichier == NULL) {
    gotoxy(49, 17);
    printf("Fichier n'est pas trouv%c !!", 130);

  } else

    fclose(fichier);
  int d = remove(en);
  if (d != 0) {
    gotoxy(49, 16);
    printf("Echec lors initialisation !");
    gotoxy(49, 17);
  } else {
    gotoxy(52, 15);
    printf("liste initialis%ce(^-^)", 130);
  }

}

//================================================//
/// fonction de medcin///
//================================================//
// ==============================================  //
medcin * initialiserm(medcin * l) {
  l = NULL;
  return l;
}

// ==============================================  //
medcin * ajouter_entetem(medcin * list) {
  medcin * nv = (medcin * ) malloc(sizeof(medcin));
  medcin * tst = list;
  int rp, rm;
  gotoxy(38, 10);
  printf("entrez le cne de ce medcin\t ");
  scanf("%s", & nv -> cnem);
  while (tst != NULL) {
    if ((strcmp(tst -> cnem, nv -> cnem)) == 0) {
      gotoxy(38, 12);
      printf("ce medcin existe d%cja dans la liste", 130);
      return list;
    } else
      tst = tst -> suivant;
  }

  gotoxy(38, 11);
  printf("Nom                      :    ");
  gotoxy(38, 12);
  printf("Pr%cnom                   :    ", 130);
  gotoxy(38, 13);
  printf("t%cl%c                     :    ", 130, 130);
  gotoxy(38, 14);
  printf("sex                      :    ");
  gotoxy(38, 15);
  printf("sp%ccialisation           :    ", 130);

  gotoxy(65, 11);
  scanf("%s", nv -> nom);
  gotoxy(65, 12);
  scanf("%s", nv -> prenom);
  gotoxy(65, 13);
  scanf("%d", & nv -> numtele);
  gotoxy(65, 14);
  scanf("%s", nv -> sex);
  gotoxy(65, 15);
  scanf("%s", nv -> specialisation);
  nv -> suivant = list;
  return nv;

}

// ==============================================  //
medcin * ajoutEnfinm(medcin * list) {
  medcin * nv = (medcin * ) malloc(sizeof(medcin));
  medcin * tst = list;
  gotoxy(38, 10);
  printf("entrez le cne de ce medcin\t ");
  scanf("%s", & nv -> cnem);
  while (tst != NULL) {
    if ((strcmp(tst -> cnem, nv -> cnem)) == 0) {
      gotoxy(38, 12);
      printf("ce medcin existe d%cja dans la liste", 130);
      return list;
    } else
      tst = tst -> suivant;
  }
  gotoxy(38, 11);
  printf("Nom                      :    ");
  gotoxy(38, 12);
  printf("Pr%cnom                   :    ", 130);
  gotoxy(38, 13);
  printf("t%cl%c                     :    ", 130, 130);
  gotoxy(38, 14);
  printf("sex                      :    ");
  gotoxy(38, 15);
  printf("sa sp%ccialisation        :    ", 130);

  gotoxy(65, 11);
  scanf("%s", nv -> nom);
  gotoxy(65, 12);
  scanf("%s", nv -> prenom);
  gotoxy(65, 13);
  scanf("%d", & nv -> numtele);
  gotoxy(65, 14);
  scanf("%s", nv -> sex);
  gotoxy(65, 15);
  scanf("%s", nv -> specialisation);

  nv -> suivant = NULL;
  if (list == NULL) return nv;
  else
    tst = list;
  while (tst -> suivant != NULL) tst = tst -> suivant;

  tst -> suivant = nv;

  return tst;

}

// ==============================================  //
// ==============================================  //
void affichagem(medcin * list) {
  medcin * tmp = list;
  int c = 1, i = 1;
  int x = 38;
  int y = 15;
  int choix;
  if (list == NULL) {
    gotoxy(38, 12);
    printf("la liste est vide!!");
    return;
  }
  gotoxy(38, 12);
  printf("affichage de liste ");
  ri: while (tmp != NULL) {
    gotoxy(x, 15);
    printf(" MEEDCIN %d ", i);
    gotoxy(x, 16);
    printf("CNE    :%5s     ", tmp -> cnem);
    gotoxy(x, 17);
    printf("Nom    :%5s     ", tmp -> nom);
    gotoxy(x, 18);
    printf("Pr%cnom :%5s     ", 130, tmp -> prenom);
    gotoxy(x, 19);
    printf("Sex    :%5s     ", tmp -> sex);
    gotoxy(x, 20);
    printf("T%cl%c   :%5d     ", 130, 130, tmp -> numtele);
    gotoxy(x, 21);
    printf("Spec   :%5s     ", tmp -> specialisation);

    ask: gotoxy(38, 23);
    printf("Voulez vous afficher le patient suivant (Y/N):  ");
    choix = _getch();
    if (choix == 'Y' || choix == 'y') {
      tmp = tmp -> suivant;
      i++;
      clearS();
      goto ri;
    }
    if (choix == 'N' || choix == 'n') {
      return;
    } else {
      gotoxy(38, 24);
      printf("invalide choix !!");
      Sleep(666);
      clearS();
      goto ask;
    }
  }
}

// ==============================================  //
void recherchercnem(medcin * list) {
  char cne[9];
  medcin * tmp = list;
  int i = 1;
  int x = 38;
  int y = 15;
  gotoxy(38, 10);
  printf("Entrez le cne de medcin  : ");
  scanf("%s", cne);
  while (tmp != NULL) {
    if (strcmp(tmp -> cnem, cne) == 0) {
      gotoxy(46, 12);
      printf("La valeur existe");

      gotoxy(x, y);
      printf(" MEDCIN %d ", i);
      y++;
      gotoxy(x, y);
      printf("CNE    :%5s     ", tmp -> cnem);
      y++;
      gotoxy(x, y);
      printf("Nom    :%5s     ", tmp -> nom);
      y++;
      gotoxy(x, y);
      printf("Pr%cnom :%5s     ", 130, tmp -> prenom);
      y++;
      gotoxy(x, y);
      printf("Sex    :%5s     ", tmp -> sex);
      y++;
      gotoxy(x, y);
      printf("T%cl%c   :%5d     ", 130, 130, tmp -> numtele);
      y++;
      gotoxy(x, y);
      printf("Spec   :%5s     ", tmp -> specialisation);
      y = y + 2;
      gotoxy(x, 24);
      return;
    }
    tmp = tmp -> suivant;
  }
  gotoxy(46, 12);
  printf("Le medcin n'existe pas ");
}

// ==============================================  //
void recherchernomm(medcin * list) {
  char nom[15];
  medcin * tmp = list;
  int x = 38;
  int y = 15;
  int i = 1;
  int k = 0;
  gotoxy(38, 10);
  printf(" entrez le nom a recherch%c\t", 130);
  scanf("%s", nom);

  while (tmp != NULL) {
    if (strcmp(tmp -> nom, nom) == 0) {
      gotoxy(x, y);
      printf(" MEDCIN  ");
      y++;
      gotoxy(x, y);
      printf("CNE    :%5s     ", tmp -> cnem);
      y++;
      gotoxy(x, y);
      printf("Nom    :%5s     ", tmp -> nom);
      y++;
      gotoxy(x, y);
      printf("Pr%cnom :%5s     ", 130, tmp -> prenom);
      y++;
      gotoxy(x, y);
      printf("Sex    :%5s     ", tmp -> sex);
      y++;
      gotoxy(x, y);
      printf("T%cl%c   :%5d     ", 130, 130, tmp -> numtele);
      y++;
      gotoxy(x, y);
      printf("Spec   :%5s     ", tmp -> specialisation);
      y = y + 2;
      gotoxy(36, y);
      printf("cliquer n'importe o%c pour afficher le medcin suivant", 151);
      _getch();
      clearS();
      y = y - 8;
      tmp = tmp -> suivant;
    } else
      tmp = tmp -> suivant;
  }

  gotoxy(46, 12);
  printf("aucun autre medcin n'existe avec ce nom ", 82);

}

//========================================================

medcin * modifierm(medcin * p) {
  int num, num2;
  medcin * tmp1, * tmp2, * print = p;
  char cnem[9], n[9];
  int rp, rm, j, ms, an, k = 0, d;
  medcin * nv = (medcin * ) malloc(sizeof(medcin));
  gotoxy(39, 11);
  printf("entrez le CNE du medcin a modifie  : ");
  scanf("%s", cnem);

  if (p == NULL) {
    gotoxy(38, 13);
    printf("la liste est vide");
    return NULL;
  }
  d = rechercherAjoum(p, cnem);
  if (d == 1) {

    if (strcmp(print -> cnem, cnem) == 0) {
      tmp2 = print -> suivant;
      free(print);
      k++;
      goto red;
    }

    while (print != NULL) {
      if (strcmp(print -> suivant -> cnem, cnem) == 0) {
        tmp1 = print;
        tmp2 = print -> suivant -> suivant;
        free(print -> suivant);
        red: Sleep(100);
        clearS();
        gotoxy(38, 11);
        printf("entrez le nouveau cne ");
        scanf("%s", n);
        num = rechercherAjoum(p, n);
        if (num == 1) {
          gotoxy(38, 12);
          printf("le CNE d%cja existe !!!", 130);
          Sleep(200);
          goto red;
        }
        strcpy(nv -> cnem, n);
        gotoxy(38, 12);
        printf("Nom :    ");
        scanf("%s", nv -> nom);
        gotoxy(38, 13);
        printf("Pr%cnom :    ", 130);
        scanf("%s", nv -> prenom);
        gotoxy(38, 14);
        printf("t%cl%c  :    ", 130, 130);
        scanf("%d", & nv -> numtele);
        gotoxy(38, 15);
        printf("sex :    ");
        scanf("%s", nv -> sex);
        gotoxy(38, 16);
        printf("  entrez sp%ccialisation :    ", 130);
        scanf("%s", nv -> specialisation);
        nv -> suivant = tmp2;
        if (k == 1) {
          return nv;
        }

        tmp1 = nv;
        return tmp1;
      }
      print = print -> suivant;
    }
  }
  if (d != 1) {
    gotoxy(38, 13);
    printf("ce CNE n'est pas trouv%c", 130);
    return p;
  }

}

// ==============================================  
medcin * suppRm(medcin * list, char cnem[9]) {
  medcin * n, * prec;
  if (list == NULL) {
    gotoxy(38, 13);
    printf("la liste est vide!");
    return NULL;
  }
  if (list -> suivant == NULL && strcmp(list -> cnem, cnem) == 0) {
    gotoxy(38, 15);
    printf("la liste ne contient que ce medcin ");
    gotoxy(38, 17);
    printf("le medcin est supprim%c", 130);
    return NULL;
  } else {
    if (strcmp(list -> cnem, cnem) == 0) {
      n = list;
      list = list -> suivant;
      free(n);
      gotoxy(38, 17);
      printf("le medcin est supprim%c", 130);
      return list;
    }

    prec = list;
    n = list -> suivant;
    while (n != NULL) {
      if (strcmp(n -> cnem, cnem) == 0) {
        prec -> suivant = n -> suivant;
        free(n);
        gotoxy(38, 17);
        printf("le medcin est supprim%c", 130);
        return prec;
      }
      prec = n;
      n = n -> suivant;
    }
  }
  gotoxy(38, 18);
  printf("le medcin n'est pas trouv%c", 130);
  return list;
}
//================================================//
void enregistrerm(medcin * print) {
  char en[] = "fmedcin.txt";
  FILE * fichier = fopen(en, "a");
  while (print != NULL) {
    fprintf(fichier, "%s\n", print -> cnem);
    fprintf(fichier, "%s\n", print -> nom);
    fprintf(fichier, "%s\n", print -> prenom);
    fprintf(fichier, "%s\n", print -> sex);
    fprintf(fichier, "%d\n", print -> numtele);
    fprintf(fichier, "%s\n", print -> specialisation);
    print = print -> suivant;
  }
  fclose(fichier);
}
//================================================//
medcin * chargerm(medcin * p) {
  medcin * list = p;

  char en[] = "fmedcin.txt";
  FILE * fichier = fopen(en, "r+");
  if ((fopen(en, "r+")) == NULL) {
    gotoxy(52, 15);
    printf("Fichier ne pas trouv%c !!", 130);
    return list;
  }

  while (!feof(fichier)) {
    medcin * nw = (medcin * ) malloc(sizeof(medcin));
    fscanf(fichier, "%s\n%s\n%s\n%s\n%d\n%s\n", nw -> cnem, nw -> nom, nw -> prenom, nw -> sex, & nw -> numtele, nw -> specialisation);
    list = chargehelpm(list, nw -> cnem, nw -> nom, nw -> prenom, nw -> numtele, nw -> sex, nw -> specialisation);
  }
  fclose(fichier);
  gotoxy(52, 15);
  printf("liste charg%ce (^-^)", 130);
  return list;
}
//=====================================================//
medcin * chargehelpm(medcin * list, char cne[], char nom[], char prenom[], int tele, char sex[], char spec[]) {
  medcin * nv = (medcin * ) malloc(sizeof(medcin));
  medcin * tst = list;
  while (tst != NULL) {
    if ((strcmp(tst -> cnem, cne)) == 0) {
      return list;
    } else
      tst = tst -> suivant;
  }
  strcpy(nv -> cnem, cne);
  strcpy(nv -> nom, nom);
  strcpy(nv -> prenom, prenom);
  nv -> numtele = tele;
  strcpy(nv -> sex, sex);
  strcpy(nv -> specialisation, spec);

  if (list == NULL) {
    nv -> suivant = NULL;
    return nv;
  } else {
    nv -> suivant = list;
    return nv;
  }
}
//================================================//
void initialiserfichierm() {
  char en[] = "fmedcin.txt";
  FILE * fichier = fopen(en, "r+");
  if (fichier == NULL) {
    gotoxy(49, 17);
    printf("Fichier n'est pas trouv%c !!", 130);

  } else {

    fclose(fichier);
    int d = remove(en);
    if (d != 0) {
      gotoxy(49, 16);
      printf("Echec lors initialisation !");
      gotoxy(49, 17);
    } else
      gotoxy(52, 15);
    printf("liste initialis%ce(^-^)", 130);
  }
}
//================================================//
//================================================//

void nothing() {
  int i;
  for (i = 4; i < 16; i += 2) {
    gotoxy(i, 10);
    printf("MENU");
    Sleep(200);
    if (i != 14) {
      gotoxy(i, 10);
      printf("    ");
    }
  }

  gotoxy(10, 9);
  printf("/");
  gotoxy(21, 9);
  printf("\\");
  Sleep(100);
  gotoxy(10, 9);
  printf("|");
  gotoxy(21, 9);
  printf("|");
  Sleep(100);
  gotoxy(10, 9);
  printf("\\|");
  gotoxy(21, 9);
  printf("|/");
  Sleep(100);
  gotoxy(10, 9);
  printf("_|");
  gotoxy(21, 9);
  printf("|_");
  Sleep(100);
  gotoxy(10, 9);
  printf(" |");
  gotoxy(21, 9);
  printf("| ");
  Sleep(100);
  gotoxy(10, 10);
  printf(" /");
  gotoxy(21, 10);
  printf("\\");
  Sleep(100);
  gotoxy(10, 10);
  printf(" |");
  gotoxy(21, 10);
  printf("|  ");
  Sleep(100);
  gotoxy(10, 11);
  printf(" |");
  gotoxy(21, 11);
  printf("|  ");
  Sleep(100);
  gotoxy(12, 9);
  printf("_");
  gotoxy(20, 11);
  printf("_");
  Sleep(100);
  gotoxy(12, 9);
  printf("__");
  gotoxy(18, 11);
  printf("__");
  Sleep(100);
  gotoxy(12, 9);
  printf("____");
  printf("_");
  gotoxy(15, 11);
  printf("___");
  Sleep(100);
  gotoxy(12, 9);
  printf("______");
  printf("_");
  gotoxy(14, 11);
  printf("____");
  Sleep(100);
  gotoxy(12, 9);
  printf("________");
  printf("_");
  gotoxy(12, 11);
  printf("____");
}
//==================Fonction qui supprime une partie de la console aprÃƒÆ’Ã‚Â©s l'execution des choix  =====//
void clearS() {
  int i;
  for (i = 9; i < 25; i++) {
    gotoxy(36, i);
    printf("                                                      ");
    gotoxy(10, 23);
    printf("    ");
  }
  drawRectangle();
}
//=====================================================================
void SetConsoleColour(WORD * Attributes, DWORD Colour) {
  CONSOLE_SCREEN_BUFFER_INFO Info;
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleScreenBufferInfo(hStdout, & Info);
  * Attributes = Info.wAttributes;
  SetConsoleTextAttribute(hStdout, Colour);
}

void ResetConsoleColour(WORD Attributes) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

//====================================================================
void display() {
  int i;
  for (i = 20; i > 11; i -= 2) {
    gotoxy(8, i);
    printf("Organiser patients");
    Sleep(150);
    if (i != 13) {
      gotoxy(8, i);
      printf("                   ");
    }

  }

  for (i = 20; i > 13; i -= 2) {
    gotoxy(8, 13);
    printf("Organiser patients");
    gotoxy(8, i);
    printf("Organiser medcins");
    Sleep(150);
    if (i != 15) {
      gotoxy(8, i);
      printf("                  ");
    }
  }

  for (i = 20; i > 15; i -= 2) {
    gotoxy(8, 13);
    printf("Organiser patients");
    gotoxy(8, 15);
    printf("Organiser medcins");
    gotoxy(8, i);
    printf("Organiser consultations");
    Sleep(150);
    if (i != 17) {
      gotoxy(8, i);
      printf("                         ");
    }
  }

  for (i = 20; i > 17; i -= 2) {
    gotoxy(8, 13);
    printf("Organiser patients");
    gotoxy(8, 15);
    printf("Organiser medcins");
    gotoxy(8, 17);
    printf("Organiser consultations");
    gotoxy(8, i);
    printf("Changer le mot de passe");
    Sleep(150);
    if (i != 14) {
      gotoxy(8, i);
      printf("                       ");
    }
  }
  for (i = 20; i > 19; i -= 2) {
    gotoxy(8, 13);
    printf("Organiser patients");
    gotoxy(8, 15);
    printf("Organiser medcins");
    gotoxy(8, 17);
    printf("Organiser consultations");
    gotoxy(8, 19);
    printf("Changer le mot de passe");
    gotoxy(8, i);
    printf("QUITTER");
    Sleep(150);
    if (i != 14) {
      gotoxy(8, i);
      printf("                       ");
    }
  }
  gotoxy(8, 21);
  printf("QUITTER");
  nothing();
}

//============================================================================
void ClearConsoleToColors(int ForgC, int BackC) {
  WORD wColor = ((BackC & WHITE) << 4) + (ForgC & WHITE);
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD coord = {
    0,
    0
  };
  DWORD count;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  SetConsoleTextAttribute(hStdOut, wColor);
  if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
    FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, & count);
    SetConsoleCursorPosition(hStdOut, coord);
  }
  return;
}
//===========================================================================

//=========================================================================

void drawRectangle() {
  WORD Attributes = 0;
  int i, j;
  gotoxy(0, 0);
  printf("%c", 201);

  for (i = 1; i < 90; i++) {
    gotoxy(i, 0);
    printf("%c", 205);
  }
  gotoxy(90, 0);
  printf("%c", 187);

  for (i = 1; i < 25; i++) {
    gotoxy(90, i);
    if (i == 3 || i == 8) {
      printf("%c", 185);
    } else {
      printf("%c", 186);
    }
  }

  gotoxy(90, 25);
  printf("%c", 188);
  for (i = 89; i > 0; i--) {
    gotoxy(i, 25);
    if (i == 35) {
      printf("%c", 202);
    } else {
      printf("%c", 205);
    }
  }
  gotoxy(0, 25);
  printf("%c", 200);
  for (i = 24; i > 0; i--) {
    gotoxy(0, i);
    if (i == 3 || i == 8) {
      printf("%c", 204);
    } else {
      printf("%c", 186);
    }
  }

  for (i = 1; i < 90; i++) {
    gotoxy(i, 3);
    printf("%c", 205);
  }
  for (i = 1; i < 90; i++) {
    gotoxy(i, 8);
    if (i == 35) {
      printf("%c", 203);
    } else {
      printf("%c", 205);
    }
  }
  for (i = 9; i < 25; i++) {
    gotoxy(35, i);
    printf("%c", 186);
  }

  for (i = 9; i < 29; i++) {
    gotoxy(0, i);
    printf("%c", 186);
  }
  for (i = 9; i < 29; i++) {
    gotoxy(90, i);
    printf("%c", 186);
  }
  for (i = 0; i < 90; i++) {
    gotoxy(i, 29);
    printf("%c", 205);
  }
  gotoxy(0, 29);
  printf("%c", 200);
  gotoxy(0, 25);
  printf("%c", 204);
  gotoxy(90, 29);
  printf("%c", 188);
  gotoxy(90, 25);
  printf("%c", 185);

  for (i = 1; i < 90; i++) {
    SetConsoleColour( & Attributes, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    gotoxy(i, 26);
    printf(" ");
    ResetConsoleColour(Attributes);
  }
  for (i = 1; i < 90; i++) {
    SetConsoleColour( & Attributes, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    gotoxy(i, 27);
    printf(" ");
    ResetConsoleColour(Attributes);
  }
  for (i = 1; i < 90; i++) {
    SetConsoleColour( & Attributes, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    gotoxy(i, 28);
    printf(" ");
    ResetConsoleColour(Attributes);
  }
  gotoxy(20, 26);
  SetConsoleColour( & Attributes, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
  printf("Utiliser les touches         pour deplacer le curseur  ");
  gotoxy(41, 26);
  printf("Up Down");
  ResetConsoleColour(Attributes);
  gotoxy(20, 27);
  SetConsoleColour( & Attributes, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
  printf("Utiliser la touche           pour executer votre choix ");
  gotoxy(41, 27);
  printf("Entree ");
  ResetConsoleColour(Attributes);
}
//================================================================
void drawRectanglelogin() {
  int i;
  gotoxy(48, 12);
  printf("Entrez les infos suivants    ");
  gotoxy(58, 9);
  printf("LOGIN");
  gotoxy(40, 14);
  printf("USERNAME          : \t");
  gotoxy(40, 16);
  printf("PASSWORD          :");
  for (i = 9; i < 25; i++) {
    gotoxy(35, i);
    printf("%c", 186);
  }
  gotoxy(35, 8);
  printf("%c", 201);

  for (i = 36; i < 90; i++) {
    gotoxy(i, 8);
    printf("%c", 205);
  }

  printf("%c", 187);

  for (i = 9; i < 25; i++) {
    gotoxy(90, i);
    if (i == 3 || i == 8) {
      printf("%c", 185);
    } else {
      printf("%c", 186);
    }
  }

  for (i = 36; i < 90; i++) {
    gotoxy(i, 10);
    printf("%c", 205);
  }
  for (i = 36; i < 90; i++) {
    gotoxy(i, 25);
    printf("%c", 205);
  }

  printf("%c", 188);
  gotoxy(35, 25);
  printf("%c", 200);
  gotoxy(90, 10);
  printf("%c", 185);
  gotoxy(35, 10);
  printf("%c", 204);
  for (i = 36; i < 90; i++) {
    gotoxy(i, 19);
    printf("%c", 205);
  }
  gotoxy(35, 19);
  printf("%c", 204);
  gotoxy(90, 19);
  printf("%c", 185);
}
//================================================
void print(const char st[]) {
  int i = 54;
  gotoxy(53, 8);
  printf("%c", 203);
  gotoxy(74, 8);
  printf("%c", 203);
  gotoxy(53, 9);
  printf("%c   %s", 186, st);
  gotoxy(74, 9);
  printf("%c", 186);
  gotoxy(53, 10);
  printf("%c", 200);
  gotoxy(74, 10);
  printf("%c", 188);
  for (i = 54; i < 74; i++) {
    gotoxy(i, 10);
    printf("%c", 205);
  }
}

//==================================================
void Chargement() {
  int i, gd = DETECT, gm;
  char driver[] = "C:\\TURBOC3\\BGI"; // pour enlever le warning deprecated conversion from string to constant to char , nous avons mis (C:\\TURBOC3\\BGI) 
  // dans un tableau et pas dans initgraph directement
  // la mÃƒÂ©me chose est faite dans d'autres fonctions
  initgraph( & gd, & gm, driver);
  setviewport(0, 0, 639, 440, 1);
  clearviewport();
  settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
  char chargement[] = "CHARGEMENT ,patienter....";
  outtextxy(150, 260, chargement);
  for (i = 0; i <= 320; i = i + 10) {
    setcolor(5);
    circle(150 + i, 410, 10);
    circle(150 + i, 415, 10);
    circle(150 + i, 420, 10);
    delay(200);
    if (i == 320)
      break;
  }
  closegraph();
}

//=================================
void printMsg() {
  int gdriver = DETECT, gmode, i;
  char driver[] = "C:\\Turboc3\\BGI";
  initgraph( & gdriver, & gmode, driver);
  setcolor(8);
  settextstyle(1, 0, 5);
  char gestion[] = "Gestion d'AKBABEL";
  outtextxy(10, 200, gestion);
  Sleep(3000);
  closegraph();
  Chargement();
}
//=================================	
void TextColour(WORD * Attributes, DWORD Colour) {
  CONSOLE_SCREEN_BUFFER_INFO Info;
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleScreenBufferInfo(hStdout, & Info);
  * Attributes = Info.wAttributes;
  SetConsoleTextAttribute(hStdout, Colour);
}

//==================================================================

const char * menu[] = {
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  "Organiser patients",
  " ",
  "Organiser medcins",
  " ",
  "Organiser consultations",
  " ",
  "Changer le mot de passe",
  " ",
  "QUITTER         "
};
const char * menuP[] = {
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  "initialiser liste         ",
  "ajouter un patient     ",
  "afficher liste des patient",
  "rechercher            ",
  "modifier un patient     ",
  "supprimer un patient(par CNE)",
  "enregistrer dans un fichier",
  "charger depuis fichier",
  "initialiser fichier",
  "retour au menu principal "
};
const char * menuM[] = {
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  "initialiser liste         ",
  "ajouter un medcin      ",
  "afficher liste des medcin ",
  "rechercher            ",
  "modifier un medcin      ",
  "supprimer un medcin(par CNE) ",
  "enregistrer dans un fichier",
  "charger depuis fichier",
  "initialiser fichier",
  "retour au menu principal "
};
const char * menuC[] = {
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  " ",
  "initialiser liste         ",
  "ajouter une consultation      ",
  "afficher liste des consultation",
  "rechercher            ",
  "supprimer une consultation ",
  "modifier une consultation",
  "enregistrer dans un fichier",
  "charger depuis fichier",
  "initialiser fichier",
  "retour au menu principal "
};

WORD Attributes = 0;
//=============================================
int MENU() {
  int i, j = 13;
  int val = 13;

  for (i = 4; i < 9; i++, j = j + 2) {
    gotoxy(7, j);
    printf("%s", menu[i]);
  }

}
//============================================
int MENUp() {
  int i, j = 12;
  int val = 12;
  for (i = 12; i <= 21; i++, j = j++) {
    gotoxy(4, j);
    printf("%s", menuP[i]);
  }
}
//=============================================
int MENUm() {
  int i, j = 12, val = 12;
  for (i = 12; i <= 21; i++, j = j++) {
    gotoxy(4, j);
    printf("%s", menuM[i]);
  }
}
//==============================================
int MENUc() {
  int i, j = 12, val = 12;
  for (i = 12; i <= 21; i++, j = j++) {
    gotoxy(4, j);
    printf("%s", menuC[i]);
  }
}
//===========================================
int CHOIX(int val, int
  var, int theme) {
  switch (var) {
  case 1:
    if (val == 15 || val == 17 || val == 19 || val == 21) {
      gotoxy(8, val);
      printf("%s  ", menu[val]);
      val = val - 2;

      gotoxy(8, val);
      printf("%s  ", menu[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);

    } else {
      gotoxy(8, val);
      printf("%s  ", menu[val]);
      val = 21;

      gotoxy(8, val);
      printf("%s  ", menu[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    }
    break;

  case 2:
    if (val == 13 || val == 15 || val == 17 || val == 19) {
      gotoxy(8, val);
      printf("%s  ", menu[val]);
      val = val + 2;
      gotoxy(8, val);
      printf("%s  ", menu[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    } else {
      gotoxy(8, val);
      printf("%s  ", menu[val]);
      val = 13;
      gotoxy(8, val);
      printf("%s  ", menu[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    }
    break;
  }
  return val;
}

int CHOIXP(int val, int
  var, int theme) {
  switch (var) {
  case 1:
    if (val == 13 || val == 14 || val == 15 || val == 16 || val == 17 || val == 18 || val == 19 || val == 20 || val == 21) {
      gotoxy(4, val);
      printf("%s  ", menuP[val]);
      val = val--;

      gotoxy(4, val);
      printf("%s  ", menuP[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    } else {
      gotoxy(4, val);
      printf("%s  ", menuP[val]);
      val = 21;

      gotoxy(4, val);
      printf("%s  ", menuP[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    }
    break;

  case 2:
    if (val == 12 || val == 13 || val == 14 || val == 15 || val == 16 || val == 17 || val == 18 || val == 19 || val == 20) {
      gotoxy(4, val);
      printf("%s  ", menuP[val]);
      val = val++;
      gotoxy(4, val);
      printf("%s  ", menuP[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    } else {
      gotoxy(4, val);
      printf("%s  ", menuP[val]);
      val = 12;
      gotoxy(4, val);
      printf("%s  ", menuP[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    }
    break;
  }
  return val;
}

int CHOIXM(int val, int
  var, int theme) {
  switch (var) {
  case 1:
    if (val == 13 || val == 14 || val == 15 || val == 16 || val == 17 || val == 18 || val == 19 || val == 20 || val == 21) {
      gotoxy(4, val);
      printf("%s  ", menuM[val]);
      val = val--;

      gotoxy(4, val);
      printf("%s  ", menuM[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    } else {
      gotoxy(4, val);
      printf("%s  ", menuM[val]);
      val = 21;

      gotoxy(4, val);
      printf("%s  ", menuM[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    }
    break;

  case 2:
    if (val == 12 || val == 13 || val == 14 || val == 15 || val == 16 || val == 17 || val == 18 || val == 19 || val == 20) {
      gotoxy(4, val);
      printf("%s  ", menuM[val]);
      val = val++;
      gotoxy(4, val);
      printf("%s  ", menuM[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    } else {
      gotoxy(4, val);
      printf("%s  ", menuM[val]);
      val = 12;
      gotoxy(4, val);
      printf("%s  ", menuM[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    }
    break;
  }
  return val;
}

int CHOIXC(int val, int
  var, int theme) {
  switch (var) {
  case 1:
    if (val == 13 || val == 14 || val == 15 || val == 16 || val == 17 || val == 18 || val == 19 || val == 20 || val == 21) {
      gotoxy(4, val);
      printf("%s", menuC[val]);
      val = val--;

      gotoxy(4, val);
      printf("%s", menuC[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    } else {
      gotoxy(4, val);
      printf("%s", menuC[val]);
      val = 21;

      gotoxy(4, val);
      printf("%s", menuC[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    }
    break;

  case 2:
    if (val == 12 || val == 13 || val == 14 || val == 15 || val == 16 || val == 17 || val == 18 || val == 19 || val == 20) {
      gotoxy(4, val);
      printf("%s", menuC[val]);
      val = val++;
      gotoxy(4, val);
      printf("%s", menuC[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    } else {
      gotoxy(4, val);
      printf("%s", menuC[val]);
      val = 12;
      gotoxy(4, val);
      printf("%s", menuC[val]);
      if (theme == 1) ClearConsoleToColors(80, 15);
      if (theme == 2) ClearConsoleToColors(GREEN, WHITE);
    }
    break;
  }
  return val;
}

//=============================================================

//===================MENUPRINCIPAL==================//
void MENUPRI(char user[], int theme) {
  WORD Attributes = 0;
  int boucle, bouclep, bouclem, bouclec;
  int z, y, choixp, rchoix, choixMain, choix;
  int val = 13, valp = 12, valm = 12, valc = 12;
  int zc, yc, choixc;
  int zm, ym, choixm, rchoixm;
  char cnep[9];
  char cnem[9];
  patient * listp = (patient * ) malloc(sizeof(patient));
  medcin * listm = (medcin * ) malloc(sizeof(medcin));
  consultation * listc = (consultation * ) malloc(sizeof(consultation));

  listp = initialiserp(listp);
  listm = initialiserm(listm);
  listc = initialiserc(listc);

  herec: gotoxy(32, 1);
  printf("HOSPITAL    : AKBABEL ");
  gotoxy(73, 2);
  printf("MEKNES,MAROC ");
  gotoxy(10, 5);
  printf("Bonjour  %s", user);
  drawRectangle();
  time_t rawtime;
  struct tm * timeinfo;
  time( & rawtime);
  timeinfo = localtime( & rawtime);
  gotoxy(10, 6);
  printf("heure et date actuelles: %s", asctime(timeinfo));
  Sleep(333);
  display();

  //les choix 
  MENU();
  boucle:

    while (boucle != 99) {
      gotoxy(5, val);
      boucle = _getch();
      switch (boucle) {
      case KEY_UP:
        val = CHOIX(val, 1, theme);
        break;
      case KEY_DOWN:
        val = CHOIX(val, 2, theme);
        break;
      case KEY_ENTER:
        goto encore;
        break;
      }
    }

  encore:
    choix = val;
  switch (choix) {
  case 13:
    goto menup;
    break;
  case 15:
    goto menum;
    break;
  case 17:
    goto menuc;
    break;
  case 19:
    changepass(user, theme);
    break;
  case 21:
    gotoxy(5, 25);
    exit(0);
    break;
  default:
    gotoxy(4, 21);
    printf("CHOIX INVALIDE");
    Sleep(666);
    system("cls");
    goto herec;
  }

  menup: system("cls");
  gotoxy(32, 1);
  printf("HOSPITAL    : AKBABEL ");
  gotoxy(73, 2);
  printf("MEKNES,MAROC ");
  gotoxy(10, 5);
  printf("Bonjour  %s", user);
  drawRectangle();
  time( & rawtime);
  timeinfo = localtime( & rawtime);
  gotoxy(10, 6);
  printf("heure et date actuelles: %s", asctime(timeinfo));

  herep: gotoxy(4, 10);
  printf("PATIENT");
  MENUp();
  bouclep:

    while (bouclep != 99) {
      gotoxy(3, valp);
      bouclep = _getch();
      switch (bouclep) {
      case KEY_UP:
        valp = CHOIXP(valp, 1, theme);
        break;
      case KEY_DOWN:
        valp = CHOIXP(valp, 2, theme);
        break;
      case KEY_ENTER:
        goto encorep;
        break;
      }
    }

  encorep:
    choixp = valp;
  switch (choixp) {
  case 12:
    clearS();
    print("INITIALISATION");
    listp = initialiserp(listp);
    gotoxy(44, 12);
    printf("Liste initialis%ce  ", 130);
    gotoxy(44, 13);
    printf("cliquer sur une touche pour retourner au menu ");
    _getch();
    clearS();
    goto herep;
    break;
  case 13:
    ajt:
      clearS();
    print("AJOUT");
    gotoxy(46, 12);
    printf("1 :ajoute en tete ");
    gotoxy(46, 13);
    printf("2 :ajoute en fin ");
    gotoxy(46, 14);
    printf("entrez votre choix :  ");
    scanf("%d", & z);
    if (z == 1) {
      clearS();
      listp = ajouter_entetep(listp);
      gotoxy(52, 20);
      printf("patient ajout%c", 130);
      gotoxy(43, 21);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto herep;
      break;
    }
    if (z == 2) {
      clearS();
      listp = ajoutEnfinp(listp);
      gotoxy(52, 20);
      printf("patient ajout%c", 130);
      gotoxy(43, 21);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto herep;
      break;
    } else {
      gotoxy(46, 14);
      printf("entrez un valide choix ");
      goto ajt;
    }

  case 14:
    clearS();
    print("AFFICHAGE");
    affichagep(listp);
    goto herep;
    break;
  case 15:
    clearS();
    print("RECHERCHE");
    ici: gotoxy(40, 12);
    printf("Voulez vous rechercher par cne ou par nom ");
    gotoxy(40, 13);
    printf("1 . reference    ");
    gotoxy(40, 14);
    printf("2 . nom  . ");
    gotoxy(40, 15);
    printf("==>votre choix :  ");
    scanf("%d", & rchoix);
    if (rchoix == 1) {
      clearS();
      recherchercnep(listp);
      gotoxy(43, 24);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto herep;
      break;
    }
    if (rchoix == 2) {
      clearS();
      recherchernomp(listp);
      gotoxy(43, 24);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto herep;
      break;
    } else
      gotoxy(40, 17);
    printf("entrez a valide choix!");
    Sleep(200);
    clearS();
    goto ici;
    break;
  case 16:
    clearS();
    print("MODIFICATION");
    listp = modifierp(listp);
    gotoxy(38, 21);
    printf("element modifi%c ", 130);
    gotoxy(43, 22);
    printf("cliquer sur une touche pour retourner au menu ");
    _getch();
    clearS();
    goto herep;
    break;
  case 17:
    supp:
      clearS();
    print("SUPPRESSION");
    gotoxy(38, 11);
    printf("Entrer la CNE :  ");
    scanf("%s", cnep);
    listp = suppRp(listp, cnep);
    gotoxy(37, 20);
    printf("voulez vous supprimer un autre patient?(Y/N) ");
    y = _getch();
    if (y == 'Y' || y == 'y') goto supp;
    else {
      goto herep;
      break;
    }
    goto herep;
    break;

  case 18:
    clearS();
    print("ENREGISTREMENT");
    enregistrerp(listp);
    gotoxy(52, 15);
    printf("liste enregistr%ce (^-^)", 130);
    gotoxy(43, 19);
    printf("cliquer sur une touche pour retourner au menu ");
    _getch();
    clearS();
    goto herep;
    break;

  case 19:
    clearS();
    print("CHARGEMENT");
    listp = chargerp(listp);
    gotoxy(43, 19);
    printf("cliquer sur une touche pour retourner au menu ");
    _getch();
    clearS();
    goto herep;
    break;
  case 20:
    clearS();
    initialiserfichierp();
    gotoxy(43, 19);
    printf("cliquer sur une touche pour retourner au menu ");
    _getch();
    clearS();
    goto herep;
    break;
  case 21:
    clearS();
    system("cls");
    goto herec;
    break;
  default:
    gotoxy(2, 24);
    printf("Choix non valide !! ");
    Sleep(333);
    gotoxy(2, 24);
    printf("                     ");
    break;

  }

  menum: system("cls");
  gotoxy(32, 1);
  printf("HOSPITAL    : AKBABEL ");
  gotoxy(73, 2);
  printf("MEKNES,MAROC ");
  gotoxy(10, 5);
  printf("Bonjour  %s", user);
  drawRectangle();
  time( & rawtime);
  timeinfo = localtime( & rawtime);
  gotoxy(10, 6);
  printf("heure et date actuelle: %s", asctime(timeinfo));
  herem:
    gotoxy(4, 10);
  printf("MEDCIN");
  MENUm();

  bouclem:
    while (bouclem != 99) {
      gotoxy(3, valm);
      bouclem = _getch();
      switch (bouclem) {
      case KEY_UP:
        valm = CHOIXM(valm, 1, theme);
        break;
      case KEY_DOWN:
        valm = CHOIXM(valm, 2, theme);
        break;
      case KEY_ENTER:
        goto encorem;
        break;
      }
    }

  encorem:
    choixm = valm;
  while (choixm != 99) {
    switch (choixm) {
    case 12:
      clearS();
      print("INITIALISATION");
      listm = initialiserm(listm);
      gotoxy(46, 12);
      printf("Liste initialis%ce  ", 130);
      gotoxy(43, 13);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto herem;
      break;
    case 13:
      ajta: clearS();
      print("AJOUT");
      gotoxy(46, 12);
      printf("1 :ajoute en tete ");

      gotoxy(46, 13);
      printf("2 :ajoute en fin ");

      gotoxy(46, 14);
      printf("entrez votre choix : ");
      scanf("%d", & zm);
      if (zm == 1) {
        clearS();
        listm = ajouter_entetem(listm);
        gotoxy(52, 20);
        printf("medcin ajout%c", 130);
        gotoxy(43, 21);
        printf("cliquer sur une touche pour retourner au menu ");
        _getch();
        clearS();
        goto herem;
        break;
      }
      if (zm == 2) {
        clearS();
        listm = ajoutEnfinm(listm);
        gotoxy(52, 20);
        printf("patient ajout%c", 130);
        gotoxy(43, 21);
        printf("cliquer sur une touche pour retourner au menu ");
        _getch();
        clearS();
        goto herem;
        break;
      } else {
        gotoxy(46, 14);
        printf("entrez un valide choix ");
        goto ajta;
      }

    case 14:
      clearS();
      print("AFFICHAGE");
      affichagem(listm);
      goto herem;
      break;

    case 15:
      clearS();
      print("RECHERCHE");

      icia: gotoxy(40, 12);
      printf("Voulez vous rechercher par cne ou par nom ");
      gotoxy(40, 13);
      printf("1 . reference    ");
      gotoxy(40, 14);
      printf("2 . nom  . ");
      gotoxy(40, 15);
      printf("==>votre choix :  ");
      scanf("%d", & rchoixm);
      if (rchoixm == 1) {
        clearS();
        recherchercnem(listm);
        gotoxy(43, 22);
        printf("cliquer sur une touche pour retourner au menu ");
        _getch();
        clearS();
        goto herem;
        break;
      }
      if (rchoixm == 2) {
        clearS();
        recherchernomm(listm);
        gotoxy(43, 22);
        printf("cliquer sur une touche pour retourner au menu ");
        _getch();
        clearS();
        goto herem;
        break;
      } else
        gotoxy(40, 17);
      printf("entrez un valide choix!");
      Sleep(200);
      clearS();
      goto icia;
      break;

    case 16:
      clearS();
      print("MODIFICATION");
      listm = modifierm(listm);
      gotoxy(38, 21);
      printf("element modifi%c ", 130);
      gotoxy(43, 23);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      goto herem;
      break;
    case 17:
      suppc:
        clearS();
      print("SUPPRESSION");
      gotoxy(38, 11);
      printf("Entrez la CNE :  ");
      scanf("%s", cnem);
      listm = suppRm(listm, cnem);
      if (listm == NULL) goto herem;
      gotoxy(38, 20);
      printf("supprimer un autre medcin?(Y/N)? ");
      ym = _getch();
      if (ym == 'Y' || ym == 'y') goto suppc;
      else {
        goto herem;
        break;
      }
      break;

    case 18:
      clearS();
      print("ENREGISTREMENT");
      enregistrerm(listm);
      gotoxy(52, 15);
      printf("liste enregistr%ce (^-^)", 130);
      gotoxy(43, 16);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto herem;
      break;

    case 19:
      clearS();
      print("CHARGEMENT");
      listm = chargerm(listm);
      gotoxy(43, 19);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto herem;
      break;

    case 20:
      clearS();
      initialiserfichierm();
      gotoxy(43, 19);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto herem;
      break;
    case 21:
      clearS();
      system("cls");
      goto herec;
      break;

    default:
      gotoxy(2, 24);
      printf("choix non valide !! ");
      Sleep(333);
      gotoxy(2, 24);
      printf("                     ");
      break;
    }
  }

  menuc: system("cls");
  gotoxy(32, 1);
  printf("HOSPITAL    : AKBABEL ");
  gotoxy(73, 2);
  printf("MEKNES,MAROC ");
  gotoxy(10, 5);
  printf("Bonjour  %s", user);
  drawRectangle();
  time( & rawtime);
  timeinfo = localtime( & rawtime);
  gotoxy(10, 6);
  printf("heure et date actuelles : %s", asctime(timeinfo));

  hereco: gotoxy(4, 10);
  printf("CONSULTATION");
  MENUc();

  bouclec:

    while (bouclec != 99) {
      gotoxy(3, valc);
      bouclec = _getch();
      switch (bouclec) {
      case KEY_UP:
        valc = CHOIXC(valc, 1, theme);
        break;
      case KEY_DOWN:
        valc = CHOIXC(valc, 2, theme);
        break;
      case KEY_ENTER:
        goto encorec;
        break;
      }
    }
  encorec:

    choixc = valc;
  while (choixc != 99) {
    switch (choixc) {

    case 12:
      clearS();
      print("INITIALISATION");
      listc = initialiserc(listc);
      gotoxy(46, 12);
      printf("Liste initialis%ce  ", 130);
      gotoxy(43, 16);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto hereco;
      break;

    case 13:
      ajtc:
        clearS();
      print(" AJOUT ");
      gotoxy(46, 12);
      printf("1 :ajoute en tete ");
      gotoxy(46, 13);
      printf("2 :ajoute en fin ");
      gotoxy(46, 14);
      printf("entrez votre choix : ");
      scanf("%d", & zc);
      clearS();
      if (zc == 1) {
        clearS();
        listc = ajouter_entetec(listc, listp, listm);
        gotoxy(52, 20);
        printf("consulation ajout%ce", 130);
        gotoxy(42, 21);
        printf("cliquer sur une touche pour retourner au menu ");
        _getch();
        clearS();
        goto hereco;
        break;
      }
      if (zc == 2) {
        clearS();
        listc = ajouter_enfinc(listc, listp, listm);
        gotoxy(52, 20);
        printf("Reference ajout%ce", 130);
        gotoxy(42, 21);
        printf("cliquer sur une touche pour retourner au menu ");
        _getch();
        clearS();
        goto hereco;
        break;
      } else {
        gotoxy(46, 14);
        printf("entrez un valide choix choix ");
        goto ajtc;
      }

    case 14:
      clearS();
      print("AFFICHAGE");
      affichagec(listc);
      goto hereco;
      break;

    case 15:
      clearS();
      print("RECHERCHE");
      rechercher_consultation(listc);
      gotoxy(38, 23);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      goto hereco;
      break;

    case 16:
      supcc: clearS();
      print("SUPPRESSION");

      listc = suppRc(listc);
      if (listc == NULL) goto hereco;
      gotoxy(38, 20);
      printf("Supprimer une autre consultation ?(Y/N) ");
      yc = _getch();
      if (yc == 'Y' || yc == 'y') goto supcc;
      else {
        goto hereco;
        break;
      }

      break;

    case 17:
      clearS();
      print("MODIFICATION");
      listc = modifierc(listc, listp, listm);
      gotoxy(52, 21);
      printf("liste est modifi%ce (^-^)", 130);
      gotoxy(43, 15);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto hereco;
      break;
    case 18:
      clearS();
      print("ENREGISTREMENT");
      enregistrerc(listc);
      gotoxy(52, 15);
      printf("liste enregistr%ce (^-^)", 130);
      gotoxy(43, 16);
      printf("cliquez sur une touche pour retourner au menu ");
      _getch();
      goto hereco;
      break;

    case 19:
      clearS();
      print("CHARGEMENT");
      listc = chargerc(listc);
      gotoxy(43, 19);
      printf("cliquez sur une touche pour retourner au menu ");
      _getch();
      goto hereco;
      break;
    case 20:
      clearS();
      initialiserfichierc();
      gotoxy(43, 19);
      printf("cliquer sur une touche pour retourner au menu ");
      _getch();
      clearS();
      goto hereco;
      break;

    case 21:
      clearS();
      system("cls");
      goto herec;
      break;
    default:
      gotoxy(2, 24);
      printf("Choix non valide !! ");
      Sleep(333);
      gotoxy(2, 24);
      printf("                     ");
      break;
    }
  }
}

//==================LOGIN=======================//

void login(char user[], int theme) {
  char * password = (char * ) malloc(sizeof(char));
  password = "naruto";
  int f = 0, i = 0, a;
  char pass[10];
  passe:
    char motp[] = "passeword.txt";
  i = 0;
  FILE * fichierp = fopen(motp, "r");
  if (fichierp != NULL) {
    free(password);
    password = (char * ) malloc(sizeof(char));
    fscanf(fichierp, "%s", password);
    fclose(fichierp);
  } else

    i = 0;
  gotoxy(62, 16);
  do {
    pass[i] = _getch();
    if (pass[i] == 8) {
      printf("\b");
      i = i - 2;
    }
    if (pass[i] != '\r' && pass[i + 2] != 8) {
      printf("*");
    }
    i++;
  } while (pass[i - 1] != '\r');
  pass[i - 1] = '\0';
  gotoxy(48, 20);
  if (strcmp(password, pass) == 0) {
    printf("Mot de passe correct!");
    gotoxy(48, 21);
    printf("Chargement");
    for (i = 0; i <= 6; i++) {
      Sleep(100);
      printf(".");
    }
    system("cls");
    MENUPRI(user, theme);
  } else {
    printf("Mot de passe incorrect!!\a");
    login_try:
      gotoxy(48, 21);
    printf("Entrez 1 pour ressayer ou 0 pour sortir:");
    scanf("%d", & a);
    if (a == 1) {
      gotoxy(48, 20);
      printf("                                      ");
      gotoxy(48, 21);
      printf("                                          ");
      gotoxy(60, 16);
      printf("                              ");
      goto passe;
    } else if (a == 0) {
      system("cls");
      return;
    } else {
      gotoxy(48, 22);
      printf("Invalid!");
      Sleep(90);
      gotoxy(48, 22);
      printf("         ");
      gotoxy(88, 21);
      printf(" ");
      Sleep(100);
      gotoxy(60, 16);
      printf("                              ");
      goto login_try;
    }
  }
}
//=================================================
void changepass(char user[], int theme) {
  char password[20];
  int ym, i;
  char motp[] = "passeword.txt";
  gotoxy(43, 14);
  printf("Voulez vous changer le mot de pasee ?(Y/N)? ");
  ym = _getch();
  if (ym == 'Y' || ym == 'y') {
    remove(motp);
    FILE * fichierp = fopen(motp, "a+");
    gotoxy(50, 17);
    printf("new passeword :");
    scanf("%s", password);
    fprintf(fichierp, "%s", password);
    fclose(fichierp);
    gotoxy(50, 21);
    printf("please wait");
    for (i = 0; i <= 6; i++) {
      Sleep(100);
      printf(".");
    }
    system("cls");
    MENUPRI(user, theme);
  } else
    system("cls");
  MENUPRI(user, theme);

}
//=================================================
void instruction(int theme) {
  WORD Attributes = 0;
  if (theme == 1) {
    ClearConsoleToColors(0, WHITE);

    gotoxy(25, 25);
    SetConsoleColour( & Attributes, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
    printf("Utiliser les touches         pour deplacer le curseur ");
    ResetConsoleColour(Attributes);
    gotoxy(46, 25);
    printf("Up Down");
    ResetConsoleColour(Attributes);
    gotoxy(25, 26);
    SetConsoleColour( & Attributes, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
    printf("Utiliser la touche           pour executer votre choix");
    ResetConsoleColour(Attributes);
    gotoxy(46, 26);
    printf("Entree ");
    ResetConsoleColour(Attributes);
  }

  if (theme == 2) {
    ClearConsoleToColors(WHITE, 0);
    gotoxy(25, 25);
    SetConsoleColour( & Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
    printf("Utiliser les touches         pour deplacer le curseur ");
    ResetConsoleColour(Attributes);
    gotoxy(46, 25);
    printf("Up Down");
    ResetConsoleColour(Attributes);
    gotoxy(25, 26);
    SetConsoleColour( & Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
    printf("Utiliser la touche           pour executer votre choix");
    ResetConsoleColour(Attributes);
    gotoxy(46, 26);
    printf("Entree ");
    ResetConsoleColour(Attributes);
  }
}
//================================================= //

int mode_switch() {
  int i, theme = 1, val = 10;
  ClearConsoleToColors(0, WHITE);
  instruction(theme);
  theme:
    for (i = 25; i < 74; i++) {
      gotoxy(i, 8);
      printf("%c", 176);
    }

  for (i = 8; i < 14; i++) {
    gotoxy(25, i);
    printf("%c", 176);
  }

  for (i = 25; i < 74; i++) {
    gotoxy(i, 14);
    printf("%c", 176);
  }

  for (i = 8; i < 15; i++) {
    gotoxy(74, i);
    printf("%c", 176);
  }

  for (i = 24; i < 80; i++) {
    gotoxy(i, 24);
    printf("%c", 176);
  }
  for (i = 24; i < 28; i++) {
    gotoxy(24, i);
    printf("%c", 176);
  }
  for (i = 24; i < 28; i++) {
    gotoxy(79, i);
    printf("%c", 176);
  }
  for (i = 24; i < 80; i++) {
    gotoxy(i, 27);
    printf("%c", 176);
  }
  gotoxy(30, 10);
  printf("choisissez votre theme :  ");
  gotoxy(56, 10);
  printf("Normal theme");
  gotoxy(56, 12);
  printf("Dark theme");

  while (theme != 99) {
    boucleTheme: gotoxy(54, val);theme = _getch();
    switch (theme) {

    case KEY_UP:
      if (val == 10) {
        val = 12;
        gotoxy(56, val);
        theme = 2;
        ClearConsoleToColors(WHITE, 0);
        instruction(theme);
        goto boucleTheme;
      }
      if (val == 12) {
        val = 10;
        gotoxy(56, val);
        theme = 1;
        ClearConsoleToColors(0, WHITE);
        instruction(theme);
        goto boucleTheme;
      }
      break;
    case KEY_DOWN:
      if (val == 10) {
        val = 12;
        gotoxy(56, val);
        theme = 2;
        ClearConsoleToColors(WHITE, 0);
        instruction(theme);
        goto boucleTheme;
      }
      if (val == 12) {
        val = 10;
        gotoxy(56, val);
        theme = 1;
        ClearConsoleToColors(0, WHITE);
        instruction(theme);
        goto boucleTheme;
      }
      break;
    case KEY_ENTER:
      goto finBoucle;
      break;
    }
  }
  finBoucle:
    if (theme == 1) {
      ClearConsoleToColors(0, WHITE);
      instruction(theme);
      goto finBoucle;
    }
  if (theme == 2) {
    ClearConsoleToColors(WHITE, 0);
    instruction(theme);
    goto finBoucle;
  }
  system("cls");
  return theme;
}

//========================MAIN============================================

main() {
  int theme;
  char user[20];
  SetConsoleTitle("Gestion de AKBABEL");
  //printMsg();
  theme = mode_switch();
  drawRectanglelogin();
  gotoxy(62, 14);
  scanf("%s", user);
  login(user, theme);
}