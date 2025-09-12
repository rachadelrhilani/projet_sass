#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 100
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"
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

//-----------------------------------------------initialisation -----------------------------------------------

void initialiserjoueurs() {
    joueurs[0] = (joueur){1, "Messi", "Lionel", "10", "attaquant", "36", 20};
    joueurs[1] = (joueur){2, "Ronaldo", "Cristiano", "7", "attaquant", "38", 25};
    joueurs[2] = (joueur){3, "Neymar", "Junior", "11", "attaquant", "32", 15};
    joueurs[3] = (joueur){4, "Mbappe", "Kylian", "7", "attaquant", "25", 30};  
    joueurs[4] = (joueur){5, "Modric", "Luka", "10", "milieu", "38", 10};
    joueurs[5] = (joueur){6, "Kante", "Ngolo", "13", "milieu", "34", 5};
    joueurs[6] = (joueur){7, "Ramos", "Sergio", "4", "defenseur", "39", 8};
    joueurs[7] = (joueur){8, "Pique", "Gerard", "3", "defenseur", "37", 3};
    joueurs[8] = (joueur){9, "Neuer", "Manuel", "1", "gardien", "38", 0};
    joueurs[9] = (joueur){10, "Hakimi", "Achraf", "2", "defenseur", "26", 12};

    nbrjoueur = 10;   // car on a rempli 10 joueurs
    auto_id = 11;     // le prochain joueur aura l'id = 11
}
//-----------------------------------------------Validation -----------------------------------------------

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
        return 0; // invalid
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
	//(gardien, defenseur, milieu, attaquant).
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
int validerbut(int but, int check) {
    if (check == 0) {
     while (getchar() != '\n');
       return 0;  
    } 
   
    if (but < 0) {
            return 0;  
    }
    return 1;  
}


//-----------------------------------------------les fonctions -----------------------------------------------

//choix ajoutersimple
void ajoutersimple(){
	
    if(nbrjoueur >= max){
        printf(YELLOW"les nombres de joueurs sont plein"RESET);
        return;
    }
    
    joueur j; 
    
    j.id = auto_id++; // incrementation de l'id automatique
    
    int faux = 0;
    
    do{
		if( faux > 0){
			printf(RED"Veuillez entre des caractere\n"RESET);
		}
    	printf("nom: ");
        scanf(" %[^\n]", j.nom);
        
        faux++;
	}while(!(validernom(j.nom)));
	
    faux = 0;
    
    do{
    	if( faux > 0){
			printf(RED"Veuillez entre des caractere\n"RESET);
		}
    	printf("Prenom: ");
        scanf(" %[^\n]", j.prenom);
        faux++;
	}while(!(validernom(j.prenom)));
	
	faux = 0;
	
	do{
		if( faux > 0){
			printf(RED"ton nombre n'est pas (de 1 a 99) ou (il est deja pris)\n"RESET);
		}
    	printf("numero de maillot : ");
        scanf("%s", j.numeroMaillot);
        faux++;
	}while(!(validernumeromaillot(j.numeroMaillot)));
	
	faux = 0;
	
	do{
		if( faux > 0){
			printf(RED"Veuillez entre des caractere\n");
			printf("entre l'un de ses postes (gardien, defenseur, milieu, attaquant)\n"RESET);
		}
    	printf("le Poste de joueur: ");
        scanf(" %[^\n]", j.poste);
        faux++;
	}while(!(validerposte(j.poste)));
	
	faux = 0;
	
	do{
		if( faux > 0){
			printf(RED"Veuillez entre de 15 a 45\n");
		}
    	printf("Age de joueur: ");
        scanf("%s", j.age);
        faux++;
	}while(!(validerage(j.age)));
	
	faux = 0;
	int check = 0;
	do{
	   if( faux > 0){
			printf(RED"Veuillez entre de 0 et plus\n");
	   }
       printf("Nombre de buts : ");
       check = scanf("%d", &j.buts);
       faux++;
    }while(!(validerbut(j.buts, check)));
    

    joueurs[nbrjoueur++] = j;

    printf(GREEN"le joueur ajoute avec sucess !\n"RESET);
    printf("appyuez pour continue .....");
    getchar();getchar();
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
    	system("cls");
    	printf(YELLOW"1_ ajouter simple\n");
        printf("2_ ajouter multiple\n");
        printf("0_Quittre\n"RESET);
        printf("votre choix :");
        scanf("%d",&choix);
        switch(choix){
            case 1:
              ajoutersimple();
              break;
            case 2:
              ajoutermultiple();
              break;
            case 0:
              printf("quitter\n");
              break;
            default:
            	printf("veuillez entre l'un de numero de menu");
        }
    }while(choix !=0);
}


void afficherjoueurs() {
    int choix;
    if (nbrjoueur == 0) {
        printf("aucune joueur dans la liste pour le supprimer\n");
        return;
    }

    do {
    	system("cls");
        printf(YELLOW"\n--- Affichage des joueurs ---\n");
        printf("1. Tri par Nom (ordre alphabitique)\n");
        printf("2. Tri par agee\n");
        printf("3. afficher par poste\n");
        printf("0. retour\n"RESET);
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                // Tri par nom (ordre alphabitique)
                int i,j;
                for (i = 0; i < nbrjoueur; i++) {
                    for (j = 0; j < nbrjoueur - 1; j++) {
                        if (strcmp(joueurs[j].nom, joueurs[j+1].nom) > 0) {
                            joueur temp = joueurs[j];
                            joueurs[j] = joueurs[j+1];
                            joueurs[j+1] = temp;
                        }
                    }
                }
                printf("\n--- Liste des joueurs (tri par Nom) ---\n");
                for (i = 0; i < nbrjoueur; i++) {
                    printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
                        joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
                        joueurs[i].numeroMaillot, joueurs[i].poste,
                        joueurs[i].age, joueurs[i].buts);
                }
                printf("appyuez pour revenir .....");
                getchar();getchar();
                break;
            }

            case 2: {
                // Tri par age
                int i,j;
                for (i = 0; i < nbrjoueur; i++) {
                    for (j = 0; j < nbrjoueur -1 ; j++) {
                    	int age = atoi(joueurs[j].age);
                    	int age_suivant = atoi(joueurs[j+1].age);
                        if (age > age_suivant || age == age_suivant) {
                            joueur temp = joueurs[j];
                            joueurs[j] = joueurs[j+1];
                            joueurs[j+1] = temp;
                        }
                    }
                }
                printf("\n--- Liste des joueurs (tri par age) ---\n");
                for (i = 0; i < nbrjoueur; i++) {
                    printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
                        joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
                        joueurs[i].numeroMaillot, joueurs[i].poste,
                        joueurs[i].age, joueurs[i].buts);
                }
                printf("appyuez pour revenir .....");
                getchar();getchar();
                break;
            }

            case 3: {
                // Afficher par poste
                char recherche[30];
                printf("entrer le poste que tu veux rechercher : ");
                scanf(" %[^\n]", recherche);
                int i;
                printf("\n--- Joueurs au poste : %s ---\n", recherche);
                int trouve = 0;
                for (i = 0; i < nbrjoueur; i++) {
                    if (strcmp(recherche,joueurs[i].poste) == 0) {
                        printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
                               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
                               joueurs[i].numeroMaillot, joueurs[i].poste,
                               joueurs[i].age, joueurs[i].buts);
                        trouve = 1;
                    }
                }
                if (!trouve) {
                    printf("aucun joueur trouve pour ce poste.\n");
                }
                printf("appyuez pour revenir .....");
                getchar();getchar();
                break;
            }

            case 0:
            	printf("retour au menu principal.\n");
                break;
            default:
                printf("ce choix invalide, veuillez saisi des nombres dans le menu.\n");
        }

    } while (choix != 0);
}


void rechercherjoueur() {
    int choix;
    system("cls");
    printf(YELLOW"\n--- recherche de joueur ---\n");
    printf("1. rechercher par ID\n");
    printf("2. rechercher par Nom\n");
    printf("0. rechercher par Nom\n"RESET);
    printf("Votre choix : ");
    scanf("%d", &choix);
    int i;
    if (choix == 1) {
        int id, trouve = 0;
        printf("entre l'id de joueur : ");
        scanf("%d", &id);

        for (i = 0; i < nbrjoueur; i++) {
            if (joueurs[i].id == id) { //comparaison l id avec les autres id dans le tableau
                printf("--- le joueur trouve par id ---\n");
                printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
                               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
                               joueurs[i].numeroMaillot, joueurs[i].poste,
                               joueurs[i].age, joueurs[i].buts);
                trouve = 1;
                break;
            }
        }
        
        if(trouve == 1){
            printf("appyuez pour revenir .....");
            getchar();getchar();	
		}
        
        else if (trouve == 0) {
            printf("aucun joueur ce id %d.\n", id);
			printf("appyuez pour revenir .....");
            getchar();getchar();
        }
    } 
    else if (choix == 2) {
        char nom[30];
        int trouve = 0;
        printf("entre le nom du joueur : ");
        scanf(" %[^\n]", nom);
        
        for (i = 0; i < nbrjoueur; i++) {
            if (strcmp(joueurs[i].nom, nom) == 0) {  //comparaison de nom avec les autres nom dans le tableau
                printf("--- le joueur %s ---\n",joueurs[i].nom);
                printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
                               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
                               joueurs[i].numeroMaillot, joueurs[i].poste,
                               joueurs[i].age, joueurs[i].buts);
                trouve = 1;
                break;
            }
        }
        if(trouve == 1){
            printf("appyuez pour revenir .....");
            getchar();getchar();	
		}
        
        else if (trouve == 0) {
            printf("aucun joueur avec le nom '%s'.\n", nom);
			printf("appyuez pour revenir .....");
            getchar();getchar();
        }
        
    } 
    else {
        printf("ce choix invalide.\n");
        printf("appyuez pour revenir .....");
        getchar();getchar();
    }
}

void statistiques(){
    int choix;
    do {
    system("cls");
    printf(YELLOW"\n--- Menu Statistiques ---\n");
    printf("1. nombre total de joueurs\n");
    printf("2. le moyen d'age des joueurs\n");
    printf("3. joueurs ayant marque plus de X buts\n");
    printf("4. meilleur buteur\n");
    printf("5. joueur le plus jeune et le plus age \n");
    printf("0. Retour\n"RESET);
    printf("Votre choix : ");
    scanf("%d", &choix);
        int i;
        switch (choix) {
            case 1: { // le Nombre total des joueurs
                printf("Nombre total de joueurs : %d\n", nbrjoueur);
                printf("appyuez pour revenir .....");
                getchar();getchar();
                break;
            }
            case 2: { // le moyen d'age
                if (nbrjoueur == 0) {
                    printf("aucun joueur disponible.\n");
                    break;
                }
                int somme = 0;
                
                for (i = 0; i < nbrjoueur; i++) {
                	int age = atoi(joueurs[i].age);
                    somme += age;
                }
                float moyenne = (float)somme / nbrjoueur;
                printf("le moyen d'age' des joueurs : %.2f ans\n", moyenne);
                printf("appyuez pour revenir .....");
                getchar();getchar();
                break;
            }
            case 3: { // joueur marque plus de X buts
                if (nbrjoueur == 0) {
                    printf("aucun joueur disponible.\n");
                    break;
                }
                int x;
                printf("entre le nombre de buts X : ");
                scanf("%d", &x);
                int trouve = 0;
                for (i = 0; i < nbrjoueur; i++) {
                    if (joueurs[i].buts > x) {
                        printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
                               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
                               joueurs[i].numeroMaillot, joueurs[i].poste,
                               joueurs[i].age, joueurs[i].buts);
                        trouve = 1;
                    }
                }
                printf("appyuez pour revenir .....");
                getchar();getchar();
                if (!trouve){
                	printf("aucun joueur avec plus de %d buts.\n", x);
                	printf("appyuez pour revenir .....");
                    getchar();getchar();
				} 
                break;
            }
            case 4: { // le meilleur buteur
                if (nbrjoueur == 0) {
                    printf(" aucun joueur disponible.\n");
                    printf("appyuez pour revenir .....");
                    getchar();getchar();
                }
                int maxIndex = 0;
                for (i = 1; i < nbrjoueur; i++) {
                    if (joueurs[i].buts > joueurs[maxIndex].buts) {
                        maxIndex = i; // recuperation de l'indice de meilleur joueur
                    }
                }
                printf("Meilleur buteur :\n");
                printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
                               joueurs[maxIndex].id,joueurs[maxIndex].nom,joueurs[maxIndex].prenom,
                               joueurs[maxIndex].numeroMaillot, joueurs[maxIndex].poste,
                               joueurs[maxIndex].age, joueurs[maxIndex].buts);
                printf("appyuez pour revenir .....");
                getchar();getchar();
                break;
            }
            case 5: { // le Plus jeune et plus age
                if (nbrjoueur == 0) {
                    printf("aucun joueur disponible..\n");
                    printf("appyuez pour revenir .....");
                    getchar();getchar();
                }
                int minIndex = 0, maxIndex = 0;
                for (i = 1; i < nbrjoueur; i++) {
                	int age = atoi(joueurs[i].age);
                	int age_min = atoi(joueurs[minIndex].age);
                	int age_max = atoi(joueurs[maxIndex].age);
                    if (age < age_min){
                    	minIndex = i;
					} 
                    if (age > age_max){
                    	maxIndex = i;
					} 
                }
                printf("Le joueur le plus jeune :\n");
                printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
                               joueurs[minIndex].id,joueurs[minIndex].nom,joueurs[minIndex].prenom,
                               joueurs[minIndex].numeroMaillot, joueurs[minIndex].poste,
                               joueurs[minIndex].age, joueurs[minIndex].buts);
                printf("Le joueur le plus age :\n");
                printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
                               joueurs[maxIndex].id,joueurs[maxIndex].nom,joueurs[maxIndex].prenom,
                               joueurs[maxIndex].numeroMaillot, joueurs[maxIndex].poste,
                               joueurs[maxIndex].age, joueurs[maxIndex].buts);
                printf("appyuez pour revenir .....");
                getchar();getchar();
                break;
            }
            case 0:
                printf("Retour au menu principal...\n");
                printf("appyuez pour revenir .....");
                getchar();getchar();
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while (choix != 0);
    
}

void supprimerjoueurs(){
	 system("cls");
	if (nbrjoueur == 0) {
        printf(RED"aucune joueur dans la liste pour le supprimer\n"RESET);
        printf("appyuez pour revenir .....");
        getchar();getchar();
    }
	int trouve = 0;
	int i,j;
	int id;
	char confirme[180];
	
	printf("entre l'identifiant que tu veux supprimer : \n");
	scanf("%d",&id);
	printf(YELLOW"voulez vous vraiment supprimer cette joueur (O/N)"RESET);
	scanf("%s",confirme);
	if(strcmp(confirme,"O") == 0 || strcmp(confirme,"o") == 0){
	   for(i = 0; i < nbrjoueur;i++){
		 if(id == joueurs[i].id ){
		    printf("\n ----------- le joueur supprime ----------- \n");
		 	printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
               joueurs[i].numeroMaillot, joueurs[i].poste,
               joueurs[i].age, joueurs[i].buts);
		 	for(j = i+1; j <= nbrjoueur - 1;j++){
		 	joueurs[i] = joueurs[j];
			 trouve = 1;	
			}
		 }
	   }
	   nbrjoueur--;
	   printf(GREEN"supprimer avec sucess\n"RESET);
	   printf("appyuez pour revenir .....");
       getchar();getchar();
	}
	else{
		printf("suppression annuler");
		printf("appyuez pour revenir .....");
        getchar();getchar();
		trouve = 1;
	}
	if(trouve == 0){
		printf("aucune joueur avec ce identifiant");
		printf("appyuez pour revenir .....");
        getchar();getchar();
	}
}


void modifierjoueurs(){
	system("cls");
	if (nbrjoueur == 0) {
        printf(RED"aucune joueur dans la liste pour le supprimer\n"RESET);
        printf("appyuez pour revenir .....");
        getchar();getchar();
    }
    int choix;
    do{
	printf(YELLOW"\n--- Menu de modification ---\n");
	printf("0. Quitter.\n");
    printf("1. Modifier le poste d un joueur.\n");
    printf("2. Modifier l age d un joueur. \n");
    printf("3. Modifier le nombre de buts marques par un joueur. \n"RESET);
	printf("Votre choix : ");
    scanf("%d", &choix);
	int trouve = 0;
	int i;
	int id;
	switch(choix){
		case 0:
			printf("retour au menu principale\n");
			printf("appyuez pour revenir .....");
            getchar();getchar();
            system("cls");
			break;
		case 1:
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
            int faux = 0;
            do{
		      if( faux > 0){
			     printf(RED"Veuillez entre des caractere\n");
			     printf("entre l'un de ses postes (gardien, defenseur, milieu, attaquant)\n"RESET);
		      }
    	    printf("le Poste de joueur: ");
            scanf(" %s", poste);
            faux++;
	        }while(!(validerposte(poste)));

	        strcpy(joueurs[i].poste,poste);// modifier le poste
	        printf(GREEN"modifier avec sucess\n"RESET);
	        }
		} 
		if(trouve == 0){
		    printf(RED"aucune joueur avec ce identifiant\n"RESET);
		    printf("appyuez pour revenir .....");
            getchar();getchar();
	    } 
	      printf("appyuez pour revenir .....");
            getchar();getchar();
	      break;
	    case 2:
		  printf("entre l'identifiant que tu veux modifier :");
	      scanf("%d",&id);
	      for(i = 0; i < nbrjoueur;i++){
	        if(id == joueurs[i].id ){
			trouve = 1;
			printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
               joueurs[i].numeroMaillot, joueurs[i].poste,
               joueurs[i].age, joueurs[i].buts);
            char age[30];
            int faux = 0;
	
	         do{
		      if( faux > 0){
			     printf(RED"Veuillez entre des caractere\n"RESET);
		      }
    	      printf("l'age de joueur: ");
              scanf("%s", age);
               faux++;
	         }while(!(validerage(age)));
	         strcpy(joueurs[i].age,age);  // modifier l'age
	         printf(GREEN"modifier avec sucess\n"RESET);
            }
          }
          if(trouve == 0){
		    printf(RED"aucune joueur avec ce identifiant"RESET);
		    printf("appyuez pour revenir .....");
            getchar();getchar();
	      }
	      printf("appyuez pour revenir .....");
          getchar();getchar();
	      break;
	    case 3:
		  printf("entre l'identifiant que tu veux modifier :");
	      scanf("%d",&id);
	      for(i = 0; i < nbrjoueur;i++){
	        if(id == joueurs[i].id ){
			trouve = 1;
			printf("id: %d |nom: %s | prenom: %s | maillot: %s | poste: %s | age: %s | buts: %d\n",
               joueurs[i].id,joueurs[i].nom,joueurs[i].prenom,
               joueurs[i].numeroMaillot, joueurs[i].poste,
               joueurs[i].age, joueurs[i].buts);
            int buts;
            int faux = 0;
	        int check = 0;
	        do{
		       if( faux > 0){
			      printf("Veuillez entre des caractere\n");
		       }
    	       printf("les buts de joueur: ");
               check = scanf("%d",&buts);
               faux++;
	        }while(!(validerbut(buts , check)));
	          joueurs[i].buts = buts;    // modifier les buts
	          printf(GREEN"modifier avec sucess\n"RESET);
            }
          }
          if(trouve == 0){
		    printf(RED"aucune joueur avec ce identifiant"RESET);
		    printf("appyuez pour revenir .....");
            getchar();getchar();
	      }
	      printf("appyuez pour revenir .....");
          getchar();getchar();
	      break;
	    default: printf(" veuillez entre l'un des nombres dans le menu  .\n");
	}
	}while(choix != 0);
}
int main(){
    int choix;
    initialiserjoueurs();
    do {
    	system("cls");
        printf(YELLOW"\n===== MENU PRINCIPAL =====\n");
        printf("1. ajouter des joueurs\n");
        printf("2. afficher les joueurs\n");
        printf("3. recherche les joueurs\n");
        printf("4. supprimer les joueurs\n");
        printf("5. modifier les joueurs\n");
        printf("6. les statistiques\n");
        printf("0. Quitter\n"RESET);
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterjoueur(); break;
            case 2: afficherjoueurs(); break;
            case 3: rechercherjoueur(); break;
            case 4: supprimerjoueurs(); break;
            case 5: modifierjoueurs(); break;
            case 6: statistiques(); break;
            case 0: printf("Quitter ....."); break;
            default: printf(" veuillez entre l'un des nombres dans le menu  .\n");
        }
    } while (choix != 0);
    return 0;
}
