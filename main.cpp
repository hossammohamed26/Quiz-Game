#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct bank {
    char name[1000];
    char add[1000];
    char trantype[11];
    int trans[10];
};
///functions
int sumtrans(char[],int[],int);
int idd(char name[],bank a[],int );
char* split(char []);
///built in
int strcmp (const char * s1, const char * s2);
size_t strlen(const char * str);


int main()
{
    int strcount=0;
    bank a[20];
    int custnum,trannum;
    int trana[20];
    char city[1000];
    //string citynum[custnum];
    char more[4]="Yes";
    ///getting customers numbers
    cout<<"Enter Customers number maximum 20"<<endl;
    cin>>custnum;
    while(true){
    if(custnum<1||custnum>20){
        cout<<"Enter valid Customers number maximum 20 & minimum 1"<<endl;
        cin>>custnum;
    }
    else{
        break;
    }
}
    ///Inputs
    for(int i=0;i<custnum;i++){
        ///Getting name
        cout << "Please enter name of "<< i+1 <<" customer" << endl;
        cin>>a[i].name;
        cin.ignore();

        cout << "Please enter address like that number &  street name, neighborhood, city." << endl;
        cin.get(a[i].add,1000);
        ///repeating add entering
        while(true){
            strcount=0;
            for(int k=0;k<strlen(a[i].add);k++){
                if(a[i].add[k]==','){
                    strcount++;
        }
    }

        if(strcount<2||!isdigit(a[i].add[0])){
            cin.ignore();
            cout<<"Please enter valid address like that street name, neighborhood, city."<<endl;
            cin.get(a[i].add,1000);
    }
        else if (strcount==2){
                break;
        }

    }

        //citynum[i]=split(a[i].add);
        cout<<"Enter Number of Transactions between 1:10"<<endl;
        cin>>trannum;
        cout << "Please enter "<<a[i].name<<"\'s account transactions" << endl;
        for(int j=0;j<trannum;j++){
            cin>>a[i].trantype[j];
            cin>>a[i].trans[j];
            ///repeating trans entering
            if(a[i].trans[j]<0){
                cout<<"Please enter valid transaction:"<<endl;
                cin>>a[i].trantype[j];
                cin>>a[i].trans[j];
            }
        }
        ///cal bal
        trana[i]=sumtrans(a[i].trantype,a[i].trans,trannum);

    }
    ///Bank management system

    int cho;
    char name[100];
    char m1[]="Yes";
    char m2[]="yes";

    while(strcmp(more,m1)==0||strcmp(more,m2)==0){
            system("CLS");
            cout<<"Hello in bank management system please enter your choice"<<endl;
            cout<<"1) To print all names and account balances"<<endl;
            cout<<"2) To print specific customer\'s account balance"<<endl;
            cout<<"3) To edit customer transactions"<<endl;
            cout<<"4) To show customer with highest balance"<<endl;
            cout<<"5) To change customer\'s name, transactions, balance, or address"<<endl;
            cout<<"6) To show how many customers in one city"<<endl;
            cin>>cho;
            if(cho==1){
                    ///print all data
                for(int i=0;i<custnum;i++){
                    cout<<i+1<<") Name: "<<a[i].name<<" and his / her Account Balance is : "<<trana[i]<<endl;
                }
            }
            else if(cho==2){
                int id=0;
                cout<<"Enter His or Her Name."<<endl;
                cin>>name;
                ///fun to find id
                id=idd(name,a,custnum);
                cout<<name<<"\'s Account Balance; "<<trana[id]<<endl;
            }
            else if(cho==3){
                int id=0;
                cout<<"Enter His or Her Name."<<endl;
                cin>>name;
                ///fun to find id
                id=idd(name,a,custnum);
                cout<<"Enter Number of Transactions between 1:10"<<endl;
                cin>>trannum;
                cout << "Please enter "<<a[id].name<<"\'s account transactions" << endl;
                for(int j=0;j<trannum;j++){
                    cin>>a[id].trantype[j];
                    cin>>a[id].trans[j];
                    ///repeating trans entering
                    if(a[id].trans[j]<0){
                        cout<<"Please enter valid transaction:"<<endl;
                        cin>>a[id].trantype[j];
                        cin>>a[id].trans[j];
                    }
                }
                trana[id]+=sumtrans(a[id].trantype,a[id].trans,trannum);

            }
            else if(cho==4){
                    ///highest balance
                //int b[custnum];

                int j;
                /*///array to sum all balances for every one in the bank
                for(int i=0;i<custnum;i++){
                    b[i]=sumtrans(a[i].trantype,a[i].trans,trannum);
                }*/
                int maxi=trana[0];
                for(int i=0;i<custnum;i++){
                    ///getting highest one
                    if(trana[i]>maxi){
                        maxi=trana[i];
                        j=i;
                    }
                }
                cout<<"The Highest balance customer is "<<a[j].name<<endl
                <<"  His/her Address is "<<a[j].add<<endl
                <<"  His/Her Balance is "<<maxi<<endl;

            }
            else if(cho==5){
                ///Editing all data
                int strcount=0;
                cout<<"Enter His or Her Name."<<endl;
                cin>>name;
                ///fun to find id
                int id=idd(name,a,custnum);
                cout<<"Enter the new data"<<endl;
                ///Getting name
                cout << "Please enter name of the new customer" << endl;
                cin>>a[id].name;
                cin.ignore();

                cout << "Please enter address like that street name, neighborhood, city." << endl;
                cin.get(a[id].add,1000);
                ///repeating add entering
                while(true){
                    strcount=0;
                    for(int k=0;k<strlen(a[id].add);k++){
                        if(a[id].add[k]==','){
                            strcount++;
                }
            }

                if(strcount<2||!isdigit(a[id].add[0])){
                    cin.ignore();
                    cout<<"Please enter valid address like that number & street name, neighborhood, city."<<endl;
                    cin.get(a[id].add,1000);
            }
                else if (strcount==2){
                        break;
                }

            }
                cout<<"Enter Number of Transactions between 1:10"<<endl;
                cin>>trannum;
                cout << "Please enter "<<a[id].name<<"\'s account transactions" << endl;
                for(int j=0;j<trannum;j++){
                    cin>>a[id].trantype[j];
                    cin>>a[id].trans[j];
                    ///repeating trans entering
                    if(a[id].trans[j]<0){
                        cout<<"Please enter valid transaction:"<<endl;
                        cin>>a[id].trantype[j];
                        cin>>a[id].trans[j];
                    }
                }
                trana[id]+=sumtrans(a[id].trantype,a[id].trans,trannum);
            }
            else if(cho==6){
                cout<<"Enter The Name of the city"<<endl;
                cin>>city;
                int c=0;
                for(int i=0;i<custnum;i++){
                    if(strcmp(split(a[i].add),city)==0){
                        c++;
                    }
                }
                cout<<"The Number of Customers in "<<city<<" is "<<c<<endl;
            }
            cout<<"Do You want to do more on the bank system"<<endl;
            cin>>more;
}

    return 0;
}


int sumtrans(char transtype[],int trans[],int trannum){
    int sum=0;
    for(int i=0;i<trannum;i++){
        if(transtype[i]=='D'){
            sum+=trans[i];
        }
        else if (transtype[i]=='W'){
            sum-=trans[i];
        }
    }
    return sum;
}

int idd(char name[],bank a[],int custnum){
    int num=0;
    for(int i=0;i<custnum;i++){
        if(strcmp(a[i].name,name)==0){
            num=i;
            break;
        }
    }
    return num;
}

char* split(char add[]){
    char* ptr;
    char* str;
    ptr=strtok(add,",");
    int i=0;
    while(ptr !=NULL){
        i++;
        if(i==3){
            str=ptr;
        }
        ptr=strtok(NULL,",");
    }
    return str;
}
///built in functions we used
///strcmp
int strcmp (const char * s1, const char * s2)
{
    for(; *s1 == *s2; ++s1, ++s2)
        if(*s1 == 0)
            return 0;
    return *(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1;
}
///strlen
size_t strlen(const char * str)
{
    const char *s;
    for (s = str; *s; ++s) {}
    return(s - str);
}
