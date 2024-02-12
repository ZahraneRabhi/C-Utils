#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element{
    int val;
    struct Element *next; 
} Element;

typedef Element *Liste;

void remplirListe(int taille, Liste * liste){
    for (int i = 0; i < taille; i++){
        Liste new = (Element*)malloc(sizeof(Element));
        new -> val = i;
        new -> next = *liste;
        *liste = new;
    }
}

void afficheListe(int taille, Liste liste){
    printf("Liste chainée: ");
    for (int i = 0; i < taille; i++){
        printf("|%d|", liste -> val);
        liste = liste -> next;
    }
    printf("\n");
}

/* 
- Prints the linked list in an ascending order
- change the printf() statement's position to print the linked list in a descending order 
*/
void afficheListeRecusrive(Liste liste){
    if(liste != NULL){
        afficheListeRecusrive(liste -> next);
        printf("%d", liste -> val);
    }
    printf("\n");
}

int somme(int taille, Liste liste){
    int somme = 0;
    for (int i = 0; i < taille; i++){
        somme += liste -> val;
        liste = liste -> next;
    }
    printf("La somme = ");
    return somme;
}

int sommeRecursive(Liste liste){
    if (liste == 0){
        printf("La somme = ");
        return 0;
    }
    else{
        return liste -> val + sommeRecursive(liste -> next);
    }
}

int trouveIndice(int val, Liste liste){
    int existe = false;
    int indice = 0;
    
    while (existe == false && liste != NULL){
        indice += 1;
        liste = liste -> next;
        if (liste -> val == val){
            existe = true;
        }
    }
    return indice;
}

void main(){
    Liste liste = NULL;
    
    remplirListe(5, &liste);
    afficheListe(5, liste);
    int valeur = 3;
    printf("La valeur %d existe dans l'indice %d", valeur, trouveIndice(valeur, liste));
    //afficheListeRecusrive(liste);
    //printf("%d", somme(5, liste));
    //printf("%d", sommeRecursive(liste));
}