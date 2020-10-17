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
	Student student [5];
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
};


void main()
{
	srand(time(0));
	Student x;
	x.FillStudent();
	x.PrintStudent();
	cout << "------------------------------------"<<endl;
	Teacher n;
	n.FillTeacher();
	n.PrintTeacher();
	cout << "------------------------------------" << endl;
	Group g;
	g.FillName();
	g.PrintName();

}
