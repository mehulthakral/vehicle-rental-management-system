#include "pch.h"
#include<stdlib.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include<time.h>

using namespace std;

void sleep(int microseconds) // Cross-platform sleep function
{
	clock_t time_end;
	time_end = clock() + microseconds * CLOCKS_PER_SEC / 1000000;
	while (clock() < time_end) {}
}

int main()
{

	int ch, veh, lor, wish , in ;
	Beginning:
	wish = 0, in = 0;
	string person,reg;
	cout << "MAIN MENU" << endl<<endl;
	cout<< "Welcome to Vehicle Rental Management System" << endl;
	sleep(500000);//for time lag in microseconds
	cout<< "Do you want to " << endl << "1)Put your vehicle on rent  " << endl << "2)Get a rented vehicle" << endl;
	do
	{
		cout<< "Enter your choice 1 or 2: " << endl;
		cin >> ch;
		int found = 0;
		switch (ch)
		{			
			case 1:
			Login:
			system("clear");
			//admin code here
			cout<< "Welcome to the best vehicle rental facility" << endl;
			cout<< "You are few steps away from putting your vehicle on rent" << endl<<endl;
			sleep(500000);
			cout<< "Enter 1)Login "<<endl<<"2)Register " << endl << "3)Exit to Main Menu " << endl << "4)Exit Application" << endl;
			do
			{
				cout<< "Enter your choice 1 or 2: " << endl;
				cin >> lor;
				switch (lor)
				{
				case 1:
				{
					do
					{
						cout<< "Enter your username and password (Use spaces or enter to input) :" << endl;
						string usnl, passwordl;
						cin >> usnl >> passwordl;
						string name, usn, password, email;
						ifstream admin;
						admin.open("admin.txt", ios::in);
						while (!admin.eof())
						{
							admin >> usn >> password >> name >> email;
							//cout<< usn << password << endl;
							int x = usn.compare(usnl);
							int y = password.compare(passwordl);
							if (x == 0 && y == 0 || found)
							{
								found = 1;
								break;
							}
						}
						if (found == 0)
						{
							cout<< "Invalid username or password" << endl;
							cout<< "Do you want to register( Yes(Y)/No(N) )" << endl;
							cin >> reg;
							if (reg == "Yes" || reg == "yes" || reg == "Y" || reg == "y")
								goto HERE;
							else if (reg == "No" || reg == "no" || reg == "N" || reg == "n")
								goto Beginning;
							else
								printf("Reenter Details.");
						}


						if (found == 1)
							person = name;
						in = 1;
					} while (!found);

					break;
				}

				case 2:
				{
					HERE:
					cout<< "Enter name,username,password and email address (Use spaces or enter to input) :" << endl;
					string name, usn, password, email;
					cin >> name >> usn >> password >> email;
					ofstream adminfile;
					adminfile.open("admin.txt", ios::app);
					adminfile << usn << " " << password << " " << name << " " << email << endl;
					person = name;
					adminfile.close();
					cout<< "You have been sucessfully registered!!" << endl;
					sleep(500000);
					in = 1;
					break;
				}

				case 4:
				{
					cout << "Thanks for visiting us!!" << endl;
					sleep(500000);
					return 0;
				}
				case 3:
				{
					system("clear");
					goto Beginning;
				}

				default: {printf("Invalid Option. Try Again");sleep(100000);}
				}
			} while (!(lor == 1 || lor == 2 || lor==3 ||lor==4));

			if (in)
			{
				system("clear");
				cout<< "Congrats " << person << " are in now, you can add your vehicle" << endl;
				sleep(800000);
				cout<< "Which vehicle do you want to put on rent" << endl;
				cout << "1)Car" << endl << "2)Motor Bike" << endl << "3)Bike" << endl << "4) Exit to Main Menu" << endl<<"5) Exit the Application"<<endl;
				do
				{
					cout<< "Enter your choice 1 , 2 or 3: " << endl;
					cin >> veh;
					switch (veh)
					{
					case 1: {
						cout<< "Enter car name,model,car number,type(suv/normal),fuel type,no.of seats,mileage in km/l,base fare,fare per day" << endl<< "(Use spaces or enter to input) : "<<endl;
						string name, num, type, ftype, model;
						int numseats;
						double mileage, bfare, dfare;
						cin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
						ofstream carfile;
						carfile.open("car.txt", ios::app);
						carfile << name << " " << model << " " << num << " " << type << " " << ftype << " " << numseats << " " << mileage << " " << bfare << " " << dfare << endl;
						carfile.close();
						cout<< "Car has been sucessfully added!!" << endl;
						sleep(500000);
						cout<< "Do you want to add more vehicles 0)No 1)Yes" << endl;
						cin >> wish;
						break;
					}

					case 2: {
						cout<< "Enter  motorbike name,model,motorbike number,type(sports/normal),fuel type,no.of seats,mileage in km/l,base fare,fare per day" << endl;
						string name, num, type, ftype, model;
						int numseats;
						double mileage, bfare, dfare;
						cin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
						ofstream mbikefile;
						mbikefile.open("mbike.txt", ios::app);
						mbikefile << name << " " << model << " " << num << " " << type << " " << ftype << " " << numseats << " " << mileage << " " << bfare << " " << dfare << endl;
						mbikefile.close();
						cout<< "Motorbike has been sucessfully added!!" << endl;
						sleep(2000000);
						cout<< "Do you want to add more vehicles 0)No 1)Yes" << endl;
						cin >> wish;
						break;
					}

					case 3: {
						cout<< "Enter  bike name,model,bike number,type(geared/normal),base fare,fare per day" << endl;
						string name, num, model, type;
						double bfare, dfare;
						cin >> name >> model >> num >> type >> bfare >> dfare;
						ofstream bikefile;
						bikefile.open("bike.txt", ios::app);
						bikefile << name << " " << model << " " << num << " " << type << " " << bfare << " " << dfare << endl;
						bikefile.close();
						cout<< "Bike has been sucessfully added!!" << endl;
						sleep(2000000);
						cout<< "Do you want to add more vehicles 0)No 1)Yes" << endl;
						cin >> wish;
						break;
					}

					case 4:break;

					case 5: 
					{
						cout << "Thanks for visiting us!!" << endl;
						return 0;
					}

					default:cout<< "Enter valid choice" << endl;
						cout<< "Enter 4 if don't want to add a vehicle " << endl;
					}

					if (veh == 4)
					{
						system("clear");
						goto Beginning;
						break;
					}

				} while (!(veh == 1 || veh == 2 || veh == 3) || wish);
			}

			break;
		case 2:system("clear");
			//insert user code here

			break;

		case 3:break;

		default:cout<< "Enter valid choice" << endl;
			cout<< "Enter 3 if not interested anymore" << endl;
			//here we can add code to just display them our collection of vehicles 
			//so they get motivated to put their vehicle or rent a vehicle.
		}
		if (ch == 3)
		{
			cout<< "Thanks for visiting us!!" << endl;
			break;
		}

	} while (!(ch == 1 || ch == 2));

	return 0;
}
