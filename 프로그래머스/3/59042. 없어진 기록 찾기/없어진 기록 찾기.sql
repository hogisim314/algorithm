select o.animal_id as animal_id, o.name as name
from animal_outs as o
left join animal_ins as i
on o.animal_id = i.animal_id
where i.datetime is null