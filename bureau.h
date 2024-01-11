#ifndef BUREAU_H
#define BUREAU_H

#include "person.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

class Bureau {
public:
    void addPerson(const Person& person);
    void deletePerson(const std::string& name);
    const Person* findPerson(const std::string& name) const;
    void readClientsFromFile(const std::string& filename);
    std::vector<Person> people;
    std::vector<Person> findMatches(const Person& person) const;
     
};



void Bureau::addPerson(const Person& person) {
    people.push_back(person);
}

//looking for a person by name using find if and labnda expression, taking external variable 

const Person* Bureau::findPerson(const std::string& name) const {

    auto it = std::find_if(people.begin(), people.end(), [&name](const Person& person) {
        return person.getName() == name;
    });

    if (it != people.end()) {
        return &(*it);  //returning the pointer to person object if found
    } else {
        return nullptr;  
    }
}

//filling the vector with data form txt file 
void Bureau::readClientsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        //creating teh string stream of read data 
        std::istringstream iss(line);
        std::string name;
        int age;
        bool kids;
        char gender;
        //assigning the data separated by spaces to variables 
        iss >> name >> age >> kids >> gender;

        //creating a person object 
        Person person(name, age, kids, gender);

        //adding the 3 interest to the person
        for (int i = 0; i < 3; ++i) {
            std::string interest;
            iss >> interest;
            person.addInterest(interest);
        }

        addPerson(person);
    }
    

    file.close();
}

#endif
