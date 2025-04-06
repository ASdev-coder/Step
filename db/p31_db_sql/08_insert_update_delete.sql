
-- INSERT --

-- INSERT [INTO] <table> ([<fields...>]) VALUES (<values>...)
-- INSERT [INTO] <table> ([<fields...>]) SELECT...


--INSERT INTO albums (title, creation_date, user_id, rate)
--	VALUES ('bali_1', GETDATE(), 10, 5);

--INSERT INTO albums (title, creation_date, user_id, rate)
--	VALUES 
--		('bali_2', GETDATE(), 10, 5),
--		('bali_3', GETDATE(), 10, 5),
--		('bali_4', GETDATE(), 10, 5);


-- Отключение контроля изменения первичного ключа с автоинкрементом
--SET IDENTITY_INSERT albums ON;

--INSERT INTO albums (id, title, creation_date, user_id, rate)
--	VALUES (100, 'bali_10', GETDATE(), 10, 5);

--SET IDENTITY_INSERT albums OFF;

--INSERT INTO albums (title, creation_date, user_id, rate)
--	VALUES ('bali_12', GETDATE(), 10, 5);


-- Вернуть при вcтавке id
--INSERT INTO albums (title, creation_date, user_id, rate)
--	OUTPUT inserted.id
--	VALUES ('bali_15', GETDATE(), 10, 5);


--INSERT INTO temp (user_nickname, user_email)
--SELECT nickname, email
--FROM users
--ORDER BY email;


-- CTE (Common table expression)
--WITH src AS (
--	SELECT nickname, email
--	FROM users
--	-- ORDER BY email  -- TODO: ???
--)

--INSERT INTO temp
--SELECT *
--FROM src;



--- UPDATE ---
--UPDATE albums
--SET rate = 6
--WHERE rate = 5;

--UPDATE albums
--SET deleted_at = GETDATE()
--WHERE id = 2;


--- DELETE ---
--DELETE FROM temp
--WHERE id = 209;

--DELETE FROM temp;

--DELETE TOP(50)
--FROM temp;

--DELETE TOP(50) PERCENT
--FROM temp;

-- Удалние всех записей со сбросом счётчика
-- TRUNCATE TABLE temp;




