
-- TASK
-- Посчитать кол-во служащих по должностям
-- Position | Count

--SELECT
--	p.title,
--	COUNT(e.id)
--FROM positions p LEFT JOIN employees e ON p.id = e.position_id
--GROUP BY p.id, p.title;


--SELECT
--	p.id,
--	p.title,
--	(
--		SELECT COUNT (e.id)
--		FROM employees e
--		WHERE e.position_id = p.id
--	)
--FROM positions p;



------ EXISTS / NOT EXISTS
-- TASK
-- Показать пользователей, которые создавали альбомы

--SELECT DISTINCT u.nickname
--FROM albums a LEFT JOIN users u ON a.user_id = u.id;

--SELECT u.nickname
--FROM albums a LEFT JOIN users u ON a.user_id = u.id
--GROUP BY u.id, u.nickname


--SELECT u.nickname
--FROM users u
--WHERE EXISTS (
--	SELECT a.id
--	FROM albums a
--	WHERE a.user_id = u.id
--);


-- TASK
-- Показать пользователей, которые не создавали альбомы

--SELECT u.nickname
--FROM users u
--WHERE NOT EXISTS (
--	SELECT a.id
--	FROM albums a
--	WHERE a.user_id = u.id
--);




-- TASK 
-- Показать пользователей, у которых больше 1 альбома (2 и более)

--SELECT u.nickname
--FROM users u
--WHERE (
--	SELECT COUNT(a.id)
--	FROM albums a
--	WHERE a.user_id = u.id
--) > 1;


--SELECT u.nickname
--FROM users u
--WHERE EXISTS (
--	SELECT a.user_id
--	FROM albums a
--	WHERE a.user_id = 2
--	GROUP BY a.user_id
--	HAVING COUNT(a.user_id) > 1
--);




-- ANY / ALL --
-- TASK
-- Вывести пользователей, у которых есть альбомы с рейтингом 5
--SELECT u.id, u.email
--FROM users u
--WHERE u.id = ANY (
--	SELECT a.user_id
--	FROM albums a
--	WHERE rate = 5
--);


--SELECT u.id, u.email
--FROM users u
--WHERE u.id IN (
--	SELECT a.user_id
--	FROM albums a
--	WHERE rate = 5
--);


--SELECT u.id, u.email
--FROM users u
--WHERE EXISTS (
--	SELECT a.id
--	FROM albums a
--	WHERE a.user_id = u.id AND a.rate = 5
--);



-- TASK
-- Отобрать пользователей у которых рейтинг любого альбома больше или равен
-- любому среднему рейтингу альбомов у каждого пользователя

--SELECT u.id, u.email
--FROM albums a LEFT JOIN users u ON a.user_id = u.id
--WHERE ISNULL(a.rate, 0) >= ALL (
--	SELECT AVG(ISNULL(a.rate, 0))
--	FROM albums a
--	GROUP BY a.user_id
--);




-- TASK
-- Выбрать пользователей, у которых есть альбомы с максимальным рейтингом

--SELECT *
--FROM albums a LEFT JOIN users u ON a.user_id = u.id
--WHERE a.rate = (
--	SELECT MAX(rate)
--	FROM albums
--);


--SELECT *
--FROM users u
--WHERE u.id IN (
--	SELECT user_id
--	FROM albums a
--	WHERE a.rate = (
--		SELECT MAX(rate)
--		FROM albums
--	)
--);



-- TASK HW
-- Для каждого отдела вывести сотрудника (-ов), у которого ЗП больше, чем ЗП каждого ОСТАЛЬНОГО сотрудника из этого отдела
-- Отдел | Сотрудник | ...
