#include "excel.h"

namespace excel{
Cell::Cell(const std::string& data, const int x, const int y) : data_(data), x_(x), y_(y) {
}
std::string Cell::CellToStr() const {
		return data_;
}

bool Cell::IsInt(){
	std::string::const_iterator it = data_.begin();
	while (it != data_.end() && std::isdigit(*it)){
		++it;
	};
	return !data_.empty() && it == data_.end();
}
Cell::Cell() {
	data_ = "";
	x_ = VACANT;
	y_ = VACANT;
}
StringCell::StringCell(const std::string& data, const int x, const int y) : Cell(data, x, y) {
} 
int StringCell::ToNumeric() {
	if(IsInt() == false)
		return 0;
	return atoi(data_.c_str());
}

ExprCell::ExprCell(Cell* left, char op, Cell* right,int x, int y) : Cell() {
	switch(op){
		case '+':
			calculated_num_ = left->ToNumeric() + right->ToNumeric();
			break;
		case '-':
			calculated_num_ = left->ToNumeric() - right->ToNumeric();
			break;
		case '*':
			calculated_num_ = left->ToNumeric() * right->ToNumeric();
			break;
		case '/':
			calculated_num_ = left->ToNumeric() / right->ToNumeric(); 
			break;
	}		
	data_ = std::to_string(calculated_num_);
	x_ = x;
	y_ = y;
}	
int ExprCell::ToNumeric() { 
		return calculated_num_;
}
void Table::RegCell(Cell* c, int row, int col) {
	data_base_[row][col] = c;
}
std::string Table::GetCellToString(int row, int col) {
	return data_base_[row][col]->CellToStr();
}
std::ostream& operator<<(std::ostream& o, Table& t) {
	o << t.PrintTable();
	return o;
}
	
TextTable::TextTable(int max_row, int max_col) : max_row_(max_row), max_col_(max_col), Table() {
	data_base_ = new Cell**[max_row+1];
	for(int i = 0; i <= max_row; i++){
		data_base_[i] = new Cell*[max_col+1];
	}
	index_row_ = 1, index_col_ = 0; 
}

bool TextTable::IsDatabaseFull() {
	if (index_col_ == max_col_) {
		if (index_row_ == max_row_) {
			return true;
		} else {
			index_row_++;
			index_col_ = 1;
			return false;
		}
	} else {
		index_col_++;
		return false;
	}
}
std::string TextTable::PrintTable() {
	std::string result;
	int _col = max_col_;	
	for (int i = 1; i <= index_row_; i++) {
		if (i == index_row_) 
			_col = index_col_;
	
		for (int j = 1; j <= _col; j++) { 
			result += GetCellToString(i, j) + " ";
		}

		result += "\n";
	}
	return result;
}

void TextTable::MakeCell (const std::string data) {
		if (!IsDatabaseFull()) {
			Cell* input = new StringCell(data, index_row_, index_col_);
			data_base_[index_row_][index_col_] = input;	
		}
}	
void TextTable::CalculateCell (std::string left_data, char op, std::string right_data) {
	if (!IsDatabaseFull()){
		int left_index[2];
		int right_index[2];
		left_index[0] = atoi(left_data.substr(1).c_str()); 
		left_index[1] = left_data[0] - '@';
		right_index[0] = atoi(right_data.substr(1).c_str());
		right_index[1] = right_data[0] - '@';
		Cell* input = new ExprCell(data_base_[left_index[0]][left_index[1]],op,data_base_[right_index[0]][right_index[1]],index_row_,index_col_);
		data_base_[index_row_][index_col_] = input;
		}
}
TextTable::~TextTable(){
	for(int i = 0 ; i <= max_col_; i++) {
		delete[] data_base_[i];
	}	
	delete[] data_base_;
}

std::string CsvTable::PrintTable() {
	std::string result;
	int _col = max_col_;
	for(int i = 1; i <= index_row_; i++){
		if(i == index_row_) 
			_col = index_col_;
		for(int j = 1; j <= _col; j++) { 
			result += GetCellToString(i, j) + ",";
		}
		result += "\n";
	}
	return result;
}

}

/*class CsvTable : public TextTable {

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
}*/
