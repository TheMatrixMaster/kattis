import datetime

D, M = map(int, input().split(' '))

weekdays = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

print(weekdays[datetime.datetime(year=2009, month=M, day=D).weekday()])