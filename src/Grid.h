/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_

#include "Cell.h"

class Grid {
private:
	int n = 0;
	int numDoodle = 0;
	int numAnt = 0;
	Cell** myGridCells_ptr_array = (Cell**)nullptr;
	int seed = 0;

public:
	Grid();
	Grid(int nSquaresOnASide);
	bool setCellOccupant(int r, int c, occupationStatus g);
	int getNumDoodle();
	bool setNumDoodle(int num);
	bool setNumAnt(int num);
	int getNumAnt();
	occupationStatus getCellOccupant(int r, int c);
	bool printGrid();
	bool setSeed(int s);
	virtual ~Grid();
	int getNumCells();
	Cell** getGrid();
	Cell getCell(int r, int c);
};

#endif /* GRID_H_ */
