/**
 *******************************************************************************
 * @file    luck.cpp
 * @brief   Used as a implementation file for the luck skill branch
 *
 * @remarks
 *      Personal Project
 *
 * @author  Christian Huggins
 * @date    September 9th, 2021
 *******************************************************************************
**/

#include "luck.h"

void LuckTree::upgrade_luck(){
    // Initialize user's choice for future input
    int choice;
    // Prompt User
    cout << "\nWhich would you like to upgrade?";
    cout << "\n - Crit Chance (1)";
    cout << "\n - Dealer Difficulty (2)";
    cout << "\n - Drops Modifier (3)\n";
    // Input Choice
    cin >> choice;
    // 
    if (choice == 1)
        upgrade_crit_chance();
    else if (choice == 2)
        upgrade_dealer_difficulty();
    else if (choice == 3)
        upgrade_drops_modifier();
    else{
        cout << "\nSilly Alex, that's not a choice!\n";
    }
}

void LuckTree::upgrade_crit_chance(){
    // Check to make sure enough skill points are available and upgrades
    // are not maxed
    if (check_skillpoints() > 0 && crit_chance < .07){
        // Use a skillpoint
        use_skillpoint();
        // If the crit chance is being maxed, boost more than usual
        if (crit_chance == .04)
            // Change crit chance to 7%
            crit_chance = .07;
        else
            // Else, only boost it by .01
            crit_chance += .01;
        
        // Increment total
        total++;
        // Check to see if luck overall needs to be increased
        check_luck_upgrade();
    } else{
        // The skill can not be upgraded by either option
        if (check_skillpoints() == 0)
            cout << "\nYou don't have any skillpoints to upgrade!\n";
        else
            cout << "\nYou've already maxed this skill!\n";
    }
}

void LuckTree::upgrade_dealer_difficulty(){
    // Check to make sure enough skill points are available and upgrades
    // are not maxed
    if (check_skillpoints() > 0 && dealer_difficulty != 1){
        // Use a skillpoint
        use_skillpoint();
        // Decrement dealer difficulty by 1
        dealer_difficulty--;

        // Increment total
        total++;
        // Check to see if luck overall needs to be increased
        check_luck_upgrade();
    } else{
        // The skill can not be upgraded by either option
        if (check_skillpoints() == 0)
            cout << "\nYou don't have any skillpoints to upgrade!\n";
        else
            cout << "\nYou've already maxed this skill!\n";
    }
}

void LuckTree::upgrade_drops_modifier(){
    // Check to make sure enough skill points are available and upgrades
    // are not maxed
    if (check_skillpoints() > 0 && drops_modifier != 1.5){
        // Use a skillpoint
        use_skillpoint();
        // If the drops modifier is being maxed, give it a boost
        if (drops_modifier == .9)
            // Upgrade it to 150%
            drops_modifier = 1.5;
        else
            // Upgrade drops modifier by normal amount
            drops_modifier += .1;
        
        // Increment total
        total++;
        // Check to see if luck overall needs to be increased
        check_luck_upgrade();
    } else{
        // The skill can not be upgraded by either option
        if (check_skillpoints() == 0)
            cout << "\nYou don't have any skillpoints to upgrade!\n";
        else
            cout << "\nYou've already maxed this skill!\n";
    }
}

void LuckTree::check_luck_upgrade(){
    if (total == 5){
        // Monsters now can drop 10 additional chips randomly
        // Set flag to true for additional drop
    } else if (total == 10){
        // Monsters now can drop 50 additional chips randomly
        // Set flag to true for additional drop
    } else if (total == 15){
        // Split hands bonus
        // If split hands, set flag to true for higher chances
        // of receiving higher cards
    } else if (total == 20){
        // Bust chance reduced
        // Chance of busting reduced by multiplying your chance to randomly
        // draw the bust card by the applied percentage
    } else if (total == 25){
        // Double down to 21
        // Chances of getting 21 or close are improved by multipling
        // the random chances by the applied percentage
    }
}