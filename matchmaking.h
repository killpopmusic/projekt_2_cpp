#ifndef MATCHMAKING_H
#define MATCHMAKING_H

#include "person.h"
#include <vector>
#include <cmath>
#include <algorithm> 

//algorithm for matchmaking 

class Matchmaking {

public:
    static std::vector<Person> findMatches(const Person& person, const std::vector<Person>& people) {
    std::vector<Person> matches;

    //each person from people vector is taken to compare with the person we want to find a match for 

    for (const Person& p : people) {
        // looking for a different gender 
        if (p.getGender() == person.getGender()) {
            continue;  
        }

        // compatibility will be based on same inerests, wanting to have kids and age gap 
        int compatibilityScore = 0;


        const std::vector<std::string>& personInterests = person.getInterests();
        const std::vector<std::string>& pInterests = p.getInterests();

        
        int matchingInterests = 0;

        for (const std::string& interest : personInterests) {
            if (std::find(pInterests.begin(), pInterests.end(), interest) != pInterests.end()) {
                matchingInterests++;
            }
        }

        
        compatibilityScore += 2*matchingInterests;

        
        compatibilityScore += (p.getKids() == person.getKids()) ? 5 : 0;

        
        compatibilityScore += (std::abs(p.getAge() - person.getAge()) <= 5) ? 3 : 0;

        
        if (compatibilityScore > 5) {// the lowe limit of comp. score 
            matches.push_back(p);
        }
    }

    return matches;
}


};

#endif