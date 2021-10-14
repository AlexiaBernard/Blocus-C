#include<graph.h>
#include<stdio.h>
#include<stdlib.h>
#include"menu.h"
 
#define tx 700
#define ty 700
 
//------------------------------------FONCTION-------------------------------//

void DessinerScene1(int action){
    int c;

    //bouton 3
    if(action==1){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("pink");
        ChoisirCouleurDessin(c);
        RemplirArc(40,220,80,80,-360,360);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        EcrireTexte(72,273,"3",2);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }
    //bouton 4
    if(action==2){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("pink");
        ChoisirCouleurDessin(c);
        RemplirArc(140,220,80,80,-360,360);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        EcrireTexte(172,273,"4",2);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }
    //bouton 5
    if(action==3){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("pink");
        ChoisirCouleurDessin(c);
        RemplirArc(240,220,80,80,-360,360);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        EcrireTexte(272,273,"5",2);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }
    //bouton 6
    if(action==4){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("pink");
        ChoisirCouleurDessin(c);
        RemplirArc(40,320,80,80,-360,360);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        EcrireTexte(72,373,"6",2);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }
    //bouton 7
    if(action==5){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("pink");
        ChoisirCouleurDessin(c);
        RemplirArc(140,320,80,80,-360,360);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        EcrireTexte(172,373,"7",2);;
        CopierZone(3,0,0,0,tx,ty,0,0);
    }
    //bouton 8
    if(action==6){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("pink");
        ChoisirCouleurDessin(c);
        RemplirArc(240,320,80,80,-360,360);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        EcrireTexte(272,373,"8",2);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }

    //bouton 9
    if(action==7){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("pink");
        ChoisirCouleurDessin(c);
        RemplirArc(140,420,80,80,-360,360);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        EcrireTexte(172,473,"9",2);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }

    //bouton 1j
    if(action==8){ 
        ChoisirEcran(4);
        CopierZone(3,4,0,0,tx,ty,0,0);
        c=CouleurParNom("pink");
        ChoisirCouleurDessin(c);
        RemplirArc(440,220,80,80,-360,360);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        EcrireTexte(472,273,"1",2);
        CopierZone(4,0,0,0,tx,ty,0,0);
    }
    //bouton2j
    if(action==9){
        ChoisirEcran(4);
        CopierZone(3,4,0,0,tx,ty,0,0);
        c=CouleurParNom("pink");
        ChoisirCouleurDessin(c);
        RemplirArc(560,220,80,80,-360,360);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        EcrireTexte(592,273,"2",2);
        CopierZone(4,0,0,0,tx,ty,0,0);
    }

    //bouton effacer
    if (action==10){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        RemplirRectangle(200,580,120,40);
        c=CouleurParNom("red");
        ChoisirCouleurDessin(c);
        EcrireTexte(207,613,"Effacer",2);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }

    //bouton valider
    if (action==11){
        ChoisirEcran(3);
        CopierZone(1,3,0,0,tx,ty,0,0);
        c=CouleurParNom("black");
        ChoisirCouleurDessin(c);
        RemplirRectangle(390,580,120,40);
        c=CouleurParNom("red");
        ChoisirCouleurDessin(c);
        EcrireTexte(396,613,"Valider",2);
        CopierZone(3,0,0,0,tx,ty,0,0);
    }

}

int menu(void){

    int x,y,i=0,j,taille=0, joueur=0;
    int go_on=1;
    int c;

    //------------------TEXTE-MISE-EN-PAGE------------------//

    ChoisirEcran(2);
    ChargerImageFond("couleur2.jpeg");

    ChoisirEcran(1);
    CopierZone(2,1,0,0,tx,ty,0,0);
    c=CouleurParNom("black");
    ChoisirCouleurDessin(c);

    EcrireTexte(240,35,"Bienvenue dans Blocus",2);
    EcrireTexte(180,65,"Veuillez selectionner les caracteristiques du jeu",1);

    //bouton taille du terrain
    EcrireTexte(115,180,"Taille du Terrain:",1);

    for(i=220; i<=320; i=i+100){
        for(j=40; j<=240;j=j+100){
            DessinerArc(j,i,80,80,-360,360);
        }
    }
    DessinerArc(140,420,80,80,-360,360);

    EcrireTexte(72,273,"3",2);
    EcrireTexte(172,273,"4",2);
    EcrireTexte(272,273,"5",2);
    EcrireTexte(72,373,"6",2);
    EcrireTexte(172,373,"7",2);
    EcrireTexte(272,373,"8",2);
    EcrireTexte(172,473,"9",2);

    //bouton nombre de joueur
    EcrireTexte(480,180,"Nombre de joueur:",1);
    DessinerArc(440,220,80,80,-360,360);
    DessinerArc(560,220,80,80,-360,360);
    EcrireTexte(472,273,"1",2);
    EcrireTexte(592,273,"2",2);

    //bouton valider et effacer
    RemplirRectangle(390,580,120,40);
    RemplirRectangle(200,580,120,40);
    c=CouleurParNom("white");
    ChoisirCouleurDessin(c);
    EcrireTexte(396,613,"Valider",2);
    EcrireTexte(207,613,"Effacer",2);
    c=CouleurParNom("black");
    ChoisirCouleurDessin(c);
    CopierZone(1,0,0,0,tx,ty,0,0);

//----------------------CHOIX-TAILLE-ET-JOUEUR-----------------------//

    while(go_on){
        if(SourisCliquee()){
            SourisPosition();
            x=_X;
            y=_Y;

            //bouton 3
            if((40<x) && (x<100) && (220<y) && (y<300)){
                DessinerScene1(1);
                taille=3;
            }
            //bouton 4
            if((140<x) && (x<200) && (220<y) && (y<300)){
                DessinerScene1(2);
                taille=4;
            }
            //bouton 5
            if((240<x) && (x<300) && (220<y) && (y<300)){
                DessinerScene1(3);
                taille=5;
            }
            //bouton 6
            if((40<x) && (x<100) && (320<y) && (y<400)){
                DessinerScene1(4);
                taille=6;
            }
            //bouton 7
            if((140<x) && (x<200) && (320<y) && (y<400)){
                DessinerScene1(5);
                taille=7;
            }
            //bouton 8
            if((240<x) && (x<300) && (320<y) && (y<400)){
                DessinerScene1(6);
                taille=8;
            }

            //bouton 9
            if((140<x) && (x<200) && (420<y) && (y<500)){
                DessinerScene1(7);
                taille=9;
            }

            //bouton 1j
            if(( 440<x) && (x<520) && (220<y) && (y<300)){
                DessinerScene1(8);
                joueur=1;
            }
            //bouton2j
            if((560<x) && (x<640) && (220<y) && (y<300)){
                DessinerScene1(9);
                joueur=2;
            }

            //bouton effacer
            if ((200<x && x<320) && (580<y && y<620)){
                DessinerScene1(10);
                taille=0;
                joueur=0;
            }

            //bouton valider
            if ((390<x && x<510) && (580<y && y<620) && taille!=0 && joueur!=0){
                DessinerScene1(11);
                if (joueur==1){
                    if (taille==3){
                        return 31;
                    }
                    if (taille==4){
                        return 41;
                    }
                    if (taille==5){
                        return 51;
                    }
                    if (taille==6){
                        return 61;
                    }
                    if (taille==7){
                        return 71;
                    }
                    if (taille==8){
                        return 81;
                    }
                    if (taille==9){
                        return 91;
                    }
                }

                if (joueur==2){
                    if (taille==3){
                        return 32;
                    }
                    if (taille==4){
                        return 42;
                    }
                    if (taille==5){
                        return 52;
                    }
                    if (taille==6){
                        return 62;
                    }
                    if (taille==7){
                        return 72;
                    }
                    if (taille==8){
                        return 82;
                    }
                    if (taille==9){
                        return 92;
                    }
                }
            }
        }
    }
    
    return -1;
}