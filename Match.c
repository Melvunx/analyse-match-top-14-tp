#include <stdio.h>
#include "Match.h"
#include "Equipe.h"


/* Affiche les donnés d'un match dont les données sont passées par copie*/
void affiche_match(Match m){
    printf("\n%6s %2d - %2d %s\n", m.eq_hote->nom,m.score_hote,m.score_invite,m.eq_invite->nom);
}

void afficher_tous_les_matchs(Match Tmatch[], int n)
{
  printf("\n\n=============================| Affichage des matchs |=============================\n\n");
    for (int i = 0; i < n; i++)
        affiche_match(Tmatch[i]);
  printf("\n\n==================================================================================\n\n");
    
}

/* Calcule les statistiques de victoire, nul, défaites et bonus
   des équipes à partir du tableau Tmatch des n matchs */
void analyse_matchs(Match Tmatch[], int n){
    for (int i = 0; i < n; i++){
        Match m = Tmatch[i];
        Equipe *hote = m.eq_hote;
        Equipe *invite = m.eq_invite;

        if (m.score_hote == m.score_invite){
            hote->nb_nuls++;
            invite->nb_nuls++;
        }
        else if (m.score_hote > m.score_invite){
            hote->nb_victoires++;
            invite->nb_defaites++;
            if (m.score_hote - m.score_invite <= 5)
                invite->nb_bonus++;
        }
        else{
            invite->nb_victoires++;
            hote->nb_defaites++;
            if (m.score_invite - m.score_hote <= 5)
                hote->nb_bonus++;
        }
    }
}
