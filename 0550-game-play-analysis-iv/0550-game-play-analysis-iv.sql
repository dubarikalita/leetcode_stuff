# Write your MySQL query statement below
select round(avg(flag),2) as fraction
from(
    select
        a.player_id,
        max(
            case when a.event_date=date_add(first_login,interval 1 day) then 1 else 0 end
    ) as flag
    from Activity a
    join (
            select
                player_id,
                min(event_date) as first_login
            from Activity
            group by player_id
        ) f
    on a.player_id=f.player_id
    group by a.player_id
)t