#include"Header.h"
using namespace role;
void Admin::writePayServiceToFile(vector<shared_ptr<PayService>> PayServices) {
	string filename = "list_services.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "Ошибка открытия файла \"" << filename << "\" для записи." << std::endl;
		return;
	}
	for (shared_ptr<PayService>& servicePtr :PayServices ) {
		PayService& service = *servicePtr;
		outputFile << service.getNameService() << " " << service.getavailibility() << " " << service.getCost() << endl;
		
	}
	outputFile.close();
}
vector<shared_ptr<PayService>> role::Visitor::readPayServiceFromFIle()
{
	string filename = "list_services.txt";
	vector<shared_ptr<PayService>> PayServices;
	ifstream inFile(filename);
	if (inFile.is_open()) {
		string nameService;
		char availability;
		double Cost;
		while (inFile >> nameService>> availability >> Cost) {
			shared_ptr<PayService> service = make_shared<PayService>(nameService, availability, Cost);
			PayServices.push_back(service);
		}
		inFile.close();
	}
	else {
		cerr << "Невозможно открыть файл " << filename << endl;
	}
	return PayServices;
	
}


void role::Visitor::printPayServiceTable(vector<shared_ptr<PayService>>& PayServices)
{
	cout << "----------------------------------------------------------" << endl;
	std::cout << "|" << setw(3) << "№" << "|" << std::setw(30) << "Название услуги" << " | "
		<< std::setw(5) << "Налич." << " | " << setw(10) << "Цена" << "|"
		<< endl;
	cout << "----------------------------------------------------------" << endl;
	int i = 0;
	for (const auto& payservicePtr : PayServices) {
		payservicePtr->show(i);
		i++;
	}
}
void PayService::show(int i) {
	std::cout << "|" << setw(3) << ++i << "|" << std::setw(30) << getNameService()<< " | "
		<< std::setw(6) << getavailibility()<< " | "<<setw(10)<<getCost()<<"|"
		<< endl;
	cout << "----------------------------------------------------------" << endl;
}

void Admin::addPayService() {

	cout << "Добавить новую услугу" << endl;
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();


	// Запрос данных для новой услуги у пользователя
	string nameService;
	char availability;
	double cost;

	cout << "Введите имя новой услуги: " << endl;
	cin.ignore();
	getline(cin, nameService);

	cout << "Введите доступность новой услуги ('+' или '-'): "<<endl;
	cin >> availability;
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "Введите стоимость новой услуги: "<<endl;
	cin >> cost;

	// Создание нового объекта PayService и добавление его в вектор
	shared_ptr<PayService> newService = make_shared<PayService>(nameService, availability, cost);
	PayServices.push_back(newService);

	// Сохранение обновленного списка услуг в файл
	writePayServiceToFile(PayServices);

}
void Admin:: deletePayService() {
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
	printPayServiceTable(PayServices);
	int number_for_delete;
	cout << "----УДАЛЕНИЕ УСЛУГИ----" << endl << endl;
	cout << "Введите номер услуги, которую хотите удалить: ";
	cin >> number_for_delete;
	cout << "Вы уверены, что хотите удалить эту услугу?" << endl;
	cout << "1. Да" << endl << "2. Нет" << endl;
	int yes_or_no;
	cin >> yes_or_no;
	if (yes_or_no == 1) {

		PayServices.erase(PayServices.begin() + number_for_delete - 1);
		cout << "----Услуга успешно удалена----" << endl;
		writePayServiceToFile(PayServices);
		
	}
	else {
		cout << "Вы отменили удаление." << endl;
	}
}

void role::Admin::editPayService()
{
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
	printPayServiceTable(PayServices);

	int number_for_edit;
	cout << "Введите номер услуги, которую хотите изменить: ";
	cin >> number_for_edit;

	int choice;
	string nameService;
	char availability;
	double cost;

	cout << "--------------ВВЕДИТЕ--------------" << endl;
	cout << "1-чтобы изменить название услуги" << endl;
	cout << "2-чтобы изменить наличие" << endl;
	cout << "3-чтобы изменить цену" << endl;
	cout << "4-чтобы выйти из режима редактирования" << endl;
	cout << "Ваш выбор: ";
	cin >> choice;

	// Очищаем буфер после ввода числа choice
	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

	switch (choice) {
	case 1: {
		cout << endl << "--Новое название--" << endl;
		getline(cin, nameService);
		PayServices.at(number_for_edit - 1)->setName(nameService);
		cout << "--Название успешно изменено--" << endl;
		break;
	}
	case 2: {
		cout << endl << "--Изменить наличие--" << endl;
		cin >> availability;
		PayServices.at(number_for_edit - 1)->setavailability(availability);
		cout << "--Наличие успешно изменено--" << endl;
		break;
	}
	case 3: {
		cout << endl << "--Изменить цену--" << endl;
		cin >> cost;
		PayServices.at(number_for_edit - 1)->setCost(cost);
		cout << "--Цена успешно изменена--" << endl;
		break;
	}
	case 4: {
		return;
	}
	}
	writePayServiceToFile(PayServices);
}
void User::findPayService() {
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
	string nameService;
	int count = 0;
	cout << "---Поиск---" << endl;
	cout << "Введите название услуги: ";
	cin >> nameService;
	for (int i = 0; i < PayServices.size(); i++) {
		if (PayServices.at(i)->getNameService() == nameService) {
			count++;
			cout << "----------------------------------------------------------" << endl;
			std::cout << "|" << setw(3) << "№" << "|" << std::setw(30) << "Название услуги" << " | "
				<< std::setw(5) << "Налич." << " | " << setw(10) << "Цена" << "|"
				<< endl;
			cout << "----------------------------------------------------------" << endl;
			std::cout << "|" << setw(3) << ++i << "|" << std::setw(30) << PayServices.at(i-1)->getNameService() << " | "
				<< std::setw(6) << PayServices.at(i-1)->getavailibility() << " | " << setw(10) << PayServices.at(i-1)->getCost() << "|"
				<< endl;
			cout << "----------------------------------------------------------" << endl;
		}
	}
	if (count == 0) {
		cout << "Ничего не найдено" << endl;
	}
}

bool role::User::compareByCost(shared_ptr<PayService>& a, shared_ptr<PayService>& b)
{
	return a->getCost() < b->getCost();
}

void role::User::sortPayService()
{
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
	vector<shared_ptr<PayService>> PayServices_temp;
	PayServices_temp = PayServices;
	sort(PayServices_temp.begin(), PayServices_temp.end(), compareByCost);
	cout << "--Успешно отсортировано--" << endl;
	printPayServiceTable(PayServices_temp);
}
void DecoratedService::writeDecoratedServicesToFile(vector<DecoratedService>& decoratedServices) {
	string filename = "decorated_services.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "Ошибка открытия файла \"" << filename << "\" для записи." << std::endl;
		return;
	}

	for (DecoratedService& decoratedService : decoratedServices) {
		outputFile << decoratedService.user.getSurname() << " "
			<< decoratedService.user.getName() << " "
			<< decoratedService.user.getPatronymic() << " "
			<< decoratedService.payService.getNameService() << " "
			<< decoratedService.payService.getCost() << endl;
	}

	outputFile.close();
}

vector<DecoratedService> DecoratedService::readDecoratedServiceFromFile()
{
	string filename = "decorated_services.txt";
	vector<DecoratedService> decoratedServices;
	ifstream inFile(filename);
	if (inFile.is_open()) {
		string surname,name,patronymic,nameService;
		double Cost;
		while (inFile >>surname>>name>>patronymic>> nameService  >> Cost) {
			decoratedServices.push_back(DecoratedService{ surname,name,patronymic,nameService,Cost });
		}
		inFile.close();
	}
	else {
		cerr << "Невозможно открыть файл " << filename << endl;
	}
	return decoratedServices;
}

void DecoratedService::printDecoratedServiceTable(vector<DecoratedService>& decoratedService)
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "№" <<"|" << setw(15) << "Фамилия" << "|" << setw(10) << "Имя" << "|" << setw(17) << "Отчество" << "|" << setw(17) << "Название услуги" << "|" << setw(10) << "Цена" << "|" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	int i = 0;
	for (auto& decoratedservice : decoratedService) {
		cout << "|" << setw(3) << ++i <<"|" << setw(15) << decoratedservice.user.getSurname() << "|" << setw(10) <<	decoratedservice.user.getName()<< "|" << setw(17)
			<< decoratedservice.user.getPatronymic() << "|" << setw(17) << decoratedservice.payService.getNameService() << "|" << setw(10) << decoratedservice.payService.getCost() << "|" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
	}
}

void DecoratedService::issueService(User& currentUser)
{
	cout << "-Бронирование услуг-" << endl;

	// Чтение существующих оформленных услуг из файла
	vector<DecoratedService> decoratedService = readDecoratedServiceFromFile();

	// Чтение доступных платных услуг из файла
	vector<shared_ptr<PayService>> payServices = currentUser.readPayServiceFromFIle();

	// Вывод доступных платных услуг для выбора пользователем
	currentUser.printPayServiceTable(payServices);

	int choice;
	int count = 0;

	// Пользователь выбирает услугу для бронирования
	cout << "Введите номер услуги, которую хотите забронировать: ";
	cin >> choice;

	// Проверка корректности выбора пользователя
	if (choice < 1 || choice > payServices.size()) {
		cout << "Некорректный выбор услуги." << endl;
		return;
	}
	
	// Получение выбранной платной услуги
	shared_ptr<PayService> selectedService = payServices[choice - 1];
	if (selectedService->getavailibility() == '-') {
		cout << "Данной услуги нет в наличии" << endl;
	}
	else {

		// Создание объекта DecoratedService и добавление его в вектор
		decoratedService.push_back(DecoratedService{ currentUser.getSurname(), currentUser.getName(), currentUser.getPatronymic(), selectedService->getNameService(), selectedService->getCost() });

		// Запись обновленных данных об оформленных услугах в файл
		writeDecoratedServicesToFile(decoratedService);

		cout << "--Бронирование прошло успешно--" << endl;
	}
}

void DecoratedService::deleteDecoratedService()
{

	vector<DecoratedService> decoratedServices = readDecoratedServiceFromFile();
	printDecoratedServiceTable(decoratedServices);

	cout << "----УДАЛЕНИЕ УСЛУГИ----" << endl << endl;
	cout << "Введите номер услуги, которую хотите удалить: ";
	int number_for_delete;
	cin >> number_for_delete;

	// Проверяем корректность номера для удаления
	if (number_for_delete < 1 || number_for_delete > decoratedServices.size()) {
		cout << "Некорректный номер услуги для удаления." << endl;
		return;
	}

	cout << "Вы уверены, что хотите удалить эту услугу?" << endl;
	cout << "1. Да" << endl << "2. Нет" << endl;

	int yes_or_no;
	cin >> yes_or_no;

	if (yes_or_no == 1) {
		// Используем decoratedServices.erase для удаления элемента по указанному индексу
		decoratedServices.erase(decoratedServices.begin() + number_for_delete - 1);
		cout << "----Услуга успешно удалена----" << endl;

		// Перезаписываем обновленные данные в файл
		writeDecoratedServicesToFile(decoratedServices);
	}
	else {
		cout << "Вы отменили удаление." << endl;
	}
}

void DecoratedService::watchUserDecoratedService(string surname, string name, string patronymic)
{
	int count = 0;
	vector<DecoratedService> decoratedService = readDecoratedServiceFromFile();
	int i = 0;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "№" << "|" << setw(15) << "Фамилия" << "|" << setw(10) << "Имя" << "|" << setw(17) << "Отчество" << "|" << setw(17) << "Название услуги" << "|" << setw(10) << "Цена" << "|" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (auto& decorservice : decoratedService) {
		
		if (decorservice.user.getSurname() == surname && decorservice.user.getName() == name && decorservice.user.getPatronymic()==patronymic) {
			count++;
			
				cout << "|" << setw(3) << ++i << "|" << setw(15) << decorservice.user.getSurname() << "|" << setw(10) << decorservice.user.getName() << "|" << setw(17)
					<< decorservice.user.getPatronymic() << "|" << setw(17) << decorservice.payService.getNameService() << "|" << setw(10) << decorservice.payService.getCost() << "|" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
			
			}
	}
	if (count == 0) {
		cout<<"У вас нет забронированных услуг"<<endl;
	}
}



