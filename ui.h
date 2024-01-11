#ifndef UI_H
#define UI_H

#include "bureau.h"
#include "matchmaking.h"
#include <iostream>
#include <stdexcept>

class UI {
public:
    void run() {
        std::string filename;
        filename = "baza_1.txt";

        bureau.readClientsFromFile(filename);

        while (true) {
            displayActions(); 



        try {
            // User input
            std::cout << "\nEnter your command: ";
            std::string command;
            std::cin >> command;

            if (command != "m" && command != "q") {
                throw std::invalid_argument("Invalid command. Expected 'm' or 'q'.");
            }

            action(command);
        } catch (const std::invalid_argument& e) {
            std::cerr << "\nError: " << e.what() << std::endl;
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }



        }
    }

private:
    Bureau bureau;


    void displayActions() const {
        std::cout
                  << "\nWelcome to  Tinder 2.0:\n\n"
                  << "Actions:\n\n"
                  << "m - Find matches for a person\n"
                  << "q - Quit \n";
    }

    // Kolejne funkcje reagujące na input 

    void action(const std::string& command) {

        if (command=="m")
        {
            std::string searchName;
            std::cout << "Enter the name to search for: ";
            std::cin >> searchName;
            
            const Person* foundPerson = bureau.findPerson(searchName);

            if (foundPerson) {
                std::cout << "\nPerson found:" << std::endl;
                printPerson(foundPerson);

                // szukanie dopasaowan dla wybranej osoby 
                std::vector<Person> matches = Matchmaking::findMatches(*foundPerson, bureau.people);

                if (!matches.empty()) {
                    std::cout << "\nBest Matches:" << std::endl;
                    printMatches(matches);
                } else {
                    std::cout << "No matches found." << std::endl;
                }
            } else {
                std::cout << "Person not found." << std::endl;
            }

            
        }
        else if (command=="q")
        {
            exit(0);
        }

    }

    
    void printPerson(const Person* person) const {

        std::cout << "Name: " << person->getName() << std::endl;
        std::cout << "Age: " << person->getAge() << std::endl;
        std::cout << "Gender: " << person->getGender() << std::endl;
        std::cout << "Wants kids?: " << (person->getKids() ? "Yes" : "No") << std::endl;
        std::cout << "Interests: ";
        for (const auto& interest : person->getInterests()) {
            std::cout << interest << " ";
        }
        std::cout << std::endl;
    }

    void printMatches(const std::vector<Person>& matches) const {

        for (const auto& match : matches) {
            
            printPerson(&match);
            std::cout << std::endl;
        }
    }

};

#endif
