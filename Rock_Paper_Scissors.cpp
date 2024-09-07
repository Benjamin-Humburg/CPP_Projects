#include <iostream>
#include <random>
#include <string>
#include <vector>

std::vector<std::string> CHOICES = {"Rock", "Paper", "Scissors"};
std::vector<std::string> RESULTS = {"It's a draw.\n", "You win!\n", "Sorry, you lost.\n"};
//std::vector<std::string> PROMPTS = {"", "Paper covers Rock. ",
//                                    "Rock smashes Scissors. ", "Scissors cutting Paper. "};

int get_result(int user, int comp) {
    // 0 = draw, 1 = win, 2 = loss
    return (user - comp + 3) % 3;
}

/*
int get_prompt(int user, int comp) {
    // 0 - draw, 1 - paper, 2 - rock, 3 - scissors
    if (user == comp) {
        return 0;
    }

    return user + comp;
}
*/

int main() {
    std::cout << "Welcome to the Rock, Paper, Scissors game!" << std::endl << std::endl;
    std::cout << "Please enter your name, number of repetitions," << std::endl;
    std::cout << "and your chosen steps" << std::endl;
    std::cout << "1 - Rock," << std::endl;
    std::cout << "2 - Paper," << std::endl;
    std::cout << "3 - Scissors" << std::endl << std::endl;

    std::vector<int> user_choices;
    std::string user_name;
    std::cin >> user_name; // first input = name

    int repititions = 0;
    std::cin >> repititions; // second input = number of games

    int iterations = repititions;
    // The silly repeated output
    std::cout << "> " << user_name << " " << iterations << " ";

    // For better memory usage, declare variables outside of loop
    std::string user_choice = "";
    for (int i = 0; i < iterations; i++) {
        std::cin >> user_choice;
        std::cout << user_choice;
        if (i < iterations - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
        for (int j = 0; j < user_choice.length(); j++) {
            user_choice[j] = std::tolower(user_choice[j]);
        }
        if (user_choice == "1" || user_choice == "rock") {
            user_choices.push_back(0);
        } else if (user_choice == "2" || user_choice == "paper") {
            user_choices.push_back(1);
        } else if (user_choice == "3" || user_choice == "scissors") {
            user_choices.push_back(2);
        } else {
            std::cout << "Invalid move. Please enter Rock, Paper, or Scissors.";
            return 0;
        }
    }

    // Get Computer Selections
    std::random_device seed;
    std::mt19937 gen(seed());
    //std::vector<int> computer_choices;
    //for (int i = 0; i < iterations; i++) {
    //    computer_choices.push_back(gen() % 3);
    //}

    std::cout << "Game Start!" << std::endl;
    int user_wins = 0, computer_wins = 0;
    std::string winner;
    for (int i = 0; i < iterations; i++) {
        // Get computer choice
        int computer_choice = gen() % 3;
        //Round 1: Computer chose Paper, Jack chose Scissors. Winner: Jack.
        switch (get_result(user_choices[i], computer_choice)) {
            case 0:
                i--;
                winner = "It's a draw";
                break;
            case 1:
                user_wins++;
                winner = "Winner: " + user_name;
                break;
            case 2:
                computer_wins++;
                winner = "Winner: Computer";
                break;
            default:
                break;
        }
        std::cout << "Round " << i + 1 << ": Computer chose " << CHOICES[computer_choice] << ", "
                  << user_name << " chose " << CHOICES[user_choices[i]] << ". " << winner << "."
                  << std::endl;

    }

    std::cout << std::endl;
    std::cout << "Game Over!" << std::endl;
    std::cout << "Total Score - " << user_name << ": " << user_wins
              << ", Computer: " << computer_wins << std::endl;
    std::cout << "Would you like to play again? (yes/no)";

    return 0;
}
