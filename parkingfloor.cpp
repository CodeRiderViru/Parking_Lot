#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "parkingSlot.cpp"
#include "vechile.cpp"

class Floor ;

class Ticket { 
    public :
        string id ;
        Vechile *vechile ;
        Slot * slot ;
        Floor * floor ;

        Ticket(string id,Vechile *vechile ,Slot * slot ,Floor * floor ){

            this->id=id ;
            this->vechile=vechile ;
            this->slot=slot ;
            this->floor=floor ;
        }  

        void PrintTicketDetails(){
            cout<<"-----------------------------------"<<endl;
            cout<<"Your Ticket Details are as follows "<<endl;
            cout<<"id             -"<<id<<endl;
            cout<<"Driver         -"<<vechile->owner_name<<endl;
            cout<<"vechile num    -"<<vechile->num<<endl;
            cout<<"vechile type    -"<<vechile->type<<endl;
            //cout<<"Floor num      -"<<floor->id<<endl;
            cout<<"Slot  num      -"<<slot->id<<endl;
            cout<<"-----------------------------------"<<endl;
        }    
} ;

class Floor {
    public :
    string id ;
    unordered_map< string , unordered_map<string , Slot *>>  Slots;

    Floor(string id , unordered_map< string , unordered_map<string , Slot *>>  Slots){
        this->id =id ;
        this->Slots =Slots ;
    }

    Ticket * ParkVechile(Vechile * v){
        string type = v->type ;
        for(auto slot : Slots[type]){
            if(slot.second->isAvailable){

                string tid = this->id+"-"+v->owner_name+"-"+v->num ;
                Ticket *t =new Ticket(tid , v ,slot.second ,this) ;
                slot.second->isAvailable =false ;
                slot.second->vechile=v; 
                return t ;
            }
        }

        return NULL ;
    }

    void ReleseVechile(Slot * s){
        if(s->isAvailable){
            cout<<"There is no vechile parked at this slot !!"<<endl;
            return ;
        }

        s->isAvailable=true ;
        s->vechile=NULL ;
    }

    void DisplayAllVechileParked(){
        cout<<"-------------------------------------------------"<<endl;
        cout<<"This are the vechiles parked at floor no "<<id<<endl;
        for(auto type : Slots){
            for(auto slot : type.second){
                cout<<"NUM             -  "<<slot.second->vechile->num<<endl;
                cout<<"Owner's Name    -  "<<slot.second->vechile->owner_name<<endl ;
                cout<<"Vechile's Type  -  "<<slot.second->vechile->type<<endl ;
            }
        }

    }

} ;