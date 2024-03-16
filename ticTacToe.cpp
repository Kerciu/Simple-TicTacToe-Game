#include <iostream>
#include <ctime>

void drawBoard(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces, char computer);
bool checkWinner(char* spaces, char player, char computer);
bool checkTie(char* spaces);

int main()
{
    char spaces[9];
    std::fill(spaces, spaces + 9, ' ');

    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running) {
        playerMove(spaces, player);
        drawBoard(spaces);

        system("cls");

        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }

        system("cls");

        computerMove(spaces, computer);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }
    }

    drawBoard(spaces);

    return 0;
}

void drawBoard(char* spaces)
{   
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}
void playerMove(char* spaces, char player)
{
    int number;

    do {
        std::cout << "enter a spot to place the marker (1-9): ";
        std::cin >> number;
        number--;
        if (number >= 0 && number <= 8 && spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
        else {
            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
        }
    } while (true);
}
void computerMove(char* spaces, char computer) {
    int number;
    srand(time(NULL));
    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char* spaces, char player, char computer)
{
    int winCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6} };

    for (int i = 0; i < 8; i++) {
        int a = winCombinations[i][0];
        int b = winCombinations[i][1];
        int c = winCombinations[i][2];

        if (spaces[a] != ' ' && (spaces[a] == spaces[b] && spaces[b] == spaces[c])) {
            std::cout << (spaces[a] == player ? "You Win!" : "You lose!");
            return true;
        }
    }
    return false;
}
bool checkTie(char* spaces) {
    
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "It's a TIE!";
    return true;
}
