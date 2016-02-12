
DROP DATABASE IF EXISTS pie_employee_db;

CREATE DATABASE pie_employee_db;

\connect pie_employee_db;

/* Note that psql doesn't support an int(4) datatype */
CREATE TABLE COMPANY ( 
	companyName CHAR(30),
	id integer PRIMARY KEY
);




CREATE TABLE EMPLOYEESHIRED ( 
	id integer REFERENCES Company(id),
	numHired integer,
	fiscalQuarter integer,
	PRIMARY KEY (id, fiscalQuarter)
);


INSERT INTO COMPANY (companyName, id) VALUES ('Hillary Plumbing', 6);
INSERT INTO COMPANY (companyName, id) VALUES ('John Lawn Company', 9);
INSERT INTO COMPANY (companyName, id) VALUES ('Dave Cookie Company', 19);
INSERT INTO COMPANY (companyName, id) VALUES ('Jane Electricity', 3);
INSERT INTO COMPANY (companyName, id) VALUES ('Edge Case', 1);
      
INSERT INTO EMPLOYEESHIRED (id, numHired, fiscalQuarter) VALUES ( 3, 3, 3);
INSERT INTO EMPLOYEESHIRED (id, numHired, fiscalQuarter) VALUES ( 3, 2, 4);
INSERT INTO EMPLOYEESHIRED (id, numHired, fiscalQuarter) VALUES (19, 4, 1);
INSERT INTO EMPLOYEESHIRED (id, numHired, fiscalQuarter) VALUES ( 6, 2, 1);
INSERT INTO EMPLOYEESHIRED (id, numHired, fiscalQuarter) VALUES ( 1, 0, 3);





