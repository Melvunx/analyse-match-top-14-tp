#include<stdio.h>
#include<stdlib.h>
#include <string.h> 

#include "Equipe.h"
#include "Match.h"


int main(){
  Equipe Teq[NB_EQUIPES];      /* Tableau des équipes */
  Match Tmatch[NB_MATCHS];     /* Tableau des matchs */
  int i = 0;

  char nom_eq_hote[MAX_STRING], nom_eq_invite[MAX_STRING];
  int score_hote, score_invite;
  
  FILE *fic = fopen("./Top14.txt", "r");
  
  if (!fic){
    printf("Fichier non trouvé\n");
    return EXIT_FAILURE;
  }
  
  /* Lecture du début du fichier pour remplir le tableau Teq des NB_EQUIPES équipes */
  /* et mise à zéros des compteurs des statistiques */
  while (fgets(Teq[i].nom, MAX_STRING, fic) != NULL && i < NB_EQUIPES)
  {
    Teq[i].nom[strcspn(Teq[i].nom, "\n")] = '\0';

    Teq[i].nb_points = 0;
    Teq[i].nb_defaites = 0;
    Teq[i].nb_victoires = 0;
    Teq[i].nb_nuls = 0;
    Teq[i].nb_bonus = 0;

    i++;
  }

  
  
  /* Affichage pour test de la liste des équipes */
  
  for (int j = 0; j < NB_EQUIPES; j++)
  {
    affiche_equipe(&Teq[j]);
  }
  
  
  /* Lecture de la 2eme partie du fichier pour remplir le tableau Tmatch des NB_MATCHS matchs */
  /* Pour cela, il faut rechercher un pointeur sur équipe dans Teq à partir de son nom */


  for (int k = 0; k < NB_MATCHS; k++)
  {
    fscanf(fic, "%s %d - %d %s", nom_eq_hote, &score_hote, &score_invite, nom_eq_invite);

    printf("%s %d %d %s", nom_eq_hote, score_hote, score_invite, nom_eq_invite);
    Tmatch[k].eq_hote = rech_ptr_equipe(Teq, NB_EQUIPES, nom_eq_hote);
    Tmatch[k].eq_invite = rech_ptr_equipe(Teq, NB_EQUIPES, nom_eq_invite);
    Tmatch[k].score_hote = score_hote;
    Tmatch[k].score_invite = score_invite;
  }

  

  
  /* Affichage pour test de la liste des matchs */
  for (int l = 0; l < NB_MATCHS; l++)
  {
    affiche_match(Tmatch[l]);
  }
  
  
  
  fclose(fic);

  /* Affichage des résultats des équipes */
  // for (int i=0;i<NB_EQUIPES;i++)
  //   affiche_equipe(&(Teq[i]));

  /* Affichage de l'équipe première au classement */
  


  /* Affichage du classement trié des équipes */


  return EXIT_SUCCESS;
}
