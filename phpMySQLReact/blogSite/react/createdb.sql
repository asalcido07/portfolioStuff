drop table users;

create table users ( 
    username varchar(255) primary key,
    password varchar(255),
    click_count int not null
);

insert into users values ('alice', '1234', 0);
insert into users values ('bob', '1234', 0);
insert into users values ('claire', '1234', 0);
