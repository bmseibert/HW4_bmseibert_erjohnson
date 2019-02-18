/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Doodlebug.h"
/* Doodlebug::Doodlebug():Organism() Constructor
 * @param false is set for the organism input to tell the organism that it is not an ant
 *
 */
Doodlebug::Doodlebug():Organism(false) {
	// TODO Auto-generated constructor stub

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
/* Doodlebug::~Doodlebug() Function, used to remove a pointer to a doodlebug
 * @param
 *
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

