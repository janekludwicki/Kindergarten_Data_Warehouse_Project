--CREATE DATABASE KIND

use KIND
CREATE TABLE Person
(PESEL BIGINT,
DateOfBirth DATE,
Name VARCHAR(20),
Surname VARCHAR(20),
Gender CHAR(1),
Registered_address VARCHAR(50),
City VARCHAR(30),
Postcode CHAR(6),
PRIMARY KEY (PESEL));

CREATE TABLE Kindergarten
(Kindergarten_ID INT,
KAddress VARCHAR(50),
City VARCHAR(30),
Postcode CHAR(6),
PRIMARY KEY (Kindergarten_ID))

CREATE TABLE Parent
(Parent_ID INT,
Email VARCHAR(40),
PhoneNumber CHAR(9),
PRIMARY KEY (Parent_ID),
PESEL BIGINT FOREIGN KEY REFERENCES Person(PESEL))

CREATE TABLE Student
(Student_ID INT,
GroupName VARCHAR(6),
IsCurrent BIT,
PESEL BIGINT FOREIGN KEY REFERENCES Person(PESEL),
Parent_ID INT FOREIGN KEY REFERENCES Parent(Parent_ID),
Kindergarten_ID INT FOREIGN KEY REFERENCES	Kindergarten(Kindergarten_ID),
PRIMARY KEY (Student_ID))

CREATE TABLE Meal
(Meal_ID INT,
Meal_Date DATE,
FirstCourse VARCHAR(50),
SecondCourse VARCHAR(50),
Kindergarten_ID INT FOREIGN KEY REFERENCES Kindergarten(Kindergarten_ID),
PRIMARY KEY (Meal_ID))

CREATE TABLE Eating
(Meal_ID INT FOREIGN KEY REFERENCES Meal(Meal_ID),
Student_ID INT FOREIGN KEY REFERENCES Student(Student_ID))
