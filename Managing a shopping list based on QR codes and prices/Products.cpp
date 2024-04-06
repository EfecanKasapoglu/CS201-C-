#include "Products.h"

Products::Products(){}

Products::Products(const Products & p){
    item_list=p.get_item_list();
    shop_list=p.get_shop_list();
}
vector<Product> Products::get_item_list() const {
    return item_list;
}

vector<Product> Products::get_shop_list() const {
    return shop_list;
}

void Products::read_files(ifstream & qr, ifstream & price){
    string line1,line2;
    Product p(" ", -1, -1, " ");
    while(getline(qr,line1) && getline(price,line2)){
        int SpaceFinder1=line1.find(" ");
        string QrCode1=line1.substr(0,SpaceFinder1);
        ToUpper(QrCode1);
        string Name=line1.substr(SpaceFinder1+1);
        StripWhite(Name);
        int SpaceFinder2=line2.find(" ");
        string QrCode2=line2.substr(0,SpaceFinder2);
        ToUpper(QrCode2);
        string StringPrice=line2.substr(SpaceFinder2+1);
        float FloatPrice=stof(StringPrice);
        if (QrCode1 == QrCode2){
            p.name=Name;
            p.price=FloatPrice;
            p.qr_code=QrCode1;
            item_list.push_back(p);
        }
        else{
            break;
        }
    }
}

bool Products::find(string qr_code){
    ToUpper(qr_code);
    for ( int x=0; x<item_list.size(); x++){
        if(qr_code==item_list[x].qr_code){
            return true;
        }
        }
    return false;
}

bool Products::findInShopList(string qr_code){
    ToUpper(qr_code);
    for (int x=0; x<shop_list.size();x++){
        if(qr_code==shop_list[x].qr_code){
            return true;
        }
    }
    return false;
}

void Products::add_item(string qr, int amount){
    Product p(" ", -1, -1, " ");
    ToUpper(qr);
    p.amount=amount;
    p.qr_code=qr;
    for (int x=0; x<item_list.size(); x++){
        if(p.qr_code==item_list[x].qr_code){
            p.price=item_list[x].price;
            break;
        }
    }
    
    shop_list.push_back(p);
}

void Products::edit_item(string qr, int amount){
    ToUpper(qr);
    for (int x=0; x<shop_list.size();x++){
        if (qr==shop_list[x].qr_code){
            shop_list[x].amount=amount;
        }
    }
}

void Products::remove_item(string qr){
    ToUpper(qr);
    for (int x=0; x<shop_list.size();x++){
        if(qr==shop_list[x].qr_code){
            shop_list[x].qr_code.clear();
            
        }
    }
}

void Products::printCurrentReceipt() {

    float totalprice;
    float itemprice;
    
    
    
    for(int x=0; x<shop_list.size();x++){
        string currentcode=shop_list[x].qr_code;
        int currentamount=shop_list[x].amount;
        for(int e=0; e<item_list.size();e++){
            if(currentcode==item_list[e].qr_code){
                itemprice=currentamount*item_list[e].price;
                totalprice=itemprice+totalprice;
                cout<<setw(5)<<item_list[e].name<< " * "<<setw(3)<<currentamount<<setw(31 - item_list[e].name.length())<<fixed<<setprecision(1)<<itemprice<<endl;
                
            }
        }
                
    }
    cout<<endl;
    cout<<setw(5)<<"VAT(18%):"<<setw(28)<< fixed << setprecision(1)<<totalprice*0.18<<endl;
    cout<<"_______________________________________"<<endl;
    cout<<setw(5)<< "Total:"<<setw(31)<<fixed << setprecision(1)<<totalprice*1.18<<endl;
    cout<<endl;
    
}

void Products::printCurrentReceiptAscending() {

    float totalprice = 0;
    float itemprice;

    for (int i = 0; i < shop_list.size(); i++) {
        int minprice = shop_list[i].price * shop_list[i].amount;
        int minindex = i;

        for (int j = i + 1; j < shop_list.size(); j++) {
            if (shop_list[j].price * shop_list[j].amount < minprice) {
                minprice = shop_list[j].price * shop_list[j].amount;
                minindex = j;
            }
        }

        Product temp = shop_list[i];
        shop_list[i] = shop_list[minindex];
        shop_list[minindex] = temp;
    }

    for (int x = 0; x < shop_list.size(); x++) {
        string currentcode = shop_list[x].qr_code;
        int currentamount = shop_list[x].amount;
        for (int e = 0; e < item_list.size(); e++) {
            if (currentcode == item_list[e].qr_code) {
                itemprice = currentamount * item_list[e].price;
                totalprice += itemprice;
                cout << setw(5) << item_list[e].name << " * " << setw(3) << currentamount << setw(31 - item_list[e].name.length()) << fixed << setprecision(1) << itemprice << endl;
            }
        }
    }
    cout<<endl;
    cout << setw(5) << "VAT(18%):" << setw(28) << fixed << setprecision(1) << totalprice * 0.18 << endl;
    cout << "_______________________________________" << endl;
    cout << setw(5) << "Total:" << setw(31) << fixed << setprecision(1) << totalprice * 1.18 << endl;
    cout<<endl;
}

void Products::printCurrentReceiptDescending(){

    float totalprice = 0;
    float itemprice;
    for (int i = 0; i < shop_list.size(); i++) {
        int maxprice = shop_list[i].price * shop_list[i].amount;
        int maxindex = i;

        for (int j = i + 1; j < shop_list.size(); j++) {
            if (shop_list[j].price * shop_list[j].amount >= maxprice) {
                maxprice = shop_list[j].price * shop_list[j].amount;
                maxindex = j;
            }
        }

        Product temp = shop_list[i];
        shop_list[i] = shop_list[maxindex];
        shop_list[maxindex] = temp;
    }
    for (int x = 0; x < shop_list.size(); x++) {
        string currentcode = shop_list[x].qr_code;
        int currentamount = shop_list[x].amount;
        for (int e = 0; e < item_list.size(); e++) {
            if (currentcode == item_list[e].qr_code) {
                itemprice = currentamount * item_list[e].price;
                totalprice += itemprice;
                cout << setw(5) << item_list[e].name << " * " << setw(3) << currentamount << setw(31 - item_list[e].name.length()) << fixed << setprecision(1) << itemprice << endl;
            }
        }
    }
    cout<<endl;
    cout << setw(5) << "VAT(18%):" << setw(28) << fixed << setprecision(1) << totalprice * 0.18 << endl;
    cout << "_______________________________________" << endl;
    cout << setw(5) << "Total:" << setw(31) << fixed << setprecision(1) << totalprice * 1.18 << endl;
    cout<<endl;
}
