#include"Header.h"
using namespace role;
void Admin::writePayServiceToFile(vector<shared_ptr<PayService>> PayServices) {
	string filename = "list_services.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "������ �������� ����� \"" << filename << "\" ��� ������." << std::endl;
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
		cerr << "���������� ������� ���� " << filename << endl;
	}
	return PayServices;
	
}


void role::Visitor::printPayServiceTable(vector<shared_ptr<PayService>>& PayServices)
{
	cout << "----------------------------------------------------------" << endl;
	std::cout << "|" << setw(3) << "�" << "|" << std::setw(30) << "�������� ������" << " | "
		<< std::setw(5) << "�����." << " | " << setw(10) << "����" << "|"
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

	cout << "�������� ����� ������" << endl;
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();


	// ������ ������ ��� ����� ������ � ������������
	string nameService;
	char availability;
	double cost;

	cout << "������� ��� ����� ������: " << endl;
	cin.ignore();
	getline(cin, nameService);

	cout << "������� ����������� ����� ������ ('+' ��� '-'): "<<endl;
	cin >> availability;
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cout << "������� ��������� ����� ������: "<<endl;
	cin >> cost;

	// �������� ������ ������� PayService � ���������� ��� � ������
	shared_ptr<PayService> newService = make_shared<PayService>(nameService, availability, cost);
	PayServices.push_back(newService);

	// ���������� ������������ ������ ����� � ����
	writePayServiceToFile(PayServices);

}
void Admin:: deletePayService() {
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
	printPayServiceTable(PayServices);
	int number_for_delete;
	cout << "----�������� ������----" << endl << endl;
	cout << "������� ����� ������, ������� ������ �������: ";
	cin >> number_for_delete;
	cout << "�� �������, ��� ������ ������� ��� ������?" << endl;
	cout << "1. ��" << endl << "2. ���" << endl;
	int yes_or_no;
	cin >> yes_or_no;
	if (yes_or_no == 1) {

		PayServices.erase(PayServices.begin() + number_for_delete - 1);
		cout << "----������ ������� �������----" << endl;
		writePayServiceToFile(PayServices);
		
	}
	else {
		cout << "�� �������� ��������." << endl;
	}
}

void role::Admin::editPayService()
{
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
	printPayServiceTable(PayServices);

	int number_for_edit;
	cout << "������� ����� ������, ������� ������ ��������: ";
	cin >> number_for_edit;

	int choice;
	string nameService;
	char availability;
	double cost;

	cout << "--------------�������--------------" << endl;
	cout << "1-����� �������� �������� ������" << endl;
	cout << "2-����� �������� �������" << endl;
	cout << "3-����� �������� ����" << endl;
	cout << "4-����� ����� �� ������ ��������������" << endl;
	cout << "��� �����: ";
	cin >> choice;

	// ������� ����� ����� ����� ����� choice
	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

	switch (choice) {
	case 1: {
		cout << endl << "--����� ��������--" << endl;
		getline(cin, nameService);
		PayServices.at(number_for_edit - 1)->setName(nameService);
		cout << "--�������� ������� ��������--" << endl;
		break;
	}
	case 2: {
		cout << endl << "--�������� �������--" << endl;
		cin >> availability;
		PayServices.at(number_for_edit - 1)->setavailability(availability);
		cout << "--������� ������� ��������--" << endl;
		break;
	}
	case 3: {
		cout << endl << "--�������� ����--" << endl;
		cin >> cost;
		PayServices.at(number_for_edit - 1)->setCost(cost);
		cout << "--���� ������� ��������--" << endl;
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
	cout << "---�����---" << endl;
	cout << "������� �������� ������: ";
	cin >> nameService;
	for (int i = 0; i < PayServices.size(); i++) {
		if (PayServices.at(i)->getNameService() == nameService) {
			count++;
			cout << "----------------------------------------------------------" << endl;
			std::cout << "|" << setw(3) << "�" << "|" << std::setw(30) << "�������� ������" << " | "
				<< std::setw(5) << "�����." << " | " << setw(10) << "����" << "|"
				<< endl;
			cout << "----------------------------------------------------------" << endl;
			std::cout << "|" << setw(3) << ++i << "|" << std::setw(30) << PayServices.at(i-1)->getNameService() << " | "
				<< std::setw(6) << PayServices.at(i-1)->getavailibility() << " | " << setw(10) << PayServices.at(i-1)->getCost() << "|"
				<< endl;
			cout << "----------------------------------------------------------" << endl;
		}
	}
	if (count == 0) {
		cout << "������ �� �������" << endl;
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
	cout << "--������� �������������--" << endl;
	printPayServiceTable(PayServices_temp);
}
void DecoratedService::writeDecoratedServicesToFile(vector<DecoratedService>& decoratedServices) {
	string filename = "decorated_services.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "������ �������� ����� \"" << filename << "\" ��� ������." << std::endl;
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
		cerr << "���������� ������� ���� " << filename << endl;
	}
	return decoratedServices;
}

void DecoratedService::printDecoratedServiceTable(vector<DecoratedService>& decoratedService)
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "�" <<"|" << setw(15) << "�������" << "|" << setw(10) << "���" << "|" << setw(17) << "��������" << "|" << setw(17) << "�������� ������" << "|" << setw(10) << "����" << "|" << endl;
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
	cout << "-������������ �����-" << endl;

	// ������ ������������ ����������� ����� �� �����
	vector<DecoratedService> decoratedService = readDecoratedServiceFromFile();

	// ������ ��������� ������� ����� �� �����
	vector<shared_ptr<PayService>> payServices = currentUser.readPayServiceFromFIle();

	// ����� ��������� ������� ����� ��� ������ �������������
	currentUser.printPayServiceTable(payServices);

	int choice;
	int count = 0;

	// ������������ �������� ������ ��� ������������
	cout << "������� ����� ������, ������� ������ �������������: ";
	cin >> choice;

	// �������� ������������ ������ ������������
	if (choice < 1 || choice > payServices.size()) {
		cout << "������������ ����� ������." << endl;
		return;
	}
	
	// ��������� ��������� ������� ������
	shared_ptr<PayService> selectedService = payServices[choice - 1];
	if (selectedService->getavailibility() == '-') {
		cout << "������ ������ ��� � �������" << endl;
	}
	else {

		// �������� ������� DecoratedService � ���������� ��� � ������
		decoratedService.push_back(DecoratedService{ currentUser.getSurname(), currentUser.getName(), currentUser.getPatronymic(), selectedService->getNameService(), selectedService->getCost() });

		// ������ ����������� ������ �� ����������� ������� � ����
		writeDecoratedServicesToFile(decoratedService);

		cout << "--������������ ������ �������--" << endl;
	}
}

void DecoratedService::deleteDecoratedService()
{

	vector<DecoratedService> decoratedServices = readDecoratedServiceFromFile();
	printDecoratedServiceTable(decoratedServices);

	cout << "----�������� ������----" << endl << endl;
	cout << "������� ����� ������, ������� ������ �������: ";
	int number_for_delete;
	cin >> number_for_delete;

	// ��������� ������������ ������ ��� ��������
	if (number_for_delete < 1 || number_for_delete > decoratedServices.size()) {
		cout << "������������ ����� ������ ��� ��������." << endl;
		return;
	}

	cout << "�� �������, ��� ������ ������� ��� ������?" << endl;
	cout << "1. ��" << endl << "2. ���" << endl;

	int yes_or_no;
	cin >> yes_or_no;

	if (yes_or_no == 1) {
		// ���������� decoratedServices.erase ��� �������� �������� �� ���������� �������
		decoratedServices.erase(decoratedServices.begin() + number_for_delete - 1);
		cout << "----������ ������� �������----" << endl;

		// �������������� ����������� ������ � ����
		writeDecoratedServicesToFile(decoratedServices);
	}
	else {
		cout << "�� �������� ��������." << endl;
	}
}

void DecoratedService::watchUserDecoratedService(string surname, string name, string patronymic)
{
	int count = 0;
	vector<DecoratedService> decoratedService = readDecoratedServiceFromFile();
	int i = 0;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "�" << "|" << setw(15) << "�������" << "|" << setw(10) << "���" << "|" << setw(17) << "��������" << "|" << setw(17) << "�������� ������" << "|" << setw(10) << "����" << "|" << endl;
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
		cout<<"� ��� ��� ��������������� �����"<<endl;
	}
}



