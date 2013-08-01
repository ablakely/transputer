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
		}

		long lastReadTime;
		byte MacAddr[];
		IPAddress ip;
		EthernetServer srv;
		void readSensors();
		void handleClient();
		void sendJSONData();
};

#endif
