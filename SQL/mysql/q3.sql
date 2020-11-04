select area.name ,count(*) as t from
artist inner join area
on artist.area = area.id
where artist.begin_date_year < 1850
group by area.id
order by t desc
limit 10;
