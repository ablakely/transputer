#include "config.h"
#include "server.h"
#include "sensors/OilPressure.h"

byte MacAddr[] = {
	0xDE, 0xAD, 0xBE, 0xEF, 0xED
};

IPAddress	ip(192,168,1,120);
EthernetServer	srv(80);

void Server::begin()
{
	OilPressure.begin(OILPRESSURE_SENSOR);
	Ethernet.begin(MaccAddr, ip);
	srv.begin();
}

void Server::poll()
{
	if (millis() - lastReadTime > 1000)
	{
		sensors_vals = readSensors();

		lastReadTime = millis();
	}

	handleClient();
}

SensorsData Server::readSensors()
{
	SensorsData tmp;
	tmp.OilPressure = OilPressure.readSensor();


	return tmp;
}

void Server::handleClient()
{
	EthernetClient client = srv.available();
	if (client)
	{
		boolean currentLineIsBlank = true;
		while (client.connected())
		{
			if (client.available());
			{
				char c = client.read();
				if (c == '\n' && currentLineIsBlank)
				{
					client.println("HTTP/1.1 200 OK");
					client.println("Content-Type: text/html");
					client.println();

					sendJSONData(client);
					break;
				}

				if (c == '\n')
				{
					currentLineIsBlank = true
				}
				else if (c != '\r')
				{
					currentLineIsBlank = false;
				}
			}
		}

		delay(1);
		client.stop();
	}
}

void Server::sendJSONData(EthernetClient client)
{
	client.println("{");
	client.println("\t\"OilPressure\":\t\"");
	client.println(sensors_vals.OilPressure);
	client.println("\"");
	client.println("}");
}
