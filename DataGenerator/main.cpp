#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

//Defines of number of rows in each table
#define PERSONS 4000
#define KINDERGARTENS 20
#define PARENTS 1000
#define PARENTSV2 500
#define STUDENTS 2000
#define STUDENTSV2 2000
#define GROUPS 20
#define MEALS 200
#define MEALSV2 200
#define EATINGS 2000
#define EATINGSV2 2000


std::fstream& GotoLine(std::fstream& file, unsigned int num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}

struct Elements {
	vector <string> PESELs;
	vector <string> datesList;
	vector <int> kindergarten;
	vector <int> kindergarten2;
	vector <string> datesList2;
	int* StudentKindergarten;
	vector <int>* KindergartenMeals;
	vector <int>* KindergartenMeals2;
}elements;

string getMaleName();
string getFemaleName();
string getSurname();
string getCity();
string getAddress();
string getEmail();
string getMeal();

//Generate random number including min and max
long long int randNumber(long long int min, long long int max)
{
	long long int modulo = max - min + 1;
	long long int r;
	return  r = rand() % modulo + min;
}

string randPESEL()
{
	long long unsigned int a, b, c;
	a = randNumber(100, 993);
	b = randNumber(2310, 9999);
	c = randNumber(1000, 9999);
	return to_string(a) + to_string(b) + to_string(c);
}

string randDate(int startDate, int EndDate)
{
	int month_l = randNumber(1, 12);
	int year_l = randNumber(startDate, EndDate);
	int day_l;

	string month = to_string(month_l);
	string year = to_string(year_l);
	string day;
	if (month == "2")
		day_l = randNumber(1, 28);
	else if (month == "1" || month == "3" || month == "5" || month == "7" || month == "8" || month == "10" || month == "12")
		day_l = randNumber(1, 31);
	else
		day_l = randNumber(1, 30);

	day = to_string(day_l);

	if (day_l < 10)
		day = "0" + day;
	if (month_l < 10)
		month = "0" + month;

	return year + "-" + month + "-" + day;
}

string randPhone()
{
	long long unsigned int a, b, c;
	a = randNumber(100, 999);
	b = randNumber(100, 999);
	c = randNumber(100, 999);
	return to_string(a) + to_string(b) + to_string(c);
}

void createExcel()
{
	ofstream Sheet1, Sheet2;
	Sheet1.open("Sheet1.csv");
	Sheet2.open("Sheet2.csv");
	Sheet1 << "Date;Amount of food thrown out(in kg);Amount of food bought (in kg);Money invested to buy products (in zl);Kindergarten_ID\n";
	Sheet2 << "Date;Amount of food thrown out(in kg);Amount of food bought (in kg);Money invested to buy products (in zl);Kindergarten_ID\n";

	int bought, thrown, money, kindergatenID;
	string date;
	for (int i = 0; i < MEALS; i++)
	{
		bought = randNumber(250, 1000);
		thrown = randNumber(0, bought);
		money = bought * randNumber(10, 40);
		date = elements.datesList.back();
		kindergatenID = elements.kindergarten.back();
		Sheet1 << date << ";" << thrown << ";" << bought << ";" << money << ";" << kindergatenID << ";\n";
		Sheet2 << date << ";" << thrown << ";" << bought << ";" << money << ";" << kindergatenID << ";\n";
		elements.datesList.pop_back();
		elements.kindergarten.pop_back();
	}
	Sheet1.close();
	for (int i = 0; i < MEALSV2; i++)
	{
		bought = randNumber(250, 400);
		thrown = randNumber(0, bought) * 0.3;
		money = bought * randNumber(20, 40);
		date = elements.datesList2.back();
		kindergatenID = elements.kindergarten2.back();
		Sheet2 << date << ";" << thrown << ";" << bought << ";" << money << ";" << kindergatenID << ";\n";
		elements.datesList2.pop_back();
		elements.kindergarten2.pop_back();
	}
	Sheet2.close();
}


void createPersonBulk()
{
	ofstream Person;
	Person.open("Person.bulk");
	Person << "PESEL|DateOfBirth|Name|Surname|Gender|Registered_address|City|Postcode\n";

	string PESEL, date;
	string name, surname, gender, address, city, postcode;
	for (int i = 0; i < PERSONS; i++)
	{
		PESEL = randPESEL();
		elements.PESELs.push_back(PESEL);
		date = randDate(2015, 2022);
		if (randNumber(0, 1) == 1)
		{
			gender = "m";
			name = getMaleName();
		}
		else
		{
			gender = "f";
			name = getFemaleName();
		}
		surname = getSurname();
		address = getAddress();
		city = getCity();
		postcode = to_string(randNumber(40, 99)) + "-" + to_string(randNumber(100, 400));
		Person << PESEL << "|" << date << "|" << name << "|" << surname << "|" << gender << "|" << address << "|" << city << "|" << postcode << "\n";
	}
	Person.close();
}

void createKindergartenBulk()
{
	int id, students;
	string address, city, postcode;
	ofstream Kindergarten;
	Kindergarten.open("Kindergarten.bulk");

	Kindergarten << "Kindergarten_ID|KAddress|City|Postcode\n";
	for (int i = 0; i < KINDERGARTENS; i++)
	{
		id = i + 1;
		address = getAddress();
		city = getCity();
		postcode = to_string(randNumber(40, 99)) + "-" + to_string(randNumber(100, 400));
		students = NULL;
		Kindergarten << id << "|" << address << "|" << city << "|" << postcode << "\n";
	}
	Kindergarten.close();
}

void createParentBulk()
{
	int id;
	string email, phone, PESEL;
	ofstream Parent, Parent2;
	Parent.open("Parent.bulk");
	Parent2.open("Parent2.bulk");

	Parent << "Parent_ID|Email|PhoneNumber|PESEL\n";
	Parent2 << "Parent_ID|Email|PhoneNumber|PESEL\n";
	for (int i = 0; i < PARENTS; i++)
	{
		id = i + 1;
		email = getEmail();
		phone = randPhone();
		PESEL = elements.PESELs[randNumber(0, PERSONS - 1)];
		Parent << id << "|" << email << "|" << phone << "|" << PESEL << "\n";
		Parent2 << id << "|" << email << "|" << phone << "|" << PESEL << "\n";
	}
	Parent.close();
	for (int i = 0; i < PARENTSV2; i++)
	{
		id = i + 1;
		email = getEmail();
		phone = randPhone();
		PESEL = elements.PESELs[randNumber(0, PERSONS - 1)];
		Parent2 << id << "|" << email << "|" << phone << "|" << PESEL << "\n";
	}
	Parent2.close();
}

void createStudentBulk()
{
	int id, group, parentId, kindergartenId, IsCurrent;
	string PESEL;
	ofstream Student, Student2;
	Student.open("Student.bulk");
	Student2.open("Student2.bulk");

	Student << "Student_ID|GroupName|IsCurrent|PESEL|Parent_ID|Kindergarten_ID\n";
	Student2 << "Student_ID|GroupName|IsCurrent|PESEL|Parent_ID|Kindergarten_ID\n";
	for (int i = 0; i < STUDENTS; i++)
	{
		id = i + 1;
		group = randNumber(1, GROUPS);
		PESEL = elements.PESELs[randNumber(0, PERSONS - 1)];
		parentId = randNumber(1, PARENTS);
		kindergartenId = randNumber(1, KINDERGARTENS);
		elements.StudentKindergarten[i] = kindergartenId;
		IsCurrent = randNumber(0, 1);
		Student << id << "|" << group << "|" << IsCurrent << "|" << PESEL << "|" << parentId << "|" << kindergartenId << "\n";
		if (IsCurrent == 1)
			IsCurrent = randNumber(0, 1);
		Student2 << id << "|" << group << "|" << IsCurrent << "|" << PESEL << "|" << parentId << "|" << kindergartenId << "\n";
	}
	Student.close();
	for (int i = 0; i < STUDENTSV2; i++)
	{
		id = STUDENTS + i + 1;
		group = randNumber(1, GROUPS);
		PESEL = elements.PESELs[randNumber(0, PERSONS - 1)];
		parentId = randNumber(1, PARENTS);
		kindergartenId = randNumber(1, KINDERGARTENS);
		elements.StudentKindergarten[STUDENTS + i] = kindergartenId;
		IsCurrent = randNumber(0, 1);
		Student2 << id << "|" << group << "|" << IsCurrent << "|" << PESEL << "|" << parentId << "|" << kindergartenId << "\n";
	}
	Student2.close();
}

void createMealBulk()
{
	int id, kindergartenId;
	string date, first, second;
	ofstream Meal, Meal2;
	Meal.open("Meal.bulk");
	Meal2.open("Meal2.bulk");
	Meal << "Meal_ID|Meal_Date|FirstCourse|SecondCourse|Kindergarten_ID\n";
	Meal2 << "Meal_ID|Meal_Date|FirstCourse|SecondCourse|Kindergarten_ID\n";
	for (int i = 0; i < MEALS; i++)
	{
		id = i + 1;
		date = randDate(2019, 2020);
		first = getMeal();
		second = getMeal();
		elements.datesList.push_back(date);
		kindergartenId = randNumber(1, KINDERGARTENS);
		elements.KindergartenMeals[kindergartenId - 1].push_back(id);
		elements.kindergarten.push_back(kindergartenId);
		Meal << id << "|" << date << "|" << first << "|" << second << "|" << kindergartenId << "\n";
		Meal2 << id << "|" << date << "|" << first << "|" << second << "|" << kindergartenId << "\n";
	}
	Meal.close();
	for (int i = 0; i < MEALSV2; i++)
	{
		id = MEALSV2 + i + 1;
		date = randDate(2021, 2022);
		first = getMeal();
		second = getMeal();
		elements.datesList2.push_back(date);
		kindergartenId = randNumber(1, KINDERGARTENS);
		elements.KindergartenMeals2[kindergartenId - 1].push_back(id);
		elements.kindergarten2.push_back(kindergartenId);
		Meal2 << id << "|" << date << "|" << first << "|" << second << "|" << kindergartenId << "\n";
	}
	Meal2.close();
}

void createEatingBulk()
{
	int mealId, studentId;
	ofstream Eating, Eating2;
	Eating.open("Eatings.bulk");
	Eating2.open("Eatings2.bulk");
	Eating << "Meal_ID|Student_ID\n";
	Eating2 << "Meal_ID|Student_ID\n";
	for (int i = 0; i < EATINGS; i++)
	{

		studentId = randNumber(1, STUDENTS);       //Student's kindergarten ID
		mealId = elements.KindergartenMeals[elements.StudentKindergarten[studentId - 1] - 1]
			[randNumber(0, elements.KindergartenMeals[elements.StudentKindergarten[studentId - 1] - 1].size()-1)];
		Eating << mealId << "|" << studentId << "\n";
		Eating2 << mealId << "|" << studentId << "\n";
	}
	Eating.close();
	for (int i = 0; i < EATINGSV2; i++)
	{
		studentId = randNumber(1, STUDENTS + STUDENTSV2);
		mealId = elements.KindergartenMeals2[elements.StudentKindergarten[studentId - 1] - 1]
			[randNumber(0, elements.KindergartenMeals2[elements.StudentKindergarten[studentId - 1] - 1].size()-1)];
		Eating2 << mealId << "|" << studentId << "\n";
	}
	Eating2.close();
}

string getMaleName()
{
	fstream file("mnames.txt");

	GotoLine(file, randNumber(1, 1000));

	string line;
	file >> line;
	return line;
}

string getFemaleName()
{
	fstream file("fnames.txt");

	GotoLine(file, randNumber(1, 1000));

	string line;
	file >> line;
	return line;
}

string getSurname()
{
	fstream file("surnames.txt");

	GotoLine(file, randNumber(1, 500));

	string line;
	file >> line;
	return line;
}

string getCity()
{
	fstream file("cities.txt");

	GotoLine(file, randNumber(1, 1000));

	string line;
	file >> line;
	return line;
}

string getAddress()
{
	fstream file("streets.txt");

	GotoLine(file, randNumber(1, 250));

	string line, number;
	file >> line;

	number = " " + to_string(randNumber(1, 99));
	return line + number;
}

string getEmail()
{
	fstream file("emails.txt");

	GotoLine(file, randNumber(1, 250));

	string line, number;
	file >> line;
	return line;
}

string getMeal()
{
	fstream file("meals.txt");

	GotoLine(file, randNumber(1, 130));

	string line, number;
	file >> line;
	return line;
}

int main()
{

	srand((unsigned)time(NULL));

	elements.KindergartenMeals = new vector <int>[KINDERGARTENS];
	elements.KindergartenMeals2 = new vector <int>[KINDERGARTENS];
	elements.StudentKindergarten = new int[STUDENTSV2 + STUDENTS];

	createPersonBulk();
	createKindergartenBulk();
	createParentBulk();
	createStudentBulk();
	createMealBulk();
	createEatingBulk();
	createExcel();

	elements.PESELs.~vector();
	elements.datesList.~vector();
	elements.datesList2.~vector();
	elements.kindergarten.~vector();
	elements.kindergarten2.~vector();
	for (int i = 0; i < KINDERGARTENS; i++)
	{
		elements.KindergartenMeals[i].~vector();
		elements.KindergartenMeals2[i].~vector();
	}
	delete[] elements.StudentKindergarten;
	delete[] elements.KindergartenMeals;
	delete[] elements.KindergartenMeals2;

	return 0;
}