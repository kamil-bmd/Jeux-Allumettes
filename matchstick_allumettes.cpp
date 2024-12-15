#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//PROCEDURE PARAMETRE DE LA PARTIE
void saisie(string &nomJoueur, char &nivOrdi, char &joueurCourant, int &nbAllumettes)
{
    cout << "Quel nom choisissez-vous ?" << endl;
    cin >> nomJoueur;

    do
    {
        cout << "Quel niveau souhaitez-vous pour l'ordinateur ? (N/n pour naïf ou E/e pour expert)" << endl;
        cin >> nivOrdi;
    } while (nivOrdi != 'E' && nivOrdi != 'e' && nivOrdi != 'N' && nivOrdi != 'n');

    do
    {
        cout << "Combien d'allumettes voulez-vous ? (entre 1 et 30)" << endl;
        cin >> nbAllumettes;
    } while (nbAllumettes > 30 || nbAllumettes < 1);

    do
    {
        cout << "Quel est le premier joueur à jouer ? (U/u pour l'utilisateur ou O/o pour l'ordinateur" << endl;
        cin >> joueurCourant;
    } while (joueurCourant != 'U' && joueurCourant != 'u' && joueurCourant != 'O' && joueurCourant != 'o');
}

// PROCEDURE AFFICHAGE ALLUMETTES
void affiche(int nbAllumettes)
{
    int i, j, reste, k ;
    reste=nbAllumettes%5;

    for (i = 1; i <= nbAllumettes/5; i = i + 1)
    {
        for (j = 1; j <= 5; j = j + 1)
        {
            cout<< "|";
        }
        
        cout<< endl;
    }
    for (k = 1 ; k <= reste; k = k + 1)
    {
        cout<< "|";

    }
    cout<<endl;
}

// //3) PROCEDURE MISE A JOUR NOMBRE D'ALLUMETTES
void miseAJour(int &nbAllumettes, int nb)
{
    nbAllumettes = nbAllumettes - nb;
}

//4) FONCTION ORDINATEUR JOUE
int joueOrdi(char nivOrdi, int nbAllumettes)
{
    int a, nb;
    char s;
    int nbChoixOrdi;
    srand(time(NULL));
    cout << "L'ordinateur joue !" << endl;
    if (nivOrdi == 'N' || nivOrdi == 'n')
    {
        nbChoixOrdi = rand() % 4;
        cout << "L'ordinateur pioche " << nbChoixOrdi << " allumettes." << endl;
    }
    else
    {

        if (( nbAllumettes % 4) == 2)
        {
            cout << "L'ordinateur pioche 1 allumettes." << endl;
            nbChoixOrdi = 1;
        }
        
        else if (( nbAllumettes % 4) == 1)
        {
            cout << "L'ordinateur pioche 2 allumettes." << endl;
            nbChoixOrdi = 2;
        }
        
        else if(( nbAllumettes % 4) == 0)
        {
            cout << "L'ordinateur pioche 3 allumettes." << endl;
            nbChoixOrdi = 3;
        }
        else if(( nbAllumettes % 4) == 3)
        {
            cout << "L'ordinateur pioche 2 allumettes." << endl;
            nbChoixOrdi = 2;
        }
    }
    return nbChoixOrdi;
}

//5) FONCTION JOUEUR JOUE
int joueJoueur(string nomJoueur, int &nbAllumettes)
{
    int nbChoixJoueur = 0;

    if (nbAllumettes == 2)
    {
        do
        {
            cout << "Le joueur " << nomJoueur << ", c'est ton tour de jouer." << endl;
            cout << "Il reste " << nbAllumettes << " prends 1 ou 2 allumettes." << endl;
            cin >> nbChoixJoueur;
        } while (nbChoixJoueur > 2);
    }
    else if (nbAllumettes == 1)
    {
        cout << "C'est perdu. :(" << endl;
        nbChoixJoueur = 1;
    }
    else
    {
        do
        {
            cout << "Le joueur " << nomJoueur << ", c'est ton tour de jouer." << endl;
            cout << "Il reste " << nbAllumettes << " prends 1, 2 ou 3 allumettes." << endl;
            cin >> nbChoixJoueur;
        } while (nbChoixJoueur > 3);
    }
    return nbChoixJoueur;
}

void jeuAlterne(char &joueurCourant, char nivOrdi, string nomJoueur, int &nbAllumettes)
{
    int nb = 0;
    if (joueurCourant == 'O' || joueurCourant == 'o')
    {
        nb = joueOrdi(nivOrdi, nbAllumettes);
    }
    else
    {
        nb = joueJoueur(nomJoueur, nbAllumettes);
    }
    miseAJour(nbAllumettes, nb);
    affiche(nbAllumettes);
    if (joueurCourant == 'O' || joueurCourant == 'o')
    {
        joueurCourant = 'U';
    }
    else
    {
        joueurCourant = 'O';
    }
}

// TACHE PRINCIPALE
int main()
{
    string nomJoueur;
    char nivOrdi, joueurCourant;
    int nbAllumettes;
    
    cout<<"JEU DES ALLUMETTES"<<endl;
    
    saisie(nomJoueur, nivOrdi, joueurCourant, nbAllumettes);

    affiche(nbAllumettes);

    while (nbAllumettes > 0)
    {
        jeuAlterne(joueurCourant, nivOrdi, nomJoueur, nbAllumettes);
    }
    if ((joueurCourant == 'U' || joueurCourant == 'u'))
    {
        cout << nomJoueur << " a gagné !!!" << endl;
    }
    else
    {
        cout << "L'ordinateur a gagné !!!" << endl;
    }
    cout<<"FIN DE LA PARTIE";

    return 0;
}
