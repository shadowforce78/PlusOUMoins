#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    using namespace std;
    // Initialiser le générateur de nombres aléatoires
    srand(time(nullptr));

    string welcometext = "Bienvenue dans le jeu du Nombre Mystère !\n"
                         "Devinez un nombre entre 1 et 100 :\n";

    int mysteryNumber = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    string tooLowText = "→ Trop petit !\n";
    string tooHighText = "→ Trop grand !\n";
    string guessText = "Votre proposition : ";
    string errorText = "Erreur !\n";

    cout << welcometext;

    do
    {
        attempts++;
        cout << guessText;
        cin >> guess;

        if (guess > 100 || guess < 1)
        {
            cout << errorText;
            return 1;
        }

        if (guess > mysteryNumber)
        {
            cout << tooHighText;
        }
        else if (guess < mysteryNumber)
        {
            cout << tooLowText;
        }

    } while (guess != mysteryNumber);

    // Afficher le message de victoire avec le nombre d'essais
    cout << "Bravo ! Vous avez trouvé en " << attempts << " essais.\n";

    return 0;
}
