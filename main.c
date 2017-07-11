#include <stdio.h>
#include <mem.h>
#include <stdlib.h>

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

void gen_random(char *s, const int len) {
    int i = 0;
    static const char alphanum[] =
            "0123456789"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";

    for ( ; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
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

    char choix = 'a';
    while (choix != 'r' || choix != 'R' || choix != 'q' || choix != 'Q') {

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

        //gen_random(client.id,10);

        printf("Client : %s %s, prof : %s, tel : %s\n",  client.nom, client.prenom, client.profession, client.numero);

        printf("\n---\nProchaine etape?\n---\nr. Revenir au menu clientele,\nq. Revenir au menu principal \n");

        scanf("%c", &choix);

        switch (choix) {
            case 'R':
                gestionClient();
                break;
            case 'Q':
                menu();
                break;
            case 'r':
                gestionClient();
                break;
            case 'q':
                menu();
                break;
            default:
                break;
        }
    }
}

void  modifierClient(/*Client rep[], int nb*/) {
    header();
    printf("--- Modifier un client\n");
    printf("--------\n");
    printf("Faites un choix : \n");
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

    gen_random(client.id,10);

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