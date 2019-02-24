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

	int numDoodle = 0;
	int numAnt = 0;
	Cell** myGridCells_ptr_array = (Cell**)nullptr;
	int seed = 0;
	int nCells = 0;
	char pause = 'n';

public:

	int randomVal = 0;
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
	bool setRand();
	bool setPause(char c);
	char getPause();
	Cell** getGrid();
	Cell getCell(int r, int c);
	bool setCellOrganism(int r, int c, Organism* o);
	Organism* getCellOrganism(int r, int c);
};

#endif /* GRID_H_ */
