#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <vector>
#include<bits/stdc++.h>
#include <set>



using namespace std;


///global variables
vector <int> score;
vector <string> randans;
vector <int> randansnum;
vector <string> rightans;
string name="USER",filename="exam_questions.txt";
deque <string> ques_view;
int my_choice,numofques=0,k=0,Q_numbers=4,ry=0;
bool load=1;


///functions
void ques_memo();
void welcome();
void add_menu();
void view_ques();
void del_ques(int del);
void add_ques();
bool fileopen();
void load_ques();
void cout_ques(int numg);
void answers();
void total_score();
void score_stat();
void randd();
void randansr(int rx);
void randansr1();
bool Right_ans(string cho_ans);





int main()
{
    if(load){
        ques_memo();
        load=0;
    }

    main:
    welcome();
    if(my_choice==1){
        system("CLS");
        add_menu();
    }
    else if(my_choice==2){
        system("CLS");
        cout<<"Enter your name please: ";
        cin>>name;
        cout << '\a';
        system("CLS");
        goto main ;
    }
    else if(my_choice==3){
        system("CLS");
        randd();

    }
    else if(my_choice==4){
        system("CLS");
        score_stat();
    }
    else if(my_choice==5){
        system("CLS");
        total_score();
    }
    else if(my_choice==6){
        //cout<<rightans[6]<<endl;
        //cout<<rightans[7]<<endl;
        cout << '\a';
        cout<<"Thanks for using our application. ... Good bye"<<endl;
    }
    else{
        system("CLS");
        cout<<" Please chose a number from 1 to 6 only.\n\n\a";
        goto main;
    }

    return 0;
}


void ques_memo(){
    fstream file;
    string fileout;
    file.open(filename.c_str());
    ///copy file to deque
    while(!file.eof()){
        getline(file,fileout);
        ques_view.push_back(fileout);
        if((numofques-1)%5==0){
            rightans.push_back(fileout);
        }
        numofques++;
    }
    file.close();
}
void welcome (){
    //system("CLS");
    cout<<" Welcome "<<name<<", please choose from the following options:"<<endl;
    cout<<"     [1] Go to administration menu"<<endl;
    cout<<"     [2] Update your name"<<endl;
    cout<<"     [3] Start a new quiz"<<endl;
    cout<<"     [4] Display your scores statistics"<<endl;
    cout<<"     [5] Display all your scores"<<endl;
    cout<<"     [6] Exit"<<endl;
    cout<<" My choice: ";
    m:
    cin>>my_choice;
    if(cin.fail()){
            cin.clear();
            cin.ignore();
            //system("CLS");
            cout<<" Please chose a number from 1 to 6 only.\n\n\a";
            cout<<" My choice: ";
            goto m;
        }
}
void add_menu(){
    //system("CLS");
    int menu_cho;
    cout<<" Welcome to the administration menu, please choose from the following options:\n";
    cout<<"     [1] View all questions\n";
    cout<<"     [2] Add new question\n";
    cout<<"     [3] Load questions from file\n";
    cout<<"     [4] Go back to main menu\n";
    cout<<" My choice: ";
    m1:
    cin>>menu_cho;
    if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<" Please chose a number from 1 to 4 only.\n\n\a";
            cout<<" My choice: ";
            goto m1;
        }
    if(menu_cho==1){view_ques();}
    else if(menu_cho==2){add_ques();}
    else if(menu_cho==3){load_ques();}
    else if(menu_cho==4){
            system("CLS");
            main();
    }
    else{
        cout<<" Please chose a number from 1 to 4 only.\n\n\a";
        add_menu();
    }
}
void del_ques(int del){
        del=((del-1)*5 );
        deque <string> :: iterator it;
        it=ques_view.begin()+del;
        for(int i=0;i<5;i++,it++){
            ques_view.erase(it);
        }
        system("CLS");
        main();
}
void view_ques(){
    system("CLS");
    int cont=0,qcont=1;
    bool a=1,b=0,c=0,d=0;

    cout<<" Number of questions available: "<<numofques/5<<"\n";
    cout<<" Questions list:\n";
    cout<<" -------------------\n";

    deque <string> :: iterator it;
    ///print deque
    for (it = ques_view.begin(); it != ques_view.end(); ++it,cont++){
        if(cont%5==0){
                cout<<" ["<<qcont<<"]"<< *it<<endl;
                qcont++;
        }
        else if(a){
            cout<<"       "<<"*[a]"<<*it<<"     ";
            a=0,b=1;
        }
        else if(b){
            cout<<"[b]"<<*it<<"     ";
            b=0,c=1;
        }
        else if(c){
            cout<<"[c]"<<*it<<"     ";
            c=0,d=1;
        }
        else if(d){
                cout<<"[d]"<<*it<<'\n'<<'\n';
                d=0,a=1;
        }
    }
    cout<<" \n----------------------------------------------------------------------------\n";
    cout<<"Press [d] and the question ID if you want to delete a question (Example: d 2)\n"
        <<"Press [b] if you want to go back to the main menu\n";
    cho:
    string chose;
    cin>>chose;

    if(chose=="b"){
            system("CLS");
            main();
    } ///back to main

    else if(chose=="d"){ ///delete question
        numofques-=5;
    deel:
        int delet;
    m3:
        cin>>delet;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<" Please chose a right number.\n\n\a";
            cout<<" Number of the question: ";
            goto m3;
        }
        if(delet<=(numofques/5)&&delet>0){
            del_ques(delet);
        }
        else{
            cout<<"Please enter a valid Number\n";
            goto deel;
        }
    }
    else{
        cout<<" Please chose b or d only.\n";
        goto cho;
    }


}
void add_ques(){
    system("CLS");
    string newq,moreq;
    cout<<"The questions on the file should be like this\n";
    cout<<"<q1_text>\n";
    cout<<"<q1_correct_choice>\n";
    cout<<"<q1_choice2>\n";
    cout<<"<q1_choice3>\n";
    cout<<"<q1_choice4>\n";
    cout<<"<q2_text>\n";
    cout<<"<q2_correct_choice>\n";
    cout<<"....\n";

    ques:
    //cin.ignore();
    //getline(cin,newq);
    cin.ignore();
    for(int i=0;i<5;i++){
        getline(cin,newq);
        ques_view.push_back(newq);
        if(i==1){
            rightans.push_back(newq);
        }
    }
    numofques+=5;
    cout<<"Do you want to add more Questions? y for yes n for no\n";
    m4:
    cin>>moreq;
        if(moreq=="y"){goto ques;}
        else if(moreq=="n"){
                system("CLS");
                main();}
        else{
            cout<<"Please chose only y for yes n for no\n";
            goto m4;
        }


}
bool fileopen(){
    fstream newfile;
    newfile.open(filename.c_str());
    if(newfile.fail()){
        return 0;}
    else{
        return 1;}
}
void load_ques(){
    system("CLS");
    reinput:
    cout<<"Enter the file name (file name.txt) for Example exam_questions.txt\n";
    cout<<"The questions on the file should be like this\n";
    cout<<"<q1_text>\n";
    cout<<"<q1_correct_choice>\n";
    cout<<"<q1_choice2>\n";
    cout<<"<q1_choice3>\n";
    cout<<"<q1_choice4>\n";
    cout<<"<q2_text>\n";
    cout<<"<q2_correct_choice>\n";
    cout<<"....\n";
    cin>>filename;
    if(fileopen()==1){
            ques_memo();}
    else{
        cout<<"Please Enter right name and type for the file.\n";
        goto reinput;
    }

    system("CLS");
    main();
}
void cout_ques(int numg){
        randansr1();
        //cout<<randansnum[0]<<"   "<<randansnum[1]<<"   "<<randansnum[2]<<"   "<<randansnum[3]<<endl;
        k++;
        //bool a1=0,b1=0,c1=0,d1=0,itt=1;
        numg=((numg-1)*5 );
        deque <string> :: iterator it;
        it=ques_view.begin()+numg;
        cout<<" "<<k<<" - "<<*it<<endl;
        cout<<"     [a]"<<*(it+randansnum[0])<<"     ";
        randans.push_back(*(it+randansnum[0]));
        cout<<"     [b]"<<*(it+randansnum[1])<<"     ";
        randans.push_back(*(it+randansnum[1]));
        cout<<"     [c]"<<*(it+randansnum[2])<<"     ";
        randans.push_back(*(it+randansnum[2]));
        cout<<"     [d]"<<*(it+randansnum[3])<<"\n"<<"\n";
        randans.push_back(*(it+randansnum[3]));
        randansnum.clear();
        randansnum[0]=0;
        randansnum[1]=0;
        randansnum[2]=0;
        randansnum[3]=0;
        ry=0;

}
void answers (){
    int Q_numbers=4,wrong=0,right = 0;
    string s,Q_answer;

    for (int i=1; i <= Q_numbers; i++)
    {
        cout << "Please enter your choice for the " << i << " question : ";
        cin >> Q_answer;
        while (Q_answer != "a" && Q_answer != "b" && Q_answer != "c" && Q_answer != "d")
        {
            cout << "Your choices are (a ,b ,c & d) there is no " << Q_answer << endl;
            cout << "Please enter your choice again : " ;
            cin >> Q_answer ;
        }
        if (Q_answer=="a"){
            if(Right_ans(randans[(i-1)*4])){
                right++;
            }
            else{
                wrong++;
            }
        }
        else if (Q_answer=="b"){
            if(Right_ans(randans[((i-1)*4)+1])){
                right++;
            }
            else{
                wrong++;
            }
        }
        else if (Q_answer=="c"){
            if(Right_ans(randans[((i-1)*4)+2])){
                right++;
            }
            else{
                wrong++;
            }
        }
        else if (Q_answer=="d"){
           if(Right_ans(randans[((i-1)*4)+3])){
                right++;
           }
           else{
                wrong++;
           }
        }

    }
    randans.clear();
    score.push_back(right);
    system("CLS");
    cout << "Your right answers are : " << right << endl << "Your wrong answers are : " << wrong << endl;
    cout << "Your score is : " << right << " / " << Q_numbers << endl;
    cout << "======================================================================================================" << endl << endl << endl;
    //string z;
    //cout << "To go to main please press any key & click enter. \n";
    //cin >> z;
    cout << '\a';
    main();

}
void total_score(){
    if(score.empty()){
        system("CLS");
        cout<<"You didn't join any quiz please join at least one before displaying your scores\n\n";
        main();
    }
    else{
    cout << "Your total score:\n";
    for (int i=0;i<score.size();i++){
        cout << "  Quiz " << i+1 << " - " << score[i] << " / " << Q_numbers << endl;
        cout << "        Your right answers are : " << score[i] <<endl;
        cout << "        Your wrong answers are : " << 4-score[i] <<endl;
    }

    string s;
    cout << "======================================================================================================" << endl << endl << endl;
    cout << "Press [b] if you want to go back to the main menu or [e] to exit\n";
    cout << "Your choice: ";
    cin >> s;
    while (s!="b" && s!="e")
    {
        cout << "Your selected choice is not exit. ... The choices are (b or e) only \n";
        cout << "Enter your choice again: ";
        cin >> s;
    }
    if (s=="b")
    {
        cout << '\a';
        system("CLS");
        main();
    }
    else if (s=="e")
    {
        cout << '\a';
        exit(0);
    }
  }
}
void score_stat(){
    if(score.empty()){
        system("CLS");
        cout<<" You didn't join any quiz please join at least one before displaying your scores\n\n";
        main();
    }
    else{
    int highest_score=0,lowest_score=4;
    float average_score=0;
    for (int i=0;i<score.size();i++)
    {
        average_score += score[i];
        if (score[i] > highest_score)
            highest_score = score[i];
        if (score[i] < lowest_score)
            lowest_score = score[i];
    }
    average_score /= score.size();
    cout << "Your score statistics:\n";
    cout << "\t - Number of Quizzes taken:  " << score.size() << endl;
    cout << "\t - Highest score: " << highest_score << " / " << Q_numbers << endl;
    cout << "\t - Lowest score: " << lowest_score << " / " << Q_numbers << endl;
    cout << "\t - Average score: " << average_score << " / " << Q_numbers << endl;
    string s;
    cout << "Press [b] if you want to go back to the main menu or [e] to exit\n";
    cout << "Your choice: ";
    cin >> s;
    while (s!="b" && s!="e")
    {
        cout << "Your selected choice is not exit. ... The choices are (b or e) only \n";
        cout << "Enter your choice again: ";
        cin >> s;
    }
    if (s=="b")
    {
        cout << '\a';
        system("CLS");
        main();
    }
    else if (s=="e")
    {
        cout << '\a';
        exit(0);
    }
  }
}
void randd(){
    set <int, greater <int> > sett;
    int x,y=0;

    if((numofques/5)<4){
        system("CLS");
        cout<<"Sorry you can't start a new quiz because the number of questions are less than 4.\n";
        cout<<"Please add more questions to start the quiz.\n";
        main();
    }
    else{
    int i=0;
	m10:
    srand(time(0));
    for(;i<=3;i++)
    {
        x=(rand()%(numofques/5))+1;
        sett.insert(x);
        //cout_ques(x);
    }
    if(sett.size()<4){
        i=3;
        goto m10;
    }
    else{
            set <int, greater <int> > ::iterator its;
        for(its=sett.begin();y<4;its++,y++){
            cout_ques(*its);

        }
        sett.clear();
        k=0;
        answers();
    }
        }

}
void randansr(int rx){
vector <int>::iterator iit;

    //cout<<"itp "<<*iit;
    int y;
    for(iit=randansnum.begin();iit!=randansnum.end()-1;iit++){
            //cout<<"iit= "<<*iit<<endl;
        y=*iit;
        if(y==rx){
            //randansnum.erase(iit);
            randansnum.pop_back();
            //cout<<*iit<<" "<<rx<<" erased \n";
            --ry;
            //--ry;
            break;
        }
      }
}
void randansr1(){
    int rrx;
    rrx=(rand()%4)+1;
    randansnum.push_back(rrx);
    //vector <int>::iterator it;
    srand(time(0));
    for(;ry<3;ry++){
            rrx=(rand()%4)+1;
            randansnum.push_back(rrx);
            randansr(rrx);
    }
}
bool Right_ans(string cho_ans){
    vector <string> ::iterator iit;
    iit=rightans.begin();
    for(int ii=0;ii<rightans.size();ii++,iit++){
        if(cho_ans==*iit){
            return 1;
        }
    }
    return 0;
}
