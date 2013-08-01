#ifndef SERVER_H
#define SERVER_H

#if defined(ARDUINO) && ARDUINO > 18
#include <SPI.h>
#endif
#include <Ethernet.h>

class Server {
	public:
		void begin();
		void  poll();

	private:
		struct SensorsData {
			float OilPressure;
		};

		void handleClient();
		void sendJSONData(EthernetClient client);
		byte MacAddr[];
		long lastReadTime;
		IPAddress ip;
		SensorsData sensors_vals;
		SensorsData readSensors();
		EthernetServer srv;
};

#endif
