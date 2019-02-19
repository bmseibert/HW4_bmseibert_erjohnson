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
	Organism();
	Organism(bool b);
	bool isPrey();
	virtual bool move();
	virtual bool breed(Grid* g);
	void setAmAnt(bool b);
	virtual ~Organism();
	virtual bool step(Grid* g);
	int howManyNeighbors(int row, int col, Grid* g);
	Cell getRandCell(int row, int col, Grid* g);
};

#endif /* ORGANISM_H_ */
