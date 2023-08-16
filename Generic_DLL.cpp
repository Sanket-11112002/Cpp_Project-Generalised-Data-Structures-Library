//////////////////////////////////////////////////////////////////
//
// Description   :  GENERIC DOUBLY LINEAR LINKED LIST USING C++
// Input         :  Char,Int
// Output        :  Char,Int
//
/////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
    struct node * prev;
};


//=========================================================================
//
//
// Class Name  :  DoublyLL
// Description :  This Class represents Generic Doubly linear linked list
//
//
//=========================================================================


template <class T>
class DoublyLL
{
    private :

        struct node<T> * Head;
        int iSize;

    public :

        DoublyLL();
        ~DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,T);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T);
        int Count();
        void Display();
};


//=========================================================================
//
//
// Class Name       :   DoublyLL
// Parameters       :   NONE
// Description      :   This Is Constructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================


template <class T>
DoublyLL<T> :: DoublyLL()
{
    cout << "\nInside Constructor \n";
    Head = NULL;
    iSize = 0;
}


//=========================================================================
//
//
// Class Name       :   DoublyLL
// Parameters       :   NONE
// Description      :   This Is Distructor Of Class DoublyLL
//
// Returns          :   NONE
//
//
//=========================================================================


template <class T>
DoublyLL<T> :: ~DoublyLL()
{
    cout << "\nInside Destructor \n";
    struct node <T> * temp = NULL;
    while(temp != NULL)
    {
        temp = Head;
        Head = Head -> next;
        delete temp;
    }
}


//=======================================================================================
//
//
// Function Name    :   InsertFirst()
// Parameters       :   Generic No
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList 
//
// Returns          :   NONE
//
//
//=======================================================================================


template <class T>
void DoublyLL<T> :: InsertFirst(T No)
{
    struct node<T> *newn = new struct node<T>;
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> next = Head;
        Head -> prev = newn;
        Head = newn;
    }
    iSize++;
}


//============================================================================
//
//
// Function Name    :   InsertLast()
// Parameters       :   Generic No 
// Description      :   InsertLast Function Add New Node At End Of LinkedList 
//
// Returns          :   NONE
//
//
//============================================================================


template <class T>
void DoublyLL<T> :: InsertLast(T No)
{
    struct node<T> *newn = new struct node<T>;
    struct node<T> *temp = Head;
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
    }
    iSize++;
}


//======================================================================================================
//
//
// Function Name    :   InsertAtPos()
// Parameters       :   Generic No, Generic Pos
// Description      :   Insert At Position Function Add New Node At Given Position In The LinkedList 
//
// Returns          :   NONE
//
//
//=======================================================================================================


template <class T>
void DoublyLL<T> :: InsertAtPos(T No, T Pos)
{
    struct node<T> *newn = new struct node<T>;
    struct node<T> *temp = Head;
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((Pos < 1) || (Pos > iSize + 1))
    {
        return;
    }

    if(Pos == 1)
    {
        InsertFirst(No);
    }
    else if(Pos == iSize + 1)
    {
        InsertLast(No);
    }

    else
    {
        for(int i = 1; i < Pos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;
        iSize++;
    } 

}


//================================================================================================
//
//
// Function Name    :   DeleteFirst()
// Parameters       :   None
// Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList 
//
// Returns          :   NONE
//
//
//================================================================================================


template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }

    else if(Head -> next == NULL)
    {
        delete Head;
        Head = NULL;
    }

    else
    {
        Head = Head -> next;
        delete(Head -> prev);
        Head -> prev = NULL;
        iSize--; 
    } 
} 


//=========================================================================================
//
//
// Function Name    :   DeleteLast()
// Parameters       :   None
// Description      :   DeleteLast Function Remove The Node At End Of The LinkedList 
//
// Returns          :   NONE
//
//
//==========================================================================================


template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct node<T> *temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Head -> next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete (temp -> next);
        temp -> next = NULL;
        iSize--;
    }
}


//==========================================================================================================
//
//
// Function Name    :   DeleteAtPos()
// Parameters       :   Generic Pos
// Description      :   Delete At Position Function Remove Existing Node At Any Position In The LinkedList 
//
// Returns          :   NONE
//
//
//==========================================================================================================


template <class T>
void DoublyLL<T> :: DeleteAtPos(T Pos)
{
    struct node<T> *temp = Head;

    if((Pos < 1) || (Pos > iSize))
    {
        return;
    }

    if(Pos == 1)
    {
        DeleteFirst();
    }

    else if(Pos == iSize)
    {
        DeleteLast();
    }

    else
    {
        for(int i = 1; i < Pos - 1; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete (temp -> next -> prev);
        temp -> next -> prev = temp;
        iSize--;
    }

}


//================================================================================================
//
//
// Function Name    :   Count()
// Parameters       :   None
// Description      :   Count Function Count Number Of Nodes In LinkedList 
//
// Returns          :   Generic iSize
//                  :   Return Number Of Nodes In LinkedList
//
//
//================================================================================================


template <class T>
int DoublyLL<T> :: Count()
{
    return iSize;
}


//============================================================================
//
//
// Function Name    :   Display()
// Parameters       :   None
// Description      :   Display Function Display The Nodes In LinkedList 
//
// Returns          :   NONE
//
//
//=============================================================================


template <class T>
void DoublyLL<T> :: Display()
{
    struct node<T> * temp = Head;
    while(temp != NULL)
    {
        cout << temp -> data << " ->\t";
        temp = temp -> next;
    }
    cout << "NULL\n";
}


//====================================================================================================
//
//
// Function Name   :   Entry Point Function
// Description     :   In STL There Is No Main But To Check All Functions I Create The Main Function
//
//
//====================================================================================================


int main()
{
    DoublyLL <char> obj;
    DoublyLL<int>*obj2 = new DoublyLL<int>();

    cout << "\n_______________________________________________________\n";
    cout << "\n-------------------------------------------------------\n";

    cout << "\nAdding Node At First Position : \n";
    obj.InsertFirst('B');
    obj.InsertFirst('A');
    obj.Display();
    cout << "\nLength Of Linked List is : " << obj.Count() << "\n";

    cout << "\nAdding Node At Last Position : \n";
    obj.InsertLast('D');
    obj.Display();
    cout << "\nLength Of Linked List is : " << obj.Count() << "\n";

    cout << "\nAdding Node At Given Position 3 : \n";
    obj.InsertAtPos('C', 3);
    obj.Display();
    cout << "\nLength Of Linked List is : " << obj.Count() << "\n";

    cout << "\n Removing First Node From Linkedlist : \n";
    obj.DeleteFirst();
    obj.Display();
    cout << "\nLength Of Linked List is : " << obj.Count() << "\n";

    cout << "\n Removing Last Node From Linkedlist : \n";
    obj.DeleteLast();
    obj.Display();
    cout << "\nLength Of Linked List is : " << obj.Count() << "\n";

    cout << "\nRemoving Node At Given Position 2 : \n";
    obj.DeleteAtPos(2);
    obj.Display();
    cout << "\nLength Of Linked List is : " << obj.Count() << "\n";
    cout << "\n_______________________________________________________\n";
    cout << "\n-------------------------------------------------------\n";

    cout << "\nAdding Node At First Position : \n";
    obj2 -> InsertFirst(20);
    obj2 -> InsertFirst(10);
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\nAdding Node At Last Position : \n";
    obj2 -> InsertLast(40);
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\nAdding Node At Given Position 3 : \n";
    obj2 -> InsertAtPos(30, 3);
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\n Removing First Node From Linkedlist : \n";
    obj2 -> DeleteFirst();
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\n Removing Last Node From Linkedlist : \n";
    obj2 -> DeleteLast();
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\nRemoving Node At Given Position 2 : \n";
    obj2 -> DeleteAtPos(2);
    obj2 -> Display();
    cout << "\nLength Of Linked List is : " << obj2 -> Count() << "\n";

    cout << "\n_______________________________________________________\n";
    cout << "\n-------------------------------------------------------\n";

    delete obj2;

    return 0;
}