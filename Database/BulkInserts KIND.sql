use KIND
GO

BULK INSERT dbo.Person FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Person.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)
BULK INSERT dbo.Parent FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Parent.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)
BULK INSERT dbo.Kindergarten FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Kindergarten.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)
BULK INSERT dbo.Student FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Student.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)
BULK INSERT dbo.Meal FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Meal.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)
BULK INSERT dbo.Eating FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Eatings.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)

use KIND
GO


BULK INSERT dbo.Person FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Person.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)
BULK INSERT dbo.Kindergarten FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Kindergarten.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)
BULK INSERT dbo.Student FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Student2.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)
BULK INSERT dbo.Meal FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Meal2.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)
BULK INSERT dbo.Eating FROM 'C:\Users\MAC JANEK\source\repos\DataGEnerator\Eatings2.bulk' WITH (FIELDTERMINATOR='|', FIRSTROW = 2)