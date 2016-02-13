
DROP DATABASE IF EXISTS pie_three_valued_logic;

CREATE DATABASE pie_three_valued_logic;

\connect pie_three_valued_logic;

/* Note that psql doesn't support an int(4) datatype */
CREATE TABLE Address ( 
	street CHAR(30) NOT NULL,
	apartment CHAR(10),
	city CHAR(40) NOT NULL
);


INSERT INTO Address (street,apartment,city) VALUES ('123 George St.',NULL,'Berlin');
INSERT INTO Address (street,apartment,city) VALUES ('456 Bell St.','Unit 123','Paris');
INSERT INTO Address (street,apartment,city) VALUES ('789 David Ave.','','London');
      
