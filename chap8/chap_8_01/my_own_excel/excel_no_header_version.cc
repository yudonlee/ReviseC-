#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
class Table; //이거 한 이유가 무엇일까? 
class Cell {
 protected:
	//Table* table;
	std:: string data;
	int x, y;
 
 public:
	Cell(const std::string& data, const int x, const int y) : data(data), x(x), y(y) {}
	std::string cell_str() const {
		return data;
	}
	bool is_int(){
		std::string::const_iterator it = data.begin();
		while (it != data.end() && std::isdigit(*it)) ++it;
		return !data.empty() && it == data.end();
	}
	Cell() {}
	virtual int to_numeric() = 0;
	//virtual std::string int_to_string() = 0;
};
class StringCell : public Cell {
 public:
	StringCell(const std::string& data, const int x, const int y) : Cell(data, x, y) {}; 
	int to_numeric() override{
		if(is_int() == false)
			return 0;
		return atoi(data.c_str());
	}
};

class NumberCell : public Cell {
	int number;

 public:
	NumberCell(const std::string& data, const int x, const int y) : Cell(data, x, y) { number = to_numeric();}
	int to_numeric() override{
		return number;
	}
};

class ExprCell : public Cell {
	int calculated_num;
 public:
	ExprCell(Cell* left, char op, Cell* right,int _x, int _y) : Cell() {
		switch(op){
			case '+':
				calculated_num = left->to_numeric() + right->to_numeric();
				break;
			case '-':
				calculated_num = left->to_numeric() - right->to_numeric();
				break;
			case '*':
				calculated_num = left->to_numeric() * right->to_numeric();
				break;
			case '/':
				calculated_num = left->to_numeric() / right->to_numeric(); 
				break;
		}		
		data = std::to_string(calculated_num);
		x = _x;
		y = _y;
	}	
	int to_numeric() override{
		return calculated_num;
	}
};
class Table {
 protected:
	Cell*** data_base;

 public:
	Table() {} 
	virtual std::string print_table() = 0;
	void reg_cell(Cell* c, int row, int col);
	std::string get_cell_str(int row, int col);
	friend std::ostream& operator <<(std::ostream& o, Table& t);

	~Table(){}
};

void Table::reg_cell(Cell* c, int row, int col){
	data_base[row][col] = c;
}
std::string Table::get_cell_str(int row, int col) {
	return data_base[row][col]->cell_str();
}
std::ostream& operator<<(std::ostream& o, Table& t) {
	o << t.print_table();
	return o;
}
	
class TextTable : public Table {
 protected:
	int max_row, max_col;
	int index_row, index_col;
 public:
	TextTable(int max_row, int max_col) : max_row(max_row), max_col(max_col), Table() {
		data_base = new Cell**[max_row+1];
		for(int i = 0; i <= max_row; i++){
			data_base[i] = new Cell*[max_col+1];
		}
		index_row = 1, index_col = 0; //셀에서 초기값 하나가 있다는 가정하에 check_database가 작동되기 때문이다.
	}; 
	bool check_database_full() {
		if(index_col == max_col){
			if(index_row == max_row){
				return false;
			}
			else{
				index_row++;
				index_col = 1;
				return true;
			}
		}
		else{
			index_col++;
			return true;
		}
	}
	std::string print_table() override {
		std::string result;
		int _col = max_col;	
		for(int i = 1; i <= index_row; i++){
			if(i == index_row) 
				_col = index_col;
			
			for(int j = 1; j <= _col; j++) { 
				result += get_cell_str(i, j) + " ";
			}
			result += "\n";
		}

		return result;
	}

	void make_cell(const std::string data){
		if (check_database_full()){
			Cell* input = new StringCell(data, index_row, index_col);
			data_base[index_row][index_col] = input;
		
		}
	}
	void cal_cell(std::string left_data, char op, std::string right_data){
		if (check_database_full()){
			int left_index[2];
			int right_index[2];
			left_index[0] = atoi(left_data.substr(1).c_str()); 
			left_index[1] = left_data[0] - '@';
			right_index[0] = atoi(right_data.substr(1).c_str());
			right_index[1] = right_data[0] - '@';
			Cell* input = new ExprCell(data_base[left_index[0]][left_index[1]],op,data_base[right_index[0]][right_index[1]],index_row,index_col);
			data_base[index_row][index_col] = input;
		}
	}
};

class CsvTable : public TextTable {

 public:
	CsvTable(int r, int c) : TextTable(r,c) {}
	std::string print_table() override {
		std::string result;
		int _col = max_col;
		for(int i = 1; i <= index_row; i++){
			if(i == index_row) 
				_col = index_col;
			
			for(int j = 1; j <= _col; j++) { 
				result += get_cell_str(i, j) + ",";
			}
			result += "\n";
		}
		return result;
	}
}; 

int main() {
	TextTable test1(3, 3);
	CsvTable test2(3, 3);
	test1.make_cell("12a");
	test1.make_cell("13");
	test1.cal_cell("A1",'+',"B1");
	test1.cal_cell("A1",'+',"C1");
	test2.make_cell("12a");
	test2.make_cell("13");
	test2.cal_cell("A1",'+',"B1");
	test2.cal_cell("A1",'+',"C1");
	std::ofstream file1;
	std::ofstream file2;
	file1.open("test.txt");
	file2.open("test.csv");
	file1 << test1;
	file2 << test2;
	return 0;
}