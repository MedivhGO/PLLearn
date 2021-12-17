select work.name , work_type.name from 
work inner join work_type on 
work.type  = work_type.id 
where (work.type,length(work.name)) 
in 
(
	select work.type , max(length((work.name))) from work inner join work_type 
	on work.type = work_type.id group by work.type
)  
order by work.type , work.name;
