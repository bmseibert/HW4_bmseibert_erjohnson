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
	a1->~Ant();
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}
/* Organism Test
 * @return bool if the tests works
 */
bool Tests2::OrganismTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	bool ok3 = true;
	std::cout << "Running the Organism Methods test" << std::endl;

	// Make the Grid
	Grid* myGrid_t = new Grid(9);
	// Checks that the grid has none of the cells initialized
	if(myGrid_t->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	// Make all of the ants
	Ant* a3 = new Ant(3,4, myGrid_t);
	myGrid_t->setCellOccupant(3, 4, ant);
	Ant* a4 = new Ant(3,5,myGrid_t);
	myGrid_t->setCellOccupant(3, 5, ant);
	Ant* a5 = new Ant(8,6,myGrid_t);
	myGrid_t->setCellOccupant(8, 6, ant);

	// checks that the number of cells empty is correct
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

	a3->~Ant();
	a4->~Ant();
	a5->~Ant();
	myGrid_t->~Grid();
	result = ok1 && ok2 && ok3;
	return result;
}
/*
 * Ants Move test
 * Tests if the ants move function operates correctly
 *
 * NEED TO TEST:
 * Cases of boundaries
 * Cases of ants being surrounded with other ants and doodlebugs
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
	bool ok4 = true;
	bool ok5 = true;
	bool ok6 = true;
	std::cout << "Running the move ants test" << std::endl;

	// Make the Grid
	Grid* myGrid_l = new Grid(9);

	// Testing an ant moving with no restrictions
	// Make ant
	Ant* a3 = new Ant(3, 4, myGrid_l);
	// Set the Cell occupant and organism
	myGrid_l->setCellOccupant(3, 4, ant);
	myGrid_l->setCellOrganism(3, 4, a3);

	// Make the ant move
	a3->move();

	// Check if the ant moved
	if (myGrid_l->getCellOccupant(3, 4) == ant){
		printf("There is still an ant at this location \n");
		ok1 = false;
	}
	// Check to make sure that the ant pointer moved
	if (myGrid_l->getCellOrganism(3, 4) == nullptr){

	}
	else{
		printf("there is still an ant pointer here");
		ok2 = false;
	}

	// Check the nearby cells
	if (myGrid_l->getCellOccupant(2, 4) == ant || myGrid_l->getCellOccupant(4, 4) == ant
			|| myGrid_l->getCellOccupant(3, 3) == ant || myGrid_l->getCellOccupant(3, 5) == ant){

	} else
	{
		printf("Ant moved to a random location or did not move at all \n");
		ok3 = false;
	}

	// Tests the boundaries
	// make the ant
	Ant* a2 = new Ant(0,0,myGrid_l);

	// Sets the occupant
	myGrid_l->setCellOccupant(0, 0, ant);
	myGrid_l->setCellOrganism(0, 0, a2);

	//myGrid_l->printGrid();
	// Make the ant move
	a2->move();

	// Check if the ant moved
	if (myGrid_l->getCellOccupant(0, 0) == ant){
		printf("There is still an ant at this location \n");
		ok4 = false;
	}
	// Check to make sure that the ant pointer moved
	if (myGrid_l->getCellOrganism(0, 0) == nullptr){

	}
	else{
		printf("there is still an ant pointer here");
		ok5 = false;
	}
	// Check the nearby cells
	if (myGrid_l->getCellOccupant(0, 1) == ant || myGrid_l->getCellOccupant(1, 0) == ant){

	} else
	{
		printf("Ant moved to a random location or did not move at all 2 \n");
		myGrid_l->printGrid();
		ok6 = false;
	}

	// Surrounded by Doodlebug and another ant
	Ant *a4 = new Ant(6,6,myGrid_l);

	// Sets the occupant
	myGrid_l->setCellOccupant(6, 6, ant);
	myGrid_l->setCellOrganism(6, 6, a4);

	// Doodlebug initialization
	Doodlebug* d1 = new Doodlebug(6,7,myGrid_l);
	myGrid_l->setCellOccupant(6, 7, doodlebug);
	myGrid_l->setCellOrganism(6, 7, d1);

	// One more ant
	Ant* a5 = new Ant(5,6,myGrid_l);
	myGrid_l->setCellOccupant(5, 6, ant);
	myGrid_l->setCellOrganism(5, 6, a5);

	// Move the ant
	a4->move();

	// Check if the ant moved
	if (myGrid_l->getCellOccupant(6, 6) == ant){
		printf("There is still an ant at this location \n");
		ok4 = false;
	}
	// Check to make sure that the ant pointer moved
	if (myGrid_l->getCellOrganism(6, 6) == nullptr){

	}
	else{
		printf("there is still an ant pointer here");
		ok5 = false;
	}
	// Check the nearby cells
	if (myGrid_l->getCellOccupant(7, 6) == ant || myGrid_l->getCellOccupant(6, 5) == ant){

	} else
	{
		printf("Ant moved to a random location or did not move at all 2 \n");
		myGrid_l->printGrid();
		ok6 = false;
	}

	// delete all of the objects used
	a3->~Ant();
	a4->~Ant();
	a5->~Ant();
	a2->~Ant();
	d1->~Doodlebug();
	myGrid_l->~Grid();

	result = ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
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
	bool ok3 = true;
	std::cout << "Running the breed ants test" << std::endl;

	//makes a grid pointer
	Grid* myGrid_p = new Grid(9);

	// checking the normal case
	// Make ant
	Ant* a3 = new Ant(3,4,myGrid_p);
	// Add the Ant to the grid
	myGrid_p->setCellOccupant(3, 4, ant);
	myGrid_p->setCellOrganism(3, 4, a3);
	// Make the ant breed
	a3->breed();
	// check if there is an ant and an ant in any surrounding cells
	if(myGrid_p->getCellOccupant(2, 4) == ant || myGrid_p->getCellOccupant(4, 4) == ant
			|| myGrid_p->getCellOccupant(3, 3) == ant || myGrid_p->getCellOccupant(3, 5) == ant){

	}else{
		printf("Ant did not breed \n");
		ok1 = false;
	}

	// checking the boundary case
	// Make ant
	Ant* a1 = new Ant(0,0,myGrid_p);
	// Add the Ant to the grid
	myGrid_p->setCellOccupant(0, 0, ant);
	myGrid_p->setCellOrganism(0, 0, a1);
	// Make the ant breed
	a1->breed();
	// check if there is an ant
	// check if there is an ant and an ant in any surrounding cells
	if(myGrid_p->getCellOccupant(0, 1) == ant || myGrid_p->getCellOccupant(1, 0) == ant){

	}else{
		printf("Ant did not breed \n");
		ok2 = false;
	}

	// checking when there is no place for the and to breed
	// Make ant
	Ant* a4 = new Ant(8,8,myGrid_p);
	Ant* a5= new Ant(7,8,myGrid_p);
	Ant* a6 = new Ant(8,7,myGrid_p);
	// Add the Ant to the grid
	myGrid_p->setCellOccupant(8, 8, ant);
	myGrid_p->setCellOrganism(8, 8, a4);
	myGrid_p->setCellOccupant(7, 8, ant);
	myGrid_p->setCellOrganism(7, 8, a5);
	myGrid_p->setCellOccupant(8, 7, ant);
	myGrid_p->setCellOrganism(8, 7, a6);
	// Make the ant breed
	int antsBeforeBreed = myGrid_p->getNumAnt();
	a4->breed();
	// check that no new ants were created
	if(myGrid_p->getNumAnt() == antsBeforeBreed){

	}else{
		printf("Ant breed when there was no space \n");
		ok3 = false;
	}
	a1->~Ant();
	a3->~Ant();
	a4->~Ant();
	a5->~Ant();
	a6->~Ant();
	myGrid_p->~Grid();
	result = ok1 && ok2 && ok3;
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
	bool ok1 = true;
	std::cout << "Running the ants die test" << std::endl;
	//makes a grid pointer
	Grid* myGrid_p = new Grid(9);
	// checking the normal case
	// Make ant
	Ant* a3 = new Ant(3,4,myGrid_p);
	// Add the Ant to the grid
	myGrid_p->setCellOccupant(3, 4, ant);
	myGrid_p->setCellOrganism(3, 4, a3);
	// kill the ant
	a3->~Ant();
	//check if the ant is still there or alive
	if (myGrid_p->getCellOrganism(3, 4) == nullptr){

	}
	else{
		printf("there is still an ant pointer here");
		ok1 = false;
	}

	myGrid_p->~Grid();
	result = ok1;
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

	d1->~Doodlebug();
	myGrid_p->~Grid();
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
	Doodlebug* d3 = new Doodlebug(3, 4, myGrid_l);
	// Set the Cell occupant and organism
	myGrid_l->setCellOccupant(3, 4, doodlebug);
	myGrid_l->setCellOrganism(3, 4, d3);

	//myGrid_l->printGrid();
	// Have the doodlebug move
	d3->move();
	//myGrid_l->printGrid();
	// check if the doodlebug moved
	if (myGrid_l->getCellOccupant(3, 4) == doodlebug){
		printf("There is still an ant at this location \n");
		ok1 = false;
	}
	//this does not seem to be working
	if (myGrid_l->getCellOrganism(3, 4) == nullptr){

	}
	else{
		printf("there is still an doodlebug pointer here");
		ok2 = false;
	}

	//Check the nearby cells
	if (myGrid_l->getCellOccupant(2, 4) == doodlebug || myGrid_l->getCellOccupant(4, 4) == doodlebug
			|| myGrid_l->getCellOccupant(3, 3) == doodlebug || myGrid_l->getCellOccupant(3, 5) == doodlebug){

	} else
	{
		myGrid_l->printGrid();
		printf("Doodlebug Moved to a random location or did not move at all \n");
		ok3 = false;
	}
	//delete d3;
	d3->~Doodlebug();
	myGrid_l->~Grid();

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
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;

	// Create the Grid
	Grid* myGrid_l = new Grid(9);

	// Testing a doodlebug moving with no restrictions
	// Make doodlebug
	Doodlebug* d3 = new Doodlebug(3, 4, myGrid_l);

	// Set the Cell occupant and organism
	myGrid_l->setCellOccupant(3, 4, doodlebug);
	myGrid_l->setCellOrganism(3, 4, d3);

	// Make the doodlebug breed
	d3->breedDoodle();
	// check if there is an ant and an ant in any surrounding cells
	if(myGrid_l->getCellOccupant(2, 4) == doodlebug || myGrid_l->getCellOccupant(4, 4) == doodlebug
			|| myGrid_l->getCellOccupant(3, 3) == doodlebug || myGrid_l->getCellOccupant(3, 5) == doodlebug){
	}else{
		printf("Ant did not breed \n");
		ok1 = false;
	}
	// check to make sure the doodlebug is still there
	if(myGrid_l->getCellOccupant(3, 4) == doodlebug){

	}else{
		printf("Doodlebug moved \n");
		ok2 = false;
	}

	d3->~Doodlebug();
	myGrid_l->~Grid();
	result = ok1 && ok2;
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
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the eat ant test" << std::endl;
	// Generate the Grid
	Grid * myGrid = new Grid(9);
	// Add an Ant and a Doodlebug to the Grid
	// Make doodlebug
	Doodlebug* d = new Doodlebug(3, 4, myGrid);

	// Set the Cell occupant and organism
	myGrid->setCellOccupant(3, 4, doodlebug);
	myGrid->setCellOrganism(3, 4, d);
	// Make an Ant
	Ant * a = new Ant(4,4, myGrid);
	// Set the occupancy on the grid
	myGrid->setCellOccupant(4, 4, ant);
	myGrid->setCellOrganism(4, 4, a);

	// Make the Doodlebug eat
	d->eat(); // There are bugs with this function

	// Test if it worked
	if(myGrid->getCellOccupant(4, 4) == doodlebug && myGrid->getCellOccupant(3, 4) == empty){

	}else{
		printf("One of the tests failed for eat /n");
		ok1 = false;
	}
/*
	Ant * a1 = new Ant(5,4, myGrid);
	// Set the occupancy on the grid
	myGrid->setCellOccupant(5, 4, ant);
	myGrid->setCellOrganism(5, 4, a1);

	Ant * a2 = new Ant(4,3, myGrid);
	// Set the occupancy on the grid
	myGrid->setCellOccupant(4, 3, ant);
	myGrid->setCellOrganism(4, 3, a2);

	d->eat();

	if((myGrid->getCellOccupant(5, 4) == doodlebug || myGrid->getCellOccupant(4, 3) == doodlebug)
	   && myGrid->getCellOccupant(4, 4) == empty){

	}else{

		printf("One of the tests failed for eat \n");
		ok2 = false;
	}
*/
	d->~Doodlebug();
	//the ant was already destructed, that was the error
	myGrid->~Grid();
	result = ok1 && ok2;
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
	bool ok1 = true;
	std::cout << "Running the Doodlebug die test" << std::endl;
	//makes a grid pointer
	Grid* myGrid_p = new Grid(9);
	// checking the normal case
	// Make doodlebug
	Doodlebug* d3 = new Doodlebug(3,4,myGrid_p);
	// Add the Doodlebug to the grid
	myGrid_p->setCellOccupant(3, 4, doodlebug);
	myGrid_p->setCellOrganism(3, 4, d3);
	// kill the doodlebug
	d3->~Doodlebug();
	//check if the doodlebug is still there or alive
	if (myGrid_p->getCellOrganism(3, 4) == nullptr){

	}
	else{
		printf("there is still an doodlebug pointer here");
		ok1 = false;
	}

	myGrid_p->~Grid();
	result = ok1;
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
	bool ok = true;
	bool ok1 = true;
	bool ok2 = true;
	bool ok3 = true;
	bool ok4 = true;

	Grid* myGrid_n = new Grid(9);

	//Ant on an empty field
	Ant* a1 = new Ant(3,4,myGrid_n);
	myGrid_n->setCellOccupant(3, 4, ant);
	myGrid_n->setCellOrganism(3, 4, a1);

	int neighbors1 = a1->numPossCells(3, 4, myGrid_n);
	//Second ant on field
	Ant* a2 = new Ant(4,4,myGrid_n);
	myGrid_n->setCellOccupant(4, 4, ant);
	myGrid_n->setCellOrganism(4, 4, a2);

	int neighbors2 = a1->numPossCells(3, 4, myGrid_n);

	//third ant on field
	Ant* a3 = new Ant(3,3,myGrid_n);
	myGrid_n->setCellOccupant(3, 3, ant);
	myGrid_n->setCellOrganism(3, 3, a3);

	int neighbors3 = a1->numPossCells(3, 4, myGrid_n);

	//fourth ant on field
	Ant* a4 = new Ant(2,4,myGrid_n);
	myGrid_n->setCellOccupant(2, 4, ant);
	myGrid_n->setCellOrganism(2, 4, a4);

	int neighbors4 = a1->numPossCells(3, 4, myGrid_n);

	//fifth ant on field
	Ant* a5 = new Ant(3,5,myGrid_n);
	myGrid_n->setCellOccupant(3, 5, ant);
	myGrid_n->setCellOrganism(3, 5, a5);

	int neighbors5 = a1->numPossCells(3, 4, myGrid_n);

	if(neighbors1 != 4){
		ok1 = false;
	}
	if(neighbors2 != 3){
		ok2 = false;
	}
	if(neighbors3 != 2){
		ok3 = false;
	}
	if(neighbors4 != 1){
		ok4 = false;
	}
	if(neighbors5 != 0){
		ok = false;
	}

	result = ok1 && ok2 && ok3 && ok4 && ok;
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
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the Rand Cell test" << std::endl;
	// Grid Initialization
	Grid* Grid_p = new Grid (8);
	// Ant Initialization
	Ant * a1 = new Ant(3,4,Grid_p);
	// Find the random cells
	struct Ant::Coordinates cords = a1->getRandCell(3, 4, Grid_p);
	int b[]= {cords.cellRow, cords.cellCol};
	if ((b[0] == 4 && b[1] == 4) || (b[0] == 3 && b[1] == 5) || (b[0] == 3 && b[1] == 3) || (b[0] == 2 && b[1] == 4)){

	}else {
		printf("Did not pick a correct random cell");
		ok1 = false;
	}
	// Adding ants around the other ant
	Ant * a2 = new Ant(3,5,Grid_p);
	Grid_p->setCellOccupant(3, 5, ant);
	Grid_p->setCellOrganism(3, 5, a2);
	Ant * a3 = new Ant(3,3,Grid_p);
	Grid_p->setCellOccupant(3, 3, ant);
	Grid_p->setCellOrganism(3, 3, a3);
	Ant * a4 = new Ant(2,4,Grid_p);
	Grid_p->setCellOccupant(2, 4, ant);
	Grid_p->setCellOrganism(2, 4, a4);

	struct Ant::Coordinates cords2 = a1->getRandCell(3, 4, Grid_p);
	int b2[]= {cords2.cellRow, cords2.cellCol};
	if (b2[0] == 4 && b2[1] == 4){

	}else {
		printf("Did not pick a correct random cell");
		ok2 = false;
	}

	result = ok1 && ok2;
	return result;
}

/* Test Destructor Sub
 * Deletes the Testing file
 */
Tests2::~Tests2() {

}

