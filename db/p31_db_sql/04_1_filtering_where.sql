--SELECT id, last_name, first_name, salary
--FROM employees
--WHERE department_id = 3;

-- ORDER BY			3
-- TOP				4
-- DISTINCT			2
-- FROM + WHERE		1



-- Отобрать топ-менеджеров / не топ-менеджеров
--SELECT *
--FROM employees
---- WHERE manager_id IS NULL;
--WHERE manager_id IS NOT NULL;


-- Посчитать бонусы всех работников у которых определён bonus_percent
--SELECT *
--FROM employees
---- WHERE NOT(bonus_percent <= 0 OR bonus_percent IS NULL);
---- WHERE bonus_percent > 0 AND bonus_percent IS NOT NULL;
--WHERE ISNULL(bonus_percent, 0) <> 0;



--==================== BETWEEN / IN / LIKE ========================

--SELECT id, name, salary
--FROM employees

-- WHERE salary >= 2000 AND salary <= 3000
-- WHERE salary BETWEEN 2000 AND 3000;

-- WHERE NOT(salary >= 2000 AND salary <= 3000)
-- WHERE salary NOT BETWEEN 2000 AND 3000;

--WHERE salary BETWEEN 2000 AND 3000
--		AND department_id = 3;


-- WHERE department_id = 3 OR department_id = 4;
-- WHERE department_id IN (3, 4)

-- WHERE department_id NOT IN (3, 4)

-- Отобрать тех, кто работает в отделе 3, 4 или отдел не определён
-- NULL в операторе IN  ПЛОХО !!! :-(((
-- WHERE department_id IN (3, 4, NULL)								-- :-(((
-- WHERE department_id IN (3, 4) OR department_id IS NULL			-- :-)))
-- WHERE ISNULL(department_id, -1) IN (3, 4, -1)					-- :-)))

--WHERE department_id NOT IN (1) AND department_id IS NOT NULL;		-- :-)


-- %	_	[abc]	[a-c]	[^a-c]

--SELECT *
--FROM employees

-- WHERE last_name LIKE N'П%'
-- WHERE last_name LIKE N'%ов'
-- WHERE last_name LIKE N'%ре%'
-- WHERE email LIKE '%.com'
--WHERE email LIKE '%.c__'
-- WHERE email LIKE '%.[cbr]__'
-- WHERE email LIKE '%.[^a-c]__'
-- WHERE LOWER(email) LIKE '%.c__'			-- :-)))

-- WHERE LOWER(email) LIKE '!%_!_' ESCAPE '!'


--SELECT *
--FROM employees

-- Которые родились в 1982 г
-- WHERE YEAR(birthday) = 1982

-- У которых сегодня день рождения
-- WHERE MONTH(birthday) = MONTH(GETDATE()) AND DAY(birthday) = DAY(GETDATE())



--DECLARE @d date = '20001223'
--SELECT DATEDIFF(year, @d, GETDATE());


-- declare @d date = DATEFROMPARTS(2000, 12, 23);


-- SELECT CONVERT(DATE, '20001223', 104);






