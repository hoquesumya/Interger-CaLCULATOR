#include "Largeint.h"
//#include "DList.h"
#include <string>
using namespace std;
#include <sstream>

Largeint::Largeint(){
  overflow=0;
  
  //is_neg=false;
  
}

istream & operator>>(istream &in, Largeint &other){
  string number;
  in>>number;
  int item;
  string neg;
  
  
    bool is_neg=false;
  for(int i=0;i<number.length();i++){
    if(number[i]=='-'){
      is_neg=true;
      i++;
    }
    
    item=number[i]-'0';
    
     if(is_neg&&i==(number.length()-1)){
       
      
        item=item*(-1);
      
     
    }
    
    other.db.insertItem_front(item);
  }
  
  auto m=other.db.begin();
  if(is_neg&&*m==0){
    int n=*m;
    other.db.deleteItem(*m);
    //cout<<"Now"<<*m;
    m=other.db.begin();
     int temp=*m;
    // cout<<"Now"<<*m<<endl;
     other.db.deleteItem(*m);
     temp=temp*(-1);
     other.db.insertItem_front(temp);
     other.db.insertItem_front(n);

    


  }

  return in;
}


ostream  & operator<<(ostream & out, Largeint &other){
    for(auto i=other.db.begin();i!=other.db.endofList();i++){
      out<<*i<<" ";
    }
    return out;
}
//staring of the function of addition//
Largeint Largeint::operator+( Largeint &obj){
  Largeint sum;
  int item=0;
  int overflow=0;
  auto iter=db.begin();
  auto i=obj.db.begin();
  int temp;
  bool is_neg=false;
  bool is_other_neg=false;
  bool zero_neg=false;
  bool zero_neg_first=false;
  bool is_both_neg=false;
  bool zero_both_neg=false;
  bool one_side_zero=false;

  int len= obj.db.getlength();

  int len2=db.getlength();
  int sumsml;

  int sumlength;
  if(len>len2){
    sumlength=len;
    sumsml=len2;
  }
  else {
    sumlength=len2;
    sumsml=len;
  }

 
  if((*iter<0&&*i>0)){
    int m;
    m=*iter;
    db.deleteItem(*iter);
    m=m*(-1);
    db.insertItem_front(m);
    
    is_neg=true;
    sum=*this-obj;
  }
  
   else if((*iter>0&&*i<0)){
    // cout<<*i;
    int m;
    m=*i;
    obj.db.deleteItem(*i);
    m=m*(-1);
    obj.db.insertItem_front(m);
   // cout<<*i;
    
    is_other_neg=true;
    sum=*this-obj;
  }
  else if(*iter<0&&*i<0){
     int m,n;
    m=*i;
    //cout<<*i<<endl;
    obj.db.deleteItem(*i);
   // cout<<*i<<endl;
    m=m*(-1);
    obj.db.insertItem_front(m);

  //for first
    n=*iter;
   
     db.deleteItem(*iter);
    n=n*(-1);
   // cout<<*iter;
    db.insertItem_front(n);


    is_both_neg=true;
    

  }
  else{
    if(*i==0||*iter==0){
      
      //checking numbers like -90-11//
      if(*i<0&&*iter==0){
        iter++;
        if(*iter<0){
         iter--;
        int m=*iter;
        //cout<<m<<endl;
        db.deleteItem(*iter);
        iter=db.begin();
        int n=*iter;
        //cout<<n<<endl;
        db.deleteItem(*iter);
        n=n*(-1);
        db.insertItem_front(n);
        db.insertItem_front(m);
        //zero_neg_first=true;
        iter=db.begin();
        
        //for the second part
        int r;
       r=*i;
        obj.db.deleteItem(*i);
        r=r*(-1);
      obj.db.insertItem_front(r);


        //for the second part
       
        one_side_zero=true;
        //cout<<*i;
        
      }
      }
      else if(*i==0&&*iter<0){
        
        if(obj.db.getlength()!=1){

        i++;
        

        if(*i<0){
        i--;
        int m=*i;
        //cout<<m<<endl;
        obj.db.deleteItem(*i);
        i=obj.db.begin();
        int n=*i;
        //cout<<n<<endl;
        obj.db.deleteItem(*i);
        n=n*(-1);
        obj.db.insertItem_front(n);
        obj.db.insertItem_front(m);
        
        i=obj.db.begin();

         int r;
    r=*iter;
    db.deleteItem(*iter);
    r=r*(-1);
    db.insertItem_front(r);
    
        one_side_zero=true;

        }

      }
      }
      else{
      if(obj.db.getlength()!=1&&db.getlength()!=1){
      i++;
      iter++;
      if(*i<0 &&*iter>0){
        i--;
        int m=*i;
        //cout<<m<<endl;
        obj.db.deleteItem(*i);
        i=obj.db.begin();
        int n=*i;
        //cout<<n<<endl;
        obj.db.deleteItem(*i);
        n=n*(-1);
        obj.db.insertItem_front(n);
        obj.db.insertItem_front(m);
        zero_neg=true;
        i=obj.db.begin();
        //cout<<*i;
        sum=*this-obj;
       

      }
 
      else if(*iter<0 && *i>0){
         iter--;
        int m=*iter;
        //cout<<m<<endl;
        db.deleteItem(*iter);
        iter=db.begin();
        int n=*iter;
        //cout<<n<<endl;
        db.deleteItem(*iter);
        n=n*(-1);
        db.insertItem_front(n);
        db.insertItem_front(m);
        zero_neg_first=true;
        iter=db.begin();
        //cout<<*i;
        sum=*this-obj;
      }

      else if(*iter<0 && *i<0){
          i--;
        int m=*i;
        //cout<<m<<endl;
        obj.db.deleteItem(*i);
        i=obj.db.begin();
        int n=*i;
        //cout<<n<<endl;
        obj.db.deleteItem(*i);
        n=n*(-1);
        obj.db.insertItem_front(n);
        obj.db.insertItem_front(m);
         i=obj.db.begin();
        


        iter--;
        int a=*iter;
        //cout<<m<<endl;
        db.deleteItem(*iter);
        iter=db.begin();
        int b=*iter;
        //cout<<n<<endl;
        db.deleteItem(*iter);
        b=b*(-1);
        db.insertItem_front(b);
        db.insertItem_front(a);
       zero_both_neg=true;
        iter=db.begin();
   

      }
      }
      }
      if(zero_neg==false&&!zero_neg_first&&!zero_both_neg&&!one_side_zero){
        i=obj.db.begin();
        iter=db.begin();
      }
    }
  }
  
  for(int in=0; in<sumlength;in++){
    if(!is_neg&&!is_other_neg&&!zero_neg&&!zero_neg_first){
    if(in<sumsml){
      item=*iter+*i+overflow;
      

      if(i!=obj.db.endofList())
        i++;
      if(iter!=this->db.endofList()){
        iter++;
      }
    }
    

    else{
        if(sumlength==len2){
          item=overflow+*iter;
        
          if(iter!=this->db.endofList()){
            iter++;
        }
        }

        else{
          item=overflow+*i;
          if(i!=obj.db.endofList()){
            i++;
        }

        }

      }
     

      if(item>9){
         temp=item%10;
        overflow=1;
        sum.db.insertItem_front(temp);
      }
    else {
      sum.db.insertItem_front( item);
      overflow=0;
    }

    
    }
  }
   if(overflow==1){
      sum.db.insertItem_front(1);
    }
    if(is_neg){
    auto n=sum.db.begin();
  
      n=sum.db.begin();
     int m=*n;
     sum.db.deleteItem(m);
     
     sum.db.insertItem_front( m *(-1));

    }

    if(is_both_neg||zero_both_neg||one_side_zero){
      auto n=sum.db.begin();
  
      n=sum.db.begin();
     int m=*n;
     sum.db.deleteItem(m);
     
     sum.db.insertItem_front( m *(-1));

    }
  
      
    return sum;
  }
//end of the funtion

  
//starting of the function//
Largeint operator-( Largeint a, Largeint b){
    Largeint neg;
    
    bool is_neg=false;
    bool is_neg_second=false;
    bool both_neg=false;


    int item=0;
  int overflow=0;
  auto iter=a.db.begin();
  auto i=b.db.begin();
  int temp;

  int len= b.db.getlength();

  int len2=a.db.getlength();
  int sumsml;


  auto newiter=a.db.end();
    auto newi=b.db.end();
    bool bigfirst=false;
    bool bigsecond=false;
    bool equalnum=false;


  int sumlength;
  if(len>len2){
    sumlength=len;
    sumsml=len2;
  }
  else {
    sumlength=len2;
    sumsml=len;
  }
  //Check negative num
  if(*iter<0&&*i>0){
    int m;
    m=*iter;
    a.db.deleteItem(*iter);
    m=m*(-1);
    a.db.insertItem_front(m);
    is_neg=true;
    neg=a+b;
  }
  else  if(*iter>0&&*i<0){
    int m;
    m=*i;
    b.db.deleteItem(*i);
    m=m*(-1);
    b.db.insertItem_front(m);
    is_neg_second=true;
    neg=a+b;
  }
  else if(*iter<0&&*i<0){
    int m;
    m=*iter;
    a.db.deleteItem(*iter);
    m=m*(-1);
    a.db.insertItem_front(m);
    


    int n;
    n=*i;
    b.db.deleteItem(*i);
    n=n*(-1);
    b.db.insertItem_front(n);
    both_neg=true;
   
  }
  for(int in=0;in<sumlength;in++){

    if(!is_neg && !is_neg_second){
    if(in<sumsml&&(a.db.getlength()>b.db.getlength())){

      if(*iter<*i){
        item=(*iter+10-overflow)-*i;
        overflow=1;
      }
      else {
          if(overflow==1){
            if(*iter-1<*i){
              item=(*iter+10-overflow)-*i;
               overflow=1;
            }
            else {
              item=(*iter-overflow)-*i;
              overflow=0;
            }
          }
          else {
            item=(*iter-overflow)-*i;
              overflow=0;
          }
      }
      if(i!=b.db.endofList())
        i++;
      if(iter!=a.db.endofList()){
        iter++;
    }
    
  }

   else if(in<sumsml&&(b.db.getlength()>a.db.getLength())){
      if(*i<*iter){
        item=(*i+10-overflow)-*iter;
        overflow=1;
      }
      else {
          if(overflow==1){
            if(*i-1<*iter){
              item=(*i+10-overflow)-*iter;
               overflow=1;
            }
            else{
              item=(*i-overflow)-*iter;
              overflow=0;
            }
          }
          else {
            item=(*i-overflow)-*iter;
              overflow=0;
          }
      }
      if(i!=b.db.endofList()){
        i++;
       }
      if(iter!=a.db.endofList()){
        iter++;
    }
  }

  
  else if(a.db.getlength()==b.db.getlength()){
    

    if(*newiter>*newi){
      bigfirst=true;
    }
    else if(*newiter<*newi){
      bigsecond=true;
    }

    else if(*newiter==*newi){
      

      while(newiter!=a.db.beginofList()&&newi!=b.db.beginofList()){
         if(*newiter>*newi){
           bigfirst=true;
           equalnum=false;
           break;
           
         }
         else if(*newiter<*newi){
           bigsecond=true;
           equalnum=false;
           break;
          
         }
         else{
            
            equalnum=true;
            
         }
         if(newiter!=a.db.begin()&&newi!=b.db.begin()){
         newiter--;
            newi--;
         }
         else 

          break;
      
      }
    }
         
      if(bigfirst==true){

        if(*iter<*i){
        item=(*iter+10-overflow)-*i;
        overflow=1;
      }
      else {
          if(overflow==1){
            if(*iter-1<*i){
              item=(*iter+10-overflow)-*i;
               overflow=1;
            }
            else {
              item=(*iter-overflow)-*i;
              overflow=0;
            }
          }
          else {
            item=(*iter-overflow)-*i;
              overflow=0;
          }
      }
      if(i!=b.db.endofList())
        i++;
      if(iter!=a.db.endofList()){
        iter++;
    }
      }

      else if(bigsecond==true){
        if(*i<*iter){
        item=(*i+10-overflow)-*iter;
        overflow=1;
      }
      else {
          if(overflow==1){
            if(*i-1<*iter){
              item=(*i+10-overflow)-*iter;
               overflow=1;
            }
            else{
              item=(*i-overflow)-*iter;
              overflow=0;
            }
          }
          else {
            item=(*i-overflow)-*iter;
              overflow=0;
          }
      }
      if(i!=b.db.endofList()){
        i++;
       }
      if(iter!=a.db.endofList()){
        iter++;
    }
      }
      else{
        item=(*i-overflow)-*iter;
              overflow=0;
        if(i!=b.db.endofList()){
        i++;
       }
      if(iter!=a.db.endofList()){
        iter++;
    }
      }
  


    }
  
  
  

  else{
    if(sumlength==len2){
      if(*iter<overflow){
        *iter+=10;
         item=*iter-overflow;
        overflow=1;
      }
      else{
        item=*iter-overflow;
         overflow=0;
      }
        
          if(iter!=a.db.endofList()){
            iter++;
    }
   
  }
  else{
    if(*i<overflow){
        *i+=10;
         item=*i-overflow;
        overflow=1;
      }
      else{
        item=*i-overflow;
         overflow=0;
      }
      if(i!=b.db.endofList()){
        i++;
      }
  }

  } 
  
     if((b.db.getLength()>a.db.getLength())&& (in==sumlength-1)){
       if(item==0){
         auto n=neg.db.begin();
         int m=*n;
         neg.db.deleteItem(m);
         item=m;
       }
       
        neg.db.insertItem_front( item *(-1));
      }

    else 
        neg.db.insertItem_front( item);
      
  }
  }
  
  auto n=neg.db.begin();
  if(is_neg){
      n=neg.db.begin();
     int m=*n;
     neg.db.deleteItem(m);
     neg.db.insertItem_front( m *(-1));
    }
    
  if(*n==0){
  for(int c=0;c<neg.db.getlength();c++){
    if(*n==0 &&(a.db.getLength()>b.db.getlength()||bigfirst)){
     neg.db.deleteItem(0);
     
    
    
    if(is_neg){
      n=neg.db.begin();
     int m=*n;
     neg.db.deleteItem(m);
     neg.db.insertItem_front( m *(-1));
    }
    if(*n!=0){
      break;
    }
    n++;
    }
    else if (*n==0 &&(b.db.getLength()>a.db.getlength()||bigsecond)){
      
     neg.db.deleteItem(0);
     n=neg.db.begin();
     int m=*n;
     neg.db.deleteItem(m);
     neg.db.insertItem_front( m *(-1));
     
     if(*n!=0){
      break;
    }
    n++;
    }
   
    else if(equalnum){
       neg.db.deleteItem(0);
     
    n++;
    }
  }
  }
  else if(bigsecond&&!both_neg){
     n=neg.db.begin();
     int m=*n;
     neg.db.deleteItem(m);
     neg.db.insertItem_front( m *(-1));
  }
  else if((a.db.getLength()>b.db.getLength())&&both_neg){
     n=neg.db.begin();
     int m=*n;
     neg.db.deleteItem(m);
     neg.db.insertItem_front( m *(-1));
  }
  else if((a.db.getLength()<b.db.getLength())&&both_neg){
     n=neg.db.begin();
     int m=*n;
     neg.db.deleteItem(m);
     neg.db.insertItem_front( m *(-1));
  }
  
  return neg;

}
/***************End of the function******///

bool Largeint::is_negative_this(){
  auto imp=db.begin();
  if(*imp>0){
    return true;
  }
  else 
    return false;
}


Largeint Largeint:: multiply(Largeint value, const int num){
  Largeint temp2;
    int carry = 0;
    
  
    for (auto i=value.db.begin();i!=value.db.endofList();i++)
    {
        int sum = num*(*i)+ carry;
        carry = sum / 10;
        sum %= 10;
        temp2.db.insertItem_front(sum);
    }
  
    if (carry>0)
    {
        temp2.db.insertItem_front(carry);
        carry=0;
    }
  
    return temp2;
}
//starting of the multiplication//
Largeint Largeint::operator*(Largeint &other){
   Largeint product,temp,length;
 
    int carry=0;
    int count = 0;
    int power = 0;
    for(auto iter=other.db.begin(); iter!=other.db.endofList();iter++){

        for(auto i=db.begin();i!=db.endofList();i++){
          int t;
          int sum = *iter*(*i)+ carry;
           carry = sum / 10;
          t=sum% 10;
        temp.db.insertItem_back(t);
        }
        if (carry>0)
      {
        temp.db.insertItem_back(carry);
        carry=0;
      }
      
        power = count;
        if (power > 0)
        {
            while (power != 0)
            {
                temp.db.insertItem_front(0);
                power--;
            }
        }
        
        count++;
      
        if (count == 1)
        {

            for(auto a=temp.db.begin();a!=temp.db.endofList();a++){
              product.db.insertItem_back(*a);
            }
            
        }
        else if(count==2)
        {    Largeint temp2;
            temp2 = product + temp;
            
            product.db.destroy();
            for(auto a=temp2.db.begin();a!=temp2.db.endofList();a++){
              product.db.insertItem_back(*a);
            }
           
            //product.db.printList();
            temp2.db.destroy();
            
          
        }
        else{
          
          for(auto b=product.db.begin();b!=product.db.endofList();b++){
            length.db.insertItem_back(*b);
          }
          product.db.destroy();
          
         for(auto m=length.db.begin();m!=length.db.endofList();m++){
           product.db.insertItem_front(*m);   
         }
        
         length.db.destroy();
        

        Largeint phi;
        phi=product+temp;
        product.db.destroy();

          for(auto a=phi.db.begin();a!=phi.db.endofList();a++){
              product.db.insertItem_back(*a);
            }

            phi.db.destroy();
         
        }
      
        temp.db.destroy();
    }
    return product;
    }
/*******End of the function********/
   
Largeint Largeint::operator/(Largeint other){
  Largeint result;
  bool bigfirst=false;
  bool bigsecond=false;
  bool equalnum=false;


  auto iter=db.begin();
  auto i=other.db.begin();
   if(db.getlength()<other.db.getlength()){
     result.db.insertItem_front(0);
   }
   else if(db.getlength()==1&&*iter==0){
     result.db.insertItem_front(0);
   }
   else if(other.db.getlength()==1&&*i==0){
     cout<<"Undefined"<<endl;
   }

   else if(db.getlength()==other.db.getlength()){
     auto newiter=db.end();
     auto newi=other.db. end();
      
    if(*newiter>*newi){
      bigfirst=true;
    }
    else if(*newiter<*newi){
      bigsecond=true;
    } 


    else if(*newiter==*newi){
      
      //newiter--;
      //newi--;

      while(newiter!=db.beginofList()&&newi!=other.db.beginofList()){
         if(*newiter>*newi){
           bigfirst=true;
           equalnum=false;
           break;
           
         }
         else if(*newiter<*newi){
           bigsecond=true;
           equalnum=false;
           break;
          
         }
         else{
            
            equalnum=true;
            bigfirst=false;
            bigsecond=false;
            //newiter--;
           // newi--;
         }
         if(newiter!=db.begin()&&newi!=other.db.begin()){
           newiter--;
            newi--;
         }
        else 

          break;
      
      }
   }

   if(bigsecond){
     
     result.db.insertItem_front(0);
   }
   else if(bigfirst){
    
     stringstream ss, dd;
     int arr[db.getlength()];
    

     int arr2[other.db.getlength()];
     long long int firstnum,secondnum;
     auto o=db.end();
     auto p=other.db.end();

     //string a;
    // string b;

     for(int m=0;m<db.getlength();m++){
        arr[m]=*o;
        if(o!=db.beginofList()){
          o--;
        }
     }
      for (unsigned n = 0; n < sizeof arr / sizeof arr [0]; ++n){
        ss << arr [n];
      }
      ss>>firstnum;
     cout<<firstnum<<endl;

      for(int m=0;m<other.db.getlength();m++){
        arr2[m]=*p;
        if(p!=other.db.beginofList()){
          p--;
        }
     }
      for (unsigned n = 0; n < sizeof arr / sizeof arr [0]; ++n){
        dd << arr2 [n];
      }
      dd>>secondnum;
      cout<<secondnum<<endl;

      for(int f=1;f<10;f++){
        if((secondnum*f)>firstnum){
          result.db.insertItem_front(f-1);
          break;
        }
      }
   }
   else if(equalnum){
     result.db.insertItem_front(1);
   }

   }
  
else if(db.getlength()>other.db.getlength()){
     Largeint temp;
     auto q=db.end();
     static int count=0;
     bool last=false;
     bool twice=false;
    
     
     
     while(q!=db.beginofList()){
       
       while(temp.db.getlength()!=other.db.getlength()){

         if(q==db.begin()){
           last=true;
         }
         temp.db.insertItem_back(*q);
         if(q!=db.begin()&&(temp.db.getlength()!=other.db.getlength())){
           q--;
           twice=true;
           
         }
    //else break;
       }
       count++;
       
       
       
      bool equal=false;

      auto m=temp.db.end();
      auto n=other.db.end();
      //int count=0;
      
      bool bigother=false;
      bool bigfirst1=false;
     int ar[temp.db.getlength()];
     int ar2[other.db.getLength()];
      long long int firstnum1,secondnum1;
     //auto a=temp.db.end();
     //auto b=other.db.end();
     auto a=temp.db.begin();
     auto b=other.db.end();

     stringstream ss1,dd1;
     

     //string a;
    // string b;

     for(int m=0;m<temp.db.getlength();m++){
        ar[m]=*a;
      /*  if(a!=db.beginofList()){
          a--;
        }*/
        if(a!=temp.db.endofList()){
          a++;
        }
     }
      for (unsigned n = 0; n < sizeof ar / sizeof ar [0]; ++n){
        ss1 << ar [n];
      }
      ss1>>firstnum1;

      

      for(int m=0;m<other.db.getlength();m++){
        ar2[m]=*b;
        /*if(b!=other.db.beginofList()){
          b--;
        }*/
        if(b!=other.db.beginofList()){
          b--;
        }
     }

       for (unsigned n = 0; n < sizeof ar2 / sizeof ar2 [0]; ++n){
        dd1 << ar2 [n];
      }
      dd1>>secondnum1;
    

      if(firstnum1>secondnum1){
        
        bigfirst1=true;
        
      }
      else if(firstnum1<secondnum1){
        
      
        bigother=true;
      
      }
      else if(firstnum1==secondnum1){
        equal=true;
        
      }

       // count=count+1;
       if(bigother){
        // cout<<"count is "<<count<<endl;
         if(count==1){
           q--;
            temp.db.insertItem_back(*q);
         }
    
        else if(!last&&q!=db.beginofList()){
          if(twice){
            q--;
            twice=false;
          }

             temp.db.insertItem_back(*q);
            
       }

      
        long long int difference;

        stringstream ss, dd;
        int arr[temp.db.getlength()];
     
    

     int arr2[other.db.getlength()];
     //cout<<temp.db.getlength()<<endl;
     long long int firstnum,secondnum;
     //auto o=temp.db.end();
     //auto p=other.db.end();

     auto o=temp.db.begin();
     auto p=other.db.end();

    
     
     for(int m=0;m<temp.db.getlength();m++){
        arr[m]=*o;
        if(o!=db.endofList()){
          o++;
        }
     }
      for (unsigned n = 0; n < sizeof arr / sizeof arr [0]; ++n){
        ss << arr [n];
      }
      ss>>firstnum;
    

      for(int m=0;m<other.db.getlength();m++){
       
        arr2[m]=*p;
      
       
           if(p!=db.beginofList()){
          p--;
        }
        
        
     }
      for (unsigned n = 0; n < sizeof arr2 / sizeof arr2 [0]; ++n){
        dd << arr2 [n];
      }
      dd>>secondnum;
     
      for(int f=0;f<20;f++){
       // cout<<secondnum*2;
        if((secondnum*f)>firstnum){
          
          result.db.insertItem_back(f-1);
          difference=firstnum-secondnum*(f-1);
          break;
        }
      }
     
      string change=to_string(difference);


      temp.db.destroy();
      for(int r=0;r<change.size();r++){
          int w=change[r]-'0';
          temp.db.insertItem_back(w);
      }
      if(q!=db.begin()){
       if(other.db.getlength()-temp.db.getlength()==2){
        result.db.insertItem_back(0);
       }
      }
      
        
      }
    else  if(equal==true){
        result.db.insertItem_front(1);
        temp.db.destroy();
        temp.db.insertItem_back(0);
      }
     
     
     else   if(bigfirst1){

        
        long long int difference;

        stringstream ss, dd;
        int arr[temp.db.getlength()];
    

        int arr2[other.db.getlength()];
        long long int firstnum,secondnum;
          auto o=temp.db.begin();
        auto p=other.db.end();


     

  for(int m=0;m<temp.db.getlength();m++){
        arr[m]=*o;
        if(o!=temp.db.endofList()){
          o++;
        }
  }
      for (unsigned n = 0; n < sizeof arr / sizeof arr [0]; ++n){
        ss << arr [n];
      }
      ss>>firstnum;
     

     


     
      for(int m=0;m<other.db.getlength();m++){
        arr2[m]=*p;
        if(p!=other.db.beginofList()){
          p--;
        }
     }
      for (unsigned n = 0; n < sizeof arr2 / sizeof arr2 [0]; ++n){
        dd << arr2 [n];
      }
      dd>>secondnum;
     

      for(int f=0;f<12;f++){
        if((secondnum*f)>firstnum){
          
          result.db.insertItem_back(f-1);
          difference=firstnum-secondnum*(f-1);
           
          break;
        }
      }
      
    string change=to_string(difference);


      temp.db.destroy();
      for(int r=0;r<change.size();r++){
          int w=change[r]-'0';
          temp.db.insertItem_back(w);
      }
      if(q!=db.begin()){
      if(other.db.getlength()-temp.db.getlength()==2){
        result.db.insertItem_back(0);
      }
      }
     //temp.db.insertItem_back(difference);

     
     
      }
      
      if(q==db.begin())
        break;
      
      else{ 
        q--;
        twice=false;
      }
      

     }
     
}

   return result;
}
/*********************************End of the function***************/

//this function will evaluate the remainder of two large numbers//
Largeint Largeint::operator%(Largeint other){
  Largeint result;
  Largeint temp;
  bool bigfirst=false;
  bool bigsecond=false;
  bool equalnum=false;


  auto iter=db.begin();
  auto i=other.db.begin();
   if(db.getlength()<other.db.getlength()){
     auto z=db.begin();
    // result.db.insertItem_front(0);
    while(z!=db.endofList()){
      temp.db.insertItem_front(*z);
      z++;
    }
    
     
   }
   else if(db.getlength()==1&&*iter==0){
     //result.db.insertItem_front(0);
     temp.db.insertItem_back(0);
   }
   else if(other.db.getlength()==1&&*i==0){
     cout<<"Undefined"<<endl;
     
   }

   else if(db.getlength()==other.db.getlength()){
     auto newiter=db.end();
     auto newi=other.db. end();
      
    if(*newiter>*newi){
      bigfirst=true;
    }
    else if(*newiter<*newi){
      bigsecond=true;
    } 


    else if(*newiter==*newi){

      while(newiter!=db.beginofList()&&newi!=other.db.beginofList()){
         if(*newiter>*newi){
           bigfirst=true;
           equalnum=false;
           break;
           
         }
         else if(*newiter<*newi){
           bigsecond=true;
           equalnum=false;
           break;
          
         }
         else{
            
            equalnum=true;
            bigfirst=false;
            bigsecond=false;
            
         }
         if(newiter!=db.begin()&&newi!=other.db.begin()){
           newiter--;
            newi--;
         }
        else 

          break;
      
      }
   }

   if(bigsecond){
       auto z=db.begin();
    // result.db.insertItem_front(0);
    while(z!=db.endofList()){
      temp.db.insertItem_front(*z);
      z++;
    }
    
     
     //result.db.insertItem_front(0);
   }
   else if(bigfirst){
    
     stringstream ss, dd;
     int arr[db.getlength()];
    

     int arr2[other.db.getlength()];
     long long int firstnum,secondnum;
     auto o=db.end();
     auto p=other.db.end();

     
     for(int m=0;m<db.getlength();m++){
        arr[m]=*o;
        if(o!=db.beginofList()){
          o--;
        }
     }
      for (unsigned n = 0; n < sizeof arr / sizeof arr [0]; ++n){
        ss << arr [n];
      }
      ss>>firstnum;
    

      for(int m=0;m<other.db.getlength();m++){
        arr2[m]=*p;
        if(p!=other.db.beginofList()){
          p--;
        }
     }
      for (unsigned n = 0; n < sizeof arr / sizeof arr [0]; ++n){
        dd << arr2 [n];
      }
      dd>>secondnum;
      
    int difference;
      for(int f=1;f<10;f++){
        if((secondnum*f)>firstnum){
        //  result.db.insertItem_front(f-1);
        difference=firstnum-(secondnum*(f-1));
          break;
        }
      }
      string change=to_string(difference);


     
      for(int r=0;r<change.size();r++){
          int w=change[r]-'0';
          temp.db.insertItem_back(w);
      }
   }
   else if(equalnum){
     //result.db.insertItem_front(1);
     temp.db.insertItem_front(0);
   }

   }
  
else if(db.getlength()>other.db.getlength()){
   
     auto q=db.end();
     static int count=0;
     bool last=false;
     bool twice=false;
    
     
     
     while(q!=db.beginofList()){
       
       while(temp.db.getlength()!=other.db.getlength()){

         if(q==db.begin()){
           last=true;
         }
         temp.db.insertItem_back(*q);
         if(q!=db.begin()&&(temp.db.getlength()!=other.db.getlength())){
           q--;
           twice=true;
           
         }
       }
       count++;
       
       
       
      bool equal=false;

      auto m=temp.db.end();
      auto n=other.db.end();
      
      
      bool bigother=false;
      bool bigfirst1=false;
     int ar[temp.db.getlength()];
     int ar2[other.db.getLength()];
      long long int firstnum1,secondnum1;
     
     auto a=temp.db.begin();
     auto b=other.db.end();

     stringstream ss1,dd1;
     

     for(int m=0;m<temp.db.getlength();m++){
        ar[m]=*a;
      
        if(a!=temp.db.endofList()){
          a++;
        }
     }
      for (unsigned n = 0; n < sizeof ar / sizeof ar [0]; ++n){
        ss1 << ar [n];
      }
      ss1>>firstnum1;
     

      for(int m=0;m<other.db.getlength();m++){
        ar2[m]=*b;
       
        if(b!=other.db.beginofList()){
          b--;
        }
     }

       for (unsigned n = 0; n < sizeof ar2 / sizeof ar2 [0]; ++n){
        dd1 << ar2 [n];
      }
      dd1>>secondnum1;
      

      if(firstnum1>secondnum1){
        
        bigfirst1=true;
        
      }
      else if(firstnum1<secondnum1){
        
      
        bigother=true;
      
      }
      else if(firstnum1==secondnum1){
        equal=true;
    
      }

    
       if(bigother){
        
         if(count==1){
           q--;
            temp.db.insertItem_back(*q);
         }
    
        else if(!last&&q!=db.beginofList()){
          if(twice){
            q--;
            twice=false;
          }

             temp.db.insertItem_back(*q);
            
       }

      
        long long int difference;

        stringstream ss, dd;
        int arr[temp.db.getlength()];
     
    

     int arr2[other.db.getlength()];
     
     long long int firstnum,secondnum;
     

     auto o=temp.db.begin();
     auto p=other.db.end();

    
     
     for(int m=0;m<temp.db.getlength();m++){
        arr[m]=*o;
        if(o!=db.endofList()){
          o++;
        }
     }
      for (unsigned n = 0; n < sizeof arr / sizeof arr [0]; ++n){
        ss << arr [n];
      }
      ss>>firstnum;
     

      for(int m=0;m<other.db.getlength();m++){
       
        arr2[m]=*p;
      
       
           if(p!=db.beginofList()){
          p--;
        }
        
        
     }
      for (unsigned n = 0; n < sizeof arr2 / sizeof arr2 [0]; ++n){
        dd << arr2 [n];
      }
      dd>>secondnum;

      for(int f=0;f<20;f++){
       
        if((secondnum*f)>firstnum){
        
          //result.db.insertItem_back(f-1);
          difference=firstnum-secondnum*(f-1);
          break;
        }
      }
     
      string change=to_string(difference);


      temp.db.destroy();
      for(int r=0;r<change.size();r++){
          int w=change[r]-'0';
          temp.db.insertItem_back(w);
      }
      if(q!=db.begin()){
       if(other.db.getlength()-temp.db.getlength()==2){
        result.db.insertItem_back(0);
       }
      }
      
    
        
      }
    else  if(equal==true){
        result.db.insertItem_front(1);
        temp.db.destroy();
        temp.db.insertItem_back(0);
      }
     
     
     else   if(bigfirst1){

        
        long long int difference;

        stringstream ss, dd;
        int arr[temp.db.getlength()];
    

        int arr2[other.db.getlength()];
        long long int firstnum,secondnum;
          auto o=temp.db.begin();
        auto p=other.db.end();


     

  for(int m=0;m<temp.db.getlength();m++){
        arr[m]=*o;
        if(o!=temp.db.endofList()){
          o++;
        }
  }
      for (unsigned n = 0; n < sizeof arr / sizeof arr [0]; ++n){
        ss << arr [n];
      }
      ss>>firstnum;
     

      for(int m=0;m<other.db.getlength();m++){
        arr2[m]=*p;
        if(p!=other.db.beginofList()){
          p--;
        }
     }
      for (unsigned n = 0; n < sizeof arr2 / sizeof arr2 [0]; ++n){
        dd << arr2 [n];
      }
      dd>>secondnum;
     

      for(int f=0;f<12;f++){
        if((secondnum*f)>firstnum){
          
          result.db.insertItem_back(f-1);
          difference=firstnum-secondnum*(f-1);
    
          break;
        }
      }
    
    string change=to_string(difference);


      temp.db.destroy();
      for(int r=0;r<change.size();r++){
          int w=change[r]-'0';
          temp.db.insertItem_back(w);
      }
      if(q!=db.begin()){
      if(other.db.getlength()-temp.db.getlength()==2){
        result.db.insertItem_back(0);
      }
      }
     
      }
      
      if(q==db.begin())
        break;
      
      else{ 
        q--;
        twice=false;
      }
      

     }
}

   return temp;

}






bool Largeint::operator>(Largeint other){
  if(db.getlength()<other.db.getlength()){
    return false;

  }
  else if(db.getlength()>other.db.getlength()){
    return true;
  }
  else {
   auto newiter=db.end();
    auto newi=other.db.end();
    while(newiter!=db.beginofList()&&newi!=other.db.beginofList()){
         if(*newiter>*newi){
           return true;
           
         }
         else if(*newiter<*newi){
           return false;
          
         }
         
         if(newiter!=db.begin()&&newi!=other.db.begin()){
         newiter--;
            newi--;
         }
         else 

          break;
      
      }
  }
  return false;
}

