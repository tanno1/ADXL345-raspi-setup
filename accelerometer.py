#Noah Tanner
#Accelerometer script
#October 2022

#Import Packages
import time 
import board
import busio
import adafruit_adxl34x

#use busio library to prep I2C connection
i2c = busio.I2C(board.SCL, board.SDA)

#Instatntiate the ADXL345 library into accelerometer obj
accelerometer = adafruit_adxl34x.ADXL345(i2c)
#Enable freefall detection
accelerometer.enable_freefall_detection(threshold=10, time=25)
#Motion detection event
accelerometer.enable_motion_detection(threshold=18)
#Tap detection event
accelerometer.enable_tap_detection(tap_count=1, threshold=20, duration=50, latency=20, window=255)

#Infinite loop to print out the accelerometer data
while True:
	print("%f %f %f"%accelerometer.acceleration)
	print("Dropped: %s"%accelerometer.events['freefall'])
	print("Tapped: %s"%accelerometer.events['tap'])
	print("Motion detected: %s"%accelerometer.events['motion'])
	time.sleep(.5)
