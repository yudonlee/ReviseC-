#include "excel.h"

int main() {

	excel::TextTable test1(3, 3);
	test1.MakeCell("12a");
	test1.MakeCell("13");
	test1.CalculateCell("A1",'+',"B1");
	excel::CsvTable test2(3, 3);
	test2.MakeCell("12a");
	test2.MakeCell("13");
	test2.CalculateCell("A1",'+',"B1");
	std::ofstream file1;
	std::ofstream file2;
	file1.open("test.txt");
	file2.open("test.csv");
	file1 << test1;
	file2 << test2;
	return 0;
}
