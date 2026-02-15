#include<stdio.h>
#include<stdlib.h>
#include <string.h> 

#include "Equipe.h"
#include "Match.h"


int main(){
  Equipe Teq[NB_EQUIPES];      /* Tableau des équipes */
  Match Tmatch[NB_MATCHS];     /* Tableau des matchs */
  int i = 0;

  char nom_eq[MAX_STRING];
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
    // On remplace les sauts de lignes par des un caractère de fin de chaînes de caractère
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
    affiche_equipe(&Teq[j]);
  
  
  
  /* Lecture de la 2eme partie du fichier pour remplir le tableau Tmatch des NB_MATCHS matchs */
  /* Pour cela, il faut rechercher un pointeur sur équipe dans Teq à partir de son nom */

  // char ligne_vide[MAX_STRING];
  // fgets(ligne_vide, MAX_STRING, fic);  // Saute la ligne vide

  for (int k = 0; k < NB_MATCHS; k++)
  {
    int nb_lus = fscanf(fic, "%s %d - %d %s", nom_eq_hote, &score_hote, &score_invite, nom_eq_invite);


    Tmatch[k].eq_hote = rech_ptr_equipe(Teq, NB_EQUIPES, nom_eq_hote);
    Tmatch[k].eq_invite = rech_ptr_equipe(Teq, NB_EQUIPES, nom_eq_invite);
    Tmatch[k].score_hote = score_hote;
    Tmatch[k].score_invite = score_invite;
  }

  

  
  /* Affichage pour test de la liste des matchs */
  afficher_tous_les_matchs(Tmatch, NB_MATCHS);
  
  fclose(fic);

  /* Affichage des résultats des équipes */
  analyse_matchs(Tmatch, NB_MATCHS);
  calcul_points(Teq, NB_EQUIPES);

  afficher_toutes_les_equipes(Teq, NB_EQUIPES);
    
  /* Affichage de l'équipe première au classement */
  printf("\n\n=============================| Equipe première au classement ! |=============================\n");
  affiche_equipe(premier_classement(Teq, NB_EQUIPES));
  printf("\n=============================================================================================\n\n");
  
    
  /* Affichage du classement trié des équipes */
  trier_equipes(Teq, NB_EQUIPES);
    
  printf("\n\n=============================| Classement des équipes |=============================\n\n");
    for (int i = 1; i <= NB_EQUIPES; i++)
    {
      printf("n°%2d ", i);
      affiche_equipe(&(Teq[i - 1]));
      printf("\n");
    }
  printf("\n\n=============================================================================================\n\n");

  return EXIT_SUCCESS;
}
