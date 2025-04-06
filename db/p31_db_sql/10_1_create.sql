CREATE database ddl_db;

use ddl_db;

CREATE TABLE users (
	id int PRIMARY KEY IDENTITY(1,1),
	username varchar(50) NOT NULL,
	email varchar(50) UNIQUE NOT NULL,
	age tinyint NULL
);

CREATE TABLE images (
	id				int				PRIMARY KEY IDENTITY(1,1),
	title			varchar(50)		NULL,
	description		varchar(250)	NULL,
	publish_date	smalldatetime	NOT NULL,
	link			varchar(128)	NOT NULL,
	user_id			int				NOT NULL
);

INSERT users (username, email)
VALUES
	('vasia', 'vasia@mail.com'),
	('petya', 'petya@mail.com');

INSERT INTO images (publish_date, link, user_id)
VALUES
	('20250225', 'http://lskjdlf.com/lkjsd.jpg', 1),
	('20250225', 'http://lskjdlf.com/lkjsd.jpg', 2),
	('20250225', 'http://lskjdlf.com/lkjsd.jpg', 2),
	('20250225', 'http://lskjdlf.com/lkjsd.jpg', 1),
	('20250225', 'http://lskjdlf.com/lkjsd.jpg', 3);


--UPDATE users
--SET email = NULL
--WHERE id = 1;