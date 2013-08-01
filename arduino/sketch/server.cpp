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
		readSensors();


