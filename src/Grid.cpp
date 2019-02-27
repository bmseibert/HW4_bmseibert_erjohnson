/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Cell.h"

/** Grid::Grid() is the default constructor for the grid
 * @param none
 * @return none
 */
Grid::Grid() {

	Grid(10); //calls general constructor with default value
}

/** Grid::Grid(int nSquaresOnASide) is a constructor for the grid
 * @param int nSquaresOnASide is the number of squares for one side
 * @return none
 */
Grid::Grid(int nSquaresOnASide)
{
	nCells = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	myGridCells_ptr_array = new Cell* [nCells];  //first allocate array of row pointers

	for(int i=0 ; i < nCells ; i++)
	{
		myGridCells_ptr_array[i] = new Cell[nCells]; // allocate memory for columns in each row
	}
}
/** Grid::setCellOccupant() is a Function that sets the occupation status for a cell
 * @param int r is the row of the grid
 * @param int c is the column of the grid
 * @param occupationStatus g is the occupation status that you are trying to pass on a given cell
 * @return bool returns the status of if this function worked
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g)
{
	return myGridCells_ptr_array[r][c].setOccupant(g);
}
/** Grid::getCellOccupant() is a Function that gets the occupation status for a cell
 * @param int r is the row of the grid
 * @param int c is the column of the grid
 * @return occupation status of a given cell
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
}

/** Grid::setCellOrganism() is a Function that sets organism of a cell
 * @param int r is the row of the grid
 * @param int c is the column of the grid
 * @param Organism * g is the pointer to an organism
 * @return bool returns the status of if this function worked
 */
bool Grid::setCellOrganism(int r, int c, Organism* o)
{
	return myGridCells_ptr_array[r][c].setOrganism(o);
}
/** Grid::getCellOrganism() is a Function that gets the Organism* for a cell
 * @param int r is the row of the grid
 * @param int c is the column of the grid
 * @return organism* of a given cell
 */
Organism* Grid::getCellOrganism(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOrganism();
}

/** Grid::getNumCells() is a Function that gets the number
 * of cells in the grid
 * @return the number of cells in the grid
 */
int Grid::getNumCells()
{
	return nCells;
}


/** Grid::getNumDoodle() Function gets the number of doodlebugs
 * @return is the number of doodlebugs on the grid
 */
int Grid::getNumDoodle()
{
	return numDoodle;
}

/** Grid::getNumAnt() Function sets the number of Ants
 * @return a bool on if this function ran or not
 */
bool Grid::setNumAnt(int num)
{
	bool result = true;
	numAnt = num;
	return result;
}

/** Grid::getNumAnt() Function gets the number of ants
 * @return is the number of ants on the grid
 */
int Grid::getNumAnt()
{
	return numAnt;
}

/* Grid::getNumDoodle() Function sets the number of doodlebugs
 * @return a bool on if this function ran or not
 */
bool Grid::setNumDoodle(int num)
{
	bool result = true;
	numDoodle = num;
	return result;
}

/** Grid::printGrid() will print the grid to the console
 * @param none
 * @return bool if it worked
 */
bool Grid::printGrid() {
	bool result = true;
	for(int r=0; r < nCells; r++)
	{
		for(int c=0; c < nCells; c++)
		{
			if(myGridCells_ptr_array[r][c].getOccupant() == empty){
				printf("-");
			}
			if(myGridCells_ptr_array[r][c].getOccupant() == ant){
				printf("o");
			}
			if(myGridCells_ptr_array[r][c].getOccupant() == doodlebug){
				printf("x");
			}
		}
		printf("\n");
	}
	printf("\n");
	return result;

}
/** Grid::getGrid gets the pointer to the first cell in the
 * gird, which is the pointer to the grid
 * @param none
 * @return returns a pointer to the grid
 */
Cell** Grid::getGrid(){

	return myGridCells_ptr_array;
}

/** Grid::setSeed sets the seed of the program
 * @param none
 * @return bool if the function worked
 */
bool Grid::setSeed(int s){
	bool result = true;
	seed = s;
	return result;
}
/** Grid::setPause set the status pause functionality of the grid
 * @param none
 * @return bool if the function worked
 */
bool Grid::setPause(char c){
	bool result = true;
	pause = c;
	return result;
}
/** Grid::getPause get the status pause functionality of the grid
 * @param none
 * @return bool if the function worked
 */
char Grid::getPause(){
	return pause;
}
/** Grid::setRand() sets the randomVal field of the grid
 * @param none
 * @return bool if the function worked
 */
bool Grid::setRand(){
	bool result = false;
	randomVal = rand();
	return result;
}
/** Grid::getRand get the randomVal field of the grid
 * @param none
 * @return bool if the function worked
 */
int Grid::getRand(){
	return randomVal;
}

/** Grid::~Grid() is the default destructor for a grid
 * @param none
 * @return none
 */
Grid::~Grid() {

	for(int r=0; r < nCells; r++)
	{
		for(int c=0; c < nCells; c++)
		{
			//cout << "Before freeing" << r << c << endl;
			myGridCells_ptr_array[r][c].~Cell(); // free memory for columns in each row
		}
	}
	//myGridCells_ptr_array = (Cell**)nullptr;
}

