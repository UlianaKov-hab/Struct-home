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
void Highest_Academic_Perfomance_Teacher(Group* groups)//2
{
	float sum = 0;	
	float average_rating_group [3];
	
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 5; j++)
		{			
			for (int e = 0; e < 10; e++)			
			{				
				sum += groups[i].students[j].marks[e];				
			}					
		}
		average_rating_group[i] = sum/50;		
	}
	float max = 0;
	for (int i = 0; i < 3; i++)
	{		
		if (average_rating_group[i] > max)
			max = average_rating_group[i];		
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
void Lowest_Academic_Perfomance_Group(Group* groups)//3
{
	float sum = 0;
	float average_rating_group[3];

	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int e = 0; e < 10; e++)
			{
				sum += groups[i].students[j].marks[e];
			}
		}
		average_rating_group[i] = sum/50;
	}
	/*for (int i = 0; i < 3; i++)
	{
		cout << average_rating_group[i] << " ";
	}*/
	float min = average_rating_group[0];
	for (int i = 0; i < 3; i++)
	{
		if (average_rating_group[i] < min)
			min = average_rating_group[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (average_rating_group[i] == min)
		{
			cout << "The Lowest Academic Perfomance\t" << min << endl;
			cout << "Group name \n";
			cout << groups[i].Name << endl;			
		}
	}
}
void Birthday1(Group* groups) //4
{
	Student* arr1 = new Student[15];
	for (int i = 0, s = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++, s++)
		{
			arr1[s] = groups[i].students[j];
			//groups[i].students[j].PrintStudent();
			//cout << endl;
		}
	}
	bool a;
	bool b=false;
	for (int i = 0; i < 15; i++)
	{
		//arr1[i].PrintStudent();
		//cout << endl;
		a = false;

		for (int j = i+1; j < 15; j++)
		{			
			if (arr1[i].date.year && arr1[i].date.month && arr1[i].date.day== arr1[j].date.year && arr1[j].date.month && arr1[j].date.day)
			{
				a = true;
				b = true;				
				arr1[j].PrintStudent();
				cout << endl;
			}			
		}
		if (a)
		{
			arr1[i].PrintStudent();
			cout << endl;
		}
	}
	if (b == false)
	{
		cout << "net" << endl;
	}
}
void OldestStudent(Group* groups)//5
{
	int year = (2020-groups[0].students[0].date.year)*365;
	int month = (12-groups[0].students[0].date.month)*30;
	int day = 30-groups[0].students[0].date.day;
	int vik;
	vik = day + month + year;
	int vik1;
	int indexi = 0, indexj=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			year = (2020-groups[i].students[j].date.year)*365;
			month = (12-groups[i].students[j].date.month)*30;
			day = 30-groups[i].students[i].date.day;
			vik1= day + month + year;
			if (vik1 > vik)
			{
				vik = vik1;
				indexi = i;
				indexj = j;
			}

		}
	}
	cout << "The oldest student is: " << endl;
	groups[indexi].students[indexj].PrintStudent();

}

void Number_Highest_Academic_Perfomance_Student(Group* groups)//6
{
	float sum = 0;
	float average_rating_student[3][5];
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum = 0;
			for (int e = 0; e < 10; e++)
			{
				sum += groups[i].students[j].marks[e];
			}
			average_rating_student[i][j] = sum/10;
		}		
	}	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << average_rating_student[i][j] << "\t";
		}
		cout << endl;		
	}
	short a = 8.5;
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (average_rating_student[i][j] >= a)
				count++;			
		}		
	}
	cout << "Number of students with an average rating abov 8.5:  " << count << endl;
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
	//srand(time(0));
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
	Highest_Academic_Perfomance_Teacher(groups);
	//Number_Highest_Academic_Perfomance_Student(groups);
	//Lowest_Academic_Perfomance_Group(groups);
	//Birthday1(groups);
	//OldestStudent(groups);
}


