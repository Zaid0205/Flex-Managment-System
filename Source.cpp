#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<conio.h>
using namespace std;
class teacherssecondry
{

public:

	void viewAllTeachers()
	{
		string t_id, f_n, l_n, u_n, mail, d, r_date, g, q, c_n, Teacher_ID;
		cout << "Enter the teacher ID = ";
		cin >> Teacher_ID;
		ifstream vt;
		vt.open("teacher.txt");
		while (!vt.eof()) {
			vt >> t_id;
			vt >> f_n;
			vt >> l_n;
			vt >> u_n;
			vt >> mail;
			vt >> d;
			vt >> r_date;
			vt >> g;
			vt >> q;
			vt >> c_n;

			if (t_id == Teacher_ID) {
				cout << "\nName = " << f_n << " " << l_n << endl;
				cout << "Gender = " << g << endl;
				cout << "Qualification = " << q << endl;
				cout << "Contact number = " << c_n << endl;
				exit(0);
				break;
			}
			/*else if (t_id == "") {
				continue;
			}
			else if (t_id != Teacher_ID) {
				continue;
			}*/
		}
		string done;
		done = _getch();
		vt.close();
	}
	void teachermenu(int& choice)
	{
		cout << "<<<<-----------------WELCOME!----------------->>>>\n";
		cout << "\t\tMAIN MENU:\n";
		cout << "\t1. Add Teacher in File\n";
		cout << "\t2. Search Teacher from File\n";
		cout << "\t3. Update Teacher in File\n";
		cout << "\t4. View Teacher Data in File\n";
		cout << "\t5. Exit The Program\n";
		cout << "\tChoose an option:\n";
		cout << "<<<<------------------------------------------>>>>\n";
		cin >> choice;
		while (choice < 1 || choice > 5)
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid entry! enter again:";
			cin >> choice;
			system("cls");
		}
	}
	void insert(string fname, string Tid, string  firstn, string lastn, string username, string email, string regdate, string gender, string bloodgrp, string contact, string depart)
	{
		fstream ip;
		ip.open(fname, ios::app);
		ip << "\t" << firstn << "\t" << lastn << "\t" << username << "\t" << email << "\t" << depart << "\t" << regdate << "\t" << gender << "\t" << bloodgrp << "\t" << contact << "\t" << endl;
		ip.close();
	}

	void insert2(string fname, string Tid, string  firstn, string lastn, string username, string email, string regdate, string gender, string qual, string contact, string depart, string op)
	{
		//a.insert2(filename, Tidee, firstn, lastn, username, email, regdate, gender, qual, contact, depart, choif);

		fstream ip;
		ip.open(fname, ios::app);
		ip << Tid << "\t" << firstn << "\t" << lastn << "\t" << username << "\t" << email << "\t" << depart << "\t" << regdate << "\t" << gender << "\t" << qual << "\t" << contact << "\t" << op;
		ip.close();
	}

	void search(string fname, string ip)
	{
		string  firstn, lastn, username, email, regdate, gender, depart, contact;

		string id = "\0";
		fstream ip1;
		ip1.open(fname, ios::in);
		bool check = false;

		while (!ip1.eof())
		{
			ip1 >> id;
			ip1 >> firstn;
			ip1 >> lastn;
			ip1 >> username;
			ip1 >> email;
			ip1 >> regdate;
			ip1 >> gender;
			ip1 >> depart;
			ip1 >> contact;

			if (id != ip)
			{
				continue;
			}
			else
			{
				check = true;
				break;
			}
		}
		if (check == true)
		{
			cout << "The ID is Found\n";
			cout << "ID\tFirstname\tLastname\tUsername\tEmail\tDepartment\tRegdate\tGender\tBlood\tContact\t";
			cout << id << "\t" << firstn << "\t" << lastn << "\t" << username << "\t" << email << "\t" << depart << "\t" << regdate << "\t" << gender
				<< "\t" << contact << "\n";
		}
		else
		{
			cout << "The ID is Not Found\n";
		}
		ip1.close();
	}
	void display(string fname)
	{
		string temp = "\0";
		fstream ip1;
		ip1.open(fname, ios::in);
		int count = 1;
		cout << "\n\n";
		cout << "<<<<-------------MESSAGES!-------------------->>>>\n";
		while (!ip1.eof())
		{
			getline(ip1, temp);
			cout << temp << "\t" << endl;
			count++;
		}
		cout << "<<<<------------------------------------------>>>>\n";
		cout << "\n\n";
		ip1.close();
	}
	void update(string fname, string ip)
	{
		string  firstn, lastn, username, email, regdate, gender, depart, contact, qual;

		string file2name = "teacher.txt";

		string id = ip;

		fstream op;
		op.open(file2name, ios::out);

		fstream ip1;
		ip1.open(fname, ios::in);
		int count = 1;

		while (!ip1.eof())
		{
			ip1 >> id;
			ip1 >> firstn;
			ip1 >> lastn;
			ip1 >> username;
			ip1 >> email;
			ip1 >> regdate;
			ip1 >> gender;
			ip1 >> depart;
			ip1 >> contact;
			ip1 >> qual;

			if (id != ip)
			{
				op << id << "\t";
				op << firstn << "\t";
				op << lastn << "\t";
				op << username << "\t";
				op << email << "\t";
				op << depart << "\t";
				op << regdate << "\t";
				op << gender << "\t";
				op << qual << "\t";
				op << contact << "\n";
			}
			if (id == ip)
			{   //1	Saud	Arshad	saudd	saud@gmail.com	AI	23/9/2023	Male	PHD	0332321233	
				cout << "--ENTER NEW DETAILS--\n";
				cout << "Enter your ID\n";
				cin.ignore();
				getline(cin, id);
				cout << "Enter your First name\n";
				cin.ignore();
				getline(cin, firstn);
				cout << "Enter your Last name\n";
				getline(cin, lastn);
				cout << "Enter your username\n";
				getline(cin, username);
				cout << "Enter you email\n";
				getline(cin, email);
				cout << "Enter your department\n";
				getline(cin, depart);
				cout << "Enter your Registration date\n";
				getline(cin, regdate);
				cout << "Enter your gender\n";
				getline(cin, gender);
				cout << "Enter your Qualification\n";
				getline(cin, qual);
				cout << "Enter your contact\n";
				getline(cin, contact);

				op << ip << "\t";
				op << firstn << "\t";
				op << lastn << "\t";
				op << username << "\t";
				op << email << "\t";
				op << depart << "\t";
				op << regdate << "\t";
				op << gender << "\t";
				op << qual << "\t";
				op << contact << "\n";
			}

		}

		op.close();
		ip1.close();

		fstream ip2;
		ip2.open(file2name, ios::in);
		fstream op1;
		op1.open(fname, ios::out);

		while (!ip2.eof())
		{
			ip2 >> id;
			ip2 >> firstn;
			ip2 >> lastn;
			ip2 >> username;
			ip2 >> email;
			ip2 >> regdate;
			ip2 >> gender;
			ip2 >> depart;
			ip2 >> contact;

			op1 << id << "\t";
			op1 << firstn << "\t";
			op1 << lastn << "\t";
			op1 << username << "\t";
			op1 << email << "\t";
			op1 << regdate << "\t";
			op1 << gender << "\t";
			op1 << depart << "\t";
			op1 << contact << endl;
		}
		ip2.close();
		op1.close();
	}
};
class studentssecondry
{
public:

	void studentmenu(int& choice)
	{
		cout << "<<<<-----------------WELCOME!----------------->>>>\n";
		cout << "\t\tMain Menu:\n";
		cout << "\t1. Add Student in File\n";
		cout << "\t2. Search Student from File\n";
		cout << "\t3. Update Student in File\n";
		cout << "\t4. View Student Data in File\n";
		cout << "\t5. Exit The Program\n";
		cout << "\tChoose an option:\n";
		cout << "<<<<------------------------------------------>>>>\n";
		cin >> choice;

		while (choice < 1 || choice > 5)
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid entry! enter again:";
			cin >> choice;
			system("cls");
		}
	}


	void insert(string fname, string Tid, string  firstn, string lastn, string username, string depart, string regdate, string gender, string bloodgrp, string contact, string feeStatus, string address, string marks, char ch)
	{
		fstream ip;
		ip.open(fname, ios::app);
		ip << Tid << "\t" << firstn << "\t" << lastn << "\t" << username << "\t" << depart << "\t" << regdate << "\t" << gender << "\t" << bloodgrp << "\t" << contact << "\t" << feeStatus << "\t" << address << "\t" << marks << "\t" << endl;
		ip.close();
	}

	void viewAllStudents()
	{
		string s_id, s_fn, s_ln, s_un, s_mail, s_d, s_rdate, s_g, s_depart, s_cn, Student_ID;
		cout << "Enter the Student ID = ";
		cin >> Student_ID;
		ifstream vs;
		vs.open("student.txt");
		while (!vs.eof()) {
			vs >> s_id;
			vs >> s_fn;
			vs >> s_ln;
			vs >> s_un;
			vs >> s_mail;
			vs >> s_d;
			vs >> s_rdate;
			vs >> s_g;
			vs >> s_depart;
			vs >> s_cn;

			if (s_id == Student_ID) {
				cout << "\nName = " << s_fn << " " << s_ln << endl;
				cout << "Gender = " << s_g << endl;
				cout << "Department= " << s_depart << endl;
				cout << "Contact number = " << s_cn << endl;
				exit(0);
				break;
			}
			/*else if (s_id == "") {
				continue;
			}
			else if (s_id != Student_ID) {
				continue;
			}*/
		}
		string done;
		done = _getch();
		vs.close();
	}

	void viewFeeStatus()
	{

		string s_id, s_fn, s_ln, s_un, s_mail, s_d, s_rdate, s_g, s_fee, s_cn, Student_ID;
		cout << "Enter the Student ID = ";
		cin >> Student_ID;
		ifstream vf;
		vf.open("student.txt");
		while (!vf.eof()) {
			vf >> s_id;
			vf >> s_fn;
			vf >> s_ln;
			vf >> s_un;
			vf >> s_mail;
			vf >> s_d;
			vf >> s_rdate;
			vf >> s_g;
			vf >> s_fee;
			vf >> s_cn;

			if (s_id == Student_ID) {
				cout << "\nName = " << s_fn << " " << s_ln << endl;
				cout << "Department= " << s_fee << endl;
				cout << "Fee Status = " << s_cn << endl;
				break;
			}
			else if (s_id == "") {
				continue;
			}
			else if (s_id != Student_ID) {
				continue;
			}
		}
		string done;
		done = _getch();
		vf.close();



	}

	void search(string fname, string ip)
	{
		string  firstn, lastn, username, depart, regdate, gender, bloodgrp, contact, feeStatus, address, marks, password;

		string id = "\0";
		fstream ip1;
		ip1.open(fname, ios::in);
		bool check = false;

		while (!ip1.eof())
		{
			ip1 >> id;
			ip1 >> firstn;
			ip1 >> lastn;
			ip1 >> username;
			ip1 >> password;
			ip1 >> depart;
			ip1 >> regdate;
			ip1 >> gender;
			ip1 >> bloodgrp;
			ip1 >> contact;
			ip1 >> feeStatus;
			ip1 >> address;
			ip1 >> marks;

			if (id != ip)
			{
				continue;
			}
			else
			{
				check = true;
				break;
			}
		}
		if (check == true)
		{
			cout << "The ID is Found" << endl;
			cout << "ID: " << id << "\tFirst Name: " << firstn << "\tLast Name: " << lastn << "\tDepartment: " << depart << endl;
		}
		else
		{
			cout << "The ID is Not Found\n";
		}
		ip1.close();
	}
	void display(string fname)
	{
		string temp = "\0";
		fstream ip1;
		ip1.open(fname, ios::in);
		int count = 1;
		cout << "\n\n";
		cout << "<<<<-------------MESSAGES!-------------------->>>>\n";
		while (!ip1.eof())
		{
			getline(ip1, temp);
			cout << temp << "\t" << endl;
			count++;
		}
		cout << "<<<<------------------------------------------>>>>\n";
		cout << "\n\n";
		ip1.close();
	}
	void update(string fname, string ip)
	{
		string  firstn, lastn, depart, address, regdate, gender, bloodgrp, contact, feeStatus, st_address, marks;

		string file2name = "temp.txt";

		string id = ip;

		fstream op;
		op.open(file2name, ios::out);

		fstream ip1;
		ip1.open(fname, ios::in);
		int count = 1;

		while (!ip1.eof())
		{
			ip1 >> id;
			ip1 >> firstn;
			ip1 >> lastn;
			ip1 >> depart;
			ip1 >> address;
			ip1 >> regdate;
			ip1 >> gender;
			ip1 >> bloodgrp;
			ip1 >> contact;
			ip1 >> feeStatus;
			ip1 >> st_address;
			ip1 >> marks;

			if (id != ip)
			{
				op << id << "\t";
				op << firstn << "\t";
				op << lastn << "\t";
				op << depart << "\t";
				op << address << "\t";
				op << regdate << "\t";
				op << gender << "\t";
				op << bloodgrp << "\t";
				op << contact << "\t";
				op << feeStatus << "\t";
				op << st_address << "\t";
				op << marks << "\n";
			}
			else
			{
				cout << "Enter new details:\n";
				cout << "Enter you First name\n";
				cin.ignore();
				getline(cin, firstn);
				cout << "Enter your Last name\n";
				getline(cin, lastn);
				cout << "Enter your Department\n";
				getline(cin, depart);
				cout << "Enter you address\n";
				getline(cin, address);
				cout << "Enter your Registration date\n";
				getline(cin, regdate);
				cout << "Enter your gender\n";
				getline(cin, gender);
				cout << "Enter your Blood grp\n";
				getline(cin, bloodgrp);
				cout << "Enter your contact\n";
				getline(cin, contact);
				cout << "Fees Paid?\n";
				getline(cin, feeStatus);
				cout << "Enter your Address\n";
				getline(cin, st_address);
				cout << "Enter your Marks\n";
				getline(cin, marks);

				op << id << "\t";
				op << firstn << "\t";
				op << lastn << "\t";
				op << depart << "\t";
				op << address << "\t";
				op << regdate << "\t";
				op << gender << "\t";
				op << bloodgrp << "\t";
				op << contact << "\t";
				op << feeStatus << "\t";
				op << st_address << "\t";
				op << marks << "\n";

			}

		}

		op.close();
		ip1.close();

		fstream ip2;
		ip2.open(file2name, ios::in);
		fstream op1;
		op1.open(fname, ios::out);

		while (!ip2.eof())
		{
			ip2 >> id;
			ip2 >> firstn;
			ip2 >> lastn;
			ip2 >> depart;
			ip2 >> address;
			ip2 >> regdate;
			ip2 >> gender;
			ip2 >> bloodgrp;
			ip2 >> contact;
			ip2 >> feeStatus;
			ip2 >> st_address;
			ip2 >> marks;

			op1 << id << "\t";
			op1 << firstn << "\t";
			op1 << lastn << "\t";
			op1 << depart << "\t";
			op1 << address << "\t";
			op1 << regdate << "\t";
			op1 << gender << "\t";
			op1 << bloodgrp << "\t";
			op1 << contact << "\t";
			op1 << feeStatus << "\t";
			op1 << st_address << "\t";
			op1 << marks << endl;

		}
		ip2.close();
		op1.close();
	}
};
class Login
{
	string checkusername;
	string checkpassword;
	string username;
	string password;
	string defaultusername;
	string defaultpass;
	int decision;

	bool verifyusername(string x, string y)
	{
		fstream op;
		op.open("credentials.txt", ios::in);
		op >> checkusername;
		op >> checkpassword;
		op.close();
		if (checkusername == x && checkpassword == y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Login()
	{
		checkusername = "\0";
		checkpassword = "\0";
		defaultusername = "admin";
		defaultpass = "admin";
		username = "\0";
		password = "\0";
		decision = 0;

		fstream ip;
		ip.open("credentials.txt", ios::out);
		ip << defaultusername << "\t" << defaultpass;
		ip.close();
	}


	bool sign_in()
	{
		bool check = false;
		while (check != true)
		{
			cout << "--LOGIN DETAILS FOR ADMIN--" << endl;
			cout << "Enter Username and Password:\n";
			cin >> username;
			cin >> password;
			if (verifyusername(username, password) == true)
			{
				check = true;
				cout << "--YOU LOGGED IN AS AN ADMIN--" << endl;
				cout << endl;
			}
			else
			{
				cout << "Error! Wrong Credentials\n";
			}
		}
		return true;
	}
};
class AdminModule :public Login
{
	string filename = "teacher.txt";
	string filename1 = "student.txt";
	string filename2 = "student.txt";
	int tors = 0;
public:
	AdminModule()
	{

	}



	void menu()
	{

		if (sign_in() == true)
		{
			while (tors != 5)
			{
				cout << "ENTER 1 TO ACCESS TEACHER DATA\nENTER 2 TO ACCESS STUDENT DATA\nENTER 3 TO FIND TEACHER DATA\nENTER 4 FOR EXIT" << endl;
				cin >> tors;
				while (tors < 1 || tors> 4)
				{
					cin.clear();
					cin.ignore();
					cout << "Invalid entry! enter again:";
					cin >> tors;
					system("cls");
				}

				if (tors == 1)
				{
					teacherssecondry a;
					int x = 0;
					while (x != 1)
					{
						int choice = 0;

						a.teachermenu(choice);

						switch (choice)
						{
						case 1:
						{

							string  firstn, Tidee, lastn, username, email, regdate, gender, qual, contact, depart;
							cin.ignore();
							cout << "Enter you First name\n";
							getline(cin, firstn);
							cout << "Enter your Last name\n";
							getline(cin, lastn);
							cout << "Enter your username\n";
							getline(cin, username);
							cout << "Enter your department\n";
							getline(cin, depart);
							cout << "Enter your teacher ID\n";
							getline(cin, Tidee);
							cout << "Enter you email\n";
							getline(cin, email);
							cout << "Enter your Registration date\n";
							getline(cin, regdate);
							cout << "Enter your gender\n";
							getline(cin, gender);
							cout << "Enter your qualification\n";
							getline(cin, qual);
							cout << "Enter your contact\n";
							getline(cin, contact);
							string choif = "\n";
							a.insert2(filename, Tidee, firstn, lastn, username, email, regdate, gender, qual, contact, depart, choif);

							break;
						}

						case 2:
						{
							cout << "Enter TID to search\n";
							string temp = "\0";
							cin.ignore();
							getline(cin, temp);
							a.search(filename, temp);
							break;
						}
						case 3:
						{
							string ip;
							cout << "Enter TID to Update\n";
							cin.ignore();
							cin >> ip;
							a.update(filename, ip);
							break;
						}
						case 4:
						{
							a.display(filename);
							break;
						}
						case 5:
						{
							x = 1; break;
						}
						default:
						{
							cout << "Wrong Input! Enter again! ! !\n";
							break;
						}
						}
					}
					system("cls");
				}
				if (tors == 2)
				{
					studentssecondry b;
					int x = 0;
					while (x != 1)
					{
						int choice = 0;
						b.studentmenu(choice);

						switch (choice)
						{
						case 1:
						{
							string  Sid, firstn, lastn, depart, address, regdate, gender, bloodgrp, contact, feeStatus, st_address, marks;
							char lin = '\n';
							cin.ignore();
							cout << "Enter you First name\n";
							getline(cin, firstn);
							cout << "Enter your Last name\n";
							getline(cin, lastn);
							cout << "Enter your Department\n";
							getline(cin, depart);
							cout << "Enter your Student ID\n";
							getline(cin, Sid);
							cout << "Enter you address\n";
							getline(cin, address);
							cout << "Enter your Registration date\n";
							getline(cin, regdate);
							cout << "Enter your gender\n";
							getline(cin, gender);
							cout << "Enter your Blood grp\n";
							getline(cin, bloodgrp);
							cout << "Enter your contact\n";
							getline(cin, contact);
							cout << "Fee Paid?\n";
							getline(cin, feeStatus);

							cout << "Enter your Marks\n";
							getline(cin, marks);

							b.insert(filename2, Sid, firstn, lastn, depart, address, regdate, gender, bloodgrp, contact, feeStatus, st_address, marks, lin);
							break;
						}

						case 2:
						{
							cout << "Enter SID to search\n";
							string temp = "\0";
							cin.ignore();
							getline(cin, temp);
							b.search(filename2, temp);
							break;
						}
						case 3:
						{
							string ip;
							cout << "Enter SID to Update\n";
							cin.ignore();
							cin >> ip;
							b.update(filename2, ip);
							break;
						}
						case 4:
						{
							b.display(filename2);
							break;
						}
						case 5:
						{
							x = 1;
							break;
						}
						default:
						{
							cout << "Wrong Input! Enter again! ! !\n";
							break;
						}
						}
					}
					system("cls");
				}

				if (tors == 3)
				{
					teacherssecondry c;
					cout << ">DATA OF A SPECIFIC TEACHER:" << endl;
					c.viewAllTeachers();

				}

				if (tors == 4)
				{
					tors = 4;
					break;
				}
			}
		}
	}

};

class Member {
protected:
	string username;
	string password;
public:
	Member()
	{

	}
	Member(const string& username, const string& password) : username(username), password(password) {}
	virtual void displayInfo() = 0;
	friend bool signIn(const string& username, const string& password, const string& fileName);
};

class Student : public Member
{
private:
	string studentId;
	string firstName;
	string lastName;
	vector<double> marks;
public:


	Student();
	Student(const string& username, const string& password, const string& studentId, const string& firstName, const string& lastName) : Member(username, password), studentId(studentId), firstName(firstName), lastName(lastName) {}


	bool student_signIn()
	{

		string s_id, s_fn, s_ln, s_bg, s_add, s_d, s_rdate, s_g, s_fee, s_cn, s_mark, Student_ID;
		cout << "Enter the Student ID = ";
		cin >> Student_ID;
		ifstream vf;
		vf.open("student.txt");
		while (!vf.eof()) {
			vf >> s_id;
			vf >> s_fn;
			vf >> s_ln;
			vf >> s_d;
			vf >> s_add;
			vf >> s_rdate;
			vf >> s_g;
			vf >> s_bg;
			vf >> s_cn;
			vf >> s_fee;
			vf >> s_mark;
			if (s_id == Student_ID) {
				//1	Rafay	Mughal	BBA	Multan	1/1/2022	Male	O+	0321456789	PAID		88	

				cout << "--LOGIN SUCCESSFUL--" << endl;
				cout << "\n>Name = " << s_fn << " " << s_ln << endl;
				cout << ">Department= " << s_d << endl;
				cout << ">Student ID= " << s_id << endl;
				break;
				return true;
			}


		}
		string done;
		done = _getch();
		vf.close();

		return false;


	}

	void viewFeeStatus()
	{

		string s_id, s_fn, s_ln, s_bg, s_add, s_d, s_rdate, s_g, s_fee, s_cn, s_mark, Student_ID;
		cout << "Enter the Student ID = ";
		cin >> Student_ID;
		ifstream vf;
		vf.open("student.txt");
		while (!vf.eof()) {
			vf >> s_id;
			vf >> s_fn;
			vf >> s_ln;
			vf >> s_d;
			vf >> s_add;
			vf >> s_rdate;
			vf >> s_g;
			vf >> s_bg;
			vf >> s_cn;
			vf >> s_fee;
			vf >> s_mark;
			if (s_id == Student_ID) {

				cout << "--LOGIN SUCESSFULL--" << endl;
				cout << "\n>Name = " << s_fn << " " << s_ln << endl;
				cout << ">Department= " << s_d << endl;
				cout << ">Student ID = " << s_id << endl;
				break;
			}
			else if (s_id == "") {
				continue;
			}
			else if (s_id != Student_ID) {
				continue;
			}
		}
		string done;
		done = _getch();
		vf.close();



	}
	void displayInfo()
	{
		/*cout << "Student ID: " << studentId << endl;
		cout << "Name: " << firstName << " " << lastName << endl;
		cout << "Registered Courses: "<<endl;

		cout << endl;
		cout << "Marks: ";
		for (double mark : marks)
		{
			cout << mark << "\t ";
		}
		cout << endl;*/
	}
	void viewRegisteredCourses()
	{
		cout << endl;
		cout << "1-  COMMUNICATION AND PRESENTATION SKILLS " << endl;
		cout << "2-  OBJECT ORIENTED PROGRAMMING " << endl;
		cout << "3-  DIGITAL LOGIC DESIGN" << endl;
		cout << "4-  DIFFERENTIAL EQUATIONS" << endl;
		cout << endl;
	}
	void viewAttendance() {
		ifstream file("attendance.txt");
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	void viewMarks() {
		ifstream file("marks.txt");
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	void viewGrades() {
		ifstream file("grades.txt");
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}


	void viewAllStudents()
	{
		string s_id, s_fn, s_ln, s_un, s_mail, s_d, s_rdate, s_g, s_depart, s_cn, Student_ID;
		cout << "Enter the Student ID = ";
		cin >> Student_ID;
		ifstream vs;
		vs.open("student.txt");
		while (!vs.eof()) {
			vs >> s_id;
			vs >> s_fn;
			vs >> s_ln;
			vs >> s_un;
			vs >> s_mail;
			vs >> s_d;
			vs >> s_rdate;
			vs >> s_g;
			vs >> s_depart;
			vs >> s_cn;

			if (s_id == Student_ID) {
				cout << "\nName = " << s_fn << " " << s_ln << endl;
				cout << "Gender = " << s_g << endl;
				cout << "Department= " << s_depart << endl;
				cout << "Contact number = " << s_cn << endl;
				break;
			}
			else if (s_id == "") {
				continue;
			}
			else if (s_id != Student_ID) {
				continue;
			}
		}
		string done;
		done = _getch();
		vs.close();
	}

};

class Teacher : public Member {
private:
	string teacherId;
	string firstName;
	string lastName;
public:
	Teacher()
	{

	}
	Teacher(const string& username, const string& password, const string& teacherId, const string& firstName, const string& lastName)
		: Member(username, password), teacherId(teacherId), firstName(firstName), lastName(lastName) {}



	bool teacher_signIn()
	{

		string t_id, f_n, l_n, u_n, mail, d, r_date, g, q, c_n, Teacher_ID;
		cout << "Enter the teacher ID = ";
		cin >> Teacher_ID;
		ifstream vt;
		vt.open("teacher.txt");
		while (!vt.eof()) {
			vt >> t_id;
			vt >> f_n;
			vt >> l_n;
			vt >> u_n;
			vt >> mail;
			vt >> d;
			vt >> r_date;
			vt >> g;
			vt >> q;
			vt >> c_n;
			//1	Usman	Azhar	Ajjay	usman@gmail.com	CS	1/2/2022	Male	MS	0303939393	
			if (t_id == Teacher_ID) {
				cout << "----LOGIN SUCCESSFULL---" << endl;
				cout << "\nName = " << f_n << " " << l_n << endl;
				cout << "Teacher ID = " << t_id << endl;
				ofstream putting("teachersActivity.txt", ios::app);
				putting << "Teacher ID" << t_id << "Logged in" << endl;
				putting.close();
				return true;
			}

		}
		string done;
		done = _getch();
		vt.close();
		return false;
	}
	void displayInfo() {
		cout << "Teacher ID: " << teacherId << endl;
		cout << "Name: " << firstName << " " << lastName << endl;
	}
	void viewTimeTable() {
		ifstream file("timetable.txt");
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
		ofstream putting("teachersActivity.txt", ios::app);
		putting << "Time Table viewed" << endl;
		putting.close();
	}
	void markAttendance(const string& studentId, const string& date, const string& status) {
		ofstream file("attendance.txt", ios::app);
		file << "Student ID: " << studentId << ", Date: " << date << ", Status: " << status << endl;
		file.close();
		ofstream putting("teachersActivity.txt", ios::app);
		putting << "Mark Attendence of student ID " << studentId << "of date " << date << endl;
		putting.close();
	}
	void assignMarks(const string& studentId, const string& marks) {
		ofstream file("marks.txt", ios::app);
		file << "Student ID: " << studentId << ", Marks: " << marks << endl;
		file.close();
		ofstream putting("teachersActivity.txt", ios::app);
		putting << "Assign marks of student ID " << studentId << endl;
		putting.close();
	}
	void assignGrades(const string& studentId, const string& grade) {
		ofstream file("grades.txt", ios::app);
		file << "Student ID: " << studentId << ", Grade: " << grade << endl;
		file.close();
		ofstream putting("teachersActivity.txt", ios::app);
		putting << "Assign Grades of student ID " << studentId << endl;
		putting.close();
	}

	void viewAllTeachers()
	{
		string t_id, f_n, l_n, u_n, mail, d, r_date, g, q, c_n, Teacher_ID;
		cout << "Enter the teacher ID = ";
		cin >> Teacher_ID;
		ifstream vt;
		vt.open("teacher.txt");
		while (!vt.eof()) {
			vt >> t_id;
			vt >> f_n;
			vt >> l_n;
			vt >> u_n;
			vt >> mail;
			vt >> d;
			vt >> r_date;
			vt >> g;
			vt >> q;
			vt >> c_n;
			//1	Usman	Azhar	Ajjay	usman@gmail.com	CS	1/2/2022	Male	MS	0303939393	
			if (t_id == Teacher_ID) {
				cout << "\nName = " << f_n << " " << l_n << endl;
				cout << "Gender = " << g << endl;
				cout << "Qualification = " << q << endl;
				cout << "Contact number = " << c_n << endl;
				break;
			}
			else if (t_id == "") {
				continue;
			}
			else if (t_id != Teacher_ID) {
				continue;
			}
		}
		string done;
		done = _getch();
		vt.close();
	}

};


class HOD :public teacherssecondry, public studentssecondry
{
public:


	bool hod_signIn()
	{

		string t_id, f_n, l_n, u_n, mail, d, r_date, g, q, c_n, Teacher_ID;
		cout << "Enter the Hod ID = ";
		cin >> Teacher_ID;
		ifstream vt;
		vt.open("hod.txt");
		while (!vt.eof()) {
			vt >> t_id;
			vt >> f_n;
			vt >> l_n;
			vt >> u_n;
			vt >> mail;
			vt >> d;
			vt >> r_date;
			vt >> g;
			vt >> q;
			vt >> c_n;
			//1	Usman	Azhar	Ajjay	usman@gmail.com	CS	1/2/2022	Male	MS	0303939393	
			if (t_id == Teacher_ID) {
				cout << "----LOGIN SUCCESSFULL---" << endl;
				cout << "\nName = " << f_n << " " << l_n << endl;
				cout << "Teacher ID = " << t_id << endl;
				return true;
			}

		}
		string done;
		done = _getch();
		vt.close();
		return false;
	}

};
int main()
{

	system("color 3");
	cout << endl;
	cout << endl;
	cout << "\t      88888888888888888    88             8888888888888   88          88                       \n";
	cout << "\t      88                   88             88               88        88          \n";
	cout << "\t      88                   88             88                88      88           \n";
	cout << "\t      88                   88             88                 88    88             \n";
	cout << "\t      88                   88             88                  88  88              \n";
	cout << "\t      8888888888888888     88             8888888888888         88                \n";
	cout << "\t      88                   88             88                   88 88               \n";
	cout << "\t      88                   88             88                 88     88               \n";
	cout << "\t      88                   88             88                88       88            \n";
	cout << "\t      88                   88888888888    8888888888888    88         88            \n";

	cout << endl;
	cout << endl;
	cout << "\tWELCOME TO FLEX MANAGEMENT SYSTEM!" << endl;
	int option;
	cout << ">Enter 1 to SignIn as a Admin\n>Enter 2 to SignIn as a Teacher\n>Enter 3 to SignIn as a Student\n>Enter 4 to SignIn as a Hod\n>Enter 5 to Exit the Program\nYour Choice : ";
	cin >> option;
	while (option < 1 || option > 5)
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid entry! enter again:";
		cin >> option;

	}
	string studentFile = "students.txt";
	string teacherFile = "teachers.txt";
	string studentUsername, studentPassword;
	string teacherUsername, teacherPassword;
	bool studentSignInSuccess = false, teacherSignInSuccess = false;
	string username, password, teacherId, firstName, lastName, studentId, grade, st_marks, date, feeStatus;
	string st_username, st_password, st_firstName, st_lastname, st_grade, s_marks, st_date, st_feeStatus;
	AdminModule a;
	HOD hod_log;
	int hod_option = 0;

	switch (option)
	{
	case 1:
	{
		a.menu();
		break;
	}
	case 2:
	{

		Teacher t(username, password, teacherId, firstName, lastName);
		if (t.teacher_signIn() != true) {
			cout << "-----WRONG ID SIR! LOGIN FAIL-----";
			exit(0);
		}
		cout << endl;
		cout << endl;
		int option;
		do
		{
			cout << endl;
			cout << ">Enter 1 to Assign Grades\n>Enter 2 to Assign Marks\n>Enter 3 to Mark Attendance\n>Enter 4 to View TimeTable\n>Enter 5 to Exit\nYour Choice : ";
			cin >> option;
			while (option < 1 || option > 5)
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid entry! enter again:";
				cin >> option;
			}
			switch (option)
			{
			case 1:
			{

				cout << "Enter the Student ID: ";
				cin >> studentId;
				cout << "Enter the Grade: ";
				cin >> grade;
				t.assignGrades(studentId, grade);

				break;
			}
			case 2:
			{
				cout << "Enter the Student ID: ";
				cin >> studentId;
				cout << "Enter the Marks: ";
				cin >> st_marks;
				t.assignMarks(studentId, st_marks);

				break;
			}
			case 3:
			{
				cout << "Enter the Student ID: ";
				cin >> studentId;
				cout << "Enter the Date:";
				cin >> date;
				cout << "Enter the Fee Status: ";
				cin >> feeStatus;
				t.markAttendance(studentId, date, feeStatus);
				break;
			}
			case 4:
			{
				t.viewTimeTable();
				break;
			}
			case 5:
			{
				break;
			}
			default:
			{
				cout << "Invalid Input!" << endl;
				break;
			}
			}

		} while (option != 5);
		break;


	}
	case 3:
	{
		cout << endl;
		int st_option = 0;
		Student s(st_username, st_password, studentId, st_firstName, st_lastname);
		if (s.student_signIn() == false)
		{
			cout << "WRONG STUDENT ID";
			exit(0);
		}
		do
		{
			cout << "--TEACHER FUNCTIONS ACCESSED--" << endl;
			cout << ">Enter 1 to View Attendance\n>Enter 2 to View Marks\n>Enter 3 to View Registered Courses\n>Enter 4 to View Grades\n>Enter 5 to Fee Status\n>Enter 6 to Exit\nYour Choice : ";
			cin >> option;
			while (option < 1 || option > 6)
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid entry! enter again:";
				cin >> option;
			}
			switch (option)
			{
			case 1:
			{
				s.viewAttendance();

				break;
			}
			case 2:
			{
				s.viewMarks();
				break;
			}
			case 3:
			{
				s.viewRegisteredCourses();
				break;
			}
			case 4:
			{
				s.viewGrades();
				break;
			}
			case 5:
			{
				s.viewFeeStatus();
				break;
			}
			case 6:
			{

				break;
			}
			default:
			{
				cout << "Invalid Input!" << endl;
				break;
			}
			}

		} while (option != 6);
	}break;
	case 4:
	{
		ifstream re("teachersActivity.txt");
		char c;
		if (hod_log.hod_signIn() == false)
		{
			cout << "Wrong inforation" << endl;
			exit(0);
		}

		cout << "ENTER 1 TO VIEW TEACHERS\nENTER 2 TO VIEW STUDENTS\nENTER 3 FOR HOD AS TEACHER\nENTER 4 TO VIEW TEACHER ACTIVITY\nENTER 5 TO EXIT" << endl;
		cin >> hod_option;
		while (hod_option < 1 || hod_option > 5)
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid entry! enter again:";
			cin >> hod_option;
		}
		do
		{

			switch (hod_option)
			{

			case 1:
				hod_log.viewAllTeachers();
				break;
			case 2:
				hod_log.viewAllStudents();
				break;
			case 3:
				cout << "\t YOUR DATA HAS BEEN ADDED TO TEACHER FILE. YOU HAVE LOGGED IN AS TEACHER TO TEACH COURSES\n";
			case 4:
				while (!re.eof())
				{
					re.get(c);
					cout << c;
					if (re.eof()) {

						system("pause");
						exit(0);
					}
				}
				break;
			case 5:

				exit(0);
				break;
			}
		} while (hod_option != 5);

		break;
	}
	}
	system("pause");
	return 0;
}