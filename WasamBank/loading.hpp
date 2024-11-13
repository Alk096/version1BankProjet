#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

void loading()
{

    const char spinner[] = {'|', '/', '-', '\\'};
    int spinnerIndex{};
    const int duree{1};

    cout << "Processus en cours de chargement, veuillez patienter un moment...\n";

    for (int i{}; i < duree * 4; i++)
    {
        cout << "\r" << spinner[spinnerIndex] << flush;
        spinnerIndex = (spinnerIndex + 1) % 4;
        this_thread::sleep_for(chrono::milliseconds(250));
    }
    system("CLS");
    cout << "\rChargement termine. Merci d'avoir patienter            \n";
}

void loadingRetrait()
{

    const int duree = 8;
    const int longueurMax = 15;
    int position{};

    cout << "retrait en cours, veuillez patienter un moment...\n";

    for (int i = 0; i < duree * 4; i++)
    {
        cout << "\r";
        cout << string(position, '<') << "-";
        cout << flush;

        position = (position + 1) % (longueurMax - 1);

        this_thread::sleep_for(chrono::milliseconds(250));
    }
    system("CLS");
    cout << "\rRetrait effectue avec succes!            \n";
}

void loadingPourcent()
{
    int duration = 3000;
    cout << "Operation en cours veuillez patienter svp...\n";
    const int barWidth = 30;
    for (int i = 0; i <= barWidth; ++i)
    {
        cout << "\r[";
        for (int j = 0; j < i; ++j)
            cout << "=";
        for (int j = i; j < barWidth; ++j)
            cout << " ";

        cout << "] " << (i * 100) / barWidth << "%";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(duration / barWidth));
    }
    // system("CLS");
    cout << "\nOperation termine ! merci d'avoir utiliser notre service \n\n";
}

void loadingVirement(const string &nomEnvoyeur, long montant, const string &nomReceiveur)
{
    cout << "\n\tVirement en cours, veuillez patienter un moment...\n\n";
    int duration = 4000;
    const string arrow = "->"; // arrow fleche
    const int spaces = 20;
    int i, j;

    string montantStr = to_string(montant) + " FCFA ";

    for (i = 0; i < spaces; i++)
    {
        cout << "\r" << nomEnvoyeur << " " << montantStr << " ";

        for (j = 0; j < i; j++)
            cout << " ";
        cout << arrow << montantStr;

        for (int j = i + 1; j < spaces; j++)
            cout << " ";
        cout << nomReceiveur;

        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(duration / spaces));
    }
    system("CLS");
    cout << arrow;
    cout << montantStr << " ";
    cout << nomReceiveur;
}

void loadingPourcentFin()
{
    int duration = 1000;
    cout << "Operation en cours veuillez patienter svp...\n";
    const int barWidth = 30;
    for (int i = 0; i <= barWidth; ++i)
    {
        cout << "\r[";
        for (int j = 0; j < i; ++j)
            cout << "=";
        for (int j = i; j < barWidth; ++j)
            cout << " ";

        cout << "] " << (i * 100) / barWidth << "%";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(duration * 4 / barWidth));
    }
    system("CLS");
    cout << "\nOperation termine ! merci d'avoir utiliser notre service \n";
}
