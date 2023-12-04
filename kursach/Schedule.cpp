#include "Header.h"
using namespace role;
void Visitor:: menu_schedule()
{
	while (1) {
		//system("cls");
		int choice;
		vector<DepartureSchedule> DepartureFlights = readDepartureSchedulefromFile();
		vector<ArrivalSchedule> ArrivalFlights = readArrivalSchedulefromFile();
		cout << "-------�������-------- \n 1-��� ��������� ���������� ������� \n 2-��� ��������� ���������� ������� \n 3-��� ������\n ";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "���������� �������" << endl;
			//cout << "Size of DepartureFlights: " << DepartureFlights.size() << endl;
			printDepartureSchedule(DepartureFlights);
			break;
		}
		case 2: {
		//	system("cls");
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
			depshed.ReceptionDesk = ReceptionDesk;
			depshed.DepartureGate = DepartureGate;

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
			arrshed.LuggageBelt = LuggageBelt;
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
		for (const Flight& flight : departureflight.flights) {
			cout << "|" << left <<setw(3) << ++i << "|" << setw(6) << flight.numberFlight << "|" << setw(4)<<right << flight.day<<"."<<flight.month<<"."<<flight.year << "|"
				<< setw(17) << flight.Destination << "|" << setw(16) << flight.status << "|" <<setw(5)<<flight.time<<"|" << setw(18) << departureflight.ReceptionDesk <<
				"|" << setw(16) << departureflight.DepartureGate << "|" << endl;
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
		for (const Flight& flight : arrivalflight.flights) {
			cout << "|" << left << setw(3) << ++i << "|" << setw(6) << flight.numberFlight << "|" << setw(4) << right << flight.day << "." << flight.month << "." << flight.year << "|"
				<< setw(17) << flight.Destination << "|" << setw(16) << flight.status << "|" << setw(5) << flight.time << "|" << setw(15) << arrivalflight.LuggageBelt <<
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
		outputFile << depshed.getReceptionDesk() << " " << depshed.DepartureGate << " ";
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
		outputFile << arrshed.LuggageBelt << " ";
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
		cin >> numberFlight;
		cout << "������� ���� ������: ";
		cout << "������� ���� ������: ";
		cin >> day;
		cout << "������� ����� ������: ";
		cin >> month;
		cout << "������� ��� ������: ";
		cin >> year;
		cout << "������� �����: ";
		cin >> Destination;
		cout << "������� ������ �����: ";
		cin >> status;
		cout << "������� �����: ";
		cin >> time;
		cout << "������� ������ ����������� ";
		cin >> ReceptionDesk;
		cout << "������� ����� �� �������: ";
		cin >> DepartureGate;
		break;
	}
	DepartureSchedule DepartureFlight;
	Flight newflight{ numberFlight, day,month,year, Destination, status, time };
	DepartureFlight.flights.push_back(newflight);
	DepartureFlight.ReceptionDesk = ReceptionDesk;
	DepartureFlight.DepartureGate = DepartureGate;

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
		cin >> numberFlight;
		cout << "������� ���� ������: ";
		cout << "������� ���� ������: ";
		cin >> day;
		cout << "������� ����� ������: ";
		cin >> month;
		cout << "������� ��� ������: ";
		cin >> year;
		cout << "������� �����: ";
		cin >> Destination;
		cout << "������� ������ �����: ";
		cin >> status;
		cout << "������� �����: ";
		cin >> time;
		cout << "������� �������� ����� ";
		cin >> LaggageBelt;
		
		break;
	}
	ArrivalSchedule ArrivalFlight;
	Flight newflight{ numberFlight, day,month,year, Destination, status, time };
	ArrivalFlight.flights.push_back(newflight);
	ArrivalFlight.LuggageBelt = LaggageBelt;
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
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "--��������� ���� ���������--" << endl;
			int targetFlightNumber;
			cout << "������� ����� �����, ��� �������� ������ �������� ����: ";
			cin >> targetFlightNumber;
			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ����: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).day;
					cout << setw(5) << "����� �����: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).month;
					cout << setw(5) << "����� ���: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).year;

					found = true;
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
			cin >> targetFlightNumber;
			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ����� ��������: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).Destination;
					
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
			cin >> targetFlightNumber;
			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ������: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).status;
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
			cin >> targetFlightNumber;
			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ����� ������: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).time;
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
			cout << "������� ����� �����, ��� �������� ������ �������� ������ ����������� � ����� �� �������: ";
			cin >> targetFlightNumber;
			// ����� ����� �� ������ � ������� flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// ������ ������ ����, �������� ��� ����
					cout << setw(5) << "����� ������ �����������: ";
					cin >> departureFlights.at(departureIndex).ReceptionDesk;
					cout << setw(5) << "����� ����� �� ������� : ";
					cin >> departureFlights.at(departureIndex).DepartureGate;
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
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "--��������� ���� ������--" << endl;
		int targetFlightNumber;
		cout << "������� ����� �����, ��� �������� ������ �������� ����: ";
		cin >> targetFlightNumber;
		// ����� ����� �� ������ � ������� flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� ����: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).day;
				cout << setw(5) << "����� �����: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).month;
				cout << setw(5) << "����� ���: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).year;

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
		cin >> targetFlightNumber;
		// ����� ����� �� ������ � ������� flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� ����� ������: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).Destination;

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
		cin >> targetFlightNumber;
		// ����� ����� �� ������ � ������� flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� ������: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).status;
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
		cin >> targetFlightNumber;
		// ����� ����� �� ������ � ������� flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� ����� ������: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).time;
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
		cout << "������� ����� �����, ��� �������� ������ �������� �������� �����: ";
		cin >> targetFlightNumber;
		// ����� ����� �� ������ � ������� flights
		int departureIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(departureIndex).flights.size(); ++i) {
			if (arrivalFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// ������ ������ ����, �������� ��� ����
				cout << setw(5) << "����� �������� �����: ";
				cin >> arrivalFlights.at(departureIndex).LuggageBelt;
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
	cin >> number_for_delete;
	int yes_or_no;
	cout << "1. ��" << endl
		<< "2. ���" << endl
		<< "��� �����: " << endl;
	cin>>yes_or_no;
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
	cin >> number_for_delete;
	int yes_or_no;
	cout << "1. ��" << endl
		<< "2. ���" << endl
		<< "��� �����: " << endl;
	cin >> yes_or_no;
	if (yes_or_no == 1) {
		arrivalFlights.erase(arrivalFlights.begin() + number_for_delete - 1);
		cout << "----���� ������� �����----" << endl;
		writeArrivalFlightstoFile(arrivalFlights);
	}
	else cout << "�� �������� ��������" << endl;
}
