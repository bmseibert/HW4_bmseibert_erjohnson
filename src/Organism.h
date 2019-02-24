/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include "Grid.h"

class Organism {
private:
	bool amAnt = false;

public:
	struct Coordinates{
		int cellRow;
		int cellCol;
	};
	Organism();
	Organism(bool b);
	bool isPrey();
	virtual bool move() = 0;
	virtual bool breed() = 0;
	virtual bool step() = 0;
	void setAmAnt(bool b);
	virtual ~Organism();
	virtual int numPossCells(int row, int col, Grid* g);
	virtual struct Coordinates getRandCell(int row, int col, Grid* g);
};

#endif /* ORGANISM_H_ */
