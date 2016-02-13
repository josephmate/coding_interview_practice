


\connect pie_max_no_agg;


/* version using sort */
select  num from TEST
	ORDER BY num DESC
	limit 1;


/* version using join */

/*
num
1
2
3

catesian product
a b
1 1
2 1
3 1
1 2
2 2
3 2
1 3
2 3
3 3

a < b
a b
1 2
1 3
2 3

The greatest value does not appear in 'a' because the greatest value is not less than any value (because it is the greatest).

*/

select distinct num from Test
	where num not in
	(
	select lesser.num from Test lesser
		inner join Test greater on
			lesser.num < greater.num
	);
