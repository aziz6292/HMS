//Online Treatment project
//1st project of programming
// Abdul Aziz  BCSF19A026
// Fatima Ansari  BCSF20A046


#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <iomanip>


using namespace std;



int serial = 1;



struct DoctorProfile
{
	string name, qulif, gender, mail, speciality, bankName, cntc, acNo;
	string  branchCode, avilblHours, startH, endH, hospitalName;
	int noOfDays = 0;
	string nameOfDays[7];
};




struct PatientInfo
{
	string name, gender, disease;
};








void hospital();
int useAs();
DoctorProfile creatingDrProfile();
void doctorEntry(int type);
int disease();
void display(int  patientChoice);
int confirmation();
void appointment(int agree);









int main()
{

	cout << "\t**********************" << endl;
	cout << "\t* ASSALAM O ALAIKUM  *\n";
	cout << "\t**********************" << endl << endl;

	char terminator = 0;
	do
	{
		int selection;
		hospital();
		selection = useAs();
		if (selection == 1)
		{
			int type = disease();
			doctorEntry(type);
		}
		else if (selection == 2)
		{
			int patientChoice = disease();
			display(patientChoice);
			int agree = confirmation();
			appointment(agree);


		}
		else
		{
			continue;
		}
		cout << "\n\nWould You Like to use this App again!!\nPress 'Y' for yes\n\tOR\nPress any key to Finish\nYour Selection: ";
		cin >> terminator;
		system("cls");
	} while (terminator == 'y' || terminator == 'Y');
	system("cls");

	cout << "Please Rate us and review our work as well\n";
	cout << "If you have any Problem regarding this App Please Comment us\n";
	cout << "\n\tTHANK YOU SO MUCH FOR USING THE APP" << endl;
	cout << "\tALLAH HAFIZ";

	return 0;
}







void hospital()
{
	int choice;
	cout << "Select Hospital from the following\n";
	cout << "Select: '1' for General Hospital\n\t'2' for City Hospital\n\t'3' If Other\nYour Selection: ";
	cin >> choice;
	system("cls");
	while (choice < 1 || choice >3)
	{
		cout << "ERROR!! Invalid selection\n";
		cout << "Select 1, 2 OR 3: ";
		cin >> choice;
		system("cls");
	}
	if (choice == 1)
	{
		cout << "\t***********************************";
		cout << "\n\t* WELCOME TO THE GENERAL HOSPITAL *";
		cout << "\n\t***********************************\n\n";
	}
	else if (choice == 2)
	{
		cout << "\t********************************";
		cout << "\n\t* WELCOME TO THE CITY HOSPITAL *";
		cout << "\n\t********************************\n\n";
	}
	else
	{
		string hospital;
		cout << "Please Mention the Name of the Hospital\n";
		cout << "We will include in Hospital list as soon as possible: ";
		cin >> hospital;
	}

}





int  useAs()
{
	int choice;
	cout << "Sir Kindly tell us about yourself\n";
	cout << "Select: '1' If you want to use as a Doctor\n";
	cout << "\t'2' If you want to use as a Patient/for Patient\n";
	cout << "\t'3' If Other\n";
	cout << "Your Selection: ";
	cin >> choice;
	system("cls");
	while (choice < 1 || choice >3)
	{
		cout << "ERROR!! Invalid selection\n";
		cout << "Select 1, 2 OR 3: ";
		cin >> choice;
		system("cls");
	}

	if (choice == 3)
	{
		cout << "\nPlease Mention your purpose of using the App\n";
		cout << "Sorry Sir it's only for Doctor as well as for Patient\n\tTHANKS FOR USING THE APP";
	}

	return choice;
}







DoctorProfile creatingDrProfile()
{
	DoctorProfile doctor;
	cout << "\t\t CREATING PROFILE\n";
	cout << "\n\tPERSONAL INFORMATION\n\n";
	cout << "Name: ";
	cin.ignore();
	getline(cin, doctor.name);
	cout << "Gender: ";
	getline(cin, doctor.gender);
	cout << "Qulification: ";
	getline(cin, doctor.qulif);
	cout << "Specialty: ";
	getline(cin, doctor.speciality);
	cout << "Hospital Name: ";
	getline(cin, doctor.hospitalName);
	cout << "Email: ";
	getline(cin, doctor.mail);
	cout << "Contact: ";
	cin >> doctor.cntc;
	system("cls");
	cout << "\n\n\tMOVING TO THE NEXT CATEGARY\n";
	cout << "\nKindly Give us Bank Detail for online Payment\n";
	cout << "Bank Name: ";
	cin.ignore();
	getline(cin, doctor.bankName);
	cout << "Bank Account No: ";
	cin >> doctor.acNo;
	cout << "Branch Code/Area code of Mention Bank: ";
	cin >> doctor.branchCode;
	system("cls");
	cout << "\n\n\tFINALIZING YOUR PROFILE\n";
	cout << "\nNow You Have to share your Availability\n";
	cout << "Hours You are Available in a Day: ";
	cin >> doctor.avilblHours;
	cout << "Starting Time/Just Mention Hours e.g 06 am: ";
	cin >> doctor.startH;
	cout << "Finishing Time/Just Mention Hours e.g 01 pm: ";
	cin >> doctor.endH;
	cout << "Days You are Available in a Week: ";
	cin >> doctor.noOfDays;
	system("cls");
	cout << "Name of Days on which you are Available:\n";
	for (int i = 0; i < doctor.noOfDays; i++)
	{
		cout << "Day " << i + 1 << " : ";
		cin >> doctor.nameOfDays[i];
	}
	system("cls");

	return doctor;
}












void doctorEntry(int type)
{
	switch (type)
	{

	case 1:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();

		ofstream fout;
		fout.open("type1.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();



		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n"; 
		}
		else
		{
			doctorEntry(type);
		}


	}

	break;

	case 2:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();
		ofstream fout;
		fout.open("type2.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();



		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n";
		}
		else
		{
			doctorEntry(type);
		}





	}

	break;

	case 3:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();
		ofstream fout;
		fout.open("type3.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occure Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();



		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n";
		}
		else
		{
			doctorEntry(type);
		}



	}

	break;

	case 4:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();
		ofstream fout;
		fout.open("type4.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occure Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();



		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n";
		}
		else
		{
			doctorEntry(type);
		}



	}

	break;
	case 5:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();
		ofstream fout;
		fout.open("type5.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occure Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();



		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n";
		}
		else
		{
			doctorEntry(type);
		}




	}

	break;
	case 6:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();
		ofstream fout;
		fout.open("type6.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occure Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();



		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n";
		}
		else
		{
			doctorEntry(type);
		}


	}

	break;
	case 7:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();
		ofstream fout;
		fout.open("type7.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occure Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();


		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n";
		}
		else
		{
			doctorEntry(type);
		}




	}

	break;
	case 8:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();
		ofstream fout;
		fout.open("type8.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occure Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();


		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n";
		}
		else
		{
			doctorEntry(type);
		}



	}

	break;
	case 9:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();
		ofstream fout;
		fout.open("type9.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occure Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();


		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n";
		}
		else
		{
			doctorEntry(type);
		}



	}

	break;
	case 00:
	{
		DoctorProfile doctor;
		doctor = creatingDrProfile();
		ofstream fout;
		fout.open("type00.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occure Please try again later!!";
		}
		else
		{
			fout << "\tPERSONAL INFORMATION\n\n";
			fout << "Name: " << doctor.name << endl;
			fout << "Gender: " << doctor.gender << endl;
			fout << "Qualification: " << doctor.qulif << endl;
			fout << "Specialty: " << doctor.speciality << endl;
			fout << "Hospital Name: " << doctor.hospitalName << endl;
			fout << "\n\tCONTACT INFORMATION\n\n";
			fout << "Email: " << doctor.mail << endl;
			fout << "Contact: " << doctor.cntc << endl;
			fout << "\n\tBANK DETAILS\n\n";
			fout << "Account No: " << doctor.acNo << endl;
			fout << "Branch Code: " << doctor.branchCode << endl;
			fout << "\n\tAVAILABILITY\n\n";
			fout << "Available " << doctor.avilblHours << " Hours a day" << endl;
			fout << "Starting time " << doctor.startH  << endl;
			fout << "Finishing time " << doctor.endH << endl;
			fout << "Available on:\n";
			for (int i = 0; i < doctor.noOfDays; i++)
			{
				fout << i + 1 << ".\t" << doctor.nameOfDays[i] << endl;
			}
		}
		fout.close();


		display(type);
		int choice;
		cout << "\nPlease Verify Your Data\n";
		cout << "Select  '1' if True" << endl;
		cout << "\t'2' if you wanna edit it\n";
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >2)
		{
			cout << "ERROR!! Invailid Selection\nSelect 1 OR 2: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 1)
		{
			cout << "\t\tCONGRATULATION\n";
			cout << "You Have Successfully Created Your Profile\nThank You\n";
		}
		else
		{
			doctorEntry(type);
		}



	}

	break;

	}

}





int disease()
{
	int choice;
	cout << "Select From the list Please\n";
	cout << "Select: '1' For/If Brain Problems/Neurologist/Psychologist\n";
	cout << "\t'2' For/If Heart Problems/Cardiologist\n";
	cout << "\t'3' For/If Bone Problems/Orthopedic\n";
	cout << "\t'4' For/If Kidney problems/Urologist\n";
	cout << "\t'5' For/If Eye/Nose/Throught Diseases/ENT Specialist\n";
	cout << "\t'6' For/If Teeth Diseases/Dentist\n";
	cout << "\t'7' For/If Skin Diseases/Dermatologist\n";
	cout << "\t'8' For/If Children Diseases/Children Specialist\n";
	cout << "\t'9' For/If Delivery cases/Gynecologist\n";
	cout << "\t'00 If Other\n";
	cout << "Your Selection: ";
	cin >> choice;
	system("cls");
	while (choice < 0 || choice >9)
	{
		cout << "ERROR!! Invalid selection\n";
		cout << "Select in range of 00-9: ";
		cin >> choice;
		system("cls");
	}
	return choice;
}






void display(int  patientChoice)
{
	switch (patientChoice)
	{
	case 1:
	{
		ifstream fin;
		fin.open("type1.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;

	case 2:
	{
		ifstream fin;
		fin.open("type2.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;

	case 3:
	{
		ifstream fin;
		fin.open("type3.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;

	case 4:
	{
		ifstream fin;
		fin.open("type4.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;

	case 5:
	{
		ifstream fin;
		fin.open("type5.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;

	case 6:
	{
		ifstream fin;
		fin.open("type6.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;

	case 7:
	{
		ifstream fin;
		fin.open("type7.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;

	case 8:
	{
		ifstream fin;
		fin.open("type8.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;

	case 9:
	{
		ifstream fin;
		fin.open("type9.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;

	case 00:
	{
		ifstream fin;
		fin.open("type00.txt");
		if (!fin)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			while (fin)
			{
				string line;
				getline(fin, line);
				cout << line << endl;
			}


		}
		fin.close();
	}
	break;


	}

}




int  confirmation()
{
	int next;
	cout << "\n\tARE YOU COMFORTABLE WITH THE DOCTOR!!" << endl;
	cout << "1. Yes\n2. No" << endl;
	cin >> next;
	system("cls");
	while (next < 1 || next>2)
	{
		cout << "ERROR!! Invalid selection\n";
		cout << "Select 1 OR 2: ";
		cin >> next;
		system("cls");
	}
	if (next == 1)
	{
		int choice;
		cout << "Select your payment method\n";
		cout << "1. Easypesa" << endl;
		cout << "2. JazzCash" << endl;
		cout << "3. Online Banking Services" << endl;
		cout << "4. If Other" << endl;
		cout << "Your Selection: ";
		cin >> choice;
		system("cls");
		while (choice < 1 || choice >4)
		{
			cout << "ERROR!! Invalid selection\n";
			cout << "Select 1 , 2 , 3 OR 4: ";
			cin >> choice;
			system("cls");
		}
		if (choice == 4)
		{
			string method;
			cout << "\n Please Mention the Name of the Method";
			cin >> method;
			cout << "We will include it as soon as possible\n";
		}

	}
	else
	{
		return next;
	}
}





void appointment(int agree)
{
	PatientInfo patient;
	cout << "Enter Patient Name: ";
	cin.ignore();
	getline(cin, patient.name);
	cout << "Gender: ";
	getline(cin, patient.gender);
	cout << "Disease: ";
	getline(cin, patient.disease);

	cout << "\n\nYour Appointment is Confirmed Successfully\nThank You\n";
	if (serial == 1)
	{
		ofstream fout;
		fout.open("ListOfPatient.txt");
		if (!fout)
		{
			cout << "ERROR!!\n";
			cout << "Some technical error occur Please try again later!!";
		}
		else
		{
			fout << "Serial.No: " << serial << endl;
			fout << "Name: " << patient.name << endl;
			fout << "Gender: " << patient.gender << endl;
			fout << "Disease: " << patient.disease << endl;
			serial++;

		}
		fout.close();
	}

}
