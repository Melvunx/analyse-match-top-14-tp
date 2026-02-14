#include "Equipe.h"
#include <stdio.h>


void affiche_equipe(const Equipe *eq){
  printf("%s %d pts (G:%d N:%d P:%d B:%d)\n", 
    eq->nom, eq->nb_points, eq->nb_victoires,
     eq->nb_nuls, eq->nb_defaites, eq->nb_bonus);
}

/* Renvoie un pointeur sur une équipe sotckée dans le tableau Teq de n cases
   et qui a le nom passé en paramètre */
Equipe* rech_ptr_equipe(Equipe Teq[], int n, char nom[]){
  Equipe *eq;

  for (int i = 0; i < n; i++)
  {
    if (nom == Teq[i].nom)
    {
      *eq = Teq[i];
      break;
    }
  }

  return eq;
}

/* Calcul du nombre total de points pour chacune des n équipes */
void calcul_points(Equipe Teq[], int n){}

/* Retourne un pointeur sur la premiere equipe du classement parmi les n équipes*/
Equipe* premier_classement(Equipe Teq[], int n){}

/* Retourne l'indice du tableau Teq de l'équipe de plus grand score 
   à partir de l'incide d entre 0 et n-1*/
int max_indice(Equipe Teq[], int n, int d){}

/* Tri par sélection des équipes par score du tableau des n équipes*/
void trier_equipes(Equipe Teq[], int n){}