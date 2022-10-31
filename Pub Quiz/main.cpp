#include <iostream>
#include <fstream>

bool searchvalue(std::string arr[],int size, std::string value){
    for(int i=0;i<size;i++)
    {
        if(arr[i] == value)
        {
            return true;
        }
    }
    return false;
}

int main() {
    std::string playerName;
    std::cout << "Enter your name:";
    std::cin >> playerName;
    std::string possibleAnswers[4] = {"A", "B", "C", "D"};
    std::string questions[] = {"1. What year was C++ created?: ",
                               "2. Who invented C++?: ",
                               "3. What is the predecessor of C++?: ",
                               "4. How many cups in a quart?",
                               "5. What do you call a wingless fly?",
                               "6. Complete the title of this famous painting: Girl with a Pearl ...?",
                               "7. Bill Gates was responsible for creating..",
                               "8. When you take credit for someone else's work you are said to steal their what?",
                               "9. What is the main source of vitamin C?",
                               "10. Guess the song:\n"
                               "'When I find myself in times of trouble Mother Mary comes to me.'",
                               "What colour is found on 75% of the world's flags?",
                               "How many million cups of tea are drunk in the UK on average every day?",
                               "What is the world's largest man-made structure? ",
                               "John Denver's 'Take Me Home Country Roads' is about which US state?",
                               "In 1952 Albert Einstein was offered the Presidency of which country?",
                               "Which famous computer scientist got chemically castrated for being gay?"};

    std::string options[][16] = {{"A. 1969",                "B. 1975",              "C. 1985",              "D. 1989"},
                                 {"A. Guido van Rossum",    "B. Bjarne Stroustrup", "C. John Carmack",      "D. Mark Zuckerburg"},
                                 {"A. C",                   "B. C+",                "C. C--",               "D. B++"},
                                 {"A. yes",                 "B. 4",                 "C. 8",                 "D. What's a quart?"},
                                 {"A. a walk",              "B. a fly",             "C. John",              "D. a flap"},
                                 {"A. Neckless",            "B. Ring",              "C. Foot",              "D. Earring"},
                                 {"A. C",                   "B. HTML",              "C. Python",            "D. Basic"},
                                 {"A. Stride",              "B. Thunder",           "C. Shine",             "D. Love"},
                                 {"A. Lemon",               "B. Citrus",            "C. Fruits",            "D. Fish"},
                                 {"A. Hey Jude",            "B. Let it be",         "C. The Righteous",     "D. The Search"},
                                 {"A. Blue",                "B. White",             "C. Red",               "D. Yellow"},
                                 {"A. 165",                 "B. 78",                "C. 112",               "D. 95"},
                                 {"A. Great Wall of China", "B. Burj Khalifa",      "C. Egyptian pyramids", "D. Stonehenge"},
                                 {"A. Alabama",             "B. Washington",        "C. West Virginia",     "D. Virginia "},
                                 {"A. Germany",             "B. Sudan",             "C. Australia",         "D. Israel"},
                                 {"A. Bill Gates",          "B. Charles Babbage",   "C. Alan Turing",       "D. Paul Allen"}};

    std::string answerKey[] = {"C", "B", "A", "B", "A", "D", "D", "B", "C", "B", "C",
                               "A", "A", "C", "D", "C"};

    int size = sizeof(questions) / sizeof(questions[0]);
    std::string guess;
    int score = 0;

    for (int i = 0; i < size; i++) {
        std::cout << "*********************************************\n";
        std::cout << questions[i] << '\n';
        std::cout << "*********************************************\n";

        for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++) {
            std::cout << options[i][j] << '\n';
        }
        do {
            std::cout << "Enter your answer:";
            std::cin >> guess;
            //guess = toupper(guess);
        } while (!searchvalue(possibleAnswers, 4, guess));
        if (guess == answerKey[i]) {
            std::cout << "CORRECT\n";
            score++;
        } else {
            std::cout << "WRONG!\n";
            //std::cout << "Answer: " << answerKey[i] << '\n';
        }
    }
    std::cout << "*******************************\n";
    std::cout << "*           RESULTS           *\n";
    std::cout << "*******************************\n";
    std::cout << "CORRECT GUESSES: " << score << '\n';
    std::cout << "# of QUESTIONS: " << size << '\n';
    std::cout << "SCORE: " << (score / (double) size) * 100 << "%";

    std::ofstream Scores("Scores.txt", std::ios::app);
    Scores << "        " << playerName << "        \n";
    Scores << "Score: " << (score / (double) size) * 100 << "%\n";
    Scores.close();
    return 0;
};