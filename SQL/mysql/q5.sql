select distinct(t.name) from release t
inner join medium m on t.id = m.release
inner join medium_format mf on mf.id = m.format
inner join release_info ri on t.id = ri.release
inner join artist_credit ac on t.artist_credit=ac.id
inner join artist_credit_name acn on ac.id = acn.artist_credit
inner join artist a on a.id = acn.artist
where mf.name like '%Vinyl' and a.name = 'Coldplay'
order by ri.date_year,ri.date_month,ri.date_day;
