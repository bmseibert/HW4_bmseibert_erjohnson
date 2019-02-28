/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include "Doodlebug.h"
#include "Grid.h"
#include <stdlib.h>
#include <stdio.h>



/** Doodlebug::Doodlebug() Default Constructor
 * @param false is set for the organism input to tell the organism that it is not an ant
 * @return none
 */
Doodlebug::Doodlebug():Organism(false) {


}
/** Doodlebug::Doodlebug():Organism() Constructor
 * @param int r, The row the doodlebug should be constructed on
 * @param int c, The col the doodlebug should be constructed on
 * @param Grid * ptr, The pointer to the grid the doodlebug is geing created on
 * @param false is set for the organism input to tell the organism that it is not an ant
 * Doodlebug will have a Starve Counter and a Breed Counter it will also have a row and col for its location
 * @return none
 */
Doodlebug::Doodlebug(int r, int c, Grid * ptr):Organism(false) {
	row = r; //row
	col = c; //column
	g = ptr;

}
/** Doodlebug::move() this function used finds are random neighboring unoccupied cell
 * and moves the doodlebug form its current cell to the neighboring
 * @param none
 * @return bool returns true if the bug was able to move
 */
bool Doodlebug::move()
{
	bool status = true;

	struct Coordinates cell = Organism::getRandCell(row,col,g);
	int b[] = {cell.cellRow, cell.cellCol};

	if(b[0] == -1 || b[1] == -1){

	}
	else{

		g->setCellOrganism(b[0], b[1], g->getCellOrganism(row, col));
		g->setCellOccupant(b[0], b[1], doodlebug);

		g->setCellOrganism(row, col, nullptr);
		g->setCellOccupant(row, col, empty);

		setRowAndCol(b[0],b[1]);
	}


	return status;
}
/*The is a random error that occurs with the breed function so we made a
 * a second one below called breed doodle and it solves the error.
 * we couldn't find a better solution and we asked the professors but couldn't
 * figure it out
*/
bool Doodlebug::breed(){
	return true;
}
/** Doodlebug::breed(), finds a random unoccupied neighboring cell
 * and creates a new doodlebug inside it.
 * Breeding does NOT take precidence over death
 * @param none
 * @return bool returns true if the bug was able to breed
 */
bool Doodlebug::breedDoodle()
{
	bool status = true;

	// FIRST
	// Find Cell to Breed
	struct Coordinates cell = Organism::getRandCell(row,col,g);
	int b[] = {cell.cellRow, cell.cellCol};
	if(b[0] == -1 || b[1] == -1){
		status = false;
	}
	else{
		// SECOND
		// Create doodlebug from this breeding
		Doodlebug* d1 = new Doodlebug(b[0], b[1], g);
		// put it in the new cell
		g->setCellOccupant(b[0], b[1], doodlebug);
		g->setCellOrganism(b[0], b[1], d1);

		//Add a doodlebug to the total counter in the grid
		int totalDoodleBugs = g->getNumDoodle();
		totalDoodleBugs++;
		g->setNumDoodle(totalDoodleBugs);
		// THIRD
		// Reset the Counter of breed to 0
		setBreedCnt(0);
	}
	return status;
}

/** Doodlebug::eat() finds a neighboring cell that contains an ant and
 * resets the doodlebug's starve counter, also destructs the ant
 * Eating takes precedence over the majority of other actions
 * @param none
 * @return bool returns true if the bug was able to eat
 */
bool Doodlebug::eat()
{
	bool status = true;

	//Check surrounding cells for ants
	struct Coordinates cell = Doodlebug::getRandCell(row,col,g);
	int b[] = {cell.cellRow, cell.cellCol};
	// Neighboring cells did not contain an ant
	if(b[0] == -1 || b[1] == -1){

	}
	// Neighboring cells contain an ant
	else{
		// eat (destruct) the ant in the cell
		Ant* deadAnt = (Ant*) g->getCellOrganism(b[0], b[1]);
		deadAnt->~Ant();

		g->setNumAnt(g->getNumAnt() - 1);
		/* gets the doodlebug from the current cell and moves it to the
		 * cell that the ant it is eating is in
		 */
		g->setCellOrganism(b[0], b[1], g->getCellOrganism(row, col));
		g->setCellOccupant(b[0], b[1], doodlebug);

		g->setCellOrganism(row, col, nullptr);
		g->setCellOccupant(row, col, empty);



		setRowAndCol(b[0],b[1]);

		setStarveCnt(0);
	}
	return status;
}

/** Doodlebug::getStarveCnt() gets the starve count
 * @param none
 * @return the starve count
 */
int Doodlebug::getStarveCnt(){
	return starveCnt;
}

/** Doodlebug::setStarveCnt() sets the starve count
 * @param int s, the desired starve count
 * @return the starve count
 */
bool Doodlebug::setStarveCnt(int s){
	bool result = true;
	starveCnt = s;
	return result;
}
/** Doodlebug::step() tries to get the doodlebug to move or eat, then checks if
 * the doodlebug has starved to death, then attempts to breed
 * @param none
 * @return bool if the step worked
 */
bool Doodlebug::step(){
	bool ok1 = true;

	// FIRST
	// Move or Eat
	if(Doodlebug::numPossCells(row, col, g) > 0) {
		eat();

	}else if (Organism::numPossCells(row, col, g) > 0 ){
		move();
	}

	// SECOND
	// starve check
	if (starveCnt > 2){
		//DELETE DOODLE BUG
		g->setNumDoodle(g->getNumDoodle() - 1);
		Doodlebug* db = (Doodlebug*) g->getCellOrganism(row, col);
		db->~Doodlebug();


	}
	// THIRD
	// breed Check
	if (breedCnt > 7 && Organism::numPossCells(row, col, g) > 0){
		breedDoodle();
	}

	// FOURTH
	// modify values
	increm();


	return ok1;
}
/**Doodlebug::increm used to increment the starve and breed counters
 * @param none
 * @return bool result on if the function ran properly
 */
bool Doodlebug::increm(){
	bool result = true;

	//increments the counters
	starveCnt++;
	breedCnt++;

	return result;
}

/** Doodlebug::setBreedCnt Sets Breed Count
 * @param int i sets the count to i
 * @param bool result true if the function worked
 */
bool Doodlebug::setBreedCnt(int i){
	bool result = true;
	breedCnt = i;
	return result;
}

/** Doodlebug::GetNeighbors() checks how many cells next to a doodlebug contain ants
 * and then increments a value depending on how many neighbors are ants
 * @param int row, the row that this cell is on
 * @param int col, the column that this cell is on
 * @param Grid g is the grid of cells
 * @return numNeighbors is the number of neighbors with ants
 */
int Doodlebug::numPossCells(int row, int col, Grid* g) {
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
 * a pseudo-random cell that neighbors the input row column pair.
 * @param int row, the row that this cell is on
 * @param int col, the column that this cell is on
 * @param Grid g is the grid of cells
 * @return output, a struct Coordinates which represents the row and column of
 * the randomly chosen cell
 */
struct Doodlebug::Coordinates Doodlebug::getRandCell(int row, int col, Grid* g){

	struct Coordinates output;
	// Cell row and col

	// gets the number of cells in a grid
	int n = g->getNumCells();
	// sets this value equal to the number of rows and the number of columns
	int nRows = n;
	int nCols = n;
	int cell = 0;
	// Get a random number from 0-arr_size, or the maximum number of elements in that array
	int numNeighbors = Doodlebug::numPossCells(row, col, g);
	if (numNeighbors == 0){
		output.cellRow = row;
		output.cellCol = col;
	}
	else{
		int a = 1 + rand()%numNeighbors;


		if (row > 0) {
			if (g->getCellOccupant(row - 1, col) == ant)	//N
			{
				cell++;
				if(cell == a){
					output.cellRow = row-1;
					output.cellCol = col;
				}
			}
		}	//can look north
		if (col > 0) {
			if (g->getCellOccupant(row, col - 1) == ant)	//W
			{
				cell++;
				if(cell == a){
					output.cellRow = row;
					output.cellCol = col-1;
				}
			}
		}
		if (row < nRows - 1) {
			if (g->getCellOccupant(row + 1, col) == ant)	//S
			{
				cell++;
				if(cell == a){
					output.cellRow = row+1;
					output.cellCol = col;
				}
			}
		}	//can look south
		if (col < (nCols - 1)) {
			if (g->getCellOccupant(row, col + 1) == ant)	//E
			{
				cell++;
				if(cell == a){
					output.cellRow = row;
					output.cellCol = col+1;
				}
			}
		}
	}
	return output;

}

/** Doodlebug::setGridPtr Sets the grid pointer
 * @param Grid* a, the new grid
 * @return bool of if the function worked
 */
bool Doodlebug::setGridPtr(Grid * a){
	bool result = true;
	g = a;
	return result;
}
/** Doodlebug::setRowAndCol sets the row and column function
 * @param int i sets the row
 * @param int j sets the col
 * @param bool result true if the function worked
 */
bool Doodlebug::setRowAndCol(int i, int j){
	bool result = true;
	row = i;
	col = j;
	return result;
}

/** Doodlebug::~Doodlebug() Destructor, used to remove a pointer to a doodlebug
 *  @param none
 *  @return none
 */
Doodlebug::~Doodlebug() {

	g->setCellOccupant(row, col, empty);
	g->setCellOrganism(row, col, nullptr);
	setGridPtr(nullptr);
}

