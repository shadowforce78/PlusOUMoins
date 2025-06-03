#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Initialiser le générateur de nombres aléatoires
    std::srand(std::time(nullptr));

    std::string welcometext = "Bienvenue dans le jeu du Nombre Mystère !\n"
                              "Devinez un nombre entre 1 et 100 :\n";

    int mysteryNumber = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::string tooLowText = "→ Trop petit !\n";
    std::string tooHighText = "→ Trop grand !\n";
    std::string guessText = "Votre proposition : ";
    std::string errorText = "Erreur !\n";

    std::cout << welcometext;
    
    do {
        attempts++;
        std::cout << guessText;
        std::cin >> guess;

        if (guess > 100 || guess < 1)
        {
            std::cout << errorText;
            return 1;
        }

        if (guess > mysteryNumber)
        {
            std::cout << tooHighText;
        }
        else if (guess < mysteryNumber)
        {
            std::cout << tooLowText;
        }

    } while (guess != mysteryNumber);

    // Afficher le message de victoire avec le nombre d'essais
    std::cout << "Bravo ! Vous avez trouvé en " << attempts << " essais.\n";

    return 0;
}
