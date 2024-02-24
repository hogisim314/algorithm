-- 코드를 입력하세요
with maxx as (select member_id, count(member_id) as cnt
                   from rest_review
                        group by member_id
                        order by cnt desc
                        limit 1)

SELECT prof.member_name, review_text, date_format(review_date, '%Y-%m-%d')
from member_profile as prof
join rest_review as rev
on prof.member_id = rev.member_id
where prof.member_id in (select member_id from maxx)
order by review_date asc, review_text asc;