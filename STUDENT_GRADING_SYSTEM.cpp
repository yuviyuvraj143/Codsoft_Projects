#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    double grade;
};

int main() {
    std::vector<Student> students;
    
    while (true) {
        std::string name;
        double grade;
        
        std::cout << "Enter student name (or 'exit' to finish): ";
        std::cin >> name;
        
        if (name == "exit") {
            break;
        }
        
        std::cout << "Enter " << name << "'s grade: ";
        std::cin >> grade;
        
        students.push_back({name, grade});
    }
    
    if (students.empty()) {
        std::cout << "No students entered." << std::endl;
        return 1;
    }
    
    double totalGrade = 0.0;
    double highestGrade = students[0].grade;
    double lowestGrade = students[0].grade;
    
    for (const auto &student : students) {
        totalGrade += student.grade;
        if (student.grade > highestGrade) {
            highestGrade = student.grade;
        }
        if (student.grade < lowestGrade) {
            lowestGrade = student.grade;
        }
    }
    
    double averageGrade = totalGrade / students.size();
    
    std::cout << "\nStudent Grades Summary:\n";
    std::cout << "-----------------------\n";
    std::cout << "Average Grade: " << averageGrade << std::endl;
    std::cout << "Highest Grade: " << highestGrade << std::endl;
    std::cout << "Lowest Grade: " << lowestGrade << std::endl;

    return 0;
}
