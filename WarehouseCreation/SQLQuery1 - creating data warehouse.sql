USE KindergartenDW
GO

CREATE TABLE Kindergarten
(
	Kindergarten_ID INT IDENTITY(1,1) PRIMARY KEY,
	NoOfStudentsAttendingCategory VARCHAR(20)
);

CREATE TABLE Date
(
	Date_ID INT PRIMARY KEY IDENTITY(1,1),
	Date DATE,
	Year INT,
	Month VARCHAR(10),
	Weekday VARCHAR(10),
	MonthNo INT,
	WeekdayNo INT,
	Season VARCHAR(10)
);

CREATE TABLE Meal
(
	Meal_ID INT IDENTITY(1,1) PRIMARY KEY,
	FirstCourse VARCHAR(50),
	SecondCourse VARCHAR(50)
);

CREATE TABLE Student
(
	Student_ID INT IDENTITY(1,1) PRIMARY KEY,
	PESEL BIGINT,
	IsCurrent BIT, --to jest boolean wg SQL Management Studio, przyjmuje wartoœci 0 lub 1
	NameAndSurname VARCHAR(50),
	AgeCategory VARCHAR(20)
);

CREATE TABLE Meal_serving
(
	MealServing_ID INT IDENTITY(1,1) PRIMARY KEY,
	Meal_ID INT REFERENCES Meal(Meal_ID),
	Kindergarten_ID INT REFERENCES Kindergarten(Kindergarten_ID),
	MealServingDate_ID INT REFERENCES Date(Date_ID),
	NrOfMealsServed INT,
	AmountOfFoodWasted INT,
	AmountOfMoneyInvested INT,
	AmountOfFoodBought INT
);

CREATE TABLE Eating_a_meal
(
	MealServing_ID INT REFERENCES Meal_serving(MealServing_ID),
	Student_ID INT REFERENCES Student(Student_ID),
	PRIMARY KEY(MealServing_ID, Student_ID)
);