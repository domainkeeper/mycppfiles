#include<bits/stdc++.h>
using namespace std;

void explore(int &health, string &name);

void wingame(int &health, string &name)
{
    cout << "\nCongratulations! You have won the game!" << endl;
    cout << "Your final health was: " << health << " and Game ID was: " << name << endl;
    exit(0);
}

void endgame(int &health, string &name)
{
    cout << "Game Over! Your final health was: " << health << " and Game ID was: " << name << endl;
    cout << "Thank you for playing!\n" << endl;
    exit(0);
}


void monsterattack(int &health, string &name, int &monsterhealth)
{
    cout << "\nDo you want to attack ? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        monsterhealth -= 40;
        cout << "\nYou fought bravely! \nMonster's health is now: " << monsterhealth << endl;
        if (monsterhealth <= 0)
        {
            cout << "You defeated the monster!\n" << endl;
            wingame(health,name);
        }
        else if (monsterhealth >= 0)
        {
            cout << "\nMonster attacks you!" << endl;
            health -= 30;
            cout << "Your health is now: " << health << endl;
            if (health <= 0)
            {
                cout << "\nYou have been defeated by the monster. Game Over!\n" << endl;
                endgame(health,name);
            }
            else
            {
                monsterattack(health,name,monsterhealth);
            }
            
        }

    }
    else if (choice == 'N' || choice == 'n')
    {
        cout << "You chose to flee from the monster." << endl;
        explore(health,name);
    }
     

}

void explore(int &health, string &name)
{
    cout << "Exploring the game world...\n" << endl;
    cout << "You found a monster!" << endl;
    cout << "Do you want to engage it? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        int monsterhealth = 120;
        monsterattack(health,name,monsterhealth);
    }
    else if (choice == 'N' || choice == 'n')
    {
        cout << "\nYou chose to avoid the monster and continue your journey." << endl;
        explore(health,name);
    }

}


void initializeGame()
{
    string name;
    cout << "Who even are you ? \nWhy are you here ? \nTell me your identity !" << endl ;
    cout << "Enter your ID : ";
    cin >> name;
    cout << "\nGame initialized with ID: " << name << endl;
    cout << "You start with 100 health points.\n" << endl;
    int health = 100;
    explore(health,name);
}

int  main()
{
    cout << "Welcome to the Game!" << endl;
    cout << "Initializing game components..." << endl;

    // Simulate some game initialization logic
    initializeGame();

    
    return 0;
}