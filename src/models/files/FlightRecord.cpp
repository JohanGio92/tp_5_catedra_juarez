#include "FlightRecord.hpp"


const std::string FlightRecord::FILE_NAME = "./src/models/files/airports.txt";

FlightRecord::FlightRecord() {
	entryRoute.open(FILE_NAME.c_str());
	assert(entryRoute.is_open());
}

void FlightRecord::toTree(AvlTree<Airport>& airportsTree) {
	while(!entryRoute.eof()){
		Airport airport;
		airport.read(entryRoute);
		airportsTree.insert(airport);
	}
}

FlightRecord::~FlightRecord() {
	entryRoute.close();
}

