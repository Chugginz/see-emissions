/**
 *******************************************************************************
 * @file    spHWstructures.cpp
 * @brief   Reading a list of movies, sorting them, writing to files in
 *          alphabetical order and ascending order based on profit, a displays
 *          highest profiting movie and details for user.
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Monday, April 27
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    April 24, 2020
 *******************************************************************************
**/

#include <iostream>
   using std::cin;
   using std::cout;
   using std::endl;
   using std::istream;
   using std::ostream;

#include <fstream>
   using std::ofstream;
   using std::ifstream;

#include <iomanip>
   using std::setprecision;
   using std::fixed;

#include <string>
   using std::string;

#include <vector>
   using std::vector;

#include <algorithm>
   using std::swap;

#include <limits>

struct MovieData
{
    string movieTitle;
    string directorName;
    int yearReleased;
    int runningTime;
    double productionCost;
    double generatedRevenue;
    double profitOrLossAmount;
};

// define MovieData structure here
/*
void readAndCalculate(istream&, vector<MovieData>&);
void bubbleSortByName(vector<MovieData>&);
void bubbleSortByProfit(vector<MovieData>&);
void write(ostream&, const vector<MovieData>&);
void displaySingleMovie(const MovieData&);
MovieData determineHighestProfitMovie(const vector<MovieData>&);
*/

/**
 * @brief       This function reads from a file storing the results in a 
 *              structure and then storing the structure in a vector.
 *
 * @detailed    This function reads two lines of strings, then reads the rest
 *              of the values as ints or doubles, then stores them into
 *              structures and then into vectors.
 *              
 * @param       infile      File handle
 * @param       movies      Vector "movie" for storing movie information
 *                          read and calculated from the file.
**/

void readAndCalculate(istream& infile, vector<MovieData>& movies)
{
// similar to readAndCalculate from tutorial
    MovieData movie;
    
    while (! infile.eof())
    {
        getline(infile, movie.movieTitle, ';');
        getline(infile, movie.directorName, ';');
        
        infile >> movie.yearReleased;
        infile.ignore(1, ';');
        infile >> movie.runningTime;
        infile.ignore(1, ';');
        infile >> movie.productionCost;
        infile.ignore(1, ';');
        infile >> movie.generatedRevenue;
        infile.ignore();
        
        movie.profitOrLossAmount = movie.generatedRevenue 
        - movie.productionCost;
        movies.push_back(movie);
    }
}

/**
 * @brief       This function bubble sorts by ascii values
 *
 * @detailed    This reads from the vector and rearranges the vector
 *              in alphabetical order based on ascii.
 *              
 * @param       movies      Vector "movie" being rearranged in alphabetical
 *                          order
**/

void bubbleSortByName(vector<MovieData>& movies)
{
// similar to bubbleSortByName from tutorial
    int counter = 0;
    int max = movies.size();
    bool swap = true;
    
    while (swap == true)
    {
        swap = false;
        for (int i = 0; i <= max - 2; i++)
        {
            string movieTitle1 = movies[i].movieTitle;
            string movieTitle2 = movies[i + 1].movieTitle;
            
            if (movieTitle1 > movieTitle2)
            {
                string temp1, temp2;
                int temp3, temp4;
                double temp5, temp6, temp7;
                
                temp1 = movies[i].movieTitle;
                temp2 = movies[i].directorName;
                temp3 = movies[i].yearReleased;
                temp4 = movies[i].runningTime;
                temp5 = movies[i].productionCost;
                temp6 = movies[i].generatedRevenue;
                temp7 = movies[i].profitOrLossAmount;
                
                movies[i].movieTitle = movies[i + 1].movieTitle;
                movies[i].directorName = movies[i + 1].directorName;
                movies[i].yearReleased = movies[i + 1].yearReleased;
                movies[i].runningTime = movies[i + 1].runningTime;
                movies[i].productionCost = movies[i + 1].productionCost;
                movies[i].generatedRevenue = movies[i + 1].generatedRevenue;
                movies[i].profitOrLossAmount = movies[i + 1].profitOrLossAmount;
                
                movies[i + 1].movieTitle = temp1;
                movies[i + 1].directorName = temp2;
                movies[i + 1].yearReleased = temp3;
                movies[i + 1].runningTime = temp4;
                movies[i + 1].productionCost = temp5;
                movies[i + 1].generatedRevenue = temp6;
                movies[i + 1].profitOrLossAmount = temp7;
                swap = true;
            }
        }
        
        counter++;
    }
}

/**
 * @brief       This function bubble sorts by profit
 *
 * @detailed    This reads from the vector and rearranges the vector
 *              in ascending order.
 *              
 * @param       movies      Vector "movie" being rearranged in alphabetical
 *                          order
**/

void bubbleSortByProfit(vector<MovieData>& movies)
{
int counter = 0;
    int max = movies.size();
    bool swap = true;
    
    while (swap == true)
    {
        swap = false;
        for (int i = 0; i <= max - 2; i++)
        {
            int profitOrLossAmount1 = movies[i].profitOrLossAmount;
            int profitOrLossAmount2 = movies[i + 1].profitOrLossAmount;
            
            if (profitOrLossAmount1 < profitOrLossAmount2)
            {
                string temp1, temp2;
                int temp3, temp4;
                double temp5, temp6, temp7;
                
                temp1 = movies[i].movieTitle;
                temp2 = movies[i].directorName;
                temp3 = movies[i].yearReleased;
                temp4 = movies[i].runningTime;
                temp5 = movies[i].productionCost;
                temp6 = movies[i].generatedRevenue;
                temp7 = movies[i].profitOrLossAmount;
                
                movies[i].movieTitle = movies[i + 1].movieTitle;
                movies[i].directorName = movies[i + 1].directorName;
                movies[i].yearReleased = movies[i + 1].yearReleased;
                movies[i].runningTime = movies[i + 1].runningTime;
                movies[i].productionCost = movies[i + 1].productionCost;
                movies[i].generatedRevenue = movies[i + 1].generatedRevenue;
                movies[i].profitOrLossAmount = movies[i + 1].profitOrLossAmount;
                
                movies[i + 1].movieTitle = temp1;
                movies[i + 1].directorName = temp2;
                movies[i + 1].yearReleased = temp3;
                movies[i + 1].runningTime = temp4;
                movies[i + 1].productionCost = temp5;
                movies[i + 1].generatedRevenue = temp6;
                movies[i + 1].profitOrLossAmount = temp7;
                swap = true;
            }
        }
        
        counter++;
    }
}

/**
 * @brief       This function writes to a file given a vector
 *
 * @detailed    This function writes to a file given a vector using a
 *              counter to ensure everything is written to the file.
 *              
 * @param       outfile     File handle
 * @param       movies      Vector "movie" for storing movie information
 *                          read and calculated from the file.
**/

void write(ostream& outfile, const vector<MovieData>& movies)
{
    int max = movies.size();
    int i = 0;
    
	outfile << fixed << setprecision(2);
    while (i < max)
    {
        outfile << movies[i].movieTitle << ";" << movies[i].directorName << ";"
        << movies[i].yearReleased << ";" << movies[i].runningTime << ";"
        << movies[i].productionCost << ";" << movies[i].generatedRevenue << ";"
        << movies[i].profitOrLossAmount << endl;
        i++;
    }
}

/**
 * @brief       This function displays a movie and it's details
 *
 * @detailed    Given a structure, this function will display all information
 *              contained in the structure
 *              
 * @param       singleMovie     Structure "singleMovie" containing movie title, director
 *                              name, year released, run time, cost of production, 
 *                              revenue made, and the profit or loss made.
**/

void displaySingleMovie(const MovieData& singleMovie)
{
	// fill in code to output the fields of a single movie's structure to the screen
	cout << fixed << setprecision(2);
	cout << singleMovie.movieTitle << endl;
	cout << singleMovie.directorName << endl;
	cout << singleMovie.yearReleased << endl;
	cout << singleMovie.runningTime << endl;
	cout.imbue(std::locale("en_US.utf-8"));
	cout << "$" << singleMovie.productionCost << endl;
	cout.imbue(std::locale("en_US.utf-8"));
	cout << "$" << singleMovie.generatedRevenue << endl;
	cout.imbue(std::locale("en_US.utf-8"));
	cout << "$" << singleMovie.profitOrLossAmount << endl;
}

/**
 * @brief       This function returns the structure of the highest profit movie
 *
 * @detailed    This function assumes this has been bubble sorted by profit and
 *              that the first vector element contains the highest profiting movie,
 *              assigning it to a structure and then returning it.
 *              
 * @param       movies      Vector "movie" being read to find the highest profiting movie.
 * 
 * @return      returns a structure refered to as singleMovie.
**/

MovieData determineHighestProfitMovie(const vector<MovieData>& movies)
{
    MovieData singleMovie;
    singleMovie = movies[0];
    
    return singleMovie;
}

int main()
{
	string filename;
	cout << "Enter the name of the file containing the movie data (include file extension):  ";
	getline(cin,filename);
	
	ifstream fin(filename);
	if (!fin)
	{
		cout << "Unable to open " << filename << endl;
		cout << "Exiting...\n\n";
	}
	else
	{
		vector<MovieData> allMovies;
		readAndCalculate(fin,allMovies);
		fin.close();
		if (allMovies.size() > 0)
		{
			bubbleSortByName(allMovies);
			ofstream fout("sortedAlpha.txt");
			write(fout,allMovies);
			fout.close();
			
			bubbleSortByProfit(allMovies);
			fout.open("sortedProfitLoss.txt");
			write(fout,allMovies);
			fout.close();
			
			cout << "\n\nMovie with highest profit:  ";
			displaySingleMovie(determineHighestProfitMovie(allMovies));
		}
	}		
	
	return 0;
}


