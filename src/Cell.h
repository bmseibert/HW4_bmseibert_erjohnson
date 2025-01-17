/*
 * Cell.h
 *
 *  Created on: Feb 9, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#ifndef CELL_H_
#define CELL_H_

enum occupationStatus {empty, ant, doodlebug};

class Organism;

class Cell {
private:
	occupationStatus guest = empty;
	Organism* p = nullptr;
public:

	Cell();
	bool setOccupant(occupationStatus g);
	occupationStatus getOccupant();
	bool setOrganism(Organism * o);
	Organism* getOrganism();
	virtual ~Cell();

};

#endif /* CELL_H_ */
