/*
CSCI 235 Fall 2023
Project 3 - Tavern Header
Created by Allison Lee on September 24 2023
Tavern.hpp declares the Tavern class along with its private and public members
    *Tavern class as a subclass of ArrayBag that stores Character objects
    *Tavern class has the private member variables sumLevels_ and sumEnemies
    *Tavern class has the unique public member functions Tavern constructor, enterTavern, exitTavern, 
        tallyRace, tavernReport(), getLevelSum(), calculateAvgLevel(), getEnemyCount(), 
        calculateEnemyPercentage()
*/

#ifndef PROJECT_3_TAVERN_CLASS_
#define PROJECT_3_TAVERN_CLASS_

#include "Character.hpp"
#include "ArrayBag.hpp"
#include <iostream>
#include <vector>

class Tavern : public ArrayBag<Character>{
private:
    // An integer sum of the levels of all the characters currently in the tavern
    int sum_levels_;
    // An integer count of all the characters currently in the Tavern that are marked as enemies
    int sum_enemies_;
public:
    /**
        Default constructor.
        Default-initializes all private members. 
    */
    Tavern();

    /** 
        @param:   A const reference to a Character entering the Tavern
        @return:  returns true if a Character was successfully added to the tavern (i.e. items_),  
                    false otherwise
        @post:    adds Character to the Tavern and updates the level sum and the enemy count 
                if the character is an enemy.
    **/
    bool enterTavern(const Character& entering);

    /** @param:   A const reference to a Character leaving the Tavern  
        @return:  returns true if a character was successfully removed from the tavern (i.e. items_),
                    false otherwise
        @post:    removes the character from the Tavern and updates the level sum and the enemy count
                if the character is an enemy.
    **/
    bool exitTavern(const Character& exiting);

    /** 
        @return:  The integer level count of all the characters currently in the Tavern
    **/
    int getLevelSum() const;

    /** 
        @return:  The average level of all the characters in the Tavern
        @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
    **/
    int calculateAvgLevel() const;

    /** 
        @return:  The integer enemy count of the Tavern
    **/
    int getEnemyCount() const;

    /** 
        @return:  The percentage (double) of all the enemy characters in the Tavern
        @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
    **/
    double calculateEnemyPercentage() const;

    /** 
        @param:   A const reference to a string representing a character Race with value in 
                ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
        @return:  An integer tally of the number of characters in the Tavern of the given race. 
                If the argument string does not match one of the expected race values, 
                the tally is zero. NOTE: no pre-processing of the input string necessary, only                  
                uppercase input will match.
    **/
    int tallyRace(const std::string& race) const;

    /**
    @post:      Outputs a report of the characters currently in the tavern in the form:
                "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average             level is: [x] \n[x]% are enemies.\n"
                Note that the average level should be rounded to the NEAREST integer, and the enemy             percentage should be rounded to 2 decimal places.

                Example output: 
                Humans: 3
                Elves: 5
                Dwarves: 8
                Lizards: 6
                Undead: 0

                The average level is: 7
                46.67% are enemies.
    */
    void tavernReport() const;

    /**
        @post:  Outputs name, race, level, enemy of every Character in Tavern
    */
    void print() const;

};

#endif