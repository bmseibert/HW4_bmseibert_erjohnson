/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Doodlebug.h"
/* Doodlebug::Doodlebug() Default Constructor
 * @param false is set for the organism input to tell the organism that it is not an ant
 */
Doodlebug::Doodlebug():Organism(false) {


}
/* Doodlebug::Doodlebug():Organism() Constructor
 * @param false is set for the organism input to tell the organism that it is not an ant
 * Doodlebug will have a Starve Counter and a Breed Counter it will also have a row and col for its location
 */
Doodlebug::Doodlebug(int r, int c):Organism(false) {
	row = r; //row
	col = c; //column

}
/* Doodlebug::move() Function, used to make a doodlebug move
 * @param
 *
 * @return bool returns true if the bug was able to move
 */
bool Doodlebug::move()
{
	bool status = true;
	return status;
}
/* Doodlebug::breed() Function, used to make a doodlebug breed
 * Breeding does NOT take precidence over death
 * @param
 *
 * @return bool returns true if the bug was able to breed
 */
bool Doodlebug::breed()
{
	bool status = true;
	return status;
}

/* Doodlebug::eat() Function, used to make a doodlebug eat, also kills an ant
 * Eating takes precidence over the majority of actions
 * @param
 *
 * @return bool returns true if the bug was able to eat
 */
bool Doodlebug::eat()
{
	bool status = true;
	return status;
}

/* Doodlebug::getStarveCnt() is a Function that gets the starve count
 * @return the starve count
 */
int Doodlebug::getStarveCnt(){
	return starveCnt;
}
/* Doodlebug Step Function
 * @return bool if the step worked
 */
bool Doodlebug::doodlebugStep(){
	bool ok1 = true;
	// FIRST
	// Move
	move();

	// SECOND
	// starve check
	if (starveCnt > 2){
		//~Doodlebug();
	}
	// THIRD
	// breed Check
	if (breedCnt > 7){
		breed();
	}

	// FOURTH
	// modify values
	increm();


	return ok1;
}
/*
 * Doodlebug Increment Function- used to increment the starve and breed counters
 * @return bool result on if the function ran properly
 */
bool Doodlebug::increm(){
	bool result = true;

	//increments the counters
	starveCnt++;
	breedCnt++;

	return result;
}


/* Doodlebug::~Doodlebug() Destructor, used to remove a pointer to a doodlebug
 * @param
 *
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

