/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Ant.h"

/** Ant::Ant() is the basic constructor for the
 * ant class
 *
 */
Ant::Ant() : Organism(true)
{

}

/** Ant::Ant() is another constructor for the
 * ant class, placing the ant object at the location
 * on the grid specified by the row and column
 * parameters
 * @param int r, the row where the ant will be constructed
 * @param int c, the column where the ant will be constructed
 * @param int life, the amount of ticks the ant object has
 * been alive on the board
 * @return
 *
 */
Ant::Ant(int r, int c) : Organism(true)
{
	row = r;
	col = c;
	// Counters are in the header
}
/** Ant::move() should move an ant object to a neighboring
 * cell
 * @param
 * @return status, true if the ant object moved
 */
bool Ant::move()
{
	bool status = true;

	// FIRST
	// ant needs to check the surrounding cells and find all of the ones that are empty
	// pick one at random and move to it

	// CONSIDER:
	// ant should not move into a doodlebug or another ant

	return status;
}
/** Ant::breed() should check the cells around the ant
 * object and if another ant in is a neighboring cell,
 * then they will produce a new ant object in a free space
 * @param Grid* g grid we are on
 * @return status
 */
bool Ant::breed(Grid* g)
{
	// this is assuming that the counter has reached 3
	// and there is a place to breed
	bool status = true;

	// FIRST
	// Find Cell to Breed
	Cell a = getRandCell(row, col, g);

	// SECOND
	// Create Ant from this breeding


	// THIRD
	// Reset the Counter of breed to 0

	return status;
}
/* Ant Step Function
 * @return bool if the step worked
 */
bool Ant::step(Grid* g){

	bool ok1 = true;
	// FIRST
	// Move
	move();
	// SECOND
	// Check if breed
	if(breedCnt > 2 && howManyNeighbors(row, col, g) > 0){
		breed(g);
	}
	// THIRD
	// Increment
	increm();


	return ok1;
}
/*
 * Ant Increment Function- used to increment the breed counters
 * @return bool result on if the function ran properly
 */
bool Ant::increm(){
	bool result = true;

	//increments the counter
	breedCnt++;

	return result;
}
/** Ant::~Ant is a destructor for the ant class
 * indicating that a ant object has died
 *
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

