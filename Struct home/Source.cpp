#include<iostream>
#include<time.h>
#include<string>
using namespace std;
struct Date
{
	int day;
	int month;
	int year;
	void Fill(int min, int max)
	{
		day = 1 + rand() % 30;
		month = 1 + rand() % 12;
		year = min + (rand() % (max - min));
	}
	void Print()
	{
		cout << "Day: " << day << endl;
		cout << "Month: " << month << endl;
		cout << "Year: " << year << endl;
	}
};
struct Student
{
	string FirstName;
	string LastName;
	Date date;
	void FillStudent()
	{
		string fn[10] = { "Ivan", "Oleg", "Maksim", "Oleksandr", "Misha", "Tanya", "Vera", "Olga", "Iryna", "Sveta" };
		string ln[10] = { "Skidan", "Kovalchuk", "Ivanov", "Petrov", "Sidorov", "Boyko", "Vitruk", "Oleniuk", "Lozinsky", "Maksimchuk" };
		int a, b;
		a = rand() % 10;
		b = rand() % 10;
		FirstName = fn[a];
		LastName = ln[b];
		date.Fill(1990, 2010);
	}
	void PrintStudent()
	{
		
		cout << "First Name: " << FirstName << endl;
		cout << "Last Name: " << LastName << endl;
		date.Print();
	}
};
struct Teacher
{
	string FirstName;
	string LastName;
	Date date;
	void FillTeacher()
	{
		string fn[5] = { "Nikolay", "Sergiy", "Taras", "Mariya", "Anastasiya" };
		string ln[5] = { "Shport", "Koval", "Goch", "Voityuk", "Sobko" };
		int a, b;
		a = rand() % 5;
		b = rand() % 5;
		FirstName = fn[a];
		LastName = ln[b];
		date.Fill(1975, 1990);
	}
	void PrintTeacher()
	{
		
		cout << "First Name: " << FirstName << endl;
		cout << "Last Name: " << LastName << endl;
		date.Print();
		
	}
	
};
struct Group
{
	Teacher teacher;
	Student student;
	string Name;
	
	void FillName()
	{
		string name[5] = { "Samsung", "Huawei", "Sony", "Microsoft", "Apple" };		
		int a;
		a = rand() % 5;		                                                                                            
		Name = name[a];		
	}
	void PrintName()
	{
		cout << "Group Name: " << Name << endl;		
	}
	void FillGroup()
	{
		cout << "Teacher" << endl;
		teacher.FillTeacher();
		teacher.PrintTeacher();
		cout << endl;
		cout << "Students: " << endl;
		Student* students = new Student[5];
		for (int i = 0; i < 5; i++)
		{
			students[i].FillStudent();
			students[i].PrintStudent();
		}
	}
};

void main()
{	
	Group g;
	for (int i = 0; i < 5; i++)
	{
		g.FillName();
		g.PrintName();
		cout << endl;
		g.FillGroup();
	}
}
