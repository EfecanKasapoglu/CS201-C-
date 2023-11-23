
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string companyname;
    double expenses,grossincome,vat,profit,corporatetax,netprofit,capitalincrease,dividend,dividendtax;
    int ortak;
    
    cout<<"This accounting program calculates the state taxes and dividends for the company shareholders."<<endl;
    cout<<"Please enter the name of the company: ";
    cin>>companyname;
    cout<<"Please enter the gross income of "<<companyname<<": ";
    cin>>grossincome;
    
    if (grossincome<=0){
        cout<<"Invalid input for gross income (Gross Income must be greater than 0)."<<endl;
        cout<<"Stopping calculations...";
    }
    else {
        cout<<"Please enter expenses of "<<companyname<<": ";
        cin>>expenses;
        if (expenses>0 || expenses==0){
            cout<<"Please enter the number of shareholders: ";
            cin>>ortak;
            if (ortak >= 1){
                cout<<endl;
                cout<<"*********** "<<companyname<<" Financial Report **********";
                cout<<endl;
                cout<<endl;
                
                vat=grossincome*18/100;
                profit=grossincome-expenses-vat;
                
                if (profit <= 10000){
                    corporatetax=profit*10/100;
                    netprofit=profit-corporatetax;
                    if (netprofit>0){
                        capitalincrease=netprofit/2;
                        dividend=(netprofit/2);
                        dividendtax=(dividend-dividend*15/100)/ortak;
                        cout<<"Net Profit: "<<netprofit<<" TL."<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: "<<corporatetax<<" TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: "<<capitalincrease<<" TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: "<< dividendtax<<" TL."<<endl;
                        
                            
                    }
                    if (netprofit==0){
                        cout<<"Net Profit: "<<netprofit<<" TL. (Break Even)"<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: "<<corporatetax<<" TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: 0 TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: 0 TL."<<endl;
                    }
                    if (netprofit<0){
                        cout<<"Net Loss: "<<profit<< " TL."<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: 0 TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: 0 TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: 0 TL."<<endl;
                    }
                        
                    
                }
                if (profit>10000 && profit<=25000){
                    corporatetax=profit*15/100;
                    netprofit=profit-corporatetax;
                    if (netprofit>0){
                        capitalincrease=netprofit/2;
                        dividend=(netprofit/2);
                        dividendtax=(dividend-dividend*15/100)/ortak;
                        cout<<"Net Profit: "<<netprofit<<" TL."<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: "<<corporatetax<<" TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: "<<capitalincrease<<" TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: "<< dividendtax<<" TL."<<endl;
                    
                    }
                    if (netprofit==0){
                        cout<<"Net Profit: "<<netprofit<<" TL. (Break Even)"<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: "<<corporatetax<<" TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: 0 TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: 0 TL."<<endl;
                    }
                    if (netprofit<0){
                        cout<<"Net Loss: "<<profit<< " TL."<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: 0 TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: 0 TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: 0 TL."<<endl;
                    }
                        
                }
                if (profit>25000 && profit<=50000){
                    corporatetax=profit*20/100;
                    netprofit=profit-corporatetax;
                    if (netprofit>0){
                        capitalincrease=netprofit/2;
                        dividend=(netprofit/2);
                        dividendtax=(dividend-dividend*15/100)/ortak;
                        cout<<"Net Profit: "<<netprofit<<" TL."<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: "<<corporatetax<<" TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: "<<capitalincrease<<" TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: "<< dividendtax<<" TL."<<endl;
                    }
                    if (netprofit==0){
                        cout<<"Net Profit: "<<netprofit<<" TL. (Break Even)"<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: "<<corporatetax<<" TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: 0 TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: 0 TL."<<endl;
                        }
                    if (netprofit<0){
                        cout<<"Net Loss: "<<profit<< " TL."<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: 0 TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: 0 TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: 0 TL."<<endl;
                    }
                        
                    
                        
                    }
                }
                if (profit>50000){
                    corporatetax=profit*25/100;
                    netprofit=profit-corporatetax;
                    if (netprofit>0){
                        capitalincrease=netprofit/2;
                        dividend=(netprofit/2);
                        dividendtax=(dividend-dividend*15/100)/ortak;
                        cout<<"Net Profit: "<<netprofit<<" TL."<<endl;
                        cout<<"VAT: "<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: "<<corporatetax<<" TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: "<<capitalincrease<<" TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: "<< dividendtax<<" TL."<<endl;
                
                    if (netprofit==0){
                        cout<<"Net Profit: "<<netprofit<<" TL. (Break Even)"<<endl;
                        cout<<"VAT: "<<vat<<" TL.";
                        cout<<"Corporate Tax: "<<corporatetax<<" TL."<<endl;
                        cout<<endl;
                        
                        cout<<"Capital Increase: 0 TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: 0 TL."<<endl;
                    }
                    if (netprofit<0){
                        cout<<"Net Loss: "<<profit<< " TL."<<endl;
                        cout<<"VAT:"<<vat<<" TL."<<endl;
                        cout<<"Corporate Tax: 0 TL."<<endl;
                        cout<<endl;
                        cout<<"Capital Increase: 0 TL."<<endl;
                        cout<<ortak<<" shareholders will have a share of: 0 TL."<<endl;
                    }
                            
                }
                
            }
            if (ortak<1){
                cout<<"Invalid input for number of shareholders (Number of shareholders must be greater than or equal to 1)."<<endl;
                cout<<"Stopping calculations...";
            }
            
        }
        else{
            cout<<"Invalid input for expenses (Expenses must be greater than or equal 0)."<<endl;
            cout<<"Stopping calculations...";
        }
    }

    return 0;
}


