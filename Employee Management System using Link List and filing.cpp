#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct employee
{
    	int roll, bps;
    	int emp_id;
    	char name[20],fname[22], des[12];
    	int salary;
    	int age;
    	employee *next;    	
void getdata()
	{
		cout<<"enter name"<<endl;
		cin>>name;
		cout<<"enter fname"<<endl;
		cin>>fname;
		char q[6]={'a','d','m','i','n'},q1[5]={'t','e','c','h'},q2[12]={'m','a','n','a','g','e','r','i','a','l'},q3[7]={'o','t','h','e','r'};
			char    qq[6]={'A','d','m','i','n'},q4[5]={'T','e','c','h'},q5[12]={'M','a','n','a','g','e','r','i','a','l'},q6[7]={'O','t','h','e','r'};
			cout<<"Enter must be either\n\t Admin\n\t Tech\n\t Managerial\n\t Other"<<endl;
		do{
		
	        cin>>des;
			if(strcmp(des,q)==0){
			cout<<des<<endl;
			break;
			}
			else if(strcmp(des,q1)==0){
			cout<<des<<endl;
			break;
			}
			else if(strcmp(des,q2)==0){
			cout<<des<<endl;
			break;
			}
				else if(strcmp(des,q3)==0){
			cout<<des<<endl;
			break;
			}
			else if(strcmp(des,qq)==0){
			cout<<des<<endl;
			break;
			}
			else if(strcmp(des,q4)==0){
			cout<<des<<endl;
			break;
			}
			else if(strcmp(des,q5)==0){
			cout<<des<<endl;
			break;
			}
				else if(strcmp(des,q6)==0){
			cout<<des<<endl;
			break;
			}
			else
			cout<<"you enter| "<<des<<"  | which is  worng\n\n"<<endl;
}while(true);
			cout<<"Enter enployee BPS (must between 1 to 22)"<<endl;
		do
		{
	    	cin>>bps;
	    	if(bps>=1 && bps<23)
	    	break;
		else
		{
          cout<<"you enter  wrong BPS please enter again according to limit"<<endl;
		}
		}
		while(true);
		int y;
		y=((bps*10000)*45)/100;
		salary=(bps*10000)+y;
		cout<<"employee salary="<<salary<<endl;
		cout<<"Enter enploy id number(must between 7777 to 9999)"<<endl;
		do
		{
		  cin>>emp_id;
		  if(emp_id>=7777 && emp_id<9999)
		  break;
		else
		{
			cout<<"you enter  wrong id please enter again according to limit"<<endl;
		}
		}
		while(true);
		cout<<"Enter enployee age (must between 18 to 60)"<<endl;
		do
		{
		  cin>>age;
		  if(age>=18 && age<61)
	    	break;
		else
		{
	    	cout<<"you enter  wrong age please enter again according to limit"<<endl;
		}
		}
		while(true);		
	}
void addrecord()
   {    
		fstream f;
		employee s;
		f.open("record.txt",ios::app|ios::binary);
		s.getdata();
		f.write((char*)&s,sizeof(s));
		f.close();
	}
	
void showdata()
   {  
		cout<<"\n\tdesignation = "<<des<<endl;
		cout<<"\tname="<<name<<"\n\tfather_name= "<<fname<<"\n\tbps number= "<<bps<<"\n\tempoly age="<<age<<"\n\t employ id= "<<emp_id<<endl;
		cout<<"---------------------------------"<<endl;
	}
void display(){
	    system("cls");
	    roll=1;
		fstream read_file;
		employee s;
		read_file.open("record.txt",ios::app|ios::in|ios::out|ios::binary);
		
		if(!read_file)  // If file is Not Found
			cout<<"\nFile Not Found."<<endl;
			else
			{
		    	while(!read_file.eof())
				{
				   read_file.read((char *)&s, sizeof(s));
		           cout<<"No."<<roll<<endl;
		           s.showdata();
	               roll++;
				}
				read_file.close();
			}
	}
void search()
	{
		   system("cls");
		   fstream search_data;
		   employee s;
		   search_data.open("record.txt",ios::in |ios::binary);
		   int x;
	   	   cout<<"\n\t\tPress \n\t\t1 for Search by emp_id \n\t\t2 for Search by Name \n\t\t3 for Search by age \n\t\t4 for Search Eldest Employee ";
	   	   cout<<"\n\t\t5 for Search Youngest Employee \n\t\t6 for Search by BPS \n\t\t7 for Search by designation"<<endl;
	   	   cin>>x;
	   	   switch (x)
	   	{
	   		 case 1:
		   	 {
			   		system("cls");
			   		int Search_id;
			   		cout<<"\t\t\tEnter Id To Be Search:"<<endl;
			     	cin>>Search_id;
		    	  while(search_data.read((char*)this,sizeof(*this)))
		    	   {
		    	 	 if(emp_id==Search_id)
		    	 	   {
		    	 		  showdata();
		    	 		  break;
					  }
				  }
				 if(emp_id!=Search_id)
				  {
				 	 cout<<"\n\t\tNot Found"<<endl;
			    	}
		     		search_data.close();
				}break;
				case 2:	
				{
				 system("cls");	   	   			   
		   	 	 char sname[23];
		   	 	 cout<<"\n\t\tEnter Name To Be Search:"<<endl;
			 	 cin>>sname;
			 	 while(search_data.read((char*)this,sizeof(*this)))
					{			
						if(strcmp(name,sname)==0)
						{
							showdata();
							break;
						}
					}
					if(strcmp(name,sname)!=0)
					{
						cout<<"\n\t\t\tNOT FOUND"<<endl;
					}			 
					search_data.close();	
				}break;
				case 3:
				{
				 system("cls");
				 int Search_age;
			   	 cout<<"\n\t\t\tEnter Age To Be Search:"<<endl;
				 cin>>Search_age;
				 while(search_data.read((char*)this,sizeof(*this)))
				    {
				     	if(age==Search_age)
				     	{
				     	 showdata();
				     	 break;
						}   	
					}
					 if(age!=Search_age)
				   {
					  cout<<"\n\t\t\tNot Found Age"<<endl;
					}		
			    	search_data.close();	
			    }break;
				case 4:
				{
					system("cls");
					int y;
					y=18;
					while(search_data.read((char*)this,sizeof(*this)))
					{						
						if(age>y)
						{
					    	y=age;
						}	
					}
					
				 while(search_data.read((char*)this,sizeof(*this)))
				  {					
					 if(age==y)
					 	{	
							system("cls");
						    cout<<"\n\t\tEldest Employee"<<endl;
							showdata();
							break;	
						}
					}
				search_data.close();
				}break;
				case 5:
				{
				 system("cls");
				 int y;
			     y=60;
			     while(search_data.read((char*)this,sizeof(*this)))
				  {					
						if(age<y)
						{
							y=age;			
						}
			    	}
			    	while(search_data.read((char*)this,sizeof(*this)))
			    	{					
						if(age==y)
						{		
						    system("cls");
							cout<<"\n\t\tYoungest Employee"<<endl;
							showdata();
							break;	
						}
					}
			      search_data.close();
				}break;
				case 6:
				{
				 system("cls");
		   	 	 int b;
		   	 	 cout<<"\n\t\tEnter BPS To Be Search:"<<endl;
			 	 cin>>b;
			 	 while(search_data.read((char*)this,sizeof(*this)))
		  		   {
				  		if(bps==b)
				  		{
				  	     cout<<"\n\t\tBPS is found"<<endl;
				  		 showdata();
				  		 break;
					   }
				   }
				  if(bps!=b)
				   {
				  	  cout<<"\n\t\t\tNot Found"<<endl;
				   }			    
				  search_data.close();
				}break;
				case 7:
				{
				   system("cls");
				   char m[23];
			 	   cout<<"Enter Designation That you Want To search"<<endl;
			 	   cin>>m;
				 	while(search_data.read((char*)this,sizeof(*this)))
					{
						if(strcmp(des,m)==0)
						{
						  showdata();
						}
					}
					if(strcmp(des,m)!=0)
					{
						cout<<"Designation is NOT FOUND"<<endl;
					}
			     search_data.close();
				}break;	 		   				
			}
		}	
    void deleted()
	{
		fstream f,d;
		employee s;
		int r;
			cout<<"enter empoly ID"<<endl;
				cin>>r;
	        	f.open("record.txt",ios::in|ios::binary|ios::out);
			
				while(f.read((char*)&s,sizeof(s)))
				{
					if(r==s.emp_id)
					{
					  s.showdata();
					  cout<<"\n \t This record will delected"<<endl;
				    }	
	     	      if(r!=s.emp_id)
					{  	d.open("oop.txt",ios::binary|ios::in|ios::out|ios::app);
						d.write((char*)&s,sizeof(s));
						d.close();
					}
			 	}
		f.close();	 	
    	remove("record.txt");
    	rename("oop.txt","record.txt");
}
  void updated_des()
  {
  	employee s;
  	fstream f;
 char q[6]={'a','d','m','i','n'},q1[5]={'t','e','c','h'},q2[12]={'m','a','n','a','g','e','r','i','a','l'},q3[7]={'o','t','h','e','r'};
  		char    qq[6]={'A','d','m','i','n'},q4[5]={'T','e','c','h'},q5[12]={'M','a','n','a','g','e','r','i','a','l'},q6[7]={'O','t','h','e','r'};
			cout<<"Enter must be either admin \n\t tech\n\t managerial\n\t other"<<endl;
		do{
	        cin>>des;
			if(strcmp(des,q)==0){
				s.des[12]=q[6];
			cout<<des<<endl;
			break;
			}
			else if(strcmp(des,q1)==0){
				s.des[12]=q1[5];
			cout<<des<<endl;
			break;
			}
			else if(strcmp(des,q2)==0){
				s.des[12]=q2[12];
			cout<<des<<endl;
			break;
			}
				else if(strcmp(des,q3)==0){
					s.des[12]=q3[7];
			cout<<des<<endl;
			break;
			}
				else if(strcmp(des,qq)==0){
					s.des[12]=qq[6];
			cout<<des<<endl;
			break;
			}
			else if(strcmp(des,q4)==0){
				s.des[12]=q5[5];
			cout<<des<<endl;
			break;
			}
			else if(strcmp(des,q5)==0){
				s.des[12]=q5[12];
			cout<<des<<endl;
			break;
			}
				else if(strcmp(des,q6)==0){
					s.des[12]=q6[7];
			cout<<des<<endl;
			break;
			}
			else
			cout<<"you enter| "<<des<<"  | which is  worng\n\n"<<endl;
}while(true);
  }
 void updated()
	 {
		fstream f,d;
		employee s;
		int r,n;
			cout<<"enter empoly ID"<<endl;
				cin>>r;
	        	f.open("record.txt",ios::in|ios::binary | ios::out);
		 	while(f.read((char*)&s,sizeof(s)))
				{	if(r==s.emp_id)
				{
					s.showdata();
					cout<<"\n\n\t\t This record will updating"<<endl;
					cout<<"***************************************************"<<endl;
					d.open("oop.txt",ios::binary|ios::in|ios::out|ios::app);
					s.updated_des();
					d.write((char*)&s,sizeof(s));
					cout<<"this record was updated"<<endl;
					d.close();
				}		
	     	      else if(r!=s.emp_id)
					{  	n=1;
					    d.open("oop.txt",ios::binary|ios::in|ios::out|ios::app);
						d.write((char*)&s,sizeof(s));
						d.close();
					}
			 	}
		f.close();	 	
		if(n==1){
    	remove("record.txt");
    	rename("oop.txt","record.txt");
          }
}
};
int main()
	{ 
     employee S;
	 int o,i;
	 char n;
	 do{
	 system("cls");
     cout<<"press \n\t 1 for insert new records \n\t 2 for display records \n\t 3 for searching \n\t 4 for delete a single record\n\t 5 for updated "<<endl;
	 cin>>o;
	 switch(o)
	   {
	   	case 1:
	   	{
			   	 employee *next;
				 employee *current,*first,*last;
				 current=new employee;
	    		 current->addrecord();
				 current->next=NULL;
				 first=last=current;
				 int choice;
			 do
			 {
			 	cout<<"ENTER 1 to add more record OR press any other numrice key to exit "<<endl;
			    cin>>choice;
			    if(choice!=1)
			     break;
			 	current=new employee;
			 	current->addrecord();
			 	last->next=current;
			 	last=current;
			 }
			 while(true);
			 break;	
		}
		    case 2:	
			{  
			    	S.display();
			    	break;
			}
			case 3:
				
					S.search();
					break;
			case 4:
					S.deleted();
					break;
			case 5:
				S.updated();
				break;	
			default :
					cout<<"you enter worng number"<<endl;			
			}
			cout<<"if you want to preform any other operation than enter y"<<endl;
			cin>>n;
		}	
	while(n=='y' || n=='Y');
	system("pause");
		return 0;
	}

