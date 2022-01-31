// @ StudentArrayV4.cpp

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include<fstream>
    using std::ofstream;
    using std::ifstream;
    using std::ios;
#include <string>
    using std::stoi;
    using std::string;
#include <vector>
    using std::vector;
#include <iomanip>
#include <sstream>
    using std::stringstream;
#include "StudentArrayV4.h"

StudentArrayV4::StudentArrayV4(){
    physicalArraySize = 3;
    for (int i = 0; i < physicalArraySize; i++)
        members[i] = nullptr;
}

StudentArrayV4::~StudentArrayV4(){
    for (int i = 0; i < number_of_students; i++){
        delete members[i];
        members[i] = nullptr;
    }
    cout << "Memory Freed\n";
}

void StudentArrayV4::add(const Student& new_student){
    if (number_of_students == physicalArraySize){
        Student** copy = members;
        members = new Student*[physicalArraySize + 3];
        for (int i = 0; i < number_of_students; i++){
            members[i] = copy[i];
        }
        for (int i = 0; i < number_of_students; i++){
            delete copy[i];
            copy[i] = nullptr;
        }
    }
    
    physicalArraySize += 3;
    members{number_of_students} = new_student;
    number_of_students++;
}

int StudentArrayV4::add_all_from(istream& infile){
    while (!infile.eof())
        add_from(infile);
}

ostream& StudentArrayV4::write(ostream& outfile=cout) const{
    
}

void StudentArrayV4::add_from(istream infile){
    int counter = 0;
    int id = 0;
    double score = 0;
    string word;
    ifstream fin;
    fin.open("oop04in.txt");
    getline(fin, word, ' ');
    
    
    if (word.back() != ':')
        break;
    else
        set_name(word);
    
    getline(fin, word, ' ');
    stringstream digits(word);
    score >> id;
    members.set_id(id);
    
    while (getline(fin, word, ' ')){
        if (word.length() > 0){
            if (word.back() == ':')
                break;
            stringstream examScore(word);
            examScore >> score;
            set_exam_score(counter, score);
            counter++;
        }
    }
}
