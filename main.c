#include <stdio.h>
#include <mem.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * General functions
 */

struct client
{
    char id[10];
    char nom[50];
    char prenom[50];
    char profession[50];
    char numero[11];
};

struct compte
{
    char id[10];
    char proprietaire[10];
    double solde;
    double taux;
    int dureeMinimale;
};

void setIDClient(char *s, char *nom, char *prenom) {

    strncat(s, nom, 3);
}

typedef struct client Client;
typedef struct compte Compte;
void menu(), gestionClient(), gestionCompte(), gestionOperation();

void header() {
    printf("\n------------------\n--- C for Bank ---\n------------------\n\n");
}

/*
 * Fonctions gestion clienteles
 */

void ajouterClient() {

    int choix = 0;

        Client client;

        header();
        printf("--- Ajouter un client\n");
        printf("--------\n");
        printf("Saisir le nom : \n");
        scanf("%s", client.nom);
        printf("Saisir le prenom : \n");
        scanf("%s", client.prenom);
        printf("Saisir la profession : \n");
        scanf("%s", client.profession);
        printf("Saisir le numero de telephone (format: 0102030405) : \n");
        scanf("%s", client.numero);

        strncpy(client.id, client.prenom, 3);
        strncpy(client.id, client.nom, 3);

        printf("\n\nLe client : %s %s %s, Profession : %s, Numero tel : %s a ete ajoute"
                       "\n\nProchaine etape?\n---\n0. Client menu,\n1. Main menu\n",
               client.id, client.nom, client.prenom, client.profession, client.numero);

        printf("Votre choix : \n");

        scanf("%d", &choix);


        if(choix == 0)
            gestionClient();
        else if(choix == 1)
            menu();


}



void  modifierClient(/*Client rep[], int nb*/) {

    Client client;

    header();
    printf("--- Modifier un client\n");
    printf("--------\n");
    printf("Saisir l'identifiant du client : \n");
    scanf("%s", client.id);
}

void supprimerClient() {
    header();
    printf("--- Supprimer un client\n");
    printf("--------\n");
    printf("Faites un choix : \n");
}

void  rechercherClient() {
    header();
    printf("--- Rechercher un client\n");
    printf("--------\n");
    printf("Faites un choix : \n");


}

void gestionClient() {
    char choix = 0;
    while(choix != '1' && choix != '2' && choix != '3' && choix != '4'){
        header();
        printf("--- Gestion clientele\n");
        printf("--------\n");
        printf("Faites un choix : \n");
        printf("1. Ajouter un client,\n");
        printf("2. Modifier un client,\n");
        printf("3. Supprimer un client\n");
        printf("4. Rechercher un client\n");
        printf("Q. Quitter\n");

        scanf("%c", &choix);

        switch (choix) {
            case '1' :
                ajouterClient();
                break;
            case '2' :
                modifierClient();
                break;
            case '3' :
                supprimerClient();
                break;
            case '4' :
                rechercherClient();
                break;
            case 'Q' :
                menu();
                break;
            case 'q' :
                menu();
                break;
            default:
                break;
        }
    }
}

/*
 * Fonctions gestion des comptes
 */

void ajouterCompte() {

    Client client;

    header();
    printf("--- Ajouter un client\n");
    printf("--------\n\n");
    printf("Saisir le nom : \n");
    scanf("%s", client.nom);
    printf("Saisir le prenom : \n");
    scanf("%s", client.prenom);
    printf("Saisir la proffession : \n");
    scanf("%s", client.profession);
    printf("Saisir le numero de telephone (format: 0102030405) : \n");
    scanf("%s", client.numero);

    printf("ID : %s Client : %s %s, prof : %s, tel : %s", client.nom, client.prenom, client.profession, client.numero);
}

void  consulterCompte() {
    header();
    printf("--- Modifier un client\n");
    printf("--------\n");
    printf("Faites un choix : \n");
}

void fermerCompte(){
    header();
    printf("--- Supprimer un client\n");
    printf("--------\n");
    printf("Faites un choix : \n");
}

void gestionCompte() {
    char choix = 0;
    while(choix != '1' && choix != '2' && choix != '3' && choix != '4'){
        header();
        printf("--- Gestion des comptes\n");
        printf("--------\n");
        printf("Faites un choix : \n");
        printf("1. Creer un compte,\n");
        printf("2. Consulter un compte,\n");
        printf("3. Fermer un compte\n");
        printf("Q. Quitter\n");

        scanf("%c", &choix);

        switch (choix) {
            case '1' :
                ajouterCompte();
                break;
            case '2' :
                consulterCompte();
                break;
            case '3' :
                fermerCompte();
                break;
            case 'Q' :
                menu();
                break;
            case 'q' :
                menu();
                break;
            default:
                printf("Le choix n'a pas ete reconnu\n\n");
                break;
        }
    }
}

/*
 * Fonctions gestion des opérations
 */

void effectuerDepot() {
    header();
    printf("--- Ajouter un client\n");
    printf("--------\n");
    printf("Faites un choix : \n");
}

void  effectuerRetrait() {
    header();
    printf("--- Modifier un client\n");
    printf("--------\n");
    printf("Faites un choix : \n");
}

void effectuerVirement(){
    header();
    printf("--- Supprimer un client\n");
    printf("--------\n");
    printf("Faites un choix : \n");
}

void gestionOperation() {
    char choix = 0;
    while(choix != '1' && choix != '2' && choix != '3'){
        header();
        printf("--- Gestion des operations\n");
        printf("--------\n");
        printf("Faites un choix : \n");
        printf("1. Effectuer une depot,\n");
        printf("2. Effectuer un retrait,\n");
        printf("3. Effectuer un virement vers un compte\n");
        printf("Q. Quitter\n");

        scanf("%c", &choix);

        switch (choix) {
            case '1' :
                effectuerDepot();
                break;
            case '2' :
                effectuerRetrait();
                break;
            case '3' :
                effectuerVirement();
                break;
            case 'Q' :
                menu();
                break;
            case 'q' :
                menu();
                break;
            default:
                printf("Le choix n'a pas ete reconnu\n\n");
                break;
        }
    }
}

/*
 * Menu d'accueil
 */

void menu() {
    char choix = 0;
    while(choix != '1' && choix != '2' && choix != '3'){
        header();
        printf("--- Menu\n");
        printf("--------\n");
        printf("Faites un choix : \n");
        printf("1. Gestion clientele,\n");
        printf("2. Gestion des comptes,\n");
        printf("3. Gestion des operation\n");
        printf("Q. Quitter\n");

        scanf("%c", &choix);

        switch (choix) {
            case '1' :
                gestionClient();
                break;
            case '2' :
                gestionCompte();
                break;
            case '3' :
                gestionOperation();
                break;
            default:
                break;
        }
    }
}

int main() {

    menu();
    return 0;

}