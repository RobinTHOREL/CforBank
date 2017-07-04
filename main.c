#include <stdio.h>
struct client
{
    char nom[50];
    char prenom[50];
    char profession[50];
    char numero[11];
};

typedef struct client Client;

void ajouter_client(Client *c);
void  modifier_client(Client rep[], int nb);
int main() {
    printf("--- C for Bank\n");
    printf("--------\n");
    printf("--- Menu\n");
    printf("--------\n");
    printf("Faites un choix : \n");
    printf("1. Gestion clientele,\n");
    printf("2. Gestion des comptes,\n");
    printf("3. Gestion des operation\n");
    return 0;
}