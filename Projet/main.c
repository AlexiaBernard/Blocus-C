#include<graph.h>
#include<stdio.h>
#include<stdlib.h>
#include"affiche.h"
#include"jeux.h"
#include"menu.h"

int main(void) {

	int gagnant, x, n=1, joueur;

	InitialiserGraphique();
    CreerFenetre(500,200,tx,ty);
    ChoisirTitreFenetre("Blocus");

	while (n==1){
		x=menu();

		if (x==31){
			gagnant=jeux(3,1);
			joueur=1;
		}
		if (x==41){
			gagnant=jeux(4,1);
			joueur=1;
		}
		if (x==51){
			gagnant=jeux(5,1);
			joueur=1;
		}
		if (x==61){
			gagnant=jeux(6,1);
			joueur=1;
		}
		if (x==71){
			gagnant=jeux(7,1);
			joueur=1;
		}
		if (x==81){
			gagnant=jeux(8,1);
			joueur=1;
		}
		if (x==91){
			gagnant=jeux(9,1);
			joueur=1;
		}
		if (x==32){
			gagnant=jeux(3,2);
			joueur=2;
		}
		if (x==42){
			gagnant=jeux(4,2);
			joueur=2;
		}
		if (x==52){
			gagnant=jeux(5,2);
			joueur=2;
		}
		if (x==62){
			gagnant=jeux(6,2);
			joueur=2;
		}
		if (x==72){
			gagnant=jeux(7,2);
			joueur=2;
		}
		if (x==82){
			gagnant=jeux(8,2);
			joueur=2;
		}
		if (x==92){
			gagnant=jeux(9,2);
			joueur=2;
		}

		n=affiche(gagnant, joueur);
	}
	FermerGraphique();
	return EXIT_SUCCESS;
}