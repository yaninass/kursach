#include "Header.h"
using namespace role;
void Visitor:: menu_schedule()
{
	system("cls");
	while (1) {
		
		int choice;
		vector<DepartureSchedule> DepartureFlights = readDepartureSchedulefromFile();
		vector<ArrivalSchedule> ArrivalFlights = readArrivalSchedulefromFile();
		cout << "-------Введите-------- \n 1-для просмотра расписания вылетов \n 2-для просмотра расписания прилётов \n 3-для выхода\n ";
		choice=check::inputNumber(1,3);
		switch (choice) {
		case 1: {
			cout << "Расписание вылетов" << endl;
			printDepartureSchedule(DepartureFlights);
			break;
		}
		case 2: {
			cout << "Расписание посадок" << endl;
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
		cerr << "Ошибка открытия файла \"" << filename << "\" для чтения." << endl;
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
		cerr << "Ошибка открытия файла \"" << filename << "\" для чтения." << endl;
	}

	return ArrivalFlights;
}

void Visitor::printDepartureSchedule(vector<DepartureSchedule>& DepartureFlights)
{
system("cls");
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "№" << "|" << setw(6) << "НОМЕР" << "|" << std::setw(11) << "Дата" << " | "
		<< std::setw(15) << "Пункт" << " | "
		<< std::setw(15) << "Статус" << "|" << setw(5) << "Время" << "|" << setw(15) << "Стойка регистрации" << "|" << setw(15) << "Выход на посадку" << "|"
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
	cout << "|" << setw(3) << "№" << "|" << setw(6) << "НОМЕР" << "|" << std::setw(11) << "Дата" << " | "
		<< std::setw(15) << "Пункт" << " | "
		<< std::setw(15) << "Статус" << "|" << setw(5) << "Время" << "|" << setw(15) << "Багажная лента" << "|" 
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
		std::cerr << "Ошибка открытия файла \"" << filename << "\" для записи." << std::endl;
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
		std::cerr << "Ошибка открытия файла \"" << filename << "\" для записи." << std::endl;
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
	cout << "Добавить рейс в расписание взлётов" << endl;
	int numberFlight,day,month,year;
	string  Destination, status, time, ReceptionDesk, DepartureGate;
	while (true) {
		cout << "Введите номер рейса: ";
		numberFlight=check::inputNumber(100,999);
		cout << "Введите дату вылета: ";
		cout << "Введите день вылета: ";
		day=check::inputNumber(1,31);
		cout << "Введите месяц вылета: ";
		month=check::inputNumber(1,12);
		cout << "Введите год вылета: ";
		year=check::inputNumber(1979,2024);
		cout << "Введите пункт: ";
		Destination=check::checkString();
		cout << "Введите статус рейса: ";
		status=check::checkStatus();
		cout << "Введите время: ";
		cin >> time;
		cout << "Введите стойку регистрации ";
		ReceptionDesk=check::inputNumber(1,20);
		cout << "Введите выход на посадку: ";
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

	cout << "Рейс успешно добавлен в расписание." << endl;
}

void Admin::addArrivalFlight()
{
	system("cls");
	cout << "Добавить рейс в расписание посадок" << endl;
	int numberFlight,day,month,year;
	string  Destination, status, time, LaggageBelt;
	while (true) {
		cout << "Введите номер рейса: ";
		numberFlight=check::inputNumber(100,999);
		cout << "Введите дату вылета: ";
		cout << "Введите день вылета: ";
		day=check::inputNumber(1,31);
		cout << "Введите месяц вылета: ";
		month=check::inputNumber(1,12);
		cout << "Введите год вылета: ";
		year=check::inputNumber(1979,2024);
		cout << "Введите пункт: ";
		Destination=check::checkString();
		cout << "Введите статус рейса: ";
		status=check::checkStatusArrival();
		cout << "Введите время: ";
		cin >> time;
		cout << "Введите багажную ленту ";
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

	cout << "Рейс успешно добавлен в расписание." << endl;
}
void Admin::editDepartureFlight() {
	while (1) {
		//system("cls");
		vector <DepartureSchedule> departureFlights= readDepartureSchedulefromFile();
		printDepartureSchedule(departureFlights);
		int choice, numberFlight,number_for_edit,day,month,year;
		string Destination, status, time, ReceptionDesk, DepartureGate;
		cout << "Введите рейс который хотите изменить: " << endl;
		cin >> number_for_edit;
		cout << "--------------ВВЕДИТЕ--------------" << endl;
		cout << "1-чтобы изменить дату" << endl;
		cout << "2-чтобы изменить пункт" << endl;
		cout << "3-чтобы изменить статус рейса" << endl;
		cout << "4-чтобы изменить время вылета" << endl;
		cout << "5-чтобы изменить стойку регистрации и выход на посадку" << endl;
		cout << "6-чтобы выйти из режима редактирования" << endl;
		cout << "Ваш выбор: ";
		choice=check::inputNumber(1,6);
		switch (choice) {
		case 1: {
			cout << "--Изменение даты получения--" << endl;
			int targetFlightNumber;
			cout << "Введите номер рейса, для которого хотите изменить дату: ";
			targetFlightNumber=check::inputNumber(100,999);
			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			int day, month, year;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новый день: ";
					day=check::inputNumber(1,31);
					
					cout << setw(5) << "Новый месяц: ";
					month=check::inputNumber(1,12);
					
					cout << setw(5) << "Новый год: ";
					year=check::inputNumber(1979,2024);
					
					found = true;
					departureFlights.at(departureIndex).flights.at(i).setDay(day);
					departureFlights.at(departureIndex).flights.at(i).setMonth(month);
					departureFlights.at(departureIndex).flights.at(i).setYear(year);

					break;
				}
			}

			if (found) {
				// Если рейс был найден, сохраняем изменения в файл
				writeDepartureFlightstoFile(departureFlights);
				cout << "--Дата изменена--" << endl;
			}
			else {
				cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
			}

			break;
		}
		case 2: {
			cout << "--Изменение пункта прибытия--" << endl;
			int targetFlightNumber;
			cout << "Введите номер рейса, для которого хотите изменить пункт прибытия: ";
			targetFlightNumber=check::inputNumber(100,999);
			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			string destination;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новый пункт прибытия: ";
					destination=check::checkString();
						departureFlights.at(departureIndex).flights.at(i).setDestination(destination);
					
					found = true;
					break;
				}
			}
			if (found) {
				// Если рейс был найден, сохраняем изменения в файл
				writeDepartureFlightstoFile(departureFlights);
				cout << "--Пункт прибытия изменён--" << endl;
			}
			else {
				cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
			}
			break;
		}
		case 3: {
			cout << "--Изменение статуса рейса--" << endl;
			int targetFlightNumber;
			cout << "Введите номер рейса, для которого хотите изменить статус рейса: ";
			targetFlightNumber = check::inputNumber(100, 999);			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			string status;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новый статус: ";
					status=check::checkStatus();
					departureFlights.at(departureIndex).flights.at(i).setStatus(status);
					found = true;
					break;
				}
			}
			if (found) {
				// Если рейс был найден, сохраняем изменения в файл
				writeDepartureFlightstoFile(departureFlights);
				cout << "--Статус рейса изменён--" << endl;
			}
			else {
				cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
			}
			break;

		}
		case 4: {
			cout << "--Изменение времени вылета рейса--" << endl;
			int targetFlightNumber;
			cout << "Введите номер рейса, для которого хотите изменить время вылета рейса: ";
			targetFlightNumber = check::inputNumber(100, 999);			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			string time;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новое время вылета: ";
					cin >> time;
					departureFlights.at(departureIndex).flights.at(i).setTime(time);
					found = true;
					break;
				}
			}
			if (found) {
				// Если рейс был найден, сохраняем изменения в файл
				writeDepartureFlightstoFile(departureFlights);
				cout << "--Время вылета изменено--" << endl;
			}
			else {
				cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
			}
			break;
		}
		case 5: {
			cout << "--Изменение стойку регистрации и выход на посадку--" << endl;
			int targetFlightNumber;
			string ReceptionDesk, DepartureGate;
			cout << "Введите номер рейса, для которого хотите изменить стойку регистрации и выход на посадку: ";
			targetFlightNumber = check::inputNumber(100, 999);			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новая стойка регистрации: ";
					ReceptionDesk=check::inputNumber(1,20);
					departureFlights.at(departureIndex).setReceptionGate(ReceptionDesk);
					cout << setw(5) << "Новый выход на посадку : ";
					DepartureGate=check::inputNumber(1,20);
					departureFlights.at(departureIndex).setDepartureGate(DepartureGate);
					found = true;
					break;
				}
			}
			if (found) {
				// Если рейс был найден, сохраняем изменения в файл
				writeDepartureFlightstoFile(departureFlights);
				cout << "--Стойка регистрации и выход на посадку изменены--" << endl;
			}
			else {
				cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
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
	cout << "Введите рейс который хотите изменить: " << endl;
	cin >> number_for_edit;
	cout << "--------------ВВЕДИТЕ--------------" << endl;
	cout << "1-чтобы изменить дату" << endl;
	cout << "2-чтобы изменить пункт вылета " << endl;
	cout << "3-чтобы изменить статус рейса" << endl;
	cout << "4-чтобы изменить время вылета" << endl;
	cout << "5-чтобы изменить багажную ленту" << endl;
	cout << "6-чтобы выйти из режима редактирования" << endl;
	cout << "Ваш выбор: ";
	choice=check::inputNumber(1,6);
	switch (choice) {
	case 1: {
		cout << "--Изменение даты прилёта--" << endl;
		int targetFlightNumber;
		cout << "Введите номер рейса, для которого хотите изменить дату: ";
		targetFlightNumber = check::inputNumber(100, 999);		// Поиск рейса по номеру в векторе flights
		int arrivalIndex = number_for_edit - 1;
		int day, month, year;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новый день: ";
				day=check::inputNumber(1,31);
				arrivalFlights.at(arrivalIndex).flights.at(i).setDay(day);
				cout << setw(5) << "Новый месяц: ";
				month=check::inputNumber(1,12);
				arrivalFlights.at(arrivalIndex).flights.at(i).setMonth(month);
				cout << setw(5) << "Новый год: ";
				year=check::inputNumber(1979,2024);
				arrivalFlights.at(arrivalIndex).flights.at(i).setYear(year);
				found = true;
				break;
			}
		}

		if (found) {
			// Если рейс был найден, сохраняем изменения в файл
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--Дата изменена--" << endl;
		}
		else {
			cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
		}

		break;
	}
	case 2: {
		cout << "--Изменение пункта вылета--" << endl;
		int targetFlightNumber;
		cout << "Введите номер рейса, для которого хотите изменить пункт вылета: ";
		targetFlightNumber = check::inputNumber(100, 999);		// Поиск рейса по номеру в векторе flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		string destination;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новый пункт вылета: ";
				destination=check::checkString();
					arrivalFlights.at(arrivalIndex).flights.at(i).setDestination(destination);

				found = true;
				break;
			}
		}
		if (found) {
			// Если рейс был найден, сохраняем изменения в файл
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--Пункт вылета изменён--" << endl;
		}
		else {
			cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
		}
		break;
	}
	case 3: {
		cout << "--Изменение статуса рейса--" << endl;
		int targetFlightNumber;
		cout << "Введите номер рейса, для которого хотите изменить статус рейса: ";
		targetFlightNumber = check::inputNumber(100, 999);		// Поиск рейса по номеру в векторе flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		string status;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новый статус: ";
				status=check::checkStatusArrival();
					arrivalFlights.at(arrivalIndex).flights.at(i).setStatus(status);
				found = true;
				break;
			}
		}
		if (found) {
			// Если рейс был найден, сохраняем изменения в файл
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--Статус рейса изменён--" << endl;
		}
		else {
			cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
		}
		break;

	}
	case 4: {
		cout << "--Изменение времени прилёта рейса--" << endl;
		int targetFlightNumber;
		cout << "Введите номер рейса, для которого хотите изменить время прилёта рейса: ";
		targetFlightNumber = check::inputNumber(100, 999);		// Поиск рейса по номеру в векторе flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		string time;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новое время прилёта: ";
				cin >> time;
					arrivalFlights.at(arrivalIndex).flights.at(i).setTime(time);
				found = true;
				break;
			}
		}
		if (found) {
			// Если рейс был найден, сохраняем изменения в файл
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--Время прилёта изменено--" << endl;
		}
		else {
			cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
		}
		break;
	}
	case 5: {
		cout << "--Изменение багажной ленты--" << endl;
		int targetFlightNumber;
		string LuggageBelt;
		cout << "Введите номер рейса, для которого хотите изменить багажную ленту: ";
		targetFlightNumber = check::inputNumber(100, 999);		// Поиск рейса по номеру в векторе flights
		int departureIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(departureIndex).flights.size(); ++i) {
			if (arrivalFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новая багажная лента: ";
				LuggageBelt=check::inputNumber(1,10);
				arrivalFlights.at(departureIndex).setLuggageBelt(LuggageBelt);
				found = true;
				break;
			}
		}
		if (found) {
			// Если рейс был найден, сохраняем изменения в файл
			writeArrivalFlightstoFile(arrivalFlights);
			cout << "--Багажная лента изменена--" << endl;
		}
		else {
			cout << "Рейс с номером " << targetFlightNumber << " не найден." << endl;
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
	cout << "----УДАЛЕНИЕ РЕЙСА ИЗ РАСПИСАНИЯ----" << endl << endl;
	cout << "Введите номер ,который хотите удалить" << endl;
	number_for_delete=check::inputNumber(1,departureFlights.size());
	int yes_or_no;
	cout << "1. Да" << endl
		<< "2. Нет" << endl
		<< "Ваш выбор: " << endl;
	yes_or_no=check::inputNumber(1,2);
	if (yes_or_no == 1) {
		departureFlights.erase(departureFlights.begin() + number_for_delete - 1);
		cout << "----Рейс успешно удалён----" << endl;
		writeDepartureFlightstoFile(departureFlights);
	}
	else cout << "Вы отменили удаление" << endl;
}

void Admin::deleteArrivalFlight()
{
	system("cls");
	vector<ArrivalSchedule> arrivalFlights = readArrivalSchedulefromFile();
	printArrivalSchedule(arrivalFlights);
	int number_for_delete;
	cout << "----УДАЛЕНИЕ РЕЙСА ИЗ РАСПИСАНИЯ----" << endl << endl;
	cout << "Введите номер,который хотите удалить" << endl;
	number_for_delete=check::inputNumber(1,arrivalFlights.size());
	int yes_or_no;
	cout << "1. Да" << endl
		<< "2. Нет" << endl
		<< "Ваш выбор: " << endl;
	yes_or_no=check::inputNumber(1,2);
	if (yes_or_no == 1) {
		arrivalFlights.erase(arrivalFlights.begin() + number_for_delete - 1);
		cout << "----Рейс успешно удалён----" << endl;
		writeArrivalFlightstoFile(arrivalFlights);
	}
	else cout << "Вы отменили удаление" << endl;
}
