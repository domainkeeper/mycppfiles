#include <iostream>
#include <string>

class Student {
public:
	int rollNumber;
	std::string studentName;
	Student* nextStudent;

	Student(int roll, const std::string& name)
		: rollNumber(roll), studentName(name), nextStudent(nullptr) {}
};

int main() {
	Student firstStudent(1, "Aarav");
	Student secondStudent(2, "Maya");
	Student thirdStudent(3, "Noah");

	firstStudent.nextStudent = &secondStudent;
	secondStudent.nextStudent = &thirdStudent;
	thirdStudent.nextStudent = nullptr;

	Student* currentStudent = &firstStudent;
	while (currentStudent != nullptr) {
		std::cout << currentStudent->studentName << '\n';
		currentStudent = currentStudent->nextStudent;
	}

	return 0;
}
