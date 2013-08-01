#ifndef OILPRESSURE_H
#define OILPRESSURE_H

class OilPressure {
	public:
		float readSensor();
		void  begin(int pin);
	private:
		int sensor_pin;
};

#endif
