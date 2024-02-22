-- 코드를 입력하세요
SELECT ugu.user_id, nickname, 
concat_ws(' ',city, street_address1, street_address2) as "전체주소",
concat_ws("-",substr(TLNO,1,3), substr(TLNO,4,4),substr(TLNO,8,4)) as "전화번호"
from used_goods_board as ugb
join used_goods_user as ugu
on ugu.user_id = ugb.writer_id
group by ugu.user_id
having count(ugu.user_id) >=3
order by ugu.user_id desc;