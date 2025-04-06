-- ========= PRIMARY KEY ============

-- Определение при объявлении поля
--CREATE TABLE units (
--	id int PRIMARY KEY,
--	...
--);

 -- Определение вне объявления поля
--CREATE TABLE units (
--	id int,
--	title varchar(64),
--	clan varchar(64),
--	--.....

--	CONSTRAINT PK_units_id PRIMARY KEY(id),

--	-- CONSTRAINT PK_units_title_clan PRIMARY KEY(title, clan)

--	-- PRIMARY KEY (title, clan)
--);

-- Добавление
--ALTER TABLE units
--ADD PRIMARY KEY (id);




-- ========= FOREIGN KEY ============

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

--INSERT INTO roles (title)
--VALUES
--	('admin'),
--	('guest'),
--	('author');

--INSERT INTO users(email, role_id)
--VALUES
--	('vasia1@mail.com', 3),
--	('vasia2@mail.com', 1),
--	('vasia3@mail.com', 3);

----DELETE FROM roles					-- ERROR
----WHERE id = 3;





--CREATE TABLE roles (
--	id int PRIMARY KEY IDENTITY(1,1),
--	title varchar(50) NOT NULL
--);

--CREATE TABLE users (
--	id int PRIMARY KEY IDENTITY(1,1),
--	email varchar(50) NOT NULL,
--	--role_id int NOT NULL,
--	--role_id int,
--	role_id int NOT NULL DEFAULT(2)

--	CONSTRAINT FK_users_role FOREIGN KEY (role_id) REFERENCES roles(id)
--		-- ON DELETE NO ACTION				-- Работает по-умолчанию
--		-- ON DELETE CASCADE
--		-- ON DELETE SET NULL
--		-- ON DELETE SET DEFAULT
--);

--INSERT INTO roles (title)
--VALUES
--	('admin'),
--	('guest'),
--	('author');

--INSERT INTO users(email, role_id)
--VALUES
--	('vasia1@mail.com', 3),
--	('vasia2@mail.com', 1),
--	('vasia3@mail.com', 3);

--DELETE FROM roles
--WHERE id = 3;

--DROP TABLE users;
--DROP TABLE roles;







--CREATE TABLE roles (
--	id int PRIMARY KEY,
--	title varchar(50) NOT NULL
--);

--CREATE TABLE users (
--	id int PRIMARY KEY IDENTITY(1,1),
--	email varchar(50) NOT NULL,
--	role_id int NOT NULL,
--	--role_id int,
--	--role_id int NOT NULL DEFAULT(2)

--	CONSTRAINT FK_users_role FOREIGN KEY (role_id) REFERENCES roles(id)
--		-- ON UPDATE NO ACTION				-- Работает по-умолчанию
--		ON UPDATE CASCADE
--		-- ON UPDATE SET NULL
--		-- ON UPDATE SET DEFAULT
--);

--INSERT INTO roles (id, title)
--VALUES
--	(1, 'admin'),
--	(2, 'guest'),
--	(3, 'author');

--INSERT INTO users(email, role_id)
--VALUES
--	('vasia1@mail.com', 3),
--	('vasia2@mail.com', 1),
--	('vasia3@mail.com', 3);

--UPDATE roles
--SET id = 13
--WHERE id = 3;

--DROP TABLE users;
--DROP TABLE roles;




-- ========= NOT NULL ============
--CREATE TABLE permissions (
--	id int PRIMARY KEY IDENTITY(1,1)		NOT NULL,
--	title varchar(50)						NOT NULL,
--	description varchar(250)				NULL
--);

--INSERT INTO permissions (title)
--VALUES
--	('read_posts');

---- Добавление
--UPDATE permissions
--SET description = 'description'
--WHERE description IS NULL;

--ALTER TABLE permissions
--ALTER COLUMN description varchar(250) NOT NULL;

---- Удаление
--ALTER TABLE permissions
--ALTER COLUMN description varchar(250) NULL;





-- ========= UNIQUE ============
----DROP TABLE users;
----DROP TABLE roles;

--CREATE TABLE roles (
--	id int PRIMARY KEY IDENTITY(1,1),
--	title varchar(50) NOT NULL
--);

--CREATE TABLE users (
--	id int IDENTITY(1,1)		NOT NULL,
--	email varchar(50)			NOT NULL,
--	role_id int					NOT NULL,
--	username varchar(50)		NOT NULL,

--	CONSTRAINT PK_users_id		PRIMARY KEY(id),
--	CONSTRAINT UQ_users_email	UNIQUE(email),
--	CONSTRAINT FK_users_role	FOREIGN KEY (role_id) REFERENCES roles(id)
--);

---- Добавление
--ALTER TABLE roles
--ADD CONSTRAINT UQ_roles_title	UNIQUE(title);

---- Удаление
--ALTER TABLE roles
--DROP CONSTRAINT UQ_roles_title;




-- ========= CHECK ============

CREATE TABLE products (
	id int PRIMARY KEY IDENTITY(1,1) NOT NULL,
	title varchar(50) NOT NULL,

	-- price decimal(10, 2)

	-- price decimal(10, 2) CHECK(price > 0)
	
	price decimal(10, 2),
	CONSTRAINT CK_products_price CHECK(price > 0)
);

DROP TABLE products;



CREATE TABLE products (
	id int PRIMARY KEY IDENTITY(1,1) NOT NULL,
	title varchar(50) NOT NULL,

	price decimal(10, 2) CHECK(price > 0) NOT NULL,
	discount_price decimal(10, 2) CHECK(discount_price > 0) NOT NULL,

	CONSTRAINT CK_products_price_discount_price CHECK (discount_price < price)
);

DROP TABLE products;
CREATE TABLE products (
	id int PRIMARY KEY IDENTITY(1,1) NOT NULL,
	title varchar(50) NOT NULL,

	price decimal(10, 2) NOT NULL,
	discount_price decimal(10, 2) NOT NULL,

	CONSTRAINT CK_products_price 
		CHECK (price > 0),
	CONSTRAINT CK_products_price_discount_price 
		CHECK (discount_price > 0 AND discount_price < price)
);

ALTER TABLE products
ADD CONSTRAINT CK_products_title_length CHECK(LEN(title) > 10);
