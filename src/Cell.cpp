/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Cell.h"
// occupation of a guest cell is automatically empty
occupationStatus guest  = empty;

/* Cell::Cell() is a constructor of a cell
 *
 */
Cell::Cell() {

	guest = empty;
}
/* Cell::setOccupant sets the occupant of cell
 * @return bool result of if this worked
 */
bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;
	// checks if a cell is empty
	if(guest==empty)
	{
		// if it is empty set the occupant of the cell to be the input of the guest
		// also returns true saying that the setting of the occupant worked
		guest = g;
	}
	else
	{
		// if it is full return false
		result = false;
	}
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

/* Cell::~Cell is the destructor for a cell
 *
 */
Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

