#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define MaxL 5 /* Taille maximale d'une matrice en nombre de lignes */
# define MaxC 6 /* Taille maximale d'une matrice en nombre de colonnes */
# define V 21  /* Nombre aléatoire */

/* Exemple de fonction pour une matrice statique de taille nxm */
void afficher_matrice (int M[MaxL][MaxC]);

void remplir_matrice(int M[MaxL][MaxC]);

void afficher_nb_frequent_1(int M[MaxL][MaxC]);
void afficher_nb_frequent_2(int M[MaxL][MaxC]);

void remplir_matrice(int M[MaxL][MaxC])
{

  for (int i = 0; i < MaxL; i++)
  {
    for (int j = 0; j < MaxC; j++)
    {
      M[i][j] = rand() % V;
    }
  }
}

void afficher_matrice (int M[MaxL][MaxC])
{
  for (int i = 0; i < MaxL; i++)
  {
    for (int j = 0; j < MaxC; j++)
    {
      printf(" %2d ", M[i][j]);
    }
    printf("\n");
  }
}

void afficher_nb_frequent_1(int M[MaxL][MaxC])
{
  int nombre, somme;
  int max_occurences = 0, valeur_frequente = 0;
  for (int i = 0; i < MaxL; i++)
  {
    for (int j = 0; j < MaxC; j++)
    {
      nombre = M[i][j];
      somme = 0;

      for (int k = 0; k < MaxC; k++)
      {
        for (int l = 0; l < MaxL; l++)
        {
          if (nombre == M[k][l])
          {
            somme += 1;
          }
        }
      }
      
      if (somme > max_occurences)
      {
        max_occurences = somme;
        valeur_frequente = nombre;
      }
    }
  }
  
  printf("\nValeur fréquente : %d \n", valeur_frequente);
}

void afficher_nb_frequent_2(int M[MaxL][MaxC]){
  int Tcompoteur[V] = {0};
  int number, index;
  int max = Tcompoteur[0];

  for (int i = 0; i < MaxL; i++)
  {
    for (int j = 0; j < MaxC; j++)
    {
      number = M[i][j];
      Tcompoteur[number]++;
    }
  }
  
  for (int k = 0; k < V; k++)
  {
    if (max < Tcompoteur[k]) {
      max = Tcompoteur[k];
      index = k;
    }
  }
  
  printf("\nValeur fréquente : %d \n", index);
}

int main()
{
  srand(time(NULL));
  int M[MaxL][MaxC];
  int choice;
  remplir_matrice(M);
  
  afficher_matrice(M);
  do
  {
    printf("Choississez entre 2 méthodes d'algorithme (1 ou 2)\n");
    scanf("%d", &choice);
  } while (choice >= 3 || choice <= 0);
  
  switch (choice)
  {
  case 1:
    afficher_nb_frequent_1(M);
    break;
  case 2:
    afficher_nb_frequent_2(M);
    break;
  }
  
  return 0;
}
