#include <iostream>
using namespace std;

struct coord
{
    int x;
    int y;
};

struct Node       //Ñòðóêòóðà ÿâëÿþùàÿñÿ çâåíîì ñïèñêà
{
    struct coord a;     //Çíà÷åíèå x áóäåò ïåðåäàâàòüñÿ â ñïèñîê
    Node *next, *prev; //Óêàçàòåëè íà àäðåñà ñëåäóþùåãî è ïðåäûäóùåãî ýëåìåíòîâ ñïèñêà
};

struct List   //Ñîçäàåì òèï äàííûõ Ñïèñîê
{
    Node *head;
    Node *tail;  //Óêàçàòåëè íà àäðåñà íà÷àëà ñïèñêà è åãî êîíöà
    
    int searchf(int x1, int y1)
    {
        int s = 1;
        Node * temp = this->head;  // Âðåìåííî óêàçûâàåì íà àäðåñ ïåðâîãî ýëåìåíòà
        while (temp->next != NULL && (temp->a.x != x1 && temp->a.y != y1))      // Ïîêà íå âñòðåòèì ïóñòîå çíà÷åíèå
        {
            temp = temp->next;     //Ñìåíà àäðåñà íà àäðåñ ñëåäóþùåãî ýëåìåíòà
            s++;
        }
        cout << "s=" << s<<"\n";
        if (temp->a.x == x1 && temp->a.y == y1)
        {
            return s;
        }
        else
            return 0;
    }
    
    int searchl(int x1, int y1)
    {
        int s = 1;
        Node * temp = this->tail;  // Âðåìåííî óêàçûâàåì íà àäðåñ ïåðâîãî ýëåìåíòà
        while (temp->prev != NULL && (temp->a.x != x1 && temp->a.y != y1))      // Ïîêà íå âñòðåòèì ïóñòîå çíà÷åíèå
        {
            temp = temp->prev;     //Ñìåíà àäðåñà íà àäðåñ ñëåäóþùåãî ýëåìåíòà
            s++;
        }
        cout << "s=" << s << "\n";
        if (temp->a.x == x1 && temp->a.y == y1)
        {
            return s;
        }
        else
            return 0;
    }
    
    void del(int pos)
    {
        int s = 0;
        Node * temp = this->head;
        while (temp->next != NULL)
        {
            temp = temp->next;     //Ñìåíà àäðåñà íà àäðåñ ñëåäóþùåãî ýëåìåíòà
            s++;
        }
        //s-äëèííà ñïèñêà
        if (pos <= s)
        {
            Node * temp = this->head;
            for (int i = 0; i < pos; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp;
        }
        else
            cout << "Error, list is too short";
    }
    
    void insert(int pos, int x1, int y1)
    {
        int s = 0;
        Node * temp = this->head;
        while (temp->next != NULL)
        {
            temp = temp->next;     //Ñìåíà àäðåñà íà àäðåñ ñëåäóþùåãî ýëåìåíòà
            s++;
        }
        //s-äëèííà ñïèñêà
        if (pos <= s)
        {
            Node * temp = this->head;
            for (int i = 0; i < pos; i++)
            {
                temp = temp->next;
            }
            Node* t = new Node();
            t->a.x = x1; t->a.y = y1;
            t->next = temp->next;
            temp->next = t;
        }
        else
            cout << "Error, list is too short";
    }
    
};

void add(List *list, int x1, int y1)
{
    Node *temp = new Node(); // Âûäåëåíèå ïàìÿòè ïîä íîâûé ýëåìåíò ñòðóêòóðû
    temp->next = NULL;       // Óêàçûâàåì, ÷òî èçíà÷àëüíî ïî ñëåäóþùåìó àäðåñó ïóñòî
    temp->a.x = x1;             // Çàïèñûâàåì çíà÷åíèå â ñòðóêòóðó
    temp->a.y = y1;
    
    if (list->head != NULL) // Åñëè ñïèñîê íå ïóñò
    {
        temp->prev = list->tail; // Óêàçûâàåì àäðåñ íà ïðåäûäóùèé ýëåìåíò â ñîîòâ. ïîëå
        list->tail->next = temp; // Óêàçûâàåì àäðåñ ñëåäóþùåãî çà õâîñòîì ýëåìåíòà
        list->tail = temp;       //Ìåíÿåì àäðåñ õâîñòà
    }
    else //Åñëè ñïèñîê ïóñòîé
    {
        temp->prev = NULL; // Ïðåäûäóùèé ýëåìåíò óêàçûâàåò â ïóñòîòó
        list->head = list->tail = temp;    // Ãîëîâà=Õâîñò=òîò ýëåìåíò, ÷òî ñåé÷àñ äîáàâèëè
    }
}

void print(List * list)
{
    Node * temp = list->head;
    while (temp != NULL)      // Ïîêà íå âñòðåòèì ïóñòîå çíà÷åíèå
    {
        cout << "x="<<temp->a.x << " ,y="<<temp->a.y<<"\n"; //Âûâîäèì çíà÷åíèå íà ýêðàí
        temp = temp->next;     //Ñìåíà àäðåñà íà àäðåñ ñëåäóþùåãî ýëåìåíòà
    }
    cout << "\n";
}



int main() {
    List list;
    list.head = list.tail = NULL;
    for (int i = 0; i < 20; i++)
        add(&list, i, i + 1);
    int uu = list.searchf(3, 4);
    //list.insert(5, 0, 1);
    //print(&list);
    list.del(6);
    print(&list);
    
    return 0;
}