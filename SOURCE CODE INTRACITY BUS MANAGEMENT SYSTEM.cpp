#include <iostream>
#include <string.h>
using namespace std;
static int p = 0;
class reservation
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
  void admin();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);
};

reservation bus[10];
void vline(char ch)
{system("color 75");
  for (int i=135;i>0;i--)
  cout<<ch;
}
void reservation::admin()
{
  cout<<"\n\n\n\t\t\tEnter bus no: ";
  cin>>bus[p].busn;
  cout<<"\n\t\t\tEnter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"\n\t\t\tArrival time: ";
  cin>>bus[p].arrival;
  cout<<"\n\t\t\tDeparture: ";
  cin>>bus[p].depart;
  cout<<"\n\t\t\tFrom: ";
  cin>>bus[p].from;
  cout<<"\n\t\t\tTo: ";
  cin>>bus[p].to;
  bus[p].empty();
  p++;
  cout<<"\n\t\t\tBus added Sucessfully ";
}
void reservation::allotment()
{  int seat;
  char number[5];
  top:
  cout<<"\n\n\n\t\t\tBus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
   int pass,total=32;
  cout<<"\n\t\t\tNo. of seats required: ";
  cin>>pass;
  if (pass>total)
  {
      cout<<"\n\t\t\tSORRY! Only "<<total<<" seats are left";
  }
  else{
  while (pass>0){
  while(n<=p)
  {
    cout<<"\n\t\t\tSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\n\t\t\tThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"\t\t\tEnter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        cout<<"\n\t\t\tSeat Reserved Sucessfully \n";
        break;
        total--;
      }
    else
      cout<<"\t\t\tThe seat no. is already reserved.\n";
      }
      }
      pass--;}}
    if(n>p)
    {
      cout<<"\t\t\tEnter correct bus no.\n";
      goto top;
    }
  }
void reservation::empty()
{for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }}}
void reservation::show()
{ int n;
  char number[5];
  cout<<"\t\t\tEnter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  vline('#');
  cout<<"\t\t\tBus no: \t"<<bus[n].busn
  <<"\n\t\t\tDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
  <<bus[n].arrival<<"\t\t\tDeparture time:"<<bus[n].depart
  <<"\n\t\t\tFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  vline('#');
  bus[0].position(n);
 int a=0;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\n\t\t\tThe seat no "<<(a)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"\t\t\tEnter correct bus no: ";
}
void reservation::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          //cout<<bus[l].seat[i][j];
          cout<<"Empty";
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\n\t\t\tThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }
void reservation::avail()
{
		system("color 75");

  for(int n=0;n<p;n++)
  {
    vline('_');
    cout<<"\t\t\tBus no: \t"<<bus[n].busn<<"\n\t\t\tDriver: \t"<<bus[n].driver
    <<"\t\t\tArrival time: \t"<<bus[n].arrival<<"\t\t\tDeparture Time: \t"
    <<bus[n].depart<<"\n\t\t\tFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    vline('#');
   vline('_');
  }
}
int main()
{
	system( "color 75");
    
int w,n,password= 1234,p;
cout<<"\t\t\t*WELCOME TO INTRACITY BUS MANAGEMENT SYSTEM *"<<endl;
cout<<"\t\t\t PRESS 1 FOR ADMIN PORTAL "<<endl;
cout<<"\t\t\t PRESS 2 FOR PASSENGER PORTAL"<<endl;
cout<<"\t\t\t ENTER YOUR CHOICE ";
cin>>n;
if(n!=1 && n!=2){
	cout<<"\t\t\t INVALID CHOICE";
}


if (n==1){
	cout<<"\t\t\t kindly enter your password to access the admin portal"<<endl;
	cout<<"\t\t\t PASSWORD ";
	cin>>p;
	if(p != password){
		cout<<"\t\t\t AUTHENTICATION  FAILED"<<endl;
		cout<<"\t\t\t YOU CANNOT ACCESS THE ADMIN PORTAL"<<endl;
	}
	else{

	

while(1)
{
	system( "color 75");
  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t  *INTRACITY BUS MANAGEMENT SYSTEM *  \n\n";
  cout<<"\t\t\t1.Add Bus\n\t\t\t"
  <<"4.Buses Available\n\t\t\t"
  <<"5.Exit";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].admin();
      break;
    case 2:  bus[p].allotment();
      break;
    case 3:  bus[p].show();
      break;
    case 4:  bus[p].avail();
      break;
    case 5:  exit(0);
  }}}}
if (n==2){
      while(1)
{
	system( "color 75");
  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t  *INTRACITY BUS MANAGEMENT SYSTEM *  \n\n";
  cout<<"\t\t\t1.Bus Reservation\n\t\t\t"
  <<"2.Show\n\t\t\t"
  <<"3.Buses Available\n\t\t\t"
  <<"4.Exit";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].allotment();
      break;
    case 2:  bus[p].show();
      break;
    case 3:  bus[p].avail();
      break;
    case 4:  exit(0);
  }}}
  
return 0;
}
