
DROP DATABASE IF EXISTS pie_simple_sql;

CREATE DATABASE pie_simple_sql;

\connect pie_simple_sql;

CREATE TABLE Olympics ( city char(16), year integer);
/* Note that psql doesn't support an int(4) datatype */
