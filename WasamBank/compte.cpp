#include "compte.hpp"
#include <limits>
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "loading.hpp"
#include <conio.h>
using namespace std;
information *tete = nullptr;
int p;
information tableau[tab];
int i, j;

int random()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1000, 9999);
    int nombrealeatoire = distrib(gen);
    return nombrealeatoire;
}
void erreur(const string &sms)
{
    cout << "Vous avez un message : " << sms << endl;
}

bool verification(double numero)
{
    for (int j = 0; j < i; ++j)
    {
        if (tableau[j].numero == numero)
        {
            return true;
        }
    }
    return false;
}

int rechercheCompte(double numero)
{
    for (int j = 0; j < i; j++)
    {
        if (tableau[j].numero == numero)
        {
            return j;
        }
    }
    return -1;
}
void Menuprincipal()
{
    // bienvenue
    cout << ".................. BIENVENU A WASAM BANK CHER CLIENT ! ..............." << endl;
    cout << "......................................................................" << endl;
    cout << "|                       ...  Menu Principal  ...                     |" << endl;
    cout << "+....................................................................+" << endl;
    cout << "    |                                                                |" << endl;
    cout << "    |   1. Methode A - Tableau Statique                              |" << endl;
    cout << "    |                                                                |" << endl;
    cout << "    |   2. Methode B - Liste Chainee Dynamique                       |" << endl;
    cout << "    |                                                                |" << endl;
    cout << "    |   3 - Quitter le programme                                     |" << endl;
    cout << "    |                                                                |" << endl;
    cout << "    |  Quelle methode souhaitez-vous que le programme execute ?      |" << endl;
    cout << "    |................................................................|" << endl;
    cout << "Methode choisie :  ";
}

void menugestioncompte()
{
    loading();
    int choix;

    do
    {

        cout << "............................................................................/n" << endl;
        cout << "|     Excellent choix, vous avez choisi la Methode A (Tableau Statique).   |/n" << endl;
        cout << "+..........................................................................+/n/n" << endl;
        cout << "1 - Gestion des comptes \n";
        cout << "2 - Transaction des comptes \n";
        cout << "3 - Quitter le sous menu Principal \n";
        cout << "Choisir une option : ";
        cin >> choix;

        while (cin.fail() || choix < 1 || choix > 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // erreur("Vous avez fait une entree incorrecte. Veuillez recommencer SVP.");
            cout << "+....................................................................+/n" << endl;
            cout << "| ERROR, Restez concentre !!!                                        |/n" << endl;
            cout << "| Veillez à entrer un choix valide.                                  |/n" << endl;
            cout << "+....................................................................+/n/n" << endl;
            cout << "Choisir une option : ";
            cin >> choix;
        }

        switch (choix)
        {
        case 1:
            gestioncompte();
            break;
        case 2:
            gestiontransaction();
            break;
        case 3:
            cout << "Vous avez quitte le sous menu Principal.\n";
            return;
        }
    } while (true);
}

void gestioncompte()
{
    loading();
    int choix;
    do
    {

        cout << "......................................................................" << endl;
        cout << "|             ... PROGRAMME UTILISE : TABLEAU STATIC ...             |" << endl;
        cout << "+....................................................................+" << endl;
        cout << "......................................................................" << endl;
        cout << "|                        Gestion des Comptes                         |" << endl;
        cout << "+....................................................................+\n"
             << endl;

        cout << "......................................................................" << endl;
        cout << "|           |1. Ajouter un compte                                    |" << endl;
        cout << "|           |2. Supprimer un compte                                  |" << endl;
        cout << "|           |3. Modifier un compte                                   |" << endl;
        cout << "|           |4. Afficher tous les comptes                            |" << endl;
        cout << "|           |5. Retour au Menu Principal                             |" << endl;
        cout << "+....................................................................+/" << endl;
        cout << "|             Choisissez une option :  " << endl;
        cin >> choix;

        while (cin.fail() || choix < 1 || choix > 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEntree incorrecte. Veillez a entrer un choix valide." << endl;
            cout << "Choisir une option : ";
            cin >> choix;
        }

        switch (choix)
        {
        case 1:

            Ajouter();

            break;
        case 2:

            Supprimer();
            break;
        case 3:

            modifier();

            break;
        case 4:
            save();
            affichertouslescomptes();

            break;
        case 5:
            cout << "Retour au menu principal...\n";
            return;
        }
    } while (true);
}

void gestiontransaction()
{
    loading();
    int choix;
    do
    {
        cout << "......................................................................" << endl;
        cout << "|             ... PROGRAMME UTILISE : TABLEAU static ...             |" << endl;
        cout << "+....................................................................+" << endl;
        cout << "......................................................................" << endl;
        cout << "|                        Gestion des Comptes                         |" << endl;
        cout << "+....................................................................+" << endl;

        cout << "......................................................................" << endl;
        cout << "|         1 - Verser une somme dans un compte                        |" << endl;
        cout << "|         2 - Retirer une somme d'un compte                          |" << endl;
        cout << "|         3 - Virer une somme d'un compte vers un autre              |" << endl;
        cout << "|         4 - Afficher un compte                                     |" << endl;
        cout << "|         5 - Afficher tous les comptes                              |" << endl;
        cout << "|         6 - Quitter le sous menu (retour au sous menu principal)   |" << endl;
        cout << "+....................................................................+" << endl;
        cout << "Choisissez une option :  ";
        cin >> choix;

        while (cin.fail() || choix < 1 || choix > 6)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entree incorrecte. Veuillez recommencer.\n";
            cout << "Choisissez une option : ";
            cin >> choix;
        }

        switch (choix)
        {
        case 1:
        {
            double numero, montant;
            cout << "Donnez votre numero de compte :";
            cin >> numero;
            while (true)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    erreur("Veuillez entrer un nombre valide pour le numero de compte!!!");
                }
                else if (numero < 0)
                {
                    cout << "le numero doit etre positif!!!";
                }
                else if (!verification(numero))
                {
                    erreur("le numero de compte n'existe pas !!!");
                }
                else
                {
                    break;
                }
                cout << "Donnez votre numero de compte :";
                cin >> numero;
            }

            cout << "Donnez le montant a verser :";
            cin >> montant;
            while (true)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    erreur("Veuillez entrer un nombre valide pour le numero de compte!!!");
                }
                else if (montant < 0)
                {
                    cout << "excusez nous le montant a verser doit etre postif!!\n";
                }
                else
                {
                    break;
                }
                cout << "Donnez le montant a verser :";
                cin >> montant;
            }
            for (int j = 0; j < i; ++j)
            {
                if (tableau[j].numero == numero)
                {
                    tableau[j].solde += montant;
                    loadingPourcent();
                    cout << "Felicitation! votre montant a ete verser avec succes .\n";
                    cout << "Votre nouveau Solde est de :" << tableau[j].solde << "Fcfa" << endl;
                    break;
                }
            }

            break;
        }
        case 2:
        {
            double numero, montant;
            cout << "Donnez le numero de compte :";
            cin >> numero;
            while (true)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    erreur("Veuillez entrer un nombre valide pour le numero de compte!!!");
                }
                else if (numero < 0)
                {
                    cout << "le numero doit etre positif!!!";
                }
                else if (!verification(numero))
                {
                    erreur("le numero de compte n existe pas !!!");
                }
                else
                {
                    break;
                }
                cout << "Donnez votre numero de compte :";
                cin >> numero;
            }
            cout << "Donnez le montant a retirer : ";
            cin >> montant;

            while (true)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    erreur("Veuillez entrer un nombre valide pour le montant !!!");
                }
                else if (montant <= 0)
                {
                    cout << "Le montant doit être positif !!!" << endl;
                }
                else
                {
                    break;
                }
                cout << "Donnez le montant a retirer : ";
                cin >> montant;
            }

            for (int j = 0; j < i; ++j)
            {
                if (tableau[j].numero == numero)
                {
                    if (tableau[j].solde >= montant)
                    {
                        tableau[j].solde -= montant;
                        loadingRetrait();
                        cout << "Felicitation! votre montant a ete retirer avec succes .\n";
                        cout << "Votre nouveau Solde est de :" << tableau[j].solde << "Fcfa" << endl;
                    }
                    else
                    {
                        erreur("Votre fonds est inssufisant pour faire un retrait!!\n");
                    }
                    break;
                }
            }
            save();
            break;
        }
        break;
        case 3:
        {
            double numinitial, numdest, montant;
            cout << "Donnez le numero de compte initial :";
            cin >> numinitial;
            while (true)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    erreur("Veuillez entrer un nombre valide pour le numero de compte!!!");
                }
                else if (numinitial < 0)
                {
                    cout << "le numero doit etre positif!!!";
                }
                else if (!verification(numinitial))
                {
                    erreur("le numero de compte n existe pas !!!");
                }
                else
                {
                    break;
                }
                cout << "Donnez votre numero de compte initial :";
                cin >> numinitial;
            }
            cout << "le numero de compte du destinataire :";
            cin >> numdest;
            while (true)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    erreur("Veuillez entrer un nombre valide pour le numero de compte!!!");
                }
                else if (numdest < 0)
                {
                    cout << "le numero doit etre positif!!!";
                }
                else if (!verification(numdest))
                {
                    erreur("le numero de compte n existe pas !!!");
                }
                else
                {
                    break;
                }
                cout << "Donnez votre numero de compte du destinataire :";
                cin >> numdest;
            }
            cout << "Donnez le Montant a virer : ";
            cin >> montant;
            while (true)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    erreur("Veuillez entrer un nombre valide pour le montant !!!");
                }
                else if (montant <= 0)
                {
                    cout << "Le montant doit etre positif !!!" << endl;
                }
                else
                {
                    break;
                }
                cout << " Donnez le Montant a virer : ";
                cin >> montant;
            }
            int Kinitial = -1, kdestina = -1;

            for (int j = 0; j < i; ++j)
            {
                if (tableau[j].numero == numinitial)
                {
                    Kinitial = j;
                }
                if (tableau[j].numero == numdest)
                {
                    kdestina = j;
                }
            }
            if (Kinitial != -1 && kdestina != -1)
            {
                if (tableau[Kinitial].solde >= montant)
                {
                    tableau[Kinitial].solde -= montant;
                    tableau[kdestina].solde += montant;

                    loadingVirement(tableau[Kinitial].client, montant, tableau[kdestina].client);
                    cout << "Bravo! le montant a ete virer avcec succes! \n";
                }
                else
                {
                    erreur("Sorry!le fonds est inssuffisants pour le compte initial  ");
                }
            }

            break;
        }
        case 4:
        {
            double numero;
            cout << "Donnez le numero de compte a afficher ";
            cin >> numero;
            while (true)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    erreur("Veuillez entrer un nombre valide pour le numero de compte!!!");
                }
                else if (numero < 0)
                {
                    cout << "le numero doit etre positif!!!";
                }
                else if (!verification(numero))
                {
                    erreur("le numero de compte n existe pas !!!");
                }
                else
                {
                    break;
                }
                cout << "Donnez votre numero de compte :";
                cin >> numero;
            }

            for (int j = 0; j < i; ++j)
            {
                if (tableau[j].numero == numero)
                {
                    loadingPourcent();
                    cout << "Client (Nom et prenom) : " << tableau[j].client << endl;
                    cout << "Numero de compte : " << tableau[j].numero << endl;
                    cout << "Solde : " << tableau[j].solde << " Fcfa" << endl;
                    break;
                }
            }
            break;
        }

        break;
        case 5:
            save();
            loading();
            affichertouslescomptes();
            break;
        case 6:
            cout << "Retour au menu principal...\n";
            return;
        }
    } while (true);
}

void Ajouter()
{
    if (i >= 100)
    {
        cout << "+....................................................................+/n" << endl;
        cout << "| Cher client, nous sommes desoles, la banque est epuise.            |/n" << endl;
        cout << "| WASAM vous presente ses excuses                                    |/n" << endl;
        cout << "+....................................................................+/n/n" << endl;
        return;
    }

    information take;
    cout << "Veuillez saisir votre Nom et Prenom : ";
    cin.ignore();
    getline(cin, take.client);
    bool verif;
    do
    {
        take.numero = random();
        verif = verification(take.numero);
    } while (verif);

    cout << "Solde : ";
    cin >> take.solde;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("/tVeuilez entrer un nombre valide pour le solde!!!");
        }
        else if (take.solde < 0)
        {
            cout << "/t/tLe Solde doit etre positif!!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Solde : ";
        cin >> take.solde;
    }
    tableau[i++] = take;
    loadingPourcent();
    cout << "Masha Allah, Votre compte est enregistre avec succes!!!" << endl;
    cout << "......................................................" << endl;

    cout << "WASAM vous attribue le numero suivant : " << take.numero << endl;
    cout << "\nRavi de vous compter parmi nos abonnes !" << endl;
}

void Supprimer()
{
    double numero;
    cout << "Entrez le numero de compte a supprimer : ";
    cin >> numero;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuillez entrer un nombre valide pour le numero de compte!!!");
        }
        else if (numero < 0)
        {
            cout << "le numero de compte doit etre positif!" << endl;
        }
        else
        {
            break;
        }
        cout << "Entrez le numero de compte a supprimer :  ";
        cin >> numero;
    }
    int k = rechercheCompte(numero);

    if (k == -1)
    {
        loadingPourcent();
        erreur("Desolee nous avons pas trouver ce compte!!!\n");
        return;
    }
    while (k < i)
    {
        tableau[k - 1] = tableau[k];
        k++;
    }
    i--;
    loadingPourcent();
    cout << "Le compte a bien ete suprime...\n";
}

information take;
void modifier()
{
    double numero;
    cout << "Entrez le numero de compte a modifier : ";
    cin >> numero;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuillez entrer un nombre valide pour le numero de compte!!!");
        }
        else if (numero < 0)
        {
            cout << "le numero de compte doit etre positif!" << endl;
        }
        else
        {
            break;
        }
        cout << "Entrez le numero de compte a modifier : ";
        cin >> numero;
    }
    for (int j = 0; j < i; ++j)
    {
        if (tableau[j].numero == numero)
        {
            cout << "Nouveau Nom et prenom :";
            cin.ignore();
            getline(cin, tableau[j].client);
            cout << " Nouveau solde :";
            cin >> tableau[j].solde;

            if (tableau[j].solde < 0)
            {
                erreur("Votre solde est negatif!!!!\n");
                return;
            }
            loadingPourcent();
            cout << "Votre compte a ete modifier avec succes !\n";
            return;
        }
    }
    erreur("excusez nous mais nous n'avons pas trouver ce compte!!!\n");
}

void affichertouslescomptes()
{
    if (i == 0)
    {
        cout << "Aucun compte n'a ete enregistre!!!";
        return;
    }
    loadingPourcent();
    for (int j = 0; j < i; ++j)
    {
        cout << "Nom et prenom :" << tableau[j].client << endl;
        cout << "Numero de compte :" << tableau[j].numero << endl;
        cout << "Solde :" << tableau[j].solde << "Fcfa" << endl;
    }
}

bool verificationp(double numero)
{
    information *courant = tete;
    while (courant != nullptr)
    {
        if (courant->numero == numero)
        {
            return true;
        }
        courant = courant->suivant;
    }
    return false;
}

void Ajouterp()
{
    if (p >= 100)
    {
        cout << "+....................................................................+/n" << endl;
        cout << "| Cher client, nous sommes desoles, la banque est epuise.            |/n" << endl;
        cout << "| WASAM vous presente ses excuses                                    |/n" << endl;
        cout << "+....................................................................+/n/n" << endl;
        return;
    }
    information *tableaup = new information();
    cout << "Nom et prenom  :";
    cin.ignore();
    getline(cin, tableaup->client);
    bool verif;
    do
    {
        tableaup->numero = random();
        verif = verificationp(tableaup->numero);
    } while (verif);

    cout << "Solde :";
    cin >> tableaup->solde;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (tableaup->solde < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Solde : ";
        cin >> tableaup->solde;
    }
    tableaup->suivant = tete;
    tete = tableaup;
    p++;
    cout << "Masha Allah, votre compte est enregistre avec succes!" << endl;
    cout << "Wasam vous attribue le numero : " << tableaup->numero << endl;
    cout << "..................................................../n" << endl;
    cout << "Ravi de vous compter parmi nos abonnes !/n/n" << endl;
}

void supprimerp()
{
    double numero;
    cout << "Donnez le numero de compte a supprimer : ";
    cin >> numero;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (numero < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le numero de compte a supprimer : ";
        cin >> numero;
    }
    information *courant = tete;
    information *precedent = nullptr;
    while (courant != nullptr)
    {
        if (courant->numero == numero)
        {
            if (precedent == nullptr)
            {
                tete = courant->suivant;
            }
            else
            {
                precedent->suivant = courant->suivant;
            }
            delete courant;
            p--;
            cout << "Votre compte a ete supprime!\n";
            return;
        }
        precedent = courant;
        courant = courant->suivant;
    }
    erreur("desole,nous n'avons pas trouve ce compte!!!\n");
}

void modifierP()
{
    double numero;
    cout << "Donnez le numero de compte a modifier :";
    cin >> numero;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (numero < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le numero de compte a modifier : ";
        cin >> numero;
    }
    information *courant = tete;
    while (courant != nullptr)
    {
        if (courant->numero == numero)
        {
            cout << "Nouveau (Nom et prenom) : ";
            cin.ignore();
            getline(cin, courant->client);
            cout << "Nouveau solde : ";
            cin >> courant->solde;

            if (courant->solde < 0)
            {
                erreur("Votre solde est negatif!!!!\n");
                return;
            }
            cout << "Votre compte a ete modifie avec succes !\n";
            return;
        }
        courant = courant->suivant;
    }
    erreur("Excusez-nous, mais nous n'avons pas trouve ce compte!!!\n");
}

void affichercomptep()
{
    double numero;
    cout << "Donnez le numero de compte a afficher : ";
    cin >> numero;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (numero < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le numero de compte a afficher : ";
        cin >> numero;
    }

    information *courant = tete;

    while (courant != nullptr)
    {
        if (courant->numero == numero)
        {

            cout << "Client (Nom et prenom) : " << courant->client << endl;
            cout << "Numero de compte : " << courant->numero << endl;
            cout << "Solde : " << courant->solde << " Fcfa" << endl;
            return;
        }
        courant = courant->suivant;
    }

    cout << "Le compte n'existe pas !!!" << endl;
}

void affichertouslesComptesp()
{
    information *courant = tete;
    loadingPourcent();
    while (courant != nullptr)
    {
        cout << "Client (Nom et prenom) : " << courant->client << endl;
        cout << "Numero de compte : " << courant->numero << endl;
        cout << "Solde : " << courant->solde << " Fcfa" << endl;
        courant = courant->suivant;
    }
}

void menugestioncomptep()
{
    int choix;

    do
    {
        cout << "+.........................................................................+/n" << endl;
        cout << "| Excellent choix,Vous avez choisi la Methode B (Liste Chainee Dynamique).|/n" << endl;
        cout << "+.........................................................................+/n/n" << endl;
        cout << "      1 - Gestion des comptes \n";
        cout << "      2 - Transaction des comptes \n";
        cout << "      3 - Quitter le sous menu Principal \n";
        cout << "Choisir une option : ";
        cin >> choix;

        while (cin.fail() || choix < 1 || choix > 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Vous avez fait une entree incorrecte. Veuillez recommencer SVP.");
            cout << "Choisir une option : ";
            cin >> choix;
        }

        switch (choix)
        {
        case 1:
            gestioncomptep();
            break;
        case 2:
            gestiontransactionp();
            break;
        case 3:
            cout << "Vous avez quitte le sous menu Principal.\n";
            return;
        }
    } while (true);
}

void gestioncomptep()
{
    int choix;
    do
    {
        cout << "+....................................................................+/n" << endl;
        cout << "|             ... PROGRAMME UTILISE : TABLEAU STATIC ...             |/n" << endl;
        cout << "+....................................................................+/n/n" << endl;
        cout << "+....................................................................+/n" << endl;
        cout << "|                        Gestion des Comptes                         |/n" << endl;
        cout << "+................... .................................................+/n/n" << endl;

        cout << "+....................................................................+/n" << endl;
        cout << "|           |1. Ajouter un compte                                    |/n" << endl;
        cout << "|           |2. Supprimer un compte                                  |/n" << endl;
        cout << "|           |3. Modifier un compte                                   |/n" << endl;
        cout << "|           |4. Afficher tous les comptes                            |/n" << endl;
        cout << "|           |5. Retour au Menu Principal                             |/n" << endl;
        cout << "|               Choisissez une option :                              |/n" << endl;
        cout << "+....................................................................+/n/n" << endl;
        cin >> choix;

        while (cin.fail() || choix < 1 || choix > 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entree incorrecte. Veuillez recommencer.\n";
            cout << "Choisissez une option : ";
            cin >> choix;
        }

        switch (choix)
        {
        case 1:

            Ajouterp();

            break;
        case 2:

            supprimerp();

            break;
        case 3:

            modifierP();

            break;
        case 4:
            affichertouslesComptesp();

            break;
        case 5:
            cout << "Retour au menu principal...\n";
            return;
        }
    } while (true);
    savep();
}

void verserp()
{
    double numero, montant;
    cout << "Donnez le numero de compte : ";
    cin >> numero;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (numero < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else if (!verificationp(numero))
        {
            cout << "Le numero de compte  n'est pas trouve!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le numero de compte  : ";
        cin >> numero;
    }
    information *courant = tete;
    while (courant != nullptr)
    {
        if (courant->numero == numero)
        {
            break;
        }
        courant = courant->suivant;
    }

    if (courant == nullptr)
    {
        erreur("Le numero de compte n'a pas ete trouve apres la validation.");
        return;
    }
    cout << "Donnez le montant a verser : ";
    cin >> montant;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le versement!!!");
        }
        else if (montant < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le numero de compte  : ";
        cin >> montant;
    }
    loadingPourcent();
    courant->solde += montant;
    cout << "Felicitation ! Votre montant a ete verse avec succes." << endl;
    cout << "Votre nouveau solde est de : " << courant->solde << " Fcfa" << endl;
}

void retirerp()
{
    double numero, montant;
    cout << "Donnez le numero de compte : ";
    cin >> numero;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (numero < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else if (!verificationp(numero))
        {
            cout << "Le numero de compte n'est pas trouve!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le numero de compte : ";
        cin >> numero;
    }
    information *courant = tete;
    while (courant != nullptr)
    {
        if (courant->numero == numero)
        {
            break;
        }
        courant = courant->suivant;
    }
    if (courant == nullptr)
    {
        erreur("Le numero de compte n'a pas ete trouve apres la validation.");
        return;
    }
    cout << "Donnez le montant a retirer : ";
    cin >> montant;
    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (montant < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else if (courant->solde < montant)
        {
            erreur("Fonds insuffisants pour effectuer ce retrait. Veuillez entrer un montant inferieur ou egal au solde actuel.");
            cout << "Votre solde actuel est de : " << courant->solde << " Fcfa." << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le montant a retirer : ";
        cin >> montant;
    }
    loadingRetrait();
    courant->solde -= montant;
    cout << "Felicitation ! Votre montant a ete retire avec succes." << endl;
    cout << "Votre nouveau solde est de : " << courant->solde << " Fcfa" << endl;
}

void virerp()
{
    double num_initial, num_dest, montant;
    cout << "Donnez le numero de compte initial : ";
    cin >> num_initial;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (num_initial < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else if (!verificationp(num_initial))
        {
            cout << "Le numero de compte initial n'est pas trouve!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le numero de compte initial : ";
        cin >> num_initial;
    }
    information *courant = tete;
    while (courant != nullptr)
    {
        if (courant->numero == num_initial)
        {
            break;
        }
        courant = courant->suivant;
    }
    if (courant == nullptr)
    {
        erreur("Le numero de compte n'a pas ete trouve apres la validation.");
        return;
    }

    cout << "Donnez le numero de compte du destinataire : ";
    cin >> num_dest;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (num_initial < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else if (!verificationp(num_dest))
        {
            cout << "Le numero de compte destinataire n'est pas trouve!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le numero de compte destinataire : ";
        cin >> num_dest;
    }
    while (courant != nullptr)
    {
        if (courant->numero == num_dest)
        {
            break;
        }
        courant = courant->suivant;
    }
    if (courant == nullptr)
    {
        erreur("Le numero de compte n'a pas ete trouve apres la validation.");
        return;
    }

    cout << "Donnez le montant a virer : ";
    cin >> montant;
    while (true)
    {

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            erreur("Veuilez entrer un nombre valide pour le solde!!!");
        }
        else if (montant < 0)
        {
            cout << "le solde doit etre positif!!!" << endl;
        }
        else
        {
            break;
        }
        cout << "Donnez le montant a virer : ";
        cin >> montant;
    }
    information *courant_initial = tete;
    information *courant_dest = tete;

    while (courant_initial != nullptr)
    {
        if (courant_initial->numero == num_initial)
        {
            break;
        }
        courant_initial = courant_initial->suivant;
    }

    while (courant_dest != nullptr)
    {
        if (courant_dest->numero == num_dest)
        {
            break;
        }
        courant_dest = courant_dest->suivant;
    }

    if (courant_initial->solde >= montant)
    {
        loadingVirement(courant_initial->client, montant, courant_dest->client);
        courant_initial->solde -= montant;
        courant_dest->solde += montant;
        cout << "\nBravo ! Le montant a ete vire avec succes !" << endl;
    }
    else
    {
        cout << "Fonds insuffisants pour le compte initial !" << endl;
    }
}

void gestiontransactionp()
{
    int choix;
    do
    {
        cout << "+....................................................................+/n" << endl;
        cout << "|             ... PROGRAMME UTILISE : TABLEAU Dynamique ...             |/n" << endl;
        cout << "+....................................................................+/n/n" << endl;
        cout << "+....................................................................+/n" << endl;
        cout << "|                        Gestion des Comptes                         |/n" << endl;
        cout << "+................... .................................................+/n/n" << endl;

        cout << "+....................................................................+/n" << endl;
        cout << "|         1 - Verser une somme dans un compte                        |/n" << endl;
        cout << "|         2 - Retirer une somme d'un compte                          |/n" << endl;
        cout << "|         3 - Virer une somme d'un compte vers un autre              |/n " << endl;
        cout << "  |         4 - Afficher un compte                                     |/n" << endl;
        cout << "|         5 - Afficher tous les comptes                              |/n" << endl;
        cout << "|         6 - Quitter le sous menu (retour au sous menu principal)   |/n" << endl;
        cout << "|               Choisissez une option :                              |/n" << endl;
        cout << "+....................................................................+/n/n" << endl;
        cin >> choix;

        while (cin.fail() || choix < 1 || choix > 6)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entree incorrecte. Veuillez recommencer.\n";
            cout << "Choisissez une option : ";
            cin >> choix;
        }

        switch (choix)
        {
        case 1:

            verserp();

            break;
        case 2:

            retirerp();

            break;
        case 3:

            virerp();

            break;
        case 4:

            affichercomptep();

            break;
        case 5:
            savep();
            affichertouslesComptesp();

            break;
        case 6:
            cout << "Retour au menu principal...\n";
            return;
        }
    } while (true);
}

void save()

{
    ofstream naruto("compte.txt");
    if (naruto)
    {
        for (int j = 0; j < i; ++j)
        {
            naruto << tableau[j].numero << " ";
            naruto << tableau[j].solde << " ";
            naruto << tableau[j].client << "\n";
        }
        naruto.close();
    }

    naruto.close();
}
void savep()
{
    ofstream fichier("comptes.txt");
    if (!fichier)
    {
        erreur("Erreur lors de l'ouverture du fichier de sauvegarde.");
        return;
    }

    information *courant = tete;
    while (courant != nullptr)
    {
        fichier << courant->client << " ";
        fichier << courant->numero << " ";
        fichier << courant->solde << "\n";
        courant = courant->suivant;
    }
    fichier.close();
    cout << "Les comptes ont ete sauvegardes avec succes dans 'comptes.txt'." << endl;
}
void nimpop()
{
    ifstream fichier("comptes.txt");
    if (!fichier)
    {
        erreur("Erreur lors de l'ouverture du fichier de chargement.");
        return;
    }
    string nom, prenom;
    double numero, solde;
    while (fichier >> nom >> prenom >> numero >> solde)
    {
        information *courant = new information;
        courant->client = nom + " " + prenom;
        courant->numero = numero;
        courant->solde = solde;
        courant->suivant = tete;
        tete = courant;
    }
    fichier.close();
    cout << "Les comptes ont ete charges avec succes depuis 'comptes.txt'." << endl;
}
void nimpo()
{

    string nom;
    string prenom;
    double numero;
    double solde;
    ifstream naruto("compte.txt");
    i = 0;
    while (naruto >> numero >> solde >> nom >> prenom)
    {
        take.numero = numero;
        take.solde = solde;
        take.client = nom + " " + prenom;
        tableau[i++] = take;
    }
    naruto.close();
}

string login()
{
    string motDePasse;
    char ch;

    cout << "\tveuillez inserer votre mot de passe : ";
    while ((ch = _getch()) != '\r')
    { // '\r' pour entrer
        if (ch == '\b')
        { // gerer la touche de retour arrière
            if (!motDePasse.empty())
            {
                motDePasse.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            motDePasse.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return motDePasse;
}