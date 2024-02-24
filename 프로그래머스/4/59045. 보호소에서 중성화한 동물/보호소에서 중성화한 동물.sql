-- 코드를 입력하세요
SELECT ins.animal_id, ins.animal_type, ins.name
from animal_ins as ins
join animal_outs as outs
on ins.animal_id = outs.animal_id
where ins.sex_upon_intake like "%Intact%" and (outs.sex_upon_outcome like "%Spayed%" or outs.sex_upon_outcome like "%Neutered%")
order by ins.animal_id