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

Cell** myGridCells_ptr_array = (Cell**)nullptr; // This is the pointer to the array of pointers that is the gird

/* Grid::Grid() is the constructor for the grid
 *
 */
Grid::Grid() {

	Grid(10); //calls general constructor with default value
}

/* Grid::Grid(int nSquaresOnASide) is the constructor for the grid
 * @param int nSquaresOnASide is the number of squares for one side
 */
Grid::Grid(int nSquaresOnASide)
{
	n = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	myGridCells_ptr_array = new Cell* [n];  //first allocate array of row pointers

	for(int i=0 ; i < n ; i++)
	{
		myGridCells_ptr_array[i] = new Cell[n]; // allocate memory for columns in each row
	}
}
/* Grid::setCellOccupant() is a Function that sets the occupation status for a cell
 * @param int r is the row of the grid
 * @param int c is the column of the grid
 * @param occupationStatus g is the occupation status that you are trying to pass on a given cell
 * @return bool returns the status of if this function worked
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g)
{
	return myGridCells_ptr_array[r][c].setOccupant(g);
}
/* Grid::getCellOccupant() is a Function that gets the occupation status for a cell
 * @param int r is the row of the grid
 * @param int c is the column of the grid
 * @return occupation status of a given cell
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
}

/* Grid::getNumCells() is a Function that gets the occupation status for a cell
 * @return the number of cells in the grid
 */
int Grid::getNumCells()
{
	return n;
}
/* getCellPointer Function gets the cell
 * @param int r is the row of the cell
 * @param int c is the column of the cell
 * @return is a pointer to the cell that we are looking for
 */
Cell Grid::getCell(int r, int c)
{
	return myGridCells_ptr_array[r][c];
}

/* Grid::~Grid() is the default destructor for a grid
 *
 */
Grid::~Grid() {

	for(int r=0; r < n; r++)
	{
		for(int c=0; c < n; c++)
		{
			//cout << "Before freeing" << r << c << endl;
			myGridCells_ptr_array[r][c].~Cell(); // free memory for columns in each row
		}
	}
	//myGridCells_ptr_array = (Cell**)nullptr;
}

