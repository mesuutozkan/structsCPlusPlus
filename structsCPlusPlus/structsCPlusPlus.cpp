#include <iostream>
#include <string>		//string functions will be used

using namespace std;

//different variable sets can be stored with structs.
struct Student {		//Common using of struct names starts with upper case character. 
	int sNumber;
	string sName;
	double sGradeAverage;
};

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
	}

	cout << endl << "List Of Students\n" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". Students number: " << (PtrStudents + i) -> sNumber << endl;
		cout << i + 1 << ". Students name: " << (PtrStudents + i) -> sName << endl;
		cout << i + 1 << ". Students average grade: " << (PtrStudents + i) -> sGradeAverage << endl;
	}
	delete[] PtrStudents;
	PtrStudents = NULL;


}