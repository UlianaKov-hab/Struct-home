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
	int marks[10];
	int Status;
	int Privilege;
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
		Status = rand() % 2;	
		Privilege = rand() % 2;
		if (Status == 1)
		{
			for (int i = 0; i < 10; i++)
			{
				marks[i] = 9 + rand() % 10;
			}
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				marks[i] = 1 + rand() % 8;
			}
		}
		

	}
	void PrintStudent()
	{		
		cout << "First Name: " << FirstName << endl;
		cout << "Last Name: " << LastName << endl;
		date.Print();
		cout << "Marks: ";
		for (int i = 0; i < 10; i++)
		{
			cout<<marks[i]<<" ";
		}
		cout << endl;
		if (Status == 1)
		{
			cout << "Status - ecxellent student" << endl;
		}
		else
		{
			cout << "Status - " << Status<<endl;
		}
		if (Privilege == 1)
		{
			cout << "Student have privilege";
		}
		if (Privilege == 0)
		{
			cout << "Student has no privilege";
		}	
		cout << endl;
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
	Student* students = new Student[5];
	void FillGroup(string name)
	{			
		Name = name;
		teacher.FillTeacher();
		
		for (int i = 0; i < 5; i++)
		{
			students[i].FillStudent();				
		}
	}
	void PrintGroup()
	{

		cout << "Name Group: " << Name << endl<<endl;
		cout << "Teacher" << endl;

		teacher.PrintTeacher();
		cout << endl;
		cout << "Students: " << endl << endl;
		
		for (int i = 0; i < 5; i++)
		{
			students[i].PrintStudent();
			cout << endl;
		}
		cout << "----------------------------------" << endl;
	}
};

void main()
{	
	Group groups[3];
	string names[3]= { "Samsung", "Microsoft", "Apple" };	

	for (int i = 0; i < 3; i++)
	{				
		groups[i].FillGroup(names[i]);
		groups[i].PrintGroup();
	}

}


