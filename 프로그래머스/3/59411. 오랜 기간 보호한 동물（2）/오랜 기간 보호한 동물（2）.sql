-- 코드를 입력하세요
SELECT ins.animal_id, ins.name
from animal_outs as outs
join animal_ins as ins
on outs.animal_id = ins.animal_id
order by datediff(outs.datetime, ins.datetime) desc
limit 2;