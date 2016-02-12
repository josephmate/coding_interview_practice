


\connect pie_employee_db;


/* 
Part i)
Write a SQL statement that returns the names of all the companies that hired
employees in fiscal quarter 4.
 */
select c.companyName from EMPLOYEESHIRED e
inner join company c
on e.id = c.id
where
	    e.fiscalQuarter = 4
	and e.numHired > 0;


/*
Part ii)
Now, using the same schema, write a SQL statement that returns the names of all
companies that did not hire anyone in fiscal quarters 1 through 4.
*/

select c.companyName from COMPANY c
left join EMPLOYEESHIRED e
on e.id = c.id
where
	    e.id IS NULL

UNION 

select c.companyName from COMPANY c
	where c.id in
	(
		select e.id from EMPLOYEESHIRED e
		group by e.id
		having SUM(numHired) = 0
	);

/*
Part iii)
Finally, return the names of all companies and the total number of employees that
each company hired during fiscal quarters 1 through 4.
*/

select 
c.companyName, 
case when totalHired IS NULL THEN 0 ELSE totalHired END as totalHired from COMPANY c
	left join  /* must be left join because one company doesn't have an entry in the table */
	(
		select e.id as id, sum(numHired) as totalHired from EMPLOYEESHIRED e
		group by e.id
	) totals on totals.id = c.id 
	;


