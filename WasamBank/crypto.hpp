#ifndef __CRYPTO__
#define __CRYPTO__
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void encrypt(const string &inputFile, const string &outputFile, char key)
{
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile || !outFile)
    {
        cerr << "Erreur lors de l'ouverture des fichiers." << endl;
        return;
    }

    char ch;
    while (inFile.get(ch))
    {
        ch ^= key;
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();
    cout << "\n";
}

void decrypt(const string &inputFile, const string &outputFile, char key)
{
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile || !outFile)
    {
        cerr << "Erreur lors de l'ouverture des fichiers." << endl;
        return;
    }

    char ch;
    while (inFile.get(ch))
    {
        ch ^= key;
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();
}

void prepareEncrypt()
{
    string cryptoDir = "fichier_cripte";
    if (!fs::exists(cryptoDir))
    {
        fs::create_directory(cryptoDir);
    }

    string inputFile = "compte.txt";
    string encryptedFile = cryptoDir + "/compteCryptee.txt";
    char key = 'K';

    encrypt(inputFile, encryptedFile, key);
}

void prepareDecrypt()
{
    string cryptoDir = "crypto";
    string encryptedFile = cryptoDir + "/compteCryptee.txt";
    string decryptedFile = cryptoDir + "/compteDecryptee.txt";
    char key = 'K';

    decrypt(encryptedFile, decryptedFile, key);
}
// appele de fonction soit 1 ou 2 dans le main
// 1- prepareEncrypt();
// 2- prepareDecrypt();

#endif
