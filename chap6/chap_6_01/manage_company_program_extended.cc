#include <iostream>
#include <string>
class Employee{
	std::string name;
	int age;

	std::string position;
	int rank;

 public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}
	
	Employee(const Employee& employee){
		name =  employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}
	Employee() {}

	void print_info(){
		std::cout << name << " (" << position <<" , " << age << ") ==> "
							<< calculate_pay() << "만원" << std::endl;
	}
	int calculate_pay(){ return 200 + rank * 50; }
};
class Manager {
	std::string name;
	int age;

	std::string position;
	int rank;
	int year_of_service;

 public:
	Manager(std::string name, int age, std::string position, int rank, 
					int year_of_service) 
		: year_of_service(year_of_service),
			name(name),
			age(age),
			position(position),
			rank(rank) {}

	Manager(const Manager& manager) {
		name = manager.name;
		age = manager.age;
		rank= manager.rank;
		year_of_service = manager.year_of_service;
	}

	Manager() {}
	
	int calculate_pay() {	return 200 + rank * 5 + 5 * year_of_service; }
	void print_info() {	
		std::cout << name << " (" << position << " , " << age << ", "
							<< year_of_service << "년차) ==> " << calculate_pay() 
							<< "만원" << std::endl;
	}
};
class EmployeeList {
	int alloc_employee;
	
	int current_employee;
	int current_manager;

	Employee **employee_list;
	Manager **manager_list;
 public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee*[alloc_employee];
		manager_list = new Manager*[alloc_employee];
	//	for (int i = 0; i < alloc_employee; i++)
	//		employee_list[i] = new Employee[i];
		current_employee = 0;
		current_manager = 0;
	}
	void add_employee(Employee *employee){
		employee_list[current_employee] = employee;
		current_employee++;
	}
	void add_manager(Manager* manager){
		manager_list[current_manager] = manager;
		current_manager++;
	}
	
	void add_employee_staff(Employee *employee){
		employee_list[current_employee][1] = *employee;
	}
	
	int current_employee_num() { return current_employee + current_manager; }
	
	void print_employee_info(){
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++){
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}

		std::cout <<"총 비용 : " << total_pay << "만원 " << std::endl;
	}
	void print_manager_info() {
		int total_pay = 0;
		for (int i = 0; i < current_manager; i++){
			manager_list[i]->print_info();
			total_pay += manager_list[i]->calculate_pay();
		}
		std::cout <<"총 비용 : " << total_pay << "만원 " << std::endl;
	}
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
			delete manager_list[i];
		}
		delete[] employee_list;
		delete[] manager_list;
	}
};

int main(){
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("Ro Hong Cheol", 34, "평사원", 1));
	emp_list.add_employee(new Employee("HaHa", 34, "평사원", 1));
	emp_list.add_employee(new Employee("Yu jae seok", 41, "부장", 7));
	emp_list.add_employee(new Employee("Jeong Jun ha", 43, "과장", 4));
	emp_list.add_employee(new Employee("G-Park", 44, "차장", 5));
	emp_list.add_employee(new Employee("Jeong Hyeong Don", 36, "대리", 2));
	emp_list.add_employee(new Employee("Gil", 36, "인턴", -2));
	emp_list.add_manager(new Manager("Tae Ho Kim", 45, "PD", 8,20));
	emp_list.print_employee_info();
	emp_list.print_manager_info();
	//emp_list.add_employee_staff(new Employee("Tae ho kim", 44, "PD", 8));
	return 0;
}
