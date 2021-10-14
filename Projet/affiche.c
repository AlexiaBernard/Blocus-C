#include<graph.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h> 
#include "affiche.h"
#include "menu.h"
 
#define tx 700
#define ty 700

void DessinerScene2(int action){
    int c;

    //bouton rejouer
    if(action==1){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        RemplirArc(240,372,80,45,-360,360);
        c=CouleurParNom("red");
        ChoisirCouleurDessin(c);
        EcrireTexte(253,400,"Rejouer",1);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }
    //bouton quitter
    if(action==2){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        RemplirArc(380,375,70,40,-360,360);
        c=CouleurParNom("red");
        ChoisirCouleurDessin(c);
        EcrireTexte(388,400,"Quitter",1);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }
}
 
int affiche(int gagnant, int joueur){

    int x,y,n,w;
    unsigned long c;
    int go_on=1;

    n=ChargerSprite("fete.png");
    w=ChargerSprite("fete2.png");
    ChoisirEcran(2);
    ChargerImageFond("couleur2.jpeg");

    ChoisirEcran(1);
    CopierZone(2,1,0,0,tx,ty,0,0);
    //touche rejouer et quitter
    c=CouleurParNom("black");
    ChoisirCouleurDessin(c);
    RemplirRectangle(240,372,90,45);
    RemplirRectangle(380,372,80,45);
    

    c=CouleurParNom("white");
    ChoisirCouleurDessin(c);
    EcrireTexte(250,400,"Rejouer",1);
    EcrireTexte(388,400,"Quitter",1);

    c=CouleurParNom("black");
    ChoisirCouleurDessin(c);
    if(gagnant==1&&joueur==2){
        EcrireTexte(190,300,"Le gagnant est le joueur 1",2);
        AfficherSprite(n,520,200);
        AfficherSprite(w,100,200);

    }else if(gagnant==2&&joueur==2){
        EcrireTexte(190,300,"Le gagnant est le joueur 2",2);
        AfficherSprite(n,520,200);
        AfficherSprite(w,100,200);
    }else if (gagnant==1&&joueur==1){
        EcrireTexte(190,300,"Felicitations vous avez gagne !",2);
        AfficherSprite(n,520,200);
        AfficherSprite(w,100,200);
    }else if (gagnant==2&&joueur==1){
        EcrireTexte(230,300,"Vous avez perdu...",2);
    }
    CopierZone(1,0,0,0,tx,ty,0,0);

    while(go_on){
        if(SourisCliquee()){
            SourisPosition();
            x=_X;
            y=_Y;

            //bouton rejouer
            if((240<x && x<330) && (330<y && y<415)){
                DessinerScene2(1);
                sleep(1);
                return 1;
            }
            //bouton quitter
            if((380<x && x<460) && (330<y && y<415)){
                DessinerScene2(2);
                sleep(1);
                return 0;
            }
        }
    }
    return -1;
}