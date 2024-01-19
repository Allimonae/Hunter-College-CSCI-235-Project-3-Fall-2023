/*
CSCI 235 Fall 2023
Project 3 - Tavern Class
Created by Allison Lee on September 24 2023
Tavern.cpp defines the constructors and private and public function implementation of the Tavern class
    *Tavern class as a subclass of ArrayBag that stores Character objects
    *Tavern class has the private member variables sumLevels_ and sumEnemies
    *Tavern class has the unique public member functions Tavern constructor, enterTavern, exitTavern, 
        tallyRace, tavernReport(), getLevelSum(), calculateAvgLevel(), getEnemyCount(), 
        calculateEnemyPercentage()
*/

#include "Tavern.hpp"
#include "Character.hpp"
#include "ArrayBag.hpp"
#include <iostream>

/**
    Default constructor.
    Default-initializes all private members. 
*/
Tavern::Tavern(){
    sum_levels_ = 0;
    sum_enemies_ = 0;
}

/** 
    @param:   A const reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to the tavern (i.e. items_),  
                false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count 
            if the character is an enemy.
**/
bool Tavern::enterTavern(const Character& entering){
    if (add(entering)){
        sum_levels_ += entering.getLevel();
        if (entering.isEnemy()){
            sum_enemies_++;
        }
        return true;
    }
    else {return false;}
}

/** @param:   A const reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from the tavern (i.e. items_),
                false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count
            if the character is an enemy.
**/
bool Tavern::exitTavern(const Character& exiting){
    if (remove(exiting)){
        sum_levels_ -= exiting.getLevel();
        if (exiting.isEnemy()){
            sum_enemies_--;
        }
        return true;
    }
    else {return false;}
}

/** 
    @return:  The integer level count of all the characters currently in the Tavern
**/
int Tavern::getLevelSum() const{
    return sum_levels_;
}

/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Computes the average level of the Tavern rounded to the NEAREST integer.
**/
int Tavern::calculateAvgLevel() const{
    double value = (double)sum_levels_/getCurrentSize() + 0.5;
    return value;
}

/** 
    @return:  The integer enemy count of the Tavern
**/
int Tavern::getEnemyCount() const{
    return sum_enemies_;
}

/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
**/
double Tavern::calculateEnemyPercentage() const{
    double value = (int)(((double)sum_enemies_/getCurrentSize() + 0.00005) * 10000);
    return value/100;
}

/** 
    @param:   A const reference to a string representing a character Race with value in 
            ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return:  An integer tally of the number of characters in the Tavern of the given race. 
            If the argument string does not match one of the expected race values, 
            the tally is zero. NOTE: no pre-processing of the input string necessary, only                  
            uppercase input will match.
**/
int Tavern::tallyRace(const std::string& race) const{
    int count = 0;
    for (int i = 0; i < getCurrentSize(); i++){
        if (items_[i].getRace() == race){
            count++;
        }
    }
    return count;
}

/**
@post:      Outputs a report of the characters currently in the tavern in the form:
            "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average             
            level is: [x] \n[x]% are enemies.\n"
            Note that the average level should be rounded to the NEAREST integer, and the enemy             
            percentage should be rounded to 2 decimal places.

            Example output: 
            Humans: 3
            Elves: 5
            Dwarves: 8
            Lizards: 6
            Undead: 0

            The average level is: 7
            46.67% are enemies.
*/
void Tavern::tavernReport() const{
    std::cout << "Humans: " << tallyRace("HUMAN") << "\nElves: " << tallyRace("ELF") << "\nDwarves: " << 
        tallyRace("DWARF") << "\nLizards: " << tallyRace("LIZARD") << "\nUndead: " << tallyRace("UNDEAD") <<
        "\n\nThe average level is: " << calculateAvgLevel() << "\n" << calculateEnemyPercentage() << 
        "% are enemies.\n";
}

/**
    @post:  Outputs name, race, level, enemy of every Character in Tavern
*/
void Tavern::print() const{
   for (int i = 0; i < getCurrentSize(); i++){
      std::cout << items_[i].getName() << " " << items_[i].getRace() << " " << items_[i].getLevel() << " " << 
      items_[i].isEnemy() << std::endl;
   }
   std::cout << std::endl;
}
