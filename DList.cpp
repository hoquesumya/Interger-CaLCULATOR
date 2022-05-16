#include "DList.h"

/***************************************************************/
/* Programmer: Sumya Hoque                                    */        
/* Date: March 2 , 2021                                    */        
/* Purpose:  generic unsorted doubly linked list class                  */
/*           implementation file including an iterator class                              */
/***************************************************************/

template <class T>
DList<T> :: DList()
{
   first = NULL;
   last=NULL;
  
}

template <class T>     
DList<T> :: ~DList()
{ 
   destroy();
}

template <class T>        
DList<T> :: DList ( const DList<T> & other)
{
   copy (other);
}

template <class T>        
const DList<T> & DList<T> :: operator= (const DList<T> & other)
{
   if ( this != &other )      
   {
      destroy();
      copy(other);
   }

   return *this;
}

template <class T>        
bool DList<T> :: isEmpty()
{
   return first == NULL;
}
//inserting items from the front//    
template <class T>        
void DList<T> :: insertItem_front(T item)
{
   node<T> *temp;
   temp = new node<T>;

   temp->info = item;

   if ( first == NULL )
   {  
      temp->back=NULL;
      temp->next = NULL;
      first = temp;
      last=first;
      
   }
   else
   {
     node<T> *p;
     p=first;
     
     temp->back=NULL;
     temp->next=p;
     p->back=temp;
     first=temp;
    }
   

}
//inserting item from the back of the list//
template<class T>
void DList<T>::insertItem_back(T item){
  
  node<T>*temp;

  temp=new node<T>;
  temp->info=item;
  temp->next = NULL;
  temp->back = NULL;
 //For empty list
  if(first==NULL){
    first=temp;
    last=temp;
  }
  else{
    
    node<T>*p=last;
    
    temp->next=p->next;
    temp->back=p;
    p->next=temp;
    last=temp;

  }
}
template<class T>
void DList< T>::intialize(){
  first=NULL;
  last=NULL;
   
}
      
/*template <class T>      
void DList<T> :: deleteItem(T item)
{
   if ( first == NULL )
      cout<<"ERROR - LIST IS EMPTY OR ITEM IS NOT IN THE LIST";
   else 
   {
      node<T> *p = first;

      if ( item == first->info )
      { 
         
         first = first->next;
          if(first==NULL)
         {
              last=NULL;
         }
         else{
        
          first->back=NULL;
         }
         
           delete p;
      }
      else
      {
        bool found=false;
        
        
        while ( p != NULL &&!found )
        {
           if(item==p->info) {
             found=true;
           }
           else{
           p = p->next;
           }
        }

        if ( p == NULL||item!=p->info)
           cout<<"ERROR - ITEM NOT IN THE LIST";
        else
        {
           p->back->next=p->next;
           if(p->next!=NULL){
           p->next->back=p->back;
           }
           if(p==last){
             last=last->back;
           }
          
           delete p; 
        }
      }   
   }   
}*/

template <class T>
void DList<T> :: destroy()
{
    node <T> *p;

    while ( first != NULL )
    {
       p = first;
       first = first->next;
       delete p;      
    }
    last=NULL;
   
}
template <class T>
void DList<T> :: copy ( const DList<T> & other )
{
   if ( other.first == NULL ){
      first = NULL;
      last=NULL;
   }

   else
   {  
      first = new node<T>;
      first->info = other.first->info;
      first->back=NULL;
      
      last=first;
      
      node<T> *p = other.first->next;
      node<T> *r=first;

      while ( p != NULL )
      {
         r->next = new node<T>;
         r->next->info = p->info;
         r->next->back=r;
         r = r->next;
         
         last=r;
         p=p->next;
      }
      r->next = NULL; 
    
   }   
}

template <class T>        
int DList<T> :: getLength()
{
   node<T> *p = first;
   int count = 0;
   
   while ( p != NULL )
      {
         count++;
         p = p->next;
      
      }
 
   return count;
}

template <class T>        
bool DList<T> :: searchItem (T item)
{
  node<T> *p = first;
  bool found=false;

 
  while ( p != NULL && !found )
  {
     if ( p->info == item )
        found=true;
     else
        p = p->next;   
  }
  
  return found;

} 

template <class T>        
void DList<T> :: printList()
{
   node<T> *p;

   p = first;
   
  
   while ( p != NULL )
   {
      cout<<p->info<<" ";
      p = p->next;
   }
   
  
}
template <class T>
void DList<T>:: printback(){
  
  node<T>*p;
  p=last;

  while(p!=NULL){
    cout<<p->info<<" ";
    p=p->back;
  }
}


//implementation of the iterator class//
/*template <class T>
class DList<T>::iterator{
  public:
  //constructor//
  iterator(node<T>*n){
    current=n;
  }
  //operator overloading++//
  iterator &operator++(int){
      current=current->next;
      return *this;
   }
   //operator overloading --//
  iterator &operator--(int){
     current=current->back;
     return *this;
   }
   //operator overloading  of the pointer derefernce//
  T & operator*(){
      return current->info;
  }
  //operator overloading !=//
  bool operator!=(const iterator &r){
    return this->current!=r.current;
  }
  private:
    node<T> *current;
    
};*/

template<class T>
typename DList<T>::iterator DList<T>::begin()const{
  return iterator(first);
}
//end of the list
template<class T>
typename DList<T>::iterator DList<T>::end()const{
  return iterator(last);
}
//end of the list that has NULL to check if the iterator is not same as this address//
template<class T>
typename DList<T>::iterator DList<T>::endofList()const{
  return iterator(last->next);
}
//this function send the Null address to the iterator constructor.//
template<class T>
typename DList<T>::iterator DList<T>::beginofList()const{
  return iterator(first->back);
}



template <class T>      
void DList<T> :: deleteItem(T item)
{
   if ( first == NULL )
      cout<<"ERROR - LIST IS EMPTY OR ITEM IS NOT IN THE LIST";
   else 
   {
      node<T> *p = first;
      node<T>*r=last;
      if ( item == first->info )
      { 
         
         first = first->next;
          if(first==NULL)
         {
              last=NULL;
         }
         else{
        
          first->back=NULL;
         }
         
           delete p;
      }
      
      else if(item==last->info){
        
        r->back->next=NULL;
        last=last->back;
        delete r;
      }
      else
      {
        bool found=false;
        
        
        while ( p !=r&&!found )
        {
           if(item==p->info) {
             found=true;
           }
           else{
           p = p->next;
           }
        }

        if ( p == r||item!=p->info)
           cout<<"ERROR - ITEM NOT IN THE LIST";
        else
        {
           p->back->next=p->next;
           p->next->back=p->back;
          
          
           delete p; 
        }
      }   
   }   
}

template <class T>      
int DList<T> :: getlength(){
  node<T> *p;

   p = first;
   int count=0;
   
  
   while ( p != NULL )
   {
      count++;
      p = p->next;
   }
   return count;

}





  
 



