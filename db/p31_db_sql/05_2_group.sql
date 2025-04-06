
--SELECT
--	department_id,
--	COUNT(id) AS [count]
--FROM employees
--GROUP BY department_id;


--SELECT
--	department_id,
--	COUNT(id) AS [count],
--	COUNT(position_id),
--	COUNT(DISTINCT position_id)
--FROM employees
--GROUP BY department_id;



--SELECT
--	'const string',
--	department_id,
--	position_id,
--	COUNT(id) AS [count],
--	COUNT(position_id),
--	COUNT(DISTINCT position_id),				-- :-)))  Всегда 1
--	SUM(salary)
--FROM employees
--GROUP BY department_id, position_id;



-- Посчитать кол-во сотрудников в разрезе года рождения
--SELECT
--	-- birthday,			-- ERROR
--	YEAR(birthday),
--	COUNT(id)
--FROM employees
--GROUP BY YEAR(birthday);

------------
-- Посчитать кол-во сотрудников в разрезе отдела, родившихся в разных десятилетиях
-- dep_id | < 1970 | 1970 - 1980 | 1980 - 1990 | 1990 - 2000 | 2000 - 2010|
--SELECT
--	department_id,
--	SUM(IIF(YEAR(birthday) < 1970, 1, 0)) AS [<1970],
--	SUM(IIF(YEAR(birthday) BETWEEN 1970 AND 1980, 1, 0)) AS [1970-1980],
--	SUM(IIF(YEAR(birthday) BETWEEN 1980 AND 1990, 1, 0)) AS [1980-1990]
--FROM employees
--GROUP BY department_id
--------------


----------- HW
-- Получить сводные данные в разрезе отделов, посчитать сумму ЗП в разбивке по должностям
-- Department name | Bookers | Directors | Developers | Teamleads | SalarySum |
-------------------------------------------------------------------------------
-- Administration  | 10      | 0         | 20         | 0         | 30
-- Accounting      |
-- IT              |
-- ...

--SELECT
--    CASE
--		WHEN department_id = 1 THEN 'Administration'
--		WHEN department_id = 2 THEN 'Accounting'
--		WHEN department_id = 3 THEN 'IT'
--		ELSE 'NONE'
--	END AS Departments,
 
--	SUM(IIF(position_id = 1, salary, 0)) AS Bookers,
--	SUM(IIF(position_id = 2, salary, 0)) AS Director,
--	SUM(IIF(position_id = 3, salary, 0)) AS Developer,
--	SUM(IIF(position_id = 4, salary, 0)) AS Teamlead,
 
--	SUM(salary) AS SalarySum
 
--FROM employees
--GROUP BY department_id

---------------------------------------





------------------- HAVING ------------------

--SELECT
--	department_id,
--	SUM(salary) salary_sum
--FROM employees
--GROUP BY department_id
--HAVING SUM(salary) > 6000


--SELECT
--	department_id,
--	SUM(salary) salary_sum
--FROM employees
--GROUP BY department_id
--HAVING SUM(salary) > 6000 AND COUNT(id) > 1


-- :-(((

--SELECT
--	department_id,
--	SUM(salary) AS [Salary Sum]
--FROM employees
--GROUP BY department_id
--HAVING department_id IN (1, 3)

-- :-)))

--SELECT
--	department_id,
--	SUM(salary) AS [Salary Sum]
--FROM employees
--WHERE department_id IN (1, 3)
--GROUP BY department_id


----------------------------------------------

-- DISTINCT						5
-- TOP							7
-- SELECT					4
-- FROM				0
-- WHERE			1
-- GROUP BY				2
-- HAVING				3
-- ORDER BY						6






