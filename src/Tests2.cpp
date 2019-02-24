/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 *
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "Cell.h"
#include <iostream>
#include <stdio.h>

/* Test Constructor Sub
 * Generates a new test object
 */
Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}
/* do Test Function
 * Runs all of the tests
 * @return bool on if all of the tests passed or not
 *
 */
bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	//populate it with ants
	bool ok2 = makeAntsTest();
	//see whether they move
	bool ok3 = antsMoveTest();
	//see whether they breed
	bool ok4 = antsBreedTest();
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	//see whether they move
	bool ok7 = doodleMoveTest();
	//see whether they breed
	bool ok8 = doodleBreedTest();
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	//see whether they die
	bool ok10 = doodleDietest();
	//see whether the neighbor function works
	bool ok11 = organismNeighborTest();
	//see whether the random cell test works
	bool ok12 = organismRandCellTest();

	// if all tests pass return true
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12;
	return results;
}

/** Test the Grid class by constructing a grid object and calling the
 * getCellOccupant() method on a random cell, then using the setCellOccupant
 * to ant, and checking if the getCellOccupant returns ant, then
 * destructs the grid
 *  @return true if the initialized grid does not have a occupant in a
 *  random cell and if once you use the setter method, the occupant
 *  status changes to the set enumeration (empty, ant or doodlebug)
 */
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the grid test" << std::endl;
	Grid myGrid = Grid(8);
	if(myGrid.getCellOccupant(2, 3)!=empty)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	std::cout << "second grid test" << std::endl;
	myGrid.setCellOccupant(2, 3, ant);
	if(myGrid.getCellOccupant(2, 3)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	std::cout << "third grid test" << std::endl;
	myGrid.~Grid();
	result = ok1 && ok2;
	return result;
}
/** Test the Ant class by constructing a grid object and setting a cell
 *  occupant to ant, then it creates an ant object
 *  @return true if the initialized grid does not have a occupant in a
 *  random cell and if once you use the setter method, the occupant
 *  status changes to the set enumeration (empty, ant or doodlebug)
 */
bool Tests2::makeAntsTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant(3,4,myGrid_p);
	if(myGrid_p->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, doodlebug);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty);
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}

bool Tests2::OrganismTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	bool ok3 = true;
	std::cout << "Running the Organism Methods test" << std::endl;

	Grid* myGrid_t = new Grid(9);
	if(myGrid_t->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	Ant* a3 = new Ant(3,4, myGrid_t);
	myGrid_t->setCellOccupant(3, 4, ant);
	Ant* a4 = new Ant(3,5,myGrid_t);
	myGrid_t->setCellOccupant(3, 5, ant);
	Ant* a5 = new Ant(8,6,myGrid_t);
	myGrid_t->setCellOccupant(8, 6, ant);


	int numNeighbors1 = a3->numPossCells(3, 4, myGrid_t);
	printf("numNeighbors1: %d \n", numNeighbors1);
	if(numNeighbors1 != 3){
		ok1 = false;
		printf("did not find neighbor\n");
	}

	int n = myGrid_t->getNumCells();
	printf("nRows %d \n", n);
	int numNeighbors2 = a5->numPossCells(8, 6, myGrid_t);
	printf("numNeighbors2: %d \n", numNeighbors2);
	if(numNeighbors2 != 3){
		ok2 = false;
		printf("found a non-existent neighbor neighbor\n");
	}
	//	int arr[] = {*(a3->getRandCell(3, 4, myGrid_t))};
	//	printf("arr: %d ", arr[0]);
	//	printf(" %d \n", arr[1]);
	//	if((arr[0] == 4 && arr[1] == 4) || (arr[0] == 3 && arr[1] == 2) ||
	//	   (arr[0] == 2 && arr[1] == 4)){
	//		ok3 = false;
	//		printf("GetRandCell returned a cell that was not empty");
	//	}


	result = ok1 && ok2 && ok3;
	return result;
}
/*
 * Ants Move test
 * Tests if the ants move function operates correctly
 *
 * NEED TO TEST: **-still need to complete
 * Cases of boundaries **
 * Cases of ants being surrounded with other ants and doodlebugs **
 * Case of no boundary
 *
 * @return bool if test ran
 */
bool Tests2::antsMoveTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	bool ok3 = true;
	std::cout << "Running the move ants test" << std::endl;

	Grid* myGrid_l = new Grid(9);

	//Testing an ant moving with no restrictions
	// Make ant
	Ant* a3 = new Ant(3,4,myGrid_l);
	// Set the Cell occupant and organism
	myGrid_l->setCellOccupant(3, 4, ant);
	myGrid_l->getCell(3, 4).setOrganism(a3);

	myGrid_l->printGrid();
	printf("\n");
	// Have the ant move
	a3->move();  //THIS HAS SO MANY BUGS

	//myGrid_l->printGrid();
	//check if the ant moved
	if (myGrid_l->getCell(3, 4).getOccupant() == ant){
		printf("There is still an ant at this location \n");
		ok1 = false;
	}
	//this does not seem to be working
	if (myGrid_l->getCell(3, 4).getOrganism() == nullptr){

	}
	else{
		printf("there is still an ant pointer here");
		ok2 = false;
	}

	//Check the nearby cells
	if (myGrid_l->getCell(2, 4).getOccupant() == ant || myGrid_l->getCell(4, 4).getOccupant() == ant
			|| myGrid_l->getCell(3, 3).getOccupant() == ant || myGrid_l->getCell(3, 5).getOccupant() == ant){

	} else
	{
		printf("Ant moved to a random location or did not move at all \n");
		ok3 = false;
	}
	delete a3;
	delete myGrid_l;

	result = ok1 && ok2 && ok3;
	return result;
}
/* Ant Breed Test
 * Tests if the Breed test for ants works
 *
 * NEED TO TEST: **-still need to complete
 * Boundary Breeding
 * Normal Breeding
 *
 *
 * @return bool if the test worked
 */
bool Tests2::antsBreedTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the breed ants test" << std::endl;

	//makes a grid pointer
	Grid* myGrid_p = new Grid(9);

	// checking the normal case
	// Make ant
	Ant* a3 = new Ant(3,4,myGrid_p);
	// Add the Ant to the grid
	myGrid_p->setCellOccupant(3, 4, ant);
	myGrid_p->getCell(3, 4).setOrganism(a3);
	// Make the ant breed
	//a3.breed()
	// check if there is an ant and an ant in any surrounding cells
	if(myGrid_p->getCell(2, 4).getOccupant() == ant || myGrid_p->getCell(4, 4).getOccupant() == ant
			|| myGrid_p->getCell(3, 3).getOccupant() == ant || myGrid_p->getCell(3, 5).getOccupant() == ant){

	}else{
		printf("Ant Moved to a random location or did not move at all \n");
		ok1 = false;
	}

	// checking the boundary case
	// Make ant
	Ant* a1 = new Ant(1,1,myGrid_p);
	// Add the Ant to the grid
	myGrid_p->setCellOccupant(3, 4, ant);
	myGrid_p->getCell(3, 4).setOrganism(a1);
	// Make the ant breed
	// a1->breed();
	// check if there is an ant
	// check if there is an ant and an ant in any surrounding cells
	if(myGrid_p->getCell(1, 2).getOccupant() == ant || myGrid_p->getCell(2, 1).getOccupant() == ant){

	}else{
		printf("Ant Moved to a random location or did not move at all \n");
		ok2 = false;
	}

	result = ok1 && ok2;
	return result;
}

/* Ants Die Test
 * Checks if the Ant Delete test works
 * NEED TO CHECK:
 * normal death condition
 *
 * @return bool of if the test worked or not
 */
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	//makes a grid pointer
	Grid* myGrid_p = new Grid(9);
	// checking the normal case
	// Make ant
	Ant* a3 = new Ant(3,4,myGrid_p);
	// Add the Ant to the grid
	myGrid_p->setCellOccupant(3, 4, ant);
	myGrid_p->getCell(3, 4).setOrganism(a3);
	// kill the ant
	// a3~Ant();

	//check if the ant is still there or alive
	// NEED TO DO

	return result;
}
/* Make Doodles Test
 * Checks if the Make Doodles Test worked
 *
 * @return bool of if the test worked
 */
bool Tests2::makeDoodlesTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make doodlebugs test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, doodlebug);
	if(myGrid_p->getCellOccupant(1, 2)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok1 = false;
	}
	Doodlebug* d1 = new Doodlebug(3,4,myGrid_p);
	if(myGrid_p->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, doodlebug);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty);
	//delete d1; // NEED TO FIX THIS
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}

/* Doodle Move Test
 * Checks if the Doodle move function works
 * NEED TO TEST: **-still need to complete
 * Boundary Moving
 * Normal Moving
 * Check if it moves on an ant before it moves to an open cell
 *
 * @return bool if the test worked
 *
 */
bool Tests2::doodleMoveTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	bool ok3 = true;
	std::cout << "Running the move doodlebug move test" << std::endl;

	// Create the Grid
	Grid* myGrid_l = new Grid(9);

	// Testing a doodlebug moving with no restrictions
	// Make doodlebug
	Doodlebug* d3 = new Doodlebug(3,4,myGrid_l);
	// Set the Cell occupant and organism
	myGrid_l->setCellOccupant(3, 4, ant);
	myGrid_l->getCell(3, 4).setOrganism(d3);
	// Have the doodlebug move
	d3->move();  //THIS HAS SO MANY BUGS
	// check if the doodlebug moved
	if (myGrid_l->getCell(3, 4).getOccupant() == doodlebug){
		printf("There is still an ant at this location \n");
		ok1 = false;
	}
	//this does not seem to be working
	if (myGrid_l->getCell(3, 4).getOrganism() == nullptr){

	}
	else{
		printf("there is still an doodlebug pointer here");
		ok2 = false;
	}

	//Check the nearby cells
	if (myGrid_l->getCell(2, 4).getOccupant() == doodlebug || myGrid_l->getCell(4, 4).getOccupant() == doodlebug
			|| myGrid_l->getCell(3, 3).getOccupant() == doodlebug || myGrid_l->getCell(3, 5).getOccupant() == doodlebug){

	} else
	{
		printf("Ant Moved to a random location or did not move at all \n");
		ok3 = false;
	}
	//delete d3;
	delete myGrid_l;

	result = ok1 && ok2 && ok3;
	return result;
}
/* Doodle Breed Test
 * Checks if the breed function for doodlebug works
 * NEED TO TEST:
 * Normal Condition
 * Boundary Conditions
 *
 * @return bool if this function worked properly
 *
 */
bool Tests2::doodleBreedTest()
{
	bool result = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;

	return result;
}
/* Doodle Eat Test
 * Checks if the eat function worked
 * NEED TO TEST:
 * normal conditions
 *
 * @return bool of if the function worked
 *
 */
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	return result;
}
/* Doodle Die Test
 * Checks if the doodlebug is erased correctly
 * NEED TO TEST:
 * Normal Conditions
 *
 * @return bool on if the function worked correctly
 *
 */
bool Tests2::doodleDietest()
{
	bool result = true;
	std::cout << "Running the doodlebug dies test" << std::endl;
	return result;
}
/* How many neighbors test function
 * Tests if the function works properly
 *
 * NEED TO TEST:
 * 0, 1, 2, 3, 4 neighbors
 *
 * @return bool of if the test passed
 */

bool Tests2::organismNeighborTest(){
	bool result = true;
	std::cout << "Running the Neighbor Test" << std::endl;


	return result;
}
/* Rand Cell Test
 * Tests if the function of rand cell test works
 *
 * NEED TO TEST:
 * if a cell is picked and is one of the surrounding cells of the picked cell
 *
 * @return bool of if the test passed
 */
bool Tests2::organismRandCellTest(){
	bool result = true;
	std::cout << "Running the Rand Cell test" << std::endl;


	return result;
}

/* Test Destructor Sub
 * Deletes the Testing file
 */
Tests2::~Tests2() {
	delete this;
}

