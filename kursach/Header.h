#pragma once
#include<iostream>
#include<Windows.h>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
#include <conio.h>
#include<memory>
using namespace std;
class Service {
protected:
	string nameService;
	char availability;
public:
	virtual void show(int i) = 0;
	string getNameService() {
		return nameService;
	}
	void setName(string newName) {
		nameService = newName;
	}
	char getavailibility() {
		return availability;
	}
	void setavailability(char newAvalibility) {
		availability = newAvalibility;
	}
	Service(string nameService) {
		this->nameService = nameService;
	}
	Service( string nameService, char availability)
		: nameService(nameService), availability(availability)
	{
	}
};
class PayService : public Service {
protected:
	double Cost;

public:
	double getCost() { return Cost; }
	void setCost(double newCost) { Cost = newCost; }
	void show(int i) override;

	PayService(std:: string nameService, char availability,double Cost): Service(nameService, availability)
	{
		this->Cost = Cost;
	}
	PayService(string nameService, double Cost) :Service(nameService) {
		this->Cost = Cost;
	}
	PayService() : Service(""), Cost(0.0) {}

};
class Flight {

protected:
	int numberFlight;
	int day;
	int month;
	int year;
	string Destination;
	string status;
	string time;
public:
	int GetnumberFlight() { return numberFlight; };
	void setnumberFlight(int newnumberFlight) {
		numberFlight = newnumberFlight;
	}
	int Getday()  { return day; };
	void setDay(int newDay) {
		day = newDay;
	}
	int Getmonth() { return month; };
	void setMonth(int newMonth) {
		month = newMonth;
	}
	int Getyear() { return year; };
	void setYear(int newYear) {
		year = newYear;
	}
	string GetDestination(){ return Destination; };
	void setDestination(string newDestinaation) {
		Destination = newDestinaation;
	}
	string Getstatus() { return status; };
	void setStatus(string newStatus) {
		status = newStatus;
	}
	string Gettime()  { return time; };
	void setTime(string newtime) {
		time = newtime;
	}
	friend istream& operator>>(istream& is, Flight& flight) {
		cout << "Введите номер рейса: ";
		is >> flight.numberFlight;
		cout << "Введите дату вылета: ";
		cout << "Введите день вылета: ";
		is >> flight.day;
		cout << "Введите месяц вылета: ";
		is >> flight.month;
		cout << "Введите год вылета: ";
		is >> flight.year;
		cout << "Введите пункт: ";
		is >> flight.Destination;
		cout << "Введите статус рейса: ";
		is >> flight.status;
		cout << "Введите время: ";
		is >> flight.time;
		return is;
	}
	
	friend ostream& operator<<(ostream& os,  Flight& flight) {
		os << flight.GetnumberFlight() << " " << flight.Getday() << " "<<flight.Getmonth()<<" "<<flight.Getyear()<<" " << flight.GetDestination()
			<< " " << flight.Getstatus() << " " << flight.Gettime();
		return os;
	}

	Flight(int numberFlight, int day, int month, int year, const string& Destination, const string& status, const string& time)
		: numberFlight(numberFlight), day(day), month(month), year(year), Destination(Destination), status(status), time(time)
	{
	}
};
class  Schedule {
public:
	vector<Flight> flights;
	
	friend istream& operator>>(istream& is, Schedule& schedule) {
		for (Flight& flight : schedule.flights) {
			cout << "Введите данные для рейса:\n";
			is >> flight;  // Используем перегруженный оператор для Flight
		}
		return is;
	}

	friend ofstream& operator<<(ofstream& of, Schedule& schedule) {
		for (Flight& flight : schedule.flights) {
			of << flight.GetnumberFlight() << " " << flight.Getday() << " "<<flight.Getmonth()<<" "<<flight.Getyear()<<" " << flight.GetDestination() << " " << flight.Getstatus() << " " << flight.Gettime() << " ";
		}
		return of;
	}
	
};
class DepartureSchedule : public Schedule {
protected:
	string ReceptionDesk;
	string DepartureGate;
public:
	string getDepartureGate() {
		return DepartureGate;
	}
	string getReceptionDesk() {
		return ReceptionDesk;
	}
	void setDepartureGate(string newDepartureGate) {
		DepartureGate = newDepartureGate;
	}
	void setReceptionGate(string newReceptionGate) {
		ReceptionDesk = newReceptionGate;
	}
	friend istream& operator>>(istream& is, DepartureSchedule& departureSchedule) {
		// Перегрузка оператора ввода для DepartureSchedule
		is >> static_cast<Schedule&>(departureSchedule);  // Ввод расписания
		cout << "Введите стойку регистрации ";
		is >> departureSchedule.ReceptionDesk;
		cout << "Введите выход на посадку: ";
		is >> departureSchedule.DepartureGate;
		return is;
	}
	friend ostream& operator<<(ostream& os, const DepartureSchedule& departureSchedule) {
		/*os << static_cast<const Schedule&>(departureSchedule);*/
		os  << departureSchedule.ReceptionDesk << " "
		 << departureSchedule.DepartureGate << " ";
		return os;
	}
	
};
class ArrivalSchedule : public Schedule {
protected:
string LuggageBelt;
public:
	
	string getLuggageBelt() {
		return LuggageBelt;
	}
	void setLuggageBelt(string newLuggageBelt) {
		LuggageBelt = newLuggageBelt;
	}
	friend istream& operator>>(istream& is, ArrivalSchedule& arrivalSchedule) {
		
		is >> static_cast<Schedule&>(arrivalSchedule);  // Ввод расписания
		cout << "Введите багажную ленту ";
		is >> arrivalSchedule.LuggageBelt;
		
		return is;
	}
	friend ostream& operator<<(ostream& os, const ArrivalSchedule& arrivalSchedule) {
		/*os << static_cast<const Schedule&>(arrivalSchedule);*/
		os  << arrivalSchedule.LuggageBelt << " ";
		return os;
	}
};
namespace role {
	
	class Visitor {
	protected:
		vector<DepartureSchedule> DepartureFlights;
		vector<ArrivalSchedule> ArrivalFlights;
		vector<shared_ptr<PayService>> PayServices;
	public:
		void menu_schedule();
		vector<DepartureSchedule> readDepartureSchedulefromFile();
		vector<ArrivalSchedule> readArrivalSchedulefromFile();
		void printDepartureSchedule(vector<DepartureSchedule>& DepartureFlights);
		void printArrivalSchedule(vector<ArrivalSchedule>& ArrivalFlights);
		vector<shared_ptr<PayService>> readPayServiceFromFIle();
		void printPayServiceTable(vector<shared_ptr<PayService>>& PayServices);
		void watchService();
	};
	class Account {
	protected:
		string login;
		string password;
	public:
		Account() : login(""), password("") {};
		Account(string login, string password) {
			this->login = login;
			this->password = password;
		}
		string getLogin() { return login; };
		string getPassword() { return password; };
		void SetPassword(string newPassword) {
			password = newPassword;
		}
		void SetLogin(string newLogin) {
			login = newLogin;
		}
		friend std::ostream& operator<<(std::ostream& os, Account& account) {
			os << account.getLogin() << ' ' << account.getPassword();
			return os;
		}
		

	};
	class User :public virtual  Visitor, public  Account {
	protected:
		string name;
		string surname;
		string patronymic;
		int identNumber;
	public:
		User(string surname, string name, string patronymic) {
			this->surname = surname;
			this->name = name;
			this->patronymic = patronymic;
		}
		string getName()  { return name; }
		void setName(string newName) {
			name = newName;
		}
		string getSurname() { return surname; }
		void setSurname(string newSurname) {
			surname = newSurname;
		}
		int getIdentNumber() { return identNumber; }
		string getPatronymic() { return patronymic; }
		void setPatronymic(string newPatronymic) {
			patronymic = newPatronymic;
		}
		void setIdentNumber(int newIdentNumber) {
			identNumber = newIdentNumber;
		}
	    User() = default;
		User(string login, string password, string surname, string name, string patronymic, int identNumber) :Account(login, password) {
			this->surname = surname; this->name = name; this->patronymic = patronymic; this->identNumber = identNumber;
		}
		void findPayService();
		static bool compareByCost(shared_ptr<PayService>& a, shared_ptr<PayService>& b);
		void sortPayService();
		
		
	};
	
	class Admin : public virtual Visitor, public Account {
		int numberAdmin;
	public:
		Admin() = default;
		Admin(string login, string password, int numberAdmin) :Account(login, password)
		{
			this->numberAdmin = numberAdmin;
		}
		int getnumberAdmin() { return numberAdmin; };
		void SetnumberAdmin(int mewnumberAdmin) {
			numberAdmin = mewnumberAdmin;
		}
		void writeDepartureFlightstoFile(vector<DepartureSchedule> DepartureFlights);
		void writeArrivalFlightstoFile(vector<ArrivalSchedule> ArrivalFlights);
		void writePayServiceToFile(vector<shared_ptr<PayService>> PayServices);
		void addDepartureFlight();
		void addArrivalFlight();
		void addPayService();
		void menu_workwithdata();
		void menu_workwithschedule();
		void menu_workwithservice();
		void editDepartureFlight();
		void editArrivalFlight();
		void deleteDepartureFlight();
		void deleteArrivalFlight();
		void deletePayService();
		void editPayService();
	};

	class Authentication {
		vector<User> users;
		vector<Admin> admins;
		vector<Account> accounts_user;
		vector<Account> accounts_admin;
		vector<Admin> admins_to_aprove;
		Admin currentAdmin;
		User currentUser;
	public:
		void saveToFileUser(vector<User>& users);//запись в файл данных пользователей
		void saveToFileAccountUser(vector<Account>& accounts_user);//запись в файл аккаунтов пользователей
		void saveToFileAccount(vector<Admin>& admins_to_aprove);
		vector<Admin> readFromFileAdmins_to_aprove();
		vector<User> readFromFileUsers();//чтение из файла данных юзеров
		vector<Account> readFromFileAccountsUser();//чтение из файла аккаутов юзеров
		void saveToFileAdmin(vector<Admin>& admins);//запись в файл данных админов
		void saveToFileAccountAdmins(vector<Account>& accounts_admin);//запись в файл аккаунтов админов
		vector<Admin> readFromFileAdmins();//чтение из файла данных администраторов
		vector<Account> readFromFileAccountsAdmins();//чтение из файла аккаунтов админов
		bool checkCredentialsUser(const string& login, const string& password,User& currentUser);
		bool checkCredentialsAdmin(string& login, string& password);
		bool checkLoginAndPasswordRegist(std::vector<Account>& accounts_user, std::string login, std::string password);
		Admin getAdminByLogin(string& login);
		void addUserAccount();
		void addAdminAccount();
		void editAdminAccount();
		void editUserAccount();
		void deleteUserAccount();
		void deleteAdminAccount(string login);
		void registerUser();
		void registerAdmin();
		void authorization();
		void start_menu();
		void menu_registration();
		void menu_admin();
		void menu_user(User& currentUser);
		void approve();
		void printAdminAccountTable(vector<Account>& accounts_admin);
		void printUserAccountTable(vector<Account>& accounts_user);
		void printUserDataTable(vector<User>& users);
		void printAdminDataTable(vector<Admin>& admins);
		void printAdmins_to_aproveTable(vector<Admin>& admins_to_aprove);
		void menu_workwithaccount();
	};
}
class DecoratedService {
	role::User user;
	PayService payService;
	vector<DecoratedService> decoratedServices;
public:
	DecoratedService(string surname, string name, string patronymic, string nameService, double Cost):user(surname,name,patronymic),payService(nameService,Cost){
		
	}
	void writeDecoratedServicesToFile(vector<DecoratedService>& decoratedServices);
	vector<DecoratedService> readDecoratedServiceFromFile();
	void printDecoratedServiceTable(vector<DecoratedService>& decoratedService);
	void issueService(role::User& currentUser);
	void deleteDecoratedService();
	void watchUserDecoratedService(string surname, string name, string patronymic);

	DecoratedService() = default;
};
template <typename T>
class CaesarCipher {
private:
	T shift; // Количество позиций для сдвига в шифре Цезаря

public:
	CaesarCipher(T shiftValue) : shift(shiftValue) {}

	// Метод для шифрования пароля
	std::string encrypt(const std::string& password) const {
		std::string encryptedPassword = password;

		for (char& ch : encryptedPassword) {
			if (isalnum(ch)) { // Проверка, что символ является буквой или цифрой
				char base = islower(ch) ? 'a' : (isupper(ch) ? 'A' : '0');
				ch = static_cast<char>((ch - base + shift) % 36 + base);
			}
		}

		return encryptedPassword;
	}

	// Метод для дешифрования пароля
	std::string decrypt(const std::string& encryptedPassword) const {
		std::string decryptedPassword = encryptedPassword;

		for (char& ch : decryptedPassword) {
			if (isalnum(ch)) { // Проверка, что символ является буквой или цифрой
				char base = islower(ch) ? 'a' : (isupper(ch) ? 'A' : '0');
				ch = static_cast<char>((ch - base - shift + 36) % 36 + base);
			}
		}
	

		return decryptedPassword;
	}
};

