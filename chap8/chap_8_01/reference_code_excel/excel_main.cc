#include "utility.h"

int main() {
	MyExcel::TextTable table(5, 5);
	std::ofstream file1;
	file1.open("text.txt");

	table.reg_cell(new MyExcel::Cell("Hello~", 0, 0, &table), 0, 0);
	table.reg_cell(new MyExcel::Cell("C++", 0, 1,&table), 0, 1);

	table.reg_cell(new MyExcel::Cell("Programming", 1, 1, &table), 1, 1);
	std::cout << std::endl << table;
	file1 << table;
	return 0;
}
