-- 코드를 입력하세요
SELECT apnt_no, pt_name, patient.pt_no, appointment.mcdp_cd, dr_name, apnt_ymd
from appointment
join patient
on appointment.pt_no = patient.pt_no
join doctor
on doctor.dr_id = appointment.mddr_id
where apnt_ymd like '2022-04-13%' and apnt_cncl_yn = "N"
order by apnt_ymd asc;