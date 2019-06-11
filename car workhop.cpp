#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class Customer
{
protected:
    int km,i,n,perc,input;
char Custm_name[40];
long long int Contact_no;

char address[80];
float cost[30],total=0,sum=0;
char parts[20][30];

public:
    float charge,sercost;
char Car_no[40];

    void getdata()
    {
        cout<<"                        WELCOME TO MY SHOP                    :)"<<endl;
		cout<<"************************HOW CAN I HELP YOU************************"<<endl;
		cout<<"_____________________________________________________________________"<<endl;
        cout<<"_____________________________________________________________________"<<endl;
cout<<"\nEnter the Information\n";
fflush(stdin);
        cout<<"COUSTOMER'S NAME:-";
        cin.getline(Custm_name,39);
        fflush(stdin);
        cout<<"\nMobile No:-";
        cin>>Contact_no;
        fflush(stdin);
        cout<<"\nEnter Car no:-";
        cin.getline(Car_no,19);
          fflush(stdin);
        cout<<"\nEnter Address:-";
        cin.getline(address,39);
 cout<<"select the type of service u want: "<<endl;
  cout<<"\n1>New Car  \n2>ACCIDENTAL\n3>DENTING AND PAINTING\n4>WASHING \n5>PART REPLACEMENT \n\n";
        cin>>input;

        if(input==1)
        {
            cout<<"Enter the distance covered by Car:-";
            cin>>km;
            if(km<=1000)
               {
                 cout<<"Free service is avilable 1st service";
                cout<<"\n NO BILL For this Car";}
            else
            {
                cout<<"\nNo service avilable here free";
                
                cout<<"\nSERVICE CHARGES : ";
                cin>>sercost;
            }

        }
        else if(input==2)
        {
          cout<<"ENTER THE % OF DAMAGE TO VEHICLE :-";
          cin>>perc;
          if(perc<=50)
          {
              cout<<"\n we can repair your car";
              cout<<"\n Number of parts change:-";
			 	cin>>n;
			 	for(i=0;i<n;i++)
                {
                    cout<<"\nName of part:-";
                    cin>>parts[i];
                    cout<<"\nEnter the cost of part:";
                    cin>>cost[i];
                       sum=sum+cost[i];
                }
                cout<<"Service Charge:-";
                cin>>charge;
                sum=sum+charge;
          }
          else
          {
        
          }
        }
       else if(input==3)
       {

       }
       else if(input==4)
       {

       }
       else if(input==5)
       {
            cout<<"\n Number of parts change:-";
			 	cin>>n;
			 	for(i=0;i<n;i++)
                {
                    cout<<"\nName of part: ";
                    cin>>parts[i];
                    cout<<"\nEnter the cost of part:";
                    cin>>cost[i];
                       sum=sum+cost[i];
                }
                cout<<"Service Charge:-";
                cin>>charge;
                sum=sum+charge;

       }
       else
       {
           cout<<"Program will be close Now you enter wrong input";
           exit (0);
       }

    }
};
class Chargess:public Customer
{
    public:
    void bill()
    {
       cout<<"\n_______________________________________________________________________________\n";
     cout<<"\n_______________________________________________________________________________\n";
    cout<<"\n                  **********BILL**********                                      \n";
     cout<<"\n_______________________________________________________________________________\n";
      cout<<"\n_______________________________________________________________________________\n";

             cout<<"COUSTOMER'S NAME:-";
        cout<<Custm_name;
        fflush(stdin);
        cout<<"\nMobile No:-";
        cout<<Contact_no;
        fflush(stdin);
        cout<<"\nEnter Car no:-";
        cout<<Car_no;
          fflush(stdin);
        cout<<"\nEnter Address:-";
        cout<<address;

        if(input==1)
        {
            if(km<=1000)
               {
                 cout<<"\nFree service is avilable 1st service";
                cout<<"\n NO BILL For this Car";}
        
            else
            {
                cout<<"\nNo service avilable here free";
                
                cout<<"\nSERVICE CHARGES : ";
                cout<<sercost;
            }

        }
        else if(input==2)
        {
          if(perc<=50)
          {
              cout<<"\n we can repair your car";

			 		for(i=0;i<n;i++)
                {
                    cout<<"\nName of part: ";
                    cout<<parts[i];
                    cout<<"\n The cost of part: ";
                    cout<<cost[i];

                }
                cout<<"\nService Charge: ";
                cout<<charge;
                cout<<"\nTotal bill: "<<sum;
          }



          else
          {
            cout<<"\nSORRY WE CAN'T REPAIR IT :( ";

          }
        }
       else if(input==3)
       {
cout<<"\nThe Cost of Painting:Rs.1500";
       }
       else if(input==4)
       {
        cout<<"\nThe Cost of Washing:Rs.350";
       }
       else if(input==5)
       {
            cout<<"\n Number of parts change:-";
			 	cout<<n;
			 		for(i=0;i<n;i++)
                {
                    cout<<"\nName of part: ";
                    cout<<parts[i];
                    cout<<"\nEnter the cost of part: ";
                    cout<<cost[i];

                }
                cout<<"\nService Charge: ";
                cout<<charge;
                cout<<"\nTotal bill: "<<sum;
          }

       else
       {
           cout<<"Program will be close Now you enter wrong input";
           exit (0);
       }


        }

};


int main()
{
    char choice[20];
int ch;
Chargess c1;
while(1)
{
     cout<<"\nSELECT YOUR CHOICE\n";
    cout<<"\n1>Create a bill\n";
    cout<<"\n2>View all\n";
    cout<<"\n3>Search\n";
    cout<<"\n4>Delete\n";
    cout<<"\n5>Update\n";
    cout<<"\n6> Exit\n";
    cout<<"\n Enter your choice:-";
    cin>>ch;

	switch(ch)
	{
		case 1:

            {c1.getdata();
            c1.bill();

    ofstream file;

	file.open("Customer bill",ios::app|ios::binary);

	file.write((char*)&c1,sizeof(c1));
	file.close();
    cout<<"\n\aRecord saved";
            }
break;
case 2:
{
ifstream fin;

fin.open("Customer bill",ios::in|ios::binary);
if(!fin)
{
cout<<"\n File not found";
}
else
{
fin.read((char*)&c1,sizeof(c1));
	while(!fin.eof())
    {
       c1.bill();
      fin.read((char*)&c1,sizeof(c1));


    }

}
}
break;
case 3:
    {

    int counter=0;
    fflush(stdin);
    cout<<"Enter the Car no to search: ";
    cin.getline(choice,19);
	ifstream fin;
	fin.open("Customer bill",ios::in|ios::binary);
	if(!fin)
	cout<<"\nFile is not found";
	else{
		fin.read((char*)&c1,sizeof(c1));
		while(!fin.eof())
		{

			if(strcmp(choice,c1.Car_no)==0)
			{
				c1.bill();
				counter++;

			}
			fin.read((char*)&c1,sizeof(c1));

		}
	}
		if(counter==0)
		cout<<"\nRecord not found";
		fin.close();
        }

				break;
			case 4:
        {



        int counter=0;
        fflush(stdin);
    cout<<"Enter the Car no to Delete: ";
    cin.getline(choice,19);
   	ifstream fin;
	ofstream fout;
	fin.open("Customer bill",ios::in|ios::binary);
	if(!fin)
    {
      cout<<"\nFile not Found";
      exit (0);
    }


	else{
		fout.open("tempfile",ios::out|ios::binary);
		fin.read((char*)&c1,sizeof(c1));
		while(!fin.eof())
		{
			if(strcmp(c1.Car_no,choice))


			fout.write((char*)&c1,sizeof(c1));
			fin.read((char*)&c1,sizeof(c1));
		}
		}
        fin.close();
		fout.close();
		remove("Customer bill");
		rename("tempfile","Customer bill");
		cout<<"\ndata is deleted";
        }
				break;
			case 5:
                {


    int counter=0;
    fflush(stdin);
    cout<<"Enter the Car no to update: ";
    cin.getline(choice,19);
 	fstream file;
	file.open("Customer bill",ios::in|ios::out|ios::ate|ios::binary);
file.seekg(0);
file.read((char*)&c1,sizeof(c1));
while(!file.eof())
{
	if(!strcmp(choice,c1.Car_no))
	{
		c1.getdata();
		file.seekp(file.tellp()-sizeof(c1));
		file.write((char*)&c1,sizeof(c1));
	}
	file.read((char*)&c1,sizeof(c1));
}
cout<<"\ndata is updated";
                }
				break;

			case 6:
			 {

        cout<<endl<<"                    THANKS FOR COMING             "<<endl;
		cout<<endl<<"*********..............VISIT US AGAIN............**************"<<endl;
			 }
                  exit(0);
			default:
			cout<<"\nInvalid choice";

	}
	getch();
}


}





