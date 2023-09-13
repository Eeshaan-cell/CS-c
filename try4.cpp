#include <iostream>
#include <vector>
#include <string>

class Employee {
public:
    Employee(std::string name, int id, double salary, int rating)
        : name(name), id(id), salary(salary), performanceRating(rating==0) {}

    std::string getName() const { return name; }
    int getId() const { return id; }
    double getSalary() const { return salary; }
    int getPerformanceRating() const { return performanceRating; }

    void promote(double raiseAmount) {
        salary += raiseAmount;
        performanceRating += 1; 
        std::cout << name << " has been promoted. New salary: $" << salary << std::endl;
    }

    void demote(double reductionAmount) {
        salary -= reductionAmount;
        performanceRating -= 1; 
        std::cout << name << " has been demoted. New salary: $" << salary << std::endl;
    }

private:
    std::string name;
    int id;
    double salary;
    int performanceRating;
};

class EmployeeManagementSystem {
public:
    void addEmployee(const Employee& emp) {
        employeeList.push_back(emp);
    }

    void displayEmployees() {
        for (const Employee& emp : employeeList) {
            std::cout << "Name: " << emp.getName()
                      << ", ID: " << emp.getId()
                      << ", Salary: $" << emp.getSalary()
                      << ", Performance Rating: " << emp.getPerformanceRating() << std::endl;
        }
    }

    Employee* findEmployeeById(int id) {
        for (Employee& emp : employeeList) {
            if (emp.getId() == id) {
                return &emp;
            }
        }
        return nullptr;
    }

private:
    std::vector<Employee> employeeList;
};

int main() {
    EmployeeManagementSystem ems;
    int z,i;
    std::cout<<"Enter No. of Employees:- ";
    std::cin>>z;

    
    for (i = 0; i < z; ++i) {
        std::string empName;
        int empId;
        double empSalary;
        int empRating;

        

        std::cout << "Enter name of employee " << i + 1 << ": ";
        std::cin>> empName;
        std::cout << "Enter ID of employee " << i + 1 << ": ";
        std::cin >> empId;
        std::cout << "Enter salary of employee " << i + 1 << ": ";
        std::cin >> empSalary;

        ems.addEmployee(Employee(empName, empId, empSalary, empRating));
    }


    std::cout << "Employee List:" << std::endl;
    ems.displayEmployees();

    
    int x;
    std::cout<<"Enter number of updates:- ";
    std::cin>>x;
    for (int i = 0; i < x; ++i) {
        int empId;
        int empRating;

        std::cout << "Enter ID of employee to rate: ";
        std::cin >> empId;
        std::cout << "Enter rating (1-10) for employee " << empId << ": ";
        std::cin >> empRating;

        Employee* emp = ems.findEmployeeById(empId);
        if (emp) {
            if (empRating >= 7) {
                emp->promote(1000); 
            } else if (empRating <= 3) {
                emp->demote(500); 
            }
        } else {
            std::cout << "Employee with ID " << empId << " not found." << std::endl;
        }
    }

    std::cout << "Updated Employee List:" << std::endl;
    ems.displayEmployees();
    return 0;
}