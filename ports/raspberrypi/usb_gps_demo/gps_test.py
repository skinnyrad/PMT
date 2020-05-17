import gpsd, time
gpsd.connect()
time.sleep(2)

while True:
	current_cord = gpsd.get_current()
	print("You are standing at",current_cord.position())
	print("You are traveling",current_cord.speed()*1.15078," MPH.")
	print("If you want to see yourself on a map, go here: ",current_cord.map_url())
	print(" ")
	time.sleep(1)
