#include <iostream>
#include <cstdlib>
#include <ctime>
void fight(int playerHealth, int damageStatMin, int damageStatMax, int enemyHealth, int enemyDamageMin, int enemyDamageMax) {
    bool done{ false };
    int choice{};
    bool blocking{ false };
    while (!done) {
        std::cout << "Current health: " << playerHealth << std::endl;
        std::cout << "Enemy health: " << enemyHealth << std::endl;
        std::cout << "1. Attack\n2. Health Boost\n3. Attack Boost\n4. Run(25% chance of escape)\n";
        std::cin >> choice;
        switch (choice) {
        case 1: { //attacking
            int damage{ rand() % damageStatMax + damageStatMin };
            enemyHealth -= damage;
            std::cout << "Dealt " << damage << " damage, enemy's health is now at " << enemyHealth << std::endl;
            break;
        }
        case 2: { //Health boost
            std::cout << "You gain 5 health." << std::endl;
            playerHealth += 5;
            break;
        }
        case 3: { // attack boost
            std::cout << "You're attack increases" << std::endl;
            damageStatMax += 2;
            damageStatMin += 2;
            break;
        }
        case 4: { //attempt to escape with 25% chance of escaping
            if (rand() % 100 + 1 < 25) {
                std::cout << "You got away." << std::endl;
                return;
            }
            else {
                std::cout << "You tried to run away but failed." << std::endl;
                break;
            }
        }
        default: {
            std::cout << "invalid choice" << std::endl;
        }
        }
        int enemyMove{ rand() % 3 + 1 };
        switch (enemyMove) {
        case 1: {
            int enemyDamage{ rand() % enemyDamageMax + enemyDamageMin };
            playerHealth -= enemyDamage;
            std::cout << "The enemy attacks dealing " << enemyDamage << std::endl;
            break;
        }
        case 2: {
            std::cout << "The enemy's attack increases." << std::endl;
            enemyDamageMin += 2;
            enemyDamageMax += 2;
            break;
        }
        case 3: {
            std::cout << "The enemy gains 5 health" << std::endl;
            enemyHealth += 5;
        }
        }
        if (enemyHealth <= 0) {
            std::cout << "You win!" << std::endl;
            done = true;
        }
        if (playerHealth <= 0) {
            std::cout << "You lost!" << std::endl;
            done = true;
        }
    }
}

int main()
{
    std::cout << "Welcome to text based RPG!\n";
    srand(time(nullptr));
    fight(100, 2, 10, 50, 2, 12);
    system("pause");
}