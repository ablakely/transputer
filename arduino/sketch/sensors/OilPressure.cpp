#include "OilPressure.h"

/*
 * oilPressure.readSensor(int pin)
 *
 * Reads the voltage input from the oil pressure sensor and
 * calculates the measurement then returns the value in PSI.
 *
 * More information on the equation can be found on the wiki's
 * sensors page.
 *
 */

void OilPressure::begin(int pin)
{
	sensor_pin = pin;
}

float OilPressure::readSensor()
{
	float sensorRaw = (float)analogRead(sensor_pin);
	float pressure  = 0.0;

	pressure = (sensorRaw / 1024.00) * 5; // calculate the actual voltage across the sensor.
	pressure = (-.177 + sqrt(.03133 - (4 * -.0065 * (.052 - pressure)))) / -.013; // get a more accurate reading
	pressure = pressure * 14.7; // convert to PSI

	return pressure;
}
