#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Employee {
public:
    string name;
    double salary;
    double tax;

    double calculateNetSalary() const {
        return salary - (salary * tax);
    }
};

class PayrollSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee() {
        Employee newEmployee;

        cout << "Enter employee name: ";
        getline(cin, newEmployee.name);

        cout << "Enter employee salary: ";
        cin >> newEmployee.salary;

        cout << "Enter employee tax rate (e.g., 0.15 for 15%): ";
        cin >> newEmployee.tax;
        cin.ignore(); 

        employees.push_back(newEmployee);
    }

    void generatePayroll() {
        cout << "Payroll Report:" << endl;
        cout << "---------------" << endl;

        for (const auto& employee : employees) {
            cout << "Name: " << employee.name << endl;
            cout << "Salary: $" << fixed << setprecision(2) << employee.salary << endl;
            cout << "Tax: " << fixed << setprecision(2) << (employee.tax * 100) << "%" << endl;
            cout << "Net Salary: $" << fixed << setprecision(2) << employee.calculateNetSalary() << endl;
            cout << "---------------" << endl;
        }
    }
};

int main() {
    PayrollSystem payrollSystem;
    char choice;

    do {
        cout << "Payroll Management System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Generate Payroll" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case '1':
            payrollSystem.addEmployee();
            break;
        case '2':
            payrollSystem.generatePayroll();
            break;
        case '3':
            cout << "Exiting Payroll Management System..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << endl;
    } while (choice != '3');

    return 0;
}