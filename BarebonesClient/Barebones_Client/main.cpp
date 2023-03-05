#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void main()
{
	//turkce karakterler
	unsigned char chari = 141;
	unsigned char charo = 148;
	unsigned char charu = 129;
	unsigned char charc = 135;
	unsigned char chars = 159;
	unsigned char charg = 167;
	unsigned char charI = 152;
	unsigned char charO = 153;
	unsigned char charU = 154;
	unsigned char charC = 128;
	unsigned char charS = 158;
	unsigned char charG = 166;
	unsigned char para = 36;
	//turkce karakterler son

	string ipAddress = "127.0.0.1";			// sunucu ip adresi
	int port = 54000;						// sunucu tarafindan dinlenen port

	// Initialize WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		cerr << "Winsock ba" << chars << "lat" << chari << "lamad" << chari << ", Err #" << wsResult << endl;
		return;
	}

	// Create socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cerr << "soket yaratilamadi, Err #" << WSAGetLastError() << endl;
		WSACleanup();
		return;
	}

	// Fill in a hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Connect to server
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		cerr << "sunucuya baglanilamiyor, Err #" << WSAGetLastError() << endl;
		closesocket(sock);
		WSACleanup();
		return;
	}

	// Do-while loop to send and receive data
	char buf[4096];
	string userInput;
	string amount;
	string accNum;
	system("title BANKA Client");
	int kontrol = 0;

	do
	{
		cout << "TCP Banka sistemi - Sinan SINIK taraf" << chari << "ndan geli" << chars << "tirildi - Beytullah G" << charO << "L taraf" << chari << "ndan d" << charu << "zenlendi" << endl;
		cout << "kullan" << chari << "c" << chari << " ad" << chari << "n" << chari << "z" << chari << " giriniz : ";
		getline(cin, userInput);


		if (userInput.size() > 0)		// Make sure the user has typed in something
		{
			// Send the text
			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{
				// Wait for response
				ZeroMemory(buf, 4096);
				int bytesReceived = recv(sock, buf, 4096, 0);
				if (bytesReceived > 0)
				{

					if (string(buf, 0, bytesReceived) == "1") {
						kontrol = 1;
						system("cls");
						cout << charS << "ifre giri" << chars << " ekran" << chari << "na y" << charo << "nlendiriliyorsunuz..." << endl;
						system("pause");
						system("cls");
					}
					else {
						cout << "Kullan" << chari << "c" << chari << " ad" << chari << " yanl" << chari << chars << ", tekrar deneyiniz..." << endl;
						system("pause");
						system("cls");
					}
				}
			}
		}

	} while (kontrol == 0);
	kontrol = 0;
	do
	{
		cout << charS << "ifrenizi Giriniz : ";
		getline(cin, userInput);


		if (userInput.size() > 0)
		{

			int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != SOCKET_ERROR)
			{

				ZeroMemory(buf, 4096);
				int bytesReceived = recv(sock, buf, 4096, 0);
				if (bytesReceived > 0)
				{

					if (string(buf, 0, bytesReceived) != "0") {
						cout << "Giri" << chars << " ba" << chars << "ar" << chari << "l" << chari << ". " << charI << chars << "lem men" << charu << "s" << charu << "ne y" << charo << "nlendiriliyorsunuz..." << endl;
						system("pause");
						system("cls");
						kontrol = 1;
						cout << "HO" << charS << "GELD" << charI << "N" << charI << "Z" << endl;
						cout << "Bank Name - Account Number - Balance " << endl;
						cout << string(buf, 0, bytesReceived) << endl;
					}
					else {
						cout << charS << "ifre yanl" << chari << chars << ", Tekrar deneyiniz." << endl;
					}
				}
			}
		}

	} while (kontrol == 0);
	kontrol = 0;
	do
	{

		cout << "1 - Hesab" << chari << "n" << chari << "za Para yat" << chari << "r" << chari << "n > " << endl;
		cout << "2 - Hesab" << chari << "n" << chari << "zdan Para " << charC << "ekin > " << endl;
		cout << "3 - Havale / EFT > " << endl;
		cout << "4 - " << charC << "IKI" << charS << " > " << endl;
		cout << "L" << charu << "tfen yapmak istedi" << charg << "iniz i" << chars << "lem numaras" << chari << "n" << chari << " giriniz : ";
		getline(cin, userInput);
		int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
		if (userInput == "1")
		{
			cout << "Hesaba yat" << chari << "r" << chari << "lacak para miktar" << chari << " : ";
			getline(cin, amount);
			int sendResult = send(sock, amount.c_str(), amount.size() + 1, 0);
			ZeroMemory(buf, 4096);
			int bytesReceived = recv(sock, buf, 4096, 0);
			if (bytesReceived > 0)
			{
				cout << "BANKA> " << string(buf, 0, bytesReceived) << endl;

			}
		}
		else if (userInput == "2")
		{
			cout << "Hesaptan " << charc << "ekilecek para miktar" << chari << " : ";
			getline(cin, amount);
			int sendResult = send(sock, amount.c_str(), amount.size() + 1, 0);
			ZeroMemory(buf, 4096);
			int bytesReceived = recv(sock, buf, 4096, 0);
			if (bytesReceived > 0)
			{
				cout << "BANKA> " << string(buf, 0, bytesReceived) << endl;

			}
		}
		else if (userInput == "3")
		{
			cout << "Transfer yap" << chari << "lacak hesap no : ";
			getline(cin, accNum);
			int sendResult = send(sock, accNum.c_str(), accNum.size() + 1, 0);
			ZeroMemory(buf, 4096);
			int bytesReceived = recv(sock, buf, 4096, 0);
			if (bytesReceived > 0)
			{
				if (string(buf, 0, bytesReceived) == "1")
				{
					cout << "Dikkat! Ba" << chars << "ka bir bankaya transfer yap" << chari << "yorsunuz, 10 TL transfer " << charu << "creti kesilecektir.";
					cout << "Para miktar" << chari << "n" << chari << " giriniz : ";
					getline(cin, amount);
					int sendResult = send(sock, amount.c_str(), amount.size() + 1, 0);
					ZeroMemory(buf, 4096);
					int bytesReceived = recv(sock, buf, 4096, 0);
					if (bytesReceived > 0)
					{
						cout << "BANKA> " << string(buf, 0, bytesReceived) << endl;

					}
				}
				else
				{
					cout << "BANKA> " << string(buf, 0, bytesReceived) << endl;
				}

			}
		}
		else if (userInput == "4") {
			kontrol = 1;
		}

	} while (kontrol == 0);

	// Gracefully close down everything
	closesocket(sock);
	WSACleanup();
}