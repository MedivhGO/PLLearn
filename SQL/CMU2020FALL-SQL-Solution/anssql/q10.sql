/*
Concat all dubbed names of The Beatles using comma-separated values(like "Beetles, fab four").
Details: Find all dubbed names of artist "The Beatles" in artist_alias and order them by id (ascending). 
Print a single string containing all the dubbed names separated by commas.

Hint: You might find CTEs useful.
*/


with seqnumanddata as ( 
select row_number() over ( order by artist_alias.id asc) as seq, artist_alias.name  as name from 
artist_alias inner join artist
on artist_alias.artist = artist.id
where artist.name = 'The Beatles')
select group_concat(seqnumanddata.name , ', ')
from seqnumanddata
order by seqnumanddata.seq asc;

