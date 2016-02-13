


\connect pie_three_valued_logic;


/*
write a SQL statement that returns nonapartment addresses only.
*/

select * from Address where apartment IS NULL or apartment = '';
