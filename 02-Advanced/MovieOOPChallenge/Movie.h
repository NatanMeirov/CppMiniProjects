//Movie class SHOULD NOT "talk" to the console - thats what the movies class does (console UI)
#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

enum class MovieRatingStars
{
	OneStar = 1,
	TwoStars,
	ThreeStars,
	FourStars,
	FiveStars
};

class Movie
{
private:

	std::string movieName;
	MovieRatingStars movieRating;
	int movieWatchedTimesCount;

public:

	//C'tors and D'tor:
	Movie(std::string movieName, int movieRating, int movieWatchedTimesCount);
	Movie(const Movie& otherMovie);
	~Movie();

	//Getters:
	std::string getMovieName() const { return movieName; }
	int getMovieRatings() const { return static_cast<int>(movieRating); }
	int getMovieWatchedTimeCount() const { return movieWatchedTimesCount; }
	
	//Setters:
	void setMovieRating(int newMovieRating) { this->movieRating = static_cast<MovieRatingStars>(newMovieRating); }

	//Methods:
	void incrementMovieWatchedTimesByOne() { this->movieWatchedTimesCount++; }
};

#endif // _MOVIE_H_
