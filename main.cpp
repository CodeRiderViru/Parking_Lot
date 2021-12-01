#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "parklot.cpp"

int main() {

    ParkingLot *Lot =new ParkingLot("Eden_Garden_Parking_Lot") ;

    vector<Slot *> slots ;
    vector<string> slotIds = {"s1","s2","s3","s4","s5","s6","s7","s8","s9","s10","s11","s12",} ;
    vector<string> types ={"twoWheller" , "large" ,"extraLarge","twoWheller" , "large" ,"extraLarge","twoWheller" , "large" ,"extraLarge","twoWheller" , "large" ,"extraLarge"} ;
    
    unordered_map< string , unordered_map<string , Slot *>> floorInput ;
    unordered_map< string , unordered_map<string , Slot *>> floorInput2 ;

    for(int i=0 ;i<6;i++){
        Slot *s = new Slot(slotIds[i],types[i]);
        unordered_map<string , Slot *> smp ;
        smp[slotIds[i]]=s ;
        floorInput[types[i]]=smp;
    }

    for(int i=6 ;i<slotIds.size();i++){
        Slot *s = new Slot(slotIds[i],types[i]);
        unordered_map<string , Slot *> smp ;
        smp[slotIds[i]]=s ;
        floorInput2[types[i]]=smp;
    }

    Lot->AddFloor("F1" ,floorInput);
    Lot->AddFloor("F2" ,floorInput2);

    vector<vector<string>> vechiles = {
        {"RJ23 1234","RJ23 1235","RJ23 1236","RJ23 1237","RJ23 1238","RJ23 1239","RJ23 1240"},
        {"Virendra" ,"Varun" ,"Naveen","Rishabh","Vikrant","Chandra","Sumit"},
    };
    
    for(int i=0;i<vechiles[0].size();i++){
        Vechile * v =new Vechile(vechiles[0][i] ,vechiles[1][i] ,types[i]) ;
        Lot->ParkVechile(v);
    }

    Lot->DisplayParkedVechiles();

    vector<string> tickets ={"F2-Virendra-RJ23 1234" ,"F2-Varun-RJ23 1235" ,"F1-Rishabh-RJ23 1237"};

    for(auto it: tickets){
        Lot->ReleseVechile(it);
    }

    Lot->DisplayParkedVechiles();
   

    return 0;
}