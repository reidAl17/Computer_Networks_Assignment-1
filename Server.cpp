#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Make sure build environment links to Winsock library file
#pragma comment(lib, "Ws2_32.lib")


// Define default global constants
#define BUFFERSIZE 256
#define DATAFILENAME "dataFile.txt"
#define IPADDRESS "127.0.0.1"
#define GOODMSG "good"
#define BADMSG "invalid"
#define DEFAULTPORT 6000


// Function to close the specified socket and perform DLL cleanup (WSACleanup)
void cleanup(SOCKET socket);
void updateFile(char* machineID, int serialNumber, bool activation);

int main(int argc, char* argv[])
{
	int port;

	// If user types in a port number on the command line use it,
	// otherwise, use the default port number
	if (argc > 1)
		port = atoi(argv[1]);
	else
		port = DEFAULTPORT;
	string machineIDstring;
	char machineID[20] = "abd";
	int serialNumber = 122;
	bool activation = true;

	updateFile(machineID, serialNumber, activation);
	return 0;
}


void cleanup(SOCKET socket)
{
	if (socket != INVALID_SOCKET)
		closesocket(socket);

	WSACleanup();
}

void updateFile(char* machineID, int serialNumber, bool activation)
{
	
	if (activation)
	{
		std::ofstream dataFile;
		dataFile.open("dataFile.txt", std::ofstream::out | std::ofstream::app);
		dataFile << serialNumber;
		dataFile << "\n";
		dataFile << machineID;
		dataFile << "\n";
		dataFile.close();
	}
}