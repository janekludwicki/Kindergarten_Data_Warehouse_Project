USE KindergartenDW
GO

INSERT INTO Kindergarten VALUES ('between 20 and 50');
INSERT INTO Kindergarten VALUES ('more than 100')

INSERT INTO Date VALUES ('2010-01-14', 2010, 'January', 'Monday', 1, 1, 'Winter')
INSERT INTO Date VALUES ('2017-07-02', 2017, 'June', 'Wednesday', 7, 1, 'Summer')

INSERT INTO Meal VALUES ('Burakowa', 'Schabowy')
INSERT INTO Meal VALUES ('Rosol', 'Ziemnioki')

INSERT INTO Student VALUES (14567913468, 1, 'Jan Kowalski', 'less than 6')
INSERT INTO Student VALUES (10465973165, 0, 'Jan Ludwicki', 'more than 8')

INSERT INTO Meal_serving VALUES (1, 1, 1, 2, 300, 117, 792, 417)
INSERT INTO Meal_serving VALUES (2, 2, 2, 1, 400, 517, 1102, 617)

INSERT INTO Eating_a_meal VALUES (1, 2)
INSERT INTO Eating_a_meal VALUES (1, 1)
INSERT INTO Eating_a_meal VALUES (2,1)