/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include "Grid.h"
#include "Ant.h"


class Doodlebug: public Organism {
private:
	int row = 0;
	int col = 0;
	int starveCnt = 0; //starving counter
	int breedCnt = 0; //breeding counter
	Grid* g = nullptr;

public:

	Doodlebug();
	Doodlebug(int r, int c, Grid * ptr);
	bool move();
	bool breed();
	bool breedDoodle();
	bool eat();
	int getStarveCnt();
	bool setStarveCnt(int s);
	~Doodlebug();
	bool step();
	bool increm();
	bool setBreedCnt(int i);
	int numPossCells(int row, int col, Grid* g);
	bool setGridPtr(Grid * a);
	bool setRowAndCol(int i, int j);
	struct Organism::Coordinates getRandCell(int row, int col, Grid* g);

};

#endif /* DOODLEBUG_H_ */
