#include "utility.h"

namespace MyExcel {
class Cell;
class NumStack;
class Table;
Vector::Vector(int n) : data(new std::string[n]), capacity(n), length(0) {}
void Vector::push_back(std::string s) {
	if (capacity <= length) {
		std::string* temp = new std::string[capacity * 2];
		for(int i = 0 ; i < length; i++) {
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		capacity *=2;
	}
	
	data[length] = s;
	length++;
}
std::string Vector::operator[](int i) { return data[i]; }
void Vector::remove(int x) {
	for (int i = x + 1; i < length; i++) {
		data[i - 1] = data[i];
	}
	length--;
}
int Vector::size() { return length; }
Vector::~Vector() {
	if (data) {
		delete[] data;
	}
}
Stack::Stack() : start(NULL, "") { current = &start; }
void Stack::push(std::string s) {
	Node* n = new Node(current, s);
	current = n;
}
std::string Stack::pop() {
	if (current == &start) return "";

	std::string s = current->s;
	Node* prev = current;
	current = current->prev;

	delete prev;
	return s;
}
std::string Stack::peek() { return current->s; }
bool Stack::is_empty() {
	if (current == &start) return true;
	return false;
}
Stack::~Stack() {
	while(current != &start) {
		Node* prev = current;
		current = current->prev;
		delete prev;
	}
}
NumStack::NumStack() : start(NULL, 0) { current = &start; }
void NumStack::push(double s) {
	Node* n = new Node(current, s);
	current = n;
}
double NumStack::pop() {
	if (current == &start) return 0;

	double s = current -> s;
	Node* prev = current;
	current = current->prev;

	delete prev;
	return s;
}
double NumStack::peek() { return current->s; }
bool NumStack::is_empty() {
	if (current == &start) return true;
	return false;
}
NumStack::~NumStack() {
	while (current != &start) { 
		Node* prev = current;
		current = current->prev;
		delete prev;
	}
}
Cell::Cell(int x, int y, Table* table) : x(x), y(y), table(table) {}

StringCell::StringCell(std::string data, int x, int y, Table* t) : data(data), Cell(x, y, t) {}

std::string StringCell::stringify() { return data; }
int StringCell::to_numeric() { return 0; }

NumberCell:NumberCell(int data, int x, int y, Table* t) 
	: data(data), Cell(x, y, t) {}

std::string NumberCell::stringify() { return to_string(data); }
int NumberCell:: to_numeric() { return data; }

std::string DateCell::stringify() {
	char buf[50];
	tm temp;
	localtime_s(&temp, &data);

	strftime(buf, 50, "%F", &temp);
	
	return std::string(buf);
}
int DateCell::to_numeric() { return static_cast<int>(data); }

DateCell::DateCell(std::string s, int x, int y, Table* t) 
	: Cell(x, y, t) { 
	int year = atoi(s.c_str());
	int month = atoi(s.c_str() + 5);
	int day = atoi(s.c_str() + 8);

	tm timeinfo;
	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;
	tminfo.tm_hour = 0;
	tminfo.tm_min = 0;
	tminfo.tm_set = 0;

	data = mktime(&timeinfo);
}

ExprCell::ExprCell(std::string data, int x, int y, Table* t) : Cell(data, x, y) {
}

int ExprCell::precedence(char c) { 
	switch (c) {
		case '(':
		case '[':
		case '{':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return 0;
}
int ExprCell::to_numeric() {
	double result = 0;
	NumStack stack;

	for (int i = 0; i < exp_vec.size(); i++) {
		std::string s = exp_vec[i];

		if (isalpha(s[0])) {
			stack.push(atoi(s.c_str()));
		}
		else if (isdigit(s[0])) {
			stack.push(atoi(s.c_str()));
		} else {
			double y = stack.pop();
			double x = stack.pop();
			switch (s[0]) {
				case '+':
					stack.push(x + y);
					break;
				case '-':
					stack.push(x - y);
					break;
				case '*':
					stack.push(x * y);
					break;
				case '/':
					stack.push(x / y);
					break;
			}
		}
	}
	
	return stack.pop();
}
 
void ExprCell::parse_expression() {
	Stack stack;

	data.insert(0, "(");
	data.push_back(')');
	for (int i = 0; i < data.length(); i++) {
		if (isalpha(data[i])) {
			exp_vec.push_back(data.substr(i, 2));
			i++;
		} else if (isdigit(data[i])) {
			exp_vec.push_back(data.substr(i, 1));
		} else if (data[i] == '(' || data[i] == '[' || data[i] == '{') {
			stack.push(data.substr(i, 1));
		} else if (data[i] == ')' || data[i] == ']' || data[i] == '}') {
			std::string t = stack.pop();
			while (t != "(" && t != "[" && t != "{") {
				exp_vec.push_back(t);
				t = stack.pop();
			}
		} else if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/') {
			
			while(!stack.is_empty() && precedence(stack.peek()[0]) >= precedence(data[i])) {
				exp_vec.push_back(stack.pop());
			}
			stack.push(data.substr(i, 1));
			
		}
	}
}
Table::Table(int max_row_size, int max_col_size) : max_row_size(max_row_size), max_col_size(max_col_size) {
	data_base = new Cell**[max_row_size];
	for(int i = 0; i < max_row_size; i++) {
		data_base[i] = new Cell*[max_col_size];
		for(int j = 0; j < max_col_size; j++) {
			data_base[i][j] = NULL;
		}
	}
}

Table::~Table() {
	for (int i = 0 ; i < max_row_size; i++) {
		for(int j = 0; j < max_col_size; j++) {
			if (data_base[i][j]) delete data_base[i][j];
		}
	}
	for (int i = 0; i < max_row_size; i++) {
		delete[] data_base[i];
	}
	delete[] data_base;
}
void Table::reg_cell(Cell* c, int row, int col) {
	if(!(row < max_row_size && col < max_col_size)) return;

	if (data_base[row][col]) {
		delete data_base[row][col];
	}
	data_base[row][col] = c;
}
int Table::to_numeric(const std::string& s) {
	int row = s[0] - 'A';
	int col = atoi(s.c_str() + 1 ) - 1;

	if (row < max_row_size && col < max_col_size) {
		if (data_base[row][col]) {
			return data_base[row][col]->to_numeric();
		}
	}
	return 0;
}
int Table::to_numeric(int row, int col ) {
	if(row < max_row_size && col < max_col_size && data_base[row][col]) {
		return data_base[row][col]->to_numeric();
	}
	return 0;
}
std::string Table::stringify(const std::string& s) {
	int col = s[0] - 'A';
	int row = atoi(s.c_str() + 1 ) - 1;

	if(row < max_row_size && col < max_row_size) {
		if (data_base[row][col]) {
			return data_base[row][col]->stringify();
		}
	}
	return "";
}
std::string Table::stringify(int row, int col) {
	if (row < max_row_size && col < max_col_size && data_base[row][col]) {
		return data_base[row][col]->stringify();
	}
	return "";
}
std::ostream& operator<<(std::ostream& o, Table& table) {
	o << table.print_table();
	return o;
}
TextTable::TextTable(int row, int col) : Table(row, col) {}

std::string TextTable::print_table() {
	std::string total_table;

	int* col_max_wide = new int[max_col_size];
	for (int i = 0; i < max_col_size; i++) {
		unsigned int max_wide = 2;
		for (int j = 0; j < max_row_size; j++) {
			if(data_base[j][i] && data_base[j][i]->stringify().length() > max_wide) {
				max_wide = data_base[j][i] ->stringify().length();
			}
		}
		col_max_wide[i] = max_wide;
	}

	total_table += "    ";
	int total_wide = 4;
	for (int i = 0; i < max_col_size; i++) {
		if (col_max_wide[i]) {
			int max_len = std::max(2, col_max_wide[i]);
			total_table += " | " + col_num_to_str(i);
			total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');
			total_wide += (max_len + 3);
		} 
	}

	total_table +=  '\n';
	for(int i = 0 ; i < max_row_size; i++) {
		total_table += repeat_char(total_wide, '-');
		total_table += "\n" + std::to_string(i + 1);
		total_table += repeat_char(4 - std::to_string(i + 1).length(), ' ');

		for (int j = 0; j < max_col_size; j++) {
			if (col_max_wide[j]) {
				int max_len = std::max(2, col_max_wide[j]);

				std::string s = "";
				if (data_base[i][j]) {
					s = data_base[i][j]->stringify();
				}
				total_table += " | " + s;
				total_table += repeat_char(max_len - s.length(), ' ');
			}
		}
		total_table += "\n";
	}
	return total_table;
}

std::string TextTable::repeat_char(int n, char c) {
	std::string s = "";
	for (int i = 0 ; i < n; i++) s.push_back(c);

	return s;
}
std::string TextTable::col_num_to_str(int n) {
	std::string s = "";
	if (n < 26) {
		s.push_back('A' + n);
	}
	else {
		char first = 'A' + n/26 - 1;
		char second = 'A' + n%26;

		s.push_back(first);
		s.push_back(second);
	}

	return s;
}

}

