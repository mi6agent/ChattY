/*
 FILNAMN: 		main.cc
 PROGRAMMERARE:	hanel742, eriek984, jened502, tobgr602, niker917, davha227
 SKAPAD DATUM:	2013-11-19
 BESKRIVNING:
 */

#include <iostream>
#include "netClient.h"
#include <QCoreApplication>


using namespace std;

int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);
    
    string name;
    while (name.size() == 0)
    {
        cout << "Skriv in ditt namn: ";
        cin >> name;
    }
    
    string address;
    while (address.size() == 0)
    {
        cout << "Skriv in serveraddress: ";
        cin >> address;
    }
    
    NetClient client(name,address);
    client.start();
    
    
    string input;
    cout<<name<<": ";
    while(cin>>input)
    {
        if (input=="message")
        {
            client.sendMessage(name);
        }
        else if (input=="username")
        {
            cout<<name;
        }
        else
        {
            cout<<"unknown command";
        }
    }
        
    
    return a.exec();
}