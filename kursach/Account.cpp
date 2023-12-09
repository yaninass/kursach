#include "Header.h"
using namespace role;
void Authentication::menu_workwithaccount() {
	system("cls");
	while (true) {

		cout << "-МЕНЮ РАБОТЫ С УЧЁТНЫМИ ЗАПИСЯМИ-" << endl;
		int choice;
		cout << "\n Введите: " << endl;
		cout << "1 - для просмотра учётных записей администраторов" << endl;
		cout << "2 - для просмотра учётных записей пользователей" << endl;
		cout << "3 - для просмотра данных администраторов" << endl;
		cout << "4 - для просмотра данных пользователей" << endl;
		cout << "5 - для подтверждения регистрации учётной записи администратора" << endl;
		cout << "6 - для добавления учётной записи администратора" << endl;
		cout << "7 - для добавления учётной записи пользователя" << endl;
		cout << "8 - для редактирования учётной записи" << endl;
		cout << "9 - для удаления учётной записи " << endl;
		cout << "10 - для выхода" << endl;
		cout << "Ваш выбор: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			cout << "---Просмотр учётных записей администраторов---" << endl;
			vector<Account> accounts_admin = readFromFileAccountsAdmins();
			printAdminAccountTable(accounts_admin);
			break;
		}
		case 2: {
			system("cls");
			cout << "---Просмотр учётных записей пользователей---" << endl;
			vector<Account> accounts_user = readFromFileAccountsUser();
			printUserAccountTable(accounts_user);
			break;
		}
		case 3: {
			system("cls");
			cout << "----Просмотр данных администраторов----" << endl;
			vector<Admin>admins = readFromFileAdmins();
			printAdminDataTable(admins);
			break;
		}
		case 4: {
			system("cls");
			cout << "----Просмотр данных пользователей----" << endl;
			vector<User> users = readFromFileUsers();
			printUserDataTable(users);
			break;

		}
		case 5: {
			cout << "----Подтверждение заявок на регистрацию----" << endl;
			approve();
			break;
		}
		case 6: {
			system("cls");
			cout << "---Добавление учётной записи администратора---" << endl;
			addAdminAccount();
			break;
		}
		case 7: {
			system("cls");
			cout << "---Добавление учётной записи пользователя---" << endl;
			addUserAccount();
			break;
		}
		case 8: {
			system("cls");
			int choice1;
			cout << "Выберите:\n 1 - Редактирование учётной записи адинистратора\n 2 - Редактирование учётной записи пользователя" << endl;
			cin >> choice1;
			if (choice1 == 1) { cout << "Редактирование учётной записи адинистратора" << endl; system("cls"); editAdminAccount(); break; }
			if (choice1 == 2) { cout << "Редактирование учётной записи пользователя" << endl; system("cls"); editUserAccount(); break; }
			else {
				return;
			}
			break;
		}
		case 9: {
			system("cls");
			int choice2;
			cout << "Выберите:\n 1 - Удаление учётной записи адинистратора\n 2 - Удаление учётной записи пользователя" << endl;
			cin >> choice2;
			if (choice2 == 1) { cout << "Удаление учётной записи адинистратора" << endl; system("cls"); deleteAdminAccount(currentAdmin.getLogin()); break; }
			if (choice2 == 2) { cout << "Удаление учётной записи пользователя" << endl; system("cls"); deleteUserAccount(); break; }
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
		cout << "МЕНЮ РАБОТЫ С ДАННЫМИ" << endl;
		int choice;
		cout << "\n Введите: " << endl;
		cout << "1 - для работы с расписанием" << endl;
		cout << "2 - для работы с услугами" << endl;
		cout << "3 - для выхода" << endl;
		cout << "Ваш выбор: ";
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
		cout << "МЕНЮ РАБОТЫ С РАСПИСАНИЕМ" << endl;
		int choice;
		cout << "\n Введите: " << endl;
		cout << "1 - для просмотра расписания" << endl;
		cout << "2 - для редактирования расписания" << endl;
		cout << "3 - для добавления рейсов в расписания" << endl;
		cout << "4 - для удаления рейсов из расписания" << endl;
		cout << "5 - для выхода" << endl;
		cout << "Ваш выбор: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			menu_schedule();
			break;
		}
		case 2: {
			system("cls");
			int choice1;
			cout << "Редактирование расписания" << endl;
			cout << "Выберите:\n 1 - расписание вылетов\n 2 - расписание прилётов\nлюбая цифра - выход" << endl;
			cin >> choice1;
			if (choice1 == 1) { cout << "Редактирование расписания вылетов" << endl; editDepartureFlight(); break; }
			if (choice1 == 2) { cout << "Редактирование расписания прилётов" << endl; editArrivalFlight(); break; }
			else {
				system("cls");
				return;
			}
			break;
		}
		case 3: {
			system("cls");
			int choice2;
			cout << "Добавление расписания" << endl;
			cout << "Выберите:\n 1 - расписание вылетов\n 2 - расписание прилётов\nлюбая цифра - выход " << endl;
			cin >> choice2;
			if (choice2 == 1) { cout << "Добавления расписания вылетов" << endl; addDepartureFlight(); break; }
			if (choice2 == 2) { cout << "Добавление расписания прилётов" << endl; addArrivalFlight(); break; }
			else {
				system("cls");
				return;
			}
			break;
		}
		case 4: {
			system("cls");
			int choice3;
			cout << "Удаление расписания" << endl;
			cout << "Выберите:\n 1 - расписание вылетов\n 2 - расписание прилётов\nлюбая цифра - выход " << endl;
			cin >> choice3;
			if (choice3 == 1) { cout << "Удаление расписания вылетов" << endl; deleteDepartureFlight(); break; }
			if (choice3 == 2) { cout << "Удаление расписания прилётов" << endl; deleteArrivalFlight(); break; }
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
		cout << "МЕНЮ РАБОТЫ С УСЛУГАМИ" << endl;
		int choice;
		cout << "\n Введите: " << endl;
		cout << "1 - для просмотра услуг, предоставляемых аэропортом" << endl;
		cout << "2 - для добавления услуг" << endl;
		cout << "3 - для редактирования услуг" << endl;
		cout << "4 - для удаления услуг" << endl;
		cout << "5 - для поиска услуг" << endl;
		cout << "6 - для сортировки услуг" << endl;
		cout << "7 - для просмотра брони на услуги" << endl;
		cout << "8 - для удаления брони на услуги" << endl;
		cout << "9 - для выхода" << endl;
		cout << "Ваш выбор: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			cout << "--УСЛУГИ ПРЕДОСТАВЛЯЕМЫЕ АЭРОПОРТОМ---" << endl;
			vector<shared_ptr<PayService>> PayServices = readPayServiceFromFIle();
			printPayServiceTable(PayServices);
			break;
		}
		case 2: {
			system("cls");
			cout << "--ДОБАВЛЕНИЕ УСЛУГ---" << endl;
			addPayService();
			break;
		}
		case 3: {
			system("cls");
			cout << "--РЕДАКТИРОВАНИЕ УСЛУГ---" << endl;
			editPayService();
			break;
		}
		case 4: {
			system("cls");
			cout << "--УДАЛЕНИЕ УСЛУГ---" << endl;
			deletePayService();
			break;
		}
		case 5: {
			system("cls");
			cout << "---ПОИСК УСЛУГ---" << endl;
			user.findPayService();
			break;
		}
		case 6: {
			system("cls");
			cout << "---СОРТИРОВКА УСЛУГ ПО ЦЕНЕ---" << endl;
			user.sortPayService();
			break;
		}
		case 7: {
			system("cls");
			cout << "---ПРОСМОТР ЗАБРОНИРОВАННЫХ УСЛУГ---" << endl;
			vector<DecoratedService> decoratedService = decorService.readDecoratedServiceFromFile();
			decorService.printDecoratedServiceTable(decoratedService);
			break;
		}
		case 8: {
			system("cls");
			cout << "---УДАЛИТЬ БРОНЬ НА УСЛУГУ---" << endl;
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
	std::cout << "|" << setw(3) << "№" << "|" << std::setw(10) << "Логин" << " | "
		<< std::setw(10) << "Пароль" << " | "
		<<endl;
	cout << "------------------------------" << endl;
	int i = 0;
	// Вывод строк таблицы
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
	std::cout << "|" << setw(3) << "№" << "|" << std::setw(10) << "Логин" << " | "
		<< std::setw(10) << "Пароль" << " | "
		<< endl;
	cout << "------------------------------" << endl;
	int i = 0;
	// Вывод строк таблицы
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
	cout << "|" << setw(3) << "№" << "|" << setw(10) << "Логин" << " | "
		<< std::setw(10) << "Пароль" << " | "<< setw(15) << "Фамилия" << "|" << setw(10) << "Имя" << "|"  << setw(17) << "Отчество" << "|" << setw(12) << "Номер" << "|" << endl;
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
	std::cout << "|" << setw(3) << "№" << "|" << std::setw(10) << "Логин" << " | "
		<< std::setw(10) << "Пароль" << " | "<<setw(10)<<"Номер"<<"|"
		<< endl;
	cout << "------------------------------------------" << endl;
	int i = 0;
	// Вывод строк таблицы
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
	std::cout << "|" << setw(3) << "№" << "|" << std::setw(10) << "Логин" << " | "
		<< std::setw(10) << "Пароль" << " | " << setw(10) << "Номер" << "|"
		<< endl;
	cout << "------------------------------------------" << endl;
	int i = 0;
	// Вывод строк таблицы
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
	cout << "---Заявки на регистрацию администраторов---" << endl;
	printAdmins_to_aproveTable(admins_to_aprove);
	int number_for_add, choice;
	cout << "---Выберите---" << endl;
	cout << "1 - для одобрения заявки" << endl;
	cout << "2 - для выхода" << endl;
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "Выберите номер заявки,которую хотите одобрить" << endl;
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
		cout << "Вы одобрили заявку" << endl;
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
	cout<<"----УДАЛЕНИЕ УЧЁТНОЙ ЗАПИСИ----" << endl << endl;
	cout << "Введите номер аккаунта, который хотите удалить: ";
	cin >> number_for_delete;
	cout << "Вы уверены, что хотите удалить этот аккаунт?" << endl;
	cout << "1. Да" << endl << "2. Нет" << endl;
	int yes_or_no;
	cin >> yes_or_no;
	if (yes_or_no == 1) {

		// Проверка, является ли аккаунт, под которым зашел администратор, тем же, что он пытается удалить
		if (admins[number_for_delete - 1].getLogin() == login) 
		{
			cout << "Вы не можете удалить аккаунт администратора, под которым вы вошли." << endl<<endl;
			return;
		}
		else {
			admins.erase(admins.begin() + number_for_delete - 1);
			accounts_admin.erase(accounts_admin.begin() + number_for_delete - 1);
			cout << "----Аккаунт успешно удалён----" << endl;

			saveToFileAccountAdmins(accounts_admin);
			saveToFileAdmin(admins);
		}
	}
	else {
		cout << "Вы отменили удаление." << endl;
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
	cout << "----УДАЛЕНИЕ УЧЁТНОЙ ЗАПИСИ----" << endl << endl;
	cout << "Введите номер аккаунта, который хотите удалить: ";
	cin >> number_for_delete;
	cout << "Вы уверены, что хотите удалить этот аккаунт?" << endl;
	cout << "1. Да" << endl << "2. Нет" << endl;
	int yes_or_no;
	cin >> yes_or_no;
	if (yes_or_no == 1) {
		
			users.erase(users.begin() + number_for_delete - 1);
			accounts_user.erase(accounts_user.begin() + number_for_delete - 1);
			cout << "----Аккаунт успешно удалён----" << endl;

			saveToFileAccountUser(accounts_user);
			saveToFileUser(users);
	}
	else {
		cout << "Вы отменили удаление." << endl;
	}
}
void Authentication::addUserAccount()
{
	cout << "Добавить пользователя" << endl;
	vector<Account> accounts_user = readFromFileAccountsUser();
	vector<User>users = readFromFileUsers();
	string login, password, name, surname, patronymic;
	int identNumber;
	User newUser;
	while (1) {
		cout << "Введите логин" << endl;
		cin >> login;
		cout << "Придумайте пароль" << endl;
		cin >> password;
		if (checkLoginAndPasswordRegist(accounts_user, login, password)) {
			break;
		}
	}
	newUser.SetLogin(login);
	newUser.SetPassword(password);
	cout << "Введите фамилию" << endl;
	cin >> surname;
	newUser.setSurname(surname);
	cout << "Введите имя" << endl;
	cin >> name;
	newUser.setName(name);
	cout << "Введите отчество" << endl;
	cin >> patronymic;
	newUser.setPatronymic(patronymic);
	cout << "Введите идентификационный номер паспорта" << endl;
	cin >> identNumber;
	newUser.setIdentNumber(identNumber);
	Account newAccount(login, password);
	//User newUser(login, password, surname, name, patronymic, identNumber);
	accounts_user.push_back(newAccount);
	users.push_back(newUser);
	saveToFileAccountUser(accounts_user);
	saveToFileUser(users);
	//system("cls");
	cout << "Регистрация прошла успешно" << endl;

}

void Authentication::addAdminAccount()
{
	cout << "Добавить аккаунт администратора" << endl;
	vector<Account> accounts_admin = readFromFileAccountsAdmins();
	vector<Admin> admins = readFromFileAdmins();
	string login, password;
	int numberAdmin;
	while (1) {
		cout << "Введите логин" << endl;
		cin >> login;
		cout << "Придумайте пароль" << endl;
		cin >> password;
		if (checkLoginAndPasswordRegist(accounts_admin, login, password)) {
			break;
		}
	}
	cout << "Введите номер сотрудника" << endl;
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

	int number_of_admins = admins.size(); // Получаем количество администраторов

	int number_for_edit;
	string login,password;

	cout << "Введите номер аккаунта у которого хотите изменить логин и пароль, 0 - для выхода: " << endl;
	cin >> number_for_edit;
	if (number_for_edit == 0) {
		system("cls");
		return;
	}
	else if (number_for_edit >= 1 && number_for_edit <= number_of_admins) {
		cout << endl << "--Новый логин--" << endl;
		cin >> login;
		cout<< "--Новый пароль--" << endl;
		cin >> password;
		// Проверка, что новый логин не занят другим аккаунтом
		int i = 0;
		while (i < accounts_admin.size()) {
			if (accounts_admin.at(i).getLogin() == login) {
				cout << "Данный логин занят, повторите попытку" << endl;
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
		

		// Сохранение изменений в файлах
		saveToFileAccountAdmins(accounts_admin);
		saveToFileAdmin(admins);

		cout << "--Логин успешно изменён--" << endl;
	}
	else {
		cout << "Некорректный номер аккаунта" << endl;
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
	cout << "Введите номер аккаунта который хотите изменить: " << endl;
	cin >> number_for_edit;
	cout << "--------------ВВЕДИТЕ--------------" << endl;
	cout << "1-чтобы изменить логин и пароль" << endl;
	cout << "2-чтобы изменить ФИО" << endl;
	cout << "3-чтобы редактировать идентификационный номер" << endl;
	cout << "4-чтобы выйти из режима редактирования" << endl;
	cout << "Ваш выбор: ";
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << endl << "--Новый логин--" << endl;
		cin >> login;
		cout << "--Новый пароль--" << endl;
		cin >> password;
		while (i < accounts_user.size()) {
			if (accounts_user.at(i).getLogin() == login) {
				cout << "Данный логин занят, повторите попытку" << endl;
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
		cout << "--Логин и пароль успешно изменены--" << endl;
		break;
	}
	case 2: {
		cout << "--Новое ФИО--" << endl;
		cout << "Введите фамилию : " << endl;
		cin >> surname;
		cout << "Введите имя :" << endl;
		cin >> name;
		cout << "Введите отчество :" << endl;
		cin >> pathronymic;
		users.at(number_for_edit - 1).setSurname(surname);
		users.at(number_for_edit - 1).setName(name);
		users.at(number_for_edit - 1).setPatronymic(pathronymic);
		saveToFileUser(users);
		saveToFileAccountUser(accounts_user);
		cout << "--ФИО успешно изменено--" << endl;
		break;
	}
	case 3:{
		cout << "--Новый номер--" << endl;
		cout << "Введите номер : " << endl;
		cin >> identNumber;
		users.at(number_for_edit - 1).setIdentNumber(identNumber);
		saveToFileUser(users);
		saveToFileAccountUser(accounts_user);
		cout << "--номер успешно изменен--" << endl;
		break;
	}
	case 4: 
		system("cls");
		return;
	}
}





