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
				marks[i] = 10 + rand() % (12-10);
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
void Ecxelents(Group *groups) //1
{
	cout << "Ecxellent students: " << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (groups[i].students[j].Status == 1)
			{
				cout << "Group name \n";
				cout << groups[i].Name << endl;
				groups[i].students[j].PrintStudent();
				cout << endl;				
			}			
		}
	}	
}
void Highest_Academic_Perfomance(Group* groups)//2
{
	int sum = 0;
	//int average_rating_students [5];
	int average_rating_group [3];
	
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 5; j++)
		{
			//sum = 0;
			for (int e = 0; e < 10; e++)			
			{				
				sum += groups[i].students[j].marks[e];				
			}	
			//average_rating_students[j] = sum;			
		}
		average_rating_group[i] = sum;		
	}
	int max = 0;
	for (int i = 0; i < 3; i++)
	{		
		if (average_rating_group[i] > max)
			max = average_rating_group[i];
		//cout << average_rating_group[i] << "\t";		
	}
	for (int i = 0; i < 3; i++)
	{
		if (average_rating_group[i] == max)
		{
			cout << "The Highest Academic Perfomance\t" << max << endl;
			cout << "Group name \n";
			cout << groups[i].Name << endl;
			groups[i].teacher.PrintTeacher();
		}
	}


}
void CountPrivilege(Group* groups)//7
{
	int count[3]{ 0,0,0 };
	int max = 0;	
	for (int i = 0; i < 3; i++)
	{		
		for (int j = 0; j < 5; j++)
		{
			if (groups[i].students[j].Privilege == 1)
			{
				count[i]++;				
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (count[i] > max)
		{
			max = count[i];					
		}
	}	
	cout << "Group with the most privileged students: " << endl;
	for (int i = 0; i < 3; i++)
	{
		if (count[i] == max)
		{			
			cout << groups[i].Name << endl;
		}
	}	
}

void main()
{	
	srand(time(0));
	Group groups[3];
	string names[3]= { "Samsung", "Microsoft", "Apple" };	

	for (int i = 0; i < 3; i++)
	{				
		groups[i].FillGroup(names[i]);
		groups[i].PrintGroup();
	}
	cout << endl << endl;
	
	//Ecxelents(groups);
	//CountPrivilege(groups);
	Highest_Academic_Perfomance(groups);

}


