#include"Header.h"
bool check:: isNumberNumeric() {
    if (cin.get() == '\n')
        return true;
    else {
        cin.clear();
        cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
        return false;
    }
}
bool check:: isNumberRangeCorrect(int number, int left_range, int right_range) {
    return (number >= left_range) && (number <= right_range);
}
int check:: inputNumber(int left_range, int right_range) {
    int number;
    while (true) {
        try {
            cin >> number;

            if (cin.fail()) {
                throw runtime_error("������ �����. ���������� ������� �����.");
            }

            if (!isNumberRangeCorrect(number, left_range, right_range)) {
                throw out_of_range("�� ����� �� ���������� �������.");
            }

            return number;
        }
        catch (const exception& e) {
            cout << "������: " << e.what() << " ��������� �������: ";
            cin.clear();
            cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
        }
    }
}
int check:: inputNumbersimple() {
    int number;
    while (true) {
        try {
            cin >> number;

            if (cin.fail()) {
                throw invalid_argument("������ �����. ���������� ������� �����.");
            }

            return number;
        }
        catch (const std::exception& e) {
            cout << "������: " << e.what() << " ��������� �������" << std::endl;
            cin.clear();
            cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
        }
    }
}
string check:: checkSize() {
    const int SIZE = 8;
    while (true) {
        try {
            string s;
            cin >> s;

            if (s.size() > SIZE) {
                throw length_error("�� ����� �� ���������� ������ ������");
            }
            else {
                return s;
            }
        }
        catch (const exception& e) {
            cout << "������: " << e.what() << " ��������� �������: " << std::endl;
            cin.clear();
            cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
        }
    }
}
string check:: checkString() {
    while (true) {
        try {
            string s;
            std::locale::global(std::locale(""));

            cin >> ws;
            getline(std::cin, s);

            for (int i = 0; i < s.size();i++) {
                if (isdigit(s[i])) {
                    throw std::invalid_argument("������ �����.���� ����� �� �����������");
                }
            }

            return s;
        }
        catch (const std::exception& e) {
            cout << "������: " << e.what() << " ��������� �������." << std::endl;
            cin.clear();
            cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
        }
    }
}
string check:: checkStatus() {
    const string allowedStatuses[] = { "�����������", "�������", "������", "��������" };

    while (true) {
        try {
            string status;
            cin >> status;

            bool isValid = false;
            for (const string& allowed : allowedStatuses) {
                if (status == allowed) {
                    isValid = true;
                    break;
                }
            }

            if (!isValid) {
                throw invalid_argument("������������ ������. ����������, ������� ���� ��: �����������, �������, ������, ��������");
            }

            return status;
        }
        catch (const exception& e) {
            cout << "������: " << e.what() << " ����������, ��������� ����." << std::endl;
            cin.clear();
            cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
        }
    }
}
string check:: checkStatusArrival() {
    const string allowedStatuses[] = { "���������", "������", "������" };

    while (true) {
        try {
            string status;
            cin >> status;

            bool isValid = false;
            for (const string& allowed : allowedStatuses) {
                if (status == allowed) {
                    isValid = true;
                    break;
                }
            }

            if (!isValid) {
                throw invalid_argument("������������ ������. ����������, ������� ���� ��: ���������, ������, ������");
            }

            return status;
        }
        catch (const exception& e) {
            cout << "������: " << e.what() << " ����������, ��������� ����." << std::endl;
            cin.clear();
            cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
        }
    }
}
char check:: checkAvailability() {
    while (true) {
        try {
            char availability;
            cin >> availability;

            if (availability != '+' && availability != '-') {
                throw invalid_argument("������������ ������. ����������, ������� '+' ��� '-'.");
            }

            return availability;
        }
        catch (const exception& e) {
            std::cout << "������: " << e.what() << " ����������, ��������� ����." << std::endl;
            std::cin.clear();
            std::cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
        }
    }
}
double check:: checkDoubleInput() {
    while (true) {
        try {
            double inputValue;
            cin >> inputValue;

            if (cin.fail()) {
                throw invalid_argument("������� ������������ ��������. ����������, ������� �����.");
            }

            return inputValue;
        }
        catch (const exception& e) {
            cout << "������: " << e.what() << " ����������, ��������� ����." << endl;
            cin.clear();
            cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
        }
    }
}
