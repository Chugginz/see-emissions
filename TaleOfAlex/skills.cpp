/**
 *******************************************************************************
 * @file    skills.cpp
 * @brief   Used as an implementation file for the skill upgrades
 *
 * @remarks
 *      Personal Project
 *
 * @author  Christian Huggins
 * @date    September 9th, 2021
 *******************************************************************************
**/

#include "skills.h"

void use_skillpoint(){
    points--;
}

int check_skillpoints(){
    return points;
}