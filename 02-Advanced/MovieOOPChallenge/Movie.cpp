#include "Movie.h"

Movie::Movie(std::string movieName, int movieRating, int movieWatchedTimesCount)
	: movieName{movieName}, movieRating{static_cast<MovieRatingStars>(movieRating)}, movieWatchedTimesCount{ movieWatchedTimesCount }
{
}

Movie::Movie(const Movie& otherMovie) // Not really needed - just for practice
	: movieName{ otherMovie.movieName }, movieRating{ otherMovie.movieRating }, movieWatchedTimesCount{ otherMovie.movieWatchedTimesCount }
{
}

Movie::~Movie()
{
}
