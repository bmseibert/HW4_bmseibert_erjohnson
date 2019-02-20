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
int Organism::howManyNeighbors(int row, int col, Grid* g) {
	// gets the number of cells in a grid
	int n = g->getNumCells();
	// the pointer to the array of unoccupied neighbors cells, which will never have more than 4 items
	int numNeighbors = 0;
	//there could be as many as 4 neighbors
	//cells on an edge or corner have fewer neighbors
	//we will search for neighbors clockwise from NorthWest
	if(row > 0){
		if (g->getCellOccupant(row - 1, col) == empty)	//N
		{
			numNeighbors++;
		}
	}//can look north
	if(col > 0){
		if (g->getCellOccupant(row, col - 1) == empty)	//W
		{
			numNeighbors++;
		}
	}
	if(row < n-1){
		if (g->getCellOccupant(row + 1, col) == empty)	//S
		{
			numNeighbors++;
		}
	}//can look south
	if(col < n-1){
		if (g->getCellOccupant(row, col + 1) == empty)	//E
		{
			numNeighbors++;
		}
	}
	return numNeighbors;
}

/** GetRandCell takes an array of pointers to cells and returns
 * a pseudo-random cell pointer from that array
 * @param int row,
 * @param int col, is the number of elements in the unoccupiedCells parameter
 * @return output, a random pointer to cell from the input array
 */
int* Organism::getRandCell(int row, int col, Grid* g){

	int output[] = {-1, -1};
	// gets the number of cells in a grid
	int n = g->getNumCells();
	// sets this value equal to the number of rows and the number of columns
	int nRows = n;
	int nCols = n;
	int cell = 0;
	// Get a random number from 0-arr_size, or the maximum number of elements in that array
	int numNeighbors = howManyNeighbors(row, col, g);
	int a = rand() % numNeighbors;

	if (numNeighbors == 0){
		output[0] = row;
		output[1] = col;
	}

	if (row > 0) {
		if (g->getCellOccupant(row - 1, col) == empty)	//N
		{
			cell++;
			if(cell == a){
				output[0] = row-1;
				output[1] = col;
			}
		}
	}	//can look north
	if (col > 0) {
		if (g->getCellOccupant(row, col - 1) == empty)	//W
		{
			cell++;
			if(cell == a){
				output[0] = row;
				output[1] = col-1;
			}
		}
	}
	if (row < nRows - 1) {
		if (g->getCellOccupant(row + 1, col) == empty)	//S
		{
			cell++;
			if(cell == a){
				output[0] = row+1;
				output[1] = col;
			}
		}
	}	//can look south
	if (col < (nCols - 1)) {
		if (g->getCellOccupant(row, col + 1) == empty)	//E
		{
			cell++;
			if(cell == a){
				output[0] = row;
				output[1] = col+1;
			}
		}
	}
	return output;

}


/* Organism::~Organism is the destructor
 *
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

