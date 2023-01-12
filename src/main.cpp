#include <iostream>
#include "client.h"
#include "hotel.h"

int main(int argc, char const *argv[])
{

	Client dg("dginhac","Dominique","Ginhac");
	std::cout << dg << std::endl;
	Chambre c1("1",Type::Single,10);
	std::cout << c1 << std::endl;
	Hotel h1("HOTEL1");
	h1.addRoom(c1);
	h1.displayRooms();
	return 0;
}