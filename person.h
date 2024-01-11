#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>

class Person{

    public:
        
        Person(const std::string& name, int age,  bool kids, char gender) 
        : name(name), age(age), kids(kids), gender(gender) {}

        std::string getName() const {
             return name;
        
        }
        int getAge() const {
            return age;
        }
        bool getKids() const{

            return kids;
        }
        char getGender() const {
            return gender;
        }

        // zainteresowania do wektora
        void addInterest(const std::string& interest) {
            interests.push_back(interest);
        }

        const std::vector<std::string>& getInterests() const {
            return interests;
        }


    private:
        std::string name;
        int age;
        bool kids;
        char gender;
        std::vector<std::string> interests;
        

};


#endif