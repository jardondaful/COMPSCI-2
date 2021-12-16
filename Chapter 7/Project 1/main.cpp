#include <iostream>
using namespace std;
int main() 
{
  int users[100];
  int master_account = 1000;
  int project_accounts[10];
  string position;
  int id;
  int copies;
  string account;
  while(position.compare("Q)uit")!=0)
  {
    cout<<endl;
  cout<<"Please choose your position: U)ser A)dministrator Q)uit"<<endl;
  cin>>position;
  if(position.compare("U)ser")==0)
  {
    cout<<endl;
    cout<<"Please enter your ID: ";
  cin>>id;
  cout<<endl;
  cout<<"Please enter the number of cpoies you wish to make: ";
  cin>>copies;
  users[id] = copies;
  cout<<endl;
  }
  else if(position.compare("A)dministrator")==0)
  {
    cout<<endl;
    cout<<"Please choose which kind of account you want to access: B)alance M)aster P)roject "<<endl;
    cin>>account;
    cout<<endl;
    if(account.compare("B)alance")==0)
    {
      cout<<"The following are the balances of the master account: "<<endl;
      cout<<master_account<<endl;
      cout<<"The following are the balances of the project accounts: "<<endl;
      for(int i = 0; i < 10; i++)
      {
        cout<<project_accounts[i]<<endl;
      }
     cout<<endl;
    }
    else if(account.compare("M)aster")==0)
    {
      cout<<endl;
      cout<<"Please enter your ID: ";
      cin>>id;
      master_account = id;
      cout<<"The ID inputted is now linked to the master account"<<endl;
    }
    else 
    {
      cout<<endl;
      cout<<"Please enter your user ID: ";
      cin>> id;
      cout<<"Please enter the project IDs: ";
     for(int i = 0; i < 10; i++)
     {
      int project_id;
       cin>>project_id;
       project_accounts[i]=project_id;

     }
     cout<<endl;
    }
    }
  }
  {
    cout<<"You quit using the software";
  }
  return 0;
  }

