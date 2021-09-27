#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
using namespace std;
#define TIME 500
#include "Sender.h"
#include "Receiver.h"


Sender S;
Receiver R;

string tryError(string str);
void opening();
void Show();

int main()
{
    time_t t;
    srand(time(&t));
    S.create_data();
    opening();
    cout<<"________________________________________________________________________________________________"<<endl<<endl;
    cout<<"\tSENDER\t\t\t\t\t\tRECEIVER"<<endl;
    cout<<"________________________________________________________________________________________________"<<endl;

    for(int i=0;i<10;i++)
    {

        S.CRC();
        cout<<"________________________________________________________________________________________________"<<endl;
RES:    string str = S.getframe();
        cout<<" Sending Frame: "<<i+1<<endl;
        for(int k=0;k<7;k++)
        {
            cout<<" . ";
            Sleep(TIME);
        }
        cout<<endl;
        string str2 = tryError(str);
        int ACK = R.receive_frame(i,str2);

        if(ACK==-1)
        {
            Sleep(TIME);
            cout<<" Trying to Resend..."<<endl<<endl;
            goto RES;
        }
        else if(ACK==0)
        {
            for(int k=0;k<3;k++)
            {
                cout<<" . "<<endl;
                Sleep(4*TIME);
            }
            cout<<" Timeout...!!!"<<endl;
            Sleep(TIME);
            cout<<" No Acknowledgment received for Frame: "<<i+1<<endl<<endl;
            Sleep(TIME);
            cout<<" Resending Data..."<<endl<<endl;
            goto RES;
        }
        else
        {
            Sleep(TIME);
            cout<<" Acknowledgment received for Frame: "<<ACK<<endl<<endl;
            cout<<"________________________________________________________________________________________________"<<endl;
        }
            Sleep(TIME);
    }
    cout<<endl<<endl<<" All Data Received Successfully...!!!"<<endl;

    system("pause");
    system("cls");
    Show();

    cout<<endl<<endl<<"\t\t\t\t\t\t THANK YOU...!!!"<<endl;

    getch();
    return 0;
}

string tryError(string str)
{

    int U=115,L=100;
    int random = (rand() % (U-L+1))+L;
    str[random] = '0';

    return str;
}

void opening()
{
    cout<<"\t\t\t\t GENERATED DATA"<<endl<<endl;
    S.showData();
    cout<<endl;
    cout<<"Press Any Key to Start Sending the Data..."<<endl;
    getch();
    system("cls");
}

void Show()
{
    cout<<"SENT DATA:"<<endl<<endl;
    S.showData();
    cout<<endl;
    cout<<"RECEIVED DATA:"<<endl<<endl;
    R.showData();
    cout<<endl;

    if(S.getdata()==R.getdata())
    {
        cout<<"NO ERROR!!"<<endl;
    }
    else
    {
        cout<<"ERROR!!"<<endl;
    }
}
