--============== один-ко-многим ==============

--DROP TABLE IF EXISTS users;
--DROP TABLE IF EXISTS roles;

--CREATE TABLE roles (
--	id int PRIMARY KEY IDENTITY(1,1),
--	title varchar(50) NOT NULL
--);

--CREATE TABLE users (
--	id int PRIMARY KEY IDENTITY(1,1),
--	email varchar(50) NOT NULL,
--	role_id int NOT NULL,

--	CONSTRAINT FK_users_role FOREIGN KEY (role_id) REFERENCES roles(id)
--);


--============== один-к-одному ==============
--DROP TABLE IF EXISTS clients;
--DROP TABLE IF EXISTS profiles;

--CREATE TABLE profiles (
--	id int PRIMARY KEY IDENTITY(1,1),
--	photo_path varchar(256) NULL
--);

--CREATE TABLE clients (
--	id int PRIMARY KEY IDENTITY(1,1),
--	email varchar(50) UNIQUE NOT NULL,
--	profile_id int UNIQUE,

--	CONSTRAINT FK_clients_role FOREIGN KEY(profile_id) REFERENCES profiles(id)
--);


--DROP TABLE IF EXISTS clients;
--DROP TABLE IF EXISTS profiles;

--CREATE TABLE clients (
--	id int PRIMARY KEY IDENTITY(1,1) NOT NULL,
--	email varchar(50) UNIQUE NOT NULL
--);

--CREATE TABLE profiles (
--	id int PRIMARY KEY NOT NULL,
--	photo_path varchar(256) NULL,

--	CONSTRAINT FK_profiles_client FOREIGN KEY(id) REFERENCES clients(id)
--);



-- ============= многие-ко-многим ==============

--CREATE TABLE teachers (
--	id int PRIMARY KEY IDENTITY(1,1),
--	full_name varchar(50) NOT NULL,
--);

--CREATE TABLE groups (
--	id int PRIMARY KEY IDENTITY(1,1),
--	title varchar(50) NOT NULL,
--);

--CREATE TABLE groups_teachers (
--	teacher_id int NOT NULL,
--	group_id int NOT NULL,

--	CONSTRAINT PK_groups_teachers PRIMARY KEY(teacher_id, group_id),

--	CONSTRAINT FK_groups_teachers_teacher FOREIGN KEY(teacher_id) REFERENCES teachers(id),
--	CONSTRAINT FK_groups_teachers_groups FOREIGN KEY(group_id) REFERENCES groups(id)
--);

--INSERT INTO teachers (full_name)
--	VALUES 
--		('aaa'),
--		('bbb'),
--		('ccc');

--INSERT INTO groups (title)
--	VALUES 
--		('000'),
--		('111'),
--		('222'),
--		('333'),
--		('444'),
--		('555');

--INSERT INTO groups_teachers (teacher_id, group_id)
--VALUES
--	(1, 2),
--	(1, 3),
--	(1, 5),
--	(2, 3),
--	(3, 3);

---- ¬ывести группы препода 1
--SELECT g.title
--FROM groups_teachers gt LEFT JOIN groups g ON gt.group_id = g.id
--WHERE gt.teacher_id = 1;




--DROP TABLE groups_teachers;
--DROP TABLE groups;
--DROP TABLE teachers;



--CREATE TABLE teachers (
--	id int PRIMARY KEY IDENTITY(1,1),
--	full_name varchar(50) NOT NULL,
--);

--CREATE TABLE groups (
--	id int PRIMARY KEY IDENTITY(1,1),
--	title varchar(50) NOT NULL,
--);

--CREATE TABLE groups_teachers_statuses (
--	id int PRIMARY KEY IDENTITY(1,1),
--	title varchar(50) NOT NULL,
--	description varchar(256) NULL
--);

--CREATE TABLE groups_teachers (
--	id int IDENTITY(1,1) NOT NULL,
--	teacher_id int NOT NULL,
--	group_id int NOT NULL,
--	start_date date NOT NULL,
--	end_date date NULL,
--	status_id int NOT NULL

--	CONSTRAINT PK_groups_teachers PRIMARY KEY(id),

--	CONSTRAINT FK_groups_teachers_teacher FOREIGN KEY(teacher_id) REFERENCES teachers(id),
--	CONSTRAINT FK_groups_teachers_groups FOREIGN KEY(group_id) REFERENCES groups(id),
--	CONSTRAINT FK_groups_teachers_status FOREIGN KEY(status_id) REFERENCES groups_teachers_statuses(id)
--);

--INSERT INTO teachers (full_name)
--	VALUES 
--		('aaa'),
--		('bbb'),
--		('ccc');

--INSERT INTO groups (title)
--	VALUES 
--		('000'),
--		('111'),
--		('222'),
--		('333'),
--		('444'),
--		('555');

--INSERT INTO groups_teachers_statuses (title)
--VALUES
--	('non_active'),
--	('active'),
--	('pending');

--INSERT INTO groups_teachers (teacher_id, group_id, start_date, end_date, status_id)
--VALUES
--	(1, 2, '20241101', NULL, 2);
----
--UPDATE groups_teachers
--SET 
--	end_date = GETDATE(),
--	status_id = 1
--WHERE id = 1;

--INSERT INTO groups_teachers (teacher_id, group_id, start_date, end_date, status_id)
--VALUES
--	(3, 2, GETDATE(), NULL, 3);



-- Ё «ќ“»„≈— »≈ —Ћ”„ј» :-))) --

--CREATE TABLE categories (
--	id int PRIMARY KEY IDENTITY(1,1),
--	title varchar(50) NOT NULL,
--	parent_id int NULL,

--	CONSTRAINT FK_categories_parent FOREIGN KEY (parent_id) REFERENCES categories(id)
--);

--INSERT INTO categories(title, parent_id)
--VALUES
--	('A', NULL),
--	('B', NULL),
--	('C', NULL);

--INSERT INTO categories(title, parent_id)
--VALUES
--	('A1', 1),
--	('A2', 1),
--	('A3', 1);




-- ќрганизовать таблицы дл€ соц.сети, где одни пользователи могут подписыватьс€ на других пользователей

--DROP TABLE users;

--CREATE TABLE users (
--	id int PRIMARY KEY IDENTITY(1,1) NOT NULL,
--	username varchar(50) UNIQUE NOT NULL,
--	email varchar(50) UNIQUE NOT NULL,
--	age tinyint NULL
--);

--CREATE TABLE subscribes (
--	author_id int NOT NULL,
--	subscriber_id int NOT NULL,

--	CONSTRAINT PK_subscribes PRIMARY KEY(author_id, subscriber_id),

--	CONSTRAINT FK_subscribers_author FOREIGN KEY(author_id) REFERENCES users(id),
--	CONSTRAINT FK_subscribers_subscriber FOREIGN KEY(subscriber_id) REFERENCES users(id),

--	CONSTRAINT CK_different_ids CHECK(author_id <> subscriber_id)
--);
