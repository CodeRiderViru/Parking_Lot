#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "parkingfloor.cpp"

class ParkingLot {
    public :
    string Name ;
    unordered_map<string , Floor *> floors ;
    unordered_map<string , Ticket *> tickets ;

    ParkingLot(string Name){
        this->Name=Name ;
    }

    void AddFloor(string id , unordered_map< string , unordered_map<string , Slot *>>  Slots){
        Floor * f = new Floor(id ,Slots) ;
        floors[id]=f;
    }
    void RemoveFloor(string id){
        floors.erase(id);
    }

    void ParkVechile(Vechile * v){
        Ticket * t =NULL ;
        for( auto floor : floors){
            t= floor.second->ParkVechile(v);
            if(t){
                cout<<"Vechile Successfully Parked !!"<<endl;
                t->PrintTicketDetails();
                tickets[t->id]=t ;
                return ;
            }
        }
        cout<<"No Parking Slot Available for this type of vechile"<<endl;
    }

    void ReleseVechile(string tickedId){
        Ticket * t= tickets[tickedId];
        Floor *pf =t->floor ;
        pf->ReleseVechile(t->slot) ;
        cout<<t->vechile->owner_name<<" Taken out his Vechile with Num "<<t->vechile->num<<" from the lot "<<endl;
        cout<<"One slot of "<<t->slot->type<<" has been freed at "<<t->floor->id<<" floor "<<endl ;
        tickets.erase(t->id);
    }

    void DisplayParkedVechiles(){
        cout<<"----------------------------------"<<endl;

        for(auto floor : floors){
            floor.second->DisplayAllVechileParked();
        }
        cout<<"----------------------------------"<<endl;
    }
        
} ;