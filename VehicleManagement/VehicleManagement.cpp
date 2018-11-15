#include "pch.h"
#include<stdlib.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include<time.h>

using namespace std;

void user_code();
void sleep(int microseconds) // Cross-platform sleep function
{
	clock_t time_end;
	time_end = clock() + microseconds * CLOCKS_PER_SEC / 1000000;
	while (clock() < time_end) {}
}
void display_car_motorbike(string vehicle,string name , string  model , string  num , string  type , string  ftype ,int numseats , double mileage , double  bfare, double  dfare)
{
	printf("****************************\n");
	printf("Type: %s\n",vehicle.c_str());
	printf("****************************\n");
	printf("Name: %s\n", name.c_str());
	printf("Model: %s \t\t Car Number: %s \n",model.c_str(),num.c_str());
	printf("Type: %s \t\t Fuel Type: %s\n",type.c_str(),ftype.c_str());
	printf("Seats: %s \t\t Mileage: %s\n",to_string(numseats).c_str(), to_string(mileage).c_str());
	printf("Base Fare: %s \t\t Fare per day: %s\n", to_string(bfare).c_str(), to_string(dfare).c_str());

}
void display_bike(string name, string  model, string  num, string  type, double  bfare, double  dfare)
{
	printf("****************************\n");
	printf("Type: Bike\n");
	printf("****************************\n");
	printf("Name: %s\n", name.c_str());
	printf("Model: %s \t\t Car Number: %s \n", model.c_str(), num.c_str());
	printf("Type: %s\n", type.c_str());
	printf("Base Fare: %s \t\t Fare per day: %s\n", to_string(bfare).c_str(), to_string(dfare).c_str());
}

int main()
{

	int ch, veh, lor, wish , in ;
	bool getVehicle = false;
	Beginning:
	wish = 0, in = 0;
	string person,reg,usnl,emailid;
	cout << "MAIN MENU" << endl<<endl;
	cout<< "Welcome to Vehicle Rental Management System" << endl;
	sleep(500000);//for time lag in microseconds
	cout<< "Do you want to " << endl << "1)Put your vehicle on rent  " << endl << "2)Get a rented vehicle" << endl << "3) Exit"<< endl;
	do
	{
		printf("\n");
		cout<< "Enter your choice : ";
		cin >> ch;
		int found = 0;
		switch (ch)
		{	
		case 1:
			{
				system("clear");
				//admin code here
				printf("ADMINISTRATOR:\n\n");
				cout << "Welcome to the best vehicle rental facility" << endl;
				cout << "You are few steps away from putting your vehicle on rent" << endl << endl;
				sleep(500000);
				UserLogin:
				cout << "Enter " << endl << "1)Login " << endl << "2)Register " << endl << "3)Exit to Main Menu " << endl << "4)Exit Application" << endl;
				do
				{

					printf("\n");
					cout << "Enter your choice 1 or 2: ";
					cin >> lor;
					switch (lor)
					{

					case 1:
					{
						do
						{
							cout << "Enter your username and password (Use spaces or enter to input) :" << endl;
							string passwordl;
							cin >> usnl >> passwordl;
							string name, usn, password, email;
							ifstream admin;
							
							if(getVehicle)
								admin.open("user.txt", ios::in);
							else
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
									emailid = email;
									break;
								}
							}
							if (found == 0)
							{
								cout << "Invalid username or password" << endl;
								cout << "Do you want to register( Yes(Y)/No(N) )" << endl;
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

							if (getVehicle)	in = 2;
							else in = 1;
							
							admin.close();
						} while (!found);

						break;
					}

					case 2:
					{
					HERE:
						system("clear");
						cout << "Enter name,username,password and email address (Use spaces or enter to input) :" << endl;
						string name, password, email;
						cin >> name >> usnl >> password >> email;
						ofstream adminfile;

						if (getVehicle)
							adminfile.open("user.txt", ios::app);
						else
							adminfile.open("admin.txt", ios::app);

						adminfile << usnl << " " << password << " " << name << " " << email << endl;
						person = name;
						emailid = email;
						adminfile.close();
						cout << "You have been sucessfully registered!!" << endl;
						sleep(500000);

						if (getVehicle)	in = 2;
						else in = 1;

						ofstream temp;
						if (!getVehicle)
							temp.open(usnl + "_admin.txt", ios::out);
						else
							temp.open(usnl + "_user.txt", ios::out);
						temp.close();
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
				} while (!(lor == 1 || lor == 2 || lor == 3 || lor == 4));

				if (in==1)
				{
					cout << "Congrats " << person << " are in now, you can add your vehicle" << endl<<endl;
					sleep(800000);
					Admin:
					system("clear");
					sleep(800000);
					printf("Admin name: %s\t Email Id: %s\n\n", person.c_str(),emailid.c_str());
					cout << "Which vehicle do you want to put on rent" << endl;
					cout << "1) Car" << endl << "2) Motor Bike" << endl << "3) Bike" << endl << "4) See you rented Vehicles" << endl << "5) Exit to Main Menu" << endl << "6) Exit the Application" << endl;
					do
					{
						printf("\n");
						cout << "Enter your choice : ";
						cin >> veh;
						ofstream adminfile;
						adminfile.open(usnl+"_admin.txt", ios::app);
						switch (veh)
						{
							system("clear");
						case 1: {
							cout << "Enter car name,model,car number,type(suv/normal/other),fuel type,no.of seats,mileage in km/l,base fare,fare per day" << endl << "(Use spaces or enter to input) : " << endl;
							string name, num, type, ftype, model;
							int numseats;
							double mileage, bfare, dfare;
							cin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
							ofstream carfile;
							carfile.open("car.txt", ios::app);
							carfile << name << " " << model << " " << num << " " << type << " " << ftype << " " << numseats << " " << mileage << " " << bfare << " " << dfare << endl;
							carfile.close();
							cout << "Car has been sucessfully added!!" << endl;
							sleep(500000);
							cout << "Do you want to add more vehicles 0)No 1)Yes" << endl;
							cin >> wish;
							adminfile <<"Car" << endl << name << " " << model << " " << num << " " << type << " " << ftype << " " << numseats << " " << mileage << " " << bfare << " " << dfare << endl;
							break;
						}

						case 2: {
							cout << "Enter  motorbike name,model,motorbike number,type(sports/normal/other),fuel type,no.of seats,mileage in km/l,base fare,fare per day" << endl;
							string name, num, type, ftype, model;
							int numseats;
							double mileage, bfare, dfare;
							cin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
							ofstream mbikefile;
							mbikefile.open("mbike.txt", ios::app);
							mbikefile << name << " " << model << " " << num << " " << type << " " << ftype << " " << numseats << " " << mileage << " " << bfare << " " << dfare << endl;
							mbikefile.close();
							cout << "Motorbike has been sucessfully added!!" << endl;
							sleep(500000);
							cout << "Do you want to add more vehicles 0)No 1)Yes" << endl;
							cin >> wish;
							adminfile<<"Motorbike" << endl << name << " " << model << " " << num << " " << type << " " << ftype << " " << numseats << " " << mileage << " " << bfare << " " << dfare << endl;
							break;
						}

						case 3: {
							cout << "Enter  bike name,model,bike number,type(geared/normal/other),base fare,fare per day" << endl;
							string name, num, model, type;
							double bfare, dfare;
							cin >> name >> model >> num >> type >> bfare >> dfare;
							ofstream bikefile;
							bikefile.open("bike.txt", ios::app);
							bikefile << name << " " << model << " " << num << " " << type << " " << bfare << " " << dfare << endl;
							bikefile.close();
							cout << "Bike has been sucessfully added!!" << endl;
							sleep(500000);
							cout << "Do you want to add more vehicles 0)No 1)Yes" << endl;
							adminfile<<"Bike" <<endl<< name << " " << model << " " << num << " " << type << " " << bfare << " " << dfare << endl;
							cin >> wish;
							break;
						}
						adminfile.close();
						case 4:
						{
							system("clear");
							ifstream admin;
							admin.open(usnl+"_admin.txt", ios::in);
							int cnt = 0;string vehicle = "Car";

							while (!admin.eof())
							{
								if (cnt % 2 == 0)
								{
									admin >> vehicle;
									cnt++;
									continue;
								}

								if (vehicle.compare("Car")==0)
								{
									string name, num, type, ftype, model;
									int numseats;
									double mileage, bfare, dfare;

									admin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
									display_car_motorbike("Car",name, model, num, type, ftype, numseats, mileage, bfare, dfare);
									cout << endl;
								}
								else if (vehicle.compare("Motorbike") == 0)
								{
									string name, num, type, ftype, model;
									int numseats;
									double mileage, bfare, dfare;

									admin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
									display_car_motorbike("Motorbike", name, model, num, type, ftype, numseats, mileage, bfare, dfare);
									cout << endl;
								}
								else if (vehicle.compare("Bike") == 0)
								{
									string name, num, model, type;
									double bfare, dfare;

									admin >> name >> model >> num >> type >> bfare >> dfare;
									display_bike(name, model, num, type, bfare, dfare);
									cout << endl;
								}
								cnt++;
							}
							system("pause");
							goto Admin;
						}
						case 5:break;

						case 6:
						{
							cout << "Thanks for visiting us!!" << endl;
							sleep(1000000);
							return 0;
						}

						default:cout << "Enter valid choice. " << endl;
							cout << "Enter 4 if don't want to add a vehicle " << endl;
							sleep(300000);
						}

						if (veh == 5)
						{
							system("clear");
							goto Beginning;
							break;
						}
						if (wish == 0)
							goto Admin;

					} while (!(veh == 1 || veh == 2 || veh == 3) || wish);
				}
				if (in == 2)
				{
					cout << "Congrats " << person << " are in now, you can book your vehicle" << endl << endl;
					sleep(800000);
				User:
					
					system("clear");
					sleep(800000);
					printf("User name: %s\t Email Id: %s\n\n", person.c_str(), emailid.c_str());
					cout << "Which vehicle do you want to book" << endl;
					cout << "1) Car" << endl << "2) Motor Bike" << endl << "3) Bike" << endl << "4) See you Booked Vehicles" << endl << "5) Exit to Main Menu" << endl << "6) Exit the Application" << endl;
					do
					{
						printf("\n");
						cout << "Enter your choice : ";
						cin >> veh;
						ofstream adminfile;
						adminfile.open(usnl + "_user.txt", ios::app);
						switch (veh)
						{
							system("clear");
						case 1: {
							cout << "Avaiable Cars are :" << endl;
							string name, num, type, ftype, model;
							int numseats;
							double mileage, bfare, dfare;
							cin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
							ifstream carfile;
							carfile.open("car.txt", ios::in);
							while (!carfile.eof())
							{
								carfile >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
							}
							carfile.close();
							cout << "Car has been sucessfully added!!" << endl;
							sleep(500000);
							cout << "Do you want to add more vehicles 0)No 1)Yes" << endl;
							cin >> wish;
							adminfile << "Car" << endl << name << " " << model << " " << num << " " << type << " " << ftype << " " << numseats << " " << mileage << " " << bfare << " " << dfare << endl;
							break;
						}

						case 2: {
							cout << "Enter  motorbike name,model,motorbike number,type(sports/normal/other),fuel type,no.of seats,mileage in km/l,base fare,fare per day" << endl;
							string name, num, type, ftype, model;
							int numseats;
							double mileage, bfare, dfare;
							cin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
							ofstream mbikefile;
							mbikefile.open("mbike.txt", ios::app);
							mbikefile << name << " " << model << " " << num << " " << type << " " << ftype << " " << numseats << " " << mileage << " " << bfare << " " << dfare << endl;
							mbikefile.close();
							cout << "Motorbike has been sucessfully added!!" << endl;
							sleep(500000);
							cout << "Do you want to add more vehicles 0)No 1)Yes" << endl;
							cin >> wish;
							adminfile << "Motorbike" << endl << name << " " << model << " " << num << " " << type << " " << ftype << " " << numseats << " " << mileage << " " << bfare << " " << dfare << endl;
							break;
						}

						case 3: {
							cout << "Enter  bike name,model,bike number,type(geared/normal/other),base fare,fare per day" << endl;
							string name, num, model, type;
							double bfare, dfare;
							cin >> name >> model >> num >> type >> bfare >> dfare;
							ofstream bikefile;
							bikefile.open("bike.txt", ios::app);
							bikefile << name << " " << model << " " << num << " " << type << " " << bfare << " " << dfare << endl;
							bikefile.close();
							cout << "Bike has been sucessfully added!!" << endl;
							sleep(500000);
							cout << "Do you want to add more vehicles 0)No 1)Yes" << endl;
							adminfile << "Bike" << endl << name << " " << model << " " << num << " " << type << " " << bfare << " " << dfare << endl;
							cin >> wish;
							break;
						}
								adminfile.close();
						case 4:
						{
							system("clear");
							ifstream admin;
							admin.open(usnl + "_user.txt", ios::in);
							int cnt = 0;string vehicle = "Car";

							while (!admin.eof())
							{
								if (cnt % 2 == 0)
								{
									admin >> vehicle;
									cnt++;
									continue;
								}

								if (vehicle.compare("Car") == 0)
								{
									string name, num, type, ftype, model;
									int numseats;
									double mileage, bfare, dfare;

									admin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
									display_car_motorbike("Car", name, model, num, type, ftype, numseats, mileage, bfare, dfare);
									cout << endl;
								}
								else if (vehicle.compare("Motorbike") == 0)
								{
									string name, num, type, ftype, model;
									int numseats;
									double mileage, bfare, dfare;

									admin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
									display_car_motorbike("Motorbike", name, model, num, type, ftype, numseats, mileage, bfare, dfare);
									cout << endl;
								}
								else if (vehicle.compare("Bike") == 0)
								{
									string name, num, model, type;
									double bfare, dfare;

									admin >> name >> model >> num >> type >> bfare >> dfare;
									display_bike(name, model, num, type, bfare, dfare);
									cout << endl;
								}
								cnt++;
							}
							system("pause");
							goto Admin;
						}
						case 5:break;

						case 6:
						{
							cout << "Thanks for visiting us!!" << endl;
							sleep(1000000);
							return 0;
						}

						default:cout << "Enter valid choice. " << endl;
							cout << "Enter 4 if don't want to add a vehicle " << endl;
							sleep(300000);
						}

						if (veh == 5)
						{
							system("clear");
							goto Beginning;
							break;
						}
						if (wish == 0)
							goto Admin;

					} while (!(veh == 1 || veh == 2 || veh == 3) || wish);
				}

				break;
			}
		case 2:system("clear");
			//insert user code here
			getVehicle = true;
			printf("USER:\n\n");
			cout << "Welcome to the best vehicle rental facility" << endl;
			cout << "You are few steps away from getting your vehicle on rent" << endl << endl;
			goto UserLogin;
			user_code();
			break;

		case 3:
		{
			cout << "Thanks for visiting us!!" << endl;
			sleep(500000);
			return 0;
		}

		default:cout<< "Enter valid choice" << endl;
				cout<< "Enter 3 for exiting applicatiom" << endl;
			//here we can add code to just display them our collection of vehicles 
			//so they get motivated to put their vehicle or rent a vehicle.
		}

	} while (!(ch == 1 || ch == 2));

	return 0;
}
void user_code()
{
}
