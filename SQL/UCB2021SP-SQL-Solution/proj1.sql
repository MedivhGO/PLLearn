-- Before running drop any existing views
DROP VIEW IF EXISTS q0;
DROP VIEW IF EXISTS q1i;
DROP VIEW IF EXISTS q1ii;
DROP VIEW IF EXISTS q1iii;
DROP VIEW IF EXISTS q1iv;
DROP VIEW IF EXISTS q2i;
DROP VIEW IF EXISTS q2ii;
DROP VIEW IF EXISTS q2iii;
DROP VIEW IF EXISTS q3i;
DROP VIEW IF EXISTS q3ii;
DROP VIEW IF EXISTS q3iii;
DROP VIEW IF EXISTS q4i;
DROP VIEW IF EXISTS q4ii;
DROP VIEW IF EXISTS q4iii;
DROP VIEW IF EXISTS q4iv;
DROP VIEW IF EXISTS q4v;

-- Question 0
CREATE VIEW q0(era)
AS
   select MAX(era)
   from pitching
;

-- Question 1i
CREATE VIEW q1i(namefirst, namelast, birthyear)
AS
  select namefirst,namelast,birthyear 
  from people 
  where weight > 300
;

-- Question 1ii
CREATE VIEW q1ii(namefirst, namelast, birthyear)
AS
  select namefirst,namelast,birthyear
  from people
  where namefirst like '% %'
  order by namefirst,namelast asc
;

-- Question 1iii
CREATE VIEW q1iii(birthyear, avgheight, count)
AS
select birthyear,avg(height),count(*)
from people
group by birthyear 
order by birthyear asc
;

-- Question 1iv
CREATE VIEW q1iv(birthyear, avgheight, count)
AS
select birthyear,avg(height) as h,count(*)
from people
group by birthyear 
having h > 70
order by birthyear asc
;

-- Question 2i
CREATE VIEW q2i(namefirst, namelast, playerid, yearid)
AS
select t1.namefirst,t1.namelast,t1.playerid,t2.yearid
from people t1 inner join halloffame t2
on t1.playerid = t2.playerid
where t2.inducted = 'Y'
order by t2.yearid desc,t1.playerid asc
;

-- Question 2ii
CREATE VIEW q2ii(namefirst, namelast, playerid, schoolid, yearid)
AS
select p.nameFirst,p.nameLast ,p.playerID ,c2.schoolID ,h.yearid 
from (people p inner join halloffame h on p.playerID = h.playerID ) 
inner join collegeplaying c2 on p.playerID = c2.playerid 
where h.inducted = 'Y' and c2.schoolID in (select schoolID from schools s2 where schoolState='CA')
order by h.yearid desc,c2.schoolID asc ,p.playerID asc
;

-- Question 2iii
CREATE VIEW q2iii(playerid, namefirst, namelast, schoolid)
AS
select p.playerID ,p.nameFirst,p.nameLast,h.schoolID 
from (people p left join collegeplaying h on p.playerID = h.playerID) INNER join halloffame h2 
on p.playerID = h2.playerID 
where h2.inducted = 'Y'
order by p.playerID desc,h.schoolID asc
;

-- Question 3i
CREATE VIEW q3i(playerid, namefirst, namelast, yearid, slg)
AS
select p.playerid,p.nameFirst,p.nameLast,b.yearID, ROUND(( ((b.H-b.H2B-b.H3B-b.HR)+2*b.H2B+3*b.H3B+4*b.HR)*1.0 / b.AB),4) as slg
from  people p inner join batting b ON p.playerID = b.playerID
where b.AB > 50
order by slg desc,b.yearID asc,p.playerID asc
limit 10
;

-- Question 3ii
CREATE VIEW q3ii(playerid, namefirst, namelast, lslg)
AS
select p.playerid,p.nameFirst,p.nameLast, 
ROUND(
((sum(b.H)-sum(b.H2B)-sum(b.H3B)-sum(b.HR))+2*sum(b.H2B)+3*sum(b.H3B)+4*sum(b.HR))*1.0 / sum(b.AB)
,4) as lslg
from  people p inner join batting b ON p.playerID = b.playerID
group by p.playerID
having sum(b.AB) > 50
order by lslg desc,b.yearID asc,p.playerID asc
limit 10
;

-- Question 3iii
CREATE VIEW q3iii(namefirst, namelast, lslg)
AS
with tmp as (
select p.playerID playerid, p.namefirst namefirst ,p.namelast namelast,ROUND(((sum(b.H)-sum(b.H2B)-sum(b.H3B)-sum(b.HR))+2*sum(b.H2B)+3*sum(b.H3B)+4*sum(b.HR))*1.0 / sum(b.AB),4) as lslg
from people p inner join batting b on p.playerID  = b.playerID
group by p.playerID
having sum(b.AB) > 50
)
select namefirst,namelast,lslg from tmp 
where lslg > (select lslg from tmp where playerid='mayswi01')
;

-- Question 4i
CREATE VIEW q4i(yearid, min, max, avg)
AS
select yearid,min(salary),max(salary),Round(avg(salary),4)
from salaries
group by yearid 
order by yearid asc
;


-- Helper table for 4ii
DROP TABLE IF EXISTS binids;
CREATE TABLE binids(binid);
INSERT INTO binids VALUES (0), (1), (2), (3), (4), (5), (6), (7), (8), (9);

-- Question 4ii
CREATE VIEW q4ii(binid, low, high, count)
AS
select row_number() over (order by Score)-1 as binid,Score-3249250 low, Score high,count(*) count from (
SELECT CASE 
WHEN  salary  >= 507500.0 AND  salary  < 3756750.0 THEN 3756750.0
WHEN  salary  >= 3756750.0 AND  salary  < 7006000.0 THEN 7006000.0
WHEN  salary  >= 7006000.0 AND  salary  < 10255250.0 THEN 10255250.0
WHEN  salary  >= 10255250.0 AND  salary  < 13504500.0 THEN 13504500.0
WHEN  salary  >= 13504500.0 AND  salary  < 16753750.0 THEN 16753750.0
WHEN  salary  >= 16753750.0 AND  salary  < 20003000.0 THEN 20003000.0
WHEN  salary  >= 20003000.0 AND  salary  < 23252250.0 THEN 23252250.0
WHEN  salary  >= 23252250.0 AND  salary  < 26501500.0 THEN 26501500.0
WHEN  salary  >= 26501500.0 AND  salary  < 29750750.0 THEN 29750750.0
WHEN   salary  >= 29750750.0 THEN 33000000.0
ELSE NULL END as Score from salaries where yearid=2016 )
group by Score
order by low
;

-- Question 4iii
CREATE VIEW q4iii(yearid, mindiff, maxdiff, avgdiff)
AS
with tmp as (select yearid,min(salary) mins,max(salary) maxs ,avg(salary) avgs
from salaries s
group by yearid)
select t1.yearid,t1.mins-t2.mins,t1.maxs-t2.maxs,ROUND(t1.avgs-t2.avgs,4) from 
tmp t1 inner join tmp t2
on t1.yearid = t2.yearid+1
;

-- Question 4iv
CREATE VIEW q4iv(playerid, namefirst, namelast, salary, yearid)
AS
select t1.playerid,p.nameFirst ,p.nameLast ,t1.salary,t1.yearid
from (
select playerid,yearID,salary from salaries s where salary 
in (select max(salary) from salaries s where yearID = 2001)
and yearID = 2001
union 
select playerid,yearID,salary from salaries s where salary
in (select max(salary) from salaries s where yearID = 2000 )
and yearID  = 2000
order by yearID asc) t1 inner join people p 
on t1.playerid = p.playerID
;
-- Question 4v
CREATE VIEW q4v(team, diffAvg) AS
select allstarfull.teamid ,ROUND(max(s.salary)-min(s.salary),4) as avgdiff
from allstarfull  inner join salaries s
on allstarfull.team_ID = s.team_ID and allstarfull.playerID = s.playerID 
where s.yearID=2016
group by allstarfull.team_ID 
;

