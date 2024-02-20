#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element {
    int val;
    struct Element* next;
} Element;

typedef Element* Liste;

void remplirListe(int taille, Liste* liste) {
    for (int i = taille - 1; i >= 0; i--) {
        Liste new = (Element*)malloc(sizeof(Element));
        new->val = i;
        new->next = *liste;
        *liste = new;
    }
}

void afficheListe(int taille, Liste liste) {
    printf("Liste chainée: ");
    while (liste != NULL) {
        printf("|%d|", liste->val);
        liste = liste->next;
    }
    printf("\n");
}

void afficheListeRecusrive(Liste liste) {
    if (liste != NULL) {
        printf("|%d|", liste->val);
        afficheListeRecusrive(liste->next);
    }
}

int somme(int taille, Liste liste) {
    int somme = 0;
    while (liste != NULL) {
        somme += liste->val;
        liste = liste->next;
    }
    printf("La somme = ");
    return somme;
}

int sommeRecursive(Liste liste) {
    if (liste == NULL) {
        printf("La somme = ");
        return 0;
    }
    else {
        return liste->val + sommeRecursive(liste->next);
    }
}

int trouveIndice(int val, Liste liste) {
    int existe = false;
    int indice = 0;

    while (liste != NULL) {
        if (liste->val == val) {
            existe = true;
            break;
        }
        liste = liste->next;
        indice += 1;
    }

    if (!existe)
        return -1; // If value not found, return -1

    return indice;
}

void ajouterTri(int val, Liste* liste) {
    Liste new = (Element*)malloc(sizeof(Element));
    new->val = val;

    if (*liste == NULL || val < (*liste)->val) {
        new->next = *liste;
        *liste = new;
    }
    else {
        Liste precedent = NULL;
        Liste courant = *liste;

        while (courant != NULL && val > courant->val) {
            precedent = courant;
            courant = courant->next;
        }

        if (precedent != NULL)
            precedent->next = new;
        else
            *liste = new;

        new->next = courant;
    }
}

void inverserListe(Liste* liste) {
    Liste precedent = NULL;
    Liste courant = *liste;
    Liste next = NULL;

    while (courant != NULL) {
        next = courant->next; 
        courant->next = precedent;  
        precedent = courant;
        courant = next;
    }

    *liste = precedent;  
}

void ajouterFin(Liste *l, int x){
    Element *new = (Element*)malloc(sizeof(Element));
    new -> val = x;
    new -> next = NULL;
    if (*l == NULL){
        *l = new;
    }else{
        Element *p = *l;
        while(p -> next != NULL){
            p = p -> next;
        }
        p -> next = new;
    }
}

Liste fusionner(Liste liste_1, Liste liste_2) {
  Liste liste_fusion = NULL;
  while (liste_1 != NULL && liste_2 != NULL) {
    if (liste_1->val < liste_2->val) {
      ajouterFin(&liste_fusion, liste_1->val);
      liste_1 = liste_1->next;
    } else {
      ajouterFin(&liste_fusion, liste_2->val);
      liste_2 = liste_2->next;
    }
  }

  while (liste_1 != NULL) {
    ajouterFin(&liste_fusion, liste_1->val);
    liste_1 = liste_1->next;
  }

  while (liste_2 != NULL) {
    ajouterFin(&liste_fusion, liste_2->val);
    liste_2 = liste_2->next;
  }

  return liste_fusion;
}

int main() {
    Liste liste_1 = NULL;
    Liste liste_2 = NULL;
    Liste liste_fusion = NULL;

    remplirListe(5, &liste_1);
    remplirListe(5, &liste_2);

    liste_fusion = fusionner(liste_1, liste_2);
    afficheListe(5, liste_fusion);

    return 0;
}
