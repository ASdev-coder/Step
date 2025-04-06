-- COUNT(*)
-- COUNT(<field>)
-- COUNT(DISTINCT <field>)
-- SUM(<field>)
-- AVG(<field>)
-- MIN(<field>)
-- MAX(<field>)

--SELECT
--	COUNT(*) [Общее кол-во строк],
--	COUNT(department_id) [Кол-во не NULL department_id],
--	COUNT(DISTINCT department_id) [Кол-во уникальных не NULL department_id],
--	COUNT(DISTINCT position_id) [Кол-во уникальных не NULL position_id],
--	COUNT(bonus_percent),
--	MAX(bonus_percent),
--	MIN(bonus_percent),
--	SUM(salary / 100 * bonus_percent) [Сумма денег на премии],
--	AVG(salary / 100 * bonus_percent) [Средняя сумма премии],
--	AVG(salary) [Средняя ЗП]
--FROM employees;



--SELECT
--	COUNT(*) [Общее кол-во строк],
--	COUNT(department_id) [Кол-во не NULL department_id],
--	COUNT(DISTINCT department_id) [Кол-во уникальных не NULL department_id],
--	COUNT(DISTINCT position_id) [Кол-во уникальных не NULL position_id],
--	COUNT(bonus_percent),
--	MAX(bonus_percent),
--	MIN(bonus_percent),
--	SUM(salary / 100 * bonus_percent) [Сумма денег на премии],
--	AVG(salary / 100 * bonus_percent) [Средняя сумма премии],
--	AVG(salary) [Средняя ЗП]
--FROM employees
--WHERE department_id = 3;



--SELECT
--	SUM(bonus_percent),
--	SUM(ISNULL(bonus_percent, 0)),
--	AVG(bonus_percent),
--	AVG(ISNULL(bonus_percent, 0))
--FROM employees;


--SELECT
--	ISNULL(SUM(salary), 0)
--FROM employees
--WHERE department_id = 100;