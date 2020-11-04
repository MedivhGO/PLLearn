select  artist.name,count(distinct(artist_alias.name)) as t
from artist inner join artist_alias
on artist.id = artist_alias.artist
where artist.area  in  (select id from area where name='United Kingdom') and artist.begin_date_year > 1950 
group by artist.id
order by t desc
limit 10;
