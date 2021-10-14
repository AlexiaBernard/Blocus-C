#include<graph.h>
#include<stdio.h>
#include<stdlib.h>
#include"jeux.h"
#include"jdeux.h"
#include"jun.h"

#define tx 700
#define ty 700

//------------------------------Fonctions------------------------------//

int jeux(int taille, int joueur){

    int c, gagnant;

    ChoisirEcran(2);
    ChargerImageFond("couleur2.jpeg");

//-------------Affichage du quadrillage-------------//
    c=CouleurParNom("black");
    ChoisirCouleurDessin(c);

    //contour grille
    c=CouleurParNom("white");
    ChoisirCouleurDessin(c);
    DessinerRectangle(0,0,tx-2,ty-2);
    c=CouleurParNom("black");
    ChoisirCouleurDessin(c);
    DessinerRectangle(1,1,tx-4,ty-4);
    DessinerRectangle(2,2,tx-6,ty-6); 
    DessinerRectangle(3,3,tx-8,ty-8);

    if (joueur==1){
        gagnant=un_joueur(taille);
    }
    if (joueur==2){
        gagnant=deux_joueurs(taille);
    }

    return gagnant;
}