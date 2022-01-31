/**
 *******************************************************************************
 * @file    luck.h
 * @brief   Used as a header file for the luck skill branch
 *
 * @remarks
 *      Personal Project
 *
 * @author  Christian Huggins
 * @date    September 9th, 2021
 *******************************************************************************
**/

#ifndef LUCK_H
#define LUCK_H

#include "master.h"
#include "skills.h"

class LuckTree : protected Skills{
public:
   void upgrade_luck();
   void upgrade_crit_chance();
   void upgrade_dealer_difficulty();
   void upgrade_drops_modifier();
   void check_luck_upgrade();
private:
    float crit_chance = 0;
    float drops_modifier = 0;
    int dealer_difficulty = 10;
    int luck = 1;
    int total = 0;
};

#endif