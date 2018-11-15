#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

int main()
{
    int ch,veh,lor,wish=0,found = 0,in=0,reg=0,won=0;
    string person;
    cout << BOLDRED << "                  Welcome to Vehicle Rental Management System" << RESET <<endl;
    usleep(2000000);//for time lag in microseconds
    cout << endl;
    cout << YELLOW <<"Do you want to "<<endl<< RESET <<endl<<"1)Put your vehicle on rent  "<<endl<<"2)Rent a vehicle"<< endl<<endl;
    cout << endl;
    do
    {
        cout << GREEN <<"Enter your choice 1 or 2: " << RESET << endl << endl;
        cin >> ch;
        switch(ch)
        {
            case 1:system("clear");
                    //admin code here
                    cout << CYAN << "                  Welcome to the best vehicle rental facility" << RESET << endl;
                    usleep(1000000);
                    cout << RED << "            You are few steps away from putting your vehicle on rent" << RESET << endl;
                    usleep(2000000);
                    cout << endl;
                    cout << YELLOW <<"Please 1)Login or 2)Register" << RESET << endl << endl;
                    do
                    {
                        cout << GREEN <<"Enter your choice 1 or 2: " << RESET <<endl;
                        cin >> lor;
                        cout << endl;
                        switch(lor)
                        {
                            case 1:
                            {
                                do
                                {
                                    LOGIN:cout << "Enter your username " << endl << endl;
                                    string usnl,passwordl;
                                    cin >> usnl ;
                                    passwordl=getpass("Enter password: ");

                                    string name,usn,password,email;
                                    ifstream admin;
                                    admin.open("admin.txt",ios::in);
                                    while(!admin.eof())
                                    {
                                        admin >> usn >> password >> name >> email;
                                        //cout << usn << password << endl;
                                        int x = usn.compare(usnl);
                                        int y = password.compare(passwordl);
                                        if(x==0 && y==0  || found )
                                        {
                                            found = 1;
                                            break;
                                        }
                                    }
                                    if(found == 0)
                                    {
                                        cout << BOLDRED << "Invalid username or password" << RESET<< endl << endl;
                                        cout << "Do you want to 1)Try again or 2)New User " << endl;
                                        cout << GREEN <<"Enter your choice 1 or 2: " << RESET <<endl;
                                        cin >> won;
                                        switch(won)
                                        {
                                            case 1:goto LOGIN;
                                            case 2:cout << "Do you want to register " << endl;
                                                    cin >> reg;
                                            
                                        }
                                        
                                        
                                    }
                                        

                                    if(found == 1)
                                        person = name;
                                        in = 1;
                                    if(reg)
                                    {
                                        goto HERE;
                                        break;
                                    } 
                                    else
                                        goto END;
                                }while(!found);
                                
                                break;
                            }
                            
                            case 2:
                            {
                                HERE:cout <<"Enter name,username and email address"<<endl;
                                string name,usn,password,email;
                                cin >> name >> usn >> email;
                                password = getpass("Enter password: ");
                                string cpassword = getpass("Confirm password: ");
                                cout << endl;
                                if(password.compare(cpassword)!=0)
                                {
                                    cout << BOLDRED << "Password didn't matched.Try again " << RESET << endl<<endl;
                                    goto HERE;
                                }
                                    
                                ofstream adminfile;
                                adminfile.open("admin.txt",ios::app);
                                adminfile << usn << " " << password << " " << name << " "<< email << endl;
                                person = name;
                                adminfile.close();
                                cout << GREEN << "You have been sucessfully registered!!" << RESET << endl;
                                usleep(2000000);
                                in = 1;
                                break;
                            }
                            
                            case 3:break;

                            default:cout << "Enter valid choice" << endl;
                                    cout << "Enter 3 if don't want to do either of them" << endl;
                                    //here we can add code to just display them our collection of vehicles 
                                    //so they get motivated to put their vehicle too. 
                        }
                        if(lor==3)
                        {
                            goto END;
                            break;
                        }
                            
                    }while(!(lor==1 || lor == 2));
                    if(in)
                    {
                        system("clear");
                        cout << YELLOW << "Congrats "<< RESET << BOLDBLUE<< person <<RESET << YELLOW << " you are in now, you can add your vehicle" << RESET <<endl<<endl;
                        usleep(2000000);
                        cout << CYAN << "Which vehicle do you want to put on rent" << RESET << endl << endl;
                        cout << "1)Car" << endl << "2)Motor Bike" << endl << "3)Bike" << endl << endl;
                        do
                        {
                            cout << GREEN << "Enter your choice 1 , 2 or 3: "<< RESET << endl;
                            cin >> veh;
                            cout << endl;
                            switch(veh)
                            {
                                case 1:{
                                            cout << BLUE <<"Enter the following values space seperated: "<< RESET << endl;
                                            usleep(500000);
                                            cout << "Enter car name,model,car number,type(suv/normal),fuel type,no.of seats,mileage in km/l,base fare,fare per day" << endl;
                                            string name,num,type,ftype,model;
                                            int numseats;
                                            double mileage,bfare,dfare;
                                            cin >> name >> model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
                                            ofstream carfile;
                                            carfile.open("car.txt",ios::app);
                                            carfile << name << " " << model << " " << num << " "<< type << " "<< ftype <<" "<< numseats <<" "<< mileage <<" "<< bfare <<" "<< dfare <<endl;
                                            carfile.close();
                                            cout << endl << GREEN <<"Car has been sucessfully added!!"<< RESET << endl<<endl;
                                            usleep(2000000);
                                            cout << "Do you want to add more vehicles 0)No 1)Yes" << endl;
                                            cin >> wish; 
                                            break;
                                        }
                                        
                                case 2: {
                                            cout << BLUE <<"Enter the following values space seperated: " << RESET<< endl;
                                            usleep(500000);
                                            cout << "Enter  motorbike name,model,motorbike number,type(sports/normal),fuel type,no.of seats,mileage in km/l,base fare,fare per day" << endl;
                                            string name,num,type,ftype,model;
                                            int numseats;
                                            double mileage,bfare,dfare;
                                            cin >> name >>  model >> num >> type >> ftype >> numseats >> mileage >> bfare >> dfare;
                                            ofstream mbikefile;
                                            mbikefile.open("mbike.txt",ios::app);
                                            mbikefile << name << " " << model << " " << num << " "<< type << " "<< ftype <<" "<< numseats <<" "<< mileage <<" "<< bfare <<" "<< dfare <<endl;
                                            mbikefile.close();
                                            cout << endl << GREEN<<"Motorbike has been sucessfully added!!"<< RESET << endl<<endl;
                                            usleep(2000000);
                                            cout << "Do you want to add more vehicles 0)No 1)Yes" << endl;
                                            cin >> wish;
                                            break;
                                        }
                                        
                                case 3: {
                                            cout << BLUE <<"Enter the following values space seperated: "<< RESET << endl;
                                            usleep(500000);
                                            cout << "Enter  bike name,model,bike number,type(geared/normal),base fare,fare per day" << endl;
                                            string name,num,model,type;
                                            double bfare,dfare;
                                            cin >> name >> model >> num >> type >> bfare >> dfare;
                                            ofstream bikefile;
                                            bikefile.open("bike.txt",ios::app);
                                            bikefile << name << " " << model << " " << num << " "<< type << " "<< bfare <<" "<< dfare <<endl;
                                            bikefile.close();
                                            cout << endl << GREEN<<"Bike has been sucessfully added!!"<< RESET << endl<<endl;
                                            usleep(2000000);
                                            cout << "Do you want to add more vehicles 0)No 1)Yes" << endl;
                                            cin >> wish;
                                            break;
                                        }

                                case 4:break;

                                default:cout << "Enter valid choice" << endl;
                                        cout << "Enter 4 if don't want to add a vehicle " << endl;
                            }
                            
                            if(veh==4 || wish==0)
                            {
                                //cout << MAGENTA <<"Thanks for visiting us!!"<< RESET << endl;
                                goto END;
                                break;
                            }
                                
                        }while(!(veh==1 || veh == 2 || veh == 3) || wish);
                    }
                    
                    break;
            case 2:system("clear");
                    //insert user code here

                    break;

            case 3:break;

            default:cout << "Enter valid choice" << endl;
                    cout << "Enter 3 if not interested anymore" << endl;
                    //here we can add code to just display them our collection of vehicles 
                    //so they get motivated to put their vehicle or rent a vehicle.
        }
        if(ch==3)
        {
            //cout << MAGENTA <<"Thanks for visiting us!!" << RESET << endl;
            goto END;
            break;
        }
            
    }while(!(ch==1 || ch==2));
    
    END:cout << MAGENTA <<endl <<"Thanks for visiting us!!"<< RESET << endl;

    return 0;   
}
