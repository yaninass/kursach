#include"Header.h"
using namespace role;


void Authentication::registerUser() {
	cout << "����������� ������������" << endl;
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
	accounts_user.push_back(newAccount);
	users.push_back(newUser);
	saveToFileAccountUser(accounts_user);
	saveToFileUser(users);
	system("cls");
	cout << "����������� ������ �������" << endl;
	Sleep(2000);
	system("cls");
	menu_user();

}
void Authentication::registerAdmin()
{
	cout << "����������� ��������������" << endl;
	vector<Account> accounts_admin = readFromFileAccountsAdmins();
	vector<Admin> admins_to_aprove = readFromFileAdmins_to_aprove();
	int numberAdmin;
	string login, password;
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
	Admin newAdmin(login, password, numberAdmin);
	admins_to_aprove.push_back(newAdmin);
	saveToFileAccount(admins_to_aprove);
	system("cls");
	cout << "--����������� ������ �������, �������� ��������� ������--" << endl;
	Sleep(3000);
	start_menu();
}


void Authentication::loginUser() {
	std::string login, password;
	while (1) {
		password = "";
		char ch;
		int i = 0;
		std::cout << "������� �����: ";
		std::cin >> login;
		std::cout << "������� ������: ";
		while ((ch = _getch()) != '\r') {   // \r - ������ Enter
			if (ch == '\b') {   // \b - ������ "backspace"
				if (i > 0) {
					cout << "\b \b";   // ���������� backspace, ������ � ��� ���� backspace
					i--;
					password.erase(i, 1);
				}
			}
			else {
				password.insert(i, 1, ch);
				i++;
				cout << '*';
			}
		}
		cout << endl;

		if (checkCredentialsUser(login, password)) {
			currentUser.SetLogin(login);
			break;
		}
		else {
			std::cout << "������������ ����� ��� ������. ���������� �����.\n";
		}
	}
}
void Authentication::authorizationAdmin()
{
	Admin currentAdmin;
	string login, password;
	while (1) {
		password = "";
		char ch;
		int i = 0;
		std::cout << "������� �����: ";
		std::cin >> login;
		std::cout << "������� ������: ";
		while ((ch = _getch()) != '\r') {   // \r - ������ Enter
			if (ch == '\b') {   // \b - ������ "backspace"
				if (i > 0) {
					cout << "\b \b";   // ���������� backspace, ������ � ��� ���� backspace
					i--;
					password.erase(i, 1);
				}
			}
			else {
				password.insert(i, 1, ch);
				i++;
				cout << '*';
			}
		}
		cout << endl;
		if (checkCredentialsAdmin(login, password)) {
			currentAdmin.SetLogin(login);
			break;
		}
		else {
			std::cout << "������������ ����� ��� ������. ���������� �����.\n";
		}
		
	}
}
void Authentication::start_menu()
{
	while (1) {
		system("cls");
		int choice;
		cout << "-------�������-------- \n 1-��� ����������� \n 2-��� ����������� \n 3-����������� ���������� \n 4-��� ������\n ";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			menu_registration();
			break;
		}
		case 2: {
			system("cls");
			menu_login();
			break;
		}
		case 3: {
			Visitor visitor;
			visitor.menu_schedule();
			break;
		}
		case 4: {
			return;
		}
		}

	}
}
void Authentication::menu_registration()
{
	while (1) {
		system("cls");
		int choice;
		cout << "-------�������-------- \n 1-��� ����������� ������ \n 2-��� ����������� ������������ \n 3-��� ������ \n";

		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			registerAdmin();
			break;
		}
		case 2: {
			system("cls");
			registerUser();
			break;
		}
		case 3: {
			return;

		}
		}

	}
}
void Authentication::menu_login()
{
	while (1) {
		system("cls");
		int choice;
		cout << "-------�������-------- \n 1-��� ����������� ������ \n 2-��� ����������� ������������ \n 3-��� ������ \n";

		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			authorizationAdmin();
			break;
		}
		case 2: {
			system("cls");
			loginUser();
			break;
		}
		case 3: {
			return;
		}
		}

	}
}
void Authentication::menu_admin()
{
	while (1)
	{
		Admin admin;
		vector<DepartureSchedule> DepartureFlights = admin.readDepartureSchedulefromFile();
		cout << endl << "����� ����������, " << currentAdmin.getLogin() << endl;
		cout << "���� ��������������" << endl;
		int choice;
		cout << "\n �������: " << endl;
		cout << "1 - ��� ������ � �������� ��������" << endl;
		cout << "2 - ��� ������ � �������" << endl;
		cout << "3 - ��� ������" << endl;
		cout << "��� �����: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			cout << "������ � ����������";
			menu_workwithaccount();
			break;
		}
		case 2: {
			system("cls");
			cout << "������ � �������";
			admin.menu_workwithdata();
			break;
		}
		case 3: {
			return;

		}
		}
	}
}
void Authentication::menu_user()
{
	while (1)
	{
		Visitor visitor;
	
		cout << "����� ����������, " << currentUser.getLogin();
		cout << "���� ������������" << endl;
		int choice;
		cout << "\n �������: " << endl;
		cout << "1 - ����� ����������� ����������" << endl;
		cout << "2 - ��� ��������� ��������� �������" << endl;
		cout << "3 - ��� ������� �������" << endl;
		cout << "4 - ��� ��������� ��������� �������" << endl;
		cout << "5 - ��� ������ ������" << endl;
		cout << "6 - ��� ���������� �������" << endl;
		cout << "7 - ��� ������" << endl;
		cout << "��� �����: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			visitor.menu_schedule();
			break;
		}
		case 2: {
			system("cls");

			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		case 5:
		{
			break;
		}
		case 6: {
			break;
		}
		case 7: {
			return;

		}
		}
	}
}

void Authentication::saveToFileUser( vector<User>& users) {
	string filename = "users.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cerr << "������ �������� ����� " << filename << " ��� ������" << endl;
		return;
	}
	CaesarCipher<int> chifer(3);
	for ( User& user : users) {
		outputFile << user.getLogin()<<" "<<chifer.encrypt(user.getPassword())<< " " << user.getSurname() << " " << user.getName() << " " << user.getPatronymic()<< " " << user.getIdentNumber() << endl;
	}
	outputFile.close();
}

void Authentication::saveToFileAccountUser( vector<Account>& accounts_user)
{
	string filename = "accounts_user.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cerr << "������ �������� ����� " << filename << " ��� ������" << endl;
		return;
	}
	CaesarCipher<int> chifer(3);
	for ( Account& account : accounts_user) {
		outputFile << account.getLogin() << " " << chifer.encrypt(account.getPassword()) << endl;
	}
	outputFile.close();
}

void role::Authentication::saveToFileAccount(vector<Admin>& admins_to_aprove)
{
	string filename = "admins_to_aprove.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cerr << "������ �������� ����� " << filename << " ��� ������" << endl;
		return;
	}
	CaesarCipher<int> chifer(3);
	for (Admin& admin : admins_to_aprove) {
		outputFile << admin.getLogin() << " " << chifer.encrypt(admin.getPassword()) << " " << admin.getnumberAdmin() << endl;
	}
	outputFile.close();
}

vector<Admin> role::Authentication::readFromFileAdmins_to_aprove()
{
	string filename = "admins_to_aprove.txt";
	vector<Admin> admins_to_aprove;
	CaesarCipher<int> chifer(3);
	ifstream inFile(filename);
	if (inFile.is_open()) {
		string login, password;
		int numberAdmin;
		while (inFile >> login >> password >> numberAdmin) {
			admins_to_aprove.push_back(Admin{ login,chifer.decrypt(password),numberAdmin });
		}
		inFile.close();
	}
	else {
		cerr << "���������� ������� ���� " << filename << endl;
	}
	return admins_to_aprove;
}



vector<User> Authentication::readFromFileUsers()
{
	string filename = "users.txt";
	vector<User> users;
	CaesarCipher<int> chifer(3);
	ifstream inFile(filename);
	if (inFile.is_open()) {
		string login, password, name, surname, patronymic;
		int identNumber;
		while (inFile >> login >> password >> surname >> name >> patronymic >> identNumber) {
			//cout << "Debug: Reading from file - " << login << " " << password << " " << surname << " " << name << " " << patronymic << " " << identNumber << endl;
			users.push_back(User{ login,chifer.decrypt(password),surname,name,patronymic,identNumber });
		}
		inFile.close();
	}
	else {
		cerr << "���������� ������� ���� " << filename << endl;
	}
	return users;
}

vector<Account> Authentication::readFromFileAccountsUser()
{
	string filename = "accounts_user.txt";
	vector<Account> accounts_user;
	CaesarCipher<int> chifer(3);
	ifstream inFile(filename);
	if (inFile.is_open()) {
		string login, password;
		while (inFile >> login >> password) {
			accounts_user.push_back(Account{ login,chifer.decrypt(password) });
		}
		inFile.close();
	}
	else {
		cerr << "���������� ������� ���� " << filename << endl;
	}
	return accounts_user;

}

void Authentication::saveToFileAdmin( vector<Admin>& admins)
{  
	string filename = "admins.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cerr << "������ �������� ����� " << filename << " ��� ������" << endl;
		return;
	}
	CaesarCipher<int> chifer(3);
	for ( Admin& admin : admins) {
		outputFile << admin.getLogin()<<" "<<chifer.encrypt(admin.getPassword()) << " " << admin.getnumberAdmin() << endl;
	}
	outputFile.close();
}

void Authentication::saveToFileAccountAdmins( vector<Account>& accounts_admin)
{
	string filename = "accounts_admins.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cerr << "������ �������� ����� " << filename << " ��� ������" << endl;
		return;
	}
	CaesarCipher<int> chifer(3);
	for ( Account& account : accounts_admin) {
		outputFile << account.getLogin() << " " << chifer.encrypt(account.getPassword()) << endl;
	}
	outputFile.close();

}

vector<Admin> Authentication::readFromFileAdmins()
{
	string filename = "admins.txt";
	vector<Admin> admins;
	ifstream inFile(filename);
	CaesarCipher<int> chifer(3);
	if (inFile.is_open()) {
		string login, password;
		int numberAdmin;
		while (inFile >> login >> password >> numberAdmin) {
			admins.push_back(Admin{ login,chifer.decrypt(password),numberAdmin });
		}
		inFile.close();
	}
	else {
		cerr << "���������� ������� ���� " << filename << endl;
	}
	return admins;
}

vector<Account> Authentication::readFromFileAccountsAdmins()
{
	string filename = "accounts_admins.txt";
	vector<Account> accounts_admins;
	CaesarCipher<int> chifer(3);
	ifstream inFile(filename);
	if (inFile.is_open()) {
		string login, password;
		while (inFile >> login >> password) {
			accounts_admins.push_back(Account{ login,chifer.decrypt(password) });
		}
		inFile.close();
	}
	else {
		cerr << "���������� ������� ���� " << filename << endl;
	}
	return accounts_admins;
}
bool Authentication::checkCredentialsUser(const std::string& login, const std::string& password) {
	accounts_user = readFromFileAccountsUser();
	//CaesarCipher<int> chifer(3);
	for ( auto& account : accounts_user) {
		if (account.getLogin() == login && account.getPassword() == password) {
			menu_user();
			return true;  // ������ ������������ � ����� ������� � �������
		}
	}

	return false;  // ������������ �� ������
}

bool Authentication::checkCredentialsAdmin( string& login,  string& password)
{
	accounts_admin = readFromFileAccountsAdmins();

	for ( auto& account : accounts_admin) {
		if (account.getLogin() == login && account.getPassword() == password) {
			currentAdmin.SetLogin(login);
			menu_admin();
			return true;// ������ ������������ � ����� ������� � �������
		}
	}

	return false;
}

bool Authentication::checkLoginAndPasswordRegist(std::vector<Account>& accounts_user, std::string login, std::string password)
{
	for (auto& account : accounts_user) {
		if (account.getLogin() == login && account.getPassword() == password) {
			std::cout << "����� ������������ ��� ����������" << endl;
			return false;
		}
	}
	return true;
}

Admin Authentication::getAdminByLogin( string& login) 
{
	for ( auto& admin : admins) {
		if (admin.getLogin() == login) {
			return admin;
		}
	}
	return Admin();
}




