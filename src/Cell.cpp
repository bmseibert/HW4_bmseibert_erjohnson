/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Cell.h"
#include "Organism.h"

/* Cell::Cell() is a constructor of a cell
 *
 */
Cell::Cell() {

}

/* Cell::setOccupant sets the occupant of cell
 * @return bool result of if this worked
 */
bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;

	guest = g;

	// returns the result of if there is an occupant in a given cell
	return result;
}
/* Cell::qetOccupant gets the occupant of cell
 * @return the occupation status of a cell
 */
occupationStatus Cell::getOccupant()
{
	// returns the result of the guest
	return guest;
}

/* set Organism function
 * @return bool if the function worked
 *
 */
bool Cell::setOrganism(Organism * o){
	bool result = true;
	p = o;
	return result;
}
/* get Organism function
 * @return Organism Pointer
 *
 */
Organism* Cell::getOrganism(){

	return p;
}


/* Cell::~Cell is the destructor for a cell
 *
 */
Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

