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
		cerr << "���������� ������� ���� " << filename << endl;
	}
	return PayServices;
}
void role::Visitor::printPayServiceTable(vector<shared_ptr<PayService>>& PayServices)
{
	cout << "--------------------------------" << endl;
	std::cout << "|" << setw(3) << "�" << "|" << std::setw(17) << "�������� ������" << " | "
		<< std::setw(5) << "�����." << " | " << setw(10) << "����" << "|"
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
	cout << "�������� ����� ������" << endl;
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();


	// ������ ������ ��� ����� ������ � ������������
	string name;
	char availability;
	double cost;

	cout << "������� ��� ����� ������: ";
	cin >> name;

	cout << "������� ����������� ����� ������ ('Y' ��� 'N'): ";
	cin >> availability;

	cout << "������� ��������� ����� ������: ";
	cin >> cost;

	// �������� ������ ������� PayService � ���������� ��� � ������
	shared_ptr<PayService> newService = make_shared<PayService>(name, availability, cost);
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
	int i = 0; int choice, number_for_edit;
	string name;
	char availability;
	double cost;
	cout << "������� ����� �������� ������� ������ ��������: " << endl;
	cin >> number_for_edit;
	cout << "--------------�������--------------" << endl;
	cout << "1-����� �������� �������� ������" << endl;
	cout << "2-����� �������� �������" << endl;
	cout << "3-����� �������� ����" << endl;
	cout << "4-����� ����� �� ������ ��������������" << endl;
	cout << "��� �����: ";
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << endl << "--����� ��������--" << endl;
		cin >> name;
		PayServices.at(number_for_edit - 1)->setName(name);
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
}
void User::findPayService() {
	vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
	string name;
	int count = 0;
	cout << "---�����---" << endl;
	cout << "������� �������� ������: ";
	cin >> name;
	for (int i = 0; i < PayServices.size(); i++) {
		if (PayServices.at(i)->getName() == name) {
			count++;
			cout << "--------------------------------" << endl;
			std::cout << "|" << setw(3) << "�" << "|" << std::setw(17) << "�������� ������" << " | "
				<< std::setw(5) << "�����." << " | " << setw(10) << "����" << "|"
				<< endl;
			cout << "--------------------------------" << endl;
			std::cout << "|" << setw(3) << ++i << "|" << std::setw(17) << PayServices.at(i)->getName() << " | "
				<< std::setw(5) << PayServices.at(i)->getavailibility() << " | " << setw(10) << PayServices.at(i)->getCost() << "|"
				<< endl;
			cout << "--------------------------------" << endl;
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
