#include "Header.h"
using namespace role;
void Visitor:: menu_schedule()
{
	while (1) {
		//system("cls");
		int choice;
		vector<DepartureSchedule> DepartureFlights = readDepartureSchedulefromFile();
		vector<ArrivalSchedule> ArrivalFlights = readArrivalSchedulefromFile();
		cout << "-------Введите-------- \n 1-для просмотра расписания вылетов \n 2-для просмотра расписания прилётов \n 3-для выхода\n ";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Расписание вылетов" << endl;
			//cout << "Size of DepartureFlights: " << DepartureFlights.size() << endl;
			printDepartureSchedule(DepartureFlights);
			break;
		}
		case 2: {
		//	system("cls");
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
			depshed.ReceptionDesk = ReceptionDesk;
			depshed.DepartureGate = DepartureGate;

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
			arrshed.LuggageBelt = LuggageBelt;
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
	cout << "|" << setw(3) << "№" << "|" << setw(6) << "НОМЕР" << "|" << std::setw(11) << "Дата" << " | "
		<< std::setw(15) << "Пункт" << " | "
		<< std::setw(15) << "Статус" << "|" << setw(5) << "Время" << "|" << setw(15) << "Багажная лента" << "|" 
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
		std::cerr << "Ошибка открытия файла \"" << filename << "\" для записи." << std::endl;
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
		std::cerr << "Ошибка открытия файла \"" << filename << "\" для записи." << std::endl;
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
	cout << "Добавить рейс в расписание взлётов" << endl;
	int numberFlight,day,month,year;
	string  Destination, status, time, ReceptionDesk, DepartureGate;
	while (true) {
		cout << "Введите номер рейса: ";
		cin >> numberFlight;
		cout << "Введите дату вылета: ";
		cout << "Введите день вылета: ";
		cin >> day;
		cout << "Введите месяц вылета: ";
		cin >> month;
		cout << "Введите год вылета: ";
		cin >> year;
		cout << "Введите пункт: ";
		cin >> Destination;
		cout << "Введите статус рейса: ";
		cin >> status;
		cout << "Введите время: ";
		cin >> time;
		cout << "Введите стойку регистрации ";
		cin >> ReceptionDesk;
		cout << "Введите выход на посадку: ";
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
		cin >> numberFlight;
		cout << "Введите дату вылета: ";
		cout << "Введите день вылета: ";
		cin >> day;
		cout << "Введите месяц вылета: ";
		cin >> month;
		cout << "Введите год вылета: ";
		cin >> year;
		cout << "Введите пункт: ";
		cin >> Destination;
		cout << "Введите статус рейса: ";
		cin >> status;
		cout << "Введите время: ";
		cin >> time;
		cout << "Введите багажную ленту ";
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
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "--Изменение даты получения--" << endl;
			int targetFlightNumber;
			cout << "Введите номер рейса, для которого хотите изменить дату: ";
			cin >> targetFlightNumber;
			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новый день: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).day;
					cout << setw(5) << "Новый месяц: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).month;
					cout << setw(5) << "Новый год: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).year;

					found = true;
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
			cin >> targetFlightNumber;
			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новый пункт прибытия: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).Destination;
					
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
			cin >> targetFlightNumber;
			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новый статус: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).status;
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
			cin >> targetFlightNumber;
			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новое время вылета: ";
					cin >> departureFlights.at(departureIndex).flights.at(i).time;
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
			cout << "Введите номер рейса, для которого хотите изменить стойку регистрации и выход на посадку: ";
			cin >> targetFlightNumber;
			// Поиск рейса по номеру в векторе flights
			int departureIndex = number_for_edit - 1;
			bool found = false;
			for (size_t i = 0; i < departureFlights.at(departureIndex).flights.size(); ++i) {
				if (departureFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
					// Найден нужный рейс, изменяем его дату
					cout << setw(5) << "Новая стойка регистрации: ";
					cin >> departureFlights.at(departureIndex).ReceptionDesk;
					cout << setw(5) << "Новый выход на посадку : ";
					cin >> departureFlights.at(departureIndex).DepartureGate;
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
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "--Изменение даты прилёта--" << endl;
		int targetFlightNumber;
		cout << "Введите номер рейса, для которого хотите изменить дату: ";
		cin >> targetFlightNumber;
		// Поиск рейса по номеру в векторе flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новый день: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).day;
				cout << setw(5) << "Новый месяц: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).month;
				cout << setw(5) << "Новый год: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).year;

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
		cin >> targetFlightNumber;
		// Поиск рейса по номеру в векторе flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новый пункт вылета: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).Destination;

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
		cin >> targetFlightNumber;
		// Поиск рейса по номеру в векторе flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новый статус: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).status;
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
		cin >> targetFlightNumber;
		// Поиск рейса по номеру в векторе flights
		int arrivalIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(arrivalIndex).flights.size(); ++i) {
			if (arrivalFlights.at(arrivalIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новое время прилёта: ";
				cin >> arrivalFlights.at(arrivalIndex).flights.at(i).time;
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
		cout << "Введите номер рейса, для которого хотите изменить багажную ленту: ";
		cin >> targetFlightNumber;
		// Поиск рейса по номеру в векторе flights
		int departureIndex = number_for_edit - 1;
		bool found = false;
		for (size_t i = 0; i < arrivalFlights.at(departureIndex).flights.size(); ++i) {
			if (arrivalFlights.at(departureIndex).flights.at(i).GetnumberFlight() == targetFlightNumber) {
				// Найден нужный рейс, изменяем его дату
				cout << setw(5) << "Новая багажная лента: ";
				cin >> arrivalFlights.at(departureIndex).LuggageBelt;
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
	cin >> number_for_delete;
	int yes_or_no;
	cout << "1. Да" << endl
		<< "2. Нет" << endl
		<< "Ваш выбор: " << endl;
	cin>>yes_or_no;
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
	cin >> number_for_delete;
	int yes_or_no;
	cout << "1. Да" << endl
		<< "2. Нет" << endl
		<< "Ваш выбор: " << endl;
	cin >> yes_or_no;
	if (yes_or_no == 1) {
		arrivalFlights.erase(arrivalFlights.begin() + number_for_delete - 1);
		cout << "----Рейс успешно удалён----" << endl;
		writeArrivalFlightstoFile(arrivalFlights);
	}
	else cout << "Вы отменили удаление" << endl;
}
