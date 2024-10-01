select round(SUM(DAILY_FEE)/COUNT(*)) as AVERAGE_FEE
from car_rental_company_car
where car_type='SUV'