-- 코드를 입력하세요
select book.category, sum(book_sales.sales) as total_sales
from book
left join book_sales on book.book_id = book_sales.book_id
where book_sales.sales_date between '2022-01-01' and '2022-01-31'
group by book.category
order by book.category