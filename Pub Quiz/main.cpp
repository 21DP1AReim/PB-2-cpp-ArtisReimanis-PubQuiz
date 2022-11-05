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
    std::string possibleAnswers[4] = {"A","B" ,"C","D"}; // array for possible answer inputs by player
    std::string questions[] = 	{"1. What year was C++ created?: ", // array for questions
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

    std::string options[][16] = 	{{"A. 1969", "B. 1975", "C. 1985", "D. 1989"}, // array for answers to questions
                                   {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerburg"},
                                   {"A. C", "B. C+", "C. C--", "D. B++"},
                                   {"A. yes", "B. 4", "C. 8", "D. What's a quart?"},
                                   {"A. a walk","B. a fly","C. John","D. a flap"},
                                   {"A. Neckless","B. Ring","C. Foot","D. Earring"},
                                   {"A. C","B. HTML","C. Python","D. Basic"},
                                   {"A. Stride","B. Thunder","C. Shine","D. Love"},
                                   {"A. Lemon","B. Citrus","C. Fruits","D. Fish"},
                                   {"A. Hey Jude","B. Let it be","C. The Righteous","D. The Search"},
                                   {"A. Blue","B. White","C. Red","D. Yellow"},
                                   {"A. 165","B. 78","C. 112","D. 95"},
                                   {"A. Great Wall of China","B. Burj Khalifa","C. Egyptian pyramids","D. Stonehenge"},
                                   {"A. Alabama","B. Washington","C. West Virginia","D. Virginia "},
                                   {"A. Germany","B. Sudan","C. Australia","D. Israel"},
                                   {"A. Bill Gates","B. Charles Babbage","C. Alan Turing","D. Paul Allen"}};

    std::string answerKey[] = {"C", "B", "A", "B","A","D","D","B","C", "B","C",
                        "A","A","C", "D","C"}; // array for answers to corresponding questions

    int const size = sizeof(questions)/sizeof(questions[0]); // variable to store size of array
    std::string guess; // variable to store user input
    int score = 0; // variable to store the amount of questions the player got right

    for(int i = 0; i < size; i++){ // loop to print out questions, possible answers and take in player answer
        std::cout << "*********************************************\n";
        std::cout << questions[i] << '\n'; // outputs the questions, for example if loop on 2nd iteration then would print out question about the invention of c++
        std::cout << "*********************************************\n";

        for(int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++){ // loop to output possible answers to questions
            std::cout << options[i][j] << '\n';
        }
        do { // do while loop to make sure the answer player inputted is a possible answer and not a misinput/incorrect input
            std::cout << "Enter your answer:";
            std::cin >> guess; // players inputs their answer
        }while(!searchvalue(possibleAnswers,4,guess)); // checks if the answer is a possible answer if not then asks the player to input new answer
        if(guess == answerKey[i]){ // checks if player answer is correct, if it is then their score increases
            std::cout << "CORRECT\n";
            score++;
        }
        else{ // if user answer is incorrect, then game says so
            std::cout << "WRONG!\n";
            //std::cout << "Answer: " << answerKey[i] << '\n'; // If want game to output right answer, then can do so by removing the 2 first characters of this line
        }
    }
    int scorePercent = (score/(double)size)*100; // variable to determine the score percentage the player got out of the maximum 100%
    std::cout << "*******************************\n";
    std::cout << "*           RESULTS           *\n";
    std::cout << "*******************************\n";
    std::cout << "CORRECT GUESSES: " << score << '\n';
    std::cout << "# of QUESTIONS: " << size << '\n';
    std::cout << "SCORE: " << scorePercent << "%";

    std::ofstream Scores("ScoresFromPubQuizGame.txt", std::ios::app); // opens or creates file in append mode, so any text writen before is uppended by this new text
    Scores << "        \t" << playerName<< "        \t\n";
    Scores << "Score: " << scorePercent << "%\n";
    Scores.close();
    return 0;
}
