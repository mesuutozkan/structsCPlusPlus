#include <iostream>
#include <string>		//string functions will be used

using namespace std;

//different variable sets can be stored with structs.
struct Student {		//Common using of struct names starts with upper case character. 
	int sNumber;
	string sName;
	double sGradeAverage;
};

void decidePassedOrNot(Student &students)		//decider of passing status (by using call by reference, to not execute in local function)
{
	cout << " Student status: ";
	students.sGradeAverage >= 50 ? cout << "PASSED" << endl : cout << "NOT PASSED" << endl;		//decider block
}

void decideStudentsExam(Student Students[], int size)		//decide all students status, array comes with its index automatically by calling it array[]
{
	cout << "Status Of Students" << endl;

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		//track student by its index (i + 1)

		cout << i + 1 << ". Student number: " << (Students + i) -> sNumber << " "
			<< " Student name: " << (Students + i) -> sName << " " 
			<< " Student Average Grade: " << (Students + i) -> sGradeAverage;

		decidePassedOrNot(Students[i]);		//use decider function (function in function
		cout << endl;
	}
}

int main()
{
	int n;		//number of how many students desired
	cout << "Enter student count: ";
	cin >> n;
	Student* PtrStudents = new Student[n];		//get a dynamic memory pointer for how many students are desired

	for (int i = 0; i < n; i++)					//bind student informations
	{
		cout << "Enter " << i + 1 << ". students number: ";
		cin >> (PtrStudents + i) -> sNumber;	//do it with address offset of the array
		cin.ignore();		//to clean "new line" character (ENTER) 

		/*
		without cin.ignore();
		output:
		Enter student count: 1
		Enter 1. students number: 1
		Enter 1. students name: Enter 1. students average grade: 1
		1. Students number: 1
		1. Students name:
		1. Students average grade: 1
		*/

		cout << "Enter " << i + 1 << ". students name: ";
		
		/*
		cin >> (PtrStudents + 1) -> sName; --> for 2 name(with space, e.g: Mesut Ozkan) it is causing error to run program.
		Instead of it, use getline for more than 1 character sets. (eg: Mesut Ozkan).
		*/

		getline(cin, (PtrStudents + i) -> sName);		//geting string with 2 character sets with string lib is possible in this way
		
		cout << "Enter " << i + 1 << ". students average grade: ";
		cin >> (PtrStudents + i) -> sGradeAverage;
		cout << endl;
	}

	//check allocation

	cout << "List Of Students\n" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Student number: " << (PtrStudents + i) -> sNumber;
		cout << " " << "Student name: " << (PtrStudents + i)->sName;
		cout  << " " << "Student average grade: " << (PtrStudents + i)->sGradeAverage << endl;
		cout << endl;
	}

	cout << endl;

	decideStudentsExam(PtrStudents, n);		//decide with PtrStudents, not locally

	delete[] PtrStudents;		//release PtrStudents
	PtrStudents = NULL;			//ensure it is not point any memory address

	return 0;
}
/*
output:
Enter student count: 2
Enter 1. students number: 11
Enter 1. students name: aa aa
Enter 1. students average grade: 49

Enter 2. students number: 22
Enter 2. students name: bb bb
Enter 2. students average grade: 51

List Of Students

1. Student number: 11 Student name: aa aa Student average grade: 49

2. Student number: 22 Student name: bb bb Student average grade: 51


Status Of Students

1. Student number: 11  Student name: aa aa  Student Average Grade: 49 Student status: NOT PASSED

2. Student number: 22  Student name: bb bb  Student Average Grade: 51 Student status: PASSED
*/