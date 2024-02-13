import datetime

# datetime(year, month, day, hour, minute, second)
a = datetime.datetime(2017, 6, 21, 18, 25, 30)
b = datetime.datetime(2017, 5, 16, 8, 21, 10)

# returns a timedelta object
c = a-b 
print('Difference: ', c)

# returns (minutes, seconds)
minutes = divmod(c.total_seconds(), 60) 
print('Total difference in minutes: ', minutes[0], 'minutes',
								minutes[1], 'seconds')

# returns the difference of the time of the day (minutes, seconds)
minutes = divmod(c.seconds, 60) 
print('Total difference in minutes: ', minutes[0], 'minutes',
								minutes[1], 'seconds')
