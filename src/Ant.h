/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Grid.h"

class Ant: public Organism {
private:
	int row = 0;
	int col = 0;
	int breedCnt = 0; // breed counter happens once every three time steps
	Grid* g = nullptr;

public:

	Ant();
	Ant(int r, int c, Grid* ptr);
	bool move();
	bool breed();
	bool step();
	bool increm();
	bool setBreedCnt(int i);
	bool setRowAndCol(int i, int j);
	struct Organism::Coordinates getRandCell(int row, int col, Grid* g);
	~Ant();

};

#endif /* ANT_H_ */
