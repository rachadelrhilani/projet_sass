#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 100
/* projet de saas  */
typedef struct joueur{
    int id;
    char nom[30];
    char prenom[30];
    char numeroMaillot[30];
    char poste[30];
    char age[30];
    int buts;
}joueur;

joueur joueurs[max];

int nbrjoueur = 0;
int auto_id = 1; // initialisation de l'id

// valide nom
int validernom(char chaine[]) {
	int i;
	
	if (chaine == NULL || chaine[0] == '\0') {
        return 0;
    }
    
	int lennom = strlen(chaine);
	if(!(lennom >= 3)){
		return 0; 
	}
    for (i = 0; i < strlen(chaine); i++) {
        if (!((chaine[i] >= 'A' && chaine[i] <= 'Z') || (chaine[i] >= 'a' && chaine[i] <= 'z') || chaine[i] == ' ')){
        	return 0; 
		}
    }
    return 1; 
}

// valide numero maillot
int validernumeromaillot(char numero[]) {
	
	if (numero == NULL || numero[0] == '\0') {
        return 0;
    }
    int i;
    
    int num = atoi(numero);
    if (!(num >= 1 && num <= 99)) {
        return 0; // valide
    }
	// verifier si le numero de maillot est deja utiliser
    for ( i = 0; i < nbrjoueur; i++) {
        if (strcmp(numero,joueurs[i].numeroMaillot) == 0) {
            return 0; 
        }
    }
    return 1;
}

// valide de poste
int validerposte(char chaine[]) {
	int i;
	
	int lenposte = strlen(chaine);
	if(!(lenposte >= 6)){
		return 0; 
	}
	
	for (i = 0; i < strlen(chaine); i++) {
        chaine[i] = tolower(chaine[i]);
    }
	//(gardien, défenseur, milieu, attaquant).
	if(!(strcmp("gardien",chaine)==0||strcmp("defenseur",chaine)==0||strcmp("milieu",chaine)==0||strcmp("attaquant",chaine)==0)){
		return 0;
	}
    
    for (i = 0; i < strlen(chaine); i++) {
        if (!((chaine[i] >= 'A' && chaine[i] <= 'Z') || (chaine[i] >= 'a' && chaine[i] <= 'z') || chaine[i] == ' ')){
        	return 0;
		}
    }
    return 1;
}

// valide age
int validerage(char age[]) {
	if (age == NULL || age[0] == '\0') {
        return 0;
    }
    
    
	int num = atoi(age);
    if (!(num >= 15 && num <= 45)) {
        return 0; // valide
    }
    return 1;
}

// valide but
int validerbut(int but) {
    if (!(but >= 0) ){
        return 0; // valide
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
        scanf("%s", j.numeroMaillot);
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
			printf("n'entre pas des lettre\n");
		}
    	printf("Age de joueur: ");
        scanf("%s", j.age);
        faux++;
	}while(!(validerage(j.age)));
	
	faux = 0;
	
	do{
	   if( faux > 0){
			printf("Veuillez entre de 0 et plus\n");
			printf("n'entre pas des lettre\n");
	   }
       printf("Nombre de buts : ");
       scanf("%d", &j.buts);
       faux++;
    }while(!(validerbut(j.buts)));
    

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
        printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
               joueurs[i].numeroMaillot, joueurs[i].poste,
               joueurs[i].age, joueurs[i].buts);
    }
}

void supprimerjoueurs(){
	if (nbrjoueur == 0) {
        printf("aucune joueur dans la liste pour le supprimer\n");
        return;
    }
	int trouve = 0;
	int i;
	int id;
	char confirme[180];
	
	printf("entre l'identifiant que tu veux supprimer : \n");
	scanf("%d",&id);
	printf("voulez vous vraiment supprimer cette joueur (O/N)");
	scanf("%s",confirme);
	if(strcmp(confirme,"O") == 0 || strcmp(confirme,"o") == 0){
	   for(i = 0; i < nbrjoueur;i++){
		 if(id == joueurs[i].id ){
			joueurs[i] = joueurs[i+1];
			trouve = 1;
			printf("supprimer avec sucess");
		 }
	   }
	  nbrjoueur--;
	}
	else{
		printf("suppression annuler");
		trouve = 1;
	}
	if(trouve == 0){
		printf("aucune joueur avec ce identifiant");
	}
}

void modifierjoueurs(){
	if (nbrjoueur == 0) {
        printf("aucune joueur dans la liste pour le supprimer\n");
        return;
    }
	int trouve = 0;
	int i;
	int id;
	printf("entre l'identifiant que tu veux modifier :");
	scanf("%d",&id);
	for(i = 0; i < nbrjoueur;i++){
	   if(id == joueurs[i].id ){
			trouve = 1;
			printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
               joueurs[i].numeroMaillot, joueurs[i].poste,
               joueurs[i].age, joueurs[i].buts);
            char poste[30];
            char age[30];
            int buts;
            int faux = 0;
	
	    do{
		    if( faux > 0){
			 printf("Veuillez entre des caractere\n");
		    }
    	    printf("le Poste de joueur: ");
            scanf(" %s", poste);
            faux++;
	    }while(!(validerposte(poste)));
	    
	    strcpy(joueurs[i].poste,poste); // modifier le poste
	    faux = 0;
	
	    do{
		    if( faux > 0){
			printf("Veuillez entre des caractere\n");
		    }
    	    printf("l'age de joueur: ");
            scanf("%s", age);
            faux++;
	    }while(!(validerage(age)));
	    
	    strcpy(joueurs[i].age,age);  // modifier l'age
	    faux = 0;
	    do{
		    if( faux > 0){
			printf("Veuillez entre des caractere\n");
		    }
    	    printf("le Poste de joueur: ");
            scanf("%d",&buts);
            faux++;
	    }while(!(validerbut(buts)));
	    joueurs[i].buts = buts;    // modifier les buts
			printf("modifier avec sucess");
		}
	}
	if(trouve == 0){
		printf("aucune joueur avec ce identifiant");
	}
}
int main(){
    int choix;
    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. ajouter des joueurs\n");
        printf("2. afficher les joueurs\n");
        printf("3. supprimer les joueurs\n");
        printf("4. modifier les joueurs\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterjoueur(); break;
            case 2: afficherjoueurs(); break;
            case 3: supprimerjoueurs(); break;
            case 4: modifierjoueurs(); break;
            case 0: printf(" fin de programme \n"); break;
            default: printf(" veuillez entre l'un des nombres dans le menu  .\n");
        }
    } while (choix != 0);
    return 0;
}
