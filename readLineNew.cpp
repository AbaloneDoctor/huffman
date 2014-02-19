#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

std::ifstream file("test.txt");


class charElement{
private:
  char value;
  int freq;
  int loc;
public:

  charElement *next;
  charElement(char value, int freq, int loc){
    this->value=value;
    this->freq=freq;
    this->loc=loc;
  }
  
  void incFreq(){
    freq++;
  }

  void setFreq(int q){
    freq=q; 
  }

  char returnValue(){
    return value;
  }
  
  int returnFreq(){
    return freq;
  }
  
  int returnLoc(){
    return loc;
  }
};



class headElement{
public:
  int count;
  charElement *headPtr;
};



/*
class HashTable {
private:
  charElement **table;
public:
  
  HashTable(int size) {
    int i=0;
    table = new charElement*[size];
    for(i=0; i < size; i++){
      table[i]= NULL;
      cout<<"writing table"<<endl;
    }

  }
  
    void insertList(charElement *head){
    charElement *temp = new charElement(0,0,0);
    temp=head;
    int count =0;
    int u=0;
    while(temp->next!=NULL){
      temp=temp->next;
      //cout<<"node: "<<temp->returnValue()<<" freq: "<<temp->returnFreq()<<endl;
      table[u]=new charElement(temp->returnValue(),temp->returnFreq(),0);
      
      cout<<table[u]->returnValue()<<endl;
      u++;
      count++;
    }
    //return count;
  }
  //}

  
};
*/

class charList{
  //private:
public:
  charElement *head;
  charElement *head2;
  charElement *headf;
  charElement *heada;
public:

  charList(){
    head=new charElement(0,0,0);
    head2=new charElement(0,0,0);
    headf=new charElement(0,0,0);
    heada=new charElement(0,0,0);


    
    }
  
  int find(char val){
    charElement* scanner = new charElement(0,0,0);
    scanner->next=head; //added ->next
    int x=0; //keeps track of which frequency
    while(scanner->next!=NULL){//removed ->next
      //cout<<"not yet"<<endl;

      scanner=scanner->next;
      if(val==scanner->returnValue()){
	//cout<<"freq is now: "<<scanner->returnFreq()<<endl;

	//cout<<"found"<<endl;
	scanner->incFreq();
	//cout<<"freq is now: "<<scanner->returnFreq()<<endl;
	x++; //shows that there is a repeat for current char
      }
      
      //scanner=scanner->next;

    }

    //if(x==0){ //no repeat for current char, new node on 2ndlist
    charElement* dupeCheck = new charElement(0,0,0);


    dupeCheck=head2;


    int multi=0;
    //cout<<"val is: "<<val<<endl;
    
    while(dupeCheck->next!=NULL){
      //cout<<"gets into dupe check loop"<<endl;
      dupeCheck=dupeCheck->next;
      
      if(dupeCheck->returnValue()==val){
	//dupeCheck=dupeCheck->next;
	//cout<<"checking head2 "<<dupeCheck->returnValue()<<endl;
	multi++;
      }
      
    }
    if(multi==0&&val!=0){ //replaced head2 with dupe
      if(val==' '){
      dupeCheck->next=new charElement(val,x,0);
      //cout<<"added charElement: "<<"sp"<<" "<<x<<endl;
      dupeCheck=dupeCheck->next;
      }
      
      else{
      dupeCheck->next=new charElement(val,x,0);
      dupeCheck->next->setFreq(x);
      //      cout<<"added charElement: "<<val<<" "<<x<<endl;
      
      // cout<<"node prop: "<<dupeCheck->next->returnValue()<<" "<<dupeCheck->next->returnFreq()<<endl;



      dupeCheck=dupeCheck->next;
 

  
      }
     

    }
    return 0;
  }
  //forms linked list of every first line char (no sorting)
  void formList(string line){
    int z=1;
    charElement* temp = new charElement(line[0],0,0);
    head->next=temp;
    while(z<line.size()+1)
    {

      temp->next= new charElement(line[z],0,0);
      //cout<<"new char element: "<<temp->returnValue()<<endl;
      temp=temp->next;
      z++;
    }
  }

  //forms second list with redundancy removed
  void formSecondList(){
    charElement* temps = new charElement(0,0,0);
    temps=head;
    //int count=0;
    while(temps->next!=NULL)
      {
	temps=temps->next;
	//cout<<"temps returnvalue: "<<temps->returnValue()<<endl;
	find(temps->returnValue());
	//	count++;
      }
    //return count;
  }
  
  //prints out list
  int returnList(charElement *head){
    charElement *temp = new charElement(0,0,0);
    temp=head;
    int count =0;
    while(temp->next!=NULL){
      temp=temp->next;
      // cout<<"node: "<<temp->returnValue()<<" freq: "<<temp->returnFreq()<<endl;
      count++;
    }
    return count;
  }

  /*
  int sortedFreqList(){
    charElement *freqCheck = new charElement(0,0,0);
    charElement *head2Check = new charElement(0,0,0);
    head2Check=headf;
    freqCheck=head2;
    cout<<"freqCheck next value: "<<freqCheck->next->returnValue()<<endl;
    //headf->next=NULL;
    while(freqCheck->next!=NULL){
      freqCheck=freqCheck->next;
      if(headf->next==0){ //inserts first node into headf list
	headf->next=freqCheck;
	char a=freqCheck->returnValue();
	int b=freqCheck->returnFreq();
	head2Check->next= new charElement(a,b, 0);
	head2Check->next->next=new charElement(0,0,1);
	//head2Check=headf->next;
	cout<<"first headf info: "<<headf->next->returnValue()<<" "<<headf->next->returnFreq()<<endl;
      }

      */

      /*
      else{
      if(freqCheck->returnValue()>=head2Check->returnFreq())
	head2Check->next=freqCheck;
      if(freqCheck->returnValue()<head2Check->returnFreq())
	headf->next=
	  }
      */
  /*
      cout<<"finding seg fault"<<endl;
      head2Check=headf;
      int j=0;
      while(head2Check->next->returnLoc()!=1){

	cout<<"looping head2Check loop"<<endl;
	head2Check=head2Check->next;
	if(freqCheck->returnFreq()>=head2Check->returnFreq()&&j==0){
	  head2Check->next= new charElement(freqCheck->returnValue(),freqCheck->returnFreq(), 0);
	  cout<<"next head2Check element: "<<head2Check->next->returnValue()<<head2Check->next->returnFreq()<<endl;
	  j++;
	  // head2Check->
	}
      }
    }
  }



  
  */

};
class HashTable {
private:
  charElement **table;
  int s;
  std::vector <char> v;
  std::map<char,int> hash;

public:
  
  HashTable(int size) {
    int i=0;
    s=size;
    table = new charElement*[size];
    for(i=0; i < size; i++){
      //v[i]=0;
      table[i]= NULL;
      //    cout<<"writing table"<<endl;
    }

  }
  
    void insertList(charElement *head){
    charElement *temp = new charElement(0,0,0);
    temp=head;
    int count =0;
    int u=0;
    while(temp->next!=NULL){
      temp=temp->next;
      //cout<<"node: "<<temp->returnValue()<<" freq: "<<temp->returnFreq()<<endl;
      table[u]=new charElement(temp->returnValue(),temp->returnFreq(),0);
      
      //cout the table contents
      //cout<<table[u]->returnValue()<<" "<<table[u]->returnFreq()<<endl;

      u++;
      count++;
    }
    //return count;
  }
  
  
  void storeMap(){
    int m=0;
    while(m<(s)){
      hash[table[m]->returnValue()]=table[m]->returnFreq();
      m++;
    }
    //cout<<"table test"<<hash.size()<<endl; tests that the stored table exists
  }


  std::map<char,int> returnMap(){
    return hash;
  }

  charElement* returnTable(){
    return *table;
  }
  
  void sortList(){
    int m=0;
    charElement *temp = new charElement(0,0,0);
    int n=0;
    while(n<(s-1)){
      while(m<(s-1)){
	if(table[m]->returnFreq()>table[m+1]->returnFreq())
	  {
	    temp=table[m];
	    table[m]=table[m+1];
	    table[m+1]=temp;
	    {/*(
	      int a=table[m]->returnValue();
	      int b=table[m+1]->returnValue();
	      if(a<b){
		temp=table[m];
		table[m]=table[m+1];
		table[m+1]=temp;
		*/
	    }
	    
	  }
	
	if(table[m]->returnFreq()==table[m+1]->returnFreq())
	  {
	    //cout<<"enters loops"<<endl;
	    int a=table[m]->returnValue();
	    int b=table[m+1]->returnValue();
	    if(a>b){
	      temp=table[m];
	      table[m]=table[m+1];
	      table[m+1]=temp;
	    }
	  }
	  
	m++;
      }
      m=0;
      n++;
    }
  }
  
  void printList(){
    int n=0;
    for(n=0;n<s;n++){
      cout<<"table["<<n<<"] value: "<<table[n]->returnValue()<<" freq: "<<table[n]->returnFreq()<<endl;
    }
  }


  void storeVector(){
    int m=0;
    
    //cout<<"gets here"<<endl;
    while(m<(s)){
      v.push_back(table[m]->returnValue());
      //cout<<"vector "<<m<<" "<<v[m]<<endl;; //cout vector items
      m++;
    }
    
  }
  
  std::vector <char>  returnVector(){
    return v;
  }
  

  void testHReturn(std::map<char,int> table){
    std::map<char,int> blah=table;
    cout<<"blah.size(): "<<blah.size()<<endl;
  }

  void testVReturn(std::vector <char> s){
    cout<<"gets to testVreturn"<<endl;
    std::vector <char> y=s;
    cout<<"y[0] is "<<y[3]<<endl;
  }
  
  
  void testTReturn(charElement *table){
    cout<<"gets to testTreturn"<<endl;
    cout<<table->next->returnValue();
    charElement *mesa = table;
    cout<<"sets mesa to table"<<endl;
    //  cout<<mesa->next->returnValue();
    //cout<<"mesa value "<<mesa->returnValue()<<endl;;
  }


};

int main(){

  charList* list = new charList();
  std::string firstLine;
  std::getline(file, firstLine);
  list->formList(firstLine);
  list->formSecondList();
  HashTable* hashT= new HashTable(list->returnList(list->head2));
  hashT->insertList(list->head2);
  hashT->sortList();
  //hashT->printList(); prints current list
  hashT->storeVector();
  hashT->storeMap();
  //hashT->testHReturn(hashT->returnMap());  //tests return functions
  //hashT->testVReturn(hashT->returnVector());
  return 0;
};
