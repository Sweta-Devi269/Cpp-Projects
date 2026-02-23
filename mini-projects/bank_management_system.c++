/*Bank Management System (date and time module)

 Main Features to Include:
1.Create New Account
2.Deposit Money
3.Withdraw Money
5.Display Account Details/Check Balance
6. Transfer money
Exit*/

#include<iostream>
#include<vector>
#include<string>
#include<ctime>

using namespace std;

class bank
{
    private:
        int accno;
        string name;
        double balance;
        
    public:
            void createAccount()
            {
                cout<<"\nEnter account number : ";
                cin>>accno;

                cout<<"\nEnter your name : ";
                cin.ignore();
                getline(cin, name);

                cout<<"Enter Initial Balance : ";
                cin>>balance;
                cout<<"\nACCOUNT SUCCESSFULLY CREATED!!!!\n\n";
            }

            void deposit(double amount)
            {
                cout<<"\nEnter the amount to be deposited : ";
                cin>>amount;

                balance += amount;
                cout<<"\nAMOUNT SUCCESSFULLY DEPOSITED!!!\n";
                cout<<"\nCurrent Balance : "<<balance<<endl;
            }

            void withdraw(double amount)
            {
                cout<<"Enter the amount to be deposited : ";
                cin>>amount;

                if(amount>balance || amount<=0)
                    cout<<"\nAmount insufficient!!!!\n";
                
                balance -= amount;
                cout<<"\nAMOUNT SUCCESSFULLY WITHDRAWN!!!\n";
                cout<<"\nCurrent Balance : "<<balance<<endl;
            }

            void display() const
            {
                cout<<"\n-------BANK ACCOUNT DETAILS-------\n\n";
                cout<<"Account Number : "<<accno<<endl;
                cout<<"Account Holder Name : "<<name<<endl;
                cout<<"Current Balance : "<<balance<<endl;
            }
            
            void transfer(vector<bank> &accounts)
            {
                int fromAccno, toAccno;
                double amount;

                cout<<"\nEnter the sender's Account number : ";
                cin>>fromAccno;
                cout<<"\nEnter the recevier's Account number : ";
                cin>>toAccno;

                if(fromAccno == toAccno)
                {
                    cout<<"\nCannot transfer to the same account!!!!\n";
                    return;
                }

                bank *sender = nullptr;
                bank *receiver = nullptr;

                //Find sender and receiver
                for (auto &acc : accounts) 
                {
                    if (acc.getAccNumber() == fromAccno) 
                        sender = &acc;
                    else if (acc.getAccNumber() == toAccno)
                        receiver = &acc;
                }           
                
                if (!sender || !receiver) {
                    cout << "One or both account numbers not found.\n";
                    return;
                }

                cout << "Enter amount to transfer: ₹";
                cin >> amount;

                if (amount <= 0) {
                    cout << "Invalid transfer amount.\n";
                    return;
                }
            // Withdraw from sender and deposit to receiver
                if (amount > 0) {
                    if (amount <= sender->getBalance()) { // Assuming getBalance() exists
                        sender->withdraw(amount);
                        receiver->deposit(amount);
                        cout << "₹" << amount << " transferred successfully.\n";
                    } 
                    else {
                        cout << "Sender has insufficient balance.\n";
                    }
                }
            }

            int getAccNumber() const 
            {
                return accno;
            }
};

vector<bank> &accounts;
/*for (int i = 0; i < accounts.size(); i++) {
    bank &acc = accounts[i];
    // use acc here
}   EQUIVALENT TO THE BELOW FUNCTION*/

// Helper function to find account by number
bank *findAccount(int accNum)
{
    for(auto &acc : accounts)
    {
        if(acc.getAccNumber() == accNum)
            return &acc;
    }
    return nullptr;
}

int main()
{
    int choice;
    cout<<"\n----------\tMENU\t----------\n\n"<<endl;
    cout<<"1.Create New Account\n2. Deposit Money\n3.Withdraw Money\n4.Check Balance\n";
    cout<<"5.Display Account Details\n6. Transfer money\n7. Exit\n\n";
    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1: {
                    cout<<"\nCREATING ACCOUNT:-\n\n";
                    bank b1;
                    b1.createAccount();
                    accounts.push_back(b1);
                    break;
                }

        case 2: {
                    cout<<"\nDEPOSITING MONEY:-\n\n";
                    
                
                }

    }
}
