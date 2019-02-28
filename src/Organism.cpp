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

/** Organism::Organism() is default constructor for a Organism
 * @param none
 * @return none
 */
Organism::Organism() {


}
/** Organism::Organism() is the Secondary Constructor
 * @param bool b is whether the organism is an ant
 * @return none
 */
Organism::Organism(bool b) {
	amAnt = b;

}
/** Organism::isPrey() is a function used to tell if an organism is prey
 * @param none
 * @return bool returns if the organism is an ant
 */
bool Organism::isPrey()
{
	return amAnt;
}
/** Organism::setAmAnt() is a function used to set if an organism is an ant
 * @param bool b, the status of the organism, true if ant false otherwise
 * @return void
 */
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}


/** Organism::GetRandCell() takes a grid and a row column pair, and
 * returns a randomly picked neighboring cell with neighbors being defined as
 * 4-connected
 * @param int row, the row of the cell to a get random neighboring cell from
 * @param int col, the row of the cell to a get random neighboring cell from
 * @param Grid* g, the grid on which you are getting the random cell
 * @return output, a Coordinate struct, which contains the row, column coordinates
 * of the random neighboring cell
 */
struct Organism::Coordinates Organism::getRandCell(int row, int col, Grid* g){

	struct Coordinates output;
	// Cell row and col
	output.cellCol = -1;
	output.cellRow = -1;
	// gets the number of cells in a grid
	int n = g->getNumCells();
	// sets this value equal to the number of rows and the number of columns
	int nRows = n;
	int nCols = n;
	int cell = 0;
	// Get a random number from 0-arr_size, or the maximum number of elements in that array
	int numNeighbors = Organism::numPossCells(row, col, g);

	g->setRand();
	int a = g->getRand() % numNeighbors;

//	if (numNeighbors == 0){
//		output.cellRow = row;
//		output.cellCol = col;
//	}

	if (row > 0) {
		if (g->getCellOccupant(row - 1, col) == empty)	//N
		{
			cell++;
			if(cell == a){
				output.cellRow = row - 1;
				output.cellCol = col;
			}
		}
	}
	if (col > 0) {
		if (g->getCellOccupant(row, col - 1) == empty)	//W
		{
			cell++;
			if(cell == a){
				output.cellRow = row;
				output.cellCol = col - 1;
			}
		}
	}
	if (row < nRows - 1) {
		if (g->getCellOccupant(row + 1, col) == empty)	//S
		{
			cell++;
			if(cell == a){
				output.cellRow = row + 1;
				output.cellCol = col;
			}
		}
	}	//can look south
	if (col < (nCols - 1)) {
		if (g->getCellOccupant(row, col + 1) == empty)	//E
		{
			cell++;
			if(cell == a){
				output.cellRow = row;
				output.cellCol = col + 1;
			}
		}
	}
	return output;

}
/** Organism::numPossCells checks how many cells neighboring a
 * cell are empty and returns the count of all the empty neighbors
 * @param int row, the row that this cell is on
 * @param int col, the column that this cell is on
 * @param Grid* g,  is the grid of cells
 * @return int the number of empty neighbors
 */
int Organism::numPossCells(int row, int col, Grid* g) {
	// gets the number of cells in a grid
	int n = g->getNumCells();
	// the pointer to the array of unoccupied neighbors cells, which will never have more than 4 items
	int numNeighbors = 0;
	//there could be as many as 4 neighbors
	//cells on an edge or corner have fewer neighbors
	//we will search for neighbors clockwise from NorthWest
	if(row > 1){
		if (g->getCellOccupant(row - 1, col) == empty)	//N
		{
			numNeighbors++;
		}
	}//can look north
	if(col > 1){
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



/** Organism::~Organism is the destructor
 * @param none
 * @return none
 */
Organism::~Organism() {

}

