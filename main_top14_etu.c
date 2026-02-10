#include<stdio.h>
#include<stdlib.h>

#include "Equipe.h"
#include "Match.h"


int main(){
  Equipe Teq[NB_EQUIPES];      /* Tableau des équipes */
  Match Tmatch[NB_MATCHS];     /* Tableau des matchs */

  FILE *fic = fopen("Top14.txt", "r");

  if (!fic){
    printf("Fichier non trouvé\n");
    return EXIT_FAILURE;
  }

  /* Lecture du début du fichier pour remplir le tableau Teq des NB_EQUIPES équipes */
  /* et mise à zéros des compteurs des statistiques */

  
  /* Affichage pour test de la liste des équipes */


  
  /* Lecture de la 2eme partie du fichier pour remplir le tableau Tmatch des NB_MATCHS matchs */
  /* Pour cela, il faut rechercher un pointeur sur équipe dans Teq à partir de son nom */

  /* Affichage pour test de la liste des matchs */


  fclose(fic);

  

  /* Affichage des résultats des équipes */
  for (int i=0;i<NB_EQUIPES;i++)
    affiche_equipe(&(Teq[i]));

  /* Affichage de l'équipe première au classement */
  


  /* Affichage du classement trié des équipes */


  return EXIT_SUCCESS;
}
