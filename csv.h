#pragma once
#include <string>
#include <vector>
using namespace std;

namespace CSVpp
{
	class CSV_row
	{
	public:
		string const& operator[](size_t index) const;
		size_t size() const;
		void read_next_row(istream& str);
		void pop_back();
	private:
		vector<string> m_data;
	};

	istream& operator>>(istream& str, CSV_row& data);

	class CSV
	{
	public:
		CSV() {}
		void fill_row(CSV_row row);
	private:
		vector<CSV_row> csv;
	};
}