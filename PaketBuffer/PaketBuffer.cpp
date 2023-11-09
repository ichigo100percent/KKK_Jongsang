#include "PaketBuffer.h"
#include <iostream>

using namespace std;

class IPPacket final
{
public:
	IPPacket(int id) :mId(id) {}
	int getId() const { return mId; }

private:
	int mId;
};

int main()
{
	PacketBuffer<IPPacket> ipPackets(3);

	//패킷 네 개를 추가한다.
	for (int i = 1; i <= 4; ++i)
	{
		if (!ipPackets.bufferPacket(IPPacket(i)))
		{
			cout << "Packet " << i << " dropped(queue is full)." << endl;
		}
	}

	while (true)
	{
		try
		{
			IPPacket packet = ipPackets.getNextPacket();
			cout << "Processing packet " << packet.getId() << endl;
		}
		catch (const out_of_range)
		{
			cout << "Queue is empty." << endl;
			break;
		}
	}

	return 0;
}
