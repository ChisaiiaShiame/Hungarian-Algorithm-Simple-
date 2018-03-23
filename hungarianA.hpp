

#include <iostream>
#include <vector>
#include <stdio.h>

#ifndef HUNGARIAN_H
#define HUNGARIAN_H

using std::vector;

typedef enum {
	HUNGARIAN_MODE_MINIMIZE_COST,
	HUNGARIAN_MODE_MAXIMIZE_UTIL,
} MODE;

typedef enum {
	HUNGARIAN_NOT_ASSIGNED,
	HUNGARIAN_ASSIGNED,
} ASSIGN;



class Hungarian
{

public:
	/** This method initialize the hungarian_problem structure and init 
	 *  the  cost matrices (missing lines or columns are filled with 0).
	 *  It returns the size of the quadratic(!) assignment matrix. **/

	Hungarian();
	Hungarian(const vector<vector<int> >&, int, int, MODE);

	int init(const vector<vector<int> >& input_matrix, 
			   int rows, 
			   int cols, 
			   MODE mode);

	/** This method computes the optimal assignment. **/
	bool solve();

	/** Accessor for the cost **/
	int cost() const;

	/** Reference accessor for assignment **/
	const vector<vector<int> >& assignment() const;

	/** Print the computed optimal assignment. **/
	void print_assignment();

	/** Print the cost matrix. **/
	void print_cost();

	/** Print cost matrix and assignment matrix. **/
	void print_status();

protected:
	bool check_solution(const vector<int>& row_dec, const vector<int>& col_inc, const vector<int>& col_vertex);
	bool assign_solution(const vector<int>& row_dec, const vector<int>& col_inc, const vector<int>& col_vertex);

private:

	int m_cost;
	int m_rows;
	int m_cols;
	vector<vector<int> > m_costmatrix;
	vector<vector<int> > m_assignment;   

};

#endif



