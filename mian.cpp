
#include <bits/stdc++.h>

using namespace std;

struct Book{
    Book *prev=NULL;
    long long ISBN;
    string Author;
    string Title;
    string Publisher;
    string Publsihing_date;
    int Number_of_pages;
    int Total_quantity;
    Book *next=NULL;
};
Book *head=NULL;
int book_num=0;

int insert_book_end()
{
    long long ISBN;
    string Author,Title,Publisher,Publsihing_date;
    int Number_of_pages,Total_quantity;
    cout<<"Enter ISBN of book: ";
    cin>>ISBN;
    cout<<"Enter Title of book(use _ instead of spaces): ";
    cin>>Title;
    cout<< "Enter the Author of the book(use _ instead of spaces): ";
    cin>> Author;
    cout<<"Enter Publisher of book(use _ instead of spaces): ";
    cin>>Publisher;
    cout<<"Enter Publishing date of book(dd-mm-yyyy): ";
    cin>>Publsihing_date;
    cout<<"Enter Number of pages  of book: ";
    cin>>Number_of_pages;
    cout<<"Enter Total quantity of book: ";
    cin>>Total_quantity;

    Book *Lbook = new Book;
    Lbook->ISBN=ISBN;
    Lbook->Author=Author;
    Lbook->Title=Title;
    Lbook->Publisher=Publisher;
    Lbook->Publsihing_date=Publsihing_date;
    Lbook->Number_of_pages=Number_of_pages;
    Lbook->Total_quantity=Total_quantity;


    if(head==NULL)
        head=Lbook;
    else{
    Book *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    Lbook->next=NULL;
    temp->next=Lbook;
    Lbook->prev=temp;

    }
    book_num++;
}


int display()
{
    if (head==NULL)
        cout<<"Record Empty!";
    else{
    Book *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->ISBN<<" "<<temp->Title<<" "<<temp->Author<<" "<<temp->Publisher<<"  "<<temp->Publsihing_date<<"  "<<temp->Number_of_pages<<"  "<<temp->Total_quantity<<endl;
        temp=temp->next;
    }
    }
}


void search_by_title(string title)
{
    if(head==NULL)
    {
        cout<<"No record to show.\n";
    }else{
    Book *temp=head;
    while(temp!=NULL)
    {
        if(temp->Title==title)
        {
          cout<<temp->ISBN<<" "<<temp->Title<<" "<<temp->Author<<" "<<temp->Publisher<<" "<<temp->Publsihing_date<<" "<<temp->Number_of_pages<<" "<<temp->Total_quantity<<endl;
          return;
        }
        temp=temp->next;
    }
    if (temp==NULL)
        cout<<"Record Not found.";
    }


}


void search_by_isbn(long long isbn)
{
    if(head==NULL)
    {
        cout<<"No record to show.\n";
    }else{
    Book *temp=head;
    while(temp!=NULL)
    {
        if(temp->ISBN==isbn)
        {
          cout<<temp->ISBN<<" "<<temp->Title<<" "<<temp->Author<<" "<<temp->Publisher<<" "<<temp->Publsihing_date<<" "<<temp->Number_of_pages<<" "<<temp->Total_quantity<<endl;
          return;
        }
        temp=temp->next;
    }
    if (temp==NULL)
        cout<<"Record Not found.";
    }


}




void update_(long long isbn)
{
    if(head==NULL)
    {
        cout<<"No record to update.\n";
    }else{
    Book *temp=head;
    while(temp!=NULL)
    {
        if(temp->ISBN==isbn)
        {
            cout<<"Current Data: \n";
          cout<<temp->ISBN<<" "<<temp->Title<<" "<<temp->Author<<" "<<temp->Publisher<<" "<<temp->Publsihing_date<<" "<<temp->Number_of_pages<<" "<<temp->Total_quantity<<endl;
          string Author,Title,Publisher,Publsihing_date;
          int Number_of_pages,Total_quantity;
          cout<<"Enter Title of book(use _ instead of spaces): ";
          cin>>Title;
          cout<< "Enter the Author of the book(use _ instead of spaces): ";
          cin>> Author;
          cout<<"Enter Publisher of book(use _ instead of spaces): ";
          cin>>Publisher;
          cout<<"Enter Publishing date of book(dd-mm-yyyy): ";
          cin>>Publsihing_date;
          cout<<"Enter Number of pages  of book: ";
          cin>>Number_of_pages;
          cout<<"Enter Total quantity of book: ";
          cin>>Total_quantity;

          temp->Title=Title;
          temp->Author=Author;
          temp->Publisher=Publisher;
          temp->Publsihing_date=Publsihing_date;
          temp->Number_of_pages=Number_of_pages;
          temp->Total_quantity=Total_quantity;
          return;
        }
        temp=temp->next;
    }
    if (temp==NULL)
        cout<<"Record Not found.";
    }



}



void delete_(long long isbn)
{
    if(head==NULL)
    {
        cout<<"Record Empty.\n";
    }else{
    Book *temp=head;
    while(temp!=NULL)
    {
        if(temp->ISBN==isbn)
        {
            if (temp == head)
                head = temp -> next;
            else
                temp->prev->next=temp->next;
            delete(temp);
          return;
        }
        temp=temp->next;
        cout<<temp -> ISBN;
    }
    if (temp==NULL)
        cout<<"Record Not found.";
    }
 book_num--;
}


void sort_byTitle()
{
    Book *sorted=NULL;
    string ar[book_num];
    int n=0;
    if (head==NULL)
        cout<<"empty list";
    else
    {
        Book* temp=head;
        while(temp->next!=NULL)
        {
            ar[n]=temp->Title;
            n++;
            temp=temp->next;
        }
        ar[n]=temp->Title;
    }
    sort(ar,ar+n+1);
    for (int i=0;i<=n;i++)
    {

		Book *tempN=head;
		if(tempN->Title==ar[i])
        {
            Book *Lbook = new Book;
            Lbook->ISBN=tempN->ISBN;
            Lbook->Title=tempN->Title;
            Lbook->Author=tempN->Author;
            Lbook->Publisher=tempN->Publisher;
            Lbook->Publsihing_date=tempN->Publsihing_date;
            Lbook->Number_of_pages=tempN->Number_of_pages;
            Lbook->Total_quantity=tempN->Total_quantity;

            if(sorted==NULL)
                sorted=Lbook;
            else{
                Book *temps=sorted;
            while(temps->next!=NULL)
                temps=temps->next;
            Lbook->next=NULL;
            temps->next=Lbook;
            Lbook->prev=temps;

            }
        }else
		{
			while(tempN!=NULL && tempN->Title!=ar[i])
            tempN=tempN->next;

            Book *Lbook = new Book;
            Lbook->ISBN=tempN->ISBN;
            Lbook->Title=tempN->Title;
            Lbook->Author=tempN->Author;
            Lbook->Publisher=tempN->Publisher;
            Lbook->Publsihing_date=tempN->Publsihing_date;
            Lbook->Number_of_pages=tempN->Number_of_pages;
            Lbook->Total_quantity=tempN->Total_quantity;

            if(sorted==NULL)
                sorted=Lbook;
            else{
                Book *temps=sorted;
            while(temps->next!=NULL)
                temps=temps->next;
            Lbook->next=NULL;
            temps->next=Lbook;
            Lbook->prev=temps;

            }
		}

    }

head=sorted;

}

void sort_byISBN()
{
    Book *sorted=NULL;
    int ar[book_num];
    int n=0;
    if (head==NULL)
        cout<<"empty list";
    else
    {
        Book* temp=head;
        while(temp->next!=NULL)
        {
            ar[n]=temp->ISBN;
            n++;
            temp=temp->next;
        }
        ar[n]=temp->ISBN;
    }
    sort(ar,ar+n+1);
    for (int i=0;i<=n;i++)
    {

		Book *tempN=head;
		if(tempN->ISBN==ar[i])
        {
            Book *Lbook = new Book;
            Lbook->ISBN=tempN->ISBN;
            Lbook->Title=tempN->Title;
            Lbook->Author=tempN->Author;
            Lbook->Publisher=tempN->Publisher;
            Lbook->Publsihing_date=tempN->Publsihing_date;
            Lbook->Number_of_pages=tempN->Number_of_pages;
            Lbook->Total_quantity=tempN->Total_quantity;

            if(sorted==NULL)
                sorted=Lbook;
            else{
                Book *temps=sorted;
            while(temps->next!=NULL)
                temps=temps->next;
            Lbook->next=NULL;
            temps->next=Lbook;
            Lbook->prev=temps;

            }
        }else
		{
			while(tempN!=NULL && tempN->ISBN!=ar[i])
            tempN=tempN->next;

            Book *Lbook = new Book;
            Lbook->ISBN=tempN->ISBN;
            Lbook->Title=tempN->Title;
            Lbook->Author=tempN->Author;
            Lbook->Publisher=tempN->Publisher;
            Lbook->Publsihing_date=tempN->Publsihing_date;
            Lbook->Number_of_pages=tempN->Number_of_pages;
            Lbook->Total_quantity=tempN->Total_quantity;

            if(sorted==NULL)
                sorted=Lbook;
            else{
                Book *temps=sorted;
            while(temps->next!=NULL)
                temps=temps->next;
            Lbook->next=NULL;
            temps->next=Lbook;
            Lbook->prev=temps;

            }
		}

    }

head=sorted;

}

int main()
{
    cout << "\n\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t@@@@ -------> WELCOME to: <------- @@@@";
		cout << "\n\t\t@@@@-> ASTU  Library Management System <-@@@@";
		cout << "\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << "\n\n";





    bool flag=false;
    while (true)
    {
        if (flag)
            break;
        int n;
        cout<<"\n------------------------------";
        cout<<"\n1 to insert Book\n2 to update Book\n3 to search for a Book\n4 to delete a Book \n5 to display Records\n6 to sort the Records\n7 to quit";
        cout<<"\n------------------------------\nchoice:";
        cin>>n;
        switch(n)
        {
        case 1:
            insert_book_end();
            cout<<"The book inserted successfully";

            break;
        case 2:
            int s;
            cout<<"enter ISBN to be updated: ";
            cin>>s;
            update_(s);
            cout<<"the book updated successfully";
            break;
        case 3:
            int cho;

            cout<<"To search by ISBN 1\n to search by title 2\n-> ";
            cin>>cho;
            if(cho==1)
            {
                long long x;
                cout<<"Enter ISBN to search for: ";
                cin>>x;
                search_by_isbn(x);

            }else if(cho==2)
            {
                string y;
                cout<<"Enter Title : ";
                cin>>y;
                search_by_title(y);
            }
            break;
        case 4:
            long long q;
            cout<<"enter ISBN to be deleted: ";
            cin>>q;
            delete_(q);
            cout<<"the book deleted successfuly";
            break;
        case 5:
            display();
            break;
        case 6:
            int cho2;
            cout<<"To sort by ISBN 1\n to sort by title 2\n-> ";
            cin>>cho2;
            if(cho2==1)
            {
                cout<<"sort by ISBN";
                sort_byISBN();

            }else if(cho2==2)
            {
                cout<<"sort by title";
                sort_byTitle();
            }
            break;
        case 7:
            flag=true;
            break;
        default:
            cout<<"Incorrect input.Try again!\n";
            break;

        }
    }



}
