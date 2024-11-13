#ifndef COMPTE_HPP
#define COMPTE_HPP
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int tab = 100;
struct information
{
    string client;
    double numero;
    double solde;
    information *suivant;
};
extern information tableau[tab];
extern int i;

void Menuprincipal();
void menugestioncompte();
void gestioncompte();
void gestiontransaction();
void erreur(const string &sms);
void Ajouter();
bool verification(double numero);
void Supprimer();
void modifier();
void affichertouslescomptes();
extern information *tete;
extern int p;
bool verificationp(double numero);
void Ajouterp();
void supprimerp();
void modifierP();
void affichertouslesComptesp();
void gestioncomptep();
void gestiontransactionp();
void menugestioncomptep();
void verserp();
void virerp();
void retirerp();
void affichercomptep();
void save();
void nimpo();
void savep();
void nimpop();
string login();
#endif
