#include <iostream>
#include "Movies.h"


int main()
{
	Movies myMovies;

	myMovies.displayAllMovies(); // empty

	myMovies.addNewMovie("Star Wars", 4, 2);
	myMovies.addNewMovie("Avatar", 3, 1);
	myMovies.addNewMovie("Harry Potter", 5, 7);
	
	myMovies.displayAllMovies();

	myMovies.incrementMovieWatchedTimesByOne("Star Wars");
	myMovies.displayAllMovies(); // After incrementation

	myMovies.addNewMovie("Some Fake Movie", 0, 0); // // Should display an error (rating error)
	myMovies.addNewMovie("Avatar", 3, 1); // Should display an error (movie already exists error)
	myMovies.incrementMovieWatchedTimesByOne("Cinderella"); // Should display an error (not found movie error)

	myMovies.resetMoviesList();
	myMovies.displayAllMovies(); // empty once again

	return 0;
}