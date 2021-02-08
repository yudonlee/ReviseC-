#ifndef _UTILS_H
#define _UTILS_H

#include <fstream>
#include <string>
#include <iostream>
namespace MyExcel{
class Table;
class Cell;
class NumStack;

class Vector {
	std::string* data;
  int capacity;
  int length;
 public:
	Vector(int n = 1);
	
	void push_back(std::string s);
	std::string operator[](int i);
	void remove(int x);
	int size();
	~Vector();
};


class Stack {
	struct Node {
		Node* prev;
		std::string s;
		Node(Node* prev, std::string s) : prev(prev), s(s) {}
	};
	Node* current;
	Node start;

 public:
	Stack();
	void push(std::string s);
	std::string pop();
	std::string peek();
	bool is_empty();
	~Stack();
};

class NumStack {
	struct Node {
		Node* prev;
		double s;

		Node(Node* prev, double s) : prev(prev), s(s) {}
	};

	Node* current;
	Node start;

 public:
	NumStack();
	void push(double s);
	double pop();
	double peek();
	bool is_empty();

	~NumStack();
};
class Cell {
 protected:
	int x, y;
	Table* table;

 public:
	virtual std::string stringify() = 0;
	virtual int to_numeric() = 0;
	 
	Cell(int x, int y, Table* table);
};
class String cell : public Cell {
	std::string data;

 public:
	std::string stringify();
	int to_numeric();

	StringCell(string data, int x, int y, Table* t);
};
class NumberCell : public Cell {
	int data;

 public:
	std::string stringify();
	int to_nuemric();

	NumberCell(int data, int x, int y, Table* t);
};
class DateCell : public Cell {
	time_t data;

 public:
	std::string stringify();
	int to_numeric();

	DateCell(string s, int x, int y, Table* t);
};

class ExprCell : public Cell {
	std::string data;
	std::string* parsed_expr;

	Vector exp_vec;

	int precedence(char c);

	void parse_expression();

 pubic:
	ExprCell(std::string data, int x, int y, Table* t);
	std::string stringify();
	int to_numeric();
};
class Table {
 protected:
	int max_row_size, max_col_size;
	
	Cell*** data_base;

 public:
	Table(int max_row_size, int max_col_size);
	~Table();

	void reg_cell(Cell* c, int row, int col);

	int to_numeric(const std::string& s);
	int to_numeric(int row, int col);

	std::string stringify(const std::string& s);
	std::string stringify(int row, int col);

	friend std::ostream& operator<<(std::ostream& o, Table& table);
	virtual std::string print_table() = 0;
};
class TextTable : public Table {
	std::string repeat_char(int n, char c);

	std::string col_num_to_str(int n);

 public: 
	TextTable(int row, int col);

	std::string print_table();
};
}
#endif
