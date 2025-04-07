#include <stdio.h>
#include <stdlib.h>

 liste* creer_liste_produits()
 {
 liste * B=NULL;
return B;
 }


 int est_vide(liste* tete)
 {
 if(tete==NULL)
 {
 return 1;
 }
 return 0;
 }


  liste* creer_produit()
 {
 liste * B=(liste*)malloc(sizeof(liste));
 printf("Entrer le nom du produit :");
 B->cellule.Nom_produit=(char*)malloc(100*sizeof(char));
 gets(B->cellule.Nom_produit);
 printf("Veuillez saisir le reference:");
 gets(B->cellule.Reference);
 printf("Veuillez saisir le montant");
 scanf("%f",&B->cellule.Montant);
 printf("Veuillez saisir le jour :");
 scanf("%s",B->cellule.DateAchat.jour);
 printf("Veuillez saisir le mois :");
 scanf("%s",B->cellule.DateAchat.mois);
 printf("Veuillez saisir l'annee :");
 scanf("%s",B->cellule.DateAchat.annee);
 return B;
 }

 void afficher_produit(liste* B)
{
printf("Nom du produit : %s\n",B->cellule.Nom_produit);
 printf("Reference : %s\n",B->cellule.Reference);
printf("Montant : %f\n",B->cellule.Montant);
 printf("Date d'achat :%s/%s/%s\n", B->cellule.DateAchat.jour,B->cellule.DateAchat.mois,B->cellule.DateAchat.annee);
 }

liste* ajouterDebut(liste* tete)
 {
 liste* A=creer_produit();
 if(tete==NULL)
{
 tete=A;
 tete->psuiv=NULL;
 return tete;
 }
A->psuiv=tete;
 tete=A;
 return tete;
 }

  void ajouterFin(liste* tete)
 {
 liste* A=creer_produit();
 if(tete==NULL)
 {
 return ;
 }
 liste *tmp=tete;
 while(tmp->psuiv!=NULL)
 {
 tmp=tmp->psuiv;
}
tmp->psuiv=A;
 A->psuiv=NULL;
 }

  int longueur(liste *tete)
 {
 if(tete==NULL)

{
 return 0;
 }
 liste * tmp=tete;
 int K=0;
 while(tmp!=NULL)
 {
 K++;
 tmp=tmp->psuiv;
 }
return K;
 }

 void filtrer_date(liste* tete, date dt)
{
liste * tmp=tete;
while(tmp!=NULL)
{
if(strcmp(tmp->cellule.DataAchat.jour,dt.jour)==0 &&
 strcmp(tmp->cellule.DataAchat.mois,dt.mois)==0 &&
 strcmp(tmp->cellule.DataAchat.annee,dt.annee)==0)
 {
 afficher_produit(tmp);
 }
 tmp=tmp->suiv;
}
}

liste* supprimerDebut(liste *tete)
 {
 if(tete==NULL)
 {
 return NULL;
}
liste *tmp=tete;
 tete=tete->psuiv;
 free(tmp);
 tmp=NULL;
 return tete;
}

void supprimer_fin(liste * tete)
{
    liste*P;
    if(tete!=NULL){
        if(tete->psuiv==NULL)
        {
        free(tete);
        tete=NULL;
        }
else{
    tete=P;
    while(P->psuiv->psuiv!=NULL){
        P=P->psuiv;}
        free(P->psuiv);
        P->psuiv=NULL;
        }
    }
    }


    liste* renbourser(liste* liste, char* refer)
 {
 if(tete==NULL)
 {
 return NULL;
 }
 if(tete->suiv==NULL&& strcmp(tete->cellule.Reference,refer)==0)
{
 tete=supprimer_Debut(tete);
 return tete;
 }
 liste * pre_tmp=tete;
 liste * tmp=tete->suiv;
while(tmp->suiv!=NULL)
{
    if(strcmp(tmp->cellule.Reference,refer)==0)
 {
 break;
 }
 pre_tmp=tmp;
 tmp=tmp->suiv;
 }
 if(tmp->suiv==NULL)
{
 supprimer_Fin(tete);
 return tete;
 }
 pre_tmp->suiv=tmp->suiv;
 free(tmp);
 tmp=NULL;
 return tete;
 }

  void main()
 {
 liste* C=NULL;
 C=ajouterDebut(C);
 ajouterFin(C);
ajouterFin(C);
 afficher_produits(C);
 C=supprimerDebut(C);
C=renbourser(C,"ss");
 afficher_produits(C);
 }








