select yearstable.t||'0s',count(*) as cnt from 
( select distinct(date_year/10) as t from  release_info
where date_year  is not null and date_year >= 1900
order by t desc ) yearstable inner join release_info
on release_info.date_year/10 =  yearstable.t
where release_info.release in (select id from release where release.status=1)
group by yearstable.t
order by cnt desc,yearstable.t desc;
