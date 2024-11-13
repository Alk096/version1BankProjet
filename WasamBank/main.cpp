#include "compte.hpp"
#include "crypto.hpp"
#include <limits>
#include <string>
#include <fstream>
#include <iostream>
int main()
{
    int choix;
    string motDepasse = "Wasam227";
    string logingwasambank;
    do
    {
        logingwasambank = login();
        if (motDepasse == logingwasambank)
        {
            system("cls");
            Menuprincipal();
            cin >> choix;

            while (cin.fail() || choix < 1 || choix > 3)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                erreur("Vous avez fait une entree incorrecte. Veillez a entrer un choix valide.");
                Menuprincipal();
                cin >> choix;
            }

            switch (choix)
            {

            case 1:
                prepareDecrypt();
                nimpo();
                menugestioncompte();
                save();
                prepareEncrypt();
                break;
            case 2:
                nimpop();
                menugestioncomptep();
                break;
            case 3:
                cout << "-------| Fin du Programme. WASAM VOUS REMERCIE POUR VOTRE CONFIANCE |------- \n";
                return 0;
            }
        }
    } while (true);
}
