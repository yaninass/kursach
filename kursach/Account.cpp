#include "Header.h"
using namespace role;
void Authentication::menu_workwithaccount() {
	system("cls");
	while (true) {

		cout << "-���� ������ � �ר����� ��������-" << endl;
		int choice;
		cout << "\n �������: " << endl;
		cout << "1 - ��� ��������� ������� ������� ���������������" << endl;
		cout << "2 - ��� ��������� ������� ������� �������������" << endl;
		cout << "3 - ��� ��������� ������ ���������������" << endl;
		cout << "4 - ��� ��������� ������ �������������" << endl;
		cout << "5 - ��� ������������� ����������� ������� ������ ��������������" << endl;
		cout << "6 - ��� ���������� ������� ������ ��������������" << endl;
		cout << "7 - ��� ���������� ������� ������ ������������" << endl;
		cout << "8 - ��� �������������� ������� ������" << endl;
		cout << "9 - ��� �������� ������� ������ " << endl;
		cout << "10 - ��� ������" << endl;
		cout << "��� �����: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			cout << "---�������� ������� ������� ���������������---" << endl;
			vector<Account> accounts_admin = readFromFileAccountsAdmins();
			printAdminAccountTable(accounts_admin);
			break;
		}
		case 2: {
			system("cls");
			cout << "---�������� ������� ������� �������������---" << endl;
			vector<Account> accounts_user = readFromFileAccountsUser();
			printUserAccountTable(accounts_user);
			break;
		}
		case 3: {
			system("cls");
			cout << "----�������� ������ ���������������----" << endl;
			vector<Admin>admins = readFromFileAdmins();
			printAdminDataTable(admins);
			break;
		}
		case 4: {
			system("cls");
			cout << "----�������� ������ �������������----" << endl;
			vector<User> users = readFromFileUsers();
			printUserDataTable(users);
			break;

		}
		case 5: {
			cout << "----������������� ������ �� �����������----" << endl;
			approve();
			break;
		}
		case 6: {
			system("cls");
			cout << "---���������� ������� ������ ��������������---" << endl;
			addAdminAccount();
			break;
		}
		case 7: {
			system("cls");
			cout << "---���������� ������� ������ ������������---" << endl;
			addUserAccount();
			break;
		}
		case 8: {
			system("cls");
			int choice1;
			cout << "��������:\n 1 - �������������� ������� ������ �������������\n 2 - �������������� ������� ������ ������������" << endl;
			cin >> choice1;
			if (choice1 == 1) { cout << "�������������� ������� ������ �������������" << endl; system("cls"); editAdminAccount(); break; }
			if (choice1 == 2) { cout << "�������������� ������� ������ ������������" << endl; system("cls"); editUserAccount(); break; }
			else {
				return;
			}
			break;
		}
		case 9: {
			system("cls");
			int choice2;
			cout << "��������:\n 1 - �������� ������� ������ �������������\n 2 - �������� ������� ������ ������������" << endl;
			cin >> choice2;
			if (choice2 == 1) { cout << "�������� ������� ������ �������������" << endl; system("cls"); deleteAdminAccount(currentAdmin.getLogin()); break; }
			if (choice2 == 2) { cout << "�������� ������� ������ ������������" << endl; system("cls"); deleteUserAccount(); break; }
			else {
				return;
			}
			break;
		}
		case 10: {
			return;
		}
		}
	}
};

void Admin::menu_workwithdata()
{
	while (true) {
		cout << "���� ������ � �������" << endl;
		int choice;
		cout << "\n �������: " << endl;
		cout << "1 - ��� ������ � �����������" << endl;
		cout << "2 - ��� ������ � ��������" << endl;
		cout << "3 - ��� ������" << endl;
		cout << "��� �����: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			menu_workwithschedule();
			break;
		}
		case 2: {
			system("cls");
			menu_workwithservice();
			break;
		}
		case 3: {
			return;
		}
		}
	}
}

void Admin::menu_workwithschedule()
{
	while (true) {
		system("cls");
		cout << "���� ������ � �����������" << endl;
		int choice;
		cout << "\n �������: " << endl;
		cout << "1 - ��� ��������� ����������" << endl;
		cout << "2 - ��� �������������� ����������" << endl;
		cout << "3 - ��� ���������� ������ � ����������" << endl;
		cout << "4 - ��� �������� ������ �� ����������" << endl;
		cout << "5 - ��� ������" << endl;
		cout << "��� �����: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			menu_schedule();
			break;
		}
		case 2: {
			system("cls");
			int choice1;
			cout << "�������������� ����������" << endl;
			cout << "��������:\n 1 - ���������� �������\n 2 - ���������� �������\n����� ����� - �����" << endl;
			cin >> choice1;
			if (choice1 == 1) { cout << "�������������� ���������� �������" << endl; editDepartureFlight(); break; }
			if (choice1 == 2) { cout << "�������������� ���������� �������" << endl; editArrivalFlight(); break; }
			else {
				system("cls");
				return;
			}
			break;
		}
		case 3: {
			system("cls");
			int choice2;
			cout << "���������� ����������" << endl;
			cout << "��������:\n 1 - ���������� �������\n 2 - ���������� �������\n����� ����� - ����� " << endl;
			cin >> choice2;
			if (choice2 == 1) { cout << "���������� ���������� �������" << endl; addDepartureFlight(); break; }
			if (choice2 == 2) { cout << "���������� ���������� �������" << endl; addArrivalFlight(); break; }
			else {
				system("cls");
				return;
			}
			break;
		}
		case 4: {
			system("cls");
			int choice3;
			cout << "�������� ����������" << endl;
			cout << "��������:\n 1 - ���������� �������\n 2 - ���������� �������\n����� ����� - ����� " << endl;
			cin >> choice3;
			if (choice3 == 1) { cout << "�������� ���������� �������" << endl; deleteDepartureFlight(); break; }
			if (choice3 == 2) { cout << "�������� ���������� �������" << endl; deleteArrivalFlight(); break; }
			else {
				system("cls");
				return;
			}
			break;
		}
		case 5: {
			return;
		}
		}
	}
}
void role::Admin::menu_workwithservice()
{
	system("cls");
	User user;
	DecoratedService decorService;
	while (true) {
		cout << "���� ������ � ��������" << endl;
		int choice;
		cout << "\n �������: " << endl;
		cout << "1 - ��� ��������� �����, ��������������� ����������" << endl;
		cout << "2 - ��� ���������� �����" << endl;
		cout << "3 - ��� �������������� �����" << endl;
		cout << "4 - ��� �������� �����" << endl;
		cout << "5 - ��� ������ �����" << endl;
		cout << "6 - ��� ���������� �����" << endl;
		cout << "7 - ��� ��������� ����� �� ������" << endl;
		cout << "8 - ��� �������� ����� �� ������" << endl;
		cout << "9 - ��� ������" << endl;
		cout << "��� �����: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			cout << "--������ ��������������� ����������---" << endl;
			vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
			printPayServiceTable(PayServices);
			break;
		}
		case 2: {
			system("cls");
			cout << "--���������� �����---" << endl;
			addPayService();
			break;
		}
		case 3: {
			system("cls");
			cout << "--�������������� �����---" << endl;
			editPayService();
			break;
		}
		case 4: {
			system("cls");
			cout << "--�������� �����---" << endl;
			deletePayService();
			break;
		}
		case 5: {
			system("cls");
			cout << "---����� �����---" << endl;
			user.findPayService();
			break;
		}
		case 6: {
			system("cls");
			cout << "---���������� ����� �� ����---" << endl;
			user.sortPayService();
			break;
		}
		case 7: {
			system("cls");
			cout << "---�������� ��������������� �����---" << endl;
			vector<DecoratedService> decoratedService = decorService.readDecoratedServiceFromFile();
			decorService.printDecoratedServiceTable(decoratedService);
			break;
		}
		case 8: {
			system("cls");
			cout << "---������� ����� �� ������---" << endl;
			decorService.deleteDecoratedService();
			Sleep(3000);
			system("cls");
			break;
		}
		case 9: {
			system("cls");
			return;
		}
		}
	}
}
void Authentication::printAdminAccountTable(vector<Account>& accounts_admin) {
	CaesarCipher<int> chifer(3);
	cout << "------------------------------" << endl;
	std::cout << "|" << setw(3) << "�" << "|" << std::setw(10) << "�����" << " | "
		<< std::setw(10) << "������" << " | "
		<<endl;
	cout << "------------------------------" << endl;
	int i = 0;
	// ����� ����� �������
	for ( auto& account : accounts_admin) {
		std::cout << "|" << setw(3) << ++i << "|" << std::setw(10) << account.getLogin() << " | "
			<< std::setw(10) <<chifer.encrypt( account.getPassword()) << " | "
			<< endl;
		cout << "------------------------------" << endl;
	}
}

void Authentication::printUserAccountTable(vector<Account>& accounts_user)
{
	CaesarCipher<int> chifer(3);
	cout << "------------------------------" << endl;
	std::cout << "|" << setw(3) << "�" << "|" << std::setw(10) << "�����" << " | "
		<< std::setw(10) << "������" << " | "
		<< endl;
	cout << "------------------------------" << endl;
	int i = 0;
	// ����� ����� �������
	for ( auto& account : accounts_user) {
		std::cout << "|" << setw(3) << ++i << "|" << std::setw(10) << account.getLogin() << " | "
			<< std::setw(10) << chifer.encrypt(account.getPassword() )<< " | "
			<< endl;
		cout << "------------------------------" << endl;
	}
}

void Authentication::printUserDataTable(vector<User>& users)
{
	CaesarCipher<int> chifer(3);
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "�" << "|" << setw(10) << "�����" << " | "
		<< std::setw(10) << "������" << " | "<< setw(15) << "�������" << "|" << setw(10) << "���" << "|"  << setw(17) << "��������" << "|" << setw(12) << "�����" << "|" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	int i = 0;
	for ( auto& user : users) {
		cout << "|" << setw(3) << ++i << "|" << setw(11) << user.getLogin() << "|" << setw(12) << chifer.encrypt(user.getPassword()) << "|" << setw(16) << user.getSurname() << "|" << setw(10) << user.getName() << "|" <<
			setw(17) << user.getPatronymic() << "|" << setw(12) << user.getIdentNumber() << "|" << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
	}
}

void Authentication::printAdminDataTable(vector<Admin>& admins)
{
	CaesarCipher<int> chifer(3);
	cout << "------------------------------------------" << endl;
	std::cout << "|" << setw(3) << "�" << "|" << std::setw(10) << "�����" << " | "
		<< std::setw(10) << "������" << " | "<<setw(10)<<"�����"<<"|"
		<< endl;
	cout << "------------------------------------------" << endl;
	int i = 0;
	// ����� ����� �������
	for ( auto& admins : admins) {
		std::cout << "|" << setw(3) << ++i << "|" << std::setw(10) << admins.getLogin() << " | "
			<< std::setw(10) <<chifer.encrypt( admins.getPassword()) << " | " << setw(10) << admins.getnumberAdmin()<<"|"
			<< endl;
		cout << "------------------------------------------" << endl;
	}
}

void role::Authentication::printAdmins_to_aproveTable(vector<Admin>& admins_to_aprove)
{
	CaesarCipher<int> chifer(3);
	cout << "------------------------------------------" << endl;
	std::cout << "|" << setw(3) << "�" << "|" << std::setw(10) << "�����" << " | "
		<< std::setw(10) << "������" << " | " << setw(10) << "�����" << "|"
		<< endl;
	cout << "------------------------------------------" << endl;
	int i = 0;
	// ����� ����� �������
	for (auto& admins : admins_to_aprove) {
		std::cout << "|" << setw(3) << ++i << "|" << std::setw(10) << admins.getLogin() << " | "
			<< std::setw(10) << chifer.encrypt(admins.getPassword()) << " | " << setw(10) << admins.getnumberAdmin() << "|"
			<< endl;
		cout << "------------------------------------------" << endl;
	}
}

void role::Authentication::approve()
{
	system("cls");
	Admin admin;
	vector<Admin> admins = readFromFileAdmins();
	vector<Admin> admins_to_aprove = readFromFileAdmins_to_aprove();
	vector<Account> accounts_admin = readFromFileAccountsAdmins();
	cout << "---������ �� ����������� ���������������---" << endl;
	printAdmins_to_aproveTable(admins_to_aprove);
	int number_for_add, choice;
	cout << "---��������---" << endl;
	cout << "1 - ��� ��������� ������" << endl;
	cout << "2 - ��� ������" << endl;
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "�������� ����� ������,������� ������ ��������" << endl;
		cin>>number_for_add;
		Account accounts_admins;
		admin.SetLogin(admins_to_aprove.at(number_for_add - 1).getLogin());
		accounts_admins.SetLogin(admins_to_aprove.at(number_for_add - 1).getLogin());
		admin.SetPassword(admins_to_aprove.at(number_for_add - 1).getPassword());
		accounts_admins.SetPassword(admins_to_aprove.at(number_for_add - 1).getPassword());
		admin.SetnumberAdmin(admins_to_aprove.at(number_for_add - 1).getnumberAdmin());
		admins.push_back(admin);
		accounts_admin.push_back(accounts_admins);
		saveToFileAdmin(admins);
		saveToFileAccountAdmins(accounts_admin);
		cout << "�� �������� ������" << endl;
		admins_to_aprove.erase(admins_to_aprove.begin() + number_for_add - 1);
		saveToFileAccount(admins_to_aprove);
		break;
	}
	case 2: {
		system("cls");
		return;
	}
	}
}

void Authentication::deleteAdminAccount(string login)
{
	//system("cls");
	vector<Admin>admins = readFromFileAdmins();
	vector<Account>accounts_admin = readFromFileAccountsAdmins();
	printAdminDataTable(admins);
	int number_for_delete;
	cout<<"----�������� �ר���� ������----" << endl << endl;
	cout << "������� ����� ��������, ������� ������ �������: ";
	cin >> number_for_delete;
	cout << "�� �������, ��� ������ ������� ���� �������?" << endl;
	cout << "1. ��" << endl << "2. ���" << endl;
	int yes_or_no;
	cin >> yes_or_no;
	if (yes_or_no == 1) {

		// ��������, �������� �� �������, ��� ������� ����� �������������, ��� ��, ��� �� �������� �������
		if (admins[number_for_delete - 1].getLogin() == login) 
		{
			cout << "�� �� ������ ������� ������� ��������������, ��� ������� �� �����." << endl<<endl;
			return;
		}
		else {
			admins.erase(admins.begin() + number_for_delete - 1);
			accounts_admin.erase(accounts_admin.begin() + number_for_delete - 1);
			cout << "----������� ������� �����----" << endl;

			saveToFileAccountAdmins(accounts_admin);
			saveToFileAdmin(admins);
		}
	}
	else {
		cout << "�� �������� ��������." << endl;
	}
}
void Authentication::deleteUserAccount()
{
	Admin admin;
	//system("cls");
	vector<User>users = readFromFileUsers();
	vector<Account>accounts_user = readFromFileAccountsUser();
	printUserDataTable(users);
	int number_for_delete;
	cout << "----�������� �ר���� ������----" << endl << endl;
	cout << "������� ����� ��������, ������� ������ �������: ";
	cin >> number_for_delete;
	cout << "�� �������, ��� ������ ������� ���� �������?" << endl;
	cout << "1. ��" << endl << "2. ���" << endl;
	int yes_or_no;
	cin >> yes_or_no;
	if (yes_or_no == 1) {
		
			users.erase(users.begin() + number_for_delete - 1);
			accounts_user.erase(accounts_user.begin() + number_for_delete - 1);
			cout << "----������� ������� �����----" << endl;

			saveToFileAccountUser(accounts_user);
			saveToFileUser(users);
	}
	else {
		cout << "�� �������� ��������." << endl;
	}
}
void Authentication::addUserAccount()
{
	cout << "�������� ������������" << endl;
	vector<Account> accounts_user = readFromFileAccountsUser();
	vector<User>users = readFromFileUsers();
	string login, password, name, surname, patronymic;
	int identNumber;
	User newUser;
	while (1) {
		cout << "������� �����" << endl;
		cin >> login;
		cout << "���������� ������" << endl;
		cin >> password;
		if (checkLoginAndPasswordRegist(accounts_user, login, password)) {
			break;
		}
	}
	newUser.SetLogin(login);
	newUser.SetPassword(password);
	cout << "������� �������" << endl;
	cin >> surname;
	newUser.setSurname(surname);
	cout << "������� ���" << endl;
	cin >> name;
	newUser.setName(name);
	cout << "������� ��������" << endl;
	cin >> patronymic;
	newUser.setPatronymic(patronymic);
	cout << "������� ����������������� ����� ��������" << endl;
	cin >> identNumber;
	newUser.setIdentNumber(identNumber);
	Account newAccount(login, password);
	//User newUser(login, password, surname, name, patronymic, identNumber);
	accounts_user.push_back(newAccount);
	users.push_back(newUser);
	saveToFileAccountUser(accounts_user);
	saveToFileUser(users);
	//system("cls");
	cout << "����������� ������ �������" << endl;

}

void Authentication::addAdminAccount()
{
	cout << "�������� ������� ��������������" << endl;
	vector<Account> accounts_admin = readFromFileAccountsAdmins();
	vector<Admin> admins = readFromFileAdmins();
	string login, password;
	int numberAdmin;
	while (1) {
		cout << "������� �����" << endl;
		cin >> login;
		cout << "���������� ������" << endl;
		cin >> password;
		if (checkLoginAndPasswordRegist(accounts_admin, login, password)) {
			break;
		}
	}
	cout << "������� ����� ����������" << endl;
	cin >> numberAdmin;
	Account newAccount(login, password);
	Admin newAdmin(login, password, numberAdmin);
	accounts_admin.push_back(newAccount);
	admins.push_back(newAdmin);
	saveToFileAccountAdmins(accounts_admin);
	saveToFileAdmin(admins);
}

void Authentication::editAdminAccount()
{
	vector<Account> accounts_admin = readFromFileAccountsAdmins();
	vector<Admin> admins = readFromFileAdmins();

	printAdminAccountTable(accounts_admin);

	int number_of_admins = admins.size(); // �������� ���������� ���������������

	int number_for_edit;
	string login,password;

	cout << "������� ����� �������� � �������� ������ �������� ����� � ������, 0 - ��� ������: " << endl;
	cin >> number_for_edit;
	if (number_for_edit == 0) {
		system("cls");
		return;
	}
	else if (number_for_edit >= 1 && number_for_edit <= number_of_admins) {
		cout << endl << "--����� �����--" << endl;
		cin >> login;
		cout<< "--����� ������--" << endl;
		cin >> password;
		// ��������, ��� ����� ����� �� ����� ������ ���������
		int i = 0;
		while (i < accounts_admin.size()) {
			if (accounts_admin.at(i).getLogin() == login) {
				cout << "������ ����� �����, ��������� �������" << endl;
				cin >> login;
				i = 0;
			}
			else {
				i++;
			}
		}

		accounts_admin.at(number_for_edit - 1).SetLogin(login);
		accounts_admin.at(number_for_edit - 1).SetPassword(password);
		//admins.at(number_for_edit - 1).setAdminLoginPassword(login, password);
		

		// ���������� ��������� � ������
		saveToFileAccountAdmins(accounts_admin);
		saveToFileAdmin(admins);

		cout << "--����� ������� ������--" << endl;
	}
	else {
		cout << "������������ ����� ��������" << endl;
	}
}


void Authentication::editUserAccount()
{

	//system("cls");
	vector<User> users = readFromFileUsers();
	vector<Account> accounts_user = readFromFileAccountsUser();
	printUserDataTable(users);
	int i = 0; int choice, number_for_edit;
	string login,password, surname, name, pathronymic;
	int identNumber;
	cout << "������� ����� �������� ������� ������ ��������: " << endl;
	cin >> number_for_edit;
	cout << "--------------�������--------------" << endl;
	cout << "1-����� �������� ����� � ������" << endl;
	cout << "2-����� �������� ���" << endl;
	cout << "3-����� ������������� ����������������� �����" << endl;
	cout << "4-����� ����� �� ������ ��������������" << endl;
	cout << "��� �����: ";
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << endl << "--����� �����--" << endl;
		cin >> login;
		cout << "--����� ������--" << endl;
		cin >> password;
		while (i < accounts_user.size()) {
			if (accounts_user.at(i).getLogin() == login) {
				cout << "������ ����� �����, ��������� �������" << endl;
				cin >> login;
				i = 0;
			}
			else i++;
		}
		accounts_user.at(number_for_edit - 1).SetLogin(login);
		accounts_user.at(number_for_edit - 1).SetPassword(password);
		users.at(number_for_edit - 1).SetPassword(password);
		users.at(number_for_edit - 1).SetLogin(login);
		saveToFileAccountUser(accounts_user);
		saveToFileUser(users);
		cout << "--����� � ������ ������� ��������--" << endl;
		break;
	}
	case 2: {
		cout << "--����� ���--" << endl;
		cout << "������� ������� : " << endl;
		cin >> surname;
		cout << "������� ��� :" << endl;
		cin >> name;
		cout << "������� �������� :" << endl;
		cin >> pathronymic;
		users.at(number_for_edit - 1).setSurname(surname);
		users.at(number_for_edit - 1).setName(name);
		users.at(number_for_edit - 1).setPatronymic(pathronymic);
		saveToFileUser(users);
		saveToFileAccountUser(accounts_user);
		cout << "--��� ������� ��������--" << endl;
		break;
	}
	case 3:{
		cout << "--����� �����--" << endl;
		cout << "������� ����� : " << endl;
		cin >> identNumber;
		users.at(number_for_edit - 1).setIdentNumber(identNumber);
		saveToFileUser(users);
		saveToFileAccountUser(accounts_user);
		cout << "--����� ������� �������--" << endl;
		break;
	}
	case 4: 
		system("cls");
		return;
	}
}





