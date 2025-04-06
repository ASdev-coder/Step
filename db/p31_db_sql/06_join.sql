--- JOIN types ---
-- JOIN (INNER JOIN)
-- LEFT JOIN (LEFT OUTER JOIN)
-- RIGHT JOIN (RIGHT OUTER JOIN)
-- FULL JOIN (FULL OUTER JOIN)
-- CROSS JOIN (CROSS OUTER JOIN)


-- LEFT JOIN --
--SELECT *
--FROM employees e LEFT JOIN departments d ON e.department_id = d.id;

--SELECT *
--FROM departments d LEFT JOIN employees e ON d.id = e.department_id;

------- RIGHT JOIN
--SELECT *
--FROM employees e RIGHT JOIN departments d ON e.department_id = d.id;

--SELECT *
--FROM departments d RIGHT JOIN employees e ON d.id = e.department_id;


------- JOIN (INNER JOIN)
--SELECT *
--FROM employees e JOIN departments d ON e.department_id = d.id;

--SELECT *
--FROM departments d JOIN employees e ON d.id = e.department_id;


---------- FULL JOIN ----
--SELECT *
--FROM employees e FULL JOIN departments d ON e.department_id = d.id;

--SELECT *
--FROM departments d FULL JOIN employees e ON d.id = e.department_id;


-------- CROSS JOIN ----
--SELECT *
--FROM employees e CROSS JOIN departments d;

--SELECT *
--FROM departments d CROSS JOIN employees e;





-- TASK
-- Вернуть кол-во служащих по должностям
-- Position | Count

--SELECT
--	p.title [Position],
--	COUNT(e.id) [Count]
--FROM positions p LEFT JOIN employees e ON p.id = e.position_id
--GROUP BY p.id, p.title



-- TASK
-- Вернуть служащих, которые родились в 1982 с информацией об их должности и отделе

--SELECT
--	e.id,
--	e.name,
--	e.birthday,
--	p.title [Position],
--	ISNULL(d.title, 'no_department') [Department]
--FROM employees e
--	LEFT JOIN positions p ON e.position_id = p.id
--	LEFT JOIN departments d ON e.department_id = d.id
--WHERE YEAR(birthday) = 1982


-- TASK
-- Для каждого отдела вывести сотрудника, нанятого последним

-- 1.неполное решение
--SELECT
--	d.title,
--	MAX(hire_date)
--FROM departments d LEFT JOIN employees e ON d.id = e.department_id
--GROUP BY d.id, d.title


--SELECT
--	d.id, d.title, e.id, e.name, e.hire_date
--FROM employees e 
--		JOIN (
--			SELECT
--				MAX(id) maxEmpId
--			FROM employees
--			GROUP BY department_id
--		) lastEmp ON e.id = lastEmp.maxEmpId
--		LEFT JOIN departments d ON e.department_id = d.id



-- TASK
-- Посчитать кол-во сотрудников по каждому отделу для каждой должности
-- Department | Position | Count

--SELECT
--	d.title,
--	p.title,
--	COUNT(e.id)
--FROM departments d
--	CROSS JOIN positions p
--	LEFT JOIN employees e ON e.department_id = d.id AND e.position_id = p.id
--GROUP BY d.id, d.title, p.id, p.title


--SELECT
--	d.title,
--	p.title,
--	ISNULL(e.users_count, 0)
--FROM departments d
--	CROSS JOIN positions p
--	LEFT JOIN (
--		SELECT
--			department_id,
--			position_id,
--			COUNT(id) [users_count]
--		FROM employees
--		GROUP BY department_id, position_id
--	) e ON e.department_id = d.id AND e.position_id = p.id



-- WHERE instead JOIN -- :-(
--SELECT *
--FROM employees e, departments d
--WHERE e.department_id = d.id




--SELECT
--	u.nickname,
--	COUNT(a.id) [Count]
--FROM albums a LEFT JOIN users u ON a.user_id = u.id
--GROUP BY u.id, u.nickname
--ORDER BY Count DESC;

