SELECT m.rid, SUM(salary) 
FROM monorail m
INNER JOIN assigned a ON(m.rid = a.rid)
INNER JOIN employee e ON(a.eid = e.eid)
WHERE runningrange > 500
GROUP BY m.rid
ORDER BY SUM(salary);
