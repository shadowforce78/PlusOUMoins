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

    fprintf(stdout, "%s", welcometext.c_str());

    do
    {
        attempts++;
        fprintf(stdout, "%s", guessText.c_str());
        fscanf(stdin, "%d", &guess);

        if (guess > 100 || guess < 1)
        {
            fprintf(stderr, "%s", errorText.c_str());
            return 1;
        }

        if (guess > mysteryNumber)
        {
            fprintf(stderr, "%s", tooHighText.c_str());
        }
        else if (guess < mysteryNumber)
        {
            fprintf(stderr, "%s", tooLowText.c_str());
        }

    } while (guess != mysteryNumber);

    // Afficher le message de victoire avec le nombre d'essais
    fprintf(stdout, "Bravo ! Vous avez trouvé en %d essais.\n", attempts);

    return 0;
}
