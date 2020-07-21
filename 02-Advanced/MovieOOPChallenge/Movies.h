//Movies class - the interface of the main to the Movie class
#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <vector>
#include <iostream>
#include "Movie.h"

class Movies
{
private:
	std::vector<Movie*> moviesList;

public:

	//C'tors and D'tor:
	Movies();
	Movies(const Movies& otherMoviesList); // Deep Copy C'tor
	Movies(Movies&& tempMoviesList) noexcept; // Move Constructor (for r-value references - while working with pointers), for optimization
	~Movies();

	//Methods:
	bool addNewMovie(std::string newMovieName, int newMovieRating, int newMovieTimesWatched); // Display error if rating is not between 1 to 5 or if the movie is already in the list
	bool incrementMovieWatchedTimesByOne(std::string movieName); // Display error if movie name not found
	void displayAllMovies() const;
	void resetMoviesList();
};

#endif // _MOVIES_H_
