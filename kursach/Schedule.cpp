#include "Header.h"
using namespace role;
void Visitor:: menu_schedule()
{
	system("cls");
	while (1) {
		
		int choice;
		vector<DepartureSchedule> DepartureFlights = readDepartureSchedulefromFile();
		vector<ArrivalSchedule> ArrivalFlights = readArrivalSchedulefromFile();
		cout << "-------�������-------- \n 1-��� ��������� ���������� ������� \n 2-��� ��������� ���������� ������� \n 3-��� ������\n ";
		choice=check::inputNumber(1,3);
		switch (choice) {
		case 1: {
			cout << "���������� �������" << endl;
			printDepartureSchedule(DepartureFlights);
			break;
		}
		case 2: {
			cout << "���������� �������" << endl;
			printArrivalSchedule(ArrivalFlights);
			break;
		}
		case 3: {
			return;
		}
		}
	}
}

vector<DepartureSchedule> Visitor::readDepartureSchedulefromFile()
{
	string filename = "departureschedule.txt";
	vector<DepartureSchedule>  DepartureFlights;
	ifstream inputFile(filename);
	if (inputFile.is_open()) {
		int numberFlight;
		int day, month, year;
		string Destination, status, time, ReceptionDesk, DepartureGate;
		while (inputFile >> numberFlight >> day>>month>>year >> Destination >> status >> time >> ReceptionDesk >> DepartureGate) {
			Flight flight{ numberFlight, day,month,year, Destination, status, time };
			DepartureSchedule depshed;
			depshed.flights.push_back(flight);
			depshed.setReceptionGate(ReceptionDesk);
			depshed.setDepartureGate(DepartureGate);

			DepartureFlights.push_back(depshed);
		}

		inputFile.close();
	}
	else {
		cerr << "������ �������� ����� \"" << filename << "\" ��� ������." << endl;
	}
	
	return DepartureFlights;
}

vector<ArrivalSchedule> Visitor::readArrivalSchedulefromFile()
{
	string filename = "arrivalschedule.txt";
	vector<ArrivalSchedule>  ArrivalFlights;
	ifstream inputFile(filename);
	if (inputFile.is_open()) {
		int numberFlight,day,month,year;
		string date, Destination, status, time, LuggageBelt;
		while (inputFile >> numberFlight >> day>>month>>year >> Destination >> status >> time >> LuggageBelt) {
			Flight flight{ numberFlight, day,month,year, Destination, status, time };
			ArrivalSchedule arrshed;
			arrshed.flights.push_back(flight);
			arrshed.setLuggageBelt(LuggageBelt);
			ArrivalFlights.push_back(arrshed);
		}

		inputFile.close();
	}
	else {
		cerr << "������ �������� ����� \"" << filename << "\" ��� ������." << endl;
	}

	return ArrivalFlights;
}

void Visitor::printDepartureSchedule(vector<DepartureSchedule>& DepartureFlights)
{
system("cls");
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "�" << "|" << setw(6) << "�����" << "|" << std::setw(11) << "����" << " | "
		<< std::setw(15) << "�����" << " | "
		<< std::setw(15) << "������" << "|" << setw(5) << "�����" << "|" << setw(15) << "������ �����������" << "|" << setw(15) << "����� �� �������" << "|"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;
	for (auto& departureflight : DepartureFlights) {
		for ( Flight& flight : departureflight.flights) {
			cout << "|" << left <<setw(3) << ++i << "|" << setw(6) << flight.GetnumberFlight() << "|" << setw(4)<<right << flight.Getday()<<"."<<flight.Getmonth()<<"."<<flight.Getyear() << "|"
				<< setw(17) << flight.GetDestination() << "|" << setw(16) << flight.Getstatus() << "|" <<setw(5)<<flight.Gettime()<<"|" << setw(18) << departureflight.getReceptionDesk()<<
				"|" << setw(16) << departureflight.getDepartureGate() << "|" << endl;
			cout << "------------------------------------------------------------------------------------------------------" << endl;
		}
	}
}

void Visitor::printArrivalSchedule(vector<ArrivalSchedule>& ArrivalFlights)
{
	system("cls");
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "�" << "|" << setw(6) << "�����" << "|" << std::setw(11) << "����" << " | "
		<< std::setw(15) << "�����" << " | "
		<< std::setw(15) << "������" << "|" << setw(5) << "�����" << "|" << setw(15) << "�������� �����" << "|" 
		<< endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	int i = 0;
	for (auto& arrivalflight : ArrivalFlights) {
		for ( Flight& flight : arrivalflight.flights) {
			cout << "|" << left << setw(3) << ++i << "|" << setw(6) << flight.GetnumberFlight() << "|" << setw(4) << right << flight.Getday() << "." << flight.Getmonth() << "." << flight.Getyear() << "|"
				<< setw(17) << flight.GetDestination() << "|" << setw(16) << flight.Getstatus() << "|" << setw(5) << flight.Gettime() << "|" << setw(15) << arrivalflight.getLuggageBelt() <<
				"|"  << endl;
			cout << "----------------------------------------------------------------------------------" << endl;
		}
	}
}


void Admin::writeDepartureFlightstoFile(vector<DepartureSchedule> DepartureFlights)
{
	string filename = "departureschedule.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "������ �������� ����� \"" << filename << "\" ��� ������." << std::endl;
		return;
	}
	for (DepartureSchedule& depshed : DepartureFlights) {
		for (Flight& flight : depshed.flights) {
			outputFile << flight << " ";
		}
		outputFile << depshed.getReceptionDesk() << " " << depshed.getDepartureGate() << " ";
	}
	outputFile.close();
}

void Admin::writeArrivalFlightstoFile(vector<ArrivalSchedule> ArrivalFlights)
{
	string filename = "arrivalschedule.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "������ �������� ����� \"" << filename << "\" ��� ������." << std::endl;
		return;
	}
	for (ArrivalSchedule& arrshed : ArrivalFlights) {
		for (Flight& flight : arrshed.flights) {
			outputFile << flight << " ";
		}
		outputFile << arrshed.getLuggageBelt() << " ";
	}
	outputFile.close();
}

void Admin::addDepartureFlight()
{
	system("cls");
	cout << "�������� ���� � ���������� ������" << endl;
	int numberFlight,day,month,year;
	string  Destination, status, time, ReceptionDesk, DepartureGate;
	while (true) {
		cout << "������� ����� �����: ";
		numberFlight=check::inputNumber(100,999);
		cout << "������� ���� ������: ";
		cout << "������� ���� ������: ";
		day=check::inputNumber(1,31);
		cout << "������� ����� ������: ";
		month=check::inputNumber(1,12);
		cout << "������� ��� ������: ";
		year=check::inputNumber(1979,2024);
		cout << "������� �����: ";
		Destination=check::checkString();
		cout << "������� ������ �����: ";
		status=check::checkStatus();
		cout << "������� �����: ";
		cin >> time;
		cout << "������� ������ ����������� ";
		ReceptionDesk=check::inputNumber(1,20);
		cout << "������� ����� �� �������: ";
		DepartureGate=check::inputNumber(1,20);
		break;
	}
	DepartureSchedule DepartureFlight;
	Flight newflight{ numberFlight, day,month,year, Destination, status, time };
	DepartureFlight.flights.push_back(newflight);
	DepartureFlight.setReceptionGate( ReceptionDesk);
	DepartureFlight.setDepartureGate( DepartureGate);

	vector<DepartureSchedule> departureFlights = readDepartureSchedulefromFile();
	departureFlights.push_back(DepartureFlight);
	writeDepartureFlightstoFile(departureFlights);

	cout << "���� ������� �������� � ����������." << endl;
}

void Admin::addArrivalFlight()
{
	system("cls");
	cout << "�������� ���� � ���������� �������" << endl;
	int numberFlight,day,month,year;
	string  Destination, status, time, LaggageBelt;
	while (true) {
		cout << "������� ����� �����: ";
		numberFlight=check::inputNumber(100,999);
		cout << "������� ���� ������: ";
		cout << "������� ���� ������: ";
		day=check::inputNumber(1,31);
		cout << "������� ����� ������: ";
		month=check::inputNumber(1,12);
		cout << "������� ��� ������: ";
		year=check::inputNumber(1979,2024);
		cout << "������� �����: ";
		Destination=check::checkString();
		cout << "������� ������ �����: ";
		status=check::checkStatusArrival();
		cout << "������� �����: ";
		cin >> time;
		cout << "������� �������� ����� ";
		LaggageBelt=check::inputNumber(1,10);
		
		break;
	}
	ArrivalSchedule ArrivalFlight;
	Flight newflight{ numberFlight, day,month,year, Destination, status, time };
	ArrivalFlight.flights.push_back(newflight);
	ArrivalFlight.setLuggageBelt(LaggageBelt);
	vector<ArrivalSchedule> arrivalFlights = readArrivalSchedulefromFile();
	arrivalFlights.push_back(ArrivalFlight);
	writeArrivalFlightstoFile(arrivalFlights);

	cout << "���� ������� �������� � ����������." << endl;
}
void Admin::editDepartureFlight() {
	while (1) {
		//system("cls");
		vector <DepartureSchedule> departureFlights= readDepartureSchedulefromFile();
		printDepartureSchedule(departureFlights);
		int choice, numberFlight,number_for_edit,day,month,year;
		string Destination, status, time, ReceptionDesk, DepartureGate;
		cout << "������� ���� ������� ������ ��������: " << endl;
		cin >> number_for_edit;
		cout << "--------------�������--------------" << endl;
		cout << "1-����� �������� ����" << endl;
		cout << "2-����� �������� �����" << endl;
		cout << "3-����� �������� ������ �����" << endl;
		cout << "4-����� �������� ����� ������" << endl;
		cout << "5-����� �������� ������ ����������� � ����� �� �������" << endl;
		cout << "6-����� ����� �� ������ ��������������" << endl;
		cout << "��� �����: ";
		choice=check::inputNumber(1,6);
		switch (choice) {
		case 1: {
			cout << "--��������� ���� ���������--" << endl;
			int targetFlightNumber;
			cout << "������� ����� �����, ��� �������� ������ �������� ����: ";
			targetFlightNumber=check::inputNumber(100,999);
			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			int day, month, year;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ����: ";
					day=check::inputNumber(1,31);
					
					cout << setw(5) << "����� �����: ";
					month=check::inputNumber(1,12);
					
					cout << setw(5) << "����� ���: ";
					year=check::inputNumber(1979,2024);
					
					found = true;
					departureFlights.at(departureIndex).flights.at(i).setDay(day);
					departureFlights.at(departureIndex).flights.at(i).setMonth(month);
					departureFlights.at(departureIndex).flights.at(i).setYear(year);

					break;
				}
			}

			if (found) {
				// ���� ���� ��� ������, ��������� ��������� � ����
				writeDepartureFlightstoFile(departureFlights);
				cout << "--���� ��������--" << endl;
			}
			else {
				cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
			}

			break;
		}
		case 2: {
			cout << "--��������� ������ ��������--" << endl;
			int targetFlightNumber;
			cout << "������� ����� �����, ��� �������� ������ �������� ����� ��������: ";
			targetFlightNumber=check::inputNumber(100,999);
			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			string destination;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ����� ��������: ";
					destination=check::checkString();
						departureFlights.at(departureIndex).flights.at(i).setDestination(destination);
					
					found = true;
					break;
				}
			}
			if (found) {
				// ���� ���� ��� ������, ��������� ��������� � ����
				writeDepartureFlightstoFile(departureFlights);
				cout << "--����� �������� ������--" << endl;
			}
			else {
				cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
			}
			break;
		}
		case 3: {
			cout << "--��������� ������� �����--" << endl;
			int targetFlightNumber;
			cout << "������� ����� �����, ��� �������� ������ �������� ������ �����: ";
			targetFlightNumber = check::inputNumber(100, 999);			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			string status;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ������: ";
					status=check::checkStatus();
					departureFlights.at(departureIndex).flights.at(i).setStatus(status);
					found = true;
					break;
				}
			}
			if (found) {
				// ���� ���� ��� ������, ��������� ��������� � ����
				writeDepartureFlightstoFile(departureFlights);
				cout << "--������ ����� ������--" << endl;
			}
			else {
				cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
			}
			break;

		}
		case 4: {
			cout << "--��������� ������� ������ �����--" << endl;
			int targetFlightNumber;
			cout << "������� ����� �����, ��� �������� ������ �������� ����� ������ �����: ";
			targetFlightNumber = check::inputNumber(100, 999);			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			string time;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ����� ������: ";
					cin >> time;
					departureFlights.at(departureIndex).flights.at(i).setTime(time);
					found = true;
					break;
				}
			}
			if (found) {
				// ���� ���� ��� ������, ��������� ��������� � ����
				writeDepartureFlightstoFile(departureFlights);
				cout << "--����� ������ ��������--" << endl;
			}
			else {
				cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
			}
			break;
		}
		case 5: {
			cout << "--��������� ������ ����������� � ����� �� �������--" << endl;
			int targetFlightNumber;
			string ReceptionDesk, DepartureGate;
			cout << "������� ����� �����, ��� �������� ������ �������� ������ ����������� � ����� �� �������: ";
			targetFlightNumber = check::inputNumber(100, 999);			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ������ �����������: ";
					ReceptionDesk=check::inputNumber(1,20);
					departureFlights.at(departureIndex).setReceptionGate(ReceptionDesk);
					cout << setw(5) << "����� ����� �� ������� : ";
					DepartureGate=check::inputNumber(1,20);
					departureFlights.at(departureIndex).setDepartureGate(DepartureGate);
					found = true;
					break;
				}
			}
			if (found) {
				// ���� ���� ��� ������, ��������� ��������� � ����
				writeDepartureFlightstoFile(departureFlights);
				cout << "--������ ����������� � ����� �� ������� ��������--" << endl;
			}
			else {
				cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
			}
			break;

		}
		case 6: {
			return;
		}
		}
	}
}

void Admin::editArrivalFlight()
{
	vector <ArrivalSchedule> arrivalFlights = readArrivalSchedulefromFile();
	printArrivalSchedule(arrivalFlights);
	int choice, numberFlight, number_for_edit, day, month, year;
	string Destination, status, time, ReceptionDesk, DepartureGate;
	cout << "������� ���� ������� ������ ��������: " << endl;
	cin >> number_for_edit;
	cout << "--------------�������--------------" << endl;
	cout << "1-����� �������� ����" << endl;
	cout << "2-����� �������� ����� ������ " << endl;
	cout << "3-����� �������� ������ �����" << endl;
	cout << "4-����� �������� ����� ������" << endl;
	cout << "5-����� �������� �������� �����" << endl;
	cout << "6-����� ����� �� ������ ��������������" << endl;
	cout << "��� �����: ";
	choice=check::inputNumber(1,6);
	switch (choice) {
	case 1: {
		cout << "--��������� ���� ������--" << endl;
		int targetFlightNumber;
		cout << "������� ����� �����, ��� �������� ������ �������� ����: ";
		targetFlightNumber = check::inputNumber(100, 999);		// ����� ����� �� ������ � ������� flights
		int arrivalIndex = number_for_edit - 1;
		int day, month, year;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� ����: ";
				day=check::inputNumber(1,31);
				arrivalFlights.at(arrivalIndex).flights.at(i).setDay(day);
				cout << setw(5) << "����� �����: ";
				month=check::inputNumber(1,12);
				arrivalFlights.at(arrivalIndex).flights.at(i).setMonth(month);
				cout << setw(5) << "����� ���: ";
				year=check::inputNumber(1979,2024);
				arrivalFlights.at(arrivalIndex).flights.at(i).setYear(year);
				found = true;
				break;
			}
		}

		if (found) {
			// ���� ���� ��� ������, ��������� ��������� � ����
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--���� ��������--" << endl;
		}
		else {
			cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
		}

		break;
	}
	case 2: {
		cout << "--��������� ������ ������--" << endl;
		int targetFlightNumber;
		cout << "������� ����� �����, ��� �������� ������ �������� ����� ������: ";
		targetFlightNumber = check::inputNumber(100, 999);		// ����� ����� �� ������ � ������� flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		string destination;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� ����� ������: ";
				destination=check::checkString();
					arrivalFlights.at(arrivalIndex).flights.at(i).setDestination(destination);

				found = true;
				break;
			}
		}
		if (found) {
			// ���� ���� ��� ������, ��������� ��������� � ����
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--����� ������ ������--" << endl;
		}
		else {
			cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
		}
		break;
	}
	case 3: {
		cout << "--��������� ������� �����--" << endl;
		int targetFlightNumber;
		cout << "������� ����� �����, ��� �������� ������ �������� ������ �����: ";
		targetFlightNumber = check::inputNumber(100, 999);		// ����� ����� �� ������ � ������� flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		string status;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� ������: ";
				status=check::checkStatusArrival();
					arrivalFlights.at(arrivalIndex).flights.at(i).setStatus(status);
				found = true;
				break;
			}
		}
		if (found) {
			// ���� ���� ��� ������, ��������� ��������� � ����
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--������ ����� ������--" << endl;
		}
		else {
			cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
		}
		break;

	}
	case 4: {
		cout << "--��������� ������� ������ �����--" << endl;
		int targetFlightNumber;
		cout << "������� ����� �����, ��� �������� ������ �������� ����� ������ �����: ";
		targetFlightNumber = check::inputNumber(100, 999);		// ����� ����� �� ������ � ������� flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		string time;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� ����� ������: ";
				cin >> time;
					arrivalFlights.at(arrivalIndex).flights.at(i).setTime(time);
				found = true;
				break;
			}
		}
		if (found) {
			// ���� ���� ��� ������, ��������� ��������� � ����
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--����� ������ ��������--" << endl;
		}
		else {
			cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
		}
		break;
	}
	case 5: {
		cout << "--��������� �������� �����--" << endl;
		int targetFlightNumber;
		string LuggageBelt;
		cout << "������� ����� �����, ��� �������� ������ �������� �������� �����: ";
		targetFlightNumber = check::inputNumber(100, 999);		// ����� ����� �� ������ � ������� flights
		int departureIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(departureIndex).flights.size(); ++i) {
			if (arrivalFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� �������� �����: ";
				LuggageBelt=check::inputNumber(1,10);
				arrivalFlights.at(departureIndex).setLuggageBelt(LuggageBelt);
				found = true;
				break;
			}
		}
		if (found) {
			// ���� ���� ��� ������, ��������� ��������� � ����
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--�������� ����� ��������--" << endl;
		}
		else {
			cout << "���� � ������� " << targetFlightNumber << " �� ������." << endl;
		}
		break;

	}
	case 6: {
		return;
	}
	}
}

void Admin::deleteDepartureFlight()
{
	system("cls");
	vector<DepartureSchedule> departureFlights = readDepartureSchedulefromFile();
	printDepartureSchedule(departureFlights);
	int number_for_delete;
	cout << "----�������� ����� �� ����������----" << endl << endl;
	cout << "������� ����� ,������� ������ �������" << endl;
	number_for_delete=check::inputNumber(1,departureFlights.size());
	int yes_or_no;
	cout << "1. ��" << endl
		<< "2. ���" << endl
		<< "��� �����: " << endl;
	yes_or_no=check::inputNumber(1,2);
	if (yes_or_no == 1) {
		departureFlights.erase(departureFlights.begin() + number_for_delete - 1);
		cout << "----���� ������� �����----" << endl;
		writeDepartureFlightstoFile(departureFlights);
	}
	else cout << "�� �������� ��������" << endl;
}

void Admin::deleteArrivalFlight()
{
	system("cls");
	vector<ArrivalSchedule> arrivalFlights = readArrivalSchedulefromFile();
	printArrivalSchedule(arrivalFlights);
	int number_for_delete;
	cout << "----�������� ����� �� ����������----" << endl << endl;
	cout << "������� �����,������� ������ �������" << endl;
	number_for_delete=check::inputNumber(1,arrivalFlights.size());
	int yes_or_no;
	cout << "1. ��" << endl
		<< "2. ���" << endl
		<< "��� �����: " << endl;
	yes_or_no=check::inputNumber(1,2);
	if (yes_or_no == 1) {
		arrivalFlights.erase(arrivalFlights.begin() + number_for_delete - 1);
		cout << "----���� ������� �����----" << endl;
		writeArrivalFlightstoFile(arrivalFlights);
	}
	else cout << "�� �������� ��������" << endl;
}
