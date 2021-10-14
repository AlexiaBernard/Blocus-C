#include<graph.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h> 
#include"jdeux.h"

#define tx 700
#define ty 700

void DessinerSceneDEUX(int pion, int x,int y, int taille){
  int c;

  if (pion==1){
      ChoisirEcran(1);
      CopierZone(2,1,0,0,tx,ty,0,0);
      c=CouleurParNom("blue");
      ChoisirCouleurDessin(c);
      RemplirArc(x+tx/taille/4,y+tx/taille/4,tx/taille/2,ty/taille/2,-360,360);
      CopierZone(1,0,0,0,tx,ty,0,0);
  }
  if (pion==2){
      ChoisirEcran(3);
      CopierZone(1,3,0,0,tx,ty,0,0);
      c=CouleurParNom("green");
      ChoisirCouleurDessin(c);
      RemplirArc(x+tx/taille/4,y+tx/taille/4,tx/taille/2,ty/taille/2,-360,360);
      CopierZone(3,0,0,0,tx,ty,0,0);
  }
  if (pion==3){
      ChoisirEcran(4);
      CopierZone(3,4,0,0,tx,ty,0,0);
      c=CouleurParNom("white");
      ChoisirCouleurDessin(c);
      DessinerArc(x+tx/taille/4,y+tx/taille/4,tx/taille/2,ty/taille/2,-360,360);
      CopierZone(4,0,0,0,tx,ty,0,0);
  }
  if (pion==4){
      ChoisirEcran(5);
      CopierZone(3,5,0,0,tx,ty,0,0);
      c=CouleurParNom("white");
      ChoisirCouleurDessin(c);
      DessinerArc(x+tx/taille/4,y+tx/taille/4,tx/taille/2,ty/taille/2,-360,360);
      CopierZone(5,0,0,0,tx,ty,0,0);
  }
    
}

int deux_joueurs(int taille) {

  int x,y,old_x,old_y;
  int joueur=2;
  int k=0,l=0,verif,i=0,j=0,vi,vj,vk,vl,z,p;
  int a,b=0,c, premier=0, deuxieme=0,rouge=0;
  int gagnant;
  int go_on=1;
  int d=taille*taille;
  int tab[d][4];
  int occupe[d][4];

  for (int w = 0; w < d; ++w){
    for (int v = 0; v < 4; ++v){
      occupe[w][v]=0;
     } 
  }

  if ((taille==4)||(taille==5)||(taille==7)||(taille==3)){
    b=1;
    for (y=1; y<=taille; y++){
      a=1;
      for (x=1; x<=taille; x++){
        DessinerRectangle(a,b,(tx-1)/taille,(ty-1)/taille);   
        tab[i][j]=a; 
        tab[i][j+1]=b; 
        tab[i][j+2]=((tx-1)/taille); 
        tab[i][j+3]=((ty-1)/taille);
        a=(((tx-1)/taille)*x)+1;
        i++;
      }
      b=(((ty-1)/taille)*y)+1;
    }
  }
  
  if ((taille==6)||(taille==8)){
    b=3;
    for (y=1; y<=taille; y++){
      a=3;
      for (x=1; x<=taille; x++){
        DessinerRectangle(a,b,(tx-4)/taille,(ty-4)/taille);
        tab[i][j]=a; 
        tab[i][j+1]=b; 
        tab[i][j+2]=(tx-4)/taille; 
        tab[i][j+3]=(ty-4)/taille;            
        a=(((tx-4)/taille)*x)+3;
        i++;
      }
      b=(((ty-4)/taille)*y)+3;
    }
  }

  if (taille==9){
    b=3;
    for (y=1; y<=taille; y++){
      a=3;
      for (x=1; x<=taille; x++){
        DessinerRectangle(a,b,(tx-7)/taille,(ty-7)/taille);
        tab[i][j]=a; tab[i][j+1]=b; tab[i][j+2]=(tx-7)/taille; tab[i][j+3]=(ty-7)/taille;           
        a=(((tx-7)/taille)*x)+3;
        i++;
      }
      b=(((ty-7)/taille)*y)+3;
    }
  }
//------------------------DÉPLACEMENT-2-JOUEUR----------------------------------------------------//

  while(go_on && joueur==2){
    verif=0;
    //Choix du 1e placement du pion1
    while (premier==0){
      if (!SourisCliquee()){
        SourisPosition();
        x=_X;
        y=_Y;
        if (x!=old_x || y!=old_y){
          DessinerSceneDEUX(1,x-35-tx/taille/4,y-35-tx/taille/4,taille);
          old_x=x;
          old_y=y;
        }

        if(SourisCliquee()){
          SourisPosition();
          x=_X;
          y=_Y;
          for(i=0;i<d;i++){
            if ( (tab[i][j]<x && x<tab[i][j]+tab[i][j+2]) && (tab[i][j+1]<y && y<tab[i][j+1]+tab[i][j+3]) ){
              DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
              premier=1;
              vi=i;
              vj=j;
              verif=1;
              occupe[i][j]=tab[i][j];
              occupe[i][j+1]=tab[i][j+1];
              occupe[i][j+2]=tab[i][j+2];
              occupe[i][j+3]=tab[i][j+3];
            }
          }
        i=vi;
        j=vj;
        }
      }
    }

    //Choix du 1e placement du pion2
    while ((deuxieme==0)&&(premier==1)&&(verif==1)){
      if (!SourisCliquee()){
        SourisPosition();
        x=_X;
        y=_Y;
        if (x!=old_x || y!=old_y){
          DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
          DessinerSceneDEUX(2,x-35-tx/taille/4,y-35-tx/taille/4,taille);
          old_x=x;
          old_y=y;
        }
      
        if(SourisCliquee()){
          SourisPosition();
          x=_X;
          y=_Y;

          for(k=0;k<d;k++){
            if( (tab[k][l]<x && x<tab[k][l]+tab[k][l+2]) && (tab[k][l+1]<y && y<tab[k][l+1]+tab[k][l+3]) ){
              DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
              DessinerSceneDEUX(2,tab[k][l],tab[k][l+1],taille);
              deuxieme=1;
              vk=k;
              vl=l;
              verif=10;
              occupe[k][l]=tab[k][l];
              occupe[k][l+1]=tab[k][l+1];
              occupe[k][l+2]=tab[k][l+2];
              occupe[k][l+3]=tab[k][l+3];
            }
          }
          k=vk;
          l=vl;
        }
      }
    } 

//--------------Mouvement Pion1--------------//
    while(verif==0){
      rouge=0;
      DessinerSceneDEUX(3,tab[i][j],tab[i][j+1],taille);

      //enlève la dernière position du pion1 dans occupe
      occupe[i][j]=0;
      occupe[i][j+1]=0;
      occupe[i][j+2]=0;
      occupe[i][j+3]=0;

      //--------------------------------------pion2-------------------------------------------//
      //fin du jeu si pion2 ne peut plus bouger
      if( (tab[k-1][l]==occupe[k-1][l] && tab[k-1][l+1]==occupe[k-1][l+1])
         && (tab[k-taille][l]==occupe[k-taille][l] && tab[k-taille][l+1]==occupe[k-taille][l+1])
         && (tab[k+taille][l]==occupe[k+taille][l] && tab[k+taille][l+1]==occupe[k+taille][l+1])
         && (tab[k+1][l]==occupe[k+1][l] && tab[k+1][l+1]==occupe[k+1][l+1])
         && (tab[k-taille-1][l]==occupe[k-taille-1][l] && tab[k-taille-1][l+1]==occupe[k-taille-1][l+1])
         && (tab[k-taille+1][l]==occupe[k-taille+1][l] && tab[k-taille+1][l+1]==occupe[k-taille+1][l+1])
         && (tab[k+taille-1][l]==occupe[k+taille-1][l] && tab[k+taille-1][l+1]==occupe[k+taille-1][l+1])
         && (tab[k+taille+1][l]==occupe[k+taille+1][l] && tab[k+taille+1][l+1]==occupe[k+taille+1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger a gauche
      if( k%taille==0 && (tab[k-taille][l]==occupe[k-taille][l] && tab[k-taille][l+1]==occupe[k-taille][l+1])
         && (tab[k+taille][l]==occupe[k+taille][l] && tab[k+taille][l+1]==occupe[k+taille][l+1])
         && (tab[k+1][l]==occupe[k+1][l] && tab[k+1][l+1]==occupe[k+1][l+1])
         && (tab[k-taille+1][l]==occupe[k-taille+1][l] && tab[k-taille+1][l+1]==occupe[k-taille+1][l+1])
         && (tab[k+taille+1][l]==occupe[k+taille+1][l] && tab[k+taille+1][l+1]==occupe[k+taille+1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger a droite 
      if( k%taille==taille-1 && (tab[k-1][l]==occupe[k-1][l] && tab[k-1][l+1]==occupe[k-1][l+1])
         && (tab[k-taille][l]==occupe[k-taille][l] && tab[k-taille][l+1]==occupe[k-taille][l+1])
         && (tab[k+taille][l]==occupe[k+taille][l] && tab[k+taille][l+1]==occupe[k+taille][l+1])
         && (tab[k-taille-1][l]==occupe[k-taille-1][l] && tab[k-taille-1][l+1]==occupe[k-taille-1][l+1])
         && (tab[k+taille-1][l]==occupe[k+taille-1][l] && tab[k+taille-1][l+1]==occupe[k+taille-1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en haut
      if( tab[0][l]<=tab[k][l] && tab[k][l]<=tab[taille-1][l] && tab[0][l+1]<=tab[k][l+1] && tab[k][l+1]<=tab[taille-1][l+1] && (tab[k-1][l]==occupe[k-1][l] && tab[k-1][l+1]==occupe[k-1][l+1])
         && (tab[k+taille][l]==occupe[k+taille][l] && tab[k+taille][l+1]==occupe[k+taille][l+1])
         && (tab[k+1][l]==occupe[k+1][l] && tab[k+1][l+1]==occupe[k+1][l+1])
         && (tab[k+taille-1][l]==occupe[k+taille-1][l] && tab[k+taille-1][l+1]==occupe[k+taille-1][l+1])
         && (tab[k+taille+1][l]==occupe[k+taille+1][l] && tab[k+taille+1][l+1]==occupe[k+taille+1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en bas
      if( tab[d-taille+1][l]<=tab[k][l] && tab[k][l]<=tab[d-1][l] && tab[d-taille+1][l+1]<=tab[k][l+1] && tab[k][l+1]<=tab[d-1][l+1] && (tab[k-1][l]==occupe[k-1][l] && tab[k-1][l+1]==occupe[k-1][l+1])
         && (tab[k-taille][l]==occupe[k-taille][l] && tab[k-taille][l+1]==occupe[k-taille][l+1])
         && (tab[k+1][l]==occupe[k+1][l] && tab[k+1][l+1]==occupe[k+1][l+1])
         && (tab[k-taille-1][l]==occupe[k-taille-1][l] && tab[k-taille-1][l+1]==occupe[k-taille-1][l+1])
         && (tab[k-taille+1][l]==occupe[k-taille+1][l] && tab[k-taille+1][l+1]==occupe[k-taille+1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en haut a gauche
      if( tab[k][j]==tab[0][j] && tab[k][j+1]==tab[0][j+1] && (tab[k+taille][j]==occupe[k+taille][j] && tab[k+taille][j+1]==occupe[k+taille][j+1])
         && (tab[k+1][j]==occupe[k+1][j] && tab[k+1][j+1]==occupe[k+1][j+1])
         && (tab[k+taille+1][j]==occupe[k+taille+1][j] && tab[k+taille+1][j+1]==occupe[k+taille+1][j+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en haut a droite
      if( tab[k][j]==tab[taille-1][j] && tab[k][j+1]==tab[taille-1][j+1] && (tab[k-1][j]==occupe[k-1][j] && tab[k-1][j+1]==occupe[k-1][j+1])
         && (tab[k+taille][j]==occupe[k+taille][j] && tab[k+taille][j+1]==occupe[k+taille][j+1])
         && (tab[k+taille-1][j]==occupe[k+taille-1][j] && tab[k+taille-1][j+1]==occupe[k+taille-1][j+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en bas a gauche
      if( tab[k][j]==tab[d-taille][j] && tab[k][j+1]==tab[d-taille][j+1] && (tab[k-taille][j]==occupe[k-taille][j] && tab[k-taille][j+1]==occupe[k-taille][j+1])
         && (tab[k+1][j]==occupe[k+1][j] && tab[k+1][j+1]==occupe[k+1][j+1])
         && (tab[k-taille+1][j]==occupe[k-taille+1][j] && tab[k-taille+1][j+1]==occupe[k-taille+1][j+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en bas a droite
      if(tab[k][j]==tab[d-1][j] && tab[k][j+1]==tab[d-1][j+1] && (tab[k-1][j]==occupe[k-1][j] && tab[k-1][j+1]==occupe[k-1][j+1])
         && (tab[k-taille][j]==occupe[k-taille][j] && tab[k-taille][j+1]==occupe[k-taille][j+1])
         && (tab[k-taille-1][j]==occupe[k-taille-1][j] && tab[k-taille-1][j+1]==occupe[k-taille-1][j+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //----------------------------------pion 1--------------------------------//
      //fin du jeu si pion1 ne peut plus bouger
      if( (tab[i-1][j]==occupe[i-1][j] && tab[i-1][j+1]==occupe[i-1][j+1])
         && (tab[i-taille][j]==occupe[i-taille][j] && tab[i-taille][j+1]==occupe[i-taille][j+1])
         && (tab[i+taille][j]==occupe[i+taille][j] && tab[i+taille][j+1]==occupe[i+taille][j+1])
         && (tab[i+1][j]==occupe[i+1][j] && tab[i+1][j+1]==occupe[i+1][j+1])
         && (tab[i-taille-1][j]==occupe[i-taille-1][j] && tab[i-taille-1][j+1]==occupe[i-taille-1][j+1])
         && (tab[i-taille+1][j]==occupe[i-taille+1][j] && tab[i-taille+1][j+1]==occupe[i-taille+1][j+1])
         && (tab[i+taille-1][j]==occupe[i+taille-1][j] && tab[i+taille-1][j+1]==occupe[i+taille-1][j+1])
         && (tab[i+taille+1][j]==occupe[i+taille+1][j] && tab[i+taille+1][j+1]==occupe[i+taille+1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger a gauche
      if( i%taille==0 && (tab[i-taille][l]==occupe[i-taille][l] && tab[i-taille][l+1]==occupe[i-taille][l+1])
         && (tab[i+taille][l]==occupe[i+taille][l] && tab[i+taille][l+1]==occupe[i+taille][l+1])
         && (tab[i+1][l]==occupe[i+1][l] && tab[i+1][l+1]==occupe[i+1][l+1])
         && (tab[i-taille+1][l]==occupe[i-taille+1][l] && tab[i-taille+1][l+1]==occupe[i-taille+1][l+1])
         && (tab[i+taille+1][l]==occupe[i+taille+1][l] && tab[i+taille+1][l+1]==occupe[i+taille+1][l+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger a droite 
      if( i%taille==taille-1 && (tab[i-1][l]==occupe[i-1][l] && tab[i-1][l+1]==occupe[i-1][l+1])
         && (tab[i-taille][l]==occupe[i-taille][l] && tab[i-taille][l+1]==occupe[i-taille][l+1])
         && (tab[i+taille][l]==occupe[i+taille][l] && tab[i+taille][l+1]==occupe[i+taille][l+1])
         && (tab[i-taille-1][l]==occupe[i-taille-1][l] && tab[i-taille-1][l+1]==occupe[i-taille-1][l+1])
         && (tab[i+taille-1][l]==occupe[i+taille-1][l] && tab[i+taille-1][l+1]==occupe[i+taille-1][l+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en bas
      if( tab[d-taille+1][l]<=tab[i][l] && tab[i][l]<=tab[d-1][l] && tab[d-taille+1][l+1]<=tab[i][l+1] && tab[i][l+1]<=tab[d-1][l+1] && (tab[i-1][l]==occupe[i-1][l] && tab[i-1][l+1]==occupe[i-1][l+1])
         && (tab[i-taille][l]==occupe[i-taille][l] && tab[i-taille][l+1]==occupe[i-taille][l+1])
         && (tab[i+1][l]==occupe[i+1][l] && tab[i+1][l+1]==occupe[i+1][l+1])
         && (tab[i-taille-1][l]==occupe[i-taille-1][l] && tab[i-taille-1][l+1]==occupe[i-taille-1][l+1])
         && (tab[i-taille+1][l]==occupe[i-taille+1][l] && tab[i-taille+1][l+1]==occupe[i-taille+1][l+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en haut
      if( tab[0][l]<=tab[i][l] && tab[i][l]<=tab[taille-1][l] && tab[0][l+1]<=tab[i][l+1] && tab[i][l+1]<=tab[taille-1][l+1] && (tab[i-1][l]==occupe[i-1][l] && tab[i-1][l+1]==occupe[i-1][l+1])
         && (tab[i+taille][l]==occupe[i+taille][l] && tab[i+taille][l+1]==occupe[i+taille][l+1])
         && (tab[i+1][l]==occupe[i+1][l] && tab[i+1][l+1]==occupe[i+1][l+1])
         && (tab[i+taille-1][l]==occupe[i+taille-1][l] && tab[i+taille-1][l+1]==occupe[i+taille-1][l+1])
         && (tab[i+taille+1][l]==occupe[i+taille+1][l] && tab[i+taille+1][l+1]==occupe[i+taille+1][l+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en haut a gauche
      if( tab[i][j]==tab[0][j] && tab[i][j+1]==tab[0][j+1] && (tab[i+taille][j]==occupe[i+taille][j] && tab[i+taille][j+1]==occupe[i+taille][j+1])
         && (tab[i+1][j]==occupe[i+1][j] && tab[i+1][j+1]==occupe[i+1][j+1])
         && (tab[i+taille+1][j]==occupe[i+taille+1][j] && tab[i+taille+1][j+1]==occupe[i+taille+1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en haut a droite
      if( tab[i][j]==tab[taille-1][j] && tab[i][j+1]==tab[taille-1][j+1] && (tab[i-1][j]==occupe[i-1][j] && tab[i-1][j+1]==occupe[i-1][j+1])
         && (tab[i+taille][j]==occupe[i+taille][j] && tab[i+taille][j+1]==occupe[i+taille][j+1])
         && (tab[i+taille-1][j]==occupe[i+taille-1][j] && tab[i+taille-1][j+1]==occupe[i+taille-1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en bas a gauche
      if( tab[i][j]==tab[d-taille][j] && tab[i][j+1]==tab[d-taille][j+1] && (tab[i-taille][j]==occupe[i-taille][j] && tab[i-taille][j+1]==occupe[i-taille][j+1])
         && (tab[i+1][j]==occupe[i+1][j] && tab[i+1][j+1]==occupe[i+1][j+1])
         && (tab[i-taille+1][j]==occupe[i-taille+1][j] && tab[i-taille+1][j+1]==occupe[i-taille+1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en bas a droite
      if(tab[i][j]==tab[d-1][j] && tab[i][j+1]==tab[d-1][j+1] && (tab[i-1][j]==occupe[i-1][j] && tab[i-1][j+1]==occupe[i-1][j+1])
         && (tab[i-taille][j]==occupe[i-taille][j] && tab[i-taille][j+1]==occupe[i-taille][j+1])
         && (tab[i-taille-1][j]==occupe[i-taille-1][j] && tab[i-taille-1][j+1]==occupe[i-taille-1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      if(SourisCliquee()&&verif==0){
        SourisPosition();
        x=_X;
        y=_Y;

        //interdit le déplacement du pion1 sur le pion2
        if( (occupe[k][l]<x && x<occupe[k][l]+occupe[k][l+2]) && (occupe[k][l+1]<y && y<occupe[k][l+1]+occupe[k][l+3]) ){
          rouge=1;
        }

        //mettre couleur croix rouge si déjà occupée
        for(p=0;p<taille*taille;p++){
          if ( (occupe[p][j]<x && x<occupe[p][j]+occupe[p][j+2]) && (occupe[p][j+1]<y && y<occupe[p][j+1]+occupe[p][j+3]) && rouge==0){
            rouge=1; 
          }
        }

        //aller à gauche
        if ( (tab[i-1][j]<x && x<tab[i][j]) && (tab[i-1][j+1]<y && y<tab[i-1][j+1]+tab[i-1][j+3]) && rouge==0){
          DessinerSceneDEUX(1,tab[i-1][j],tab[i-1][j+1],taille);
          i=i-1;
          verif=1;
        }
        //aller en haut    
        else if ( (tab[i-taille][j]<x && x<tab[i-taille][j]+tab[i-taille][j+2]) && (tab[i][j+1]-tab[i][j+3]<y && y<tab[i][j+1]) && rouge==0){
          DessinerSceneDEUX(1,tab[i-taille][j],tab[i-taille][j+1], taille);
          i=i-taille;
          verif=1;
        }
        //aller en bas
        else if ( (tab[i+taille][j]<x && x<tab[i+taille][j]+tab[i+taille][j+2]) && (tab[i+taille][j+1]<y && y<tab[i+taille][j+1]+tab[i+taille][j+3]) && rouge==0){
          DessinerSceneDEUX(1,tab[i+taille][j],tab[i+taille][j+1],taille);
          i=i+taille;
          verif=1;
        }
        //aller à droite
        else if ( (tab[i+1][j]<x && x<tab[i+1][j]+tab[i+1][j+2]) && (tab[i+1][j+1]<y && y<tab[i+1][j+1]+tab[i+1][j+3]) &&rouge==0){
          DessinerSceneDEUX(1,tab[i+1][j],tab[i+1][j+1],taille);
          i=i+1;
          verif=1;
        }
        //diagonale haut/gauche
        else if ( (tab[i-taille-1][j]<x && x<tab[i-taille-1][j]+tab[i-taille-1][j+2]) && (tab[i-1][j+1]-tab[i-1][j+3]<y && y<tab[i-1][j+1]) &&rouge==0){
          DessinerSceneDEUX(1,tab[i-taille-1][j],tab[i-taille-1][j+1],taille);
          i=i-taille-1;
          verif=1;
        }
        //diagonale haut/droite
        else if ( (tab[i-taille+1][j]<x && x<tab[i-taille+1][j]+tab[i-taille+1][j+2]) && (tab[i+1][j+1]-tab[i+1][j+3]<y && y<tab[i+1][j+1]) &&rouge==0){
          DessinerSceneDEUX(1,tab[i-taille+1][j],tab[i-taille+1][j+1],taille);
          i=i-taille+1;
          verif=1;
        } 
        //diagonale bas/gauche
        else if ( (tab[i+taille-1][j]<x && x<tab[i+taille-1][j]+tab[i+taille-1][j+2]) && (tab[i+taille-1][j+1]<y && y<tab[i+taille-1][j+1]+tab[i+taille-1][j+3]) &&rouge==0){
          DessinerSceneDEUX(1,tab[i+taille-1][j],tab[i+taille-1][j+1],taille);
          i=i+taille-1;
          verif=1;
        } 
        //diagonale bas/droite
        else if ( (tab[i+taille+1][j]<x && x<tab[i+taille+1][j]+tab[i+taille+1][j+2]) && (tab[i+taille+1][j+1]<y && y<tab[i+taille+1][j+1]+tab[i+taille+1][j+3]) &&rouge==0){
          DessinerSceneDEUX(1,tab[i+taille+1][j],tab[i+taille+1][j+1],taille);
          i=i+taille+1;
          verif=1;
        }
        DessinerSceneDEUX(2,tab[k][l],tab[k][l+1],taille);
        if (verif==1){
          occupe[i][j]=tab[i][j];
          occupe[i][j+1]=tab[i][j+1];
          occupe[i][j+2]=tab[i][j+2];
          occupe[i][j+3]=tab[i][j+3];
        }                    
      }
    }
//--------------Croix dans cases--------------//
    while(verif==1){
      if(SourisCliquee()){
        SourisPosition();
        x=_X;
        y=_Y;

        for(z=0;z<taille*taille;z++){
          if ( (tab[z][j]<x && x<tab[z][j]+tab[z][j+2]) && (tab[z][j+1]<y && y<tab[z][j+1]+tab[z][j+3]) ){
            if (tab[z][j]!=occupe[z][j]){
              ChoisirEcran(2);
              CopierZone(2,1,0,0,tx,ty,0,0);
              c=CouleurParNom("black");
              ChoisirCouleurDessin(c);                        
              DessinerSegment(tab[z][j],tab[z][j+1],tab[z][j]+tab[z][j+2],tab[z][j+1]+tab[z][j+3]);
              DessinerSegment(tab[z][j],tab[z][j+1]+tab[z][j+3],tab[z][j]+tab[z][j+2],tab[z][j+1]);
              CopierZone(1,0,0,0,tx,ty,0,0);
              occupe[z][j]=tab[z][j];
              occupe[z][j+1]=tab[z][j+1];
              occupe[z][j+2]=tab[z][j+2];
              occupe[z][j+3]=tab[z][j+3];
              DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
              DessinerSceneDEUX(2,tab[k][l],tab[k][l+1],taille);
              verif=2;
            }
          }
        }
      }
    }

//--------------Mouvement Pion2--------------//
    while(verif==2){
      DessinerSceneDEUX(4,tab[k][l],tab[k][l+1],taille);
      rouge=0;

      // enlève la dernière position de pion2 de occupe
      occupe[k][l]=0;
      occupe[k][l+1]=0;
      occupe[k][l+2]=0;
      occupe[k][l+3]=0;

      //--------------------------------------pion2-------------------------------------------//
      //fin du jeu si pion2 ne peut plus bouger
      if( (tab[k-1][l]==occupe[k-1][l] && tab[k-1][l+1]==occupe[k-1][l+1])
         && (tab[k-taille][l]==occupe[k-taille][l] && tab[k-taille][l+1]==occupe[k-taille][l+1])
         && (tab[k+taille][l]==occupe[k+taille][l] && tab[k+taille][l+1]==occupe[k+taille][l+1])
         && (tab[k+1][l]==occupe[k+1][l] && tab[k+1][l+1]==occupe[k+1][l+1])
         && (tab[k-taille-1][l]==occupe[k-taille-1][l] && tab[k-taille-1][l+1]==occupe[k-taille-1][l+1])
         && (tab[k-taille+1][l]==occupe[k-taille+1][l] && tab[k-taille+1][l+1]==occupe[k-taille+1][l+1])
         && (tab[k+taille-1][l]==occupe[k+taille-1][l] && tab[k+taille-1][l+1]==occupe[k+taille-1][l+1])
         && (tab[k+taille+1][l]==occupe[k+taille+1][l] && tab[k+taille+1][l+1]==occupe[k+taille+1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger a gauche
      if( k%taille==0 && (tab[k-taille][l]==occupe[k-taille][l] && tab[k-taille][l+1]==occupe[k-taille][l+1])
         && (tab[k+taille][l]==occupe[k+taille][l] && tab[k+taille][l+1]==occupe[k+taille][l+1])
         && (tab[k+1][l]==occupe[k+1][l] && tab[k+1][l+1]==occupe[k+1][l+1])
         && (tab[k-taille+1][l]==occupe[k-taille+1][l] && tab[k-taille+1][l+1]==occupe[k-taille+1][l+1])
         && (tab[k+taille+1][l]==occupe[k+taille+1][l] && tab[k+taille+1][l+1]==occupe[k+taille+1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger a droite 
      if( k%taille==taille-1 && (tab[k-1][l]==occupe[k-1][l] && tab[k-1][l+1]==occupe[k-1][l+1])
         && (tab[k-taille][l]==occupe[k-taille][l] && tab[k-taille][l+1]==occupe[k-taille][l+1])
         && (tab[k+taille][l]==occupe[k+taille][l] && tab[k+taille][l+1]==occupe[k+taille][l+1])
         && (tab[k-taille-1][l]==occupe[k-taille-1][l] && tab[k-taille-1][l+1]==occupe[k-taille-1][l+1])
         && (tab[k+taille-1][l]==occupe[k+taille-1][l] && tab[k+taille-1][l+1]==occupe[k+taille-1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en haut
      if( tab[0][l]<=tab[k][l] && tab[k][l]<=tab[taille-1][l] && tab[0][l+1]<=tab[k][l+1] && tab[k][l+1]<=tab[taille-1][l+1] && (tab[k-1][l]==occupe[k-1][l] && tab[k-1][l+1]==occupe[k-1][l+1])
         && (tab[k+taille][l]==occupe[k+taille][l] && tab[k+taille][l+1]==occupe[k+taille][l+1])
         && (tab[k+1][l]==occupe[k+1][l] && tab[k+1][l+1]==occupe[k+1][l+1])
         && (tab[k+taille-1][l]==occupe[k+taille-1][l] && tab[k+taille-1][l+1]==occupe[k+taille-1][l+1])
         && (tab[k+taille+1][l]==occupe[k+taille+1][l] && tab[k+taille+1][l+1]==occupe[k+taille+1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en bas
      if( tab[d-taille+1][l]<=tab[k][l] && tab[k][l]<=tab[d-1][l] && tab[d-taille+1][l+1]<=tab[k][l+1] && tab[k][l+1]<=tab[d-1][l+1] && (tab[k-1][l]==occupe[k-1][l] && tab[k-1][l+1]==occupe[k-1][l+1])
         && (tab[k-taille][l]==occupe[k-taille][l] && tab[k-taille][l+1]==occupe[k-taille][l+1])
         && (tab[k+1][l]==occupe[k+1][l] && tab[k+1][l+1]==occupe[k+1][l+1])
         && (tab[k-taille-1][l]==occupe[k-taille-1][l] && tab[k-taille-1][l+1]==occupe[k-taille-1][l+1])
         && (tab[k-taille+1][l]==occupe[k-taille+1][l] && tab[k-taille+1][l+1]==occupe[k-taille+1][l+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en haut a gauche
      if( tab[k][j]==tab[0][j] && tab[k][j+1]==tab[0][j+1] && (tab[k+taille][j]==occupe[k+taille][j] && tab[k+taille][j+1]==occupe[k+taille][j+1])
         && (tab[k+1][j]==occupe[k+1][j] && tab[k+1][j+1]==occupe[k+1][j+1])
         && (tab[k+taille+1][j]==occupe[k+taille+1][j] && tab[k+taille+1][j+1]==occupe[k+taille+1][j+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en haut a droite
      if( tab[k][j]==tab[taille-1][j] && tab[k][j+1]==tab[taille-1][j+1] && (tab[k-1][j]==occupe[k-1][j] && tab[k-1][j+1]==occupe[k-1][j+1])
         && (tab[k+taille][j]==occupe[k+taille][j] && tab[k+taille][j+1]==occupe[k+taille][j+1])
         && (tab[k+taille-1][j]==occupe[k+taille-1][j] && tab[k+taille-1][j+1]==occupe[k+taille-1][j+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en bas a gauche
      if( tab[k][j]==tab[d-taille][j] && tab[k][j+1]==tab[d-taille][j+1] && (tab[k-taille][j]==occupe[k-taille][j] && tab[k-taille][j+1]==occupe[k-taille][j+1])
         && (tab[k+1][j]==occupe[k+1][j] && tab[k+1][j+1]==occupe[k+1][j+1])
         && (tab[k-taille+1][j]==occupe[k-taille+1][j] && tab[k-taille+1][j+1]==occupe[k-taille+1][j+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion2 ne peut plus bouger en bas a droite
      if(tab[k][j]==tab[d-1][j] && tab[k][j+1]==tab[d-1][j+1] && (tab[k-1][j]==occupe[k-1][j] && tab[k-1][j+1]==occupe[k-1][j+1])
         && (tab[k-taille][j]==occupe[k-taille][j] && tab[k-taille][j+1]==occupe[k-taille][j+1])
         && (tab[k-taille-1][j]==occupe[k-taille-1][j] && tab[k-taille-1][j+1]==occupe[k-taille-1][j+1]) ){
          gagnant=1;
          sleep(1);
          return gagnant;
      }

      //----------------------------------pion 1--------------------------------//
      //fin du jeu si pion1 ne peut plus bouger
      if( (tab[i-1][j]==occupe[i-1][j] && tab[i-1][j+1]==occupe[i-1][j+1])
         && (tab[i-taille][j]==occupe[i-taille][j] && tab[i-taille][j+1]==occupe[i-taille][j+1])
         && (tab[i+taille][j]==occupe[i+taille][j] && tab[i+taille][j+1]==occupe[i+taille][j+1])
         && (tab[i+1][j]==occupe[i+1][j] && tab[i+1][j+1]==occupe[i+1][j+1])
         && (tab[i-taille-1][j]==occupe[i-taille-1][j] && tab[i-taille-1][j+1]==occupe[i-taille-1][j+1])
         && (tab[i-taille+1][j]==occupe[i-taille+1][j] && tab[i-taille+1][j+1]==occupe[i-taille+1][j+1])
         && (tab[i+taille-1][j]==occupe[i+taille-1][j] && tab[i+taille-1][j+1]==occupe[i+taille-1][j+1])
         && (tab[i+taille+1][j]==occupe[i+taille+1][j] && tab[i+taille+1][j+1]==occupe[i+taille+1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger a gauche
      if( i%taille==0 && (tab[i-taille][l]==occupe[i-taille][l] && tab[i-taille][l+1]==occupe[i-taille][l+1])
         && (tab[i+taille][l]==occupe[i+taille][l] && tab[i+taille][l+1]==occupe[i+taille][l+1])
         && (tab[i+1][l]==occupe[i+1][l] && tab[i+1][l+1]==occupe[i+1][l+1])
         && (tab[i-taille+1][l]==occupe[i-taille+1][l] && tab[i-taille+1][l+1]==occupe[i-taille+1][l+1])
         && (tab[i+taille+1][l]==occupe[i+taille+1][l] && tab[i+taille+1][l+1]==occupe[i+taille+1][l+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger a droite 
      if( i%taille==taille-1 && (tab[i-1][l]==occupe[i-1][l] && tab[i-1][l+1]==occupe[i-1][l+1])
         && (tab[i-taille][l]==occupe[i-taille][l] && tab[i-taille][l+1]==occupe[i-taille][l+1])
         && (tab[i+taille][l]==occupe[i+taille][l] && tab[i+taille][l+1]==occupe[i+taille][l+1])
         && (tab[i-taille-1][l]==occupe[i-taille-1][l] && tab[i-taille-1][l+1]==occupe[i-taille-1][l+1])
         && (tab[i+taille-1][l]==occupe[i+taille-1][l] && tab[i+taille-1][l+1]==occupe[i+taille-1][l+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en bas
      if( tab[d-taille+1][l]<=tab[i][l] && tab[i][l]<=tab[d-1][l] && tab[d-taille+1][l+1]<=tab[i][l+1] && tab[i][l+1]<=tab[d-1][l+1] && (tab[i-1][l]==occupe[i-1][l] && tab[i-1][l+1]==occupe[i-1][l+1])
         && (tab[i-taille][l]==occupe[i-taille][l] && tab[i-taille][l+1]==occupe[i-taille][l+1])
         && (tab[i+1][l]==occupe[i+1][l] && tab[i+1][l+1]==occupe[i+1][l+1])
         && (tab[i-taille-1][l]==occupe[i-taille-1][l] && tab[i-taille-1][l+1]==occupe[i-taille-1][l+1])
         && (tab[i-taille+1][l]==occupe[i-taille+1][l] && tab[i-taille+1][l+1]==occupe[i-taille+1][l+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en haut
      if( tab[0][l]<=tab[i][l] && tab[i][l]<=tab[taille-1][l] && tab[0][l+1]<=tab[i][l+1] && tab[i][l+1]<=tab[taille-1][l+1] && (tab[i-1][l]==occupe[i-1][l] && tab[i-1][l+1]==occupe[i-1][l+1])
         && (tab[i+taille][l]==occupe[i+taille][l] && tab[i+taille][l+1]==occupe[i+taille][l+1])
         && (tab[i+1][l]==occupe[i+1][l] && tab[i+1][l+1]==occupe[i+1][l+1])
         && (tab[i+taille-1][l]==occupe[i+taille-1][l] && tab[i+taille-1][l+1]==occupe[i+taille-1][l+1])
         && (tab[i+taille+1][l]==occupe[i+taille+1][l] && tab[i+taille+1][l+1]==occupe[i+taille+1][l+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en haut a gauche
      if( tab[i][j]==tab[0][j] && tab[i][j+1]==tab[0][j+1] && (tab[i+taille][j]==occupe[i+taille][j] && tab[i+taille][j+1]==occupe[i+taille][j+1])
         && (tab[i+1][j]==occupe[i+1][j] && tab[i+1][j+1]==occupe[i+1][j+1])
         && (tab[i+taille+1][j]==occupe[i+taille+1][j] && tab[i+taille+1][j+1]==occupe[i+taille+1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en haut a droite
      if( tab[i][j]==tab[taille-1][j] && tab[i][j+1]==tab[taille-1][j+1] && (tab[i-1][j]==occupe[i-1][j] && tab[i-1][j+1]==occupe[i-1][j+1])
         && (tab[i+taille][j]==occupe[i+taille][j] && tab[i+taille][j+1]==occupe[i+taille][j+1])
         && (tab[i+taille-1][j]==occupe[i+taille-1][j] && tab[i+taille-1][j+1]==occupe[i+taille-1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en bas a gauche
      if( tab[i][j]==tab[d-taille][j] && tab[i][j+1]==tab[d-taille][j+1] && (tab[i-taille][j]==occupe[i-taille][j] && tab[i-taille][j+1]==occupe[i-taille][j+1])
         && (tab[i+1][j]==occupe[i+1][j] && tab[i+1][j+1]==occupe[i+1][j+1])
         && (tab[i-taille+1][j]==occupe[i-taille+1][j] && tab[i-taille+1][j+1]==occupe[i-taille+1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      //fin du jeu si pion1 ne peut plus bouger en bas a droite
      if(tab[i][j]==tab[d-1][j] && tab[i][j+1]==tab[d-1][j+1] && (tab[i-1][j]==occupe[i-1][j] && tab[i-1][j+1]==occupe[i-1][j+1])
         && (tab[i-taille][j]==occupe[i-taille][j] && tab[i-taille][j+1]==occupe[i-taille][j+1])
         && (tab[i-taille-1][j]==occupe[i-taille-1][j] && tab[i-taille-1][j+1]==occupe[i-taille-1][j+1]) ){
          gagnant=2;
          sleep(1);
          return gagnant;
      }

      if(SourisCliquee()&&verif==2){
        SourisPosition();
        x=_X;
        y=_Y;

        //interdit le déplacement du pion2 sur le pion1
        if( (occupe[i][j]<x && x<occupe[i][j]+occupe[i][j+2]) && (occupe[i][j+1]<y && y<occupe[i][j+1]+occupe[i][j+3]) ){
          rouge=1;
        }

        for(p=0;p<taille*taille;p++){
          if( (occupe[p][j]<x && x<occupe[p][j]+occupe[p][j+2]) && (occupe[p][j+1]<y && y<occupe[p][j+1]+occupe[p][j+3]) && rouge==0 ){
            rouge=1;
          }
        }

        //aller à gauche
        if ( (tab[k-1][l]<x && x<tab[k][l]) && (tab[k-1][l+1]<y && y<tab[k-1][l+1]+tab[k-1][l+3]) &&rouge==0 ){
          DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
          DessinerSceneDEUX(2,tab[k-1][l],tab[k-1][l+1],taille);
          k=k-1;
          verif=3;
        }
        //aller en haut    
        else if ( (tab[k-taille][l]<x && x<tab[k-taille][l]+tab[k-taille][l+2]) && (tab[k][l+1]-tab[k][l+3]<y && y<tab[k][l+1])&&rouge==0 ){
          DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
          DessinerSceneDEUX(2,tab[k-taille][l],tab[k-taille][l+1],taille);
          k=k-taille;
          verif=3;
        }
        //aller en bas
        else if ( (tab[k+taille][l]<x && x<tab[k+taille][l]+tab[k+taille][l+2]) && (tab[k+taille][l+1]<y && y<tab[k+taille][l+1]+tab[k+taille][l+3]) &&rouge==0 ){
          DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
          DessinerSceneDEUX(2,tab[k+taille][l],tab[k+taille][l+1],taille);
          k=k+taille;
          verif=3;
        }
        //aller à droite
        else if ( (tab[k+1][l]<x && x<tab[k+1][l]+tab[k+1][l+2]) && (tab[k+1][l+1]<y && y<tab[k+1][l+1]+tab[k+1][l+3]) &&rouge==0 ){
          DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
          DessinerSceneDEUX(2,tab[k+1][l],tab[k+1][l+1],taille);
          k=k+1;
          verif=3;
        }
        //diagonale haut/gauche
        else if ( (tab[k-taille-1][l]<x && x<tab[k-taille-1][l]+tab[k-taille-1][l+2]) && (tab[k-1][l+1]-tab[k-1][l+3]<y && y<tab[k-1][l+1]) &&rouge==0 ){
          DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
          DessinerSceneDEUX(2,tab[k-taille-1][l],tab[k-taille-1][l+1],taille);
          k=k-taille-1;
          verif=3;
        }
        //diagonale haut/droite
        else if ( (tab[k-taille+1][l]<x && x<tab[k-taille+1][l]+tab[k-taille+1][l+2]) && (tab[k+1][l+1]-tab[k+1][l+3]<y && y<tab[k+1][l+1])&&rouge==0  ){
          DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
          DessinerSceneDEUX(2,tab[k-taille+1][l],tab[k-taille+1][l+1],taille);
          k=k-taille+1;
          verif=3;
        } 
        //diagonale bas/gauche
        else if ( (tab[k+taille-1][l]<x && x<tab[k+taille-1][l]+tab[k+taille-1][l+2]) && (tab[k+taille-1][l+1]<y && y<tab[k+taille-1][l+1]+tab[k+taille-1][l+3]) &&rouge==0 ){
          DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
          DessinerSceneDEUX(2,tab[k+taille-1][l],tab[k+taille-1][l+1],taille);
          k=k+taille-1;
          verif=3;
        } 
        //diagonale bas/droite
        else if ( (tab[k+taille+1][l]<x && x<tab[k+taille+1][l]+tab[k+taille+1][l+2]) && (tab[k+taille+1][l+1]<y && y<tab[k+taille+1][l+1]+tab[k+taille+1][l+3])&&rouge==0  ){
          DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
          DessinerSceneDEUX(2,tab[k+taille+1][l],tab[k+taille+1][l+1],taille);
          k=k+taille+1;
          verif=3;
        }
        if (verif==3){
          occupe[k][l]=tab[k][l];
          occupe[k][l+1]=tab[k][l+1];
          occupe[k][l+2]=tab[k][l+2];
          occupe[k][l+3]=tab[k][l+3];
        }
      }
    }

//--------------Croix dans cases--------------//
    while(verif==3){
      if(SourisCliquee()){
        SourisPosition();
        x=_X;
        y=_Y;

        for(z=0;z<taille*taille;z++){
          if ( (tab[z][j]<x && x<tab[z][j]+tab[z][j+2]) && (tab[z][j+1]<y && y<tab[z][j+1]+tab[z][j+3]) ){
            if (tab[z][j]!=occupe[z][j]){                    
              ChoisirEcran(2);
              c=CouleurParNom("black");
              ChoisirCouleurDessin(c);
              CopierZone(2,1,0,0,tx,ty,0,0);
              DessinerSegment(tab[z][j],tab[z][j+1],tab[z][j]+tab[z][j+2],tab[z][j+1]+tab[z][j+3]);
              DessinerSegment(tab[z][j],tab[z][j+1]+tab[z][j+3],tab[z][j]+tab[z][j+2],tab[z][j+1]);
              CopierZone(1,0,0,0,tx,ty,0,0);
              occupe[z][j]=tab[z][j];
              occupe[z][j+1]=tab[z][j+1];
              occupe[z][j+2]=tab[z][j+2];
              occupe[z][j+3]=tab[z][j+3];
              DessinerSceneDEUX(1,tab[i][j],tab[i][j+1],taille);
              DessinerSceneDEUX(2,tab[k][l],tab[k][l+1],taille);
              verif=0;
            }
          }
        }
      }
    }
  } 
    return -1;
  }