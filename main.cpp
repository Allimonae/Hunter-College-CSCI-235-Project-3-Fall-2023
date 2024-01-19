/*
CSCI 235 Fall 2023
Project 3 - main
Created by Allison Lee on September 24, 2023
main.cpp tests functions from project 3
*/
#include "Character.hpp"
#include "ArrayBag.hpp"
#include "Tavern.hpp"
#include <iostream>

int main(){
    Character char1("daniel", "HUMAN", 1, 2, 4, true);
    Character char2("Allison", "HUMAN", 1, 2, 11, false);
    Character char3("jenny", "ELF", 1, 2, 9, true);
    Character char4("angus", "DWARF", 1, 2, 9, false);
    Character char5("gabbie", "UNDEAD", 1, 2, 9, false);
    Character char6("carmen", "LIZARD", 1, 2, 9, true);
    Character char7("steph", "LIZARD", 1, 2, 9, false);
    Character char8("gigi", "LIZARD", 1, 2, 9, false);
    //char3.setEnemy();

    Tavern tavern;
    tavern.enterTavern(char1);
    tavern.enterTavern(char2);
    tavern.enterTavern(char3);
    tavern.enterTavern(char4);
    tavern.enterTavern(char5);
    tavern.enterTavern(char6);
    tavern.enterTavern(char7);
    //tavern.enterTavern(char8);
    tavern.print();
    tavern.tavernReport();
}