/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Organism.h"
#include "Grid.h"
#include "Cell.h"
#include <stdlib.h>

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
 * GetNeighbors checks how many cells next to a given organism are empty and then
 * add all the unoccupied neighbors to an array
 * @param int row, the row that this cell is on
 * @param int col, the column that this cell is on
 * @param Grid g is the grid of cells
 * @return unocc_arr is an array of pointers to cells
 */
Cell** Organism::GetNeighbors(int row, int col, Grid g) {
	// gets the number of cells in a grid
	int n = g.getNumCells();
	// sets this value equal to the number of rows and the number of columns
	int nRows = n;
	int nCols = n;
	// the pointer to the pointer array of unoccupied neighbors cells
	Cell* unocc_arr[] = (Cell**)nullptr;

	//there could be as many as 4 neighbors
	//cells on an edge or corner have fewer neighbors
	//we will search for neighbors clockwise from NorthWest
	if (row > 0) {
		if (g.getCellOccupant(row - 1, col) == empty)	//N
				{
			**unocc_arr = g.getCell((row-1), col);
			unocc_arr++;
		}
	}	//can look north
	if (col > 0) {
		if (g.getCellOccupant(row, col - 1) == empty)	//W
				{
			**unocc_arr = g.getCell(row, (col-1));
			unocc_arr++;
		}
	}
	if (col < (nCols - 1)) {
		if (g.getCellOccupant(row, col + 1) == empty)	//E
				{
			**unocc_arr = g.getCell(row, (col+1));
			unocc_arr++;
		}
	}
	if (row < nRows - 1) {
		if (g.getCellOccupant(row + 1, col) == empty)	//S
				{
			**unocc_arr = g.getCell((row+1), col);
		}
	}	//can look south

	return unocc_arr;
}

/** GetRandCell takes an array of pointers to cells and returns
 * a pseudo-random cell pointer from that array
 * @param Cell** unoccupiedCells, is the array of pointers to cells
 * that we want a random cell from
 * @param int arrSize, is the number of elements in the unoccupiedCells parameter
 * @return outCell, a random pointer to cell from the input array
 */
Cell* Organism::GetRandCell(Cell** unoccupiedCells, int arrSize){
	// Get a random number from 0-arr_size, or the maximum number of elements in that array
	int cell = rand() % arrSize;

	Cell* outCell = unoccupiedCells[cell];

	return outCell;
}


/* Organism::~Organism is the destructor
 *
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

