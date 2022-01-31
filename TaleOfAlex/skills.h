/**
 *******************************************************************************
 * @file    skills.h
 * @brief   Used as a header file for the skill upgrades
 *
 * @remarks
 *      Personal Project
 *
 * @author  Christian Huggins
 * @date    September 9th, 2021
 *******************************************************************************
**/

#ifndef SKILLS_H
#define SKILLS_H

#include "master.h"

class Skills{
public:
    void use_skillpoint();
    int check_skillpoints();

private:
    int points = 0;
};

#endif