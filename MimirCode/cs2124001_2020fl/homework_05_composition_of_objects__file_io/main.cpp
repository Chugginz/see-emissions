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
#include <iomanip>

int main(){
    string word;
    ifstream fin;
    fin.open("oop04in.txt");
    getline(fin, word, ' ');
    
    while (getline(fin, word, ' ')){
        if (word.length() > 0){
            if (word.back() == ':')
                break;
            cout << word << endl;
        }
    }
    
    return 0;
}
//if (line.back() == ':')
//line.pop_back();