select distinct b.user_id, b.product_id
from (
    select user_id, product_id, sales_date
    from online_sale
) as a, online_sale as b
where a.user_id = b.user_id and a.product_id = b.product_id and a.sales_date < b.sales_date
order by b.user_id asc, b.product_id desc;