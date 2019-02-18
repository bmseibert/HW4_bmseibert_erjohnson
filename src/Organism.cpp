/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Organism.h"
#include "Grid.h"
#include "Cell.h"

bool amAnt = false;
/* Organism::Organism() Constructor used to generally create a doodlebug
 *
 */
Organism::Organism() {


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
/**
 * HowManyNeighbors checks how many cells next to a given organism are empty
 * @param int row, the row that this cell is on
 * @param int col, the column that this cell is on
 * @param Grid g is the our grid
 * @return returns an integer number of neighbors between 0 and 4
 */
int Organism::HowManyNeighborsEmpty(int row, int col, Grid g) { //NEED TO REVISE TO HAVE IT PICK A RANDOM CELL
	// gets the number of cells in a grid
	int n = g.getNumCells();
	// sets this value equal to the number of rows and the number of columns
	int nRows = n;
	int nCols = n;
	// the number of neighbors
	int howManyN = 0;

	//there could be as many as 4 neighbors
	//cells on an edge or corner have fewer neighbors
	//we will search for neighbors clockwise from NorthWest
	if (row > 0) {
		if (g.getCellOccupant(row - 1, col) == empty)	//N
				{
			howManyN++;
		}
	}	//can look north
	if (col > 0) {
		if (g.getCellOccupant(row, col - 1) == empty)	//W
				{
			howManyN++;
		}
	}
	if (col < (nCols - 1)) {
		if (g.getCellOccupant(row, col + 1) == empty)	//E
				{
			howManyN++;
		}
	}
	if (row < nRows - 1) {
		if (g.getCellOccupant(row + 1, col) == empty)	//S
				{
			howManyN++;
		}
	}	//can look south

	return howManyN;
}


/* Organism::~Organism is the destructor
 *
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

