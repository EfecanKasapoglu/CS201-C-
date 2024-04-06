#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Products.h"
#include <fstream>
#include "strutils.h"
#include <sstream>

int main(){
    string QrFileName, PriceFileName;
    int Choice;
    Products p;
    
    cout<<"Please enter a filename for QR database: ";
    cin>>QrFileName;
    ifstream qr;
    qr.open(QrFileName.c_str());
    
    while(qr.fail()){
        cout<<endl;
        cout<<"The QR file does not exists"<<endl;
        
        cout<<"Please enter a filename for QR database: ";
        cin>>QrFileName;
        qr.open(QrFileName.c_str());
    }
    cout<<endl;
    cout<<"Please enter a filename for Price database: ";
    cin>>PriceFileName;
    ifstream price;
    price.open(PriceFileName.c_str());
    while(price.fail()){
        cout<<endl;
        cout<<"The Price file does not exists "<<endl;
        cout<<"Please enter a filename for Price database: ";
        cin>>PriceFileName;
        price.open(PriceFileName.c_str());
    }
    
    p.read_files(qr,price);
    
    cout<<"MENU"<<endl;
    cout<<"1. Add item to the shopping list"<<endl;
    cout<<"2. Delete item from the shopping list"<<endl;
    cout<<"3. Edit the amount of existing item"<<endl;
    cout<<"4. Print current receipt"<<endl;
    cout<<"5. Print current receipt in order"<<endl;
    cout<<"6. Print current receipt in reverse order"<<endl;
    cout<<"7. Exit"<<endl;
    cout<<"---"<<endl;
    cout<<"Enter your choice: ";
    cin>>Choice;
    
    while(Choice<=7 && Choice>=1){
        if(Choice == 1){
            string AddingQR;
            float AddingAmount;
            cout<<"Please enter the QR code to add: ";
            cin>>AddingQR;
            if (!p.find(AddingQR)){
                cout<<"Invalid QR code, try again "<<endl;
            }
            if (p.find(AddingQR) && p.findInShopList(AddingQR)){
                cout<<"Item is already in the shoplist, if you want to edit the amount please choose option 3"<<endl;
            }
            if (p.find(AddingQR) && !p.findInShopList(AddingQR)){
                cout<<"Please enter the amount to add: ";
                cin>>AddingAmount;
                if (AddingAmount >=1 && AddingAmount<=25){
                    p.add_item(AddingQR, AddingAmount);
                }
                else{
                    cout<<"Invalid amount, try again"<<endl;
                }
            }
        }
        else if (Choice==2){
            string removingQr;
            cout<<"Please enter the QR code to delete: ";
            cin>>removingQr;
            if (p.findInShopList(removingQr)){
                p.remove_item(removingQr);
            }
            else {
                cout<<"Shoplist does not contain the given QR code."<<endl;
            }
        }
        else if (Choice==3){
            string EdittingQR;
            int EditingAmount;
            cout<<"Please enter the QR code to edit: ";
            cin>>EdittingQR;
            if (p.findInShopList(EdittingQR)){
                cout<<"Please enter the amount to edit: ";
                cin>>EditingAmount;
                if (EditingAmount>=1 && EditingAmount<=25){
                    p.edit_item(EdittingQR,EditingAmount);
                }
                else{
                    cout<<"Invalid amount, try again"<<endl;
                }
            }
            else{
                cout<<"Shoplist does not contain the given QR code."<<endl;
            }
        }
        
        else if (Choice==4){
            p.printCurrentReceipt();
        }
        
        else if (Choice==5){
            p.printCurrentReceiptAscending();
        }
        
        else if (Choice==6){
            p.printCurrentReceiptDescending();
        }
        else if (Choice==7){
            cout<<"Goodbye!";
            break;
        }
        
        cout<<"MENU"<<endl;
        cout<<"1. Add item to the shopping list"<<endl;
        cout<<"2. Delete item from the shopping list"<<endl;
        cout<<"3. Edit the amount of existing item"<<endl;
        cout<<"4. Print current receipt"<<endl;
        cout<<"5. Print current receipt in order"<<endl;
        cout<<"6. Print current receipt in reverse order"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"---"<<endl;
        cout<<"Enter your choice: ";
        cin>>Choice;
    }
        
    
    
    qr.close();
    price.close();
    return 0;
}
