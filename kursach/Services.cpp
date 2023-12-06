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
		outputFile << service.getName() << " " << service.getavailibility() << " " << service.getCost() << endl;
		
	}
	outputFile.close();
}
vector<shared_ptr<PayService>> role::Visitor::readPayServiceFromFIle()
{
	string filename = "list_services.txt";
	vector<shared_ptr<PayService>> PayServices;
	ifstream inFile(filename);
	if (inFile.is_open()) {
		string name;
		char availability;
		double Cost;
		while (inFile >> name >> availability >> Cost) {
			shared_ptr<PayService> service = make_shared<PayService>( name, availability,Cost);
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
	cout << "--------------------------------" << endl;
	std::cout << "|" << setw(3) << "№" << "|" << std::setw(17) << "Название услуги" << " | "
		<< std::setw(5) << "Налич." << " | " << setw(10) << "Цена" << "|"
		<< endl;
	cout << "--------------------------------" << endl;
	int i = 0;
	for (const auto& payservicePtr : PayServices) {
		payservicePtr->show(i);
		i++;
	}
}
void PayService::show(int i) {
	std::cout << "|" << setw(3) << ++i << "|" << std::setw(17) << getName()<< " | "
		<< std::setw(5) << getavailibility()<< " | "<<setw(10)<<getCost()<<"|"
		<< endl;
	cout << "--------------------------------" << endl;
}

void Admin::addPayService() {
	cout << "Добавить новую услугу" << endl;
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();


	// Запрос данных для новой услуги у пользователя
	string name;
	char availability;
	double cost;

	cout << "Введите имя новой услуги: ";
	cin >> name;

	cout << "Введите доступность новой услуги ('Y' или 'N'): ";
	cin >> availability;

	cout << "Введите стоимость новой услуги: ";
	cin >> cost;

	// Создание нового объекта PayService и добавление его в вектор
	shared_ptr<PayService> newService = make_shared<PayService>(name, availability, cost);
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
	int i = 0; int choice, number_for_edit;
	string name;
	char availability;
	double cost;
	cout << "Введите номер аккаунта который хотите изменить: " << endl;
	cin >> number_for_edit;
	cout << "--------------ВВЕДИТЕ--------------" << endl;
	cout << "1-чтобы изменить название услуги" << endl;
	cout << "2-чтобы изменить наличие" << endl;
	cout << "3-чтобы изменить цену" << endl;
	cout << "4-чтобы выйти из режима редактирования" << endl;
	cout << "Ваш выбор: ";
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << endl << "--Новое название--" << endl;
		cin >> name;
		PayServices.at(number_for_edit - 1)->setName(name);
		cout << "--Название успешно изменены--" << endl;
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
}
void User::findPayService() {
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
	string name;
	int count = 0;
	cout << "---Поиск---" << endl;
	cout << "Введите название услуги: ";
	cin >> name;
	for (int i = 0; i < PayServices.size(); i++) {
		if (PayServices.at(i)->getName() == name) {
			count++;
			cout << "--------------------------------" << endl;
			std::cout << "|" << setw(3) << "№" << "|" << std::setw(17) << "Название услуги" << " | "
				<< std::setw(5) << "Налич." << " | " << setw(10) << "Цена" << "|"
				<< endl;
			cout << "--------------------------------" << endl;
			std::cout << "|" << setw(3) << ++i << "|" << std::setw(17) << PayServices.at(i)->getName() << " | "
				<< std::setw(5) << PayServices.at(i)->getavailibility() << " | " << setw(10) << PayServices.at(i)->getCost() << "|"
				<< endl;
			cout << "--------------------------------" << endl;
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
