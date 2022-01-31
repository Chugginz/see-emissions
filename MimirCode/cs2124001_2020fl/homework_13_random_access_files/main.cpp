/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   Main file which tests the usage of the class methods made
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      11/30/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    November 30th, 2020
 *******************************************************************************
**/

#include "Campsite.h"
#include "CampsiteRecord.h"
#include "CampsiteDB.h"
#include<iostream>
    using std::cout;
#include<fstream>

int main(){
    //Establishing srand to use rand()
    srand(time(0));
    //Part 1
    // Test default c-tor
    CampsiteRecord site_rec1;   
    cout << "Empty record: " << site_rec1 << "\n";
    
    // Non-default c-tor
    CampsiteRecord site_rec2{42, "Lakefront Cabin", true, 300.00};
    cout << "Non-empty record: " << site_rec2 << "\n";
    
    // Read a record from a file
    std::ifstream fin{"sites.txt"};
    from_ascii_file(fin, site_rec1);
    fin.close();
    cout << "First site from file: " << site_rec1 << "\n";
    
    //Part 2
    Campsite site1 {3, "Riverfront Condo", true, 450.00};
    cout << site1 << '\n';
    
    CampsiteDB db{"campsites.db"};
    
    //Part 3
    cout << "File currently contains " << db.get_record_count() << " records.\n\n";

    fin.open("sites.txt");
    while(fin.good()){
        Campsite site;
        if(site.from_ascii_file(fin)){
            cout << "Adding " << site << "\n";
            db.write_next_sequential(site);
        }
    }
    
    cout << "\n\n";
    fin.close();    
    
    cout << "Read index is "  << db.get_current_index() << "\n";
    cout << "Write index is " << db.get_current_index(true) << "\n";
    cout << "File now contains " << db.get_record_count() << " records.\n\n";
    
    db.list_records();
    cout << "\n";
    
    //Part 4
    // Write different records in two places:
    db.write_at_index(8, Campsite{18, "Pavillion", true, 200.00});
    db.write_at_index(2, Campsite{12, "Treehouse", false, 250.00});
    
    // See if it worked:
    Campsite result = db.get_at_index(8); // should be "Pavillion"
    cout << result << "\n";
    result = db.get_at_index(2); // should be "Treehouse"
    cout << result << "\n";
    
    return 0;
}