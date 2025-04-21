/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Déclarations des fonctions
void pageacceuil(int *score);//Avec(int *score), on travaille sur l’adresse mémoire du score 
void addition(int *score);
void multiplication(int *score);
void soustraction(int *score);
void tablemultiplication(int *score);
void divisions_(int *score);
void mesures_longueur(int *score);
void mesures_masse(int *score);
void mesures_aires(int *score);
void exercice_geometrie(int *score);
void exo_argent(int *score);
void recuperer_score(char *nom, int *score);
void ecrire_score(char *nom, int score);

// FONCTION PRINCIPALE 
int main() {
    char nom[100];
    int score = 0;

    srand(time(NULL));  // Initialisation de rand()

    recuperer_score(nom, &score);
    printf("Votre score actuel est : %d\n", score);

    pageacceuil(&score);

    ecrire_score(nom, score);
    return 0;
}

//  MENU PRINCIPAL 
void pageacceuil(int *score) {
    int choix;

    do {
        printf("\n+-----------------------------------+\n");
        printf("| 1 : Addition                        |\n");
        printf("| 2 : Soustraction                    |\n");
        printf("| 3 : Multiplication                  |\n");
        printf("| 4 : Tables des multiplications      |\n");
        printf("| 5 : Divisions                       |\n");
        printf("| 6 : Mesures de longueur             |\n");
        printf("| 7 : Mesures de masses               |\n");
        printf("| 8 : Mesures des aires               |\n");
        printf("| 9 : exercices de geometrie          |\n");
        printf("| 10: exercices argent                |\n");
        printf("| 0 : Sortir du jeu                   |\n");
        printf("+-------------------------------------+\n");
        printf("Quel est votre choix ? ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: addition(score); break;
            case 2: soustraction(score); break;
            case 3: multiplication(score); break;
            case 4: tablemultiplication(score); break;
            case 5: divisions_(score); break;
            case 6: mesures_longueur(score); break;
            case 7: mesures_masse(score);break;
            case 8:mesures_aires(score);break;
            case 9:exercice_geometrie(score);break;
            case 10:exo_argent(score);break;
            case 0: printf("Merci de votre visite !\n"); break;
            default: printf("Choix invalide. Essayez encore.\n"); break;
        }
    } while (choix != 0);
}
// fonction pour les tentatives et compter les points
void reponsessai(int a, int b, char operation, int resultat, int *score) {
    int reponse, tentatives = 0, points = 0;
    printf("\n%d %c %d = ?\n", a, operation , b);
    while (tentatives < 3) {
        printf("Tentative %d : ", tentatives + 1);
        scanf("%d", &reponse);

        if (reponse == resultat) {
            if (tentatives == 0) points = 10;
            else if (tentatives == 1) points = 5;
            else points = 1;

            printf("Bravo !\n");
            break;
        } else {
            printf("Incorrect.\n");
            tentatives++;
        }
    }

    if (tentatives == 3) {
        printf("La bonne réponse était : %d\n", resultat);
    }

    *score += points;  // mettre a jour le score globale
    printf("Score actuel : %d\n", *score);
}
// JEU ADDITION 
void addition(int *score) {
    int nb1 = rand() % 101;
    int nb2 = rand() % 101;
    reponsessai(nb1,nb2,'+',nb1+nb2,score);
}

// JEU MULTIPLICATION 
void multiplication(int *score) {
    int nb1 = rand() % 11 + 1;
    int nb2 = rand() % 11 + 1;
    reponsessai(nb1,nb2,'*',nb1*nb2,score);
    }
//  JEU SOUSTRACTION 
void soustraction(int *score) {
    int nb1 = rand() % 101;
    int nb2 = rand() % 101;
    if (nb1 < nb2) { int c = nb1; nb1 = nb2; nb2 = c; }
    reponsessai(nb1,nb2,'-',nb1-nb2,score);
    
}
//  TABLE MULTIPLICATION 
void tablemultiplication(int *score) {
    int table;
    printf("Choisissez une table : ");
    scanf("%d", &table);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", table, i, table * i);
        }
     for (int i = 1; i <= 10; i++) {
         reponsessai(table,i,'*',table*i,score);
        }
    }
// JEU DIVISION 
void divisions_(int *score) {
    int nb1 = rand() % 11 + 1;
    int nb2 = rand() % 10 + 1;
    int resultat =nb1/nb2;
    reponsessai(nb1,nb2,'/',resultat,score);
   }
// jeux supplementaires du site
//fonction pour les resultats de conversion
void conversion(float resultat, int *score) {
    float reponse;
    int tentatives = 0, points = 0;
    
    while (tentatives < 3) {
        printf("Tentative %d : ", tentatives + 1);
        scanf("%f", &reponse);

        if ( reponse == resultat){  
            if (tentatives == 0) points = 10;
            else if (tentatives == 1) points = 5;
            else points = 1;

            printf("Bravo !\n");
            break;
        } else {
            printf("Incorrect.\n");
            tentatives++;
        }
    }

    if (tentatives == 3) {
        printf("La bonne réponse était : %f\n", resultat);
    }

    *score += points;
    printf("Score actuel : %d\n", *score);
}
// jeu de lonngeur
void mesures_longueur(int *score) {
    int choix;
    float valeur,resultat;
    
    printf("\n+---------------------------------------+\n");
    printf("| 1 : Convertir m en cm                   |\n");
    printf("| 2 : Convertir cm en mm                  |\n");
    printf("| 3 : Convertir km en m                   |\n");
    printf("| 4 : Convertir m en k                    |\n");
    printf("+-----------------------------------------+\n");
    printf("Quel type de conversion ? ");
    scanf("%d", &choix);

    valeur = rand() % 100 + 1;  // valeur de base

    switch (choix) {
        case 1:
            printf("Convertir %0.f m en cm ?\n", valeur);
            resultat= valeur * 100;
            conversion(resultat,score);
            break;
        case 2:
            printf("Convertir %0.f cm en mm ?\n", valeur);
            resultat = valeur * 10;
            conversion(resultat,score);
            break;
        case 3:
            printf("Convertir fait %0.f km en m ?\n", valeur);
            resultat = valeur * 1000;
            conversion(resultat,score);
            break;
        case 4:
            valeur = (rand() % 9000) + 1000;  // pour avoir au moins 1000 m
            printf("Cnvertir %0.f m en km\n", valeur);
            resultat = valeur / 1000;
            conversion(resultat,score);
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
}
void mesures_masse(int *score) {
    float resultat,valeur;
    int choix;

    printf("\n+----------------------------------------+\n");
    printf("| 1 : Convertir kilogrammes en grammes     |\n");
    printf("| 2 : Convertir grammes en milligrammes     |\n");
    printf("| 3 : Convertir tonnes en kilogrammes       |\n");
    printf("| 4 : Convertir grammes en kilogrammes      |\n");
    printf("+------------------------------------------+\n");
    printf("Quel type de conversion ? ");
    scanf("%d", &choix);

    valeur = rand() % 100 + 1;

    switch (choix) {
        case 1:
            printf("Convertir %.0f g  en kg ?\n", valeur);
            resultat = valeur * 1000;
            conversion(resultat, score);
            break;

        case 2:
            printf("Convertir %.0f mg en g ?\n", valeur);
            resultat = valeur * 1000;
            conversion(resultat, score);
            break;

        case 3:
            printf("Convertir  %.0f kg en tonnes ?\n", valeur);
            resultat = valeur * 1000;
            conversion(resultat, score);
            break;

        case 4:
            valeur = (rand() % 9000) + 1000;  // au moins 1000g
            printf("Convertir  %.0f kg  en g ? \n", valeur);
            resultat = valeur / 1000;
            conversion(resultat, score);
            break;

        default:
            printf("Choix invalide.\n");
            break;
    }
}
void mesures_aires(int *score) {
    float resultat,valeur;
    int choix;
    printf("\n+----------------------------------------+\n");
    printf("| 1 : Convertir m² en cm²                 |\n");
    printf("| 2 : Convertir cm² en mm²                |\n");
    printf("| 3 : Convertir km² en m²                 |\n");
    printf("| 4 : Convertir m² en km²                 |\n");
    printf("+----------------------------------------+\n");
    printf("Quel type de conversion ? ");
    scanf("%d", &choix);

    valeur = rand() % 100 + 1;

    switch (choix) {
        case 1:
            printf("Convertir %.0f cm² en m² ?\n", valeur);
            resultat = valeur * 10000;
            conversion(resultat, score);
            break;

        case 2:
            printf("Convertir %.0f mm² en cm² ?\n", valeur);
            resultat = valeur * 100;
            conversion(resultat, score);
            break;

        case 3:
            printf("Convertir %.0f m²  en km² ?\n", valeur);
            resultat = valeur * 1000000;
            conversion(resultat, score);
            break;

        case 4:
            valeur = (rand() % 900000) + 100000;  // au moins 100000 m²
            printf("Convertir km² en %0.f m² ? \n", valeur);
            resultat = valeur / 1000000;
            conversion(resultat, score);
            break;

        default:
            printf("Choix invalide.\n");
            break;
    }
}

// RÉCUPÉRER LE SCORE 
void recuperer_score(char *nom, int *score) {
    char ligne[200], nom_lu[100], date[100];
    int score_lu, score_total = 0, trouve = 0;

    printf("Entrez votre nom : ");
    scanf("%s", nom);

    FILE *fichier = fopen("scores.txt", "r");
    if (fichier != NULL) {//lire le fichier ligne par ligne
        while (fgets(ligne, sizeof(ligne), fichier)) {
            if (sscanf(ligne, " %[^,], Date: %[^,], Score: %d", nom_lu, date, &score_lu) == 3) {
                if (strcmp(nom, nom_lu) == 0) {
                    score_total = score_lu;
                    trouve = 1;
                }
            }
        }
        fclose(fichier);
    }
// verifier si l'utilisateur existe deja
    if (trouve) {
        printf("Bienvenue %s, score précédent : %d\n", nom, score_total);
    } else {
        printf("Bienvenue %s, pas de score précédent trouvé.\n", nom);
    }
    *score = score_total; // attribuer le score trouvé
}

// enregistrer mes scores
void ecrire_score(char *nom, int score) {
    FILE *fichier = fopen("scores.txt", "a");  // append au lieu de "w" Le mode "a"  permet d’ajouter des lignes à la fin du fichier, sans effacer les scores précédents. 

//ce mode plutôt que "w"  pour conserver l’historique des tentatives. 
    if (fichier == NULL) {
        printf("Erreur ouverture fichier !\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(fichier, "%s, Date: %d-%02d-%02d %02d:%02d:%02d, Score: %d\n",
            nom,
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec,
            score);

    fclose(fichier);
}
// dautres exercices

void reponse_formule(int resultat, int *score) {
    int reponse, tentatives = 0, points = 0;

    while (tentatives < 3) {
        printf("Tentative %d : ", tentatives + 1);
        scanf("%d", &reponse);

        if (reponse == resultat) {
            if (tentatives == 0) points = 10;
            else if (tentatives == 1) points = 5;
            else points = 1;
            printf("bravo !\n");
            break;
        } else {
            printf("Incorrect.\n");
            tentatives++;
        }
    }

    if (tentatives == 3) {
        printf(" La bonne réponse était : %d\n", resultat);
    }

    *score += points;
    printf("Score actuel : %d\n", *score);
}
// exercice du calcul geometrique
void exercice_geometrie(int *score) {
    int choix, valeur1, valeur2, resultat;

    printf("\n+-------------------------------------------+\n");
    printf("| 1 : Aire d’un carré                        |\n");
    printf("| 2 : Aire d’un rectangle                    |\n");
    printf("| 3 : Périmètre d’un cercle (π ≈ 3)          |\n");
    printf("| 4 : Aire d’un cercle (π ≈ 3)               |\n");
    printf("| 5 : Volume d’une sphère (π ≈ 3)            |\n");
    printf("+-------------------------------------------+\n");
    printf("Quel calcul veux-tu faire ? ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: // carré
            valeur1 = rand() % 20 + 1;
            printf("Côté du carré : %d. Quelle est son aire ?\n", valeur1);
            resultat = valeur1 * valeur1;
            break;

        case 2: // rectangle
            valeur1 = rand() % 20 + 1;
            valeur2 = rand() % 20 + 1;
            printf("Longueur : %d, Largeur : %d. Quelle est l'aire ?\n", valeur1, valeur2);
            resultat = valeur1 * valeur2;
            break;

        case 3: // périmètre cercle
            printf("soit (π ≈ 3)");
            valeur1 = rand() % 20 + 1;
            printf("rayon : %d. Quel est le périmètre du cercle ? (π ≈ 3)\n", valeur1);
            resultat = 2 * 3 * valeur1;
            break;

        case 4: // aire cercle
            printf("soit (π ≈ 3)");
            valeur1 = rand() % 20 + 1;
            printf("rayon : %d. Quelle est l'aire du cercle ? (π ≈ 3)\n", valeur1);
            resultat = 3 * valeur1 * valeur1;
            break;

        case 5: // volume sphère
            printf("soit (π ≈ 3)");
            valeur1 = rand() % 10 + 1;
            printf(" Rayon : %d. Quel est le volume de la sphère ? (π ≈ 3)\n", valeur1);
            resultat = 4 * 3 * valeur1 * valeur1 * valeur1 / 3;
            break;

        default:
            printf("Choix invalide.\n");
            return;
    }

    reponse_formule(resultat, score);
}
// exo 
void exo_argent(int *score) {
    int euros = rand() % 20 + 1;
    int centimes = (rand() % 5) * 10;
    int total = euros * 100 + centimes;

    printf("on a  %d euros et %d centimes. Combien cela fait-il en centimes ?\n", euros, centimes);
    reponse_formule(total, score);
}
