#include "Movies.h"

Movies::Movies()
	: moviesList{} // Initilaze to an empty vector
{
}

Movies::Movies(const Movies& otherMoviesList)
	: moviesList{} // Just initialize to empty vector - instead of delegating to the regular c'tor (won't be efficient)...
{
	for (const auto& movie : otherMoviesList.moviesList)
	{
		moviesList.push_back(new Movie(movie->getMovieName(), movie->getMovieRatings(), movie->getMovieWatchedTimeCount()));
	}
}

Movies::Movies(Movies&& tempMoviesList) noexcept // "Moving" the resoures on the heap - no need for Deep Copy here
	: moviesList{}
{
	for (auto& movie : tempMoviesList.moviesList)
	{
		moviesList.push_back(movie);
		movie = nullptr; // movie is actually a pointer to a movie object - "steal" the data without allocating new memory on the heap for the new instance (the temp memory of the temp movie object will be free but as a nullptr!)
	}
}

Movies::~Movies()
{
	for (size_t i{ 0 }; i < moviesList.size(); i++)
	{
		delete moviesList.at(i); // Free the storage
	}

	moviesList.clear();
}

bool Movies::addNewMovie(std::string newMovieName, int newMovieRating, int newMovieTimesWatched)
{
	bool movieExistsAlready{ false };

	if (newMovieRating <= 5 && newMovieRating >= 1) // Rating is in the correct range
	{
		for (const auto& movie : moviesList)
		{
			if (movie->getMovieName() == newMovieName)
			{
				movieExistsAlready = true;
				break;
			}
		}

		if (movieExistsAlready)
		{
			std::cout << "ERROR: MOVIE ALREADY EXISTS..." << std::endl;
			return false;
		}
		else // Movie doesn't exist and movie's rate indeed in the correct range
		{
			moviesList.push_back(new Movie(newMovieName, newMovieRating, newMovieTimesWatched)); // Adding the movie to the list
			std::cout << "The movie: \"" << newMovieName << "\", added successfuly!" << std::endl;
			return true;
		}
	}
	else
	{
		std::cout << "ERROR: MOVIE RATE IS NOT IN THE CORRECT RANGE (MUST BE: 1 TO 5 STARS ONLY!)..." << std::endl;
		return false;
	}
}


bool Movies::incrementMovieWatchedTimesByOne(std::string movieName)
{
	bool foundMovie{ false };

	for (auto& movie : moviesList) // No const here - Modifing the movie
	{
		if (movie->getMovieName() == movieName)
		{
			foundMovie = true;
			movie->incrementMovieWatchedTimesByOne();
			break;
		}
	}

	if (!foundMovie)
	{
		std::cout << "ERROR: MOVIE NOT FOUND..." << std::endl;
		return false;
	}
	else
	{
		std::cout << "Watched time of the movie: \"" << movieName << "\", has incremented successfuly!" << std::endl;
		return true;
	}
}


void Movies::displayAllMovies() const
{
	if (moviesList.empty())
	{
		std::cout << "The movies list is empty..." << std::endl;
	}
	else
	{
		std::cout << "\n===============================================" << std::endl;
		std::cout << "Movies list:" << std::endl;
		for (const auto& movie : moviesList)
		{
			std::cout << "Name: \"" << movie->getMovieName()
				<< "\", Rating: " << movie->getMovieRatings()
				<< ", Time Watched: " << movie->getMovieWatchedTimeCount() << std::endl;
		}
		std::cout << "===============================================" << std::endl;
		std::cout << std::endl;
	}
}


void Movies::resetMoviesList()
{
	moviesList.clear();
}
