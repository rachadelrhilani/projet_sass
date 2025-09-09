#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
/* projet de saas  */
typedef struct joueur{
    int id;
    char nom[30];
    char prenom[30];
    int numeroMaillot;
    char poste[30];
    int age;
    int buts;
}joueur;

joueur joueurs[max];

int nbrjoueur = 0;
int auto_id = 1; // initialisation de l'id

// valide nom
int validernom(char chaine[]) {
	int i;
    for (i = 0; i < strlen(chaine); i++) {
        if (!((chaine[i] >= 'A' && chaine[i] <= 'Z') || (chaine[i] >= 'a' && chaine[i] <= 'z') || chaine[i] == ' ')){
        	return 0; 
		}
    }
    return 1; 
}

// valide numero maillot
int validernumeromaillot(int numero) {
	if(!(numero >= 1 && numero <= 99)){
		return 0; 
	}
	
	// verifier si le numero de maillot est deja utiliser
	int i;
    for ( i = 0; i < nbrjoueur; i++) {
        if (joueurs[i].numeroMaillot == numero) {
            return 0; 
        }
    }
    return 1;
}

// valide de poste
int validerposte(char chaine[]) {
	int i;
    for (i = 0; i < strlen(chaine); i++) {
        if (!((chaine[i] >= 'A' && chaine[i] <= 'Z') || (chaine[i] >= 'a' && chaine[i] <= 'z') || chaine[i] == ' ')){
        	return 0;
		}
    }
    return 1;
}

// valide age
int validerage(int age) {
	if(!(age >= 15 && age <= 45)){
		return 0; 
	}
    return 1;
}

//choix ajoutersimple
void ajoutersimple(){
    if(nbrjoueur >= max){
        printf("les nombres de joueurs sont plein");
        return;
    }
    
    joueur j; 
    
    j.id = auto_id++; // incrementation de l'id automatique
    
    int faux = 0;
    
    do{
		if( faux > 0){
			printf("Veuillez entre des caractere\n");
		}
    	printf("nom: ");
        scanf(" %[^\n]", j.nom);
        
        faux++;
	}while(!(validernom(j.nom)));
	
    faux = 0;
    
    do{
    	if( faux > 0){
			printf("Veuillez entre des caractere\n");
		}
    	printf("Prenom: ");
        scanf(" %[^\n]", j.prenom);
        faux++;
	}while(!(validernom(j.prenom)));
	
	faux = 0;
	
	do{
		if( faux > 0){
			printf("ton nombre n'est pas (de 1 a 99) ou (il est deja pris)\n");
		}
    	printf("numero de maillot : ");
        scanf("%d", &j.numeroMaillot);
        faux++;
	}while(!(validernumeromaillot(j.numeroMaillot)));
	
	faux = 0;
	
	do{
		if( faux > 0){
			printf("Veuillez entre des caractere\n");
		}
    	printf("le Poste de joueur: ");
        scanf(" %[^\n]", j.poste);
        faux++;
	}while(!(validerposte(j.poste)));
	
	faux = 0;
	
	do{
		if( faux > 0){
			printf("Veuillez entre de 15 a 45\n");
		}
    	printf("Age de joueur: ");
        scanf("%d", &j.age);
        faux++;
	}while(!(validerage(j.age)));
	
	
    printf("Nombre de buts : ");
    scanf("%d", &j.buts);
    
    

    joueurs[nbrjoueur++] = j;

    printf("le joueur ajoute avec sucess !\n");
}

//choix ajoutermultiple
void ajoutermultiple(){
    int n;
    printf("entre le nombre de joueurs que tu veux l'ajouter: ");
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        printf("\n------ajouter du joueur %d er ------\n", i + 1);
        ajoutersimple();
    }
}


void ajouterjoueur(){
    int choix;
    do{
        printf("1_ ajouter simple\n");
        printf("2_ ajouter multiple\n");
        printf("votre choix");
        scanf("%d",&choix);
        switch(choix){
            case 1:
              ajoutersimple();
              break;
            case 2:
              ajoutermultiple();
              break;
            case 3:
              printf("quitter\n");
              break;
        }
    }while(choix !=3);
}


void afficherjoueurs() {
    if (nbrjoueur == 0) {
        printf("aucune joueur dans la liste\n");
        return;
    }
    int i;
    printf("\n-------------- Liste des joueurs --------------\n");
    for (i = 0; i < nbrjoueur; i++) {
        printf("id: %d |nom: %s | prenom: %s | maillot: %d | poste: %s | age: %d | buts: %d\n",
               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
               joueurs[i].numeroMaillot, joueurs[i].poste,
               joueurs[i].age, joueurs[i].buts);
    }
}
int main(){
    int choix;
    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. ajouter des joueurs\n");
        printf("2. afficher les joueurs\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterjoueur(); break;
            case 2: afficherjoueurs(); break;
            case 0: printf(" fin de programme \n"); break;
            default: printf(" veuillez entre l'un des nombres dans le menu  .\n");
        }
    } while (choix != 0);
    return 0;
}
