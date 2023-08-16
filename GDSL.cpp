//This Program Contains Gneric Code for all types of linked list as 
/////////////
// 1. singly linear linked list
// 2. singly circular linked list
// 3. doubly linked list
// 4. doubly circular linked list
/////////////

#include<string.h>
#include<iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

//
// NEW DATA TYPES
//

typedef int BOOL;            // type defination it gives more clearity, use of my new datatype BOOL.
typedef unsigned char BYTE; // it is use to access raw memory occupied by other objects (object representation).

//
// THIS IS GENERIC LINKED LIST OF TYPE T
//

template <typename T> // we create a single function or a class to work with different data types using template<T>.
struct GEN_LIST // struct data type i used to group items of possibly different types into a single(GEN_LIST).
{
    T       Data;
    GEN_LIST*pNext;
};

//
// THIS IS GENERIC Doubly linkedList OF TYPE T
//

template <typename T>
struct GEN_DLIST // for Doubly_linkedList we use (GEN_DLIST).
{
    T     Data;
    GEN_DLIST *pNext,*pPrev;
};

//////////////////////////////////////////////////
//
// Class Name  :  Singly_Linked List
// Description : This Class represents singly linear linked list
//
//////////////////////////////////////////////////

template <class T>
class Singly_linkedList
{
    public:  // here we use public Access Specifier 
    GEN_LIST<T> *pHead; // pointing at start of linked List
    GEN_LIST<T> *pTail; // pointing at end of linked List

    Singly_linkedList();   // for constructor

    ~Singly_linkedList(); //  for distructor

    BOOL AddToGenListFirst(
                              T *pNodeData
                          );

    void DisplayGenList();

    BOOL AddToGenListLast(
                              T *pNodeData
                         );

    BOOL FreeGenList();

    int CountGenListNode();

    int SearchFirstOccurance(
                               T data
                            );

    int SearchAllOccurance(
                              T data
                          );

    BOOL InsertAtPosition(
                              int pos,
                              T* pNodeData
                         );

    BOOL DeleteFromGenListFirst();

    BOOL DeleteAtPosition(
                            int pos
                         );

    BOOL DeleteFromGenListLast();

    BOOL ReverseList();

};
//////////////////////////////////////////////////
//
// Class Name  :  Doubly_Linked List
// Description : This Class represents Doubly linear linked list
//
//////////////////////////////////////////////////

template <class T>
class Doubly_linkedList
{
    public:
    GEN_DLIST<T> *pHead; // pointing at start of linked List
    GEN_DLIST<T> *pTail; // pointing at end of linked List

    Doubly_linkedList(); // constructor

    ~Doubly_linkedList(); // distructor

    BOOL AddToGenListFirst(
                              T *pNodeData
                          );

    void DisplayGenList();

    BOOL AddToGenListLast(
                              T *pNodeData
                         );

    int CountGenListNode();

    BOOL FreeGenList();
    
    int SearchFirstOccurance(
                               T data
                            );

    int SearchAllOccurance(
                              T data
                          );

    BOOL InsertAtPosition(
                              int pos,
                              T *pNodeData
                         );

    BOOL DeleteFromGenListFirst();

    BOOL DeleteAtPosition(
                            int pos
                         );

    BOOL DeleteFromGenListLast();

    BOOL DisplayGenListReverse();

};

//////////////////////////////////////////////////
//
// Class Name  :  Singly_LinkedList_Circular
// Description : This Class represents Singly Circular linked list
//
//////////////////////////////////////////////////

template <class T>
class Singly_linkedList_Circular
{
    public:
    GEN_LIST<T> *pHead; // pointing at start of linked List
    GEN_LIST<T> *pTail; // pointing at end of linked List

    Singly_linkedList_Circular(); 

    ~Singly_linkedList_Circular();

    BOOL AddToGenListFirst(
                              T *pNodeData
                          );

    void DisplayGenList();

    BOOL AddToGenListLast(
                              T *pNodeData
                         );

    BOOL FreeGenList();
    
    int CountGenListNode();

    int SearchFirstOccurance(
                               T data
                            );

    int SearchAllOccurance(
                              T data
                          );

    BOOL InsertAtPosition(
                              int pos,
                              T* pNodeData
                         );

    BOOL DeleteFromGenListFirst();

    BOOL DeleteAtPosition(
                            int pos
                         );

    BOOL DeleteFromGenListLast();

    BOOL ReverseList();

};

//////////////////////////////////////////////////
//
// Class Name  :  Doubly_LinkedList_Circular
// Description : This Class represents Doubly Circular linked list
//
//////////////////////////////////////////////////

template <class T>
class Doubly_linkedList_Circular
{
    public:
    GEN_DLIST<T> *pHead; // pointing at start of linked List
    GEN_DLIST<T> *pTail; // pointing at end of linked List

    Doubly_linkedList_Circular();

    ~Doubly_linkedList_Circular();

    BOOL AddToGenListFirst(
                              T *pNodeData
                          );

    void DisplayGenList();

    BOOL AddToGenListLast(
                              T *pNodeData
                         );

    int CountGenListNode();
    
    BOOL FreeGenList();
    
    int SearchFirstOccurance(
                               T data
                            );

    int SearchAllOccurance(
                               T data
                            );

    BOOL InsertAtPosition(
                              int pos,
                              T* pNodeData
                         );

    BOOL DeleteFromGenListFirst();

    BOOL DeleteAtPosition(
                            int pos
                         );

    BOOL DeleteFromGenListLast();

    BOOL DisplayGenListReverse();

};
////////////////////////////////////////////////////////////
//
//
// Function Name    :   Singly_linkedList
// Parameters       :   NONE
// Description      :   
//                      This Is Constructor Of Class Singly_linkedList.
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////
template <typename T>
Singly_linkedList<T>::Singly_linkedList()
{
    pHead = NULL;
    pTail = NULL;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   ~Singly_linkedList
// Parameters       :   NONE
// Description      :   
//                      This Is Distructor Of Class Singly_linkedList.
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

template <typename T>
Singly_linkedList<T>::~Singly_linkedList()
{
    GEN_LIST<T> *pTemp;
    GEN_LIST<T> *pNavigate;

    if(NULL != pHead)
    {
        pNavigate = pHead;
        while(NULL != pNavigate)
        {
            pTemp = pNavigate->pNext;
            free(pNavigate);
            pNavigate = pTemp;
        }
    }
}
////////////////////////////////////////////////////////////
//
//
// Function Name   :  AddToGenListFirst
// Parameters      :  
// 
//                     [IN]T *pNodeData.
//                      Holds the entry which is to be added.
//
// Description     :  
//                   This Function Adds Node To Singly Linear Linked List.
//                   
// Returns         :  
//                     BOOLEAN
//                    if the function succeds, the return value is TRUE.
//                    if the function fails, the returns value is FALSE.
//
// 
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList<T>::AddToGenListFirst(
                                           T *pNodeData
                                       )
{
    GEN_LIST<T> *pNewNode;

    if (NULL == pNodeData)
    {
        return FALSE;
    }

//
// Allocate new node
//

pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T>));
  if(NULL == pNewNode)
  {
      return FALSE;
  }

//
// Fill the node with data.
//

memset(pNewNode, 0, sizeof(GEN_LIST<T>));   
pNewNode->pNext = NULL;
pNewNode->Data = *pNodeData;

//
// Prepend
//

 if (NULL == pHead)
 {
     pHead = pNewNode;
     pTail = pNewNode;
 }
 else
  {
     pNewNode-> pNext = pHead;
     pHead = pNewNode;
  }

 return TRUE;
}

/////////////////////////////////////////////////////////////////////////
//
//
// Function Name   :  DisplayGenList
// Parameters      :
//                    NONE
// Description     :
//                    This function display singly linear linked list
//
// Returns         :
//                    void
//
//
/////////////////////////////////////////////////////////////////////////

template <typename T>
void
Singly_linkedList<T>::DisplayGenList()
{
    GEN_LIST<T> *pTempNode;
    pTempNode = pHead;

    while(NULL != pTempNode)
    {
        cout<<pTempNode-> Data<<"->";
        pTempNode = pTempNode-> pNext;
    }
}

/////////////////////////////////////////////////////////////////////////
//
//
// Function Name   :  AddToGenListLast
// Parameters      :
//
//                   [IN] GEN_LIST<T>**ppListToBeAppended.
//                   List which is to be appended to an existing list.
//
// Description     :
//                    This function appends node in singly linear linked list
//
// Returns         :
//                    BOOLEAN
//                    If the function succeds, the return value is TRUE.
//                    If the function fails, the return value is FALSE.
//
//
/////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList<T>::AddToGenListLast(
                                           T *pNodeData
                                       )
{
    GEN_LIST<T> *pNewNode;

    GEN_LIST<T> *pTempNode;
    pTempNode = pHead;

    if ( NULL == pNodeData )
    {
        return FALSE;
    }

//
// Allocate new node
//

pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T>));
  if(NULL == pNewNode)
  {
      return FALSE;
  }

//
// Fill the node with data.
//

memset(pNewNode, 0, sizeof(GEN_LIST<T>));   
pNewNode-> pNext = NULL;
pNewNode-> Data = *pNodeData;

//
// Append
//

 if (NULL == pHead)
 {
     pHead = pNewNode;
     pTail = pNewNode;
 }
 else
  {
     pTail->pNext = pNewNode;
     pTail = pNewNode;
  }

 return TRUE;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  FreeGenList
// Parameters      :  NONE
// Description     :  This function frees singly linear linked list
//                   
// Returns         :  
//                     BOOLEAN
//                    if the function succeds, the return value is TRUE.
//                    if the function fails, the returns value is FALSE.
//
// 
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList<T>::FreeGenList()
{
    GEN_LIST<T> *pTemp;
    GEN_LIST<T> *pNavigate;

    if (NULL == pHead)
    {
        return FALSE;
    }

 pNavigate = pHead;
 while (NULL != pNavigate)
 {
     pTemp = pNavigate->pNext;
     free(pNavigate);
     pNavigate = pTemp;
 }

  return TRUE;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  CountGenListNode
// Parameters      :
//                    NONE
// Description     :
//                    This function counts nodes in singly linear linked list
//
// Returns         :
//                    int
//                    number of node in generic list
//
//
////////////////////////////////////////////////////////////

template <typename T>
int
Singly_linkedList<T>::CountGenListNode ()
{
    // variable for maintaning numbers of nodes
    int CountNode = 0;
    GEN_LIST<T> *pListHead = pHead;

    // Travers the linked list till end  
    while(NULL != pListHead)
    {
        CountNode++;
        pListHead = pListHead-> pNext;
    }
    return CountNode;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   SearchFirstOccurance
// Parameters      :
//
//                     [IN] GEN_LIST<T>Data.
//                     holds head data to be searched.
//
// Description     :
//                     this function search perticular data in singly linear linked list.
//                     and returns the position at which data is found.
//
// Returns         :
//                     int
//                     position at which data is found in generic list.
//
//
////////////////////////////////////////////////////////////

template <typename T>
int
Singly_linkedList<T>::SearchFirstOccurance(
                                               T data
                                           )
{
    int CountNode = 0;
    GEN_LIST<T> *pListHead = pHead;

    // Traverse the linked list till end
    while (pListHead != NULL)
    {
        ++CountNode;
        
        // If the matches with the input value
        if(memcmp(&(pListHead-> Data), &data, sizeof(data)) == 0)
        {
            // Break the loop as we get the first occurance
            return CountNode;
        } 
        pListHead = pListHead->pNext;
    }

 return -1;
}          

////////////////////////////////////////////////////////////
//
//
// Function Name   :  SearchAllOccurance
// Parameters      :
//
//                    [IN] GEN_LIST<T> data.
//                    Holds head data to be searched.
//
// Description     :
//                    This function search perticular data in Singly linear linked list.
//                    and return number of occurance of that data.
//
// Returns         :
//                    int
//                    number of times data is found in generic list.
//
//
////////////////////////////////////////////////////////////

template <typename T>
int
Singly_linkedList<T>::SearchAllOccurance(
                                             T data
                                         )


{
    int CountNode = 0;
    GEN_LIST<T> *pListHead = pHead;

    // Travers the linked list till end  
    while(pListHead != NULL)
    {
        // If the data matches with the input value 
        if(memcmp(&(pListHead-> Data), &data, sizeof(data) ) == 0)
        {
            ++CountNode;
        }
        pListHead = pListHead-> pNext;
    }
    
 return CountNode;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   InsertAtPosition
// Parameters      :
//
//                     [IN] int pos.
//                     Holds the position.
//
//                     [IN] T *pNodeData.
//                     Holds the entry which is to be added.
//
// Description     :
//                     this function adds node at specified position in singly linear linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList<T>::InsertAtPosition(
                                            int pos,
                                            T* pNodeData
                                       )
{
    int i = 1;

    GEN_LIST<T> *temp = NULL;
    GEN_LIST<T> *pNewNode = NULL;

    // If the linked list is empty
    if (pHead == NULL)
    {
        return FALSE;
    }

    else if(pos == 1)
    {
        AddToGenListFirst(pNodeData);
    }
    else if(pos == (CountGenListNode()) + 1)
    {
        AddToGenListLast(pNodeData);
    }
    else if((pos > CountGenListNode()))
    {
        return FALSE;
    }
    else
    {
       temp = pHead;
       pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T> ));
       if(NULL == pNewNode)
       {
           return FALSE;
       }

       //
       // Fill the node with Data
       //
       
       memset(pNewNode, 0, sizeof(GEN_LIST<T>));
       pNewNode-> pNext = NULL;
       pNewNode-> Data = *pNodeData;

       while(i < pos - 1)
       {
           temp = temp-> pNext;
           ++i;
       }
       pNewNode-> pNext = temp-> pNext;
       temp-> pNext = pNewNode;
    }
    
    return TRUE;
}               

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteFromGenListFirst
// Parameters      :   NONE
// Description     :
//                     this function removes first node from singly linear linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList<T>::DeleteFromGenListFirst()
{
    GEN_LIST <T> *temp;
    temp = pHead;

    // if linked list is empty
    if(pHead == NULL)
    {
        return FALSE;
    }
    else
    {
        pHead = temp-> pNext;
        free(temp);
    }
    return TRUE;    
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteFromGenListLast
// Parameters      :   NONE
//
// Description     :
//                     this function removes last node from singly linear linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL Singly_linkedList<T>::DeleteFromGenListLast()
{
    GEN_LIST<T> *temp1, *temp2;
    temp1 = temp2 = pHead;
    
    // If linked list is empty
    if(pHead == NULL)
    {
        return FALSE;
    } 
    else
    {
        while(temp1-> pNext != NULL)
        {
            temp2 = temp2-> pNext;
            temp1 = temp2-> pNext;
        }
        temp2-> pNext = NULL;
        free(temp1);
    }

    return TRUE;   
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteAtPosition
// Parameters      :   NONE
//                     [IN] int pos.
//                     Holds the position.
//
// Description     :
//                     this function delete node from  specified position in singly linear linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList<T>::DeleteAtPosition(
                                          int pos
                                       )
{
    if(pos > (CountGenListNode()))
    {
        return FALSE;
    }
    else if(pos == 1)
    {
        DeleteFromGenListFirst();
    }
    else if(pos == (CountGenListNode()))
    {
        DeleteFromGenListLast();
    }
    else
    {
       int i = 0;
       GEN_LIST<T> *temp = pHead, *t;

       for(i = 0; i < pos -1; i++)
       {
           t = temp;
           temp = temp-> pNext;
       }
       t-> pNext = temp-> pNext;
       temp-> pNext = NULL;
       free(temp);
    }

    return TRUE;   
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   ReverseList
// Parameters      :
//                    NONE
// Description     :
//                     this function reverse singly linear linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL Singly_linkedList<T>::ReverseList()
{
    GEN_LIST<T> *prev = NULL;
    GEN_LIST<T> *current = pHead;
    GEN_LIST<T> *next = NULL;

    // If the linked list is empty
    if(pHead == NULL)
    {
        return FALSE;
    }
    
    while(current != NULL)
    {
        next = current-> pNext;
        current-> pNext = prev;
        prev = current;
        current = next;
    }
    pHead = prev;

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//
//
// Function Name    :   Doubly_linkedList
// Parameters       :   NONE
// Description      :   
//                      This Is Constructor Of Class Doubly_linkedList.
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////
template <typename T>
Doubly_linkedList<T>::Doubly_linkedList()
{
    pHead = NULL;
    pTail = NULL;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   ~Doubly_linkedList
// Parameters       :   NONE
// Description      :   
//                      This Is Distructor Of Class Doubly_linkedList.
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////
template <typename T>
Doubly_linkedList<T>::~Doubly_linkedList ()
{
    GEN_DLIST<T> *pTemp;
    GEN_DLIST<T> *pNavigate;

    if(NULL != pHead)
    {
        pNavigate = pHead;
        while(NULL != pNavigate)
        {
            pTemp = pNavigate->pNext;
            free(pNavigate);
            pNavigate = pTemp;
        }
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  AddToGenListFirst
// Parameters      :  
// 
//                     [IN]T *pNodeData.
//                      Holds the entry which is to be added.
//
// Description     :  
//                   This Function Adds Node To Doubly Linear Linked List.
//                   
// Returns         :  
//                     BOOLEAN
//                    if the function succeds, the return value is TRUE.
//                    if the function fails, the returns value is FALSE.
//
// 
////////////////////////////////////////////////////////////
template <typename T>
BOOL
Doubly_linkedList<T>::AddToGenListFirst(
                                           T *pNodeData
                                       )
{
    GEN_DLIST<T> *pNewNode = NULL;

    if ( NULL == pNodeData )
    {
        return FALSE;
    }

//
// Allocate new node
//

pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T>));
  if(NULL == pNewNode)
  {
      return FALSE;
  }

//
// Fill the node with data.
//

memset(pNewNode, 0, sizeof(GEN_DLIST<T>));   
pNewNode-> pNext = NULL;
pNewNode-> Data = *pNodeData;
pNewNode-> pPrev = NULL;

//
// Prepend
//

 if (NULL == pHead)
 {
     pHead = pNewNode;
     pTail = pNewNode;
 }
 else
  {
     pNewNode-> pNext = pHead;
     (pHead)-> pPrev = pNewNode;
     pHead = pNewNode;
  }

 return TRUE;
}

/////////////////////////////////////////////////////////////////////////
//
//
// Function Name   :  AddToGenListLast
// Parameters      :
//
//                   [IN] GEN_DLIST<T> **ppListToBeAppended.
//                   List which is to be appended to an existing list.
//
// Description     :
//                    This function appends node in Doubly linear linked list
//
// Returns         :
//                    BOOLEAN
//                    If the function succeds, the return value is TRUE.
//                    If the function fails, the return value is FALSE.
//
//
/////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList<T>::AddToGenListLast(
                                           T *pNodeData
                                       )
{
    GEN_DLIST<T> *pNewNode = NULL;

    GEN_DLIST<T> *pTempNode = NULL;
    
    pTempNode = pHead;

    if ( NULL == pNodeData )
    {
        return FALSE;
    }

//
// Allocate new node
//

pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T>));
  if(NULL == pNewNode)
  {
      return FALSE;
  }

//
// Fill the node with data.
//

memset(pNewNode, 0, sizeof(GEN_DLIST<T>));   
pNewNode-> pNext = NULL;
pNewNode-> Data = *pNodeData;
pNewNode-> pPrev = NULL;
//
// Append
//

 if (NULL == pHead)
 {
     pHead = pNewNode;
     pTail = pNewNode;
 }
 else
  {
     pNewNode->pPrev = pTail;
     pTail->pNext = pNewNode;
     pTail = pNewNode;
  }

 return TRUE;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  FreeGenList
// Parameters      :  NONE
// Description     :  This function frees Doubly linear linked list
//                   
//
//
// Returns         :  
//                     BOOLEAN
//                    if the function succeds, the return value is TRUE.
//                    if the function fails, the returns value is FALSE.
//
// 
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList<T>::FreeGenList()
{
    GEN_DLIST<T> *pTemp;
    GEN_DLIST<T> *pNavigate;

    if (NULL == pHead)
    {
        return FALSE;
    }

 pNavigate = pHead;
 while (NULL != pNavigate)
 {
     pTemp = pNavigate->pNext;
     free(pNavigate);
     pNavigate = pTemp;
 }

  return TRUE;
}


////////////////////////////////////////////////////////////////////////
//
//
// Function Name   :   DisplayGenList
// Parameters      :
//                     [IN] GEN_LIST<T> *pListHead
//                     holds head pointer of the list.
//
// Description     :
//                    This function display Doubly linear linked list.
//
// Returns         :
//                     void
//
//
////////////////////////////////////////////////////////////////////////

template <typename T>
void
Doubly_linkedList<T>::DisplayGenList()
{
    GEN_DLIST<T> *pTempNode = pHead;

    while(NULL != pTempNode)
    {
        cout<<pTempNode-> Data<<"<==>";
        pTempNode = pTempNode-> pNext;
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  CountGenListNode
// Parameters      :
//                    [IN] GEN_DLIST<T> *pListHead.
//                    Holds head pointer of list
//
// Description     :
//                    This function counts nodes in Doubly linear linked list
//
// Returns         :
//                    int
//                    number of node in generic list
//
//
////////////////////////////////////////////////////////////

template <typename T>
int Doubly_linkedList<T>::CountGenListNode()
{
    // variable for maintaning numbers of nodes
    int CountNode = 0;
    GEN_DLIST<T> *pTempNode = pHead;

    // Travers the linked list till end  
    while(NULL != pTempNode)
    {
        CountNode++;
        pTempNode = pTempNode-> pNext;
    }
    return CountNode;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   SearchFirstOccurance
// Parameters      :
//
//                     [IN] GEN_DLIST<T> data.
//                     holds head data to be searched.
//
// Description     :
//                     this function search perticular data in Doubly linear linked list.
//                     and returns the position at which data is found.
//
// Returns         :
//                     int
//                     position at which data is found in generic list.
//
//
////////////////////////////////////////////////////////////
template <typename T>
int Doubly_linkedList<T>::SearchFirstOccurance(
                                               T data
                                           ) // Data to be searched
{
    int CountNode = 0;
    GEN_DLIST<T> *pTempNode = pHead;

    // Traverse the linked list till end
    while (pTempNode != NULL)
    {
        ++CountNode;
        
        // If the matches with the input value
        if(memcmp(&(pTempNode-> Data), &data, sizeof(data)) == 0)
        {
            // Break the loop as we get the first occurance
            return CountNode;
        } 
        pTempNode = pTempNode-> pNext;
    }

 return -1;
}          

////////////////////////////////////////////////////////////
//
//
// Function Name   :  SearchAllOccurance
// Parameters      :
//
//                    [IN] GEN_DLIST<T> data.
//                    Holds head data to be searched.
//
// Description     :
//                    This function search perticular data in Doubly linear linked list.
//                    and return number of occurance of that data.
//
// Returns         :
//                    int
//                    number of times data is found in generic list.
//
//
////////////////////////////////////////////////////////////

template <typename T>
int Doubly_linkedList<T>::SearchAllOccurance(
                                               T data
                                              )
{
    int CountNode = 0;
     GEN_DLIST<T> *pTempNode = pHead;

    // Travers the linked list till end  
    while(pTempNode != NULL)
    {
        // If the data matches with the input value 
        if(memcmp(&(pTempNode-> Data), &data, sizeof(data)) == 0)
        {
            ++CountNode;
        }
        pTempNode = pTempNode-> pNext;
    }
    
 return CountNode;
}


////////////////////////////////////////////////////////////
//
//
// Function Name   :   InsertAtPosition
// Parameters      :
//
//                     [IN] int pos.
//                     Holds the position.
//
//                     [IN] T *pNodeData.
//                     Holds the entry which is to be added.
//
// Description     :
//                     this function adds node at specified position in Doubly linear linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList<T>::InsertAtPosition(
                                            int pos, // position at which node is inserted
                                            T* pNodeData // Data members of the node
                                       )
{
    int i = 1;

    GEN_DLIST<T> *temp = NULL;
    GEN_DLIST<T> *pNewNode = NULL;

    // If the linked list is empty
    if (pHead == NULL)
    {
        return FALSE;
    }

    else if(pos == 1)
    {
        AddToGenListFirst(pNodeData);
    }
    else if(pos == (CountGenListNode()) + 1)
    {
        AddToGenListLast(pNodeData);
    }
    else if((pos > CountGenListNode()))
    {
        return FALSE;
    }
    else
    {
       temp = pHead;
       pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T>));
       if(NULL == pNewNode)
       {
           return FALSE;
       }

       //
       // Fill the node with Data
       //
       
       memset(pNewNode, 0, sizeof(GEN_DLIST<T>));
       pNewNode-> pNext = NULL;
       pNewNode-> Data = *pNodeData;
       pNewNode-> pPrev = NULL;

       while(i < pos - 1)
       {
           temp = temp-> pNext;
           ++i;
       }
       pNewNode-> pNext = temp-> pNext;
       temp-> pNext-> pPrev = pNewNode;
       temp-> pNext = pNewNode;
       pNewNode->pPrev = temp;
    }
    
    return TRUE;
}               

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteFromGenListFirst
//
// Parameters      :   NONE
// Description     :
//                     this function removes first node from Doubly linear linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////


template <typename T>
BOOL Doubly_linkedList<T>::DeleteFromGenListFirst()
{
    GEN_DLIST <T> *temp = NULL;
    temp = pHead;

    // if linked list is empty
    if(pHead == NULL)
    {
        return FALSE;
    }
    else
    {
        pHead = temp-> pNext;
        pHead-> pPrev = NULL;
        free(temp);
    }
    return TRUE;    
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteFromGenListLast
// Parameters      :   NONE
//
// Description     :
//                     this function removes last node from Doubly linear linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList<T>::DeleteFromGenListLast()
{
    GEN_DLIST<T> *temp1, *temp2;
    temp1 = temp2 = pHead;
    
    // If linked list is empty
    if(pHead == NULL)
    {
        return FALSE;
    } 
    else
    {
        while(temp1-> pNext != NULL)
        {
            temp2 = temp2-> pNext;
            temp1 = temp2-> pNext;
        }
        temp2-> pNext = NULL;
        free(temp1);
    }

    return TRUE;   
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteAtPosition
//
// Parameters      :
//                     [IN] int pos.
//                     Holds the position.
//
// Description     :
//                     this function delete node from  specified position in Doubly linear linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList<T>::DeleteAtPosition(
                                          int pos
                                       )
{
    if(pos > (CountGenListNode()))
    {
        return FALSE;
    }
    else if(pos == 1)
    {
        DeleteFromGenListFirst();
    }
    else if(pos == (CountGenListNode()))
    {
        DeleteFromGenListLast();
    }
    else
    {
       int i = 0;
       GEN_DLIST<T> *temp = pHead, *t;

       for(i = 0; i < pos -1; i++)
       {
           t = temp;
           temp = temp-> pNext;
       }
       t-> pNext = temp-> pNext;
       temp-> pNext->pPrev = t;
       free(temp);
    }

    return TRUE;   
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DisplayGenListReverse
// Parameters      :
//                    NONE
// Description     :
//                     this function Display Doubly linear linked list in reverse manner
//                     
// Returns         :
//
//                     void
////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Doubly_linkedList<T>::DisplayGenListReverse()
{
    GEN_DLIST<T> *temp = pTail;

    if(pHead == NULL)
    {
        return TRUE;
    }
    else
    {
     while(temp != NULL)
     {
        printf("|%d|<=>", temp-> Data);
        temp = temp-> pPrev;
     }
    }
    return FALSE;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Function Name    :   Singly_linkedList_Circular
// Parameters       :   NONE
// Description      :   
//                      This Is Constructor Of Class Singly_linkedList_Circular.
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////
template <typename T>
Singly_linkedList_Circular<T>::Singly_linkedList_Circular ()
{
    pHead = NULL;
    pTail = NULL;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   ~Singly_linkedList_Circular
// Parameters       :   NONE
// Description      :   
//                      This Is Distructor Of Class Singly_linkedList_Circular.
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////
template <typename T>
Singly_linkedList_Circular<T>::~Singly_linkedList_Circular ()
{
/*    GEN_LIST<T> *pTemp;
    GEN_LIST<T> *pNavigate;

    if(NULL != pHead)
    {
        pNavigate = pHead;
        while(NULL != pNavigate)
        {
            pTemp = pNavigate->pNext;
            free(pNavigate);
            pNavigate = pTemp;
        }
    }
*/
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  AddToGenListFirst
// Parameters      :  
// 
//                     [IN]T *pNodeData.
//                      Holds the entry which is to be added.
//
// Description     :  
//                   This Function Adds Node To Singly Circular Linked List.
//                   
// Returns         :  
//                     BOOLEAN
//                    if the function succeds, the return value is TRUE.
//                    if the function fails, the returns value is FALSE.
//
// 
////////////////////////////////////////////////////////////
template <typename T>
BOOL
Singly_linkedList_Circular<T>::AddToGenListFirst(
                                           T *pNodeData
                                       )
{
    GEN_LIST<T> *pNewNode;

    if (NULL == pNodeData)
    {
        return FALSE;
    }

//
// Allocate new node
//

pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T>));
  if(NULL == pNewNode)
  {
      return FALSE;
  }

//
// Fill the node with data.
//

memset(pNewNode, 0, sizeof(GEN_LIST<T>));   
pNewNode-> pNext = NULL;
pNewNode-> Data = *pNodeData;

//
// Prepend
//

 if (NULL == pHead && pTail == NULL)
 {
     pHead = pNewNode;
     pTail = pNewNode;
     pTail-> pNext = pHead;
 }
 else
  {
     pNewNode-> pNext = pHead;
     pHead = pNewNode;
     pTail-> pNext = pNewNode;
  }

 return TRUE;
}

/////////////////////////////////////////////////////////////////////////
//
//
// Function Name   :  DisplayGenList
// Parameters      :
//                    NONE
// Description     :
//                    This function display singly Circular linked list
//
// Returns         :
//                    void
//
//
/////////////////////////////////////////////////////////////////////////

template <typename T>
void
Singly_linkedList_Circular<T>::DisplayGenList()
{
    GEN_LIST<T> *pTempNode;
    pTempNode = pHead;

    do
    {
       cout<<pTempNode-> Data<<"->";
       pTempNode = pTempNode-> pNext;  
    } while(pTempNode != pTail->pNext);   
}

/////////////////////////////////////////////////////////////////////////
//
//
// Function Name   :  AddToGenListLast
// Parameters      :
//
//                   [IN] GEN_LIST<T> **ppListToBeAppended.
//                   List which is to be appended to an existing list.
//
// Description     :
//                    This function appends node in singly Circular linked list
//
// Returns         :
//                    BOOLEAN
//                    If the function succeds, the return value is TRUE.
//                    If the function fails, the return value is FALSE.
//
//
/////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList_Circular<T>::AddToGenListLast(
                                           T *pNodeData
                                       )
{
    GEN_LIST<T> *pNewNode;

    GEN_LIST<T> *pTempNode;
    pTempNode = pHead;

    if (NULL == pNodeData)
    {
        return FALSE;
    }

//
// Allocate new node
//

pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T>));
  if(NULL == pNewNode)
  {
      return FALSE;
  }

//
// Fill the node with data.
//

memset(pNewNode, 0, sizeof(GEN_LIST<T>));   
pNewNode-> pNext = NULL;
pNewNode-> Data = *pNodeData;

//
// Append
//

 if (NULL == pHead && pTail == NULL)
 {
     pHead = pNewNode;
     pTail = pNewNode;
     pTail->pNext = pHead;
 }
 else
  {
     pTail->pNext = pNewNode;
     pTail = pNewNode;
     pTail->pNext = pHead;
  }

 return TRUE;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  FreeGenList
// Parameters      :  NONE
//
// Description     :  This function frees singly circular linked list
//                   
//
// Returns         :  
//                     BOOLEAN
//                    if the function succeds, the return value is TRUE.
//                    if the function fails, the returns value is FALSE.
//
// 
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList_Circular<T>::FreeGenList()
{
    GEN_LIST<T> *pTemp;
    GEN_LIST<T> *pNavigate;

    if (NULL == pHead)
    {
        return FALSE;
    }

 pNavigate = pHead;
 while (NULL != pNavigate)
 {
     pTemp = pNavigate->pNext;
     free(pNavigate);
     pNavigate = pTemp;
 }

  return TRUE;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  CountGenListNode
// Parameters      :
//                    NONE
// Description     :
//                    This function counts nodes in singly Circular linked list
//
// Returns         :
//                    int
//                    number of node in generic list
//
//
////////////////////////////////////////////////////////////

template <typename T>
int
Singly_linkedList_Circular<T>::CountGenListNode ()
{
    // variable for maintaning numbers of nodes
    int CountNode = 0;
    GEN_LIST<T> *pTempNode;
    pTempNode = pHead;

    do
    {
        CountNode++;
        pTempNode = pTempNode-> pNext;
    } while(pTempNode != pTail->pNext);
    
    return CountNode;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   SearchFirstOccurance
// Parameters      :
//
//                     [IN] GEN_LIST<T>data.
//                     holds head data to be searched.
//
// Description     :
//                     this function search perticular data in singly Circular linked list.
//                     and returns the position at which data is found.
//
// Returns         :
//                     int
//                     position at which data is found in generic list.
//
//
////////////////////////////////////////////////////////////
template <typename T>
int
Singly_linkedList_Circular<T>::SearchFirstOccurance(
                                               T data
                                           )
{
    int CountNode = 0;
    GEN_LIST<T> *pListHead = pHead;

    // Traverse the linked list till end
    do
    {
        CountNode++;
        if(memcmp(&(pListHead-> Data), &data, sizeof(data)) == 0)
        {
            // Break the loop as we get the first occurance
            return CountNode;
        } 
        pListHead = pListHead->pNext;
    }while(pListHead != pTail->pNext);

 return -1;
}          

////////////////////////////////////////////////////////////
//
//
// Function Name   :  SearchAllOccurance
// Parameters      :
//
//                    [IN] GEN_LIST<T> data.
//                    Holds head data to be searched.
//
// Description     :
//                    This function search perticular data in Singly Circular linked list.
//                    and return number of occurance of that data.
//
// Returns         :
//                    int
//                    number of times data is found in generic list.
//
//
////////////////////////////////////////////////////////////

template <typename T>
int
Singly_linkedList_Circular<T>::SearchAllOccurance(
                                                       T data
                                                  )
{
    int CountNode = 0;
    GEN_LIST<T> *pListHead = pHead;

    // Travers the linked list till end  
    do
    { 
        if(memcmp(&(pListHead-> Data), &data, sizeof(data)) == 0)
        {
            CountNode++;
        }
        pListHead = pListHead-> pNext;
    }while(pListHead != pTail->pNext);
    
 return CountNode;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   InsertAtPosition
// Parameters      :
//
//                     [IN] int pos.
//                     Holds the position.
//
//                     [IN] T *pNodeData.
//                     Holds the entry which is to be added.
//
// Description     :
//                     this function adds node at specified position in singly Circular linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList_Circular<T>::InsertAtPosition(
                                            int pos,
                                            T* pNodeData
                                       )
{
    int i = 1;

    GEN_LIST<T> *temp = NULL;
    GEN_LIST<T> *pNewNode = NULL;

    // If the linked list is empty
    if (pHead == NULL)
    {
        return FALSE;
    }

    else if(pos == 1)
    {
        AddToGenListFirst(pNodeData);
    }
    else if(pos == (CountGenListNode()) + 1)
    {
        AddToGenListLast(pNodeData);
    }
    else if((pos > CountGenListNode()))
    {
        return FALSE;
    }
    else
    {
       temp = pHead;
       pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T> ));
       if(NULL == pNewNode)
       {
           return FALSE;
       }

       //
       // Fill the node with Data
       //
       
       memset(pNewNode, 0, sizeof(GEN_LIST<T>));
       pNewNode-> pNext = NULL;
       pNewNode-> Data = *pNodeData;

       while(i < pos - 1)
       {
           temp = temp-> pNext;
           ++i;
       }
       pNewNode-> pNext = temp-> pNext;
       temp-> pNext = pNewNode;
    }
    
    return TRUE;
}               

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteFromGenListFirst
// Parameters      :   NONE
//
//
// Description     :
//                     this function removes first node from singly Circular linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList_Circular<T>::DeleteFromGenListFirst()
{
    GEN_LIST <T> *temp;
    temp = pHead;

    // if linked list is empty
    if(pHead == NULL)
    {
        return FALSE;
    }
    else
    {
        pHead = temp-> pNext;
        free(temp);
    }
    return TRUE;    
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteFromGenListLast
// Parameters      :   NONE
//
// Description     :
//                     this function removes last node from singly Circular linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL Singly_linkedList_Circular<T>::DeleteFromGenListLast()
{
    GEN_LIST<T> *temp1, *temp2;
    temp1 = pHead;
    temp2 = pTail;
    
    // If linked list is empty
    if(pHead == NULL && pTail == NULL)
    {
        return FALSE;
    } 
    else
    {
        while(temp1-> pNext != temp2)
        {
            temp1 = temp1-> pNext;
        }
    
        free(temp2);
        pTail = temp1;
        temp1-> pNext = pHead;
    }

    return TRUE;   
}


////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteAtPosition
// Parameters      :
//                     NONE
//                     [IN] int pos.
//                     Holds the position.
//
// Description     :
//                     this function delete node from  specified position in singly Circular linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Singly_linkedList_Circular<T>::DeleteAtPosition(
                                          int pos
                                       )
{
    if(pos > (CountGenListNode()))
    {
        return FALSE;
    }
    else if(pos == 1)
    {
        DeleteFromGenListFirst();
    }
    else if(pos == (CountGenListNode()))
    {
        DeleteFromGenListLast();
    }
    else
    {
       int i = 0;
       GEN_LIST<T> *temp = pHead, *t;

       for(i = 0; i < pos -1; i++)
       {
           t = temp;
           temp = temp-> pNext;
       }
       t-> pNext = temp-> pNext;
       temp-> pNext = NULL;
       free(temp);
    }

    return TRUE;   
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Function Name    :   Doubly_linkedList_Circular
// Parameters       :   NONE
// Description      :   
//                      This Is Constructor Of Class Doubly_linkedList_Circular.
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////
template <typename T>
Doubly_linkedList_Circular<T>::Doubly_linkedList_Circular()
{
    pHead = NULL;
    pTail = NULL;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   ~Doubly_linkedList_Circular
// Parameters       :   NONE
// Description      :   
//                      This Is Distructor Of Class Doubly_linkedList_Circular.
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////
template <typename T>
Doubly_linkedList_Circular<T>::~Doubly_linkedList_Circular ()
{
    GEN_DLIST<T> *pTemp;
    GEN_DLIST<T> *pNavigate;

    if(NULL == pHead)
    {
        return;
    }
     
        pNavigate = pHead;
        while(pNavigate != pTail)
        {
            pTemp = pNavigate->pNext;
            free(pNavigate);
            pNavigate = pTemp;
        }
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  AddToGenListFirst
// Parameters      :  
// 
//                     [IN]T *pNodeData.
//                      Holds the entry which is to be added.
//
// Description     :  
//                   This Function Adds Node To Doubly Circular Linked List.
//                   
// Returns         :  
//                     BOOLEAN
//                    if the function succeds, the return value is TRUE.
//                    if the function fails, the returns value is FALSE.
//
// 
////////////////////////////////////////////////////////////
template <typename T>
BOOL
Doubly_linkedList_Circular<T>::AddToGenListFirst(
                                           T *pNodeData
                                       )
{
    GEN_DLIST<T> *pNewNode = NULL;

    if (NULL == pNodeData)
    {
        return FALSE;
    }

//
// Allocate new node
//

pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T>));
  if(NULL == pNewNode)
  {
      return FALSE;
  }

//
// Fill the node with data.
//

memset(pNewNode, 0, sizeof(GEN_DLIST<T>));   
pNewNode-> pNext = NULL;
pNewNode-> Data = *pNodeData;
pNewNode-> pPrev = NULL;

//
// Prepend
//

 if (NULL == pHead)
 {
     pHead = pNewNode;
     pTail = pNewNode;
     pTail-> pNext = pNewNode;
 }
 else
  {
     pNewNode-> pNext = pHead;
     (pHead)-> pPrev = pNewNode;
     pHead = pNewNode;
     pTail-> pNext = pHead;
  }

 return TRUE;
}

/////////////////////////////////////////////////////////////////////////
//
//
// Function Name   :  AddToGenListLast
// Parameters      :
//
//                   [IN] GEN_LIST<T>**ppListToBeAppended.
//                   List which is to be appended to an existing list.
//
// Description     :
//                    This function appends node in Doubly Circular linked list
//
// Returns         :
//                    BOOLEAN
//                    If the function succeds, the return value is TRUE.
//                    If the function fails, the return value is FALSE.
//
//
/////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList_Circular<T>::AddToGenListLast(
                                           T *pNodeData
                                       )
{
    GEN_DLIST<T> *pNewNode = NULL;

    GEN_DLIST<T> *pTempNode = NULL;
    
    pTempNode = pHead;

    if ( NULL == pNodeData)
    {
        return FALSE;
    }

//
// Allocate new node
//

pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T>));
  if(NULL == pNewNode)
  {
      return FALSE;
  }

//
// Fill the node with data.
//

memset(pNewNode, 0, sizeof(GEN_DLIST<T>));   
pNewNode-> pNext = NULL;
pNewNode-> Data = *pNodeData;
pNewNode-> pPrev = NULL;
//
// Append
//

 if (NULL == pHead)
 {
     pHead = pNewNode;
     pTail = pNewNode;
     pTail->pNext = pNewNode;
 }
 else
  {
     pNewNode-> pPrev = pTail;
     pTail->pNext = pNewNode;
     pTail = pNewNode;
     pTail->pNext = pHead;
  }

 return TRUE;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  FreeGenList
// Parameters      :  NONE
//
// Description     :  This function frees Doubly circular linked list
//                   
//
// Returns         :  
//                     BOOLEAN
//                    if the function succeds, the return value is TRUE.
//                    if the function fails, the returns value is FALSE.
//
// 
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList_Circular<T>::FreeGenList()
{
    GEN_DLIST<T> *pTemp;
    GEN_DLIST<T> *pNavigate;

    if (NULL == pHead)
    {
        return FALSE;
    }

 pNavigate = pHead;
 while (pNavigate != pTail)
 {
     pTemp = pNavigate->pNext;
     free(pNavigate);
     pNavigate = pTemp;
 }

  return TRUE;
}


////////////////////////////////////////////////////////////
//
//
// Function Name   :   DisplayGenList
// Parameters      :
//                     [IN] GEN_DLIST<T> *pListHead
//                     Holds head pointer of list
//
// Description     :
//                      This function display Doubly_linkedList_Circular
//
// Returns         :
//                       void
//
//
////////////////////////////////////////////////////////////

template <typename T>
void
Doubly_linkedList_Circular<T>::DisplayGenList()
{
    GEN_DLIST<T> *pTempNode;
    pTempNode = pHead;

    do
    {
        cout<<pTempNode-> Data<<"->";
        pTempNode = pTempNode-> pNext;
    }while(pTempNode != pTail->pNext);
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :  CountGenListNode
// Parameters      :
//                    [IN] GEN_DLIST<T>*pListHead
//                    holds head pointer of the list.
//
// Description     :
//                    This function counts nodes in Doubly Circular linked list
//
// Returns         :
//                    int
//                    number of node in generic list
//
//
////////////////////////////////////////////////////////////

template <typename T>
int Doubly_linkedList_Circular<T>::CountGenListNode ()
{
    // variable for maintaning numbers of nodes
    int CountNode = 0;
    GEN_DLIST<T> *pTempNode;
    pTempNode = pHead;

    do
    {
        CountNode++;
        pTempNode = pTempNode-> pNext;
    } while(pTempNode != pTail-> pNext);
    return CountNode;
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   SearchFirstOccurance
// Parameters      :
//
//                     [IN] GEN_DLIST<T> data.
//                     holds head data to be searched.
//
// Description     :
//                     this function search perticular data in Doubly Circular linked list.
//                     and returns the position at which data is found.
//
// Returns         :
//                     int
//                     position at which data is found in generic list.
//
//
////////////////////////////////////////////////////////////
template <typename T>
int Doubly_linkedList_Circular<T>::SearchFirstOccurance(
                                               T data
                                           ) //Data to be searched
{
    int CountNode = 0;
    GEN_DLIST<T> *pListHead = pHead;

    // Traverse the linked list till end
    do
    {
        CountNode++;
        if(memcmp(&(pListHead-> Data), &data, sizeof(data)) == 0)
        {
            // Break the loop as we get the first occurance
            return CountNode;
        } 
        pListHead = pListHead-> pNext;
    }while(pListHead != pTail->pNext);

 return -1;
}          

////////////////////////////////////////////////////////////
//
//
// Function Name   :  SearchAllOccurance
// Parameters      :
//
//                    [IN] GEN_DLIST<T> data.
//                    Holds head data to be searched.
//
// Description     :
//                    This function search perticular data in Doubly Circular linked list.
//                    and return number of occurance of that data.
//
// Returns         :
//                    int
//                    number of times data is found in generic list.
//
//
////////////////////////////////////////////////////////////

template <typename T>
int Doubly_linkedList_Circular<T>::SearchAllOccurance(
                                                       T data
                                                  )
{
    int CountNode = 0;
    GEN_DLIST<T> *pListHead = pHead;

    // Travers the linked list till end  
    do
    { 
        if(memcmp(&(pListHead-> Data), &data, sizeof(data)) == 0)
        {
            CountNode++;
        }
        pListHead = pListHead-> pNext;
    }while(pListHead != pTail->pNext);
    
 return CountNode;
}


////////////////////////////////////////////////////////////
//
//
// Function Name   :   InsertAtPosition
// Parameters      :
//
//                     [IN] int pos.
//                     Holds the position.
//
//                     [IN] T *pNodeData.
//                     Holds the entry which is to be added.
//
// Description     :
//                     this function adds node at specified position in singlDoubly Circular linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList_Circular<T>::InsertAtPosition(
                                            int pos, // position at which node is inserted
                                            T* pNodeData // data members of thee node
                                       )
{
    int i = 1;

    GEN_DLIST<T> *temp = NULL;
    GEN_DLIST<T> *pNewNode = NULL;

    // If the linked list is empty
    if (pHead == NULL)
    {
        return FALSE;
    }

    else if(pos == 1)
    {
        AddToGenListFirst(pNodeData);
    }
    else if(pos == (CountGenListNode()) + 1)
    {
        AddToGenListLast(pNodeData);
    }
    else if((pos > CountGenListNode()))
    {
        return FALSE;
    }
    else
    {
       temp = pHead;
       pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T> ));
       if(NULL == pNewNode)
       {
           return FALSE;
       }

       //
       // Fill the node with Data
       //

       memset(pNewNode, 0, sizeof(GEN_DLIST<T>));
       pNewNode-> pNext = NULL;
       pNewNode-> Data = *pNodeData;
       pNewNode-> pPrev = NULL;

       while(i < pos - 1)
       {
           temp = temp-> pNext;
           ++i;
       }
       pNewNode-> pNext = temp-> pNext;
       temp-> pNext-> pPrev = pNewNode;
       temp-> pNext = pNewNode;
       pNewNode-> pPrev = temp;
    }
    
    return TRUE;
}               

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteFromGenListFirst
// Parameters      :   NONE
//
//
// Description     :
//                     this function removes first node from Doubly Circular linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList_Circular<T>::DeleteFromGenListFirst()
{
    GEN_DLIST <T> *temp = NULL;
    temp = pHead;

    // if linked list is empty
    if(pHead == NULL)
    {
        return FALSE;
    }
    else
    {
        pHead = temp-> pNext;
        pTail->pNext = pHead;
        pHead-> pPrev = pTail;
        free(temp);
    }
    return TRUE;    
}

////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteFromGenListLast
// Parameters      :   NONE
//
// Description     :
//                     this function removes last node from Doubly Circular linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList_Circular<T>::DeleteFromGenListLast()
{
    GEN_DLIST<T> *temp;

    // If linked list is empty
    if(pHead == NULL)
    {
        return FALSE;
    } 
    else
    {
        temp = pTail;
        pTail = pTail-> pPrev;
        pTail-> pNext = pHead;
        free(temp);
    }
    return TRUE;   
}
////////////////////////////////////////////////////////////
//
//
// Function Name   :   DeleteAtPosition
// Parameters      :
//                    
//                     [IN] int pos.
//                     Holds the position.
//
// Description     :
//                     this function delete node from  specified position in Doubly Circular linked list
//                     
// Returns         :
//                     BOOLEAN
//                     If the function succeds, the return value is TRUE.
//                     If the function fails, the return value is FALSE.
//
//
////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList_Circular<T>::DeleteAtPosition(
                                          int pos
                                       )
{
    if(pos > (CountGenListNode()))
    {
        return FALSE;
    }
    else if(pos == 1)
    {
        DeleteFromGenListFirst();
    }
    else if(pos == (CountGenListNode()))
    {
        DeleteFromGenListLast();
    }
    else
    {
       int i = 0;
       GEN_DLIST<T> *temp = pHead, *t;

       for(i = 0; i < pos -1; i++)
       {
           t = temp;
           temp = temp-> pNext;
       }
       t-> pNext = temp-> pNext;
       temp-> pNext->pPrev = t;
       
       free(temp);
    }
    return TRUE;   
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Function Name   :  DisplayGenListReverse
// Parameters      :
//                    NONE 
// Description     :
//                    Function which display the list in reverse manner.
// Return          :
//                    void 
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <typename T>
BOOL
Doubly_linkedList_Circular<T>::DisplayGenListReverse()
{
    GEN_DLIST<T> *temp = pTail;

    if(pHead == NULL)
    {
        return TRUE;
    }
    else
    {
       do
       {
           printf("|%d|<=>",temp-> Data);
           temp = temp-> pPrev;
       } while(temp != pHead-> pPrev);
    }   
     return FALSE;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//
//
// Function Name   :   Entry Point Function
//
//////////////////////////////////////////////////////////////

int main()
{
    BOOL bRet;

    cout<<endl<<"--------------------------------------"<<endl;
    cout<<"\t\tLinear Singly Linked List";
    cout<<endl<<"---------------------------------------"<<endl;

    Singly_linkedList <int>sobj;
    
    int no = 10;
    sobj.AddToGenListFirst(&no);
    no++;
    sobj.AddToGenListFirst(&no);
    no++;
    sobj.AddToGenListFirst(&no);
    no++;
    sobj.AddToGenListFirst(&no);
    
    no = 25;
    sobj.AddToGenListLast(&no);
    sobj.DisplayGenList();

    no = 11;
    cout<<endl<<"Elements 11 is found at position"<<sobj.SearchFirstOccurance(no)<<endl;

    sobj.InsertAtPosition(4,&no);
    sobj.DisplayGenList();
    printf("\n");

    sobj.DeleteFromGenListFirst();
    sobj.DisplayGenList();
    printf("\n");

    sobj.DeleteFromGenListLast();
    sobj.DisplayGenList();
    printf("\n"); 

    sobj.DeleteAtPosition(2);
    sobj.DisplayGenList();
    printf("\n");

    sobj.ReverseList();
    sobj.DisplayGenList();
    printf("\n");

    
    cout<<endl<<"--------------------------------------"<<endl;
    cout<<"\t\tLinear Doubly Linked List";
    cout<<endl<<"---------------------------------------"<<endl;
    Doubly_linkedList <int>dobj;
    
    bRet = dobj.AddToGenListFirst(&no);
    no++;

    bRet = dobj.AddToGenListFirst(&no);
    no++;

    bRet = dobj.AddToGenListFirst(&no);
    no++;

    dobj.DisplayGenList();
    printf("\n");

    no = 20;
    bRet = dobj.AddToGenListLast(&no);
    
    no = 30;
    bRet = dobj.AddToGenListLast(&no);

    dobj.DisplayGenList();
    printf("\n");

    no = 40;
    bRet = dobj.AddToGenListLast(&no);
    
    no = 50;
    bRet = dobj.AddToGenListLast(&no);

    dobj.DisplayGenList();
    printf("\n");

    no = 20;
    cout<<endl<<"Elements 20 is found at position"<<dobj.SearchFirstOccurance(no)<<endl;
    
    no = 45;
    dobj.DisplayGenList();
    printf("\n");
    
    dobj.InsertAtPosition(4,&no);
    dobj.DisplayGenList();
    printf("\n");

    printf("\n");
    dobj.DeleteAtPosition(4);
    dobj.DisplayGenList();
    printf("\n");

    dobj.DisplayGenListReverse();

     cout<<endl<<"--------------------------------------"<<endl;
    cout<<"\t\tCircular Singly Linked List";
    cout<<endl<<"---------------------------------------"<<endl;
    
    Singly_linkedList_Circular <int>scobj;
    
    no = 25;
    scobj.AddToGenListLast(&no);
    scobj.DisplayGenList();

    no = 10;
    scobj.AddToGenListFirst(&no);
    no++;
    cout<<endl;
    scobj.DisplayGenList();

    scobj.AddToGenListFirst(&no);
    no++;
    cout<<endl;
    scobj.DisplayGenList();

    scobj.AddToGenListFirst(&no);
    no++;
    scobj.AddToGenListFirst(&no);
    no++;
    cout<<endl;
    scobj.DisplayGenList();
    cout<<endl;
    
    no = 25;
    scobj.AddToGenListLast(&no);
    scobj.DisplayGenList();
    
    no = 11;
    cout<<endl<<"Elements 11 is found at position"<<scobj.SearchFirstOccurance(no)<<endl;

    scobj.InsertAtPosition(4,&no);
    scobj.DisplayGenList();
    printf("\n");
    

    no = 25;
    cout<<endl<<"Elements 25 is fount at position"<<scobj.SearchAllOccurance(no)<<endl;

    scobj.DeleteFromGenListFirst();
    scobj.DisplayGenList();
    printf("\n");

    scobj.DeleteFromGenListLast();
    scobj.DisplayGenList();
    printf("\n");

    scobj.DeleteAtPosition(2);
    scobj.DisplayGenList();
    printf("\n");

    cout<<endl<<"----------------------------------------------"<<endl;
    cout<<"\t\tCircular Doubly Linked List";
    cout<<endl<<"----------------------------------------------"<<endl;
    
    Doubly_linkedList_Circular <int>dcobj;

    no = 95;
    dcobj.AddToGenListLast(&no);
    dcobj.DisplayGenList();

    no = 25;
    dcobj.AddToGenListFirst(&no);
    dcobj.DisplayGenList();

    no = 10;
    dcobj.AddToGenListFirst(&no);
    no++;
    cout<<endl;
    dcobj.DisplayGenList();
    
    dcobj.AddToGenListFirst(&no);
    no++;
    cout<<endl;
    dcobj.DisplayGenList();

    dcobj.AddToGenListFirst(&no);
    no++;
    dcobj.AddToGenListFirst(&no);
    no++;
    cout<<endl;
    dcobj.DisplayGenList();
    cout<<endl;
    
    no = 35;
    dcobj.AddToGenListLast(&no);
    dcobj.DisplayGenList();
    
    no = 11;
    cout<<endl<<"Elements 11 is found at position"<<dcobj.SearchFirstOccurance(no)<<endl;
    cout<<endl<<"Elements 11 is found at position"<<dcobj.SearchAllOccurance(no)<<endl;

    dcobj.InsertAtPosition(4,&no);
    dcobj.DisplayGenList();
    printf("\n");

    dcobj.DeleteFromGenListFirst();
    dcobj.DisplayGenList();
    printf("\n");

    dcobj.DeleteFromGenListLast();
    dcobj.DisplayGenList();
    printf("\n");
    
    dcobj.DeleteAtPosition(2);
    dcobj.DisplayGenList();
    printf("\n");

    dcobj.DisplayGenListReverse();
    
    return 0;
}
