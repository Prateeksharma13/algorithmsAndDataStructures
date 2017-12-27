#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

void compute_primes(int numbers[]);
void print_primes(int numbers[]);


/***** Complete this program. *****/

/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */

int main()
{
	int numbers[MAX_NUMBER]; //Creating an array of maximum possible number

	//Filling in the array

	for(int i = 0; i<= 1000; i++) {
		numbers[i] = i;
	}

	//Calling the function to compute all the primes

	compute_primes(numbers);
}


/**
 * Compute Primes: Compute all the primes up to MAX_NUMBER.
 */

void compute_primes(int numbers[]) {
	
	//Applying  sieve of Eratosthenes strting from number 2 up to square root of the maximum number

	for(int number_being_checked = 2; number_being_checked < sqrt(MAX_NUMBER); number_being_checked ++) {
		if(number_being_checked == 1) {
			continue;
		} else {
			int max_multiple = (MAX_NUMBER/number_being_checked)+1;
			for(int current_element = number_being_checked; current_element < max_multiple; current_element++) {
				numbers[current_element * number_being_checked] = 1;
			}
		}
	}

	//Print all the prime number
	print_primes(numbers);
}

/**
 * Print Primes: Print all the primes up to MAX_NUMBER.
 */

void print_primes(int numbers[]) {
	int current_element = 0; // Count to make sure a new line is added after 20 elements

	for(int i = 2; i < MAX_NUMBER; i++) {
		if(numbers[i] != 1) {
			if(current_element == ROW_SIZE) {
				current_element = 0;
				cout << endl;
			}
			current_element += 1;
			cout << std::setw(4) << numbers[i];
		}
	}

	cout << endl << endl << "Done!";
}
