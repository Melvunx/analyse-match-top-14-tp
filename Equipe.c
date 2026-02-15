#include "Equipe.h"
#include <stdio.h>
#include <string.h> 


void affiche_equipe(const Equipe *eq){
  printf("\n%6s %2d pts (G:%2d N:%2d P:%2d B:%2d)\n", 
    eq->nom, eq->nb_points, eq->nb_victoires,
     eq->nb_nuls, eq->nb_defaites, eq->nb_bonus);
}

void afficher_toutes_les_equipes(Equipe Teq[], int n)
{
    printf("\n\n=============================| Affichage des équipes |=============================\n\n");
    for (int i = 0; i < n; i++)
      affiche_equipe(&Teq[i]);
    printf("\n\n===================================================================================\n\n");
}

/* Renvoie un pointeur sur une équipe sotckée dans le tableau Teq de n cases
   et qui a le nom passé en paramètre */
Equipe* rech_ptr_equipe(Equipe Teq[], int n, char nom[]){
  Equipe *equipe_recherchee;

  for (int i = 0; i < n; i++)
  {
    
    if (!strcmp(nom, Teq[i].nom))
    {
      equipe_recherchee = &Teq[i];
      return equipe_recherchee;
    }
  }

  return NULL;
}

/* Calcul du nombre total de points pour chacune des n équipes */
void calcul_points(Equipe Teq[], int n){
  int points;

  for (int i=0; i<n; i++){
    points = 0;

    points += Teq[i].nb_victoires * 4;
    points +=Teq[i].nb_nuls * 2;
    points +=Teq[i].nb_bonus;

    Teq[i].nb_points= points;
  }
}

/* Retourne un pointeur sur la premiere equipe du classement parmi les n équipes*/
Equipe* premier_classement(Equipe Teq[], int n){
  int indice_premiere = 0;

  for (int i = 1; i < n; i++) {
    if (Teq[i].nb_points> Teq[indice_premiere].nb_points){
      indice_premiere = i;
    }
  }

  return &Teq[indice_premiere];
}

/* Retourne l'indice du tableau Teq de l'équipe de plus grand score 
   à partir de l'incide d entre 0 et n-1*/
int max_indice(Equipe Teq[], int n, int d){
  int indice_max = d;

  for (int i = d + 1; i < n; i++) {
    if (Teq[i].nb_points > Teq[indice_max].nb_points) {
      indice_max = i;
    }
  }
  return indice_max;
}

/* Tri par sélection des équipes par score du tableau des n équipes*/
void trier_equipes(Equipe Teq[], int n){
  for (int i = 0; i < n - 1; i++) {
    int indice_max = max_indice(Teq, n, i);
    Equipe temporaire = Teq[i];
    Teq[i]=Teq[indice_max];
    Teq[indice_max]= temporaire;
  }
}
