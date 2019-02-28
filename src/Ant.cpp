/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Ant.h"
#include "Grid.h"
#include <stdlib.h>
#include <stdio.h>


/** Ant::Ant() is the basic constructor for the
 * ant class
 *
 */
Ant::Ant() : Organism(true)
{

}

/** Ant::Ant() is another constructor for the
 * ant class, placing the ant object at the location
 * on the grid specified by the row and column
 * parameters
 * @param int r, the row where the ant will be constructed
 * @param int c, the column where the ant will be constructed
 * @param int life, the amount of ticks the ant object has
 * been alive on the board
 * @return none
 */
Ant::Ant(int r, int c, Grid * ptr) : Organism(true)
{
	row = r;
	col = c;
	g = ptr;
	// Counters are in the header
}
/** Ant::move() should move an ant object to a neighboring
 * cell
 * @param none
 * @return status, true if the ant object moved
 */
bool Ant::move()
{
	bool status = true;

	// FIRST
	// ant needs to check the surrounding cells and find all of the ones that are empty
	// pick one at random.
	struct Coordinates cell = getRandCell(row,col,g);
	int b[] = {cell.cellRow, cell.cellCol};
	if(b[0] == -1 && b[1] == -1){
		status = false;
	}
	else{
		//SECOND
		//modify the pointers to move
		g->setCellOrganism(b[0], b[1], g->getCellOrganism(row, col));
		g->setCellOccupant(b[0], b[1], ant);

		g->setCellOrganism(row, col, nullptr);
		g->setCellOccupant(row, col, empty);

		//g->printGrid();
		//printf("\n");
		//sets the ant row and column
		setRowAndCol(b[0],b[1]);
	}
	// CONSIDER:
	// ant should not move into a doodlebug or another ant

	return status;
}
/** Ant::breed() should check the cells around the ant
 * object and if another ant in is a neighboring cell,
 * then they will produce a new ant object in a free space
 * @param Grid* g grid we are on
 * @return status true if ant breed
 */
bool Ant::breed()
{
	// this is assuming that the counter has reached 3
	// and there is a place to breed
	bool status = true;

	// FIRST
	// Find Cell to Breed
	struct Coordinates cell = getRandCell(row, col, g);
	int b[] = {cell.cellRow, cell.cellCol};
	if(b[0] == -1 && b[1] == -1){
		status = false;
	}
	else{// SECOND
		// Create Ant from this breeding
		Ant * a1 = new Ant(b[0], b[1], g);
		// put it in the new cell
		g->setCellOccupant(b[0], b[1], ant);
		g->setCellOrganism(b[0], b[1], a1);

		// THIRD
		// Reset the Counter of breed to 0
		setBreedCnt(0);

		int numAnt = g->getNumAnt();
		numAnt++;
		g->setNumAnt(numAnt);

		increm();
	}
	return status;
}

/** Ant::Step() performs a move and breed if the conditions
 * for moving and breeding are met.
 * @param none
 * @return bool if the step worked
 */
bool Ant::step(){

	bool ok1 = true;
	// FIRST
	// Move
	if(Organism::numPossCells(row, col, g) > 0){
		move();
	}
	// SECOND
	// Check if breed
	if(breedCnt > 2 && Organism::numPossCells(row, col, g) > 0){
		breed();
		g->setNumAnt(g->getNumAnt()+1);
	}

	increm();

	return ok1;
}
/**
 * Ant::increm()- used to increment the breed counters
 * inside of the ant.
 * @return bool result on if the function ran properly
 */
bool Ant::increm(){
	bool result = true;

	//increments the counter
	breedCnt++;

	return result;
}

/* Set Breed Count
 * @param int i sets the count to i
 * @param bool result true if worked
 */
bool Ant::setBreedCnt(int i){
	bool result = true;
	breedCnt = 0;
	return result;
}

/* set the row and column function
 * @param int i sets the row
 * @param int j sets the col
 * @param bool result true if worked
 */
bool Ant::setRowAndCol(int i, int j){
	bool result = true;
	row = i;
	col = j;
	return result;
}

/** GetRandCell takes an array of pointers to cells and returns
 * a pseudo-random cell pointer from that array
 * @param int row,
 * @param int col, is the number of elements in the unoccupiedCells parameter
 * @return output, a random pointer to cell from the input array
 */
struct Ant::Coordinates Ant::getRandCell(int row, int col, Grid* g){

	struct Coordinates output;
	//int output[] = {-1, -1};
	// gets the number of cells in a grid
	int n = g->getNumCells();
	// sets this value equal to the number of rows and the number of columns
	int nRows = n;
	int nCols = n;
	int cell = 0;
	// Get a random number from 0-arr_size, or the maximum number of elements in that array
	int numNeighbors = numPossCells(row, col, g);
	if (numNeighbors == 0){
		output.cellRow = -1;
		output.cellCol = -1;

	}
	else{
		int a = 1 + rand() % numNeighbors;

		if (row > 0) {
			if (g->getCellOccupant(row - 1, col) == empty)	//N
			{
				cell++;
				if(cell == a){
					output.cellRow = row-1;
					output.cellCol = col;
					return output;
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
					return output;
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
					return output;
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
					return output;
				}
			}
		}
	}
	return output;

}
/* Set grid pointer function
 * @return bool of if the function worked
 */
bool Ant::setGridPtr(Grid * a){
	bool result = true;
	g = a;
	return result;
}


/** Ant::~Ant is a destructor for the ant class
 * indicating that a ant object has died
 *
 */
Ant::~Ant() {
	g->setCellOccupant(row, col, empty);
	g->setCellOrganism(row, col, nullptr);
	setGridPtr(nullptr);
}

