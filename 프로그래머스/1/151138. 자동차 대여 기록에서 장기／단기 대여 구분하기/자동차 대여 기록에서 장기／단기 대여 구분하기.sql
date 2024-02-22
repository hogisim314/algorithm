-- 코드를 입력하세요
SELECT history_id, car_id, DATE_FORMAT(start_date,'%Y-%m-%d') AS START_DATE,
        DATE_FORMAT(end_date,'%Y-%m-%d') AS END_DATE,
IF(DATEDIFF(END_DATE, START_DATE)+1 >= 30, "장기 대여","단기 대여") AS RENT_TYPE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
where year(start_date)=2022 and month(start_date)=9
order by history_id desc;