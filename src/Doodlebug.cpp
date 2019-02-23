/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Doodlebug.h"
#include <stdlib.h>
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
 * @return bool returns true if the bug was able to breed
 */
bool Doodlebug::breed()
{
	bool status = true;

	// FIRST
	// Find Cell to Breed
	int* a = getRandCell(row, col, g);
	int b[1] = {*a};
	// SECOND
	// Create doodlebug from this breeding
	Doodlebug* d1 = new Doodlebug(b[0], b[1]);
	// put it in the new cell
	g->setCellOccupant(b[0], b[1], doodlebug);
	g->getCell(b[0], b[1]).setOrganism(d1);

	//Add a doodlebug to the total counter in the grid
	int totalDoodleBugs = g->getNumDoodle();
	totalDoodleBugs++;
	g->setNumDoodle(totalDoodleBugs);
	// THIRD
	// Reset the Counter of breed to 0
	setBreedCnt(0);

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

	//Check surrounding cells for
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
bool Doodlebug::step(){
	bool ok1 = true;
	// FIRST
	// Move
	//move();

	// SECOND
	// starve check
	if (starveCnt > 2){
		//DELETE DOODLE BUG
		this->~Doodlebug();
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
/* Set Breed Count
 * @param int i sets the count to i
 * @param bool result true if worked
 */
bool Doodlebug::setBreedCnt(int i){
	bool result = true;
	breedCnt = i;
	return result;
}

/**
 * GetNeighbors checks how many cells next to a doodlebug contain ants
 * and then increments a value depending on how many neighbors are ants
 * @param int row, the row that this cell is on
 * @param int col, the column that this cell is on
 * @param Grid g is the grid of cells
 * @return numNeighbors is an int the
 */
int Doodlebug::howManyNeighbors(int row, int col, Grid* g) {
	// gets the number of cells in a grid
	int n = g->getNumCells();
	// the number of neighboring cells with ants in them
	int numNeighbors = 0;
	//there could be as many as 4 neighbors
	//cells on an edge or corner have fewer neighbors
	//we will search for neighbors clockwise from NorthWest
	if(row > 0){
		if (g->getCellOccupant(row - 1, col) == ant)	//N
		{
			numNeighbors++;
		}
	}//can look north
	if(col > 0){
		if (g->getCellOccupant(row, col - 1) == ant)	//W
		{
			numNeighbors++;
		}
	}
	if(row < n-1){
		if (g->getCellOccupant(row + 1, col) == ant)	//S
		{
			numNeighbors++;
		}
	}//can look south
	if(col < n-1){
		if (g->getCellOccupant(row, col + 1) == ant)	//E
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
int* Doodlebug::getRandCell(int row, int col, Grid* g){

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
		if (g->getCellOccupant(row - 1, col) == ant)	//N
		{
			cell++;
			if(cell == a){
				output[0] = row-1;
				output[1] = col;
			}
		}
	}	//can look north
	if (col > 0) {
		if (g->getCellOccupant(row, col - 1) == ant)	//W
		{
			cell++;
			if(cell == a){
				output[0] = row;
				output[1] = col-1;
			}
		}
	}
	if (row < nRows - 1) {
		if (g->getCellOccupant(row + 1, col) == ant)	//S
		{
			cell++;
			if(cell == a){
				output[0] = row+1;
				output[1] = col;
			}
		}
	}	//can look south
	if (col < (nCols - 1)) {
		if (g->getCellOccupant(row, col + 1) == ant)	//E
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



/* Doodlebug::~Doodlebug() Destructor, used to remove a pointer to a doodlebug
 *
 */
Doodlebug::~Doodlebug() {
// THERE MAY BE MORE STUFF NEEDED IN HERE

}

