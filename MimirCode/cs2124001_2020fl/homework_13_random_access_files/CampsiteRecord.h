/**
 *******************************************************************************
 * @file    CampsiteRecord.h
 * @brief   Header file used to hold the class CampsiteRecord which manages
 *          information about Campsites
 *
 * @author  Christian Huggins
 * @date    December 9th, 2020
 *******************************************************************************
**/

#ifndef CAMPSITERECORD_H
#define CAMPSITERECORD_H

#include<cstring>
#include<iostream>
#include<fstream>
#include<iomanip>

/**
 * A fixed-size record representing a campsite in a 
 * recreational area.
 */
struct CampsiteRecord {
    CampsiteRecord();
    CampsiteRecord(int number, const char description[], bool has_electric, double rate);
    
    static const int desc_size = 128;         /// max storage size of description
    int              number;                  /// site number
    char             description[desc_size];  /// a short description
    bool             has_electric;            /// is power available?
    double           rate;                    /// per-night rate
};

std::istream& from_ascii_file(std::istream& strm, CampsiteRecord& site);
std::ostream& operator<<(std::ostream& strm, const CampsiteRecord& site);

#endif