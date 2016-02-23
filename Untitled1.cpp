#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<algorithm>
using namespace std;
struct word
{
    char word[20];
    char meaning[200];
    char example[200];
};
struct number
{
    long int a;
};
int*arr;
void add();
void test();
void create(int);
void permute(int);
int main()
{
    int choice=1;
    cout<<"\n                                Welcome back Yash.!";
    while(choice)
    {

        cout<<"\nEnter your choice :- ";
        cout<<"\n1.Add a word";
        cout<<"\n2.Take a quick test";
        cout<<"\n3.EXIT ";
        cin>>choice;
        system("cls");
        switch(choice)
        {
            case 1: add();
                    system("cls");
                    break;
            case 2: test();
                    system("cls");
                    break;
            default : cout<<"\nGood Bye Yash.!";
                      cout<<"\nHope you learned something new today :D\n\n\n";
                      return 0;

        }
    }
    return 0;
}
void add()
{
    ofstream f1;
    f1.open("word.txt",ios::app | ios::binary);
    cout<<"\nEnter word : ";
    word w1;
    getchar();
    gets(w1.word);
    cout<<"\nEnter Meaning : ";
    gets(w1.meaning);
    cout<<"\nEnter example : ";
    gets(w1.example);
    f1.write((char*)&w1,sizeof(w1));
    f1.close();

    ifstream f2;
    f2.open("number.txt", ios :: binary);
    if(!f2)
     {
         ofstream t1;
         t1.open("number.txt", ios::binary | ios :: app);
         number num;
         num.a=0;
         t1.write((char*)&num,sizeof(num));
         t1.close();
     }
    f2.close();

    ifstream f3;
    ofstream f4;
    f3.open("number.txt",ios::binary);
    number num;
    f3.read((char*)&num,sizeof(num));
    num.a=num.a+1;
    f4.open("temp.txt",ios::binary | ios::app);
    f4.write((char*)&num,sizeof(num));
    f3.close();
    f4.close();
    remove("number.txt");
    rename("temp.txt","number.txt");
}
void test()
{
    int unknown_count=0;
    ifstream f1;
    f1.open("number.txt",ios::binary);
    number num;
    f1.read((char*)&num,sizeof(num));
    create(num.a);
    f1.close();
    ifstream f2;
    word w1;
    getchar();
    system("cls");
    cout<<"Commencing Test....";
    cout<<"\nPRESS ENTER WHENEVER READY";
    getchar();
    system("cls");
    for(int apk=0;apk<num.a;apk++)
    {
        f2.open("word.txt", ios::binary);
        f2.seekg(arr[apk]*sizeof(word));
        f2.read((char*)&w1,sizeof(w1));
        cout<<"Word    : "<<w1.word;
        getchar();
        cout<<"Meaning : "<<w1.meaning;
        cout<<"\nExample : "<<w1.example;
        f2.close();
        int know;
        cout<<"\n(1/0)";
        cin>>know;
        if(!know)
        {
            ofstream f5;
            f5.open("unknown.txt",ios::binary | ios::app);
            f5.write((char*)&w1,sizeof(w1));
            f5.close();
            unknown_count++;
        }
        getchar();
        system("cls");
    }
    if(!unknown_count)
    {
        cout<<"\nExcellent Performance.!   "<<num.a<<"/"<<num.a;
        getchar();
        system("cls");
    }
    else
    {
        cout<<"\nYour Score : "<<num.a-unknown_count<<"/"<<num.a;
        int correct;
        cout<<"\nWould you like to take a test of words you got wrong?(1/0)";
        cin>>correct;
        getchar();
        system("cls");
        cout<<"Commencing Test....";
        cout<<"\nPRESS ENTER WHENEVER READY";
        getchar();
        system("cls");
        if(correct)
        {
             ifstream f6;
             f6.open("unknown.txt",ios::binary);
             word w3;
             getchar();
             while(unknown_count--)
             {

                f6.read((char*)&w3,sizeof(w3));
                cout<<"\nWord    : "<<w3.word;
                getchar();
                cout<<"Meaning : "<<w3.meaning;
                cout<<"\nExample : "<<w3.example;
                getchar();

             }
             f6.close();
        }
    }
    remove("unknown.txt");
}
void create(int num)
{
    arr=(int*)malloc(num*sizeof(int));
    for(int i=0;i<num;i++)
     arr[i]=i;
    permute(num);
}
void permute(int no)
{
    int pqr=rand()%30;
    pqr=pqr+20;
    int num=no*pqr;
    do
    {
     std::next_permutation(arr,arr+no);
    }while(num--);
}
