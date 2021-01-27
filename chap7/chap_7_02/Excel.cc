#include <fstream>
#include <iostream>
#include <string>

class Table; //이거 한 이유가 무엇일까? 
class Cell {
	//Table* table;
	std:: string data;
	int x, y;
 
 public:
	Cell(const std::string& data, const int x, const int y) : data(data), x(x), y(y) {}
	std::string cell_str() const {
		return data;
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
		data_base = new Cell**[max_row];
		for(int i = 0; i < max_col; i++){
			data_base[i] = new Cell*[max_col];
		}
		index_row = 0, index_col = -1; //셀에서 초기값 하나가 있다는 가정하에 check_database가 작동되기 때문이다.
	}; 
	bool check_database_full() {
		if(index_col == max_col-1){
			if(index_row == max_row-1){
				return false;
			}
			else{
				index_row++;
				index_col = 0;
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
		int _row = index_row;
		int _col = max_col - 1;
		for(int i = 0; i <= _row; i++){
			if(i == _row) 
				_col = index_col;
			
			for(int j = 0; j <= _col; j++) { 
				result += get_cell_str(i, j) + " ";
			}
			result += "\n";
		}
		return result;
	}

	void make_cell(const std::string data){
		//check coordinate x, y
		if (check_database_full()){
			Cell* input = new Cell(data, index_row, index_col);
			data_base[index_row][index_col] = input;
		
		}
	}
};
class CsvTable : public TextTable {

 public:
	CsvTable(int r, int c) : TextTable(r,c) {}
	std::string print_table() override {
		std::string result;
		int _row = index_row;
		int _col = max_col - 1;
		for(int i = 0; i <= _row; i++){
			if(i == _row) 
				_col = index_col;
			
			for(int j = 0; j <= _col; j++) { 
				result += get_cell_str(i, j) + ",";
			}
			result += "\n";
		}
		return result;
	}
};

int main() {
	CsvTable test(3,3);
	TextTable test1(3,3);
	test.make_cell("hello");
	test.make_cell("world");
	test.make_cell("hahaha");
	test.make_cell("aas");
	test.make_cell("adsf");
	test.make_cell("adsf");
	test.make_cell("last");

	test1.make_cell("hello");
	test1.make_cell("world");
	test1.make_cell("hahaha");
	test1.make_cell("aas");
	test1.make_cell("adsf");
	test1.make_cell("adsf");
	test1.make_cell("last");
	
	std::ofstream file1;
	std::ofstream file2;
	file1.open("test.csv");
	file1 << test;
	file2.open("test.txt");
	file2 << test1;
	return 0;
}
