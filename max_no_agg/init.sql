
DROP DATABASE IF EXISTS pie_max_no_agg;

CREATE DATABASE pie_max_no_agg;

\connect pie_max_no_agg;

/* Note that psql doesn't support an int(4) datatype */
CREATE TABLE Test ( 
	num integer
);


INSERT INTO Test (num) VALUES (5);
INSERT INTO Test (num) VALUES (23);
INSERT INTO Test (num) VALUES (-6);
INSERT INTO Test (num) VALUES (7);
      
