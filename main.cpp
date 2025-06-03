#include <iostream>

int main()
{

    std::string welcometext = "Bienvenue dans le jeu du Nombre Mystère !\n"
                              "Devinez un nombre entre 1 et 100 :\n";

    int mysteryNumber = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::string ggtext = "Bravo ! Vous avez trouvé en %d essais.\n", attemps;
    std::string tooLowText = "→ Trop petit !\n";
    std::string tooHighText = "→ Trop grand !\n";
    std::string guessText = "Votre proposition : ";
    std::string errorText = "Erreur !\n";

    std::cout << welcometext;
    std::cin >> guess;

    std::cout << guessText;
    std::cout << guess;

    while (guess != mysteryNumber)
    {

        attempts++;
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

        std::cout << guessText;
        std::cin >> guess;
    }

    std::cout << ggtext;

    return 0;
}
