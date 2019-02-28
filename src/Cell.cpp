/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Cell.h"
#include "Organism.h"

/** Cell::Cell() is a constructor of a cell
 * @param none
 * @return none
 */
Cell::Cell() {

}

/** Cell::setOccupant sets the occupationStatus of cell
 * @param occupationStatus g, is an enumeration that can be
 * empty, ant or doodlebug and represents what organism is in the cell
 * @return bool result of if this worked
 */
bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;

	guest = g;

	// returns the result of if there is an occupant in a given cell
	return result;
}
/** Cell::qetOccupant gets the occupantStatus of the cell
 * @param none
 * @return the occupationStatus of a cell  which is an enumeration that can be
 * empty, ant or doodlebug and represents what organism is in the cell
 */
occupationStatus Cell::getOccupant()
{
	// returns the result of the guest
	return guest;
}

/** Cell::setOrganism sets the field p which is the
 * pointer to the organism that is currently in the cell
 * @param Organism* o, The pointer to the organism that you want
 * to put in the current cell
 * @return bool if the function was successful
 */
bool Cell::setOrganism(Organism * o){
	bool result = true;
	p = o;
	return result;
}
/** Cell::getOrganism gets the field p which is the
 * pointer to the organism that is currently in the cell
 * @param none
 * @return Organism* p, The pointer to the organism in
 * the current cell
 */
Organism* Cell::getOrganism(){

	return p;
}


/** Cell::~Cell is the destructor for a cell
 * @oaram none
 * @return none
 */
Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

