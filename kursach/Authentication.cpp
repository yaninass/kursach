#include"Header.h"
using namespace role;


void Authentication::registerUser() {
	cout << "Регистрация пользователя" << endl;
	vector<Account> accounts_user = readFromFileAccountsUser();
	vector<User>users = readFromFileUsers();
	string login, password, name, surname, patronymic;
	int identNumber;
	User newUser;
	while (1) {
		cout << "Введите логин" << endl;
		cin >> login;
		cout << "Придумайте пароль" << endl;
		password=check::checkSize();
		if (checkLoginAndPasswordRegist(accounts_user, login, password)) {
			break;
		}
	}
	newUser.SetLogin(login);
	newUser.SetPassword(password);
	cout << "Введите фамилию" << endl;
	surname=check::checkString();
	newUser.setSurname(surname);
	cout << "Введите имя" << endl;
	name=check::checkString();
	newUser.setName(name);
	cout << "Введите отчество" << endl;
	patronymic=check::checkString();
	newUser.setPatronymic(patronymic);
	cout << "Введите идентификационный номер паспорта" << endl;
	identNumber=check::inputNumber(10000000,99999999);
	newUser.setIdentNumber(identNumber);
	Account newAccount(login, password);
	accounts_user.push_back(newAccount);
	users.push_back(newUser);
	saveToFileAccountUser(accounts_user);
	saveToFileUser(users);
	system("cls");
	cout << "Регистрация прошла успешно" << endl;
	Sleep(2000);
	system("cls");
	cout <<
		"Добро пожаловать, " << newUser.getSurname() << " " << newUser.getName() << " " << newUser.getPatronymic() << "!" << endl;
	menu_user(newUser);

}
void Authentication::registerAdmin()
{
	cout << "Регистрация администратора" << endl;
	vector<Account> accounts_admin = readFromFileAccountsAdmins();
	vector<Admin> admins_to_aprove = readFromFileAdmins_to_aprove();
	int numberAdmin;
	string login, password;
	while (1) {
		cout << "Введите логин" << endl;
		cin >> login;
		cout << "Придумайте пароль" << endl;
		password=check::checkSize();
		if (checkLoginAndPasswordRegist(accounts_admin, login, password)) {
			break;
		}
	}
	cout << "Введите номер сотрудника" << endl;
	numberAdmin=check::inputNumber(1,100);
	Admin newAdmin(login, password, numberAdmin);
	admins_to_aprove.push_back(newAdmin);
	saveToFileAccount(admins_to_aprove);
	system("cls");
	cout << "--Регистрация прошла успешно, ожидайте одобрения заявки--" << endl;
	Sleep(3000);
	start_menu();
}

void Authentication::authorization()
{
	Admin currentAdmin;
	string login, password;
	while (1) {
		password = "";
		char ch;
		int i = 0;
		std::cout << "Введите логин: ";
		std::cin >> login;
		std::cout << "Введите пароль: ";
		while ((ch = _getch()) != '\r') {   // \r - символ Enter
			if (ch == '\b') {   // \b - символ "backspace"
				if (i > 0) {
					cout << "\b \b";   // Отображаем backspace, пробел и еще один backspace
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
		else if(checkCredentialsUser(login, password, currentUser)) {
			system("cls");
			cout << "Вход выполнен успешно!" << endl <<
				"Добро пожаловать, " << currentUser.getSurname() << " " << currentUser.getName() << " " << currentUser.getPatronymic() << "!" << endl;
			menu_user(currentUser);
			break;
		}
		else {
			cout << "Неправильный логин или пароль. Попробуйте снова.\n";
		}
		
	}
}
void Authentication::start_menu()
{
	while (1) {
		system("cls");
		Visitor visitor;
		int choice;
		cout << "-------Введите-------- \n 1-для регистрации \n 2-для авторизации \n 3-просмотреть расписание \n 4-посмотреть услуги, предоставляемые аэропортом\n 5-для выхода\n ";
		cout << "Ваш выбор: ";
		choice=check::inputNumber(1,5);

		switch (choice) {
		case 1: {
			system("cls");
			menu_registration();
			break;
		}
		case 2: {
			system("cls");
			authorization();
			break;
		}
		case 3: {
			visitor.menu_schedule();
			break;
		}
		case 4: {
			visitor.watchService();
			break;
		}
		case 5: {
			return;
		}
		}

	}
}
void role::Visitor::watchService(){
	system("cls");
	User user;
	cout << "--УСЛУГИ ПРЕДОСТАВЛЯЕМЫЕ АЭРОПОРТОМ---" << endl;
	vector<shared_ptr<PayService>> PayServices = user.readPayServiceFromFIle();
	user.printPayServiceTable(PayServices);
	int choice_exit;
	cout << endl << "Введите 1 для выхода\n";
	choice_exit=check::inputNumber(1,1);
	if (choice_exit == 1) {
		return;
	}
}
void Authentication::menu_registration()
{
	while (1) {
		system("cls");
		int choice;
		cout << "-------Введите-------- \n 1-для регистрации админа \n 2-для регистрации пользователя \n 3-для выхода \n";

		choice=check::inputNumber(1,3);
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

void Authentication::menu_admin()
{
	while (1)
	{
		system("cls");
		Admin admin;
		vector<DepartureSchedule> DepartureFlights = admin.readDepartureSchedulefromFile();
		cout  << "Добро пожаловать, " << currentAdmin.getLogin() << endl;
		cout << "---МЕНЮ АДМИНИСТРАТОРА---" << endl;
		int choice;
		cout << "\n Введите: " << endl;
		cout << "1 - для работы с учётными записями" << endl;
		cout << "2 - для работы с данными" << endl;
		cout << "3 - для выхода" << endl;
		cout << "Ваш выбор: ";
		choice=check::inputNumber(1,3);
		switch (choice) {
		case 1: {
			system("cls");
			cout << "---РАБОТА С УЧЁТНЫМИ ЗАПИСЯМИ---\n";
			menu_workwithaccount();
			break;
		}
		case 2: {
			system("cls");
			cout << "---РАБОТА С ДАННЫМИ---\n";
			admin.menu_workwithdata();
			break;
		}
		case 3: {
			return;

		}
		}
	}
}
void Authentication::menu_user(User& currentUser)
{
	while (1)
	{
		Visitor visitor;
		DecoratedService decorService;
		cout << "\n---МЕНЮ ПОЛЬЗОВАТЕЛЯ---" << endl;
		int choice;
		cout << "\n Введите: " << endl;
		cout << "1 - чтобы просмотреть расписание" << endl;
		cout << "2 - для просмотра услуг,предоставляемых аэропортом" << endl;
		cout << "3 - для оформления услуг" << endl;
		cout << "4 - для просмотра оформленных услуг" << endl;
		cout << "5 - для поиска услуг" << endl;
		cout << "6 - для сортировки услуги" << endl;
		cout << "7 - для выхода" << endl;
		cout << "Ваш выбор: ";
		choice=check::inputNumber(1,7);
		switch (choice) {
		case 1: {
			visitor.menu_schedule();
			break;
		}
		case 2: {
			system("cls");
			cout << "--УСЛУГИ ПРЕДОСТАВЛЯЕМЫЕ АЭРОПОРТОМ---" << endl;
			vector<shared_ptr<PayService>> PayServices = visitor.readPayServiceFromFIle();
			visitor.printPayServiceTable(PayServices);
			break;
		}
		case 3: {
			system("cls");
			cout << "---ОФОРМЛЕНИЕ УСЛУГ---" << endl;
			decorService.issueService(currentUser);
			break;
		}
		case 4: {
			cout << "---ПРОСМОТР ОФОРМЛЕННЫХ УСЛУГ---" << endl;
			decorService.watchUserDecoratedService(currentUser.getSurname(), currentUser.getName(), currentUser.getPatronymic());
			break;
		}
		case 5:
		{   system("cls");
			cout << "---ПОИСК УСЛУГ---" << endl;
			currentUser.findPayService();
			break;
		}
		case 6: {
			currentUser.sortPayService();
			break;
		}
		case 7: {
			system("cls");
			return;

		}
		}
	}
}

void Authentication::saveToFileUser( vector<User>& users) {
	string filename = "users.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cerr << "Ошибка открытия файла " << filename << " для записи" << endl;
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
		cerr << "Ошибка открытия файла " << filename << " для записи" << endl;
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
		cerr << "Ошибка открытия файла " << filename << " для записи" << endl;
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
		cerr << "Невозможно открыть файл " << filename << endl;
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
		cerr << "Невозможно открыть файл " << filename << endl;
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
		cerr << "Невозможно открыть файл " << filename << endl;
	}
	return accounts_user;

}

void Authentication::saveToFileAdmin( vector<Admin>& admins)
{  
	string filename = "admins.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cerr << "Ошибка открытия файла " << filename << " для записи" << endl;
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
		cerr << "Ошибка открытия файла " << filename << " для записи" << endl;
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
		cerr << "Невозможно открыть файл " << filename << endl;
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
		cerr << "Невозможно открыть файл " << filename << endl;
	}
	return accounts_admins;
}
bool Authentication::checkCredentialsUser(const std::string& login, const std::string& password,User& currentUser) {
	accounts_user = readFromFileAccountsUser();
	users = readFromFileUsers();
	//CaesarCipher<int> chifer(3);
	for ( auto& account : users) {
		if (account.getLogin() == login && account.getPassword() == password) {
			currentUser.setSurname(account.getSurname());
			currentUser.setName(account.getName());
			currentUser.setPatronymic(account.getPatronymic());
			
			return true;  // Найден пользователь с таким логином и паролем
		}
	}

	return false;  // Пользователь не найден
}

bool Authentication::checkCredentialsAdmin( string& login,  string& password)
{
	accounts_admin = readFromFileAccountsAdmins();

	for ( auto& account : accounts_admin) {
		if (account.getLogin() == login && account.getPassword() == password) {
			currentAdmin.SetLogin(login);
			menu_admin();
			return true;// Найден пользователь с таким логином и паролем
		}
	}

	return false;
}

bool Authentication::checkLoginAndPasswordRegist(std::vector<Account>& accounts_user, std::string login, std::string password)
{
	for (auto& account : accounts_user) {
		if (account.getLogin() == login && account.getPassword() == password) {
			std::cout << "Такой пользователь уже существует" << endl;
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




