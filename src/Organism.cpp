/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Organism.h"
bool amAnt = false;
/* Organism::Organism() Constructor used to generally create a doodlebug
 *
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub

}
/* Organism::Organism() Secondary Constructor
 * @param bool b is whether the organism is an ant
 */
Organism::Organism(bool b) {
	amAnt = b;

}
/* Organism::isPrey() is a function used to tell if an organism is prey
 * @return bool returns if the organism is an ant
 */
bool Organism::isPrey()
{
	return amAnt;
}
/* Organism::setAmAnt() is a function used to set if an organism is an ant
 * @return void
 */
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}
/* Organism::~Organism is the destructor
 *
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

