#include <iostream>
#include <string>
using namespace std;

double calculateVAT(double grossIncome, string location){
    double vat=0;
    if (location == "foreign"){
        vat=(grossIncome*18)/100;
    }
    else if (location == "local"){
        vat=(grossIncome*15)/100;
    }
    return vat;
}

double calculateProfit(double grossIncome, double expenses, string location){
    double profit=0;
    double vat=calculateVAT(grossIncome,location);
    profit= grossIncome- vat -expenses;
    return profit;
}
double calculateCorporateTax(double profit){
    double corporatetax=0;
    if (profit<=0){
        corporatetax=0;
    }
    else if (profit <= 10000){
        corporatetax=profit*10/100;
    }
    else if (profit>10000 && profit<= 25000){
        corporatetax=profit*15/100;
    }
    else if (profit>25000 && profit<=50000){
        corporatetax=profit*20/100;
    }
    else if (profit>50000){
        corporatetax=profit*25/100;
    }
    
    return corporatetax;
}
double calculateNetProfit(double grossIncome, double expenses, string location){
    double netprofit=0;
    double profit=calculateProfit(grossIncome,expenses,location);
    double ct= calculateCorporateTax(profit);
    double prof= calculateProfit(grossIncome,expenses,location);
    netprofit=prof-ct;
    return netprofit;
}
double calculateDividend(double netProfit, int numOfShareholders){
    double dividend=0;
    dividend=(netProfit/2-(netProfit*15/200))/numOfShareholders;
    return dividend;
}
bool getCompanyData(string& companyName, string& location, double& grossIncome, double& expenses, int& numOfShareholders){
    cout<<"Please enter the name of the company: ";
    cin>>companyName;
    cout<<"Is the company local or foreign? ";
    cin>>location;
    if (!(location == "local" || location == "foreign")){
        cout<<"Invalid location.";
        return false;
    }
    else{
        cout<<"Please enter the gross income of "<<companyName<<": ";
        cin>>grossIncome;
        if(grossIncome<=0){
            cout<<"Invalid input for gross income.";
            return false;
        
        }
        else{
            cout<<"Please enter expenses of "<<companyName<<": ";
            cin>>expenses;
            if (expenses<0){
                cout<<"Invalid input for expenses. ";
                return false;
            }
            else{
                cout<<"Please enter the number of shareholders: ";
                cin>>numOfShareholders;
                if (numOfShareholders <1 ){
                    cout<<"Invalid input for the number of shareholders.";
                    return false;
                }
                else{
                    return true;
                }
            }
        }
    }
}
void outputCompanyResults(string companyName, double grossIncome, double expenses, int numOfShareholders, string location){
    double profit=calculateProfit(grossIncome,expenses,location);
    double capitalincrease,netProfit,netprof;
    double dividenttax=0;
    netProfit=calculateNetProfit(grossIncome, expenses, location);
    netprof=calculateNetProfit(grossIncome,expenses,location);
    dividenttax=calculateDividend(netProfit,numOfShareholders);
    if (netprof>0){
        cout<<endl;
        cout<<"*********** "<< companyName<<" Financial Report **********"<<endl;
        cout<<endl;
        cout<<"Net Profit: "<< calculateNetProfit(grossIncome,expenses,location)<<" TL."<<endl;
        
        cout<<"VAT: "<<calculateVAT(grossIncome,location)<<" TL."<<endl;
        cout<<"Corporate Tax: "<<calculateCorporateTax(profit)<<" TL."<<endl;
        cout<<endl;
        capitalincrease=calculateNetProfit(grossIncome,expenses,location)/2;
        cout<<"Capital Increase: "<<capitalincrease<<" TL."<<endl;
        
        cout<<numOfShareholders<<" shareholders will have a share of: "<<dividenttax<<" TL."<<endl;
    }
    else if (netprof==0){
        cout<<endl;
        cout<<"*********** "<< companyName<<" Financial Report **********"<<endl;
        cout<<endl;
        cout<<"Net Profit: "<< calculateNetProfit(grossIncome,expenses,location)<< " TL. (Break Even)"<<endl;
        cout<<"VAT: "<<calculateVAT(grossIncome,location)<<" TL."<<endl;
        cout<<"Corporate Tax: 0 TL."<<endl;
        cout<<endl;
        capitalincrease=calculateNetProfit(grossIncome,expenses,location)/2;
        cout<<"Capital Increase: 0 TL."<<endl;
        cout<<numOfShareholders<<" shareholders will have a share of: 0 TL."<<endl;
    }
    else{
        cout<<endl;
        cout<<"*********** "<< companyName<<" Financial Report **********"<<endl;
        cout<<endl;
        cout<<"Net Loss: "<< calculateNetProfit(grossIncome,expenses,location)<< " TL."<<endl;
        cout<<"VAT: "<<calculateVAT(grossIncome,location)<<" TL."<<endl;
        cout<<"Corporate Tax: 0 TL."<<endl;
        cout<<endl;
        capitalincrease=calculateNetProfit(grossIncome,expenses,location)/2;
        cout<<"Capital Increase: "<<capitalincrease<<" TL."<<endl;
        cout<<numOfShareholders<<" shareholders will have a share of: 0 TL."<<endl;
    }
}

int main()
{
    double grossIncome1, grossIncome2,expenses1, expenses2, profit1, profit2, netProfit1, netProfit2, vat1, vat2,corporatetax1, corporatetax2,dividend1, dividend2;
    string companyName1,companyName2, location1, location2;
    int numOfShareholders1,numOfShareholders2;
    cout<<"This accounting program calculates the state taxes and dividends for the company shareholders."<<endl;
 
    if (!getCompanyData(companyName1, location1, grossIncome1, expenses1, numOfShareholders1)){
        return 0;
    }
    else{
        
        if (!getCompanyData(companyName2, location2, grossIncome2, expenses2, numOfShareholders2)){
            return 0;
        }
        else{
            
            vat1= calculateVAT(grossIncome1,location1);
            profit1= calculateProfit(grossIncome1,expenses1,location1);
            corporatetax1= calculateCorporateTax(profit1);
            netProfit1= calculateNetProfit(grossIncome1,expenses1,location1);
            dividend1= calculateDividend(netProfit1, numOfShareholders1);
            outputCompanyResults(companyName1,grossIncome1,expenses1,numOfShareholders1,location1);
            vat2=calculateVAT(grossIncome2,location2);
            profit2=calculateProfit(grossIncome2,expenses2,location2);
            corporatetax2=calculateCorporateTax(profit2);
            netProfit2=calculateNetProfit(grossIncome2,expenses2,location2);
            dividend2=calculateDividend(netProfit2, numOfShareholders2);
            outputCompanyResults(companyName2,grossIncome2,expenses2,numOfShareholders2,location2);
            cout<<endl;
            if (calculateNetProfit(grossIncome1,expenses1,location1)==calculateNetProfit(grossIncome2,expenses2,location2)){
                cout<<"Both Bershka and LCW have an equivalent financial performance in terms of net profit."<<endl;
            }
            else if (calculateNetProfit(grossIncome1,expenses1,location1)>calculateNetProfit(grossIncome2,expenses2,location2)){
                cout<<companyName1<<" has a superior financial performance in terms of net profit compared to "<<companyName2<<"."<<endl;
            }
            else{
                cout<<companyName2<<" has a superior financial performance in terms of net profit compared to "<<companyName1<<"."<<endl;
            }
        }
    }
    return 0;
}

