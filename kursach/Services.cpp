#include"Header.h"
using namespace role;
void Admin::writePayServiceToFile(vector<PayService>& services) {
	string filename = "list_services.txt";
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		std::cerr << "������ �������� ����� \"" << filename << "\" ��� ������." << std::endl;
		return;
	}
	for (PayService& service:services ) {
		outputFile<<
		
	}
	outputFile.close();
}