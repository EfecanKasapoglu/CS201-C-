#include <iostream>
#include <string>
#include "strutils.h"
#include <vector>
#include <iomanip>

using namespace std;

struct supermarket{
    string QRcodesupermarket;
    string namesupermarket;
    double pricesupermarket;
};

struct shoplist{
    string QRcodeshoplist;
    int quantity;
};

void upperfunction(string & word)
{
    for(int k=0; k < word.length(); k++)
    {
        word[k] = toupper(word[k]);
    }
}
void insertsupermarket(vector<supermarket> & list, string QRcodesupermarket, string namesupermarket, double price){
    supermarket stu;
    stu.QRcodesupermarket=QRcodesupermarket;
    stu.namesupermarket=namesupermarket;
    stu.pricesupermarket=price;
    list.push_back(stu);
}
void insertshoplist(vector<shoplist> & list2, string QRcodeshoplist, int quantity){
    shoplist stu;
    stu.QRcodeshoplist=QRcodeshoplist;
    stu.quantity=quantity;
    list2.push_back(stu);
}

bool checklist(const vector<supermarket> & list, string QRcodeshoplist){
    int len1=list.size();
    for (int x=0; x<len1; x++){
        if (QRcodeshoplist==list[x].QRcodesupermarket){
        return true;
            }
    }
    return false;
}

void totalpricecalculation(const vector<supermarket> & list,const vector<shoplist> & list2,double & totalprice){
    int len=list.size();
    int len2=list2.size();
    totalprice=0;
    for (int x=0; x<len2; x++){
        string currentcode=list2[x].QRcodeshoplist;
        int currentquantity=list2[x].quantity;
        for(int z=0; z<len; z++){
            if (currentcode==list[z].QRcodesupermarket){
                totalprice=list[z].pricesupermarket*currentquantity+totalprice;
            }
        }
    }
    totalprice=totalprice*0.18+totalprice;
}

void vatcalculation(const vector<supermarket> & list,const vector<shoplist> & list2,double & totalvat){
    int len=list.size();
    int len2=list2.size();
    totalvat=0;
    for (int x=0; x<len2; x++){
        string currentcode=list2[x].QRcodeshoplist;
        int currentquantity=list2[x].quantity;
        for(int z=0; z<len; z++){
            if (currentcode==list[z].QRcodesupermarket){
                totalvat=list[z].pricesupermarket*currentquantity+totalvat;
            }
        }
    }
    totalvat=totalvat*0.18;
}
int main(){
    string allsupermarket, allshoplist, QRcodesupermarket, QRcodeshoplist, namesupermarket, pricesupermarketstr,quantitystring;
    double pricesupermarket,totalprice,totalvat,itemprice;
    int quantity;
    vector<supermarket> list;
    vector<shoplist> list2;
    
    cout<<"Enter product QR, name, and price (enter 'END' to finish): "<<endl;
    getline(cin,allsupermarket);
    while(allsupermarket!="END"){
        int boslukbulma=allsupermarket.find(" ");
        int dolarbulma=allsupermarket.find("$");
        QRcodesupermarket=allsupermarket.substr(0,boslukbulma);
        upperfunction(QRcodesupermarket);
        namesupermarket=allsupermarket.substr(boslukbulma + 1,dolarbulma-boslukbulma - 2 );
        pricesupermarketstr=allsupermarket.substr(dolarbulma+1);
        pricesupermarket=atof(pricesupermarketstr.c_str());
        insertsupermarket(list,QRcodesupermarket,namesupermarket,pricesupermarket);
        getline(cin,allsupermarket);
    }
    cout<<endl;

    cout<<"Enter shopping list item QR and quantity (enter END to finish): "<<endl;
    getline(cin, allshoplist);

    while(allshoplist!="END"){
        int boslukbulma=allshoplist.find(" ");
        QRcodeshoplist=allshoplist.substr(0,boslukbulma);
        upperfunction(QRcodeshoplist);
        if (!checklist(list, QRcodeshoplist)){
                    cout<<"Item QR "<< QRcodeshoplist<<" not found in inventory. Please try again."<<endl;
                }
        else{
            
            quantitystring=allshoplist.substr(boslukbulma+1);
            quantity=atoi(quantitystring.c_str());
            insertshoplist(list2, QRcodeshoplist,quantity);
            
        }
        getline(cin, allshoplist);
    }
    vatcalculation(list, list2,totalvat);
    cout<<endl;

    int len=list.size();
    int len2=list2.size();
    for (int x=0; x<list2.size();x++){
        string currentcode=list2[x].QRcodeshoplist;
        int currentquantity=list2[x].quantity;
        for(int z=0; z<len; z++){
            if (currentcode==list[z].QRcodesupermarket){
                itemprice=list[z].pricesupermarket*currentquantity;
                cout<<setw(5)<<list[z].namesupermarket<< " * "<<setw(3)<<currentquantity<<setw(31 - list[z].namesupermarket.length())<< fixed << setprecision(2)<<itemprice<<endl;
            }
        }
    }
    totalpricecalculation(list, list2,totalprice);
    cout<<setw(5)<<"\n VAT(18%):"<<setw(27)<< fixed << setprecision(2)<<totalvat<<endl;
    cout<<" ____________________________________"<<endl;
    cout<<setw(5)<< " Total:"<<setw(30)<<fixed << setprecision(2)<<totalprice;
    
    return 0;
}


