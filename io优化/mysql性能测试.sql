SELECT id, name, value
FROM xingnengtest.deviceattr
--  性能测试
-- 插入随机数据


use test1
 
drop table if exists device,attr,deviceattr;

drop function if exists rand_name;
drop function if exists rand_value;
drop function if exists rand_num;
drop function if exists rand_creator;
drop procedure if exists insert_devattr;
drop procedure if exists insert_dev;
 
create table device    
(
id int primary key,
name varchar(40),
type varchar(40),    
aquired int,
groupname varchar(40),
creator varchar(40)
);  
 
 
create table attr
(
id int primary key,
name varchar(40)
);
 
 
create table deviceattr
(
id int,
name varchar(40),
value varchar(40)
);
 
delimiter //
 
create function rand_creator()
returns varchar(20)
begin
declare return_str varchar(20) default 'aronhe';
declare n int default 0;
set n = floor(rand()*10);
case n
when 0 then set return_str = 'aronhe';
when 1 then set return_str = 'eeelin';
when 2 then set return_str = 'shadowyang';
when 3 then set return_str = 'luzhao';
when 4 then set return_str = 'tommyzhang';
when 5 then set return_str = 'pillarzou';
when 6 then set return_str = 'allenpan';
when 7 then set return_str = 'beyondli';
when 8 then set return_str = 'minshi';
when 9 then set return_str = 'bingchen';
else set return_str = 'joyhu';
end case;
return return_str;
end//
 
create function rand_num()
returns int
begin
declare n int default 0;
set n = floor(rand()*100);
return n;
end//
 
create function rand_value()
returns varchar(10)
begin
declare return_str varchar(10) default 'false';
declare n int default 0;
set n = floor(rand()*10);
case
when n<5 then set return_str = 'false';
when n>5 then set return_str = 'true';
else set return_str = 'true';
end case;
return return_str;
end//
 
create function rand_name()
returns varchar(20)
begin
declare return_str varchar(20) default '';
set return_str = concat('attr',floor(rand()*200));
return return_str;
end//
 
create procedure insert_devattr(in start int,in max int)
begin
declare i int default 0;
repeat
set i=i+1;
insert into deviceattr values(rand_num(),rand_name(),rand_value());
until i =max
end repeat;
end//
 
create procedure insert_dev(in start int,in max int)
begin
declare i int default 10;
repeat
set i=i+1;
insert into device values(i,concat('runner',floor(rand()*100)),'pc',floor(rand()*2),'PCQQ',rand_creator());
until i =max
end repeat;
end//
 
call insert_devattr(0,4000)//
call insert_dev(11,100)//



-- 50客户端  每个100次查询  统计结果
mysqlslap   -uroot -p123456 --create-schema=xingnengtest --query="select id from deviceattr where name='attr10' group by id;" -c 50 -i 100



-- 测试基准    
x=客户端数量   相同查询条数的情况下   y=查询所用的时间

