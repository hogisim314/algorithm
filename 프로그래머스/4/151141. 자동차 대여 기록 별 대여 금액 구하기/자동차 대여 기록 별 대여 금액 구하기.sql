with ninety as 
    (
        select discount_rate
        from car_rental_company_discount_plan
        where duration_type = "90일 이상" and car_type = "트럭"
    ),
    
thirty as 
    (
        select discount_rate
        from car_rental_company_discount_plan
        where duration_type = "30일 이상" and car_type = "트럭"
    ),
seven as 
    (
        select discount_rate
        from car_rental_company_discount_plan
        where duration_type = "7일 이상" and car_type = "트럭"
    )

select history.history_id,
    case 
        when (datediff(history.end_date, history.start_date)+1)>=90
        then floor(car.daily_fee * (1-(select * from ninety)*0.01))*
             (datediff(history.end_date, history.start_date)+1)
        when (datediff(history.end_date, history.start_date)+1)>=30
        then floor(car.daily_fee * (1-(select * from thirty)*0.01))*
             (datediff(history.end_date, history.start_date)+1)
        when (datediff(history.end_date, history.start_date)+1)>=7
        then floor(car.daily_fee * (1-(select * from seven)*0.01))*
             (datediff(history.end_date, history.start_date)+1)
        else (datediff(history.end_date, history.start_date)+1) * car.daily_fee
    end as fee
from car_rental_company_car as car
join car_rental_company_rental_history as history
on car.car_id = history.car_id
where car.car_type = "트럭"
order by fee desc, history.history_id desc;