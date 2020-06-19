#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include "csv.h"
using namespace std;
using namespace CSVpp;

string const& CSV_row::operator[](size_t index) const
{
	return m_data[index];
}
size_t CSV_row::size() const
{
	return m_data.size();
}
void CSV_row::read_next_row(istream& str)
{
	string line;
	getline(str, line);

	stringstream lineStream(line);
	string cell;

	m_data.clear();
	while (getline(lineStream, cell, ','))
	{
		m_data.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		m_data.push_back("");
	}
}

void CSV_row::pop_back()
{
	m_data.pop_back();
}

istream& operator>>(istream& str, CSV_row& data)
{
	data.read_next_row(str);
	return str;
}
/*
Note, the above operator is used as follows:
int main()
{
	std::ifstream       file("plop.csv");

	CSVRow              row;
	while(file >> row)
	{
		std::cout << "4th Element(" << row[3] << ")\n";
	}
}
You may need to finagle the class and such
*/

void CSV::fill_row(CSV_row row)
{
	csv.push_back(row);
}