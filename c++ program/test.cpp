#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define message 200
#define dates  12

void write(const string* filename){
    
    system("cls");
    fstream myfile;
    char files[message];
    char date[dates];
    char month[dates];
    char year[dates];
    cin.ignore();
    cout<<"Enter the date: "<<endl;
    cin.getline(date,dates);
    cout<<"Enter the month: "<<endl;
    cin.getline(month,dates);
    cout<<"Enter the year: "<<endl;
    cin.getline(year,dates);
    cout<<"Enter the message: \n";
    cin.getline(files, message);
    myfile.open(*filename, ios::out | ios::app);
    if (myfile.is_open()){
      char m;
        myfile<<date<<"/"<<month<<"/"<<year<<endl<<files<<endl;
        cout<<"DO you want multiple lines(y or n ?) "<<endl;
        cin>>m;
        if(m == 'y'){
          int line;
          char files1[message];
          cout<<"How much lines: "<<endl;
          cin>>line;
          cout<<"Enter the message "<<endl;
          for(int j=0; j<=line; j++){
            cin.getline(files1, message);
            myfile<<files1<<"\n";
          }
        }
        else
          cout<<"Okey"<<endl;
        
       myfile.close();
    }


}
void read(const string* filename){
     system("cls");
    fstream file;
    file.open(*filename, ios::in);
    if(file.is_open()){
      string readmsg;
      while(getline(file, readmsg))
      cout<<readmsg<<endl;
     
    file.close();
    }

}
void search(const string* filename) {

    fstream myfile;
    string date;
    string month;
    string year;
    string date_is;

    int i =0;
    int j=0;
    int num;
    int total;
   system("cls");
     myfile.open(*filename, ios::in);
    if(myfile.is_open())
    { 
        string readmsg;
        cout<<"Enter the date\n month\n year: \n";
        cin>>date>>month>>year;
         date_is = date + "/" + month + "/" + year;
        while(getline(myfile, readmsg)){

           if(readmsg == date_is){   
             i++;
            }
             
            if(i == 1 ){
            //cout<<readmsg<<"\n";
            j = j+1;
           
            }
            

        }
        cout<<"date not found "<<endl;
         myfile.close();
    }
   // cout<<"j value = "<<j<<endl;
     myfile.open(*filename, ios::in);
    if(myfile.is_open())
    { 
         
        string readmsg2;
         num = stoi(date);
             num++;
             date = to_string(num);
             int count = 0;
             int count1=0;
             date_is = date + "/" + month + "/" + year;

         while(getline(myfile, readmsg2)){

           if(readmsg2 == date_is){
                
             count++;
            
            }
             
            if(count == 1 ){
            //cout<<readmsg2<<"\n";
            count1++;
           
            }

        }
        
        total = j - count1;
        //cout<<"count"<<count1;
        //cout<<"total"<<total;

        myfile.close();
    }

     myfile.open(*filename, ios::in);
    if(myfile.is_open())
    { 
         
        string readmsg3;
         num = stoi(date);
             num--;
             date = to_string(num);
             int count2 = 0;
             int count3=0;
             date_is = date + "/" + month + "/" + year;
         while(getline(myfile, readmsg3)){

           if(readmsg3 == date_is){
                
             count2++;
             count3++;
            
            }
             
            if(count2 <= total && count3 == 1){
            cout<<readmsg3<<"\n";
            count2++;
            }

        }

        myfile.close();
    }
    
    
}

   int main(){
    
    int i;
    string filename;
    cout<<"Enter the filename with date and '.txt' (EG: srithin12.txt)"<<endl;
    cin>>filename;
    do {  
    cout<<"Enter 1 to write into file "<<endl;
    cout<<"Enter 2 to read the file "<<endl;
    cout<<"Enter 3 to search the file"<<endl;
    cout<<"Enter 0 to exit "<<endl;
    cin>>i;
    switch (i)
    {
    case 1 : write(&filename);
             break;
    case 2: read(&filename);
             break;
    case 3: search(&filename);
             break;
    default: if( i!=0)
             cout<<" ";
        
    }
    
    }while(i != 0);

    return 0;
  }
