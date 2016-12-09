// primes.cpp
//
// Functions to find the prime numbers.
// g++ -Wall primes.cpp -o primes --std=c++11
//
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <stdexcept>

static bool is_prime( unsigned int n );
static unsigned int smallest_prime_factor_of( unsigned int n );
static std::list<unsigned int>& prime_factors_of( unsigned int n );

static void print_primes( unsigned int min, unsigned int max );
static void print_prime_factors( unsigned int min, unsigned int max );

int main( int argc, char **argv )
{
	print_primes( 1, 1000 );
	print_prime_factors( 1, 1000 );
	print_prime_factors( 100000, 100050 );

}

static bool is_prime( unsigned int n )
{
	if ( n < 2 )
		return false;
	if ( n % 2 == 0 )
		return false;
	if ( n % 3 == 0 )
		return false;

	unsigned int sqrt_n = static_cast<unsigned int>( sqrt( n ) );
	for ( unsigned int i = 5; i <= sqrt_n; i++ ) {
		if ( n % i == 0 )
			return false;
	}

	return true;
}

static unsigned int smallest_prime_factor_of( unsigned int n )
{
	// TODO implement this
	return 0;
}

//
// TODO: re-write this using the smallest_prime_factor() function
//
static std::list<unsigned int>& prime_factors_of( unsigned int n )
{
	std::list<unsigned int> *factors = new std::list<unsigned int>;
	if ( factors == 0 )
		throw std::runtime_error( "new failed on list" );

	unsigned int original_n = n;
	unsigned int sqrt_n = static_cast<unsigned int>( sqrt( n ) );
	unsigned int i = 2;
	while ( i <= sqrt_n && n > 1 ) {
		if ( n % i == 0 ) {
			factors->push_back( i );
			n /= i;
		} else {
			i++;
		}
	}

	if ( factors->size() == 0 )
		factors->push_back( original_n );

	return *factors;
}

static void print_primes( unsigned int min, unsigned int max )
{
	if ( min < 1 )
		throw std::invalid_argument( "invalid min");
	if ( max < 1 )
		throw std::invalid_argument( "invalid max" );
	if ( min > max )
		throw std::invalid_argument( "min greater than max" );

	for ( unsigned int i = min; i <= max; i++ ) {
		if ( is_prime( i ) )
			std::cout << std::setw(8) << i;
	}
	std::cout << std::endl;
}

static void print_prime_factors( unsigned int min, unsigned int max )
{
	if ( min < 1 )
		throw std::invalid_argument( "invalid min");
	if ( max < 1 )
		throw std::invalid_argument( "invalid max" );
	if ( min > max )
		throw std::invalid_argument( "min gretaer than max" );

	for ( unsigned int i = min; i <= max; i++ ) {
		std::cout << std::setw(8) << i << ": ";
		std::list<unsigned int>& factors = prime_factors_of( i );
		for ( auto i = factors.begin(); i != factors.end(); ++i ) {
			std::cout << std::setw(8) << *i;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

