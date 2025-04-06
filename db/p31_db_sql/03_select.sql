--SELECT [DISTINCT] [TOP] <список столбцов>
--[FROM] <источник>
--[WHERE] <условие фильтрации>
--[ORDER BY] <выражение условия сортировки>
--...

USE p31_company_db;


--SELECT *
--FROM employees;

--SELECT id
--FROM employees;


--SELECT 
--	5000 / 100 * 17,
--	SIN(0) + COS(0),
--	SYSDATETIME();


--SELECT
--	123 / 10,
--	123.0 / 10,
--	123 / 10.0;


--SELECT
--	id,
--	id / 100,
--	CAST(id AS float) / 100,
--	CONVERT(float, id) / 100,
--	id / 100.0
--FROM employees;


--SELECT *							-- :-(((
--FROM employees;

--SELECT id, email, birthday			-- :-)))
--FROM employees;


--SELECT e.email
--FROM employees e;



--- DISTINCT ---
--SELECT DISTINCT salary
--FROM employees;


-- Вывести информацию о том, в каких отделах какие должности изпользуются в принципе
--SELECT DISTINCT department_id, position_id
--FROM employees;


--SELECT
--	last_name + ' ' + first_name,
--	hire_date,
--	salary
--FROM employees;


--SELECT
--	last_name + ' ' + first_name AS ФИО,
--	hire_date AS [Дата приёма],
--	salary AS ЗП
--FROM employees;


--SELECT
--	last_name + ' ' + middle_name AS ФИО,
--	ISNULL(last_name, '') + ' ' + ISNULL(middle_name, '') AS ФИО,
--	CONCAT(last_name, ' ', middle_name) AS ФИО
--FROM employees;



--SELECT
--	id,
--	name,
--	salary / 100 * bonus_percent AS Result_1,
--	ISNULL(salary, 0) / 100 * ISNULL(bonus_percent, 0) AS Result_2,
--	COALESCE(salary, 0) / 100 * COALESCE(bonus_percent, extra_percent, 0) AS Result_3
--FROM employees;



--=========================== ORDER BY =================================
--SELECT
--	last_name,
--	first_name,
--	salary
--FROM employees
--ORDER BY last_name DESC;	-- ASC(по возрастанию) DECS(по убыванию)



--SELECT
--	last_name,
--	first_name,
--	salary
--FROM employees
--ORDER BY salary, last_name DESC;



--SELECT
--	last_name,
--	first_name
--FROM employees
--ORDER BY salary;




-- Неоднозначность результата (одинаковая salary ???)
--SELECT TOP 3
--	id,
--	last_name,
--	first_name,
--	salary
--FROM employees
--ORDER BY salary DESC




-- Однозначность результата :-)
--SELECT TOP 3
--	id,
--	last_name,
--	first_name,
--	salary
--FROM employees
--ORDER BY
--	salary DESC,
--	id DESC;




--SELECT
--	first_name,
--	last_name
--FROM employees
--ORDER BY CONCAT(first_name, last_name)



-- в ORDER BY можно использовать только поля из SELECT DISTINCT
--SELECT DISTINCT
--	last_name,
--	first_name,
--	salary
--FROM employees
--ORDER BY salary DESC




--SELECT bonus_percent
--FROM employees
--ORDER BY bonus_percent;

-- :-)))
--SELECT bonus_percent
--FROM employees
--ORDER BY ISNULL(bonus_percent, 100);


--======================== TOP ========================
--SELECT TOP 2
--	*
--FROM employees;

--SELECT TOP 25 PERCENT
--	*
--FROM employees;



--SELECT TOP 2 WITH TIES
--	id,
--	first_name,
--	last_name,
--	salary
--FROM employees
--ORDER BY salary;



-- Вывести 2 минимальных значения ЗП
--SELECT DISTINCT TOP 2
--	salary
--FROM employees
--ORDER BY salary;





