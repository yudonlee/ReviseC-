#ifndef EXCEL_MY_OWN_H_
#define EXCEL_MY_OWN_H_

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#define VACANT -999

namespace excel{
class Table;

class Cell{
 protected:
	 std::string data_;
	 int x_, y_;
 public:
	 Cell(const std::string& data, const int x, const int y);
	 std::string CellToStr() const; 
	 bool IsInt();
	 Cell();
	 virtual int ToNumeric() = 0;
};
class StringCell : public Cell {
 public:
	StringCell(const std::string& data, const int x, const int y); //: Cell(data, x, y) {}
	int ToNumeric() override;
};

class ExprCell : public Cell {
	int calculated_num_;
 public:
	ExprCell(Cell* left, char op, Cell* right, int x, int y); //: Cell() {}
	int ToNumeric() override;
};
class Table {
 protected:
	Cell*** data_base_;

 public:
	virtual std::string PrintTable() = 0;
	void RegCell(Cell* c, int row, int col);
	std::string GetCellToString(int row, int col);
	friend std::ostream& operator<<(std::ostream& o, Table& t);

};

class TextTable : public Table {
 protected:
	int max_row_, max_col_;
	int index_row_, index_col_;
 
 public:
	TextTable(int max_row, int max_col);
	bool IsDatabaseFull();	
	std::string PrintTable() override;
	void MakeCell(const std::string data);
	void CalculateCell(std::string left_data, char op, std::string right_data);
	~TextTable();
};

class CsvTable : public TextTable {
 public:
	CsvTable(int r,int c) : TextTable(r, c) {}
	std::string PrintTable() override;
};

}
#endif
